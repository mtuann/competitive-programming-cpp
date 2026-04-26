#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, int MIN_DEGREE = 16>
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    BTree<long long> tree;
    while (q--) {
        char op;
        long long x;
        cin >> op >> x;
        if (op == '+') {
            tree.insert(x);
        } else if (op == '?') {
            cout << (tree.contains(x) ? 1 : 0) << '\n';
        }
    }
    return 0;
}
