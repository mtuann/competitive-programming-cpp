// Problem: Factory Machines
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1620
// Topic: binary search on answer, monotone feasibility
// Idea: binary-search the minimum time x such that sum(x / k[i]) >= target.
// Cap the running sum at target to avoid unnecessary overflow.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;

    vector<long long> machine_time(n);
    long long fastest = 0;
    for (int i = 0; i < n; ++i) {
        cin >> machine_time[i];
        if (i == 0 || machine_time[i] < fastest) {
            fastest = machine_time[i];
        }
    }

    auto can_make = [&](long long time_limit) {
        long long produced = 0;
        for (long long time_per_item : machine_time) {
            produced += time_limit / time_per_item;
            if (produced >= target) {
                return true;
            }
        }
        return false;
    };

    long long lo = 0;
    long long hi = fastest * target;

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (can_make(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << '\n';
    return 0;
}
