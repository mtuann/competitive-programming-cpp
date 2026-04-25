#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <set>

using namespace std;

struct LineContainerMax {
    struct Line {
        mutable long long k = 0;
        mutable long long m = 0;
        mutable long long p = 0;

        bool operator<(const Line& other) const {
            return k < other.k;
        }

        bool operator<(long long x) const {
            return p < x;
        }
    };

    static constexpr long long INF = numeric_limits<long long>::max();
    static constexpr long long NEG_INF = numeric_limits<long long>::lowest();
    multiset<Line, less<>> hull;

    static long long floor_div(long long a, long long b) {
        long long q = a / b;
        long long r = a % b;
        if (r != 0 && ((r > 0) != (b > 0))) {
            --q;
        }
        return q;
    }

    using iterator = multiset<Line, less<>>::iterator;

    bool isect(iterator x, iterator y) {
        if (y == hull.end()) {
            x->p = INF;
            return false;
        }
        if (x->k == y->k) {
            x->p = (x->m > y->m ? INF : NEG_INF);
        } else {
            x->p = floor_div(y->m - x->m, x->k - y->k);
        }
        return x->p >= y->p;
    }

    void add_line(long long k, long long m) {
        auto z = hull.insert(Line{k, m, 0});
        auto y = z;
        ++z;
        auto x = y;

        while (isect(y, z)) {
            z = hull.erase(z);
        }
        if (x != hull.begin()) {
            --x;
            if (isect(x, y)) {
                isect(x, y = hull.erase(y));
            }
        }
        while ((y = x) != hull.begin()) {
            --x;
            if (x->p < y->p) {
                break;
            }
            isect(x, hull.erase(y));
        }
    }

    long long query(long long x) const {
        auto line = *hull.lower_bound(x);
        return static_cast<long long>(static_cast<__int128>(line.k) * x + line.m);
    }
};

struct LineContainerMin {
    LineContainerMax hull;

    void add_line(long long m, long long b) {
        hull.add_line(-m, -b);
    }

    long long query(long long x) const {
        return -hull.query(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    LineContainerMin hull;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        hull.add_line(a, b);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            long long a, b;
            cin >> a >> b;
            hull.add_line(a, b);
        } else {
            long long x;
            cin >> x;
            cout << hull.query(x) << '\n';
        }
    }
    return 0;
}
