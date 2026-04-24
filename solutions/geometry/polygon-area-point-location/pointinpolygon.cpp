// Problem: Point in Polygon
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2192
// Topic: point in polygon, ray casting, boundary handling
// Idea: first test whether the query point lies on any polygon edge. Otherwise
// use parity of horizontal ray crossings with a half-open y-interval rule so
// polygon vertices are never double-counted.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using i128 = __int128_t;

struct Point {
    long long x;
    long long y;
};

Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

i128 cross(const Point& a, const Point& b) {
    return static_cast<i128>(a.x) * b.y - static_cast<i128>(a.y) * b.x;
}

i128 cross(const Point& a, const Point& b, const Point& c) {
    return cross(b - a, c - a);
}

bool on_segment(const Point& a, const Point& b, const Point& p) {
    if (cross(a, b, p) != 0) {
        return false;
    }
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int classify_point(const vector<Point>& poly, const Point& p) {
    bool inside = false;
    int n = static_cast<int>(poly.size());
    for (int i = 0; i < n; ++i) {
        const Point& a = poly[i];
        const Point& b = poly[(i + 1 == n) ? 0 : i + 1];

        if (on_segment(a, b, p)) {
            return 1;
        }

        bool below = a.y < p.y;
        bool above = b.y < p.y;
        if (below == above) {
            continue;
        }

        i128 turn = cross(a, b, p);
        if ((b.y > a.y && turn > 0) || (b.y < a.y && turn < 0)) {
            inside = !inside;
        }
    }
    return inside ? 2 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> poly(n);
    for (Point& p : poly) {
        cin >> p.x >> p.y;
    }

    while (m--) {
        Point q;
        cin >> q.x >> q.y;
        int state = classify_point(poly, q);
        if (state == 1) {
            cout << "BOUNDARY\n";
        } else if (state == 2) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }

    return 0;
}
