// Problem: QOS - Chất lượng dịch vụ
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/QOS/
// Topic: shortest paths with bounded extra slack and k-th lexicographic reconstruction
// Idea: run reverse Dijkstra to get dist[u], DP on (u, extra) with extra <= Cmin, then reconstruct greedily

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, target;
    long long k;
    cin >> n >> m >> target >> k;
    --target;

    vector<vector<Edge>> graph(n), reverse_graph(n);
    int cmin = numeric_limits<int>::max();

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        graph[u].push_back({v, w});
        reverse_graph[v].push_back({u, w});
        cmin = min(cmin, w);
    }

    if (m == 0) cmin = 0;

    for (int u = 0; u < n; ++u) {
        sort(graph[u].begin(), graph[u].end(),
             [](const Edge& a, const Edge& b) {
                 if (a.to != b.to) return a.to < b.to;
                 return a.weight < b.weight;
             });
    }

    const long long inf = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, inf);
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    dist[target] = 0;
    pq.push({0, target});

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();
        long long du = top.first;
        int u = top.second;
        if (du != dist[u]) continue;

        for (const Edge& edge : reverse_graph[u]) {
            int v = edge.to;
            long long nd = du + edge.weight;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    if (dist[0] == inf) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;
    sort(order.begin(), order.end(),
         [&](int a, int b) {
             if (dist[a] != dist[b]) return dist[a] < dist[b];
             return a < b;
         });

    const long long cap = k;
    vector<vector<long long>> dp(cmin + 1, vector<long long>(n, 0));

    auto add_capped = [&](long long& current, long long value) {
        current += value;
        if (current > cap) current = cap;
    };

    for (int extra = 0; extra <= cmin; ++extra) {
        for (int u : order) {
            if (dist[u] == inf) continue;

            long long ways = (u == target ? 1 : 0);
            for (const Edge& edge : graph[u]) {
                int v = edge.to;
                if (dist[v] == inf) continue;

                long long next_extra = extra + dist[u] - edge.weight - dist[v];
                if (next_extra < 0) continue;

                add_capped(ways, dp[static_cast<int>(next_extra)][v]);
                if (ways == cap) break;
            }
            dp[extra][u] = ways;
        }
    }

    if (dp[cmin][0] < k) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> path;
    path.push_back(0);

    int u = 0;
    int extra = cmin;
    long long need = k;

    while (true) {
        if (u == target) {
            if (need == 1) break;
            --need;
        }

        bool found = false;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            if (dist[v] == inf) continue;

            long long next_extra = extra + dist[u] - edge.weight - dist[v];
            if (next_extra < 0) continue;

            long long cnt = dp[static_cast<int>(next_extra)][v];
            if (need > cnt) {
                need -= cnt;
                continue;
            }

            path.push_back(v);
            u = v;
            extra = static_cast<int>(next_extra);
            found = true;
            break;
        }

        if (!found) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << path.size() << '\n';
    for (int i = 0; i < static_cast<int>(path.size()); ++i) {
        if (i) cout << ' ';
        cout << path[i] + 1;
    }
    cout << '\n';
    return 0;
}
