// Template: meet-in-the-middle subset-sum counting.
// Signal: subset-like exact search with n around 35..45 where one half-summary
// merge is cheaper than exploring all 2^n states directly.
// Assumes: the state factors cleanly into two halves and counting duplicate
// half-sums is part of correctness.
// Exposes: count_subsets_with_sum(a, target) for one array of non-negative or
// arbitrary additive values that fit in long long.
// Complexity: O(2^(n/2) log 2^(n/2)) time and O(2^(n/2)) memory.
// Main trap: forgetting multiplicity when many half-sums are equal and the
// statement counts subsets rather than distinct sums.
// Links:
//   Topic: topics/advanced/meet-in-the-middle/README.md
//   Note: practice/ladders/advanced/meet-in-the-middle/meetinthemiddle.md

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

long long count_subsets_with_sum(const vector<long long>& a, long long target) {
    int mid = static_cast<int>(a.size()) / 2;
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
    return answer;
}

int main() {
    vector<long long> a = {1, 2, 3, 2};
    cout << count_subsets_with_sum(a, 5) << '\n';
    return 0;  // 3
}
