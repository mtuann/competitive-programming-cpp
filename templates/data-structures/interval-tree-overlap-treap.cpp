// Template: Interval Tree (Treap-Balanced)
// Signal: one live set of half-open intervals where insert / erase / any-overlap
// query are the whole state, and the real invariant is subtree max-right.
// Assumes: intervals are unique exact pairs [l, r) with l < r.
// Exposes: IntervalTree with insert_interval(), erase_interval(), any_overlap(),
// and find_any_overlap().
// Complexity: expected O(log n) per operation.
// Main trap: mixing half-open overlap semantics with closed intervals, or
// forgetting to recompute subtree max_r after every structural change.
// Links:
//   Topic: topics/data-structures/interval-trees/README.md
//   Note: practice/ladders/data-structures/interval-trees/reservationsystem.md

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <utility>

using namespace std;

struct IntervalTree {
    struct Node {
        long long l = 0;
        long long r = 0;
        long long max_r = 0;
        uint64_t priority = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root = nullptr;

    ~IntervalTree() {
        destroy(root);
    }

    bool empty() const {
        return root == nullptr;
    }

    bool insert_interval(long long l, long long r) {
        assert(l < r);
        Node* item = new Node{l, r, r, next_priority(), nullptr, nullptr};
        if (!insert(root, item)) {
            delete item;
            return false;
        }
        return true;
    }

    bool erase_interval(long long l, long long r) {
        if (l >= r) {
            return false;
        }
        return erase(root, l, r);
    }

    bool any_overlap(long long ql, long long qr) const {
        if (ql >= qr) {
            return false;
        }
        return find_any_overlap(root, ql, qr) != nullptr;
    }

    bool find_any_overlap(long long ql, long long qr,
                          pair<long long, long long>& out) const {
        if (ql >= qr) {
            return false;
        }
        Node* hit = find_any_overlap(root, ql, qr);
        if (hit == nullptr) {
            return false;
        }
        out = {hit->l, hit->r};
        return true;
    }

private:
    static long long subtree_max_r(Node* t) {
        return t == nullptr ? numeric_limits<long long>::lowest() : t->max_r;
    }

    static bool key_less(long long l1, long long r1, long long l2, long long r2) {
        return l1 < l2 || (l1 == l2 && r1 < r2);
    }

    static bool overlaps(long long l1, long long r1, long long l2, long long r2) {
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

    static Node* merge(Node* a, Node* b) {
        if (a == nullptr) {
            return b;
        }
        if (b == nullptr) {
            return a;
        }
        if (a->priority > b->priority) {
            a->right = merge(a->right, b);
            pull(a);
            return a;
        }
        b->left = merge(a, b->left);
        pull(b);
        return b;
    }

    static bool erase(Node*& t, long long l, long long r) {
        if (t == nullptr) {
            return false;
        }
        if (t->l == l && t->r == r) {
            Node* old = t;
            t = merge(t->left, t->right);
            delete old;
            return true;
        }
        bool erased = false;
        if (key_less(l, r, t->l, t->r)) {
            erased = erase(t->left, l, r);
        } else {
            erased = erase(t->right, l, r);
        }
        pull(t);
        return erased;
    }

    static Node* find_any_overlap(Node* t, long long ql, long long qr) {
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
    IntervalTree tree;
    tree.insert_interval(1, 4);
    tree.insert_interval(7, 10);

    cout << tree.any_overlap(4, 5) << '\n';

    pair<long long, long long> hit;
    bool found = tree.find_any_overlap(3, 7, hit);
    if (found) {
        cout << hit.first << ' ' << hit.second << '\n';
    } else {
        cout << "-1 -1\n";
    }

    tree.erase_interval(1, 4);
    cout << tree.any_overlap(3, 7) << '\n';
    return 0;
}
