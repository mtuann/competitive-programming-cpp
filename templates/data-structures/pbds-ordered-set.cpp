// Template: PBDS / Order Statistics Tree
// Signal: online rank / count-smaller / k-th queries on one ordered set, with
// optional duplicate-safe wrapping when equal values matter.
// Assumes: GNU++ / libstdc++ PBDS is available; raw ordered_set<T> has unique
// keys only, while duplicates require the pair-key wrapper below.
// Exposes: ordered_set<T> with find_by_order() and order_of_key(), plus
// OrderedMultiset<T> with insert(), erase_one(), count_less(), count_leq(),
// count_in_range(), kth_value(), size(), and empty().
// Complexity: O(log n) per insert, erase, rank, range-count, or k-th query.
// Main trap: forgetting PBDS is not standard C++, or using raw ordered_set<T>
// when duplicates should stay distinct.
// Links:
//   Topic: topics/data-structures/pbds-order-statistics/README.md
//   Note: practice/ladders/data-structures/pbds-order-statistics/orderset.md

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <limits>
#include <utility>

using namespace std;
using namespace __gnu_pbds;

template <class T, class Compare = less<T>>
using ordered_set =
    tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
struct OrderedMultiset {
    using Key = pair<T, int>;
    using Tree =
        tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

    Tree tr;
    int next_id = 0;

    bool empty() const {
        return tr.empty();
    }

    int size() const {
        return static_cast<int>(tr.size());
    }

    void clear() {
        tr.clear();
        next_id = 0;
    }

    void insert(const T& x) {
        tr.insert({x, next_id++});
    }

    bool erase_one(const T& x) {
        auto it = tr.lower_bound({x, numeric_limits<int>::min()});
        if (it == tr.end() || it->first != x) {
            return false;
        }
        tr.erase(it);
        return true;
    }

    int count_less(const T& x) const {
        return static_cast<int>(tr.order_of_key({x, numeric_limits<int>::min()}));
    }

    int count_leq(const T& x) const {
        return static_cast<int>(tr.order_of_key({x, numeric_limits<int>::max()}));
    }

    int count_in_range(const T& l, const T& r) const {
        if (r < l) {
            return 0;
        }
        return count_leq(r) - count_less(l);
    }

    int count_value(const T& x) const {
        return count_leq(x) - count_less(x);
    }

    bool kth_value(int k, T& out) const {
        if (k < 0 || k >= size()) {
            return false;
        }
        out = tr.find_by_order(k)->first;
        return true;
    }
};

int main() {
    ordered_set<int> os;
    os.insert(2);
    os.insert(7);
    os.insert(10);

    cout << *os.find_by_order(1) << '\n';
    cout << os.order_of_key(8) << '\n';

    OrderedMultiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(9);

    int kth = -1;
    ms.kth_value(1, kth);
    cout << kth << '\n';
    cout << ms.count_in_range(5, 8) << '\n';
    return 0;
}
