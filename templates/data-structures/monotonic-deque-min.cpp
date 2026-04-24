// Use: sliding-window minimum or DP over a moving interval.
// Invariant: indices increase front to back and values increase strictly, so the front is the current minimum.
// Complexity: amortized O(1) per push/expire, O(1) to read the minimum.

#include <deque>
#include <utility>
#include <vector>

using namespace std;

template <class T>
struct MonotonicMinDeque {
    deque<pair<int, T>> dq;

    void push(int idx, const T &value) {
        while (!dq.empty() && dq.back().second >= value) {
            dq.pop_back();
        }
        dq.emplace_back(idx, value);
    }

    void expire(int min_idx) {
        while (!dq.empty() && dq.front().first < min_idx) {
            dq.pop_front();
        }
    }

    const T &get_min() const {
        return dq.front().second;
    }

    bool empty() const {
        return dq.empty();
    }
};

template <class T>
vector<T> sliding_window_min(const vector<T> &a, int k) {
    if (k <= 0 || k > static_cast<int>(a.size())) {
        return {};
    }
    MonotonicMinDeque<T> dq;
    vector<T> mins;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        dq.push(i, a[i]);
        dq.expire(i - k + 1);
        if (i + 1 >= k) {
            mins.push_back(dq.get_min());
        }
    }
    return mins;
}
