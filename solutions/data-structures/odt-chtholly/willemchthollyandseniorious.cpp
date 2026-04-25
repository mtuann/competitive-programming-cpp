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

long long seed_value;

int next_rand(int mod) {
    long long ret = seed_value;
    seed_value = (seed_value * 7 + 13) % 1000000007LL;
    return static_cast<int>(ret % mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, vmax;
    cin >> n >> m >> seed_value >> vmax;

    vector<long long> initial(n + 1);
    for (int i = 1; i <= n; ++i) {
        initial[i] = next_rand(vmax) + 1;
    }

    ODTIntervalSet odt(initial);

    for (int query = 0; query < m; ++query) {
        int op = next_rand(4) + 1;
        int l = next_rand(n) + 1;
        int r = next_rand(n) + 1;
        if (l > r) {
            swap(l, r);
        }
        int x = (op == 3) ? (next_rand(r - l + 1) + 1) : (next_rand(vmax) + 1);

        if (op == 1) {
            odt.add_range(l, r, x);
        } else if (op == 2) {
            odt.assign_range(l, r, x);
        } else if (op == 3) {
            cout << odt.kth_smallest(l, r, x) << '\n';
        } else {
            int y = next_rand(vmax) + 1;
            cout << odt.range_pow_sum(l, r, x, y) << '\n';
        }
    }
    return 0;
}
