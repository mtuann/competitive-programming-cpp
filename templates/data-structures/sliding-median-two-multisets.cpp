// Use: maintain a sliding-window median with insertions, deletions, and duplicates.
// Invariant: lo stores the smaller half, hi the larger half, |lo| = |hi| or |lo| = |hi| + 1, and every lo <= every hi.
// Complexity: O(log n) per add/erase, O(1) for the lower median.

#include <iterator>
#include <set>
#include <vector>

using namespace std;

template <class T>
struct SlidingMedian {
    multiset<T> lo, hi;

    void rebalance() {
        while (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        }
        while (lo.size() < hi.size()) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    }

    void add(const T &x) {
        if (lo.empty() || x <= *prev(lo.end())) {
            lo.insert(x);
        } else {
            hi.insert(x);
        }
        rebalance();
    }

    bool erase(const T &x) {
        if (auto it = lo.find(x); it != lo.end()) {
            lo.erase(it);
        } else if (auto it = hi.find(x); it != hi.end()) {
            hi.erase(it);
        } else {
            return false;
        }
        rebalance();
        return true;
    }

    const T &median() const {
        return *prev(lo.end());
    }
};

template <class T>
vector<T> sliding_median(const vector<T> &a, int k) {
    if (k <= 0 || k > static_cast<int>(a.size())) {
        return {};
    }
    SlidingMedian<T> sw;
    vector<T> medians;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        sw.add(a[i]);
        if (i >= k) {
            sw.erase(a[i - k]);
        }
        if (i + 1 >= k) {
            medians.push_back(sw.median());
        }
    }
    return medians;
}
