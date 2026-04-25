// Problem: ORDERSET - Order Statistic Set
// Judge: SPOJ
// Source URL: https://www.spoj.com/problems/ORDERSET/
// Topic: GNU PBDS ordered set, k-th smallest, count smaller than x
// Idea: keep one ordered_set<int>. Use order_of_key(x) for COUNT queries and
// find_by_order(k - 1) for one-based k-th queries. Since this is a set,
// duplicate inserts are ignored naturally.

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <iostream>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    ordered_set<int> s;

    while (q--) {
        char type;
        int x;
        cin >> type >> x;

        if (type == 'I') {
            s.insert(x);
        } else if (type == 'D') {
            s.erase(x);
        } else if (type == 'K') {
            int k = x - 1;
            if (k < 0 || k >= static_cast<int>(s.size())) {
                cout << "invalid\n";
            } else {
                cout << *s.find_by_order(k) << '\n';
            }
        } else {
            cout << s.order_of_key(x) << '\n';
        }
    }

    return 0;
}
