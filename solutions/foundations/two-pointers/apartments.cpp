#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n), apartments(m);
    for (int &value : applicants) {
        cin >> value;
    }
    for (int &value : apartments) {
        cin >> value;
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0;
    int j = 0;
    int matches = 0;
    while (i < n && j < m) {
        if (apartments[j] < applicants[i] - k) {
            ++j;
        } else if (apartments[j] > applicants[i] + k) {
            ++i;
        } else {
            ++matches;
            ++i;
            ++j;
        }
    }

    cout << matches << '\n';
    return 0;
}
