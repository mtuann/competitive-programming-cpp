// Problem: Tree Matching
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1130
// Topic: dp, tree dp
// Idea: root the tree and keep whether a node matches one child or none.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);

    vector<int> stack = {1};
    parent[1] = -1;
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            stack.push_back(v);
        }
    }

    vector<int> skip(n + 1, 0);
    vector<int> take(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        int base = 0;
        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            base += max(skip[v], take[v]);
        }

        skip[u] = base;
        take[u] = 0;

        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            take[u] = max(take[u], 1 + skip[v] + base - max(skip[v], take[v]));
        }
    }

    cout << max(skip[1], take[1]) << '\n';
    return 0;
}
