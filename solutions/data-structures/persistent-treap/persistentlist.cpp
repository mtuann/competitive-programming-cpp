#include <cstdint>
#include <iostream>
#include <random>
#include <string>
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    PersistentTreapList treap;
    vector<int> roots;
    roots.reserve(n + 2);
    roots.push_back(-1);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        roots.push_back(treap.singleton(x));
    }

    int q;
    cin >> q;
    while (q--) {
        string type;
        cin >> type;
        if (type == "merge") {
            int i, j;
            cin >> i >> j;
            int root = treap.merge(roots[i], roots[j]);
            roots.push_back(root);
            cout << treap.total_sum(root) << '\n';
        } else if (type == "head") {
            int i;
            cin >> i;
            auto [a, b] = treap.split_prefix(roots[i], 1);
            roots.push_back(a);
            cout << treap.total_sum(a) << '\n';
            roots.push_back(b);
            cout << treap.total_sum(b) << '\n';
        } else if (type == "tail") {
            int i;
            cin >> i;
            auto [a, b] = treap.split_prefix(roots[i], treap.size(roots[i]) - 1);
            roots.push_back(a);
            cout << treap.total_sum(a) << '\n';
            roots.push_back(b);
            cout << treap.total_sum(b) << '\n';
        }
    }

    return 0;
}
