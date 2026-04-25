// Problem: Necessary Roads
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2076
// Topic: bridges, low-link, DFS tree
// Idea: run one DFS on the undirected graph, compute tin/low, and every tree
// edge (v, to) with low[to] > tin[v] is a necessary road.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct LowlinkUndirected {
    struct AdjEdge {
        int to, id;
    };

    int n;
    vector<pair<int, int>> edges;
    vector<vector<AdjEdge>> g;
    vector<int> tin, low, parent, parent_edge, iter;
    vector<pair<int, int>> bridges;

    explicit LowlinkUndirected(int n)
        : n(n),
          g(n),
          tin(n, -1),
          low(n, -1),
          parent(n, -1),
          parent_edge(n, -1),
          iter(n, 0) {}

    void add_edge(int u, int v) {
        int id = (int)edges.size();
        edges.push_back({u, v});
        g[u].push_back({v, id});
        g[v].push_back({u, id});
    }

    void build() {
        fill(tin.begin(), tin.end(), -1);
        fill(low.begin(), low.end(), -1);
        fill(parent.begin(), parent.end(), -1);
        fill(parent_edge.begin(), parent_edge.end(), -1);
        fill(iter.begin(), iter.end(), 0);
        bridges.clear();

        int timer = 0;
        vector<int> st;
        st.reserve(n);

        for (int start = 0; start < n; ++start) {
            if (tin[start] != -1) {
                continue;
            }
            st.push_back(start);
            while (!st.empty()) {
                int v = st.back();
                if (tin[v] == -1) {
                    tin[v] = low[v] = timer++;
                }

                if (iter[v] < (int)g[v].size()) {
                    auto [to, id] = g[v][iter[v]++];
                    if (id == parent_edge[v]) {
                        continue;
                    }
                    if (tin[to] == -1) {
                        parent[to] = v;
                        parent_edge[to] = id;
                        st.push_back(to);
                    } else if (tin[to] < tin[v]) {
                        low[v] = min(low[v], tin[to]);
                    }
                    continue;
                }

                st.pop_back();
                int p = parent[v];
                if (p != -1) {
                    low[p] = min(low[p], low[v]);
                    if (low[v] > tin[p]) {
                        bridges.push_back(edges[parent_edge[v]]);
                    }
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    LowlinkUndirected low(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        low.add_edge(a, b);
    }

    low.build();

    cout << low.bridges.size() << '\n';
    for (auto [u, v] : low.bridges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    return 0;
}
