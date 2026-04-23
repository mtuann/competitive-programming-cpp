// Problem: COMPANYQUERIES2 - Company Queries II
// Judge: CSES
// URL: https://cses.fi/problemset/task/1688
// Topic: LCA, binary lifting
// Idea: store up[k][v] = the 2^k-th ancestor of v. For each query, first lift
// the deeper node to the same depth, then lift both nodes together from large
// powers to small powers until they become children of the answer.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct LCA {
    int n;
    int logn;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> children;

    explicit LCA(int n) : n(n), logn(1), depth(n + 1, 0), children(n + 1) {
        while ((1 << logn) <= n) {
            ++logn;
        }
        up.assign(logn, vector<int>(n + 1, 1));
    }

    void add_child(int parent, int child) {
        children[parent].push_back(child);
    }

    void build(int root) {
        vector<int> order;
        order.reserve(n);
        order.push_back(root);

        up[0][root] = root;
        for (int k = 1; k < logn; ++k) {
            up[k][root] = root;
        }

        for (int i = 0; i < static_cast<int>(order.size()); ++i) {
            int u = order[i];
            for (int v : children[u]) {
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                for (int k = 1; k < logn; ++k) {
                    up[k][v] = up[k - 1][up[k - 1][v]];
                }
                order.push_back(v);
            }
        }
    }

    int lift(int u, int dist) const {
        for (int k = 0; k < logn; ++k) {
            if (dist & (1 << k)) {
                u = up[k][u];
            }
        }
        return u;
    }

    int query(int a, int b) const {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }

        a = lift(a, depth[a] - depth[b]);
        if (a == b) {
            return a;
        }

        for (int k = logn - 1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return up[0][a];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    LCA lca(n);
    for (int employee = 2; employee <= n; ++employee) {
        int boss;
        cin >> boss;
        lca.add_child(boss, employee);
    }

    lca.build(1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca.query(a, b) << '\n';
    }

    return 0;
}
