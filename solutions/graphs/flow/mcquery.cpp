// Problem: MCQUERY - MinCut Query
// Judge: VN SPOJ / VNOI
// Source URL: https://vn.spoj.com/problems/MCQUERY/
// Mirror URL: https://oj.vnoi.info/problem/mcquery
// Topic: flow, Gomory-Hu tree, DSU
// Idea: in an undirected weighted graph, a Gomory-Hu tree stores all pair
// min-cuts: minCut(s, t) equals the minimum edge weight on the unique path
// between s and t in that tree. Build the Gomory-Hu tree with n - 1 max-flow
// runs, then sort tree edges by weight descending. When DSU adds one tree edge
// of weight w between components of sizes a and b, exactly a * b unordered
// pairs have path minimum equal to w.

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Dinic {
    struct Edge {
        int to;
        int rev;
        long long cap;
    };

    int n;
    vector<vector<Edge> > g;
    vector<int> level;
    vector<int> ptr;

    explicit Dinic(int n) : n(n), g(n + 1), level(n + 1), ptr(n + 1) {}

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
            for (const Edge &e : g[u]) {
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

        for (int &cid = ptr[u]; cid < static_cast<int>(g[u].size()); ++cid) {
            Edge &e = g[u][cid];
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
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, (1LL << 60))) {
                flow += pushed;
            }
        }
        return flow;
    }

    vector<char> reachable_from(int s) const {
        vector<char> vis(n + 1, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const Edge &e : g[u]) {
                if (e.cap > 0 && !vis[e.to]) {
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return vis;
    }
};

struct DSU {
    vector<int> parent;
    vector<long long> size;

    explicit DSU(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    long long unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return 0;
        }
        long long pairs = size[a] * size[b];
        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return pairs;
    }
};

struct OriginalEdge {
    int u;
    int v;
    long long c;
};

struct TreeEdge {
    int u;
    int v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; ++tc) {
        int n, m;
        cin >> n >> m;

        vector<OriginalEdge> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].c;
        }

        vector<int> parent(n + 1, 1);
        vector<long long> cut_value(n + 1, 0);
        parent[1] = 0;

        for (int s = 2; s <= n; ++s) {
            int t = parent[s];
            Dinic dinic(n);
            for (const OriginalEdge &e : edges) {
                dinic.add_undirected(e.u, e.v, e.c);
            }

            cut_value[s] = dinic.max_flow(s, t);
            vector<char> side = dinic.reachable_from(s);

            for (int i = s + 1; i <= n; ++i) {
                if (parent[i] == t && side[i]) {
                    parent[i] = s;
                }
            }

            if (parent[t] != 0 && side[parent[t]]) {
                parent[s] = parent[t];
                parent[t] = s;
                swap(cut_value[s], cut_value[t]);
            }
        }

        vector<TreeEdge> tree_edges;
        tree_edges.reserve(n - 1);
        for (int i = 2; i <= n; ++i) {
            tree_edges.push_back({i, parent[i], cut_value[i]});
        }

        sort(tree_edges.begin(), tree_edges.end(),
             [](const TreeEdge &a, const TreeEdge &b) { return a.w > b.w; });

        DSU dsu(n);
        vector<pair<long long, long long> > exact;
        exact.reserve(n - 1);
        for (const TreeEdge &e : tree_edges) {
            long long pairs = dsu.unite(e.u, e.v);
            exact.push_back({e.w, pairs});
        }

        sort(exact.begin(), exact.end());
        vector<long long> xs;
        vector<long long> prefix;
        for (const auto &entry : exact) {
            if (xs.empty() || xs.back() != entry.first) {
                xs.push_back(entry.first);
                prefix.push_back(entry.second);
            } else {
                prefix.back() += entry.second;
            }
        }
        for (int i = 1; i < static_cast<int>(prefix.size()); ++i) {
            prefix[i] += prefix[i - 1];
        }

        int q;
        cin >> q;
        while (q--) {
            long long x;
            cin >> x;
            int pos = static_cast<int>(upper_bound(xs.begin(), xs.end(), x) - xs.begin()) - 1;
            long long answer = (pos >= 0 ? prefix[pos] : 0LL);
            cout << answer << '\n';
        }

        if (tc != tests) {
            cout << '\n';
        }
    }

    return 0;
}
