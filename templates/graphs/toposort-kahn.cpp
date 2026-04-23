// Template: Kahn topological sort.

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
