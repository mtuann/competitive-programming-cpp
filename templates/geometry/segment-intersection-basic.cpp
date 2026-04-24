// Use when: checking whether two closed segments intersect, including endpoints/overlap.
// Invariant: coordinates are integers; cross products use __int128 for long long safety.
// Complexity: O(1).

#include <algorithm>

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

int sgn(i128 x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

bool segments_intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    int ab_c = sgn(cross(a, b, c));
    int ab_d = sgn(cross(a, b, d));
    int cd_a = sgn(cross(c, d, a));
    int cd_b = sgn(cross(c, d, b));

    if (ab_c == 0 && on_segment(a, b, c)) return true;
    if (ab_d == 0 && on_segment(a, b, d)) return true;
    if (cd_a == 0 && on_segment(c, d, a)) return true;
    if (cd_b == 0 && on_segment(c, d, b)) return true;

    return ab_c * ab_d < 0 && cd_a * cd_b < 0;
}
