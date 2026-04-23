// Problem: Message Route
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1667
// Topic: BFS, unweighted shortest path, path reconstruction
// Idea: BFS from node 1. The first visit to each node gives a shortest path in
// an unweighted graph, so storing that predecessor is enough to reconstruct one
// shortest route to node n.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, -1);
    queue<int> q;
    parent[1] = 0;
    q.push(1);

    while (!q.empty() && parent[n] == -1) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (parent[v] != -1) {
                continue;
            }
            parent[v] = u;
            q.push(v);
        }
    }

    if (parent[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    for (int v = n; v != 0; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (int i = 0; i < static_cast<int>(path.size()); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << path[i];
    }
    cout << '\n';
    return 0;
}
