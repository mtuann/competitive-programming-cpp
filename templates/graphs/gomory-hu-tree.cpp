// Template: Gomory-Hu tree
// Signal: one undirected weighted graph needs many pairwise min-cut answers,
// or one offline task first compresses all pairwise min-cuts into one tree.
// Assumes: vertices are 0-indexed, capacities are nonnegative long long, the
// graph is undirected, and the exact first route is "build the cut tree"
// rather than solving a later query layer.
// Exposes: GomoryHuTree(n) with add_edge(u, v, cap) and build(), returning
// parent/cut information plus the final weighted cut-tree edges.
// Complexity: n - 1 max-flow runs, each on the full undirected graph.
// Main trap: only valid for undirected graphs; pairwise answers come from
// taking the minimum edge weight on a tree path, not summing weights.
// Links:
//   Topic: topics/graphs/gomory-hu/README.md
//   Note: practice/ladders/graphs/gomory-hu/mcquery.md

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct GomoryHuTree {
    struct OriginalEdge {
        int u = 0;
        int v = 0;
        long long cap = 0;
    };

    struct TreeEdge {
        int u = 0;
        int v = 0;
        long long cut = 0;
    };

    struct Dinic {
        struct Edge {
            int to = 0;
            int rev = 0;
            long long cap = 0;
        };

        int n = 0;
        vector<vector<Edge> > g;
        vector<int> level;
        vector<int> ptr;

        explicit Dinic(int n) : n(n), g(n), level(n), ptr(n) {}

        void add_directed(int u, int v, long long cap) {
            Edge a{v, static_cast<int>(g[v].size()), cap};
            Edge b{u, static_cast<int>(g[u].size()), 0};
            g[u].push_back(a);
            g[v].push_back(b);
        }

        void add_undirected(int u, int v, long long cap) {
            add_directed(u, v, cap);
            add_directed(v, u, cap);
        }

        bool bfs(int s, int t) {
            fill(level.begin(), level.end(), -1);
            queue<int> q;
            level[s] = 0;
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const Edge& e : g[u]) {
                    if (e.cap > 0 && level[e.to] == -1) {
                        level[e.to] = level[u] + 1;
                        q.push(e.to);
                    }
                }
            }
            return level[t] != -1;
        }

        long long dfs(int u, int t, long long pushed) {
            if (u == t || pushed == 0) {
                return pushed;
            }
            for (int& cid = ptr[u]; cid < static_cast<int>(g[u].size()); ++cid) {
                Edge& e = g[u][cid];
                if (e.cap == 0 || level[e.to] != level[u] + 1) {
                    continue;
                }
                long long tr = dfs(e.to, t, min(pushed, e.cap));
                if (tr == 0) {
                    continue;
                }
                e.cap -= tr;
                g[e.to][e.rev].cap += tr;
                return tr;
            }
            return 0;
        }

        long long max_flow(int s, int t) {
            long long flow = 0;
            const long long kInf = (1LL << 60);
            while (bfs(s, t)) {
                fill(ptr.begin(), ptr.end(), 0);
                while (long long pushed = dfs(s, t, kInf)) {
                    flow += pushed;
                }
            }
            return flow;
        }

        vector<char> reachable_from(int s) const {
            vector<char> vis(n, 0);
            queue<int> q;
            q.push(s);
            vis[s] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const Edge& e : g[u]) {
                    if (e.cap > 0 && !vis[e.to]) {
                        vis[e.to] = 1;
                        q.push(e.to);
                    }
                }
            }
            return vis;
        }
    };

    int n = 0;
    vector<OriginalEdge> edges;
    vector<int> parent;
    vector<long long> cut_to_parent;
    vector<vector<pair<int, long long> > > tree;

    explicit GomoryHuTree(int n)
        : n(n), parent(n, -1), cut_to_parent(n, 0), tree(n) {}

    void add_edge(int u, int v, long long cap) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(u != v);
        assert(cap >= 0);
        edges.push_back({u, v, cap});
    }

    vector<TreeEdge> build() {
        if (n == 0) {
            return {};
        }
        fill(parent.begin(), parent.end(), 0);
        fill(cut_to_parent.begin(), cut_to_parent.end(), 0);
        parent[0] = -1;

        for (int s = 1; s < n; ++s) {
            int t = parent[s];
            Dinic dinic(n);
            for (const OriginalEdge& e : edges) {
                dinic.add_undirected(e.u, e.v, e.cap);
            }

            cut_to_parent[s] = dinic.max_flow(s, t);
            vector<char> side = dinic.reachable_from(s);

            for (int v = s + 1; v < n; ++v) {
                if (parent[v] == t && side[v]) {
                    parent[v] = s;
                }
            }

            if (parent[t] != -1 && side[parent[t]]) {
                parent[s] = parent[t];
                parent[t] = s;
                swap(cut_to_parent[s], cut_to_parent[t]);
            }
        }

        for (int i = 0; i < n; ++i) {
            tree[i].clear();
        }
        vector<TreeEdge> result;
        result.reserve(max(0, n - 1));
        for (int v = 1; v < n; ++v) {
            result.push_back({v, parent[v], cut_to_parent[v]});
            tree[v].push_back({parent[v], cut_to_parent[v]});
            tree[parent[v]].push_back({v, cut_to_parent[v]});
        }
        return result;
    }
};

int main() {
    GomoryHuTree gh(3);
    gh.add_edge(0, 1, 3);
    gh.add_edge(1, 2, 2);
    gh.add_edge(0, 2, 4);

    vector<GomoryHuTree::TreeEdge> tree = gh.build();
    sort(tree.begin(), tree.end(), [](const GomoryHuTree::TreeEdge& a,
                                      const GomoryHuTree::TreeEdge& b) {
        if (a.u != b.u) {
            return a.u < b.u;
        }
        return a.v < b.v;
    });

    for (const auto& e : tree) {
        cout << e.u << ' ' << e.v << ' ' << e.cut << '\n';
    }
    return 0;
}
