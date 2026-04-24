#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> wait(n);
    for (long long &x : wait) {
        cin >> x;
    }

    sort(wait.begin(), wait.end(), greater<long long>());

    int joined = 0;
    for (long long x : wait) {
        if (x >= joined) {
            ++joined;
        }
    }

    cout << joined << '\n';
    return 0;
}
