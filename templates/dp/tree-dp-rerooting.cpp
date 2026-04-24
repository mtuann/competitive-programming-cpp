// Template: tree DP rerooting
// Signal: every root needs an answer and parent-side contribution must complement child subtrees.
// Assumes: the reroot transition is O(1) per edge; this concrete skeleton computes sum of distances to all nodes.
// Exposes: dfs_down / dfs_up plus sub_size, sub_dist, all_dist arrays.
// Complexity: O(n).
// Main trap: treating this sum-of-distances skeleton as a fully generic rerooting framework.
// Links:
//   Topic: topics/dp/tree-dp/README.md
//   Note: no exact repo note yet; reopen topics/dp/tree-dp/README.md

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> sub_size;
vector<long long> sub_dist;
vector<long long> all_dist;

void dfs_down(int u, int parent) {
    sub_size[u] = 1;
    sub_dist[u] = 0;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs_down(v, u);
        sub_size[u] += sub_size[v];
        sub_dist[u] += sub_dist[v] + sub_size[v];
    }
}

void dfs_up(int u, int parent, int n) {
    for (int v : g[u]) {
        if (v == parent) continue;
        all_dist[v] = all_dist[u] - sub_size[v] + (n - sub_size[v]);
        dfs_up(v, u, n);
    }
}

int main() {
    int n = 5;
    g.assign(n, {});
    auto add_edge = [&](int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    };
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(2, 3);
    add_edge(2, 4);

    sub_size.assign(n, 0);
    sub_dist.assign(n, 0);
    all_dist.assign(n, 0);

    dfs_down(0, -1);
    all_dist[0] = sub_dist[0];
    dfs_up(0, -1, n);

    for (int i = 0; i < n; ++i) {
        cout << all_dist[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
