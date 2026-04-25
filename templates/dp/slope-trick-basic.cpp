// Template: slope trick for convex piecewise-linear DP
// Signal: the DP state is one convex function f(x), updated by hinge penalties
// like max(0, x-a), max(0, a-x), |x-a|, and bounded argmin shifts.
// Assumes: x is integer-valued and you only need the minimum value plus the
// current minimizer interval, not full function reconstruction.
// Exposes: add_x_minus_a(a), add_a_minus_x(a), add_abs(a), shift_min(dl, dr),
// expand_argmin_by(d), seed_argmin_point(a, copies), min_value(), and argmin_interval().
// Complexity: O(log n) per hinge update, O(1) per lazy shift.
// Main trap: swapping the meanings of the two one-sided hinges, or using this
// when the transition is really affine and wants CHT / Li Chao instead.
// Links:
//   Topic: topics/dp/slope-trick/README.md
//   Note: practice/ladders/dp/slope-trick/snuketoon.md

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>

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

    void add_abs(long long a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }

    void shift_min(long long delta_left, long long delta_right) {
        assert(delta_left <= delta_right);
        add_left += delta_left;
        add_right += delta_right;
    }

    void expand_argmin_by(long long distance) {
        shift_min(-distance, distance);
    }

    void seed_argmin_point(long long a, int copies) {
        while (copies-- > 0) {
            push_left(a);
            push_right(a);
        }
    }

    long long min_value() const {
        return min_f;
    }

    pair<long long, long long> argmin_interval() const {
        static constexpr long long INF = numeric_limits<long long>::max() / 4;
        long long l = left.empty() ? -INF : top_left();
        long long r = right.empty() ? INF : top_right();
        return {l, r};
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
    SlopeTrick st;
    st.add_abs(4);
    st.add_abs(1);
    st.expand_argmin_by(2);
    st.add_x_minus_a(5);

    auto [l, r] = st.argmin_interval();
    cout << st.min_value() << '\n';
    cout << l << ' ' << r << '\n';
    return 0;
}
