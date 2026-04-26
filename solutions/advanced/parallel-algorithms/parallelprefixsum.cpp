#include <iostream>
#include <vector>

using namespace std;

vector<long long> blelloch_exclusive_scan(const vector<long long>& values) {
    if (values.empty()) {
        return {};
    }

    size_t m = 1;
    while (m < values.size()) {
        m <<= 1;
    }

    vector<long long> tree(m, 0);
    for (size_t i = 0; i < values.size(); ++i) {
        tree[i] = values[i];
    }

    for (size_t step = 1; step < m; step <<= 1) {
        for (size_t i = 0; i < m; i += (step << 1)) {
            tree[i + (step << 1) - 1] += tree[i + step - 1];
        }
    }

    tree[m - 1] = 0;
    for (size_t step = m >> 1; step > 0; step >>= 1) {
        for (size_t i = 0; i < m; i += (step << 1)) {
            const size_t left = i + step - 1;
            const size_t right = i + (step << 1) - 1;
            const long long saved_left = tree[left];
            tree[left] = tree[right];
            tree[right] += saved_left;
        }
    }

    return vector<long long>(tree.begin(), tree.begin() + static_cast<long long>(values.size()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<long long> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    const vector<long long> ans = blelloch_exclusive_scan(values);
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
