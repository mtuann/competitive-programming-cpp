// Problem: MTREECOL - Color a tree
// Judge: VN SPOJ / VNOI
// Source URL: https://vn.spoj.com/problems/MTREECOL/
// Mirror URL: https://oj.vnoi.info/problem/mtreecol
// Topic: trees, greedy scheduling, precedence constraints
// Idea: contract the tree bottom-up. For any active non-root component X with
// total weight W(X) and size S(X), its whole block should be scheduled before
// another available block Y iff W(X) / S(X) >= W(Y) / S(Y). Repeatedly merge
// the active non-root component with maximum density into its parent.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, root;
        cin >> n >> root;
        if (!cin) {
            return 0;
        }
        if (n == 0 && root == 0) {
            break;
        }

        vector<long long> sum_weight(n + 1, 0);
        vector<int> parent(n + 1, 0);
        vector<int> component_size(n + 1, 1);
        vector<char> active(n + 1, 1);

        long long answer = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> sum_weight[i];
            answer += sum_weight[i];
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            parent[v] = u;
        }

        for (int step = 0; step < n - 1; ++step) {
            int best = -1;
            for (int u = 1; u <= n; ++u) {
                if (!active[u] || u == root) {
                    continue;
                }
                if (best == -1 ||
                    sum_weight[u] * component_size[best] >
                        sum_weight[best] * component_size[u] ||
                    (sum_weight[u] * component_size[best] ==
                         sum_weight[best] * component_size[u] &&
                     u < best)) {
                    best = u;
                }
            }

            int p = parent[best];
            answer += sum_weight[best] * component_size[p];

            for (int u = 1; u <= n; ++u) {
                if (active[u] && parent[u] == best) {
                    parent[u] = p;
                }
            }

            active[best] = 0;
            sum_weight[p] += sum_weight[best];
            component_size[p] += component_size[best];
        }

        cout << answer << '\n';
    }

    return 0;
}
