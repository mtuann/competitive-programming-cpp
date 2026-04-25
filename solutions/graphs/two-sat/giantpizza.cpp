// Problem: Giant Pizza
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1684
// Topic: 2-SAT, implication graph, SCC assignment extraction
// Idea: treat each topping as one boolean variable, encode each wish pair as
// one 2-SAT clause, solve with SCCs on the implication graph, and print any
// recovered satisfying assignment.

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
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

    void either(int a, bool a_true, int b, bool b_true) {
        int x = lit(a, a_true);
        int y = lit(b, b_true);
        add_implication_literal(neg(x), y);
        add_implication_literal(neg(y), x);
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

static bool parse_wish(const string &sign) {
    return sign == "+";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    TwoSat sat(m);
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        int x1, x2;
        cin >> s1 >> x1 >> s2 >> x2;
        sat.either(x1 - 1, parse_wish(s1), x2 - 1, parse_wish(s2));
    }

    if (!sat.satisfiable()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        cout << (sat.assignment[i] ? '+' : '-');
        if (i + 1 < m) {
            cout << ' ';
        }
    }
    cout << '\n';
    return 0;
}
