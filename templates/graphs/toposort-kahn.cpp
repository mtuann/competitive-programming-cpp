// Template: Kahn topological sort
// Signal: explicit DAG order from indegrees, especially when you also want cycle detection.
// Assumes: the graph should be a DAG; if not, a short order means a cycle exists.
// Exposes: one indegree-based queue skeleton producing a topological order.
// Complexity: O(n + m).
// Main trap: reading any output order as valid without checking whether its length reached n.
// Links:
//   Topic: topics/graphs/scc-toposort/README.md
//   Note: practice/ladders/graphs/scc-toposort/courseschedule.md

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    int n = static_cast<int>(graph.size());
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            ++indeg[v];
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int x : order) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
