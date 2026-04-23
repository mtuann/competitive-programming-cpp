// Problem: VOTELPH - Bà Nà
// Judge: VN SPOJ / VNOI
// Source URL: https://vn.spoj.com/problems/VOTELPH/
// Mirror URL: https://oj.vnoi.info/problem/votelph
// Topic: geometry, offline queries, interval maximum
// Idea: for one parabola, the maximum on [L, R] is at clip(vertex, [L, R]).
// Split all parabolas by whether their vertex lies left of L, inside [L, R], or
// right of R. Then:
// - left part = max value at x = L among parabolas with vertex <= L
// - right part = max value at x = R among parabolas with vertex >= R
// - middle part = max peak among vertices in [L, R]
// Because all query endpoints have at most 2 decimals, endpoint values are only
// needed on the fixed 0.01 grid [-1000.00, 1000.00], so we can preprocess both
// endpoint arrays exactly with integer finite differences.

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

namespace {

constexpr int MIN_X = -100000;   // -1000.00 scaled by 100
constexpr int MAX_X = 100000;    //  1000.00 scaled by 100
constexpr int GRID = MAX_X - MIN_X + 1;
constexpr long long NEG = numeric_limits<long long>::min() / 4;

struct Parabola {
    int a100;
    int b100;
    int c100;
    long double vertex_x = 0.0L;
    long double peak_scaled = 0.0L;  // actual value * 1e6
};

struct Query {
    int l100;
    int r100;
};

int parse_scaled_100(const string& s) {
    int sign = 1;
    int i = 0;
    if (s[i] == '-') {
        sign = -1;
        ++i;
    } else if (s[i] == '+') {
        ++i;
    }

    int whole = 0;
    while (i < static_cast<int>(s.size()) && s[i] != '.') {
        whole = whole * 10 + (s[i] - '0');
        ++i;
    }

    int frac = 0;
    int digits = 0;
    if (i < static_cast<int>(s.size()) && s[i] == '.') {
        ++i;
        while (i < static_cast<int>(s.size()) && digits < 2) {
            frac = frac * 10 + (s[i] - '0');
            ++i;
            ++digits;
        }
    }
    while (digits < 2) {
        frac *= 10;
        ++digits;
    }

    return sign * (whole * 100 + frac);
}

long long floor_div(long long p, long long q) {
    long long d = p / q;
    long long r = p % q;
    if (r != 0 && ((r > 0) != (q > 0))) {
        --d;
    }
    return d;
}

long long ceil_div(long long p, long long q) {
    long long d = p / q;
    long long r = p % q;
    if (r != 0 && ((r > 0) == (q > 0))) {
        ++d;
    }
    return d;
}

inline int to_index(int x100) {
    return x100 - MIN_X;
}

inline long long value_scaled_1e6(const Parabola& p, int x100) {
    return 1LL * p.a100 * x100 * x100 +
           100LL * p.b100 * x100 +
           10000LL * p.c100;
}

struct RangeMax {
    vector<vector<long double>> st;
    vector<int> lg;

    void build(const vector<long double>& values) {
        const int n = static_cast<int>(values.size());
        if (n == 0) return;
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i / 2] + 1;
        }

        st.assign(lg[n] + 1, vector<long double>(n));
        st[0] = values;
        for (int k = 1; k <= lg[n]; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    long double query(int left, int right) const {
        if (left > right) return -1e100L;
        int k = lg[right - left + 1];
        return max(st[k][left], st[k][right - (1 << k) + 1]);
    }
};

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Parabola> parabolas(n);
    for (int i = 0; i < n; ++i) {
        string sa, sb, sc;
        cin >> sa >> sb >> sc;
        parabolas[i].a100 = parse_scaled_100(sa);
        parabolas[i].b100 = parse_scaled_100(sb);
        parabolas[i].c100 = parse_scaled_100(sc);

        const long double a = static_cast<long double>(parabolas[i].a100) / 100.0L;
        const long double b = static_cast<long double>(parabolas[i].b100) / 100.0L;
        parabolas[i].vertex_x = -b / (2.0L * a);
        parabolas[i].peak_scaled =
            10000.0L * parabolas[i].c100 -
            2500.0L * static_cast<long double>(parabolas[i].b100) *
                static_cast<long double>(parabolas[i].b100) /
                static_cast<long double>(parabolas[i].a100);
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        string sl, sr;
        cin >> sl >> sr;
        queries[i].l100 = parse_scaled_100(sl);
        queries[i].r100 = parse_scaled_100(sr);
    }

    vector<long long> left_best(GRID, NEG), right_best(GRID, NEG);

    for (const Parabola& p : parabolas) {
        const long long num = -50LL * p.b100;
        const long long den = p.a100;  // negative

        const int first_x = static_cast<int>(max<long long>(MIN_X, ceil_div(num, den)));
        if (first_x <= MAX_X) {
            long long value = value_scaled_1e6(p, first_x);
            long long delta = 1LL * p.a100 * (2LL * first_x + 1LL) + 100LL * p.b100;
            const long long second = 2LL * p.a100;
            for (int x = first_x; x <= MAX_X; ++x) {
                long long& slot = left_best[to_index(x)];
                if (value > slot) slot = value;
                value += delta;
                delta += second;
            }
        }

        const int last_x = static_cast<int>(min<long long>(MAX_X, floor_div(num, den)));
        if (last_x >= MIN_X) {
            long long value = value_scaled_1e6(p, last_x);
            long long delta = 1LL * p.a100 * (-2LL * last_x + 1LL) - 100LL * p.b100;
            const long long second = 2LL * p.a100;
            for (int x = last_x; x >= MIN_X; --x) {
                long long& slot = right_best[to_index(x)];
                if (value > slot) slot = value;
                value += delta;
                delta += second;
            }
        }
    }

    vector<pair<long double, long double>> peaks;
    peaks.reserve(n);
    for (const Parabola& p : parabolas) {
        peaks.push_back({p.vertex_x, p.peak_scaled});
    }
    sort(peaks.begin(), peaks.end());

    vector<long double> vertex_xs, peak_values;
    vertex_xs.reserve(n);
    peak_values.reserve(n);
    for (const auto& item : peaks) {
        vertex_xs.push_back(item.first);
        peak_values.push_back(item.second);
    }

    RangeMax rmq;
    rmq.build(peak_values);

    cout << fixed << setprecision(10);
    for (const Query& query : queries) {
        long double best = -1e100L;

        const long long left_value = left_best[to_index(query.l100)];
        if (left_value != NEG) {
            best = max(best, static_cast<long double>(left_value));
        }

        const long long right_value = right_best[to_index(query.r100)];
        if (right_value != NEG) {
            best = max(best, static_cast<long double>(right_value));
        }

        const long double l = static_cast<long double>(query.l100) / 100.0L;
        const long double r = static_cast<long double>(query.r100) / 100.0L;
        const int left_idx = static_cast<int>(
            lower_bound(vertex_xs.begin(), vertex_xs.end(), l) - vertex_xs.begin()
        );
        const int right_idx = static_cast<int>(
            upper_bound(vertex_xs.begin(), vertex_xs.end(), r) - vertex_xs.begin()
        ) - 1;
        if (left_idx <= right_idx) {
            best = max(best, rmq.query(left_idx, right_idx));
        }

        cout << static_cast<double>(best / 1000000.0L + 1.0L) << '\n';
    }

    return 0;
}
