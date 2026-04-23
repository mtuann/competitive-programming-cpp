#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct RollingHash {
    static constexpr unsigned long long BASE = 911382323ULL;

    vector<unsigned long long> pref;
    vector<unsigned long long> power;

    explicit RollingHash(const string &s) {
        int n = static_cast<int>(s.size());
        pref.assign(n + 1, 0);
        power.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] * BASE + static_cast<unsigned long long>(
                                               static_cast<unsigned char>(s[i]) + 1);
            power[i + 1] = power[i] * BASE;
        }
    }

    unsigned long long get(int l, int r) const {
        return pref[r] - pref[l] * power[r - l];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = static_cast<int>(s.size());
    RollingHash hash(s);

    bool first = true;
    for (int len = 1; len < n; ++len) {
        if (hash.get(0, len) == hash.get(n - len, n)) {
            if (!first) {
                cout << ' ';
            }
            cout << len;
            first = false;
        }
    }
    cout << '\n';

    return 0;
}
