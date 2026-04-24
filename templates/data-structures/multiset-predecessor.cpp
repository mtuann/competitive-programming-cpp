// Use: predecessor queries in an ordered multiset with duplicates.
// Invariant: returns an iterator to the largest value < x, or ms.end() if none exists.
// Complexity: O(log n) per query.

#include <iostream>
#include <iterator>
#include <set>

using namespace std;

template <class T, class Compare = less<T>>
typename multiset<T, Compare>::iterator predecessor(multiset<T, Compare> &ms, const T &x) {
    auto it = ms.lower_bound(x);
    return it == ms.begin() ? ms.end() : prev(it);
}

template <class T, class Compare = less<T>>
typename multiset<T, Compare>::const_iterator predecessor(const multiset<T, Compare> &ms, const T &x) {
    auto it = ms.lower_bound(x);
    return it == ms.begin() ? ms.end() : prev(it);
}

int main() {
    multiset<int> ms = {1, 2, 2, 4, 7};
    auto it = predecessor(ms, 4);
    if (it == ms.end()) {
        cout << "none\n";
    } else {
        cout << *it << '\n';
    }
    return 0;
}
