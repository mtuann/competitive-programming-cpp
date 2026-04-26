// Problem: Nearest Smaller Values
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1645
// Topic: monotonic stack, previous smaller, boundary scan
// Idea: keep an increasing stack of candidate indices; pop every value >= the
// current one, then the new top is the nearest strictly smaller index.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long& x : a) {
        cin >> x;
    }

    vector<int> st;
    st.reserve(n);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            st.pop_back();
        }
        int answer = st.empty() ? 0 : st.back() + 1;
        cout << answer << (i + 1 == n ? '\n' : ' ');
        st.push_back(i);
    }
    return 0;
}
