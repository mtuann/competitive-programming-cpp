// Problem: Point Location Test
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2189
// Topic: geometry, vector orientation
// Idea: classify the sign of cross((b - a), (p - a)).

#include <iostream>

using namespace std;

struct Point {
    long long x;
    long long y;
};

__int128 cross(const Point& a, const Point& b, const Point& p) {
    return static_cast<__int128>(b.x - a.x) * (p.y - a.y) -
           static_cast<__int128>(b.y - a.y) * (p.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Point a, b, p;
        cin >> a.x >> a.y >> b.x >> b.y >> p.x >> p.y;

        __int128 area2 = cross(a, b, p);
        if (area2 > 0) {
            cout << "LEFT\n";
        } else if (area2 < 0) {
            cout << "RIGHT\n";
        } else {
            cout << "TOUCH\n";
        }
    }

    return 0;
}
