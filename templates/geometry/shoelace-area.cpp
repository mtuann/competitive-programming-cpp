// Use when: computing the area of a simple polygon from ordered vertices.
// Invariant: vertices are in boundary order; twice_signed_area() is positive for CCW order.
// Complexity: O(n).

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

using i128 = __int128_t;

struct Point {
    long long x, y;
};

i128 twice_signed_area(const vector<Point> &poly) {
    int n = static_cast<int>(poly.size());
    i128 area2 = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1 == n ? 0 : i + 1);
        area2 += static_cast<i128>(poly[i].x) * poly[j].y -
                 static_cast<i128>(poly[i].y) * poly[j].x;
    }
    return area2;
}

long double polygon_area(const vector<Point> &poly) {
    i128 area2 = twice_signed_area(poly);
    if (area2 < 0) area2 = -area2;
    return static_cast<long double>(area2) / 2.0L;
}

int main() {
    vector<Point> poly = {
        {0, 0},
        {4, 0},
        {4, 4},
        {0, 4}
    };
    cout << fixed << setprecision(1) << polygon_area(poly) << '\n';
    return 0;
}
