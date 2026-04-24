// Template: Kosaraju SCC
// Signal: compress directed cycles into SCC ids and then reason on the condensation DAG.
// Assumes: the graph is directed and two DFS passes are acceptable.
// Exposes: dfs_order / dfs_component helpers plus one SCC labeling skeleton.
// Complexity: O(n + m).
// Main trap: forgetting the second pass must run on the reversed graph in reverse finish order.
// Links:
//   Topic: topics/graphs/scc-toposort/README.md
//   Notebook: notebook/graph-cheatsheet.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs_order(int u, const vector<vector<int>> &g, vector<int> &used, vector<int> &order) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) dfs_order(v, g, used, order);
    }
    order.push_back(u);
}

void dfs_component(int u, const vector<vector<int>> &rg, vector<int> &comp, int cid) {
    comp[u] = cid;
    for (int v : rg[u]) {
        if (comp[v] == -1) dfs_component(v, rg, comp, cid);
    }
}

int main() {
    vector<vector<int>> g = {{1}, {2}, {0, 3}, {4}, {3}};
    int n = static_cast<int>(g.size());
    vector<vector<int>> rg(n);
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            rg[v].push_back(u);
        }
    }

    vector<int> used(n, 0), order;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs_order(i, g, used, order);
    }
    reverse(order.begin(), order.end());

    vector<int> comp(n, -1);
    int cid = 0;
    for (int u : order) {
        if (comp[u] == -1) {
            dfs_component(u, rg, comp, cid++);
        }
    }

    for (int x : comp) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
