// Problem: LAMP - Dàn đèn màu
// Judge: VN SPOJ / VNOI
// Source URL: https://vn.spoj.com/problems/LAMP/
// Mirror URL: https://oj.vnoi.info/problem/lamp
// Topic: number theory, densities, exact fractions
// Idea: the final color of lamp x is the last button i such that p_i divides x,
// so color i has density 1/p_i * product_{j>i}(1 - 1/p_j). The formula is exact
// because the p_i are pairwise coprime. We maintain the suffix product as one
// reduced fraction, but use a custom big integer because the time limit is very
// tight and we only need multiply/divide/mod by numbers <= 1e9.

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

static long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a >= 0 ? a : -a;
}

struct BigInt {
    static const uint32_t BASE = 1000000000U;
    vector<uint32_t> d;  // little-endian

    BigInt(uint64_t x = 0) { assign(x); }

    void assign(uint64_t x) {
        d.clear();
        if (x == 0) return;
        while (x > 0) {
            d.push_back(static_cast<uint32_t>(x % BASE));
            x /= BASE;
        }
    }

    bool is_zero() const { return d.empty(); }

    void trim() {
        while (!d.empty() && d.back() == 0) d.pop_back();
    }

    uint32_t mod_uint(uint32_t m) const {
        if (m == 1) return 0;
        uint64_t rem = 0;
        for (int i = static_cast<int>(d.size()) - 1; i >= 0; --i) {
            rem = (rem * BASE + d[i]) % m;
        }
        return static_cast<uint32_t>(rem);
    }

    void div_uint(uint32_t v) {
        uint64_t rem = 0;
        for (int i = static_cast<int>(d.size()) - 1; i >= 0; --i) {
            uint64_t cur = rem * BASE + d[i];
            d[i] = static_cast<uint32_t>(cur / v);
            rem = cur % v;
        }
        trim();
    }

    void mul_uint(uint32_t v) {
        if (is_zero() || v == 1) return;
        if (v == 0) {
            d.clear();
            return;
        }
        uint64_t carry = 0;
        for (size_t i = 0; i < d.size(); ++i) {
            uint64_t cur = carry + static_cast<uint64_t>(d[i]) * v;
            d[i] = static_cast<uint32_t>(cur % BASE);
            carry = cur / BASE;
        }
        while (carry > 0) {
            d.push_back(static_cast<uint32_t>(carry % BASE));
            carry /= BASE;
        }
    }

    string to_string() const {
        if (d.empty()) return "0";
        string s = std::to_string(d.back());
        for (int i = static_cast<int>(d.size()) - 2; i >= 0; --i) {
            string part = std::to_string(d[i]);
            s += string(9 - static_cast<int>(part.size()), '0');
            s += part;
        }
        return s;
    }
};

static long long gcd_big_small(const BigInt& x, long long y) {
    if (y == 0) return 0;
    return gcd_ll(static_cast<long long>(x.mod_uint(static_cast<uint32_t>(y))), y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<uint32_t> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<pair<BigInt, BigInt>> answer(n);

    BigInt suffix_num(1);
    BigInt suffix_den(1);

    for (int i = n - 1; i >= 0; --i) {
        long long g = gcd_big_small(suffix_num, p[i]);
        BigInt ans_num = suffix_num;
        ans_num.div_uint(static_cast<uint32_t>(g));
        BigInt ans_den = suffix_den;
        ans_den.mul_uint(static_cast<uint32_t>(p[i] / g));

        if (ans_num.is_zero()) {
            answer[i] = make_pair(BigInt(0), BigInt(1));
        } else {
            answer[i] = make_pair(ans_num, ans_den);
        }

        if (suffix_num.is_zero() || p[i] == 1U) {
            suffix_num.assign(0);
            suffix_den.assign(1);
            continue;
        }

        uint32_t a = p[i] - 1U;
        uint32_t b = p[i];

        long long g1 = gcd_big_small(suffix_num, b);
        suffix_num.div_uint(static_cast<uint32_t>(g1));
        b /= static_cast<uint32_t>(g1);

        long long g2 = gcd_big_small(suffix_den, a);
        suffix_den.div_uint(static_cast<uint32_t>(g2));
        a /= static_cast<uint32_t>(g2);

        suffix_num.mul_uint(a);
        suffix_den.mul_uint(b);
    }

    for (int i = 0; i < n; ++i) {
        cout << answer[i].first.to_string() << '/' << answer[i].second.to_string() << '\n';
    }

    return 0;
}
