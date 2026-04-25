// Template: Eulerian path / cycle
// Signal: use every edge exactly once in a static graph, either undirected or directed.
// Assumes: vertices are 0-indexed; isolated vertices are ignored by existence checks;
// querying an empty graph returns {0} when n > 0.
// Exposes: EulerianUndirected with add_edge(), eulerian_path(), eulerian_cycle();
// EulerianDirected with add_edge(), eulerian_path(), eulerian_cycle().
// Complexity: O(n + m).
// Main trap: checking only degree conditions and forgetting the final path-size == m + 1 guard.
// Links:
//   Topic: topics/graphs/eulerian-path-cycle/README.md
//   Note: practice/ladders/graphs/eulerian-path-cycle/maildelivery.md

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct EulerianUndirected {
    int n;
    vector<vector<pair<int, int>>> g;
    vector<pair<int, int>> edges;
    vector<int> degree;

    explicit EulerianUndirected(int n) : n(n), g(n), degree(n, 0) {}

    void add_edge(int u, int v) {
        int id = static_cast<int>(edges.size());
        edges.push_back({u, v});
        g[u].push_back({v, id});
        g[v].push_back({u, id});
        ++degree[u];
        ++degree[v];
    }

    vector<int> eulerian_path() const {
        if (edges.empty()) {
            return n == 0 ? vector<int>() : vector<int>{0};
        }

        vector<int> odd;
        for (int v = 0; v < n; ++v) {
            if (degree[v] % 2 == 1) {
                odd.push_back(v);
            }
        }
        if (!(odd.empty() || odd.size() == 2)) {
            return {};
        }

        int start = odd.empty() ? first_non_isolated() : odd[0];
        return build_from(start);
    }

    vector<int> eulerian_cycle() const {
        if (edges.empty()) {
            return n == 0 ? vector<int>() : vector<int>{0};
        }
        for (int v = 0; v < n; ++v) {
            if (degree[v] % 2 == 1) {
                return {};
            }
        }
        vector<int> path = build_from(first_non_isolated());
        if (path.empty() || path.front() != path.back()) {
            return {};
        }
        return path;
    }

private:
    int first_non_isolated() const {
        for (int v = 0; v < n; ++v) {
            if (degree[v] > 0) {
                return v;
            }
        }
        return 0;
    }

    vector<int> build_from(int start) const {
        vector<int> ptr(n, 0);
        vector<char> used(edges.size(), false);
        vector<int> st{start}, path;
        path.reserve(edges.size() + 1);

        while (!st.empty()) {
            int v = st.back();
            while (ptr[v] < static_cast<int>(g[v].size()) && used[g[v][ptr[v]].second]) {
                ++ptr[v];
            }
            if (ptr[v] == static_cast<int>(g[v].size())) {
                path.push_back(v);
                st.pop_back();
            } else {
                auto [to, id] = g[v][ptr[v]++];
                if (used[id]) {
                    continue;
                }
                used[id] = true;
                st.push_back(to);
            }
        }

        if (path.size() != edges.size() + 1) {
            return {};
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

struct EulerianDirected {
    int n;
    vector<vector<pair<int, int>>> g;
    vector<pair<int, int>> edges;
    vector<int> indeg, outdeg;

    explicit EulerianDirected(int n) : n(n), g(n), indeg(n, 0), outdeg(n, 0) {}

    void add_edge(int u, int v) {
        int id = static_cast<int>(edges.size());
        edges.push_back({u, v});
        g[u].push_back({v, id});
        ++outdeg[u];
        ++indeg[v];
    }

    vector<int> eulerian_path() const {
        if (edges.empty()) {
            return n == 0 ? vector<int>() : vector<int>{0};
        }

        int start = -1;
        int end = -1;
        for (int v = 0; v < n; ++v) {
            int diff = outdeg[v] - indeg[v];
            if (diff == 1) {
                if (start != -1) {
                    return {};
                }
                start = v;
            } else if (diff == -1) {
                if (end != -1) {
                    return {};
                }
                end = v;
            } else if (diff != 0) {
                return {};
            }
        }
        if ((start == -1) != (end == -1)) {
            return {};
        }
        if (start == -1) {
            start = first_with_outgoing();
        }
        return build_from(start);
    }

    vector<int> eulerian_cycle() const {
        if (edges.empty()) {
            return n == 0 ? vector<int>() : vector<int>{0};
        }
        for (int v = 0; v < n; ++v) {
            if (indeg[v] != outdeg[v]) {
                return {};
            }
        }
        vector<int> path = build_from(first_with_outgoing());
        if (path.empty() || path.front() != path.back()) {
            return {};
        }
        return path;
    }

private:
    int first_with_outgoing() const {
        for (int v = 0; v < n; ++v) {
            if (outdeg[v] > 0) {
                return v;
            }
        }
        return 0;
    }

    vector<int> build_from(int start) const {
        vector<int> ptr(n, 0);
        vector<char> used(edges.size(), false);
        vector<int> st{start}, path;
        path.reserve(edges.size() + 1);

        while (!st.empty()) {
            int v = st.back();
            while (ptr[v] < static_cast<int>(g[v].size()) && used[g[v][ptr[v]].second]) {
                ++ptr[v];
            }
            if (ptr[v] == static_cast<int>(g[v].size())) {
                path.push_back(v);
                st.pop_back();
            } else {
                auto [to, id] = g[v][ptr[v]++];
                if (used[id]) {
                    continue;
                }
                used[id] = true;
                st.push_back(to);
            }
        }

        if (path.size() != edges.size() + 1) {
            return {};
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    EulerianUndirected undirected(4);
    undirected.add_edge(0, 1);
    undirected.add_edge(1, 2);
    undirected.add_edge(2, 0);
    undirected.add_edge(0, 3);
    undirected.add_edge(3, 2);
    vector<int> trail = undirected.eulerian_path();
    cout << trail.size() << '\n';
    return 0;
}
