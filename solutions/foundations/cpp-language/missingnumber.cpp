#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long missing = n * (n + 1) / 2;
    for (long long i = 0; i < n - 1; ++i) {
        long long value;
        cin >> value;
        missing -= value;
    }

    cout << missing << '\n';
    return 0;
}
