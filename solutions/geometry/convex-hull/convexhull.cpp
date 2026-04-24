// Problem: Convex Hull
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2195
// Topic: geometry, convex hull
// Idea: Andrew monotone chain. Pop only on strict clockwise turns so every
// boundary-collinear point stays on the hull, as required by the judge.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x;
    long long y;

    bool operator<(const Point& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

__int128 cross(const Point& a, const Point& b, const Point& c) {
    return static_cast<__int128>(b.x - a.x) * (c.y - a.y) -
           static_cast<__int128>(b.y - a.y) * (c.x - a.x);
}

vector<Point> convex_hull_with_boundary(vector<Point> points) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    if (points.size() <= 2) {
        return points;
    }

    vector<Point> lower;
    for (const Point& p : points) {
        while (lower.size() >= 2 &&
               cross(lower[lower.size() - 2], lower[lower.size() - 1], p) < 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    vector<Point> upper;
    for (int i = static_cast<int>(points.size()) - 1; i >= 0; --i) {
        const Point& p = points[i];
        while (upper.size() >= 2 &&
               cross(upper[upper.size() - 2], upper[upper.size() - 1], p) < 0) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (Point& p : points) {
        cin >> p.x >> p.y;
    }

    vector<Point> hull = convex_hull_with_boundary(points);
    cout << hull.size() << '\n';
    for (const Point& p : hull) {
        cout << p.x << ' ' << p.y << '\n';
    }

    return 0;
}
