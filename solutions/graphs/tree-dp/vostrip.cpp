#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
Problem: VOSTRIP - VOSTRIP
Judge: VN SPOJ
URL: https://vn.spoj.com/problems/VOSTRIP/
Mirror: https://oj.vnoi.info/problem/vostrip
Topic: Trees, path decomposition

Key idea:
- each edge weight is how many path-copies must use that edge
- at a vertex, copies from incident edges can be paired only across two different edges
- minimum unmatched endpoints left at a vertex is:
    max(sum_incident % 2, 2 * max_incident - sum_incident)
- total minimum number of paths is half of the sum of those leftovers
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> sum_incident(n + 1, 0);
    vector<long long> max_incident(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        sum_incident[u] += w;
        sum_incident[v] += w;
        max_incident[u] = max(max_incident[u], w);
        max_incident[v] = max(max_incident[v], w);
    }

    long long endpoint_sum = 0;
    for (int u = 1; u <= n; ++u) {
        long long need = max(sum_incident[u] & 1LL, 2LL * max_incident[u] - sum_incident[u]);
        endpoint_sum += need;
    }

    cout << (endpoint_sum / 2) << '\n';
    return 0;
}
