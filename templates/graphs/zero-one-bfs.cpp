// Use: shortest paths on graphs whose edge weights are only 0 or 1.
// Invariant: the deque stores vertices in nondecreasing tentative distance.
// Complexity: O(n + m).

#include <deque>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct ZeroOneBFSResult {
    vector<int> dist;
    vector<int> parent;
};

ZeroOneBFSResult zero_one_bfs(const vector<vector<Edge>> &graph, int source) {
    const int INF = numeric_limits<int>::max() / 4;
    int n = static_cast<int>(graph.size());
    vector<int> dist(n, INF), parent(n, -1);
    deque<int> dq;

    dist[source] = 0;
    dq.push_front(source);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (const Edge &e : graph[u]) {
            int candidate = dist[u] + e.weight;
            if (candidate >= dist[e.to]) {
                continue;
            }
            dist[e.to] = candidate;
            parent[e.to] = u;
            if (e.weight == 0) {
                dq.push_front(e.to);
            } else {
                dq.push_back(e.to);
            }
        }
    }

    return {dist, parent};
}

int main() {
    vector<vector<Edge>> graph = {
        {{1, 1}, {2, 0}},
        {{3, 1}},
        {{1, 0}, {3, 1}},
        {}
    };

    ZeroOneBFSResult result = zero_one_bfs(graph, 0);
    cout << result.dist[3] << '\n';
    return 0;
}
