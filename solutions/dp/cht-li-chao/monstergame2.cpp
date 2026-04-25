// Problem: Monster Game II
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2085
// Topic: Li Chao tree, affine DP, line container
// Idea: each previous state contributes y = f_j * x + dp[j], queried at x = s_i.

#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct LiChaoMin {
    struct Line {
        long long m = 0;
        long long b = 0;
        bool empty = true;

        __int128 eval(long long x) const {
            return static_cast<__int128>(m) * x + b;
        }
    };

    struct Node {
        Line line;
        int left = -1;
        int right = -1;
    };

    static constexpr __int128 INF128 = (static_cast<__int128>(1) << 120);

    long long x_low;
    long long x_high;
    deque<Node> nodes;

    LiChaoMin(long long x_low, long long x_high) : x_low(x_low), x_high(x_high) {
        nodes.push_back(Node());
    }

    void add_line(long long m, long long b) {
        Line line;
        line.m = m;
        line.b = b;
        line.empty = false;
        add_line(0, x_low, x_high, line);
    }

    long long query(long long x) const {
        return static_cast<long long>(query(0, x_low, x_high, x));
    }

private:
    int new_node() {
        nodes.push_back(Node());
        return static_cast<int>(nodes.size()) - 1;
    }

    void add_line(int idx, long long l, long long r, Line line) {
        Node& node = nodes[idx];
        if (node.line.empty) {
            node.line = line;
            return;
        }

        long long mid = l + (r - l) / 2;
        bool left_better = line.eval(l) < node.line.eval(l);
        bool mid_better = line.eval(mid) < node.line.eval(mid);

        if (mid_better) {
            swap(line, node.line);
        }
        if (l == r || line.empty) {
            return;
        }

        if (left_better != mid_better) {
            if (node.left == -1) {
                node.left = new_node();
            }
            add_line(node.left, l, mid, line);
        } else {
            if (node.right == -1) {
                node.right = new_node();
            }
            add_line(node.right, mid + 1, r, line);
        }
    }

    __int128 query(int idx, long long l, long long r, long long x) const {
        if (idx == -1) {
            return INF128;
        }
        const Node& node = nodes[idx];
        __int128 ans = node.line.empty ? INF128 : node.line.eval(x);
        if (l == r) {
            return ans;
        }
        long long mid = l + (r - l) / 2;
        if (x <= mid) {
            return min(ans, query(node.left, l, mid, x));
        }
        return min(ans, query(node.right, mid + 1, r, x));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long initial_skill;
    cin >> n >> initial_skill;

    vector<long long> s(n), f(n);
    for (long long& x : s) {
        cin >> x;
    }
    for (long long& x : f) {
        cin >> x;
    }

    long long x_low = *min_element(s.begin(), s.end());
    long long x_high = *max_element(s.begin(), s.end());
    LiChaoMin hull(x_low, x_high);
    hull.add_line(initial_skill, 0);

    vector<long long> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = hull.query(s[i]);
        hull.add_line(f[i], dp[i]);
    }

    cout << dp.back() << '\n';
    return 0;
}
