// Problem: Counting Rooms
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1192
// Topic: graph modeling, grid graph, flood fill
// Idea: treat each floor cell as a vertex and each 4-neighbor move as an edge.
// Then the number of rooms is the number of connected components among floor
// cells, which we count with an iterative DFS.

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int row = 0; row < n; ++row) {
        cin >> grid[row];
    }

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    int rooms = 0;
    vector<pair<int, int>> stack;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (grid[row][col] != '.') {
                continue;
            }

            ++rooms;
            grid[row][col] = '#';
            stack.push_back({row, col});

            while (!stack.empty()) {
                auto [r, c] = stack.back();
                stack.pop_back();

                for (int dir = 0; dir < 4; ++dir) {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                        continue;
                    }
                    if (grid[nr][nc] != '.') {
                        continue;
                    }
                    grid[nr][nc] = '#';
                    stack.push_back({nr, nc});
                }
            }
        }
    }

    cout << rooms << '\n';
    return 0;
}
