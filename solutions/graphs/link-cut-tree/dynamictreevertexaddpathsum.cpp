// Problem: Dynamic Tree Vertex Add Path Sum
// Judge: Library Checker
// Source URL: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
// Topic: dynamic forest, link-cut tree, preferred paths
// Idea: maintain the forest with a link-cut tree. For a path query on u -> v,
// makeroot(u) then access(v), so the whole path becomes one exposed auxiliary
// tree rooted at v and its subtree sum is the answer.

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    LinkCutPathSum lct(values);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        lct.link(u, v);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            lct.cut(a, b);
            lct.link(c, d);
        } else if (type == 1) {
            int p;
            long long x;
            cin >> p >> x;
            lct.add_value(p, x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << lct.path_sum(u, v) << '\n';
        }
    }

    return 0;
}
