// Problem: Road Reparation
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1675
// Topic: MST, Kruskal, DSU
// Idea: sort edges by weight and take an edge iff it connects two different
// DSU components. If fewer than n - 1 edges are chosen, the graph is disconnected.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    explicit DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

struct Edge {
    int u;
    int v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    long long total_cost = 0;
    int used_edges = 0;

    for (const Edge& edge : edges) {
        if (!dsu.unite(edge.u, edge.v)) {
            continue;
        }
        total_cost += edge.w;
        ++used_edges;
    }

    if (used_edges != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << total_cost << '\n';
    }
    return 0;
}
