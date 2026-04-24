#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

struct Point {
    long long x;
    long long y;
    int id;
};

long long squared_distance(const Point &a, const Point &b) {
    __int128 dx = static_cast<__int128>(a.x) - b.x;
    __int128 dy = static_cast<__int128>(a.y) - b.y;
    return static_cast<long long>(dx * dx + dy * dy);
}

long long floor_sqrt(long long value) {
    long long root = static_cast<long long>(sqrtl(static_cast<long double>(value)));
    while (static_cast<__int128>(root + 1) * (root + 1) <= value) {
        ++root;
    }
    while (static_cast<__int128>(root) * root > value) {
        --root;
    }
    return root;
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

    if (n < 2) {
        cout << 0 << '\n';
        return 0;
    }

    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        if (a.y != b.y) {
            return a.y < b.y;
        }
        return a.id < b.id;
    });

    long long best = squared_distance(points[0], points[1]);
    set<tuple<long long, long long, int>> active;
    int left = 0;

    for (int i = 0; i < n; ++i) {
        const Point &current = points[i];

        while (left < i) {
            long long dx = current.x - points[left].x;
            if (static_cast<__int128>(dx) * dx > best) {
                active.erase({points[left].y, points[left].x, points[left].id});
                ++left;
            } else {
                break;
            }
        }

        long long limit = floor_sqrt(best);
        auto it = active.lower_bound({current.y - limit, numeric_limits<long long>::lowest(), numeric_limits<int>::lowest()});
        while (it != active.end() && get<0>(*it) <= current.y + limit) {
            Point candidate{get<1>(*it), get<0>(*it), get<2>(*it)};
            best = min(best, squared_distance(current, candidate));
            ++it;
        }

        active.insert({current.y, current.x, current.id});
    }

    cout << best << '\n';
    return 0;
}
