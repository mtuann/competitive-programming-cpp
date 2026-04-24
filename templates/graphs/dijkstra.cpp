// Template: Dijkstra
// Signal: single-source shortest paths with nonnegative edge weights.
// Assumes: all reachable edges have weight >= 0 and stale priority-queue entries are skipped.
// Exposes: one min-heap shortest-path skeleton with dist and parent arrays.
// Complexity: O((n + m) log n) with a binary heap.
// Main trap: one hidden negative edge invalidates the greedy settle order completely.
// Links:
//   Topic: topics/graphs/shortest-paths/README.md
//   Note: practice/ladders/graphs/shortest-paths/qos.md

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
    vector<vector<Edge>> graph = {
        {{1, 4}, {2, 1}},
        {{3, 1}},
        {{1, 2}, {3, 5}},
        {}
    };

    int n = static_cast<int>(graph.size());
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (current_dist != dist[u]) {
            continue;
        }
        for (const Edge &e : graph[u]) {
            long long candidate = current_dist + e.weight;
            if (candidate < dist[e.to]) {
                dist[e.to] = candidate;
                parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    cout << dist[3] << '\n';
    return 0;
}
