#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, budget;
    cin >> n >> budget;

    vector<int> price(n);
    vector<int> pages(n);
    for (int &value : price) {
        cin >> value;
    }
    for (int &value : pages) {
        cin >> value;
    }

    vector<int> dp(budget + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int money = budget; money >= price[i]; --money) {
            dp[money] = max(dp[money], dp[money - price[i]] + pages[i]);
        }
    }

    cout << dp[budget] << '\n';
    return 0;
}
