#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;

    explicit SegmentTree(const vector<long long> &values)
        : n(static_cast<int>(values.size())), tree(2 * n, 0) {
        for (int i = 0; i < n; ++i) {
            tree[n + i] = values[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    void set_value(int index, long long value) {
        index += n;
        tree[index] = value;
        for (index >>= 1; index > 0; index >>= 1) {
            tree[index] = tree[index << 1] + tree[index << 1 | 1];
        }
    }

    long long query(int left, int right) const {
        long long result = 0;
        for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
            if (left & 1) {
                result += tree[left++];
            }
            if (right & 1) {
                result += tree[--right];
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> values(n);
    for (long long &value : values) {
        cin >> value;
    }

    SegmentTree st(values);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int index;
            long long value;
            cin >> index >> value;
            st.set_value(index - 1, value);
        } else {
            int left, right;
            cin >> left >> right;
            cout << st.query(left - 1, right) << '\n';
        }
    }

    return 0;
}
