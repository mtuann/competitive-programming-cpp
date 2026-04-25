// Template: Key-Based Treap Ordered Set
// Signal: self-hosted ordered set with split/merge by key, online rank / k-th,
// or one PBDS-free route where explicit key order is the real invariant.
// Assumes: keys are unique under the comparator; duplicates should be wrapped
// into unique keys such as (value, id) pairs before insertion.
// Exposes: TreapOrderedSet<Key> with contains(), insert_unique(), erase_key(),
// order_of_key(), kth_key(), size(), and empty().
// Complexity: expected O(log n) per insert, erase, rank, or k-th query.
// Main trap: forgetting this is key-based treap semantics, not implicit
// position semantics, or forgetting to make duplicate keys unique first.
// Links:
//   Topic: topics/data-structures/treap-implicit/README.md
//   Note: practice/ladders/data-structures/treap-implicit/salaryqueries.md

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

    bool empty() const {
        return root == -1;
    }

    int size() const {
        return size_of(root);
    }

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

    bool kth_key(int k, Key& out) const {
        if (k < 0 || k >= size()) {
            return false;
        }
        int v = root;
        while (v != -1) {
            int left_size = size_of(nodes[v].left);
            if (k < left_size) {
                v = nodes[v].left;
            } else if (k == left_size) {
                out = nodes[v].key;
                return true;
            } else {
                k -= left_size + 1;
                v = nodes[v].right;
            }
        }
        return false;
    }

private:
    int size_of(int v) const {
        return v == -1 ? 0 : nodes[v].size;
    }

    bool equivalent(const Key& a, const Key& b) const {
        return !comp(a, b) && !comp(b, a);
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
    TreapOrderedSet<int> treap;
    treap.insert_unique(7);
    treap.insert_unique(2);
    treap.insert_unique(10);

    int kth = -1;
    treap.kth_key(1, kth);
    cout << kth << '\n';
    cout << treap.order_of_key(8) << '\n';
    return 0;
}
