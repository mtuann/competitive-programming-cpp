// Template: BFS
// Signal: unweighted shortest path or layer exploration on a graph/grid.
// Assumes: every edge has equal unit cost and the first visit gives optimal distance.
// Exposes: one queue-based shortest-path skeleton with dist and parent arrays.
// Complexity: O(n + m).
// Main trap: slipping weighted edges into the same loop and trusting level order anyway.
// Links:
//   Topic: topics/graphs/bfs-dfs/README.md
//   Note: practice/ladders/graphs/bfs-dfs/messageroute.md

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3}
    };

    int n = static_cast<int>(graph.size());
    int source = 0;
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] != -1) {
                continue;
            }
            dist[v] = dist[u] + 1;
            parent[v] = u;
            q.push(v);
        }
    }

    cout << dist[4] << '\n';
    return 0;
}
