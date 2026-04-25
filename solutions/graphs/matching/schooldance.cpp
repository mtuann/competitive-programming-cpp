// Problem: School Dance
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1696
// Topic: bipartite matching, Hopcroft-Karp, matching reconstruction
// Idea: model boys and girls as the two sides of a bipartite graph, run
// Hopcroft-Karp, and print every matched left-side vertex with its partner.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct HopcroftKarp {
    int n_left, n_right;
    vector<vector<int>> g;
    vector<int> dist, match_left, match_right;

    HopcroftKarp(int n_left, int n_right)
        : n_left(n_left),
          n_right(n_right),
          g(n_left),
          dist(n_left),
          match_left(n_left, -1),
          match_right(n_right, -1) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        fill(dist.begin(), dist.end(), -1);
        for (int u = 0; u < n_left; ++u) {
            if (match_left[u] == -1) {
                dist[u] = 0;
                q.push(u);
            }
        }

        bool found = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                int mate = match_right[v];
                if (mate == -1) {
                    found = true;
                } else if (dist[mate] == -1) {
                    dist[mate] = dist[u] + 1;
                    q.push(mate);
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : g[u]) {
            int mate = match_right[v];
            if (mate == -1 || (dist[mate] == dist[u] + 1 && dfs(mate))) {
                match_left[u] = v;
                match_right[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int max_matching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 0; u < n_left; ++u) {
                if (match_left[u] == -1 && dfs(u)) {
                    ++matching;
                }
            }
        }
        return matching;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    HopcroftKarp hk(n, m);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        hk.add_edge(a - 1, b - 1);
    }

    int matching = hk.max_matching();
    cout << matching << '\n';
    for (int u = 0; u < n; ++u) {
        if (hk.match_left[u] != -1) {
            cout << u + 1 << ' ' << hk.match_left[u] + 1 << '\n';
        }
    }
    return 0;
}
