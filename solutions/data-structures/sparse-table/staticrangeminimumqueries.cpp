#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SparseTable {
    vector<vector<int>> st;
    vector<int> lg;

    explicit SparseTable(const vector<int> &values) {
        int n = static_cast<int>(values.size());
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i >> 1] + 1;
        }

        int levels = lg[n] + 1;
        st.assign(levels, vector<int>(n));
        st[0] = values;

        for (int k = 1; k < levels; ++k) {
            int block = 1 << k;
            int half = block >> 1;
            for (int i = 0; i + block <= n; ++i) {
                st[k][i] = min(st[k - 1][i], st[k - 1][i + half]);
            }
        }
    }

    int query(int left, int right) const {
        int k = lg[right - left + 1];
        return min(st[k][left], st[k][right - (1 << k) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    for (int &value : values) {
        cin >> value;
    }

    SparseTable st(values);

    while (q--) {
        int left, right;
        cin >> left >> right;
        --left;
        --right;
        cout << st.query(left, right) << '\n';
    }

    return 0;
}
