// Template: shoelace area
// Signal: compute polygon area from ordered boundary vertices.
// Assumes: vertices are in boundary order and the polygon is simple.
// Exposes: twice_signed_area(poly) and print_area_exact(area2).
// Complexity: O(n).
// Main trap: feeding vertices in arbitrary order and blaming the formula for the wrong area.
// Links:
//   Topic: topics/geometry/polygon-area-point-location/README.md
//   Note: practice/ladders/geometry/polygon-area-point-location/polygonarea.md

#include <algorithm>
#include <iostream>
#include <string>
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

static void print_i128(i128 x) {
    if (x == 0) {
        cout << '0';
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void print_area_exact(i128 area2) {
    if (area2 < 0) area2 = -area2;
    print_i128(area2 / 2);
    cout << (area2 % 2 == 0 ? ".0" : ".5");
}

int main() {
    vector<Point> poly = {
        {0, 0},
        {4, 0},
        {4, 4},
        {0, 4}
    };
    print_area_exact(twice_signed_area(poly));
    cout << '\n';
    return 0;
}
