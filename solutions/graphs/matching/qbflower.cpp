// Problem: QBFLOWER - Tang hoa
// Judge: VN SPOJ / VNOJ mirror
// Source URL: https://vn.spoj.com/problems/QBFLOWER/
// Mirror URL: https://oj.vnoi.info/problem/qbflower
// Topic: General graph matching / minimum edge cover
// Idea: answer = N - maximum_matching, solved with Edmonds' blossom algorithm

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct EdmondsBlossom {
    int n;
    vector<vector<int>> g;
    vector<int> match, parent, base, q;
    vector<char> used, blossom;
    int qh, qt;

    explicit EdmondsBlossom(int n)
        : n(n),
          g(n),
          match(n, -1),
          parent(n),
          base(n),
          q(n),
          used(n),
          blossom(n) {}

    void add_edge(int u, int v) {
        if (u == v) return;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lca(int a, int b) {
        vector<char> seen(n, 0);
        while (true) {
            a = base[a];
            seen[a] = 1;
            if (match[a] == -1) break;
            a = parent[match[a]];
        }
        while (true) {
            b = base[b];
            if (seen[b]) return b;
            if (match[b] == -1) break;
            b = parent[match[b]];
        }
        return -1;
    }

    void mark_path(int v, int b, int child) {
        while (base[v] != b) {
            blossom[base[v]] = blossom[base[match[v]]] = 1;
            parent[v] = child;
            child = match[v];
            v = parent[match[v]];
        }
    }

    bool find_path(int root) {
        fill(used.begin(), used.end(), 0);
        fill(parent.begin(), parent.end(), -1);
        iota(base.begin(), base.end(), 0);

        qh = qt = 0;
        q[qt++] = root;
        used[root] = 1;

        while (qh < qt) {
            int v = q[qh++];
            for (int u : g[v]) {
                if (base[v] == base[u] || match[v] == u) continue;

                if (u == root || (match[u] != -1 && parent[match[u]] != -1)) {
                    int cur_base = lca(v, u);
                    fill(blossom.begin(), blossom.end(), 0);
                    mark_path(v, cur_base, u);
                    mark_path(u, cur_base, v);

                    for (int i = 0; i < n; ++i) {
                        if (blossom[base[i]]) {
                            base[i] = cur_base;
                            if (!used[i]) {
                                used[i] = 1;
                                q[qt++] = i;
                            }
                        }
                    }
                } else if (parent[u] == -1) {
                    parent[u] = v;
                    if (match[u] == -1) {
                        int cur = u;
                        while (cur != -1) {
                            int pv = parent[cur];
                            int nv = (pv == -1 ? -1 : match[pv]);
                            match[cur] = pv;
                            if (pv != -1) match[pv] = cur;
                            cur = nv;
                        }
                        return true;
                    }

                    u = match[u];
                    used[u] = 1;
                    q[qt++] = u;
                }
            }
        }

        return false;
    }

    int maximum_matching() {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (match[i] == -1 && find_path(i)) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    EdmondsBlossom solver(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        if (a != b) {
            solver.add_edge(a, b);
        }
    }

    cout << n - solver.maximum_matching() << '\n';
    return 0;
}
