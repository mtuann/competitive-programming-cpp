// Template: Bellman-Ford
// Signal: single-source shortest paths with negative edges or reachable negative-cycle detection.
// Assumes: edge list is explicit and O(n * m) is acceptable for the input size.
// Exposes: bellman_ford(n, edges, source) returning dist, parent, and a reachable-negative-cycle flag.
// Complexity: O(n * m).
// Main trap: treating dist/parent as ordinary shortest-path outputs after has_negative_cycle becomes true.
// Links:
//   Topic: topics/graphs/shortest-paths/README.md
//   Notebook: notebook/graph-cheatsheet.md

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    long long weight;
};

struct BellmanFordResult {
    vector<long long> dist;
    vector<int> parent;
    bool has_negative_cycle;
};

BellmanFordResult bellman_ford(int n, const vector<Edge> &edges, int source) {
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, INF);
    vector<int> parent(n, -1);

    dist[source] = 0;
    for (int iter = 0; iter < n - 1; ++iter) {
        bool changed = false;
        for (const Edge &e : edges) {
            if (dist[e.from] == INF) {
                continue;
            }
            long long candidate = dist[e.from] + e.weight;
            if (candidate >= dist[e.to]) {
                continue;
            }
            dist[e.to] = candidate;
            parent[e.to] = e.from;
            changed = true;
        }
        if (!changed) {
            break;
        }
    }

    bool has_negative_cycle = false;
    for (const Edge &e : edges) {
        if (dist[e.from] == INF) {
            continue;
        }
        if (dist[e.from] + e.weight < dist[e.to]) {
            has_negative_cycle = true;
            break;
        }
    }

    return {dist, parent, has_negative_cycle};
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -2},
        {1, 3, 6},
        {2, 3, 1}
    };

    BellmanFordResult result = bellman_ford(n, edges, 0);
    cout << result.dist[3] << '\n';
    cout << result.has_negative_cycle << '\n';
    return 0;
}
