#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    constexpr int BITS = 22;
    constexpr int LIMIT = 1 << BITS;
    constexpr int FULL_MASK = LIMIT - 1;

    vector<int> witness(LIMIT, -1);
    for (int x : a) {
        witness[x] = x;
    }

    for (int bit = 0; bit < BITS; ++bit) {
        for (int mask = 0; mask < LIMIT; ++mask) {
            if ((mask & (1 << bit)) && witness[mask] == -1) {
                witness[mask] = witness[mask ^ (1 << bit)];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int ans = witness[FULL_MASK ^ a[i]];
        cout << ans << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
