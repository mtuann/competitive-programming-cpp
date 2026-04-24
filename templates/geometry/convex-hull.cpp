// Template: convex hull
// Signal: static planar point set, need the corner-only convex hull.
// Assumes: this monotone-chain variant discards collinear boundary points on edges.
// Exposes: Point, cross(a, b), and convex_hull(pts).
// Complexity: O(n log n) for sorting plus linear hull construction.
// Main trap: using it in a keep-all-boundary-points task without changing the <= 0 pop rule.
// Links:
//   Topic: topics/geometry/convex-hull/README.md
//   Note: practice/ladders/geometry/convex-hull/convexhull.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

__int128 cross(const Point &a, const Point &b) {
    return static_cast<__int128>(a.x) * b.y - static_cast<__int128>(a.y) * b.x;
}

vector<Point> convex_hull(vector<Point> pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end(), [](const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
    }), pts.end());
    if (pts.size() <= 1) return pts;
    vector<Point> lower, upper;
    for (const Point &p : pts) {
        while (lower.size() >= 2 &&
               cross(lower.back() - lower[lower.size() - 2], p - lower.back()) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }
    for (int i = static_cast<int>(pts.size()) - 1; i >= 0; --i) {
        const Point &p = pts[i];
        while (upper.size() >= 2 &&
               cross(upper.back() - upper[upper.size() - 2], p - upper.back()) <= 0) {
            upper.pop_back();
        }
        upper.push_back(p);
    }
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    vector<Point> hull = convex_hull({{0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0}});
    cout << hull.size() << '\n';
    return 0;
}
