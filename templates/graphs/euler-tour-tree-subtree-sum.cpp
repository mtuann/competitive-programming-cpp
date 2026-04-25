// Template: Euler tour tree subtree sum
// Signal: dynamic forest with online link/cut operations where the live query
// is a subtree-side aggregate on one existing edge, not a path query.
// Assumes: vertices are 0-indexed, values live on vertices, subtree queries are
// asked as subtree_sum(v, parent) for an existing edge (v, parent), and the
// first exact route is point-add plus subtree-sum rather than lazy subtree
// updates or generic path monoids.
// Exposes: EulerTourTreeSubtreeSum(values) with connected(u, v), make_root(u),
// link(child, parent), cut(u, v), add_value(u, delta), and subtree_sum(v, parent).
// Complexity: expected O(log n) per operation.
// Main trap: this is a subtree-side dynamic-tree structure; do not overclaim
// path-query support just because it also supports online link/cut.
// Links:
//   Topic: topics/graphs/euler-tour-tree/README.md
//   Note: practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md

#include <cassert>
#include <cstdint>
#include <iostream>
#include <memory>
#include <random>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct EulerTourTreeSubtreeSum {
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;
        uint32_t priority = 0;
        int size = 1;
        long long value = 0;
        long long sum = 0;
    };

    int n = 0;
    mt19937 rng{712367821};
    vector<unique_ptr<Node>> storage;
    vector<Node*> self_loop;
    unordered_map<uint64_t, Node*> edge_token;

    explicit EulerTourTreeSubtreeSum(const vector<long long>& values)
        : n(static_cast<int>(values.size())), self_loop(n, nullptr) {
        storage.reserve(values.size() * 3);
        for (int u = 0; u < n; ++u) {
            self_loop[u] = make_node(values[u]);
        }
    }

    bool connected(int u, int v) const {
        return get_root(self_loop[u]) == get_root(self_loop[v]);
    }

    void make_root(int u) {
        Node* token = self_loop[u];
        Node* root = get_root(token);
        int pos = index(token);
        auto [left, right] = split(root, pos);
        merge(right, left);
    }

    bool link(int child, int parent) {
        if (connected(child, parent)) {
            return false;
        }
        make_root(child);
        Node* child_root = get_root(self_loop[child]);
        Node* parent_root = get_root(self_loop[parent]);

        Node* down = make_node(0);
        Node* up = make_node(0);
        edge_token[pack(parent, child)] = down;
        edge_token[pack(child, parent)] = up;

        int pos = index(self_loop[parent]) + 1;
        auto [left, right] = split(parent_root, pos);
        merge(left, merge(down, merge(child_root, merge(up, right))));
        return true;
    }

    bool cut(int u, int v) {
        auto it_uv = edge_token.find(pack(u, v));
        auto it_vu = edge_token.find(pack(v, u));
        if (it_uv == edge_token.end() || it_vu == edge_token.end()) {
            return false;
        }

        make_root(u);
        Node* down = it_uv->second;
        Node* up = it_vu->second;
        Node* root = get_root(down);
        int left_pos = index(down);
        int right_pos = index(up);
        assert(left_pos < right_pos);

        auto [prefix, rest] = split(root, left_pos);
        auto [middle, suffix] = split(rest, right_pos - left_pos + 1);
        auto [drop_left, tail] = split(middle, 1);
        auto [subtree, drop_right] = split(tail, max(0, get_size(tail) - 1));

        (void)drop_left;
        (void)drop_right;
        merge(prefix, suffix);
        if (subtree != nullptr) {
            subtree->parent = nullptr;
        }

        edge_token.erase(it_uv);
        edge_token.erase(it_vu);
        return true;
    }

    void add_value(int u, long long delta) {
        Node* token = self_loop[u];
        token->value += delta;
        for (Node* cur = token; cur != nullptr; cur = cur->parent) {
            pull(cur);
        }
    }

    long long subtree_sum(int v, int parent) {
        assert(edge_token.count(pack(parent, v)) != 0);
        assert(edge_token.count(pack(v, parent)) != 0);

        make_root(parent);
        Node* down = edge_token[pack(parent, v)];
        Node* up = edge_token[pack(v, parent)];
        Node* root = get_root(down);
        int left_pos = index(down);
        int right_pos = index(up);
        assert(left_pos < right_pos);

        auto [prefix, rest] = split(root, left_pos);
        auto [middle, suffix] = split(rest, right_pos - left_pos + 1);
        long long answer = get_sum(middle);
        merge(prefix, merge(middle, suffix));
        return answer;
    }

private:
    Node* make_node(long long value) {
        storage.push_back(make_unique<Node>());
        Node* node = storage.back().get();
        node->priority = rng();
        node->value = value;
        node->sum = value;
        return node;
    }

    static int get_size(Node* node) {
        return node == nullptr ? 0 : node->size;
    }

    static long long get_sum(Node* node) {
        return node == nullptr ? 0 : node->sum;
    }

    static void set_parent(Node* child, Node* parent) {
        if (child != nullptr) {
            child->parent = parent;
        }
    }

    static void pull(Node* node) {
        if (node == nullptr) {
            return;
        }
        node->size = 1 + get_size(node->left) + get_size(node->right);
        node->sum = node->value + get_sum(node->left) + get_sum(node->right);
        set_parent(node->left, node);
        set_parent(node->right, node);
    }

    static Node* get_root(Node* node) {
        while (node->parent != nullptr) {
            node = node->parent;
        }
        return node;
    }

    static int index(Node* node) {
        int pos = get_size(node->left);
        while (node->parent != nullptr) {
            if (node->parent->right == node) {
                pos += get_size(node->parent->left) + 1;
            }
            node = node->parent;
        }
        return pos;
    }

    static uint64_t pack(int u, int v) {
        return (static_cast<uint64_t>(static_cast<uint32_t>(u)) << 32) |
               static_cast<uint32_t>(v);
    }

    static pair<Node*, Node*> split(Node* root, int count_left) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }
        if (get_size(root->left) >= count_left) {
            auto [left_part, right_part] = split(root->left, count_left);
            root->left = right_part;
            set_parent(root->left, root);
            pull(root);
            set_parent(left_part, nullptr);
            root->parent = nullptr;
            return {left_part, root};
        }

        auto [left_part, right_part] =
            split(root->right, count_left - get_size(root->left) - 1);
        root->right = left_part;
        set_parent(root->right, root);
        pull(root);
        set_parent(right_part, nullptr);
        root->parent = nullptr;
        return {root, right_part};
    }

    static Node* merge(Node* left_root, Node* right_root) {
        if (left_root == nullptr) {
            set_parent(right_root, nullptr);
            return right_root;
        }
        if (right_root == nullptr) {
            set_parent(left_root, nullptr);
            return left_root;
        }
        if (left_root->priority < right_root->priority) {
            left_root->right = merge(left_root->right, right_root);
            set_parent(left_root->right, left_root);
            pull(left_root);
            left_root->parent = nullptr;
            return left_root;
        }
        right_root->left = merge(left_root, right_root->left);
        set_parent(right_root->left, right_root);
        pull(right_root);
        right_root->parent = nullptr;
        return right_root;
    }
};

int main() {
    vector<long long> values = {1, 2, 3};
    EulerTourTreeSubtreeSum ett(values);
    ett.link(0, 1);
    ett.link(2, 1);

    cout << ett.subtree_sum(0, 1) << '\n';
    cout << ett.subtree_sum(2, 1) << '\n';
    ett.add_value(2, 5);
    cout << ett.subtree_sum(2, 1) << '\n';
    ett.cut(2, 1);
    ett.link(2, 0);
    cout << ett.subtree_sum(2, 0) << '\n';
    cout << ett.subtree_sum(0, 1) << '\n';
    return 0;
}

