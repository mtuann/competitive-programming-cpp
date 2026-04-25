// Template: closest pair sweep
// Signal: one static planar point set, need the global nearest Euclidean pair in O(n log n).
// Assumes: 2D Euclidean metric, static batch input, and one active strip ordered by y.
// Exposes: Point, squared_distance(a, b), and closest_pair_sq(points).
// Complexity: O(n log n) after sorting.
// Main trap: mixing squared and unsquared distance in the strip pruning logic.
// Links:
//   Topic: topics/geometry/nearest-pair/README.md
//   Note: practice/ladders/geometry/nearest-pair/closestpair.md

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

struct Point {
    long double x, y;
    int id;
};

long double squared_distance(const Point &a, const Point &b) {
    long double dx = a.x - b.x;
    long double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

long double closest_pair_sq(vector<Point> points) {
    if (points.size() < 2) return 0.0L;

    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        if (a.x != b.x) return a.x < b.x;
        if (a.y != b.y) return a.y < b.y;
        return a.id < b.id;
    });

    for (int i = 1; i < static_cast<int>(points.size()); ++i) {
        if (points[i - 1].x == points[i].x && points[i - 1].y == points[i].y) {
            return 0.0L;
        }
    }

    set<tuple<long double, long double, int>> active;
    long double best2 = numeric_limits<long double>::infinity();
    int left = 0;

    for (int i = 0; i < static_cast<int>(points.size()); ++i) {
        const Point &current = points[i];

        while (left < i) {
            long double dx = current.x - points[left].x;
            if (dx * dx > best2) {
                active.erase({points[left].y, points[left].x, points[left].id});
                ++left;
            } else {
                break;
            }
        }

        long double limit = sqrtl(best2);
        auto it = active.lower_bound({
            current.y - limit,
            numeric_limits<long double>::lowest(),
            numeric_limits<int>::lowest()
        });

        while (it != active.end() && get<0>(*it) <= current.y + limit) {
            Point candidate{get<1>(*it), get<0>(*it), get<2>(*it)};
            best2 = min(best2, squared_distance(current, candidate));
            ++it;
        }

        active.insert({current.y, current.x, current.id});
    }

    return best2;
}

int main() {
    vector<Point> points = {
        {0, 0, 0},
        {1, 0, 1},
        {3, 4, 2}
    };
    cout << fixed << setprecision(10) << closest_pair_sq(points) << '\n';
    return 0;
}
