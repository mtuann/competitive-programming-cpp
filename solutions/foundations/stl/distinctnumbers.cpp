#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> values(n);
    for (int &value : values) {
        cin >> value;
    }

    sort(values.begin(), values.end());
    auto unique_end = unique(values.begin(), values.end());
    cout << (unique_end - values.begin()) << '\n';

    return 0;
}
