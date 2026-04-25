// Template: SOS DP via subset/superset zeta sweeps
// Signal: every mask on the full boolean cube needs an aggregate over all submasks,
// all supersets, or one witness propagated along the same sweep skeleton.
// Assumes: arrays have length exactly 1 << bits and the mask universe is dense enough
// for O(bits * 2^bits) time and O(2^bits) memory to be realistic.
// Exposes: subset_zeta_transform(f, bits), superset_zeta_transform(f, bits),
// and propagate_any_subset(witness, bits) with -1 as the missing sentinel.
// Complexity: O(bits * 2^bits) per sweep.
// Main trap: mixing subset direction and superset direction, then querying the wrong mask.
// Links:
//   Topic: topics/dp/sos-dp/README.md
//   Note: practice/ladders/dp/sos-dp/compatiblenumbers.md

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void subset_zeta_transform(vector<T>& f, int bits) {
    assert(static_cast<int>(f.size()) == (1 << bits));
    for (int bit = 0; bit < bits; ++bit) {
        for (int mask = 0; mask < (1 << bits); ++mask) {
            if (mask & (1 << bit)) {
                f[mask] += f[mask ^ (1 << bit)];
            }
        }
    }
}

template <class T>
void superset_zeta_transform(vector<T>& f, int bits) {
    assert(static_cast<int>(f.size()) == (1 << bits));
    for (int bit = 0; bit < bits; ++bit) {
        for (int mask = 0; mask < (1 << bits); ++mask) {
            if ((mask & (1 << bit)) == 0) {
                f[mask] += f[mask | (1 << bit)];
            }
        }
    }
}

void propagate_any_subset(vector<int>& witness, int bits) {
    assert(static_cast<int>(witness.size()) == (1 << bits));
    for (int bit = 0; bit < bits; ++bit) {
        for (int mask = 0; mask < (1 << bits); ++mask) {
            if ((mask & (1 << bit)) && witness[mask] == -1) {
                witness[mask] = witness[mask ^ (1 << bit)];
            }
        }
    }
}

int main() {
    const int bits = 3;
    vector<long long> base(1 << bits, 0);
    base[1] = 5;
    base[2] = 7;
    base[7] = 11;

    auto subset = base;
    subset_zeta_transform(subset, bits);
    cout << subset[3] << ' ' << subset[7] << '\n';

    auto superset = base;
    superset_zeta_transform(superset, bits);
    cout << superset[1] << ' ' << superset[0] << '\n';

    vector<int> witness(1 << bits, -1);
    witness[1] = 1;
    witness[2] = 2;
    propagate_any_subset(witness, bits);
    cout << witness[6] << ' ' << witness[5] << '\n';
    return 0;
}
