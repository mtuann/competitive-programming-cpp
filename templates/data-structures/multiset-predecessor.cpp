// Template: multiset predecessor
// Signal: predecessor or floor queries in an ordered multiset with duplicates.
// Assumes: duplicates are real elements, not counts only; strict predecessor means largest value < x, floor means largest value <= x.
// Exposes: predecessor(ms, x) for the largest value < x and floor_leq(ms, x) for the largest value <= x, or ms.end().
// Complexity: O(log n) per query.
// Main trap: confusing strict predecessor with floor and silently choosing the wrong bound routine.
// Links:
//   Topic: topics/data-structures/heaps-and-ordered-sets/README.md
//   Note: practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md

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

template <class T, class Compare = less<T>>
typename multiset<T, Compare>::iterator floor_leq(multiset<T, Compare> &ms, const T &x) {
    auto it = ms.upper_bound(x);
    return it == ms.begin() ? ms.end() : prev(it);
}

template <class T, class Compare = less<T>>
typename multiset<T, Compare>::const_iterator floor_leq(const multiset<T, Compare> &ms, const T &x) {
    auto it = ms.upper_bound(x);
    return it == ms.begin() ? ms.end() : prev(it);
}

int main() {
    multiset<int> ms = {1, 2, 2, 4, 7};
    auto it = predecessor(ms, 4);
    auto jt = floor_leq(ms, 4);
    if (it == ms.end()) {
        cout << "none\n";
    } else {
        cout << *it << '\n';
    }
    if (jt == ms.end()) {
        cout << "none\n";
    } else {
        cout << *jt << '\n';
    }
    return 0;
}
