// Problem: Line Segment Intersection
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2190
// Topic: geometry, segment intersection
// Idea: use orientation signs for the general case and inclusive on-segment
// checks for endpoint touching / collinear overlap.

#include <algorithm>
#include <iostream>

using namespace std;

struct Point {
    long long x;
    long long y;
};

__int128 cross(const Point& a, const Point& b, const Point& c) {
    return static_cast<__int128>(b.x - a.x) * (c.y - a.y) -
           static_cast<__int128>(b.y - a.y) * (c.x - a.x);
}

int sign(__int128 value) {
    if (value > 0) {
        return 1;
    }
    if (value < 0) {
        return -1;
    }
    return 0;
}

bool on_segment(const Point& a, const Point& b, const Point& p) {
    if (sign(cross(a, b, p)) != 0) {
        return false;
    }
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool segments_intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    int o1 = sign(cross(a, b, c));
    int o2 = sign(cross(a, b, d));
    int o3 = sign(cross(c, d, a));
    int o4 = sign(cross(c, d, b));

    if (o1 == 0 && on_segment(a, b, c)) {
        return true;
    }
    if (o2 == 0 && on_segment(a, b, d)) {
        return true;
    }
    if (o3 == 0 && on_segment(c, d, a)) {
        return true;
    }
    if (o4 == 0 && on_segment(c, d, b)) {
        return true;
    }

    return o1 * o2 < 0 && o3 * o4 < 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Point a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y;
        cin >> c.x >> c.y >> d.x >> d.y;
        cout << (segments_intersect(a, b, c, d) ? "YES" : "NO") << '\n';
    }

    return 0;
}
