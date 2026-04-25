// Template: Lagrangian relaxation / Aliens trick for exact-K non-adjacent picks
// Signal: choose exactly K positions on a path, no adjacent picks allowed, and
// the direct O(nK) DP is too slow while the penalized path DP is linear.
// Assumes: maximizing score, one integer penalty lambda per pick, and tie-break
// equal penalized values by larger pick count. Also assumes
// 0 <= K <= ceil(n / 2); infeasible K is rejected by an assertion.
// Exposes: solve_penalized_nonadjacent(weights, lambda) and
// maximize_exact_k_nonadjacent(weights, k).
// Complexity: O(n log V), where V is the searched integer penalty range.
// Main trap: tie-breaking count in the wrong direction or forgetting to add
// lambda * k back after the binary search.
// Links:
//   Topic: topics/dp/lagrangian-relaxation/README.md
//   Note: practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md

#include <algorithm>
#include <cassert>
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

__int128 maximize_exact_k_nonadjacent(const vector<long long>& weights, int k) {
    if (k == 0) {
        return 0;
    }
    assert(0 <= k && k <= static_cast<int>((weights.size() + 1) / 2));

    const long long PENALTY_BOUND = 1LL << 60;
    long long low = -PENALTY_BOUND;
    long long high = PENALTY_BOUND;
    while (low + 1 < high) {
        long long mid = low + (high - low) / 2;
        PenalizedState state = solve_penalized_nonadjacent(weights, mid);
        if (state.count >= k) {
            low = mid;
        } else {
            high = mid;
        }
    }

    PenalizedState state = solve_penalized_nonadjacent(weights, low);
    return state.value + static_cast<__int128>(low) * k;
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
        int digit = static_cast<int>(x % 10);
        s.push_back(static_cast<char>('0' + digit));
        x /= 10;
    }
    if (neg) {
        s.push_back('-');
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    vector<long long> weights = {3, 4, 5, 5, 6, 5};
    cout << to_string_i128(maximize_exact_k_nonadjacent(weights, 2)) << '\n';  // 11
    return 0;
}
