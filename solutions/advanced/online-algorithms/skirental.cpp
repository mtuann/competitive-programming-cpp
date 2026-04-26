#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>

using namespace std;

struct SkiRentalOutcome {
    long long online_cost = 0;
    long long offline_cost = 0;
};

SkiRentalOutcome evaluate_ski_rental(long long buy_cost_days, long long trip_days) {
    SkiRentalOutcome outcome;
    outcome.offline_cost = min(trip_days, buy_cost_days);
    outcome.online_cost = (trip_days < buy_cost_days ? trip_days : 2 * buy_cost_days - 1);
    return outcome;
}

pair<long long, long long> worst_ratio(long long buy_cost_days) {
    long long num = 2 * buy_cost_days - 1;
    long long den = buy_cost_days;
    long long g = gcd(num, den);
    return {num / g, den / g};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long buy_cost_days;
    int q;
    if (!(cin >> buy_cost_days >> q)) {
        return 0;
    }

    for (int i = 0; i < q; ++i) {
        long long trip_days;
        cin >> trip_days;
        const SkiRentalOutcome outcome = evaluate_ski_rental(buy_cost_days, trip_days);
        cout << outcome.online_cost << ' ' << outcome.offline_cost << '\n';
    }

    const auto [num, den] = worst_ratio(buy_cost_days);
    cout << num << ' ' << den << '\n';
    return 0;
}
