// Template: Z-function
// Signal: one-string diagnostics, prefix matches, borders, or periods.
// Assumes: z[i] means longest prefix match starting at i and the maintained box is [l, r).
// Exposes: z_function(s).
// Complexity: O(n).
// Main trap: mixing inclusive and half-open meaning for the right border r.
// Links:
//   Topic: topics/strings/z-function/README.md
//   Note: practice/ladders/strings/z-function/findingperiods.md

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z_function(const string &s) {
    int n = static_cast<int>(s.size());
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    vector<int> z = z_function("aaaaa");
    cout << z[1] << '\n';
    return 0;
}
