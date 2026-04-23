// Template: sparse table for static range minimum query.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SparseTable {
    vector<vector<int>> st;
    vector<int> lg;

    explicit SparseTable(const vector<int> &a) {
        int n = static_cast<int>(a.size());
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
        int levels = lg[n] + 1;
        st.assign(levels, vector<int>(n));
        st[0] = a;
        for (int k = 1; k < levels; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        int k = lg[r - l + 1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
    vector<int> a = {5, 2, 7, 1, 3};
    SparseTable st(a);
    cout << st.query(1, 3) << '\n';
    return 0;
}
