// Template: 2-SAT
// Signal: binary choices with pairwise logical clauses like (a or b), not-both, exactly-one, or implication constraints.
// Assumes: every variable is boolean and every constraint can be rewritten as one or more 2-literal clauses.
// Exposes: TwoSat with either(), implies(), set_value(), satisfiable(), and assignment for one recovered solution.
// Complexity: O(n + m) over variables plus clause-derived implication edges.
// Main trap: encoding statement semantics or literal complements incorrectly, then blaming SCCs.
// Links:
//   Topic: topics/graphs/two-sat/README.md
//   Note: practice/ladders/graphs/two-sat/giantpizza.md

#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct TwoSat {
    int n;
    vector<vector<int>> g, rg;
    vector<int> comp, assignment;

    explicit TwoSat(int n) : n(n), g(2 * n), rg(2 * n), comp(2 * n, -1), assignment(n, 0) {}

    int lit(int var, bool is_true) const {
        return 2 * var + (is_true ? 0 : 1);
    }

    int neg(int v) const {
        return v ^ 1;
    }

    void add_implication_literal(int a, int b) {
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    void implies(int a, bool a_true, int b, bool b_true) {
        int x = lit(a, a_true);
        int y = lit(b, b_true);
        add_implication_literal(x, y);
        add_implication_literal(neg(y), neg(x));
    }

    void either(int a, bool a_true, int b, bool b_true) {
        int x = lit(a, a_true);
        int y = lit(b, b_true);
        add_implication_literal(neg(x), y);
        add_implication_literal(neg(y), x);
    }

    void set_value(int var, bool is_true) {
        int x = lit(var, is_true);
        add_implication_literal(neg(x), x);
    }

    bool satisfiable() {
        int m = 2 * n;
        vector<int> vis(m, 0), order;
        order.reserve(m);

        for (int start = 0; start < m; ++start) {
            if (vis[start]) {
                continue;
            }
            stack<pair<int, int>> st;
            st.push({start, 0});
            vis[start] = 1;

            while (!st.empty()) {
                int u = st.top().first;
                int &idx = st.top().second;
                if (idx < (int)g[u].size()) {
                    int v = g[u][idx++];
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push({v, 0});
                    }
                } else {
                    order.push_back(u);
                    st.pop();
                }
            }
        }

        fill(comp.begin(), comp.end(), -1);
        int cid = 0;
        for (int i = m - 1; i >= 0; --i) {
            int start = order[i];
            if (comp[start] != -1) {
                continue;
            }
            stack<int> st;
            st.push(start);
            comp[start] = cid;
            while (!st.empty()) {
                int u = st.top();
                st.pop();
                for (int v : rg[u]) {
                    if (comp[v] == -1) {
                        comp[v] = cid;
                        st.push(v);
                    }
                }
            }
            ++cid;
        }

        for (int i = 0; i < n; ++i) {
            int t = lit(i, true);
            int f = lit(i, false);
            if (comp[t] == comp[f]) {
                return false;
            }
            assignment[i] = comp[t] > comp[f];
        }
        return true;
    }
};

int main() {
    TwoSat ts(2);
    ts.either(0, true, 1, true);   // x0 or x1
    ts.either(0, false, 1, true);  // not x0 or x1

    if (!ts.satisfiable()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < 2; ++i) {
        cout << ts.assignment[i] << (i + 1 == 2 ? '\n' : ' ');
    }
    return 0;
}
