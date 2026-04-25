// Template: flow with lower bounds
// Signal: each directed edge has mandatory minimum and maximum flow, and the goal is one feasible circulation or one lower-bounded s-t reduction.
// Assumes: vertices are 0-indexed; add all original edges before calling feasible_circulation(); for lower-bounded s-t flow, add the modeling edge t -> s yourself.
// Exposes: LowerBoundFlow with add_edge(u, v, lower, upper), feasible_circulation(), edge_flow(id), and all_edge_flows(); the flow accessors are only valid after feasible_circulation() has returned true.
// Complexity: one Dinic run on the auxiliary graph; practical contest complexity is the underlying max-flow cost on O(n + m) vertices/edges.
// Main trap: getting the balance signs backward, or forgetting that t -> s is a real modeling edge, not a residual reverse edge.
// Links:
//   Topic: topics/graphs/flow-lower-bounds/README.md
//   Note: practice/ladders/graphs/flow/reactorcooling.md

#include <cassert>
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

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
    int super_source;
    int super_sink;
    Dinic dinic;
    vector<long long> balance;
    vector<OriginalEdge> edges;
    bool solved = false;
    bool feasible = false;

    explicit LowerBoundFlow(int n)
        : n(n), super_source(n), super_sink(n + 1), dinic(n + 2), balance(n, 0) {}

    int add_edge(int u, int v, long long lower, long long upper) {
        int residual_idx = dinic.add_edge(u, v, upper - lower);
        balance[u] -= lower;
        balance[v] += lower;
        edges.push_back({u, v, lower, upper, residual_idx});
        return static_cast<int>(edges.size()) - 1;
    }

    bool feasible_circulation() {
        if (solved) {
            return feasible;
        }

        long long need = 0;
        for (int v = 0; v < n; ++v) {
            if (balance[v] > 0) {
                dinic.add_edge(super_source, v, balance[v]);
                need += balance[v];
            } else if (balance[v] < 0) {
                dinic.add_edge(v, super_sink, -balance[v]);
            }
        }

        feasible = (dinic.max_flow(super_source, super_sink) == need);
        solved = true;
        return feasible;
    }

    long long edge_flow(int id) const {
        assert(solved && feasible);
        const OriginalEdge &e = edges[id];
        return e.lower + dinic.edge_flow(e.from, e.residual_idx);
    }

    vector<long long> all_edge_flows() const {
        vector<long long> out;
        out.reserve(edges.size());
        for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
            out.push_back(edge_flow(i));
        }
        return out;
    }
};

int main() {
    LowerBoundFlow lb(3);
    lb.add_edge(0, 1, 1, 3);
    lb.add_edge(1, 2, 1, 4);
    lb.add_edge(2, 0, 1, 5);

    if (!lb.feasible_circulation()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (long long f : lb.all_edge_flows()) {
        cout << f << ' ';
    }
    cout << '\n';
    return 0;
}
