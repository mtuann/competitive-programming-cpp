// Template: monotonic stack for nearest strictly smaller value on the left.
// Signal: first smaller / greater boundary in one linear scan where domination
// is permanent.
// Assumes: each answer is decided once, equal-value tie policy is explicit, and
// later elements never resurrect a popped candidate.
// Exposes: nearest_smaller_left(a) returning the previous strictly smaller index
// for each position, or -1 when none exists.
// Complexity: O(n) total because every index is pushed once and popped once.
// Main trap: using '>' instead of '>=' and silently changing strict-smaller
// semantics when equal values appear.
// Links:
//   Topic: topics/data-structures/monotonic-stack-queue/README.md
//   Note: practice/ladders/data-structures/monotonic-stack-queue/nearestsmallervalues.md

#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<int> nearest_smaller_left(const vector<T>& a) {
    vector<int> prev(static_cast<int>(a.size()), -1);
    vector<int> st;
    st.reserve(a.size());

    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            st.pop_back();
        }
        prev[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    return prev;
}

int main() {
    vector<int> a = {2, 5, 1, 4, 8, 3, 2, 5};
    vector<int> prev = nearest_smaller_left(a);
    for (int i = 0; i < static_cast<int>(prev.size()); ++i) {
        cout << (prev[i] == -1 ? 0 : prev[i] + 1)
             << (i + 1 == static_cast<int>(prev.size()) ? '\n' : ' ');
    }
    return 0;  // 0 1 0 3 4 3 3 7
}
