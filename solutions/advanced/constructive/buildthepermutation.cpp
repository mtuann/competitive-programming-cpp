#include <iostream>
#include <vector>

using namespace std;

static vector<int> build_high_core(int left, int right) {
    vector<int> core;
    core.push_back(left);
    for (int x = left + 1; x <= right; x += 2) {
        if (x + 1 <= right) {
            core.push_back(x + 1);
        }
        core.push_back(x);
    }
    return core;
}

static vector<int> build_low_core(int left, int right) {
    vector<int> core;
    for (int x = left; x <= right; x += 2) {
        if (x + 1 <= right) {
            core.push_back(x + 1);
        }
        core.push_back(x);
    }
    return core;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n - 2 || a - b > 1 || b - a > 1) {
            cout << -1 << '\n';
            continue;
        }

        const int m = a + b + 2;
        vector<int> ans;

        if (a >= b) {
            int left = n - m + 1;
            for (int x = 1; x < left; ++x) {
                ans.push_back(x);
            }
            vector<int> core = build_high_core(left, n);
            ans.insert(ans.end(), core.begin(), core.end());
        } else {
            vector<int> core = build_low_core(1, m);
            ans.insert(ans.end(), core.begin(), core.end());
            for (int x = m + 1; x <= n; ++x) {
                ans.push_back(x);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << ' ';
            }
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
