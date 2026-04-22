// Problem: PRAVO - Tam giac vuong
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/PRAVO/
// Source contest: Croatian Open 2007
// Topic: Geometry / counting right triangles
// Idea: same O(n^2 log n) direction-counting solution, with macro-style buffered input

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int INP, AM;
#define BUFSIZE (1 << 16)
char BUF[BUFSIZE + 1], *inp = BUF;

inline void refill_buffer() {
    size_t bytes = fread(BUF, 1, BUFSIZE, stdin);
    BUF[bytes] = 0;
    inp = BUF;
}

#define GETCHAR(INP) { \
    if (!*inp) { \
        refill_buffer(); \
    } \
    INP = *inp++; \
}

#define DIG(a) (((a) >= '0') && ((a) <= '9'))

#define GN(j) { \
    AM = 0; \
    GETCHAR(INP); \
    while (!DIG(INP) && INP != '-') GETCHAR(INP); \
    if (INP == '-') { \
        AM = 1; \
        GETCHAR(INP); \
    } \
    j = INP - '0'; \
    GETCHAR(INP); \
    while (DIG(INP)) { \
        j = 10 * j + (INP - '0'); \
        GETCHAR(INP); \
    } \
    if (AM) j = -j; \
}

struct Dir {
    int x;
    int y;

    bool operator<(const Dir& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Dir& other) const {
        return x == other.x && y == other.y;
    }
};

long long gcdll(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Dir canonical_dir(long long dx, long long dy) {
    long long g = gcdll(llabs(dx), llabs(dy));
    dx /= g;
    dy /= g;

    if (dx < 0 || (dx == 0 && dy < 0)) {
        dx = -dx;
        dy = -dy;
    }

    return {static_cast<int>(dx), static_cast<int>(dy)};
}

Dir perpendicular_dir(const Dir& d) {
    long long x = -static_cast<long long>(d.y);
    long long y = static_cast<long long>(d.x);
    if (x < 0 || (x == 0 && y < 0)) {
        x = -x;
        y = -y;
    }
    return {static_cast<int>(x), static_cast<int>(y)};
}

int main() {
    int n;
    GN(n);

    vector<long long> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        GN(xs[i]);
        GN(ys[i]);
    }

    long long answer = 0;
    vector<Dir> dirs;
    dirs.reserve(n - 1);
    vector<Dir> uniq;
    uniq.reserve(n - 1);
    vector<int> cnt;
    cnt.reserve(n - 1);

    for (int i = 0; i < n; ++i) {
        dirs.clear();
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            dirs.push_back(canonical_dir(xs[j] - xs[i], ys[j] - ys[i]));
        }

        sort(dirs.begin(), dirs.end());

        uniq.clear();
        cnt.clear();
        for (const Dir& d : dirs) {
            if (uniq.empty() || !(uniq.back() == d)) {
                uniq.push_back(d);
                cnt.push_back(1);
            } else {
                ++cnt.back();
            }
        }

        long long local = 0;
        for (int k = 0; k < static_cast<int>(uniq.size()); ++k) {
            Dir p = perpendicular_dir(uniq[k]);
            auto it = lower_bound(uniq.begin(), uniq.end(), p);
            if (it != uniq.end() && *it == p) {
                int idx = static_cast<int>(it - uniq.begin());
                local += 1LL * cnt[k] * cnt[idx];
            }
        }

        answer += local / 2;
    }

    printf("%lld\n", answer);
    return 0;
}
