// Problem: Mail Delivery
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1691
// Topic: Eulerian cycle, Hierholzer, degree parity
// Idea: reject if some undirected degree is odd, then run iterative Hierholzer
// with shared edge ids and accept only when the route uses all m edges.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    vector<int> degree(n, 0);
    for (int id = 0; id < m; ++id) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back({b, id});
        g[b].push_back({a, id});
        ++degree[a];
        ++degree[b];
    }

    for (int v = 0; v < n; ++v) {
        if (degree[v] % 2 == 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    int start = 0;
    while (start < n && degree[start] == 0) {
        ++start;
    }
    if (start == n) {
        cout << "1\n";
        return 0;
    }

    vector<int> ptr(n, 0), st{start}, path;
    vector<char> used(m, false);
    path.reserve(m + 1);

    while (!st.empty()) {
        int v = st.back();
        while (ptr[v] < static_cast<int>(g[v].size()) && used[g[v][ptr[v]].second]) {
            ++ptr[v];
        }
        if (ptr[v] == static_cast<int>(g[v].size())) {
            path.push_back(v);
            st.pop_back();
        } else {
            auto [to, id] = g[v][ptr[v]++];
            if (used[id]) {
                continue;
            }
            used[id] = true;
            st.push_back(to);
        }
    }

    if (static_cast<int>(path.size()) != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(path.begin(), path.end());
    for (int i = 0; i < static_cast<int>(path.size()); ++i) {
        cout << path[i] + 1 << (i + 1 == static_cast<int>(path.size()) ? '\n' : ' ');
    }
    return 0;
}
