// Template: Link-cut tree path sum
// Signal: dynamic forest with online link/cut operations, point adds on nodes,
// and path-sum queries on the current tree.
// Assumes: vertices are 0-indexed, values live on vertices, path queries only
// ask nodes in the same represented tree, and the first exact route is point
// add plus path sum rather than generic lazy or subtree support.
// Exposes: LinkCutPathSum(values) with connected(u, v), link(u, v), cut(u, v),
// add_value(u, delta), and path_sum(u, v).
// Complexity: amortized O(log n) per operation.
// Main trap: auxiliary splay roots are not represented-tree roots; always push
// reverse flags before rotating and do not overclaim subtree support.
// Links:
//   Topic: topics/graphs/link-cut-tree/README.md
//   Note: practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct LinkCutPathSum {
    struct Node {
        array<int, 2> ch{0, 0};
        int parent = 0;
        bool rev = false;
        long long val = 0;
        long long sum = 0;
    };

    int n = 0;
    vector<Node> tree;

    explicit LinkCutPathSum(const vector<long long>& values)
        : n(static_cast<int>(values.size())), tree(n + 1) {
        for (int i = 0; i < n; ++i) {
            tree[i + 1].val = values[i];
            tree[i + 1].sum = values[i];
        }
    }

    bool connected(int u, int v) {
        return find_root(idx(u)) == find_root(idx(v));
    }

    bool link(int u, int v) {
        int x = idx(u);
        int y = idx(v);
        make_root(x);
        if (find_root(y) == x) {
            return false;
        }
        tree[x].parent = y;
        return true;
    }

    bool cut(int u, int v) {
        int x = idx(u);
        int y = idx(v);
        make_root(x);
        access(y);
        if (tree[y].ch[0] != x || tree[x].ch[1] != 0) {
            return false;
        }
        tree[y].ch[0] = 0;
        tree[x].parent = 0;
        pull(y);
        return true;
    }

    void add_value(int u, long long delta) {
        int x = idx(u);
        access(x);
        tree[x].val += delta;
        pull(x);
    }

    long long path_sum(int u, int v) {
        int x = idx(u);
        int y = idx(v);
        assert(find_root(x) == find_root(y));
        make_root(x);
        access(y);
        return tree[y].sum;
    }

private:
    int idx(int u) const {
        return u + 1;
    }

    bool is_splay_root(int x) const {
        int p = tree[x].parent;
        return p == 0 || (tree[p].ch[0] != x && tree[p].ch[1] != x);
    }

    void pull(int x) {
        tree[x].sum = tree[tree[x].ch[0]].sum + tree[x].val + tree[tree[x].ch[1]].sum;
    }

    void toggle_rev(int x) {
        if (x == 0) {
            return;
        }
        swap(tree[x].ch[0], tree[x].ch[1]);
        tree[x].rev = !tree[x].rev;
    }

    void push(int x) {
        if (!tree[x].rev) {
            return;
        }
        toggle_rev(tree[x].ch[0]);
        toggle_rev(tree[x].ch[1]);
        tree[x].rev = false;
    }

    void push_path(int x) {
        vector<int> path;
        path.reserve(32);
        int y = x;
        path.push_back(y);
        while (!is_splay_root(y)) {
            y = tree[y].parent;
            path.push_back(y);
        }
        reverse(path.begin(), path.end());
        for (int node : path) {
            push(node);
        }
    }

    void rotate(int x) {
        int p = tree[x].parent;
        int g = tree[p].parent;
        int dir = (tree[p].ch[1] == x);
        int beta = tree[x].ch[dir ^ 1];

        if (!is_splay_root(p)) {
            tree[g].ch[tree[g].ch[1] == p] = x;
        }
        tree[x].parent = g;

        tree[x].ch[dir ^ 1] = p;
        tree[p].parent = x;

        tree[p].ch[dir] = beta;
        if (beta != 0) {
            tree[beta].parent = p;
        }

        pull(p);
        pull(x);
    }

    void splay(int x) {
        push_path(x);
        while (!is_splay_root(x)) {
            int p = tree[x].parent;
            int g = tree[p].parent;
            if (!is_splay_root(p)) {
                bool zigzig = (tree[p].ch[0] == x) == (tree[g].ch[0] == p);
                rotate(zigzig ? p : x);
            }
            rotate(x);
        }
    }

    void access(int x) {
        int last = 0;
        for (int y = x; y != 0; y = tree[y].parent) {
            splay(y);
            tree[y].ch[1] = last;
            pull(y);
            last = y;
        }
        splay(x);
    }

    void make_root(int x) {
        access(x);
        toggle_rev(x);
    }

    int find_root(int x) {
        access(x);
        while (tree[x].ch[0] != 0) {
            push(x);
            x = tree[x].ch[0];
        }
        splay(x);
        return x;
    }
};

int main() {
    vector<long long> values = {1, 2, 3};
    LinkCutPathSum lct(values);
    lct.link(0, 1);
    lct.link(1, 2);

    cout << lct.path_sum(0, 2) << '\n';
    lct.add_value(1, 5);
    cout << lct.path_sum(0, 2) << '\n';
    return 0;
}
