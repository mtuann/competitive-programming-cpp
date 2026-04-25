// Template: ODT / Chtholly interval partition over one 1-indexed array.
// Signal: range assign keeps collapsing equal-value runs, and later operations
// can be answered by walking only the current touched intervals.
// Assumes: the data is random / soft enough, or assign operations happen often
// enough, that the interval count stays manageable in practice.
// Exposes: split(), assign_range(), add_range(), kth_smallest(), and
// range_pow_sum() over the current interval partition.
// Complexity: O(log S + k) per touched slice plus extra sorting for kth, where
// S is the current node count and k is the number of touched intervals.
// Main trap: this is not a hard worst-case substitute for lazy / beats segment
// trees on adversarial updates.
// Links:
//   Topic: topics/data-structures/odt-chtholly/README.md
//   Note: practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

struct ODTIntervalSet {
    struct Node {
        int l;
        int r;
        mutable long long v;

        bool operator<(const Node& other) const { return l < other.l; }
    };

    int n;
    set<Node> segments;

    explicit ODTIntervalSet(const vector<long long>& initial)
        : n(static_cast<int>(initial.size()) - 1) {
        for (int i = 1; i <= n; ++i) {
            segments.insert({i, i, initial[i]});
        }
    }

    set<Node>::iterator split(int pos) {
        if (pos > n) {
            return segments.end();
        }
        auto it = prev(segments.upper_bound({pos, 0, 0}));
        if (it->l == pos) {
            return it;
        }
        int l = it->l;
        int r = it->r;
        long long v = it->v;
        segments.erase(it);
        segments.insert({l, pos - 1, v});
        return segments.insert({pos, r, v}).first;
    }

    void assign_range(int l, int r, long long value) {
        auto itr = split(r + 1);
        auto itl = split(l);
        segments.erase(itl, itr);
        segments.insert({l, r, value});
    }

    void add_range(int l, int r, long long delta) {
        auto itr = split(r + 1);
        auto itl = split(l);
        for (auto it = itl; it != itr; ++it) {
            it->v += delta;
        }
    }

    long long kth_smallest(int l, int r, long long k) {
        auto itr = split(r + 1);
        auto itl = split(l);
        vector<pair<long long, int>> pieces;
        for (auto it = itl; it != itr; ++it) {
            pieces.push_back({it->v, it->r - it->l + 1});
        }
        sort(pieces.begin(), pieces.end());
        for (const auto& [value, length] : pieces) {
            if (k <= length) {
                return value;
            }
            k -= length;
        }
        return -1;
    }

    static long long mod_mul(long long a, long long b, long long mod) {
        return static_cast<long long>((__int128)a * b % mod);
    }

    static long long mod_pow(long long base, long long exp, long long mod) {
        if (mod == 1) {
            return 0;
        }
        base %= mod;
        long long result = 1 % mod;
        while (exp > 0) {
            if (exp & 1LL) {
                result = mod_mul(result, base, mod);
            }
            base = mod_mul(base, base, mod);
            exp >>= 1LL;
        }
        return result;
    }

    long long range_pow_sum(int l, int r, long long exp, long long mod) {
        if (mod == 1) {
            return 0;
        }
        auto itr = split(r + 1);
        auto itl = split(l);
        long long answer = 0;
        for (auto it = itl; it != itr; ++it) {
            long long length = it->r - it->l + 1;
            long long contribution = mod_mul(length % mod, mod_pow(it->v, exp, mod), mod);
            answer += contribution;
            if (answer >= mod) {
                answer -= mod;
            }
        }
        return answer;
    }
};

int main() {
    vector<long long> initial = {0, 1, 2, 3, 4, 5};
    ODTIntervalSet odt(initial);

    odt.assign_range(2, 4, 7);
    odt.add_range(1, 3, 2);

    cout << odt.kth_smallest(1, 5, 3) << '\n';
    cout << odt.range_pow_sum(1, 5, 2, 100) << '\n';
    return 0;
}
