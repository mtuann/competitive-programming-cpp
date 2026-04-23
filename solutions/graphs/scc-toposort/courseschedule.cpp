// Problem: Course Schedule
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1679
// Topic: topological sort, Kahn algorithm
// Idea: push all indegree-zero vertices into a queue, repeatedly remove one and
// decrement its outgoing neighbors. If fewer than n vertices are output, a cycle exists.

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
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ++indegree[b];
    }

    queue<int> q;
    for (int v = 1; v <= n; ++v) {
        if (indegree[v] == 0) {
            q.push(v);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (static_cast<int>(order.size()) != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << order[i];
    }
    cout << '\n';
    return 0;
}
