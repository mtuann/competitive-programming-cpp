// Problem: Sliding Window Minimum
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/3221
// Topic: monotonic deque, sliding window, generated stream
// Idea: generate the sequence online, maintain a deque of increasing candidates,
// and xor the minimum of each full window.

#include <deque>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long long x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    deque<pair<int, long long>> dq;
    long long answer = 0;
    long long cur = x;

    for (int i = 0; i < n; ++i) {
        long long value = cur;

        while (!dq.empty() && dq.back().second >= value) {
            dq.pop_back();
        }
        dq.emplace_back(i, value);

        int left = i - k + 1;
        while (!dq.empty() && dq.front().first < left) {
            dq.pop_front();
        }

        if (i + 1 >= k) {
            answer ^= dq.front().second;
        }

        cur = (a * cur + b) % c;
    }

    cout << answer << '\n';
    return 0;
}
