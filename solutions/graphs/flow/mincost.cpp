#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

/*
Problem: MINCOST - Luong voi chi phi nho nhat
Judge: VN SPOJ
URL: https://vn.spoj.com/problems/MINCOST/
Mirror: https://oj.vnoi.info/problem/mincost
Topic: Min-cost flow

SPOJVN hidden-test gotcha:
- duplicate undirected edges can appear
- only the last occurrence should be kept
*/

struct MinCostFlow {
    struct Edge {
        int to;
        int rev;
        long long cap;
        long long cost;
    };

    int n;
    vector<vector<Edge>> g;

    explicit MinCostFlow(int n) : n(n), g(n + 1) {}

    int add_edge(int u, int v, long long cap, long long cost) {
        int idx = static_cast<int>(g[u].size());
        Edge a{v, static_cast<int>(g[v].size()), cap, cost};
        Edge b{u, idx, 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
        return idx;
    }

    pair<long long, long long> min_cost_flow(int s, int t, long long need) {
        const long long INF = numeric_limits<long long>::max() / 4;

        vector<long long> potential(n + 1, 0);
        vector<long long> dist(n + 1, INF);
        vector<int> parent_v(n + 1, -1);
        vector<int> parent_e(n + 1, -1);

        long long flow = 0;
        long long cost = 0;

        while (flow < need) {
            fill(dist.begin(), dist.end(), INF);
            fill(parent_v.begin(), parent_v.end(), -1);
            fill(parent_e.begin(), parent_e.end(), -1);

            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            dist[s] = 0;
            pq.push({0, s});

            while (!pq.empty()) {
                long long cur_dist = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if (cur_dist != dist[u]) {
                    continue;
                }

                for (int i = 0; i < static_cast<int>(g[u].size()); ++i) {
                    const Edge &e = g[u][i];
                    if (e.cap == 0) {
                        continue;
                    }
                    long long nd = cur_dist + e.cost + potential[u] - potential[e.to];
                    if (nd < dist[e.to]) {
                        dist[e.to] = nd;
                        parent_v[e.to] = u;
                        parent_e[e.to] = i;
                        pq.push({nd, e.to});
                    }
                }
            }

            if (dist[t] == INF) {
                break;
            }

            for (int i = 1; i <= n; ++i) {
                if (dist[i] < INF) {
                    potential[i] += dist[i];
                }
            }

            long long add = need - flow;
            for (int v = t; v != s; v = parent_v[v]) {
                const Edge &e = g[parent_v[v]][parent_e[v]];
                add = min(add, e.cap);
            }

            for (int v = t; v != s; v = parent_v[v]) {
                Edge &e = g[parent_v[v]][parent_e[v]];
                Edge &rev = g[e.to][e.rev];
                e.cap -= add;
                rev.cap += add;
                cost += add * e.cost;
            }

            flow += add;
        }

        return {flow, cost};
    }
};

struct SavedArc {
    int u;
    int v;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    long long need;
    if (!(cin >> n >> m >> need >> s >> t)) {
        return 0;
    }

    vector<vector<long long>> last_cap(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> last_cost(n + 1, vector<long long>(n + 1, 0));
    vector<vector<int>> last_pos(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long c, d;
        cin >> u >> v >> c >> d;
        if (u > v) {
            swap(u, v);
        }
        last_cost[u][v] = c;
        last_cap[u][v] = d;
        last_pos[u][v] = i;
    }

    vector<tuple<int, int, int, long long, long long>> edges;
    for (int u = 1; u <= n; ++u) {
        for (int v = u + 1; v <= n; ++v) {
            if (last_pos[u][v] != -1) {
                edges.push_back({last_pos[u][v], u, v, last_cost[u][v], last_cap[u][v]});
            }
        }
    }
    sort(edges.begin(), edges.end());

    MinCostFlow mcf(n);
    vector<SavedArc> forward;
    vector<SavedArc> backward;
    forward.reserve(edges.size());
    backward.reserve(edges.size());

    for (const auto &entry : edges) {
        int u = get<1>(entry);
        int v = get<2>(entry);
        long long c = get<3>(entry);
        long long d = get<4>(entry);

        int idx_uv = mcf.add_edge(u, v, d, c);
        int idx_vu = mcf.add_edge(v, u, d, c);
        forward.push_back({u, v, idx_uv});
        backward.push_back({v, u, idx_vu});
    }

    auto result = mcf.min_cost_flow(s, t, need);
    if (result.first < need) {
        cout << -1 << '\n';
        return 0;
    }

    cout << result.second << '\n';
    for (int i = 0; i < static_cast<int>(forward.size()); ++i) {
        const SavedArc &a = forward[i];
        const SavedArc &b = backward[i];

        long long flow_ab = mcf.g[a.v][mcf.g[a.u][a.idx].rev].cap;
        long long flow_ba = mcf.g[b.v][mcf.g[b.u][b.idx].rev].cap;

        long long cancel = min(flow_ab, flow_ba);
        flow_ab -= cancel;
        flow_ba -= cancel;

        if (flow_ab > 0) {
            cout << a.u << ' ' << a.v << ' ' << flow_ab << '\n';
        }
        if (flow_ba > 0) {
            cout << b.u << ' ' << b.v << ' ' << flow_ba << '\n';
        }
    }
    cout << "0 0 0\n";

    return 0;
}
