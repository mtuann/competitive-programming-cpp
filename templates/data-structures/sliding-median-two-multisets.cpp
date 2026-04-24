// Template: sliding median with two multisets
// Signal: maintain a lower median under insertions, deletions, and duplicates.
// Assumes: lo stores the smaller half, hi the larger half, and the wanted answer is the lower median.
// Exposes: SlidingMedian with add(x), erase(x), median(), plus sliding_median(a, k).
// Complexity: O(log n) per add/erase, O(1) median lookup.
// Main trap: forgetting this returns the lower median, not the average or upper median.
// Links:
//   Topic: topics/data-structures/heaps-and-ordered-sets/README.md
//   Notebook: notebook/data-structures-cheatsheet.md

#include <iostream>
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

int main() {
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> medians = sliding_median(a, 3);
    for (int i = 0; i < static_cast<int>(medians.size()); ++i) {
        cout << medians[i] << (i + 1 == static_cast<int>(medians.size()) ? '\n' : ' ');
    }
    return 0;
}
