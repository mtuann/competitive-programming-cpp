// Template: Minkowski sum of two convex polygons in CCW order.
// Signal: sum two convex polygons, or build a convex polygon for a later
// membership / collision / distance transform.
// Assumes: both polygons are convex, listed counterclockwise, and do not repeat
// the first vertex at the end.
// Exposes: minkowski_sum_convex(P, Q).
// Complexity: O(|P| + |Q|).
// Main trap: using the merge route on non-convex input or forgetting to
// normalize both polygons to the same lowest-vertex convention.
// Links:
//   Topic: topics/geometry/minkowski-sum/README.md
//   Note: practice/ladders/geometry/minkowski-sum/mogohureaidol.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using i128 = __int128_t;

struct Point {
    long long x, y;
};

bool operator==(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}

Point operator+(const Point& a, const Point& b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

i128 cross(const Point& a, const Point& b) {
    return static_cast<i128>(a.x) * b.y - static_cast<i128>(a.y) * b.x;
}

i128 cross(const Point& a, const Point& b, const Point& c) {
    return cross(b - a, c - a);
}

i128 dot(const Point& a, const Point& b) {
    return static_cast<i128>(a.x) * b.x + static_cast<i128>(a.y) * b.y;
}

void rotate_lowest_vertex(vector<Point>& poly) {
    int start = 0;
    for (int i = 1; i < static_cast<int>(poly.size()); ++i) {
        if (poly[i].y < poly[start].y ||
            (poly[i].y == poly[start].y && poly[i].x < poly[start].x)) {
            start = i;
        }
    }
    rotate(poly.begin(), poly.begin() + start, poly.end());
}

vector<Point> compress_convex_polygon(vector<Point> poly) {
    vector<Point> uniq;
    uniq.reserve(poly.size());
    for (const Point& p : poly) {
        if (uniq.empty() || !(uniq.back() == p)) {
            uniq.push_back(p);
        }
    }
    while (uniq.size() > 1 && uniq.front() == uniq.back()) {
        uniq.pop_back();
    }
    if (uniq.size() <= 2) {
        return uniq;
    }

    vector<Point> out;
    out.reserve(uniq.size());
    for (const Point& p : uniq) {
        while (out.size() >= 2 &&
               cross(out[out.size() - 2], out.back(), p) == 0 &&
               dot(out.back() - out[out.size() - 2], p - out.back()) >= 0) {
            out.pop_back();
        }
        out.push_back(p);
    }

    bool changed = true;
    while (changed && out.size() >= 3) {
        changed = false;
        if (cross(out[out.size() - 2], out.back(), out[0]) == 0 &&
            dot(out.back() - out[out.size() - 2], out[0] - out.back()) >= 0) {
            out.pop_back();
            changed = true;
        }
        if (out.size() >= 3 &&
            cross(out.back(), out[0], out[1]) == 0 &&
            dot(out[0] - out.back(), out[1] - out[0]) >= 0) {
            out.erase(out.begin());
            changed = true;
        }
    }
    if (!out.empty()) {
        rotate_lowest_vertex(out);
    }
    return out;
}

vector<Point> minkowski_sum_convex(vector<Point> P, vector<Point> Q) {
    P = compress_convex_polygon(P);
    Q = compress_convex_polygon(Q);
    rotate_lowest_vertex(P);
    rotate_lowest_vertex(Q);

    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);

    vector<Point> result;
    size_t i = 0;
    size_t j = 0;
    while (i < P.size() - 2 || j < Q.size() - 2) {
        result.push_back(P[i] + Q[j]);
        i128 cr = cross(P[i + 1] - P[i], Q[j + 1] - Q[j]);
        if (cr >= 0 && i < P.size() - 2) {
            ++i;
        }
        if (cr <= 0 && j < Q.size() - 2) {
            ++j;
        }
    }
    return compress_convex_polygon(result);
}

int main() {
    vector<Point> square_a = {
        {0, 0},
        {1, 0},
        {1, 1},
        {0, 1},
    };
    vector<Point> square_b = {
        {1, 1},
        {2, 1},
        {2, 2},
        {1, 2},
    };
    vector<Point> sum = minkowski_sum_convex(square_a, square_b);
    cout << sum.size() << '\n';
    for (const Point& p : sum) {
        cout << p.x << ' ' << p.y << '\n';
    }
    return 0;
}
