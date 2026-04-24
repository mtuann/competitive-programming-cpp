#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; ++i) {
        int budget;
        cin >> budget;

        auto it = tickets.upper_bound(budget);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
            continue;
        }

        --it;
        cout << *it << '\n';
        tickets.erase(it);
    }

    return 0;
}
