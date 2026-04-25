// Problem: Red and Blue Lamps
// Judge: AtCoder ABC218 H
// Source URL: https://atcoder.jp/contests/abc218/tasks/abc218_h
// Topic: Aliens trick, weighted independent set on a path, penalty search
// Idea: transform to choosing exactly R non-adjacent positions of weights
// B_i = A_{i-1} + A_i, then binary search an integer penalty lambda and solve
// the penalized path DP while tie-breaking equal values by larger counts.

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct PenalizedState {
    __int128 value = 0;
    int count = 0;
};

bool better(const PenalizedState& a, const PenalizedState& b) {
    if (a.value != b.value) {
        return a.value > b.value;
    }
    return a.count > b.count;
}

PenalizedState solve_penalized_nonadjacent(const vector<long long>& weights, long long lambda) {
    static constexpr __int128 NEG_INF = -(static_cast<__int128>(1) << 120);

    PenalizedState skip{0, 0};
    PenalizedState take{NEG_INF, numeric_limits<int>::min() / 4};

    for (long long weight : weights) {
        PenalizedState new_skip = better(skip, take) ? skip : take;

        PenalizedState new_take = take;
        if (skip.value > NEG_INF / 2) {
            new_take.value = skip.value + static_cast<__int128>(weight) - lambda;
            new_take.count = skip.count + 1;
        }

        skip = new_skip;
        take = new_take;
    }

    return better(skip, take) ? skip : take;
}

string to_string_i128(__int128 x) {
    if (x == 0) {
        return "0";
    }
    bool neg = x < 0;
    if (neg) {
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(static_cast<char>('0' + x % 10));
        x /= 10;
    }
    if (neg) {
        s.push_back('-');
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;
    r = min(r, n - r);

    vector<long long> edge(n + 1, 0);
    for (int i = 1; i <= n - 1; ++i) {
        cin >> edge[i];
    }

    vector<long long> weight(n, 0);
    long long max_weight = 0;
    for (int i = 1; i <= n; ++i) {
        weight[i - 1] = edge[i - 1] + edge[i];
        max_weight = max(max_weight, weight[i - 1]);
    }

    long long low = -1;
    long long high = max_weight + 1;
    while (low + 1 < high) {
        long long mid = low + (high - low) / 2;
        PenalizedState state = solve_penalized_nonadjacent(weight, mid);
        if (state.count >= r) {
            low = mid;
        } else {
            high = mid;
        }
    }

    PenalizedState best = solve_penalized_nonadjacent(weight, low);
    __int128 answer = best.value + static_cast<__int128>(low) * r;
    cout << to_string_i128(answer) << '\n';
    return 0;
}
