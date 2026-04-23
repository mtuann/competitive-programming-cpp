// Template: successive shortest augmenting path with potentials.

#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct MinCostFlow {
    struct Edge {
        int to, rev;
        long long cap, cost;
    };

    int n;
    vector<vector<Edge>> g;

    explicit MinCostFlow(int n) : n(n), g(n) {}

    void add_edge(int u, int v, long long cap, long long cost) {
        Edge a{v, static_cast<int>(g[v].size()), cap, cost};
        Edge b{u, static_cast<int>(g[u].size()), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    pair<long long, long long> min_cost_flow(int s, int t, long long need) {
        const long long INF = numeric_limits<long long>::max() / 4;
        vector<long long> pot(n, 0), dist(n);
        vector<int> pv(n), pe(n);
        long long flow = 0, cost = 0;

        while (flow < need) {
            fill(dist.begin(), dist.end(), INF);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            dist[s] = 0;
            pq.push({0, s});

            while (!pq.empty()) {
                auto [cd, u] = pq.top();
                pq.pop();
                if (cd != dist[u]) continue;
                for (int i = 0; i < static_cast<int>(g[u].size()); ++i) {
                    const Edge &e = g[u][i];
                    if (e.cap == 0) continue;
                    long long nd = cd + e.cost + pot[u] - pot[e.to];
                    if (nd < dist[e.to]) {
                        dist[e.to] = nd;
                        pv[e.to] = u;
                        pe[e.to] = i;
                        pq.push({nd, e.to});
                    }
                }
            }

            if (dist[t] == INF) break;
            for (int i = 0; i < n; ++i) {
                if (dist[i] < INF) pot[i] += dist[i];
            }

            long long add = need - flow;
            for (int v = t; v != s; v = pv[v]) {
                add = min(add, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                Edge &e = g[pv[v]][pe[v]];
                Edge &r = g[e.to][e.rev];
                e.cap -= add;
                r.cap += add;
                cost += add * e.cost;
            }
            flow += add;
        }

        return {flow, cost};
    }
};

int main() {
    MinCostFlow mcf(4);
    mcf.add_edge(0, 1, 2, 1);
    mcf.add_edge(0, 2, 1, 4);
    mcf.add_edge(1, 3, 2, 2);
    mcf.add_edge(2, 3, 1, 1);
    auto [flow, cost] = mcf.min_cost_flow(0, 3, 2);
    cout << flow << ' ' << cost << '\n';
    return 0;
}
