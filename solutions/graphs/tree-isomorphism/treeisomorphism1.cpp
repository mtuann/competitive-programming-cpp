// CSES - Tree Isomorphism I
// Rooted unordered tree isomorphism by bottom-up canonical subtree encoding.

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

    int encode_root(const vector<vector<int>>& graph, int root) {
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
        return type[root];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(n), b(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            b[u].push_back(v);
            b[v].push_back(u);
        }

        RootedTreeCanonicalizer canon;
        int left_root_type = canon.encode_root(a, 0);
        int right_root_type = canon.encode_root(b, 0);
        cout << (left_root_type == right_root_type ? "YES" : "NO") << '\n';
    }
    return 0;
}
