// Template: Tree isomorphism on rooted unordered trees.
// Signal: two rooted trees, child order irrelevant, and only shape matters.
// Assumes: both inputs are trees; roots are fixed and known.
// Exposes: rooted_isomorphic(g1, root1, g2, root2).
// Complexity: O(n log n) from sorting child-signature vectors.
// Main trap: assigning subtree IDs separately in the two trees.
// Links:
//   Topic: topics/graphs/tree-isomorphism/README.md
//   Note: practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct SignatureHash {
    size_t operator()(const vector<int>& values) const {
        size_t h = values.size();
        for (int x : values) {
            h ^= static_cast<size_t>(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        }
        return h;
    }
};

struct RootedTreeCanonicalizer {
    unordered_map<vector<int>, int, SignatureHash> id_of;

    int intern(vector<int> signature) {
        auto it = id_of.find(signature);
        if (it != id_of.end()) return it->second;
        int id = static_cast<int>(id_of.size());
        id_of.emplace(std::move(signature), id);
        return id;
    }

    vector<int> encode(const vector<vector<int>>& graph, int root) {
        const int n = static_cast<int>(graph.size());
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);

        vector<int> stack = {root};
        parent[root] = root;
        while (!stack.empty()) {
            int v = stack.back();
            stack.pop_back();
            order.push_back(v);
            for (int u : graph[v]) {
                if (u == parent[v]) continue;
                parent[u] = v;
                stack.push_back(u);
            }
        }

        vector<int> type(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            int v = order[i];
            vector<int> child_types;
            for (int u : graph[v]) {
                if (u == parent[v]) continue;
                child_types.push_back(type[u]);
            }
            sort(child_types.begin(), child_types.end());
            type[v] = intern(std::move(child_types));
        }
        return type;
    }
};

bool rooted_isomorphic(
    const vector<vector<int>>& left,
    int root_left,
    const vector<vector<int>>& right,
    int root_right
) {
    if (left.size() != right.size()) return false;
    RootedTreeCanonicalizer canon;
    vector<int> left_type = canon.encode(left, root_left);
    vector<int> right_type = canon.encode(right, root_right);
    return left_type[root_left] == right_type[root_right];
}

int main() {
    vector<vector<int>> a(6), b(6), c(6);

    auto add_edge = [](vector<vector<int>>& g, int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    };

    add_edge(a, 0, 1);
    add_edge(a, 0, 2);
    add_edge(a, 1, 3);
    add_edge(a, 1, 4);
    add_edge(a, 2, 5);

    add_edge(b, 0, 1);
    add_edge(b, 0, 2);
    add_edge(b, 2, 3);
    add_edge(b, 2, 4);
    add_edge(b, 1, 5);

    add_edge(c, 0, 1);
    add_edge(c, 0, 2);
    add_edge(c, 0, 3);
    add_edge(c, 3, 4);
    add_edge(c, 4, 5);

    cout << (rooted_isomorphic(a, 0, b, 0) ? "YES" : "NO") << '\n';
    cout << (rooted_isomorphic(a, 0, c, 0) ? "YES" : "NO") << '\n';
    return 0;
}
