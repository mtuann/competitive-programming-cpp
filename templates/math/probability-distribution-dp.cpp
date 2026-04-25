// Template: Probability distribution DP on repeated discrete steps
// Signal: one random process with a bounded integer state, repeated independent steps, and the answer is an exact probability or expectation from the final PMF.
// Assumes: each step distribution is fixed, discrete, and finite; the maximum reachable sum/state is manageable.
// Exposes: advance_distribution(cur, step_prob), repeated_distribution(steps, step_prob), probability_range(dist, l, r), and expectation_value(dist).
// Complexity: O(steps * max_state * support) for repeated_distribution, with O(max_state) memory per layer.
// Main trap: simulating random trials instead of propagating exact probability mass.
// Links:
//   Topic: topics/math/probability/README.md
//   Note: practice/ladders/math/probability/diceprobability.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long double> advance_distribution(
    const vector<long double>& cur,
    const vector<long double>& step_prob
) {
    int max_sum = static_cast<int>(cur.size()) - 1;
    int max_step = static_cast<int>(step_prob.size()) - 1;
    vector<long double> nxt(max_sum + max_step + 1, 0.0L);

    for (int sum = 0; sum <= max_sum; ++sum) {
        if (cur[sum] == 0.0L) {
            continue;
        }
        for (int step = 0; step <= max_step; ++step) {
            if (step_prob[step] == 0.0L) {
                continue;
            }
            nxt[sum + step] += cur[sum] * step_prob[step];
        }
    }
    return nxt;
}

vector<long double> repeated_distribution(
    int steps,
    const vector<long double>& step_prob
) {
    vector<long double> dist(1, 1.0L);
    for (int i = 0; i < steps; ++i) {
        dist = advance_distribution(dist, step_prob);
    }
    return dist;
}

long double probability_range(const vector<long double>& dist, int left, int right) {
    left = max(left, 0);
    right = min(right, static_cast<int>(dist.size()) - 1);
    if (left > right) {
        return 0.0L;
    }

    long double ans = 0.0L;
    for (int x = left; x <= right; ++x) {
        ans += dist[x];
    }
    return ans;
}

long double expectation_value(const vector<long double>& dist) {
    long double ans = 0.0L;
    for (int x = 0; x < static_cast<int>(dist.size()); ++x) {
        ans += static_cast<long double>(x) * dist[x];
    }
    return ans;
}

int main() {
    vector<long double> fair_die(7, 0.0L);
    for (int face = 1; face <= 6; ++face) {
        fair_die[face] = 1.0L / 6.0L;
    }

    vector<long double> dist = repeated_distribution(2, fair_die);
    cout.setf(ios::fixed);
    cout.precision(6);
    cout << static_cast<double>(probability_range(dist, 9, 10)) << '\n';
    cout << static_cast<double>(expectation_value(dist)) << '\n';
    return 0;
}
