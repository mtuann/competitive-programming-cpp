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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].id = i;
    }

    cout << fixed << setprecision(12) << sqrtl(closest_pair_sq(points)) << '\n';
    return 0;
}
