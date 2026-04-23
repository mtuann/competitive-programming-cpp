// Template: sort and comparator
// Use when sorting records by one or more keys.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int first_key;
    int second_key;
};

int main() {
    vector<Item> a = {{2, 5}, {1, 7}, {2, 3}};

    sort(a.begin(), a.end(), [](const Item &lhs, const Item &rhs) {
        if (lhs.first_key != rhs.first_key) {
            return lhs.first_key < rhs.first_key;
        }
        return lhs.second_key < rhs.second_key;
    });

    for (const Item &x : a) {
        cout << x.first_key << ' ' << x.second_key << '\n';
    }
    return 0;
}
