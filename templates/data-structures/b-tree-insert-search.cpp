// Template: B-Tree (Search + Insert)
// Signal: one high-fanout ordered dictionary where node splitting and separator
// keys are the real lesson, not binary rotations or contest-first order stats.
// Assumes: set semantics; duplicate inserts are ignored.
// Exposes: BTree<T>::contains() and insert().
// Complexity: O(MIN_DEGREE * log_{MIN_DEGREE}(n)) per operation in this simple
// in-memory starter.
// Main trap: descending into a full child during insert, instead of splitting
// it first.
// Links:
//   Topic: topics/data-structures/b-trees/README.md
//   Note: practice/ladders/data-structures/b-trees/btreedictionary.md

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, int MIN_DEGREE = 3>
struct BTree {
    static_assert(MIN_DEGREE >= 2, "B-tree minimum degree must be at least 2");

    struct Node {
        bool leaf = true;
        vector<T> keys;
        vector<Node*> children;
    };

    Node* root = nullptr;

    ~BTree() {
        destroy(root);
    }

    bool empty() const {
        return root == nullptr;
    }

    bool contains(const T& x) const {
        return contains(root, x);
    }

    void insert(const T& x) {
        if (root == nullptr) {
            root = new Node();
            root->keys.push_back(x);
            return;
        }
        if (contains(x)) {
            return;
        }
        if (is_full(root)) {
            Node* new_root = new Node();
            new_root->leaf = false;
            new_root->children.push_back(root);
            split_child(new_root, 0);
            root = new_root;
        }
        insert_nonfull(root, x);
    }

private:
    static constexpr int max_keys() {
        return 2 * MIN_DEGREE - 1;
    }

    static bool is_full(Node* u) {
        return static_cast<int>(u->keys.size()) == max_keys();
    }

    static bool contains(Node* u, const T& x) {
        if (u == nullptr) {
            return false;
        }
        int i = lower_bound(u->keys.begin(), u->keys.end(), x) - u->keys.begin();
        if (i < static_cast<int>(u->keys.size()) && u->keys[i] == x) {
            return true;
        }
        if (u->leaf) {
            return false;
        }
        return contains(u->children[i], x);
    }

    static void split_child(Node* parent, int idx) {
        Node* y = parent->children[idx];
        Node* z = new Node();
        z->leaf = y->leaf;

        const T mid = y->keys[MIN_DEGREE - 1];
        z->keys.assign(y->keys.begin() + MIN_DEGREE, y->keys.end());
        y->keys.resize(MIN_DEGREE - 1);

        if (!y->leaf) {
            z->children.assign(y->children.begin() + MIN_DEGREE, y->children.end());
            y->children.resize(MIN_DEGREE);
        }

        parent->keys.insert(parent->keys.begin() + idx, mid);
        parent->children.insert(parent->children.begin() + idx + 1, z);
    }

    static void insert_nonfull(Node* u, const T& x) {
        int i = lower_bound(u->keys.begin(), u->keys.end(), x) - u->keys.begin();
        if (u->leaf) {
            u->keys.insert(u->keys.begin() + i, x);
            return;
        }
        if (is_full(u->children[i])) {
            split_child(u, i);
            if (x > u->keys[i]) {
                i++;
            } else if (x == u->keys[i]) {
                return;
            }
        }
        insert_nonfull(u->children[i], x);
    }

    static void destroy(Node* u) {
        if (u == nullptr) {
            return;
        }
        for (Node* child : u->children) {
            destroy(child);
        }
        delete u;
    }
};

int main() {
    BTree<int, 3> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);

    cout << tree.contains(6) << '\n';
    cout << tree.contains(15) << '\n';
    tree.insert(15);
    cout << tree.contains(15) << '\n';
    return 0;
}
