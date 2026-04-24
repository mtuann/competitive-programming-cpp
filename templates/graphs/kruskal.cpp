// Template: Kruskal MST
// Signal: minimum spanning tree from an explicit weighted edge list.
// Assumes: graph is undirected, weights are sortable, and DSU merges are enough for connectivity.
// Exposes: one sorted-edge MST skeleton plus embedded DSU.
// Complexity: O(m log m) for sorting plus near-linear DSU work.
// Main trap: reaching for it on a path-distance problem that wants shortest paths, not an MST.
// Links:
//   Topic: topics/graphs/mst/README.md
//   Note: practice/ladders/graphs/mst/roadreparation.md

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent, size;
    explicit DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
};

int main() {
    int n = 4;
    vector<Edge> edges = {{0, 1, 1}, {1, 2, 2}, {0, 2, 5}, {2, 3, 1}};
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    long long total = 0;
    for (const Edge &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
        }
    }
    cout << total << '\n';
    return 0;
}
