// Template: integer geometry primitives with __int128-safe cross product.

#include <iostream>

using namespace std;

struct Point {
    long long x, y;
};

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

__int128 cross(const Point &a, const Point &b) {
    return static_cast<__int128>(a.x) * b.y - static_cast<__int128>(a.y) * b.x;
}

__int128 cross(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a);
}

int orientation(const Point &a, const Point &b, const Point &c) {
    __int128 cr = cross(a, b, c);
    if (cr > 0) return 1;
    if (cr < 0) return -1;
    return 0;
}

int main() {
    Point a{0, 0}, b{1, 0}, c{1, 1};
    cout << orientation(a, b, c) << '\n';
    return 0;
}
