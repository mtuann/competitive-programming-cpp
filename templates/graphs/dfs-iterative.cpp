// Template: iterative DFS
// Signal: traversal or component discovery is needed, but recursion depth may be risky.
// Assumes: stack order is acceptable and distance layers are not the proof-critical object.
// Exposes: one explicit stack traversal skeleton plus visited/order arrays.
// Complexity: O(n + m).
// Main trap: expecting BFS-style shortest-path guarantees from a DFS traversal order.
// Links:
//   Topic: topics/graphs/bfs-dfs/README.md
//   Note: practice/ladders/graphs/graph-modeling/countingrooms.md

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0},
        {1}
    };

    int n = static_cast<int>(graph.size());
    vector<int> visited(n, 0);
    vector<int> order;
    stack<int> st;

    st.push(0);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = 1;
        order.push_back(u);
        for (int i = static_cast<int>(graph[u].size()) - 1; i >= 0; --i) {
            int v = graph[u][i];
            if (!visited[v]) {
                st.push(v);
            }
        }
    }

    for (int x : order) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
