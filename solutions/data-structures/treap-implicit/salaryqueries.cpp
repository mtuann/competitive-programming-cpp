// Problem: Salary Queries
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1144
// Topic: key-based treap, pair-key wrapper, dynamic range counts
// Idea: store each employee as the unique key (salary, id) in a key-based
// treap. Then count salaries in [a, b] by rank difference:
// order_of_key((b, n + 1)) - order_of_key((a, 0)).

#include <iostream>
#include <random>
#include <utility>
#include <vector>

using namespace std;

template <class Key, class Compare = less<Key>>
struct TreapOrderedSet {
    struct Node {
        Key key;
        uint32_t prior = 0;
        int size = 1;
        int left = -1;
        int right = -1;
    };

    int root = -1;
    vector<Node> nodes;
    Compare comp{};
    mt19937 rng{712367821u};

    bool contains(const Key& key) const {
        int v = root;
        while (v != -1) {
            if (equivalent(key, nodes[v].key)) {
                return true;
            }
            v = comp(key, nodes[v].key) ? nodes[v].left : nodes[v].right;
        }
        return false;
    }

    bool insert_unique(const Key& key) {
        if (contains(key)) {
            return false;
        }
        int a = -1, b = -1;
        split_less(root, key, a, b);
        root = merge(merge(a, make_node(key)), b);
        return true;
    }

    bool erase_key(const Key& key) {
        if (!contains(key)) {
            return false;
        }
        int a = -1, bc = -1, b = -1, c = -1;
        split_less(root, key, a, bc);
        split_leq(bc, key, b, c);
        root = merge(a, c);
        return true;
    }

    int order_of_key(const Key& key) const {
        return order_of_key(root, key);
    }

private:
    bool equivalent(const Key& a, const Key& b) const {
        return !comp(a, b) && !comp(b, a);
    }

    int size_of(int v) const {
        return v == -1 ? 0 : nodes[v].size;
    }

    int make_node(const Key& key) {
        nodes.push_back(Node{key, rng(), 1, -1, -1});
        return static_cast<int>(nodes.size()) - 1;
    }

    void pull(int v) {
        if (v == -1) {
            return;
        }
        nodes[v].size = 1 + size_of(nodes[v].left) + size_of(nodes[v].right);
    }

    int merge(int a, int b) {
        if (a == -1 || b == -1) {
            return a == -1 ? b : a;
        }
        if (nodes[a].prior > nodes[b].prior) {
            nodes[a].right = merge(nodes[a].right, b);
            pull(a);
            return a;
        }
        nodes[b].left = merge(a, nodes[b].left);
        pull(b);
        return b;
    }

    void split_less(int v, const Key& key, int& a, int& b) {
        if (v == -1) {
            a = b = -1;
            return;
        }
        if (comp(nodes[v].key, key)) {
            split_less(nodes[v].right, key, nodes[v].right, b);
            a = v;
            pull(a);
        } else {
            split_less(nodes[v].left, key, a, nodes[v].left);
            b = v;
            pull(b);
        }
    }

    void split_leq(int v, const Key& key, int& a, int& b) {
        if (v == -1) {
            a = b = -1;
            return;
        }
        if (!comp(key, nodes[v].key)) {
            split_leq(nodes[v].right, key, nodes[v].right, b);
            a = v;
            pull(a);
        } else {
            split_leq(nodes[v].left, key, a, nodes[v].left);
            b = v;
            pull(b);
        }
    }

    int order_of_key(int v, const Key& key) const {
        if (v == -1) {
            return 0;
        }
        if (comp(nodes[v].key, key)) {
            return size_of(nodes[v].left) + 1 + order_of_key(nodes[v].right, key);
        }
        return order_of_key(nodes[v].left, key);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> salary(n + 1);
    TreapOrderedSet<pair<int, int>> treap;

    for (int i = 1; i <= n; ++i) {
        cin >> salary[i];
        treap.insert_unique({salary[i], i});
    }

    while (q--) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            treap.erase_key({salary[k], k});
            salary[k] = x;
            treap.insert_unique({salary[k], k});
        } else {
            int a, b;
            cin >> a >> b;
            int ans = treap.order_of_key({b, n + 1}) - treap.order_of_key({a, 0});
            cout << ans << '\n';
        }
    }

    return 0;
}
