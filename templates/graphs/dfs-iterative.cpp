// Template: iterative DFS.
// Useful when recursion depth may be risky.

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
