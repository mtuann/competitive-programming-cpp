// Template: monotonic deque minimum
// Signal: sliding minimum or DP over a forward-only moving interval.
// Assumes: expired indices leave forever and dominance is by value then recency.
// Exposes: MonotonicMinDeque with push(idx, value), expire(min_idx), get_min().
// Complexity: amortized O(1) per push/expire, O(1) to read the minimum.
// Main trap: using it when the valid set is not a contiguous forward-moving window.
// Links:
//   Topic: topics/data-structures/heaps-and-ordered-sets/README.md
//   Note: practice/ladders/dp/sliding-window/tfield.md

#include <deque>
#include <iostream>
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

int main() {
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> mins = sliding_window_min(a, 3);
    for (int i = 0; i < static_cast<int>(mins.size()); ++i) {
        cout << mins[i] << (i + 1 == static_cast<int>(mins.size()) ? '\n' : ' ');
    }
    return 0;
}
