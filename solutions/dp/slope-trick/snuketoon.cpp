// Problem: Snuketoon
// Judge: AtCoder ABC217 H
// Source URL: https://atcoder.jp/contests/abc217/tasks/abc217_h
// Topic: slope trick, convex DP, two heaps
// Idea: keep the convex DP f(x) by two heaps of slope-change points; each shot
// adds one one-sided hinge, and time gaps widen the minimizer interval.

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct SlopeTrick {
    long long min_f = 0;
    long long add_left = 0;
    long long add_right = 0;
    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, greater<long long>> right;

    void add_x_minus_a(long long a) {
        if (!left.empty()) {
            min_f += max(0LL, top_left() - a);
        }
        push_left(a);
        push_right(pop_left());
    }

    void add_a_minus_x(long long a) {
        if (!right.empty()) {
            min_f += max(0LL, a - top_right());
        }
        push_right(a);
        push_left(pop_right());
    }

    void expand_argmin_by(long long distance) {
        add_left -= distance;
        add_right += distance;
    }

    void seed_argmin_point(long long a, int copies) {
        while (copies-- > 0) {
            push_left(a);
            push_right(a);
        }
    }

private:
    void push_left(long long x) {
        left.push(x - add_left);
    }

    void push_right(long long x) {
        right.push(x - add_right);
    }

    long long top_left() const {
        return left.top() + add_left;
    }

    long long top_right() const {
        return right.top() + add_right;
    }

    long long pop_left() {
        long long x = top_left();
        left.pop();
        return x;
    }

    long long pop_right() {
        long long x = top_right();
        right.pop();
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    SlopeTrick st;
    st.seed_argmin_point(0, n + 10);
    long long previous_time = 0;
    for (int i = 0; i < n; ++i) {
        long long t, x;
        int d;
        cin >> t >> d >> x;

        st.expand_argmin_by(t - previous_time);
        if (d == 0) {
            st.add_a_minus_x(x);
        } else {
            st.add_x_minus_a(x);
        }
        previous_time = t;
    }

    cout << st.min_f << '\n';
    return 0;
}
