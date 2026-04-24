#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    for (auto &[start, finish] : movies) {
        cin >> start >> finish;
    }

    sort(movies.begin(), movies.end(), [](const auto &a, const auto &b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    int answer = 0;
    int last_finish = 0;
    for (const auto &[start, finish] : movies) {
        if (start >= last_finish) {
            ++answer;
            last_finish = finish;
        }
    }

    cout << answer << '\n';
    return 0;
}
