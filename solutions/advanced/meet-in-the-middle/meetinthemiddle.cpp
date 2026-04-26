// Problem: Meet in the Middle
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1628
// Topic: meet-in-the-middle, subset sums, exact counting
// Idea: enumerate all left/right half subset sums, sort one side, and count
// complement sums with equal_range.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> enumerate_subset_sums(const vector<long long>& a) {
    vector<long long> sums = {0};
    sums.reserve(1ULL << a.size());
    for (long long x : a) {
        int current = static_cast<int>(sums.size());
        for (int i = 0; i < current; ++i) {
            sums.push_back(sums[i] + x);
        }
    }
    return sums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;

    vector<long long> a(n);
    for (long long& x : a) {
        cin >> x;
    }

    int mid = n / 2;
    vector<long long> left_half(a.begin(), a.begin() + mid);
    vector<long long> right_half(a.begin() + mid, a.end());

    vector<long long> left = enumerate_subset_sums(left_half);
    vector<long long> right = enumerate_subset_sums(right_half);
    sort(right.begin(), right.end());

    long long answer = 0;
    for (long long left_sum : left) {
        auto range = equal_range(right.begin(), right.end(), target - left_sum);
        answer += static_cast<long long>(range.second - range.first);
    }

    cout << answer << '\n';
    return 0;
}
