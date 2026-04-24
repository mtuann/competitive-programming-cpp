#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;

    vector<pair<long long, int>> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i].first;
        values[i].second = i + 1;
    }

    sort(values.begin(), values.end());

    int left = 0;
    int right = n - 1;
    while (left < right) {
        long long sum = values[left].first + values[right].first;
        if (sum == target) {
            cout << values[left].second << ' ' << values[right].second << '\n';
            return 0;
        }
        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
