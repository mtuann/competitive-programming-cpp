// Problem: Tree Distances II
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1133
// Topic: tree DP, rerooting, subtree sizes
// Idea: compute subtree sizes and the root-1 distance sum once, then reroot
// along each parent-child edge using ans[v] = ans[u] - sub_size[v] + (n - sub_size[v]).

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    vector<int> stack = {1};

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (int v : g[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            stack.push_back(v);
        }
    }

    vector<int> sub_size(n + 1, 1);
    vector<long long> sub_dist(n + 1, 0);
    for (int idx = n - 1; idx >= 0; --idx) {
        int u = order[idx];
        for (int v : g[u]) {
            if (v == parent[u]) {
                continue;
            }
            sub_size[u] += sub_size[v];
            sub_dist[u] += sub_dist[v] + sub_size[v];
        }
    }

    vector<long long> ans(n + 1, 0);
    ans[1] = sub_dist[1];
    for (int u : order) {
        for (int v : g[u]) {
            if (v == parent[u]) {
                continue;
            }
            ans[v] = ans[u] - sub_size[v] + (n - sub_size[v]);
        }
    }

    for (int u = 1; u <= n; ++u) {
        cout << ans[u] << (u == n ? '\n' : ' ');
    }
    return 0;
}
