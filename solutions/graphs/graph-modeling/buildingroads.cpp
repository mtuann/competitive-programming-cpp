// Problem: Building Roads
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1666
// Topic: graph modeling, connected components, constructive output
// Idea: cities are vertices and roads are undirected edges. Find one
// representative per connected component, then connect consecutive
// representatives. This uses exactly components - 1 new roads and is minimal.

#include <iostream>
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

    vector<int> representatives;
    vector<int> stack;
    vector<char> visited(n + 1, false);

    for (int start = 1; start <= n; ++start) {
        if (visited[start]) {
            continue;
        }

        representatives.push_back(start);
        visited[start] = true;
        stack.push_back(start);

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            for (int v : adj[u]) {
                if (visited[v]) {
                    continue;
                }
                visited[v] = true;
                stack.push_back(v);
            }
        }
    }

    cout << max(0, static_cast<int>(representatives.size()) - 1) << '\n';
    for (int i = 1; i < static_cast<int>(representatives.size()); ++i) {
        cout << representatives[i - 1] << ' ' << representatives[i] << '\n';
    }
    return 0;
}
