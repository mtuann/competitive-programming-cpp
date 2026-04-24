// Template: KMP
// Signal: one exact pattern against one text, or one string where border-chain structure matters.
// Assumes: matching is exact and the separator in pattern + '#' + text is not in the alphabet.
// Exposes: prefix_function(s) and find_matches(text, pattern).
// Complexity: O(n) for prefix function, O(n + m) for matching.
// Main trap: treating pi[i] as an index instead of a matched-prefix length.
// Links:
//   Topic: topics/strings/kmp/README.md
//   Note: practice/ladders/strings/kmp/stringmatching.md

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_function(const string &s) {
    int n = static_cast<int>(s.size());
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> find_matches(const string &text, const string &pattern) {
    string combined = pattern + "#" + text;
    vector<int> pi = prefix_function(combined);
    vector<int> pos;
    int m = static_cast<int>(pattern.size());
    for (int i = m + 1; i < static_cast<int>(combined.size()); ++i) {
        if (pi[i] == m) pos.push_back(i - 2 * m);
    }
    return pos;
}

int main() {
    vector<int> pos = find_matches("ababa", "aba");
    cout << pos.size() << '\n';
    return 0;
}
