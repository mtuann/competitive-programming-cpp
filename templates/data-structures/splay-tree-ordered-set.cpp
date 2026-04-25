// Template: Splay Tree Ordered Multiset
// Signal: one self-adjusting ordered set where you explicitly want to learn
// rotate/splay machinery, or you want a direct bridge into link-cut tree.
// Assumes: keys are comparable with <; duplicates are stored through cnt.
// Exposes: SplayOrderedMultiset with contains(), insert(), erase_one(),
// count_less(), kth_zero_based(), predecessor(), successor(), size(), empty().
// Complexity: amortized O(log n) per operation.
// Main trap: forgetting to update parent pointers and subtree sizes after
// rotations, or treating amortized time as worst-case per operation.
// Links:
//   Topic: topics/data-structures/splay-tree/README.md
//   Note: practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md

#include <iostream>
#include <vector>

using namespace std;

struct SplayOrderedMultiset {
    struct Node {
        int ch[2] = {0, 0};
        int parent = 0;
        int key = 0;
        int cnt = 0;
        int size = 0;
    };

    vector<Node> t{{}};
    int root = 0;

    bool empty() const {
        return root == 0;
    }

    int size() const {
        return subtree_size(root);
    }

    bool contains(int key) {
        int v = find_node(key);
        return v != 0 && t[root].key == key;
    }

    void insert(int key) {
        if (root == 0) {
            root = make_node(key);
            return;
        }
        int v = root;
        int p = 0;
        while (v != 0) {
            p = v;
            if (t[v].key == key) {
                t[v].cnt++;
                pull(v);
                splay(v);
                return;
            }
            v = t[v].ch[key > t[p].key];
        }
        int x = make_node(key);
        t[x].parent = p;
        t[p].ch[key > t[p].key] = x;
        pull(p);
        splay(x);
    }

    bool erase_one(int key) {
        int v = find_node(key);
        if (v == 0 || t[root].key != key) {
            return false;
        }
        if (t[root].cnt > 1) {
            t[root].cnt--;
            pull(root);
            return true;
        }
        if (t[root].ch[0] == 0) {
            root = t[root].ch[1];
            if (root != 0) {
                t[root].parent = 0;
            }
            return true;
        }
        if (t[root].ch[1] == 0) {
            root = t[root].ch[0];
            if (root != 0) {
                t[root].parent = 0;
            }
            return true;
        }

        int left_root = t[root].ch[0];
        int right_root = t[root].ch[1];
        t[left_root].parent = 0;
        t[right_root].parent = 0;

        root = left_root;
        int x = root;
        while (t[x].ch[1] != 0) {
            x = t[x].ch[1];
        }
        splay(x);
        t[root].ch[1] = right_root;
        t[right_root].parent = root;
        pull(root);
        return true;
    }

    int count_less(int key) {
        int v = root;
        int last = 0;
        int answer = 0;
        while (v != 0) {
            last = v;
            if (key <= t[v].key) {
                v = t[v].ch[0];
            } else {
                answer += subtree_size(t[v].ch[0]) + t[v].cnt;
                v = t[v].ch[1];
            }
        }
        if (last != 0) {
            splay(last);
        }
        return answer;
    }

    bool kth_zero_based(int k, int& out) {
        if (k < 0 || k >= size()) {
            return false;
        }
        int v = root;
        while (v != 0) {
            int left_size = subtree_size(t[v].ch[0]);
            if (k < left_size) {
                v = t[v].ch[0];
            } else if (k < left_size + t[v].cnt) {
                splay(v);
                out = t[v].key;
                return true;
            } else {
                k -= left_size + t[v].cnt;
                v = t[v].ch[1];
            }
        }
        return false;
    }

    bool predecessor(int key, int& out) {
        int v = root;
        int last = 0;
        int best = 0;
        while (v != 0) {
            last = v;
            if (t[v].key < key) {
                best = v;
                v = t[v].ch[1];
            } else {
                v = t[v].ch[0];
            }
        }
        if (best != 0) {
            splay(best);
            out = t[root].key;
            return true;
        }
        if (last != 0) {
            splay(last);
        }
        return false;
    }

    bool successor(int key, int& out) {
        int v = root;
        int last = 0;
        int best = 0;
        while (v != 0) {
            last = v;
            if (t[v].key > key) {
                best = v;
                v = t[v].ch[0];
            } else {
                v = t[v].ch[1];
            }
        }
        if (best != 0) {
            splay(best);
            out = t[root].key;
            return true;
        }
        if (last != 0) {
            splay(last);
        }
        return false;
    }

private:
    int subtree_size(int x) const {
        return x == 0 ? 0 : t[x].size;
    }

    int make_node(int key) {
        t.push_back(Node{});
        int id = static_cast<int>(t.size()) - 1;
        t[id].key = key;
        t[id].cnt = 1;
        t[id].size = 1;
        return id;
    }

    void pull(int x) {
        if (x == 0) {
            return;
        }
        t[x].size = t[x].cnt + subtree_size(t[x].ch[0]) + subtree_size(t[x].ch[1]);
    }

    bool is_right_child(int x) const {
        int p = t[x].parent;
        return p != 0 && t[p].ch[1] == x;
    }

    bool is_aux_root(int x) const {
        int p = t[x].parent;
        return p == 0 || (t[p].ch[0] != x && t[p].ch[1] != x);
    }

    void rotate(int x) {
        int p = t[x].parent;
        int g = t[p].parent;
        int dir = is_right_child(x);
        int b = t[x].ch[dir ^ 1];

        if (!is_aux_root(p)) {
            t[g].ch[t[g].ch[1] == p] = x;
        }
        t[x].parent = g;

        t[x].ch[dir ^ 1] = p;
        t[p].parent = x;

        t[p].ch[dir] = b;
        if (b != 0) {
            t[b].parent = p;
        }

        pull(p);
        pull(x);
    }

    void splay(int x) {
        while (!is_aux_root(x)) {
            int p = t[x].parent;
            int g = t[p].parent;
            if (!is_aux_root(p)) {
                if (is_right_child(x) == is_right_child(p)) {
                    rotate(p);
                } else {
                    rotate(x);
                }
            }
            rotate(x);
        }
        root = x;
    }

    int find_node(int key) {
        int v = root;
        int last = 0;
        while (v != 0) {
            last = v;
            if (t[v].key == key) {
                splay(v);
                return v;
            }
            v = t[v].ch[key > t[v].key];
        }
        if (last != 0) {
            splay(last);
        }
        return 0;
    }
};

int main() {
    SplayOrderedMultiset splay;
    splay.insert(7);
    splay.insert(2);
    splay.insert(10);
    splay.insert(7);

    int kth = -1;
    splay.kth_zero_based(2, kth);
    cout << kth << '\n';
    cout << splay.count_less(8) << '\n';
    return 0;
}
