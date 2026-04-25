#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

/*
Problem: Reactor Cooling
Judge: Codeforces acmsguru
URL: https://codeforces.com/problemsets/acmsguru/problem/99999/194
Topic: flow with lower bounds
*/

struct Dinic {
    struct Edge {
        int to;
        int rev;
        long long cap;
    };

    int n;
    vector<vector<Edge>> g;
    vector<int> level, ptr;

    explicit Dinic(int n) : n(n), g(n), level(n), ptr(n) {}

    int add_edge(int u, int v, long long cap) {
        int idx = static_cast<int>(g[u].size());
        Edge a{v, static_cast<int>(g[v].size()), cap};
        Edge b{u, idx, 0};
        g[u].push_back(a);
        g[v].push_back(b);
        return idx;
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
                if (e.cap == 0 || level[e.to] != -1) {
                    continue;
                }
                level[e.to] = level[u] + 1;
                q.push(e.to);
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
        const long long INF = numeric_limits<long long>::max() / 4;
        long long flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }

    long long edge_flow(int u, int idx) const {
        const Edge &e = g[u][idx];
        return g[e.to][e.rev].cap;
    }
};

struct LowerBoundFlow {
    struct OriginalEdge {
        int from;
        int to;
        long long lower;
        long long upper;
        int residual_idx;
    };

    int n;
    int ss;
    int tt;
    Dinic dinic;
    vector<long long> balance;
    vector<OriginalEdge> edges;

    explicit LowerBoundFlow(int n)
        : n(n), ss(n + 1), tt(n + 2), dinic(n + 3), balance(n + 1, 0) {}

    int add_edge(int u, int v, long long lower, long long upper) {
        int idx = dinic.add_edge(u, v, upper - lower);
        balance[u] -= lower;
        balance[v] += lower;
        edges.push_back({u, v, lower, upper, idx});
        return static_cast<int>(edges.size()) - 1;
    }

    bool feasible_circulation() {
        long long need = 0;
        for (int v = 1; v <= n; ++v) {
            if (balance[v] > 0) {
                dinic.add_edge(ss, v, balance[v]);
                need += balance[v];
            } else if (balance[v] < 0) {
                dinic.add_edge(v, tt, -balance[v]);
            }
        }
        return dinic.max_flow(ss, tt) == need;
    }

    long long edge_flow(int id) const {
        const OriginalEdge &e = edges[id];
        return e.lower + dinic.edge_flow(e.from, e.residual_idx);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    LowerBoundFlow lb(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long lower, upper;
        cin >> u >> v >> lower >> upper;
        lb.add_edge(u, v, lower, upper);
    }

    if (!lb.feasible_circulation()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        cout << lb.edge_flow(i) << '\n';
    }
    return 0;
}
