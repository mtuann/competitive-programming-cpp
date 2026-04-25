// Template: XOR Basis / Linear Basis
// Signal: the task asks about xor of any subset, such as maximum subset xor or
// whether a target value is representable by xor-ing chosen elements.
// Assumes: values fit in signed long long and one fixed max_bit convention is
// used across all insertions and queries.
// Exposes: XorBasis with insert(), can_make(), max_xor(), and dimension().
// Complexity: O(max_bit + 1) per insertion or query.
// Main trap: confusing subset-xor span queries with binary-trie pair-xor
// queries against one stored element.
// Links:
//   Topic: topics/math/xor-basis/README.md
//   Note: practice/ladders/math/xor-basis/xmax.md

#include <iostream>
#include <vector>

using namespace std;

struct XorBasis {
    int max_bit;
    vector<long long> basis;

    explicit XorBasis(int max_bit = 60) : max_bit(max_bit), basis(max_bit + 1, 0) {}

    bool insert(long long x) {
        for (int bit = max_bit; bit >= 0; --bit) {
            if (((x >> bit) & 1LL) == 0) {
                continue;
            }
            if (basis[bit] == 0) {
                basis[bit] = x;
                return true;
            }
            x ^= basis[bit];
        }
        return false;
    }

    bool can_make(long long x) const {
        for (int bit = max_bit; bit >= 0; --bit) {
            if (((x >> bit) & 1LL) == 0) {
                continue;
            }
            if (basis[bit] == 0) {
                return false;
            }
            x ^= basis[bit];
        }
        return true;
    }

    long long max_xor() const {
        long long ans = 0;
        for (int bit = max_bit; bit >= 0; --bit) {
            if ((ans ^ basis[bit]) > ans) {
                ans ^= basis[bit];
            }
        }
        return ans;
    }

    int dimension() const {
        int dim = 0;
        for (long long x : basis) {
            dim += (x != 0);
        }
        return dim;
    }
};

int main() {
    XorBasis basis;
    basis.insert(1);
    basis.insert(2);
    basis.insert(4);

    cout << basis.max_xor() << '\n';
    cout << basis.can_make(3) << ' ' << basis.can_make(8) << '\n';
    return 0;
}
