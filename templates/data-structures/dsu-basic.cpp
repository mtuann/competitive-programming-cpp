// Template: DSU basic
// Signal: merge-only connectivity or component tracking under unions.
// Assumes: no deletions, rollback, parity constraints, or path aggregates.
// Exposes: DSU with find(x), unite(a, b), same(a, b), component_size(x).
// Complexity: O(alpha(n)) amortized per operation.
// Main trap: attaching component metadata anywhere except the current representative root.
// Links:
//   Topic: topics/data-structures/dsu/README.md
//   Note: practice/ladders/data-structures/dsu/c11xu.md
//   Note: practice/ladders/graphs/mst/roadreparation.md

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    explicit DSU(int n) : parent(n), size(n, 1) {
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

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int component_size(int x) {
        return size[find(x)];
    }
};

int main() {
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    cout << dsu.same(0, 2) << '\n';
    cout << dsu.component_size(0) << '\n';
    return 0;
}
