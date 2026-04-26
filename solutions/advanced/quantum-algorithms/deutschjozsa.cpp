#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    const int m = 1 << n;
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        int bit;
        cin >> bit;
        sum += (bit == 0 ? 1LL : -1LL);
    }

    cout << (sum == 0 ? "BALANCED" : "CONSTANT") << '\n';
    return 0;
}
