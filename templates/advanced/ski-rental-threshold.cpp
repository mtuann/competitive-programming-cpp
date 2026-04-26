// Template: Ski-rental threshold policy for the first deterministic online
// competitive-analysis benchmark.
// Signal: one repeated rent-vs-buy decision with no future knowledge, where
// the point is to compare one fixed online threshold rule against offline OPT.
// Assumes: the route is normalized to unit rent cost and integer buy cost B,
// so the rule is "rent B - 1 times, buy on day B if it ever arrives."
// Exposes: SkiRentalOutcome, evaluate_ski_rental(B, d), and
// worst_ratio(B).
// Complexity: O(1) per evaluated horizon.
// Main trap: using the realized horizon d as if the online policy knew it
// beforehand, or buying after day B instead of on day B.
// Links:
//   Topic: topics/advanced/online-algorithms/README.md
//   Note: practice/ladders/advanced/online-algorithms/skirental.md

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

struct SkiRentalOutcome {
    long long online_cost = 0;
    long long offline_cost = 0;
};

SkiRentalOutcome evaluate_ski_rental(long long buy_cost_days, long long trip_days) {
    assert(buy_cost_days > 0);
    assert(trip_days >= 0);

    SkiRentalOutcome outcome;
    outcome.offline_cost = min(trip_days, buy_cost_days);
    outcome.online_cost = (trip_days < buy_cost_days ? trip_days : 2 * buy_cost_days - 1);
    return outcome;
}

pair<long long, long long> worst_ratio(long long buy_cost_days) {
    assert(buy_cost_days > 0);
    long long num = 2 * buy_cost_days - 1;
    long long den = buy_cost_days;
    long long g = gcd(num, den);
    return {num / g, den / g};
}

int main() {
    const long long buy_cost_days = 5;
    const vector<long long> horizons = {1, 4, 5, 10};

    for (long long days : horizons) {
        const SkiRentalOutcome outcome = evaluate_ski_rental(buy_cost_days, days);
        cout << outcome.online_cost << ' ' << outcome.offline_cost << '\n';
    }

    const auto [num, den] = worst_ratio(buy_cost_days);
    cout << num << ' ' << den << '\n';
    return 0;
}
