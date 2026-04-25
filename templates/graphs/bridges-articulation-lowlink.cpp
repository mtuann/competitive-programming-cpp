// Template: Bridges / Articulation / BCC
// Signal: undirected graph asks for critical edges, critical vertices, or block-cut style structure.
// Assumes: undirected graph; vertices are 0-indexed; edge ids distinguish parallel edges safely.
// Exposes: LowlinkUndirected with add_edge(), build(), bridges, is_cutpoint, and biconnected_components.
// Complexity: O(n + m).
// Main trap: mixing up the strict bridge test (>) with the articulation test (>=), or forgetting the root case.
// Links:
//   Topic: topics/graphs/bridges-articulation/README.md
//   Note: practice/ladders/graphs/bridges-articulation/necessaryroads.md

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct LowlinkUndirected {
    struct AdjEdge {
        int to, id;
    };

    int n;
    vector<pair<int, int>> edges;
    vector<vector<AdjEdge>> g;

    vector<int> tin, low, parent, parent_edge, iter, child_count;
    vector<char> is_cutpoint;
    vector<pair<int, int>> bridges;
    vector<vector<int>> biconnected_components;

    explicit LowlinkUndirected(int n)
        : n(n),
          g(n),
          tin(n, -1),
          low(n, -1),
          parent(n, -1),
          parent_edge(n, -1),
          iter(n, 0),
          child_count(n, 0),
          is_cutpoint(n, false),
          seen_vertex(n, -1) {}

    void add_edge(int u, int v) {
        int id = (int)edges.size();
        edges.push_back({u, v});
        g[u].push_back({v, id});
        g[v].push_back({u, id});
    }

    void build() {
        fill(tin.begin(), tin.end(), -1);
        fill(low.begin(), low.end(), -1);
        fill(parent.begin(), parent.end(), -1);
        fill(parent_edge.begin(), parent_edge.end(), -1);
        fill(iter.begin(), iter.end(), 0);
        fill(child_count.begin(), child_count.end(), 0);
        fill(is_cutpoint.begin(), is_cutpoint.end(), false);
        fill(seen_vertex.begin(), seen_vertex.end(), -1);
        bridges.clear();
        biconnected_components.clear();
        edge_stack.clear();

        int timer = 0;
        int stamp = 0;
        vector<int> st;
        st.reserve(n);

        for (int start = 0; start < n; ++start) {
            if (tin[start] != -1) {
                continue;
            }

            st.push_back(start);
            while (!st.empty()) {
                int v = st.back();

                if (tin[v] == -1) {
                    tin[v] = low[v] = timer++;
                }

                if (iter[v] < (int)g[v].size()) {
                    auto [to, id] = g[v][iter[v]++];
                    if (id == parent_edge[v]) {
                        continue;
                    }
                    if (tin[to] == -1) {
                        parent[to] = v;
                        parent_edge[to] = id;
                        ++child_count[v];
                        edge_stack.push_back(id);
                        st.push_back(to);
                    } else if (tin[to] < tin[v]) {
                        low[v] = min(low[v], tin[to]);
                        edge_stack.push_back(id);
                    }
                    continue;
                }

                st.pop_back();
                int p = parent[v];

                if (p == -1) {
                    if (child_count[v] > 1) {
                        is_cutpoint[v] = true;
                    }
                    continue;
                }

                low[p] = min(low[p], low[v]);

                if (low[v] >= tin[p]) {
                    if (parent[p] != -1 || child_count[p] > 1) {
                        is_cutpoint[p] = true;
                    }
                    pop_component_until(parent_edge[v], stamp++);
                }

                if (low[v] > tin[p]) {
                    bridges.push_back(edges[parent_edge[v]]);
                }
            }
        }
    }

private:
    vector<int> edge_stack;
    vector<int> seen_vertex;

    void pop_component_until(int stop_edge_id, int stamp) {
        vector<int> component;
        while (!edge_stack.empty()) {
            int eid = edge_stack.back();
            edge_stack.pop_back();
            auto [a, b] = edges[eid];
            if (seen_vertex[a] != stamp) {
                seen_vertex[a] = stamp;
                component.push_back(a);
            }
            if (seen_vertex[b] != stamp) {
                seen_vertex[b] = stamp;
                component.push_back(b);
            }
            if (eid == stop_edge_id) {
                break;
            }
        }
        if (!component.empty()) {
            biconnected_components.push_back(std::move(component));
        }
    }
};

int main() {
    LowlinkUndirected low(5);
    low.add_edge(0, 1);
    low.add_edge(1, 2);
    low.add_edge(2, 0);
    low.add_edge(1, 3);
    low.add_edge(3, 4);
    low.build();

    cout << "bridges=" << low.bridges.size() << '\n';
    cout << "cutpoints:";
    for (int i = 0; i < 5; ++i) {
        if (low.is_cutpoint[i]) {
            cout << ' ' << i;
        }
    }
    cout << '\n';
    return 0;
}
