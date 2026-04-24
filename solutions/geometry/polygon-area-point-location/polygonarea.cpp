// Problem: Polygon Area
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2191
// Topic: shoelace formula, signed area, polygon geometry
// Idea: sum cross(p[i], p[i+1]) around the polygon, including the closing
// edge. The absolute value of that signed sum is exactly twice the polygon area.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using i128 = __int128_t;

struct Point {
    long long x;
    long long y;
};

string to_string_i128(i128 value) {
    if (value == 0) {
        return "0";
    }
    bool negative = value < 0;
    if (negative) {
        value = -value;
    }
    string digits;
    while (value > 0) {
        int digit = static_cast<int>(value % 10);
        digits.push_back(static_cast<char>('0' + digit));
        value /= 10;
    }
    if (negative) {
        digits.push_back('-');
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> poly(n);
    for (Point& p : poly) {
        cin >> p.x >> p.y;
    }

    i128 area2 = 0;
    for (int i = 0; i < n; ++i) {
        const Point& a = poly[i];
        const Point& b = poly[(i + 1 == n) ? 0 : i + 1];
        area2 += static_cast<i128>(a.x) * b.y - static_cast<i128>(a.y) * b.x;
    }

    if (area2 < 0) {
        area2 = -area2;
    }
    cout << to_string_i128(area2) << '\n';
    return 0;
}
