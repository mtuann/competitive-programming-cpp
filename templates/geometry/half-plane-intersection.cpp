// Template: half-plane intersection
// Signal: many directed line constraints whose common feasible region is a bounded convex polygon.
// Assumes: each half-plane keeps the left side of its directed boundary line; this starter is for bounded polygon output.
// Exposes: Point, HalfPlane, line_intersection(a, b), polygon_area(poly), and halfplane_intersection(hps).
// Complexity: O(n log n) for angle sorting plus linear deque processing.
// Main trap: wrong side convention, wrong tie-break among equal directions, or using it on an unbounded instance without a bounding-box policy.
// Links:
//   Topic: topics/geometry/half-plane-intersection/README.md
//   Note: practice/ladders/geometry/half-plane-intersection/bigbrother.md

#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

static constexpr long double EPS = 1e-12L;

struct Point {
    long double x, y;
    Point operator+(const Point &other) const { return {x + other.x, y + other.y}; }
    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
    Point operator*(long double k) const { return {x * k, y * k}; }
};

long double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

struct HalfPlane {
    Point p;
    Point pq;
    long double angle;

    HalfPlane() = default;
    HalfPlane(Point a, Point b) : p(a), pq(b - a), angle(atan2l(pq.y, pq.x)) {}

    bool outside(const Point &r) const {
        return cross(pq, r - p) < -EPS;
    }
};

bool parallel(const HalfPlane &a, const HalfPlane &b) {
    return fabsl(cross(a.pq, b.pq)) <= EPS;
}

bool same_direction(const HalfPlane &a, const HalfPlane &b) {
    return parallel(a, b) && dot(a.pq, b.pq) > 0;
}

bool halfplane_cmp(const HalfPlane &a, const HalfPlane &b) {
    if (!same_direction(a, b)) return a.angle < b.angle;
    return cross(a.pq, b.p - a.p) < 0;
}

Point line_intersection(const HalfPlane &a, const HalfPlane &b) {
    long double t = cross(b.p - a.p, b.pq) / cross(a.pq, b.pq);
    return a.p + a.pq * t;
}

long double polygon_area(const vector<Point> &poly) {
    if (poly.size() < 3) return 0.0L;
    long double twice = 0;
    for (int i = 0; i < static_cast<int>(poly.size()); ++i) {
        twice += cross(poly[i], poly[(i + 1) % static_cast<int>(poly.size())]);
    }
    return fabsl(twice) / 2.0L;
}

vector<Point> halfplane_intersection(vector<HalfPlane> hps) {
    sort(hps.begin(), hps.end(), halfplane_cmp);
    vector<HalfPlane> filtered;
    for (const HalfPlane &hp : hps) {
        if (!filtered.empty() && same_direction(filtered.back(), hp)) continue;
        filtered.push_back(hp);
    }
    hps.swap(filtered);

    deque<HalfPlane> dq;
    deque<Point> pts;

    for (const HalfPlane &hp : hps) {
        while (dq.size() > 1 && hp.outside(pts.back())) {
            dq.pop_back();
            pts.pop_back();
        }
        while (dq.size() > 1 && hp.outside(pts.front())) {
            dq.pop_front();
            pts.pop_front();
        }
        if (!dq.empty() && parallel(dq.back(), hp)) {
            return {};
        }
        if (!dq.empty()) pts.push_back(line_intersection(dq.back(), hp));
        dq.push_back(hp);
    }

    while (dq.size() > 2 && dq.front().outside(pts.back())) {
        dq.pop_back();
        pts.pop_back();
    }
    while (dq.size() > 2 && dq.back().outside(pts.front())) {
        dq.pop_front();
        pts.pop_front();
    }

    if (dq.size() < 3 || parallel(dq.front(), dq.back())) return {};
    pts.push_back(line_intersection(dq.back(), dq.front()));
    return vector<Point>(pts.begin(), pts.end());
}

int main() {
    vector<HalfPlane> hps = {
        HalfPlane({0, 0}, {1, 0}),
        HalfPlane({1, 0}, {1, 1}),
        HalfPlane({1, 1}, {0, 1}),
        HalfPlane({0, 1}, {0, 0}),
    };
    vector<Point> poly = halfplane_intersection(hps);
    cout << poly.size() << '\n';
    cout << fixed << setprecision(10) << polygon_area(poly) << '\n';
    return 0;
}
