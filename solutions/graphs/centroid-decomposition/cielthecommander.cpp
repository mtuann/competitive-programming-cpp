// Problem: Ciel the Commander
// Judge: Codeforces
// Source URL: https://codeforces.com/problemset/problem/321/C
// Topic: centroid decomposition, centroid tree, balanced recursive labeling
// Idea: recursively choose the centroid of each remaining component, label it by
// the current centroid-tree depth, and recurse on the child components. Equal
// labels are then separated by a higher-ranked centroid on every path.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> subtree_size(n, 0);
    vector<int> parent_local(n, -1);
    vector<char> removed(n, false);
    vector<char> answer(n, '?');

    auto find_centroid = [&](int entry) {
        vector<int> nodes;
        vector<int> order;
        vector<pair<int, int>> stack = {{entry, -1}};

        while (!stack.empty()) {
            auto [u, p] = stack.back();
            stack.pop_back();
            parent_local[u] = p;
            nodes.push_back(u);
            order.push_back(u);
            for (int v : graph[u]) {
                if (removed[v] || v == p) {
                    continue;
                }
                stack.push_back({v, u});
            }
        }

        for (int i = static_cast<int>(order.size()) - 1; i >= 0; --i) {
            int u = order[i];
            subtree_size[u] = 1;
            for (int v : graph[u]) {
                if (removed[v] || parent_local[v] != u) {
                    continue;
                }
                subtree_size[u] += subtree_size[v];
            }
        }

        int total = static_cast<int>(nodes.size());
        for (int u : nodes) {
            int max_part = total - subtree_size[u];
            for (int v : graph[u]) {
                if (removed[v] || parent_local[v] != u) {
                    continue;
                }
                max_part = max(max_part, subtree_size[v]);
            }
            if (max_part * 2 <= total) {
                return u;
            }
        }
        return entry;
    };

    auto decompose = [&](auto&& self, int entry, int depth) -> void {
        int centroid = find_centroid(entry);
        answer[centroid] = static_cast<char>('A' + depth);
        removed[centroid] = true;

        for (int v : graph[centroid]) {
            if (!removed[v]) {
                self(self, v, depth + 1);
            }
        }
    };

    decompose(decompose, 0, 0);

    for (int i = 0; i < n; ++i) {
        cout << answer[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
