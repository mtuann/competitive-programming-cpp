// Template: Kruskal minimum spanning tree.

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
    int u, v, w;
};

int main() {
    int n = 4;
    vector<Edge> edges = {{0, 1, 1}, {1, 2, 2}, {0, 2, 5}, {2, 3, 1}};
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    int total = 0;
    for (const Edge &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
        }
    }
    cout << total << '\n';
    return 0;
}
