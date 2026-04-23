// Problem: VODIVIDE - VOI 2015 Day 2 - Chia phần
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/VODIVIDE/
// Topic: greedy selection under prefix constraints
// Idea: sort by a, choose Vinh's coins as a minimum-b feasible subset with prefix cap floor(i / 2), then reconstruct pairs

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Coin {
    int a;
    int b;
    int index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Coin> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i].a;
    long long total_b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i].b;
        coins[i].index = i + 1;
        total_b += coins[i].b;
    }

    sort(coins.begin(), coins.end(),
         [](const Coin& x, const Coin& y) {
             if (x.a != y.a) return x.a < y.a;
             return x.index < y.index;
         });

    vector<int> is_vinh(n, 0);
    priority_queue<pair<int, int> > pq;
    long long vinh_sum = 0;

    for (int i = 0; i < n; ++i) {
        pq.push(make_pair(coins[i].b, i));
        is_vinh[i] = 1;
        vinh_sum += coins[i].b;

        int cap = (i + 1) / 2;
        if ((int)pq.size() > cap) {
            pair<int, int> top = pq.top();
            pq.pop();
            is_vinh[top.second] = 0;
            vinh_sum -= top.first;
        }
    }

    vector<int> open;
    vector<pair<int, int> > answer;
    open.reserve(n / 2);
    answer.reserve(n / 2);

    for (int i = 0; i < n; ++i) {
        if (!is_vinh[i]) {
            open.push_back(coins[i].index);
        } else {
            int son_coin = open.back();
            open.pop_back();
            answer.push_back(make_pair(son_coin, coins[i].index));
        }
    }

    cout << total_b - vinh_sum << '\n';
    for (int i = 0; i < (int)answer.size(); ++i) {
        cout << answer[i].first << ' ' << answer[i].second << '\n';
    }
    return 0;
}
