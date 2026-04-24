// Template: sort and comparator
// Use when sorting records by one or more keys.
// Signal: records need an explicit main key and tie rule.
// Assumes: comparator must remain a strict weak ordering.
// Exposes: one record struct plus one lambda comparator pattern.
// Complexity: O(n log n) sort, then usually one linear scan.
// Main trap: forgetting tie behavior or writing an inconsistent comparator.
// Links:
//   Topic: topics/foundations/patterns/sorting/README.md
//   Note: practice/ladders/foundations/sorting/ferriswheel.md
//   Note: practice/ladders/foundations/sorting/moviefestival.md

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
