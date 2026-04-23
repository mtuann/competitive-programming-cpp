#include <algorithm>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using namespace std;

/*
Problem: VMWTREE - Lại là cây khung
Judge: VN SPOJ / VNOI
URL: https://vn.spoj.com/problems/VMWTREE/
Mirror: https://oj.vnoi.info/problem/vmwtree
Topic: Trees, heavy-light decomposition, implicit treap

Key idea:
- reverse the tree path into O(log N) heavy-chain intervals
- each chain is stored as an implicit treap in top-to-bottom order
- query min/max by splitting the needed interval
- reverse a path by extracting all path pieces in path order, concatenating them,
  flipping the concatenated sequence once, then splitting and reinserting the
  pieces back into their original chain positions
*/

namespace {

struct Node {
    int val;
    int mn;
    int mx;
    int sz;
    uint32_t prio;
    bool rev;
    Node *left;
    Node *right;

    explicit Node(int value, uint32_t priority)
        : val(value),
          mn(value),
          mx(value),
          sz(1),
          prio(priority),
          rev(false),
          left(nullptr),
          right(nullptr) {}
};

int get_size(Node *node) {
    return node == nullptr ? 0 : node->sz;
}

int get_min(Node *node) {
    return node == nullptr ? 1000000007 : node->mn;
}

int get_max(Node *node) {
    return node == nullptr ? -1000000007 : node->mx;
}

void apply_reverse(Node *node) {
    if (node != nullptr) {
        node->rev = !node->rev;
    }
}

void push(Node *node) {
    if (node == nullptr || !node->rev) {
        return;
    }
    node->rev = false;
    swap(node->left, node->right);
    apply_reverse(node->left);
    apply_reverse(node->right);
}

void pull(Node *node) {
    if (node == nullptr) {
        return;
    }
    node->sz = 1 + get_size(node->left) + get_size(node->right);
    node->mn = min(node->val, min(get_min(node->left), get_min(node->right)));
    node->mx = max(node->val, max(get_max(node->left), get_max(node->right)));
}

Node *merge(Node *left, Node *right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    if (left->prio < right->prio) {
        push(left);
        left->right = merge(left->right, right);
        pull(left);
        return left;
    }
    push(right);
    right->left = merge(left, right->left);
    pull(right);
    return right;
}

void split(Node *root, int left_size, Node *&left, Node *&right) {
    if (root == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }
    push(root);
    if (get_size(root->left) >= left_size) {
        split(root->left, left_size, left, root->left);
        pull(root);
        right = root;
    } else {
        split(root->right, left_size - get_size(root->left) - 1, root->right, right);
        pull(root);
        left = root;
    }
}

struct IntervalResult {
    int mn;
    int mx;
};

struct Chain {
    vector<int> nodes;
    Node *root = nullptr;
};

struct Piece {
    int chain;
    int l;
    int r;
    bool reverse_in_path;
};

Node *extract_interval(Node *&root, int l, int r) {
    Node *left_part = nullptr;
    Node *middle = nullptr;
    Node *right_part = nullptr;
    split(root, r + 1, middle, right_part);
    split(middle, l, left_part, middle);
    root = merge(left_part, right_part);
    return middle;
}

void insert_interval(Node *&root, int pos, Node *segment) {
    Node *left_part = nullptr;
    Node *right_part = nullptr;
    split(root, pos, left_part, right_part);
    root = merge(merge(left_part, segment), right_part);
}

IntervalResult query_interval(Node *&root, int l, int r) {
    Node *left_part = nullptr;
    Node *middle = nullptr;
    Node *right_part = nullptr;
    split(root, r + 1, middle, right_part);
    split(middle, l, left_part, middle);
    IntervalResult result{get_min(middle), get_max(middle)};
    root = merge(merge(left_part, middle), right_part);
    return result;
}

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> weight(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> depth(n + 1, 0);
    vector<int> subtree(n + 1, 1);
    vector<int> heavy(n + 1, 0);
    vector<int> order;
    order.reserve(n);

    vector<int> stack;
    stack.reserve(n);
    stack.push_back(1);
    parent[1] = -1;

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (int v : graph[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            depth[v] = depth[u] + 1;
            stack.push_back(v);
        }
    }

    for (int idx = n - 1; idx >= 0; --idx) {
        int u = order[idx];
        int best_size = 0;
        for (int v : graph[u]) {
            if (v == parent[u]) {
                continue;
            }
            subtree[u] += subtree[v];
            if (subtree[v] > best_size) {
                best_size = subtree[v];
                heavy[u] = v;
            }
        }
    }

    vector<int> top(n + 1, 0);
    vector<int> chain_id(n + 1, -1);
    vector<int> chain_pos(n + 1, -1);
    vector<Chain> chains;
    chains.reserve(n);

    for (int u = 1; u <= n; ++u) {
        if (parent[u] != -1 && heavy[parent[u]] == u) {
            continue;
        }
        chains.push_back(Chain());
        int cid = static_cast<int>(chains.size()) - 1;
        int cur = u;
        while (cur != 0) {
            top[cur] = u;
            chain_id[cur] = cid;
            chain_pos[cur] = static_cast<int>(chains[cid].nodes.size());
            chains[cid].nodes.push_back(cur);
            cur = heavy[cur];
        }
    }

    mt19937 rng(712367821);
    for (Chain &chain : chains) {
        Node *root = nullptr;
        for (int node : chain.nodes) {
            root = merge(root, new Node(weight[node], rng()));
        }
        chain.root = root;
    }

    auto collect_path = [&](int u, int v) {
        vector<Piece> left;
        vector<Piece> right;

        while (top[u] != top[v]) {
            if (depth[top[u]] >= depth[top[v]]) {
                left.push_back(Piece{chain_id[u], chain_pos[top[u]], chain_pos[u], true});
                u = parent[top[u]];
            } else {
                right.push_back(Piece{chain_id[v], chain_pos[top[v]], chain_pos[v], false});
                v = parent[top[v]];
            }
        }

        if (depth[u] >= depth[v]) {
            left.push_back(Piece{chain_id[u], chain_pos[v], chain_pos[u], true});
        } else {
            right.push_back(Piece{chain_id[v], chain_pos[u], chain_pos[v], false});
        }

        vector<Piece> pieces = left;
        for (int i = static_cast<int>(right.size()) - 1; i >= 0; --i) {
            pieces.push_back(right[i]);
        }
        return pieces;
    };

    auto query_path = [&](int u, int v, bool want_min) {
        vector<Piece> pieces = collect_path(u, v);
        int answer = want_min ? 1000000007 : -1000000007;

        for (const Piece &piece : pieces) {
            IntervalResult current = query_interval(chains[piece.chain].root, piece.l, piece.r);
            if (want_min) {
                answer = min(answer, current.mn);
            } else {
                answer = max(answer, current.mx);
            }
        }
        return answer;
    };

    auto reverse_path = [&](int u, int v) {
        vector<Piece> pieces = collect_path(u, v);
        Node *path_root = nullptr;

        for (const Piece &piece : pieces) {
            Node *segment = extract_interval(chains[piece.chain].root, piece.l, piece.r);
            if (piece.reverse_in_path) {
                apply_reverse(segment);
            }
            path_root = merge(path_root, segment);
        }

        apply_reverse(path_root);

        for (const Piece &piece : pieces) {
            int len = piece.r - piece.l + 1;
            Node *segment = nullptr;
            split(path_root, len, segment, path_root);
            if (piece.reverse_in_path) {
                apply_reverse(segment);
            }
            insert_interval(chains[piece.chain].root, piece.l, segment);
        }
    };

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            cout << query_path(u, v, true) << '\n';
        } else if (type == 2) {
            cout << query_path(u, v, false) << '\n';
        } else {
            reverse_path(u, v);
        }
    }

    return 0;
}
