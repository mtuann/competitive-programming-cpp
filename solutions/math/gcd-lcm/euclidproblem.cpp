// Problem: Euclid Problem
// Judge: UVa
// Source URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1045
// Topic: extended gcd, Bezout coefficients
// Idea: run extended Euclid on each pair (a, b) and print one witness x, y
// such that ax + by = gcd(a, b).

#include <iostream>

using namespace std;

long long ext_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1 = 0, y1 = 0;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    while (cin >> a >> b) {
        long long x = 0, y = 0;
        long long g = ext_gcd(a, b, x, y);
        cout << x << ' ' << y << ' ' << g << '\n';
    }
    return 0;
}
