// Problem: Common Divisors
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1081
// Topic: gcd, divisor frequency, counting multiples
// Idea: a value d can be the gcd of some pair iff at least two array elements
// are divisible by d. Count frequencies, scan candidate divisors downward, and
// find the first d with at least two multiples in the array.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> values(n);
    int max_value = 0;
    for (int& x : values) {
        cin >> x;
        if (x > max_value) {
            max_value = x;
        }
    }

    vector<int> freq(max_value + 1, 0);
    for (int x : values) {
        ++freq[x];
    }

    for (int d = max_value; d >= 1; --d) {
        int count = 0;
        for (int multiple = d; multiple <= max_value; multiple += d) {
            count += freq[multiple];
            if (count >= 2) {
                cout << d << '\n';
                return 0;
            }
        }
    }

    return 0;
}
