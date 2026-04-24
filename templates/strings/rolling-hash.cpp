// Template: rolling hash
// Signal: same-length substring fingerprints, borders, or LCP via binary search.
// Assumes: equal hashes are treated as fingerprints, not absolute proof of equality.
// Exposes: RollingHash with get(l, r) over half-open substring indices.
// Complexity: O(n) build, O(1) hash extraction.
// Main trap: comparing hashes of substrings with different lengths as if the fingerprint were position-free.
// Links:
//   Topic: topics/strings/hashing/README.md
//   Note: practice/ladders/strings/hashing/findingborders.md

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct RollingHash {
    static const unsigned long long BASE = 911382323ULL;
    vector<unsigned long long> pref, power;

    explicit RollingHash(const string &s) {
        int n = static_cast<int>(s.size());
        pref.assign(n + 1, 0);
        power.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] * BASE + static_cast<unsigned long long>(s[i] + 1);
            power[i + 1] = power[i] * BASE;
        }
    }

    unsigned long long get(int l, int r) const {
        return pref[r] - pref[l] * power[r - l];
    }
};

int main() {
    string s = "abracadabra";
    RollingHash rh(s);
    cout << (rh.get(0, 4) == rh.get(7, 11)) << '\n';
    return 0;
}
