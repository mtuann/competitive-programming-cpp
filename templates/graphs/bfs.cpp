// Template: BFS for unweighted shortest path.

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
