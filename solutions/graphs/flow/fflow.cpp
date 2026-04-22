// Problem: FFLOW - Fast Maximum Flow
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/FFLOW/
// English URL: https://vn.spoj.com/problems/FFLOW/en/
// Topic: Maximum flow / minimum cut on an undirected graph
// Idea: model each undirected edge as capacity c in both directions and run capacity-scaling Dinic

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Dinic {
    struct Edge {
        int to;
        int next;
        long long cap;
    };

    int n;
    int edge_count;
    vector<int> head, level, ptr, q;
    vector<Edge> edges;

    explicit Dinic(int n, int max_edges)
        : n(n),
          edge_count(0),
          head(n, -1),
          level(n),
          ptr(n),
          q(n) {
        edges.reserve(max_edges);
    }

    void add_directed(int u, int v, long long cap) {
        edges.push_back({v, head[u], cap});
        head[u] = edge_count++;
        edges.push_back({u, head[v], 0});
        head[v] = edge_count++;
    }

    void add_undirected(int u, int v, long long cap) {
        if (u == v) return;
        add_directed(u, v, cap);
        add_directed(v, u, cap);
    }

    bool bfs(int s, int t, long long lim) {
        fill(level.begin(), level.end(), -1);
        int ql = 0;
        int qr = 0;
        q[qr++] = s;
        level[s] = 0;

        while (ql < qr) {
            int v = q[ql++];
            for (int id = head[v]; id != -1; id = edges[id].next) {
                const Edge& e = edges[id];
                if (e.cap < lim || level[e.to] != -1) continue;
                level[e.to] = level[v] + 1;
                q[qr++] = e.to;
            }
        }

        return level[t] != -1;
    }

    long long dfs(int v, int t, long long pushed, long long lim) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;

        for (int& id = ptr[v]; id != -1; id = edges[id].next) {
            Edge& e = edges[id];
            if (e.cap < lim || level[e.to] != level[v] + 1) continue;

            long long flow = dfs(e.to, t, min(pushed, e.cap), lim);
            if (flow == 0) continue;

            e.cap -= flow;
            edges[id ^ 1].cap += flow;
            return flow;
        }

        return 0;
    }

    long long max_flow(int s, int t, long long max_cap) {
        long long flow = 0;
        const long long inf = numeric_limits<long long>::max() / 4;

        long long lim = 1;
        while ((lim << 1) <= max_cap) lim <<= 1;

        for (; lim > 0; lim >>= 1) {
            while (bfs(s, t, lim)) {
                ptr = head;
                while (long long pushed = dfs(s, t, inf, lim)) {
                    flow += pushed;
                }
            }
        }

        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Dinic dinic(n, 4 * m + 5);
    long long max_cap = 0;

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        --a;
        --b;
        max_cap = max(max_cap, c);
        dinic.add_undirected(a, b, c);
    }

    cout << dinic.max_flow(0, n - 1, max_cap) << '\n';
    return 0;
}
