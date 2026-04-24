#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> suffix(k);
        for (long long &x : suffix) {
            cin >> x;
        }

        bool ok = true;
        for (int i = 2; i < k; ++i) {
            long long prev = suffix[i - 1] - suffix[i - 2];
            long long cur = suffix[i] - suffix[i - 1];
            if (cur < prev) {
                ok = false;
            }
        }

        if (ok && k >= 2) {
            long long next_value = suffix[1] - suffix[0];
            long long prefix_len = n - k + 1LL;
            if (suffix[0] > next_value * prefix_len) {
                ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
