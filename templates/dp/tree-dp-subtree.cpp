// Template: subtree DP with one postorder DFS.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> sub_size;

void dfs(int u, int parent) {
    sub_size[u] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);
        sub_size[u] += sub_size[v];
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
    dfs(0, -1);
    cout << sub_size[2] << '\n';
    return 0;
}
