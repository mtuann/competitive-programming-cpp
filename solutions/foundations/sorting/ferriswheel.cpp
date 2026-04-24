#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> weights(n);
    for (long long &weight : weights) {
        cin >> weight;
    }

    sort(weights.begin(), weights.end());

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            ++left;
        }
        --right;
        ++gondolas;
    }

    cout << gondolas << '\n';
    return 0;
}
