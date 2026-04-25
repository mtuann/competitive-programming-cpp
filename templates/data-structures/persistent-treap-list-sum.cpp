// Template: persistent treap (branching list roots, split/merge, subtree sum)
// Signal: old list versions stay alive while new operations concatenate or split
// whole sequences into new versions instead of mutating one current list.
// Assumes: implicit-position semantics; zero-based split counts; values are
// aggregated modulo 1e9+7; no lazy tags or key-based ordered-set API here.
// Exposes: PersistentTreapList with singleton(), merge(), split_prefix(),
// size(), total_sum(), and to_vector().
// Complexity: expected O(log n) new nodes per merge or split.
// Main trap: rewriting a shared node during merge/split instead of cloning it
// first, which corrupts old versions.
// Links:
//   Topic: topics/data-structures/persistent-treap/README.md
//   Note: practice/ladders/data-structures/persistent-treap/persistentlist.md

#include <cstdint>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using namespace std;

struct PersistentTreapList {
    static constexpr int MOD = 1000000007;

    struct Node {
        int value = 0;
        int sum = 0;
        int size = 1;
        uint32_t prior = 0;
        int left = -1;
        int right = -1;
    };

    vector<Node> nodes;
    mt19937 rng{712367821u};

    int singleton(long long value) {
        int value_mod = static_cast<int>(value % MOD);
        if (value_mod < 0) {
            value_mod += MOD;
        }
        nodes.push_back(Node{value_mod, value_mod, 1, rng(), -1, -1});
        return static_cast<int>(nodes.size()) - 1;
    }

    int size(int root) const {
        return root == -1 ? 0 : nodes[root].size;
    }

    int total_sum(int root) const {
        return root == -1 ? 0 : nodes[root].sum;
    }

    int merge(int a, int b) {
        if (a == -1 || b == -1) {
            return a == -1 ? b : a;
        }
        if (nodes[a].prior > nodes[b].prior) {
            int cur = clone_node(a);
            nodes[cur].right = merge(nodes[cur].right, b);
            pull(cur);
            return cur;
        }
        int cur = clone_node(b);
        nodes[cur].left = merge(a, nodes[cur].left);
        pull(cur);
        return cur;
    }

    pair<int, int> split_prefix(int root, int k) {
        if (root == -1) {
            return {-1, -1};
        }
        int left_size = size(nodes[root].left);
        if (k <= left_size) {
            int cur = clone_node(root);
            auto [a, b] = split_prefix(nodes[cur].left, k);
            nodes[cur].left = b;
            pull(cur);
            return {a, cur};
        }
        int cur = clone_node(root);
        auto [a, b] = split_prefix(nodes[cur].right, k - left_size - 1);
        nodes[cur].right = a;
        pull(cur);
        return {cur, b};
    }

    vector<int> to_vector(int root) const {
        vector<int> out;
        out.reserve(size(root));
        dfs(root, out);
        return out;
    }

private:
    int clone_node(int v) {
        nodes.push_back(nodes[v]);
        return static_cast<int>(nodes.size()) - 1;
    }

    void pull(int v) {
        if (v == -1) {
            return;
        }
        nodes[v].size = 1 + size(nodes[v].left) + size(nodes[v].right);
        long long sum = nodes[v].value;
        if (nodes[v].left != -1) {
            sum += nodes[nodes[v].left].sum;
        }
        if (nodes[v].right != -1) {
            sum += nodes[nodes[v].right].sum;
        }
        nodes[v].sum = static_cast<int>(sum % MOD);
    }

    void dfs(int v, vector<int>& out) const {
        if (v == -1) {
            return;
        }
        dfs(nodes[v].left, out);
        out.push_back(nodes[v].value);
        dfs(nodes[v].right, out);
    }
};

int main() {
    PersistentTreapList treap;
    int a = treap.singleton(1);
    int b = treap.singleton(2);
    int c = treap.singleton(3);

    int ab = treap.merge(a, b);
    int abc = treap.merge(ab, c);
    auto [head, rest] = treap.split_prefix(abc, 1);

    cout << treap.total_sum(head) << '\n';
    cout << treap.total_sum(rest) << '\n';
    return 0;
}
