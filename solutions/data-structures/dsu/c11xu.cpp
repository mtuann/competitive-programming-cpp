#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
Problem: C11XU - Bộ sưu tập đồng xu
Judge: VN SPOJ / VNOI
URL: https://vn.spoj.com/problems/C11XU/
Mirror: https://oj.vnoi.info/problem/c11xu
Topic: DSU, forest independence, augmenting path

Key idea:
- each envelope contributes the parity vector of its two coin types
- a nonempty chosen subset is "bad" exactly when those parity vectors xor to 0
- for a pair of distinct types (u, v), the parity vector is the incidence vector of
  an undirected edge; bad subsets are exactly cycles / even subgraphs
- so valid chosen envelopes are exactly a forest, with the extra rule that from each
  pair of neighboring envelopes we may choose at most one
- maximize the size of a set independent in:
    1) a partition matroid (one envelope per pair-group)
    2) a graphic matroid (chosen edges form a forest)
- solve the small instance with augmenting paths on the exchange graph
*/

namespace {

struct Dsu {
    vector<int> parent;
    vector<int> sz;

    explicit Dsu(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

struct Edge {
    int u;
    int v;
    int group;
    bool loop;
};

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> coin(n);
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
        --coin[i];
    }

    const int envelope_count = n / 2;
    const int group_count = envelope_count / 2;

    vector<Edge> edges(envelope_count);
    for (int i = 0; i < envelope_count; ++i) {
        int u = coin[2 * i];
        int v = coin[2 * i + 1];
        edges[i] = Edge{u, v, i / 2, u == v};
    }

    vector<char> in_set(envelope_count, 0);
    vector<int> selected_in_group(group_count, -1);

    vector<vector<pair<int, int>>> forest(m);
    vector<vector<int>> exchange(envelope_count);
    vector<int> starts;
    vector<char> terminal(envelope_count, 0);
    vector<int> parent_vertex(m, -1);
    vector<int> parent_edge(m, -1);

    while (true) {
        for (int i = 0; i < m; ++i) {
            forest[i].clear();
        }
        fill(selected_in_group.begin(), selected_in_group.end(), -1);

        Dsu dsu(m);
        for (int i = 0; i < envelope_count; ++i) {
            if (!in_set[i]) {
                continue;
            }
            selected_in_group[edges[i].group] = i;
            forest[edges[i].u].push_back({edges[i].v, i});
            forest[edges[i].v].push_back({edges[i].u, i});
            dsu.unite(edges[i].u, edges[i].v);
        }

        for (int i = 0; i < envelope_count; ++i) {
            exchange[i].clear();
            terminal[i] = 0;
        }
        starts.clear();

        for (int i = 0; i < envelope_count; ++i) {
            if (in_set[i] || edges[i].loop) {
                continue;
            }

            int chosen = selected_in_group[edges[i].group];
            if (chosen == -1) {
                terminal[i] = 1;
            } else {
                exchange[i].push_back(chosen);
            }

            if (dsu.find(edges[i].u) != dsu.find(edges[i].v)) {
                starts.push_back(i);
                continue;
            }

            fill(parent_vertex.begin(), parent_vertex.end(), -1);
            fill(parent_edge.begin(), parent_edge.end(), -1);

            queue<int> q;
            q.push(edges[i].u);
            parent_vertex[edges[i].u] = edges[i].u;

            while (!q.empty() && parent_vertex[edges[i].v] == -1) {
                int u = q.front();
                q.pop();
                for (const auto &next : forest[u]) {
                    int v = next.first;
                    int edge_id = next.second;
                    if (parent_vertex[v] != -1) {
                        continue;
                    }
                    parent_vertex[v] = u;
                    parent_edge[v] = edge_id;
                    q.push(v);
                }
            }

            int cur = edges[i].v;
            while (cur != edges[i].u) {
                exchange[parent_edge[cur]].push_back(i);
                cur = parent_vertex[cur];
            }
        }

        vector<int> parent(envelope_count, -1);
        vector<char> visited(envelope_count, 0);
        queue<int> q;

        int finish = -1;
        for (int start : starts) {
            visited[start] = 1;
            q.push(start);
            if (terminal[start]) {
                finish = start;
                break;
            }
        }

        while (finish == -1 && !q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : exchange[u]) {
                if (visited[v]) {
                    continue;
                }
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
                if (terminal[v]) {
                    finish = v;
                    break;
                }
            }
        }

        if (finish == -1) {
            break;
        }

        int cur = finish;
        while (cur != -1) {
            in_set[cur] ^= 1;
            cur = parent[cur];
        }
    }

    int chosen = 0;
    for (char picked : in_set) {
        chosen += picked;
    }

    cout << (2 * chosen) << '\n';
    return 0;
}
