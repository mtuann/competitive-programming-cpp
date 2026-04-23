// Template: Hopcroft-Karp for bipartite matching.

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
        for (int i = 0; i < n_left; ++i) {
            if (match_left[i] == -1) {
                dist[i] = 0;
                q.push(i);
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
            for (int i = 0; i < n_left; ++i) {
                if (match_left[i] == -1 && dfs(i)) {
                    ++matching;
                }
            }
        }
        return matching;
    }
};

int main() {
    HopcroftKarp hk(3, 3);
    hk.add_edge(0, 0);
    hk.add_edge(0, 1);
    hk.add_edge(1, 1);
    hk.add_edge(2, 2);
    cout << hk.max_matching() << '\n';
    return 0;
}
