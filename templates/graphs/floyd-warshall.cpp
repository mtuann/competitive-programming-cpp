// Template: Floyd-Warshall
// Signal: all-pairs shortest paths on small dense graphs, or closure-style DP on distances.
// Assumes: O(n^3) time and O(n^2) memory are acceptable, INF guards prevent overflow, and no negative cycle is needed for shortest-path meaning.
// Exposes: floyd_warshall(dist) over an initialized distance matrix.
// Complexity: O(n^3) time, O(n^2) memory.
// Main trap: forgetting the INF guards, or reading the final matrix as shortest-path distances when negative cycles exist.
// Links:
//   Topic: topics/graphs/shortest-paths/README.md
//   Notebook: notebook/graph-cheatsheet.md

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void floyd_warshall(vector<vector<long long>> &dist) {
    const long long INF = numeric_limits<long long>::max() / 4;
    int n = static_cast<int>(dist.size());
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) {
                    continue;
                }
                long long through_k = dist[i][k] + dist[k][j];
                if (through_k < dist[i][j]) {
                    dist[i][j] = through_k;
                }
            }
        }
    }
}

int main() {
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<vector<long long>> dist = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    floyd_warshall(dist);
    cout << dist[0][3] << '\n';
    return 0;
}
