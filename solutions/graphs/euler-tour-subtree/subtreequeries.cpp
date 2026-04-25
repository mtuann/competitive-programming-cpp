// Problem: Subtree Queries
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1137
// Topic: Euler tour flattening, subtree intervals, Fenwick tree
// Idea: record one DFS entry time for each node so every subtree becomes one
// contiguous interval [tin[u], tout[u]). Then point assignment is a point delta
// update at tin[u], and subtree sum is one range sum on that interval.

#include <iostream>
#include <vector>

using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long delta) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    long long prefix_sum(int right) const {
        long long result = 0;
        for (; right > 0; right -= right & -right) {
            result += bit[right];
        }
        return result;
    }

    long long range_sum(int left, int right) const {
        return prefix_sum(right) - prefix_sum(left);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> value(n + 1);
    for (int node = 1; node <= n; ++node) {
        cin >> value[node];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> tin(n + 1, -1);
    vector<int> tout(n + 1, -1);
    vector<int> next_idx(n + 1, 0);
    vector<int> stack = {1};
    parent[1] = 1;
    int timer = 0;

    while (!stack.empty()) {
        int u = stack.back();
        if (next_idx[u] == 0) {
            tin[u] = timer;
            ++timer;
        }

        if (next_idx[u] == static_cast<int>(graph[u].size())) {
            tout[u] = timer;
            stack.pop_back();
            continue;
        }

        int v = graph[u][next_idx[u]++];
        if (v == parent[u]) {
            continue;
        }
        parent[v] = u;
        stack.push_back(v);
    }

    Fenwick fenwick(n);
    for (int node = 1; node <= n; ++node) {
        fenwick.add(tin[node], value[node]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            fenwick.add(tin[s], x - value[s]);
            value[s] = x;
        } else {
            int s;
            cin >> s;
            cout << fenwick.range_sum(tin[s], tout[s]) << '\n';
        }
    }

    return 0;
}
