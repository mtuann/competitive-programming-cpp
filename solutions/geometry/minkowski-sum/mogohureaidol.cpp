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

Point operator*(const Point& a, long long k) {
    return {a.x * k, a.y * k};
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

bool on_segment(const Point& a, const Point& b, const Point& p) {
    if (cross(a, b, p) != 0) {
        return false;
    }
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int point_in_convex(const vector<Point>& poly, const Point& p) {
    int n = static_cast<int>(poly.size());
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return poly[0] == p ? 1 : 0;
    }
    if (n == 2) {
        return on_segment(poly[0], poly[1], p) ? 1 : 0;
    }

    if (on_segment(poly[0], poly[1], p) || on_segment(poly[0], poly[n - 1], p)) {
        return 1;
    }
    if (cross(poly[0], poly[1], p) < 0 || cross(poly[0], poly[n - 1], p) > 0) {
        return 0;
    }

    int left = 1;
    int right = n - 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (cross(poly[0], poly[mid], p) >= 0) {
            left = mid;
        } else {
            right = mid;
        }
    }

    i128 c1 = cross(poly[0], poly[left], p);
    i128 c2 = cross(poly[left], poly[left + 1], p);
    i128 c3 = cross(poly[left + 1], poly[0], p);
    if (c2 == 0 && on_segment(poly[left], poly[left + 1], p)) {
        return 1;
    }
    return (c1 >= 0 && c2 >= 0 && c3 >= 0) ? 2 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<Point>> polys(3);
    for (int t = 0; t < 3; ++t) {
        int n;
        cin >> n;
        polys[t].resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> polys[t][i].x >> polys[t][i].y;
        }
    }

    vector<Point> total = minkowski_sum_convex(polys[0], polys[1]);
    total = minkowski_sum_convex(total, polys[2]);

    int q;
    cin >> q;
    while (q--) {
        Point hill;
        cin >> hill.x >> hill.y;
        Point target = hill * 3LL;
        cout << (point_in_convex(total, target) ? "YES" : "NO") << '\n';
    }
    return 0;
}
