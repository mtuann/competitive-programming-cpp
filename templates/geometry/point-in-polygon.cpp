// Use when: classifying a point against a simple polygon (outside/boundary/inside).
// Invariant: polygon vertices are in boundary order; returns 0 = outside, 1 = boundary, 2 = inside.
// Complexity: O(n).

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using i128 = __int128_t;

struct Point {
    long long x, y;
};

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

i128 cross(const Point &a, const Point &b) {
    return static_cast<i128>(a.x) * b.y - static_cast<i128>(a.y) * b.x;
}

i128 cross(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a);
}

bool on_segment(const Point &a, const Point &b, const Point &p) {
    if (cross(a, b, p) != 0) return false;
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int point_in_polygon(const vector<Point> &poly, const Point &p) {
    bool inside = false;
    int n = static_cast<int>(poly.size());
    for (int i = 0; i < n; ++i) {
        const Point &a = poly[i];
        const Point &b = poly[(i + 1 == n ? 0 : i + 1)];
        if (on_segment(a, b, p)) return 1;
        bool below = a.y < p.y;
        bool above = b.y < p.y;
        if (below != above) {
            i128 cr = cross(a, b, p);
            if ((b.y > a.y && cr > 0) || (b.y < a.y && cr < 0)) {
                inside = !inside;
            }
        }
    }
    return inside ? 2 : 0;
}

int main() {
    vector<Point> poly = {
        {0, 0},
        {4, 0},
        {4, 4},
        {0, 4}
    };
    cout << point_in_polygon(poly, {2, 2}) << '\n';
    cout << point_in_polygon(poly, {4, 2}) << '\n';
    cout << point_in_polygon(poly, {5, 2}) << '\n';
    return 0;
}
