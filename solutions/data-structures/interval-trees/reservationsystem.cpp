#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>

using namespace std;

struct IntervalTree {
    struct Node {
        int l = 0;
        int r = 0;
        int max_r = 0;
        uint64_t priority = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root = nullptr;

    ~IntervalTree() {
        destroy(root);
    }

    void insert_interval(int l, int r) {
        Node* item = new Node{l, r, r, next_priority(), nullptr, nullptr};
        if (!insert(root, item)) {
            delete item;
        }
    }

    bool any_overlap(int ql, int qr) const {
        return find_any_overlap(root, ql, qr) != nullptr;
    }

private:
    static int subtree_max_r(Node* t) {
        return t == nullptr ? numeric_limits<int>::lowest() : t->max_r;
    }

    static bool key_less(int l1, int r1, int l2, int r2) {
        return l1 < l2 || (l1 == l2 && r1 < r2);
    }

    static bool overlaps(int l1, int r1, int l2, int r2) {
        return max(l1, l2) < min(r1, r2);
    }

    static uint64_t next_priority() {
        static uint64_t state = 0x9e3779b97f4a7c15ULL;
        state += 0x9e3779b97f4a7c15ULL;
        uint64_t z = state;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }

    static void pull(Node* t) {
        if (t == nullptr) {
            return;
        }
        t->max_r = max(t->r, max(subtree_max_r(t->left), subtree_max_r(t->right)));
    }

    static void rotate_left(Node*& t) {
        Node* child = t->right;
        t->right = child->left;
        child->left = t;
        pull(t);
        pull(child);
        t = child;
    }

    static void rotate_right(Node*& t) {
        Node* child = t->left;
        t->left = child->right;
        child->right = t;
        pull(t);
        pull(child);
        t = child;
    }

    static bool insert(Node*& t, Node* item) {
        if (t == nullptr) {
            t = item;
            return true;
        }
        if (t->l == item->l && t->r == item->r) {
            return false;
        }
        bool inserted = false;
        if (key_less(item->l, item->r, t->l, t->r)) {
            inserted = insert(t->left, item);
            if (inserted && t->left->priority > t->priority) {
                rotate_right(t);
            }
        } else {
            inserted = insert(t->right, item);
            if (inserted && t->right->priority > t->priority) {
                rotate_left(t);
            }
        }
        pull(t);
        return inserted;
    }

    static Node* find_any_overlap(Node* t, int ql, int qr) {
        if (t == nullptr) {
            return nullptr;
        }
        if (t->left != nullptr && t->left->max_r > ql) {
            Node* left_hit = find_any_overlap(t->left, ql, qr);
            if (left_hit != nullptr) {
                return left_hit;
            }
        }
        if (overlaps(t->l, t->r, ql, qr)) {
            return t;
        }
        if (t->l < qr) {
            return find_any_overlap(t->right, ql, qr);
        }
        return nullptr;
    }

    static void destroy(Node* t) {
        if (t == nullptr) {
            return;
        }
        destroy(t->left);
        destroy(t->right);
        delete t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;

    IntervalTree tree;
    for (int i = 0; i < n; i++) {
        int s, f;
        cin >> s >> f;
        tree.insert_interval(s, f);
    }

    cout << (tree.any_overlap(a, b) ? 1 : 0) << '\n';
    return 0;
}
