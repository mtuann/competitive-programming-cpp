// Problem: Word Combinations
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1731
// Topic: trie, DP on strings, dictionary segmentation
// Idea: dp[i] = number of ways to split suffix s[i..]. Insert all dictionary
// words into a trie, then for each i walk forward through the trie and add
// dp[j + 1] whenever a terminal word ends at j.

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int MOD = 1'000'000'007;

struct TrieNode {
    array<int, 26> next{};
    int terminal_count = 0;

    TrieNode() {
        next.fill(-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    vector<TrieNode> trie(1);
    auto insert_word = [&](const string& word) {
        int node = 0;
        for (char ch : word) {
            int c = ch - 'a';
            if (trie[node].next[c] == -1) {
                trie[node].next[c] = static_cast<int>(trie.size());
                trie.push_back(TrieNode());
            }
            node = trie[node].next[c];
        }
        ++trie[node].terminal_count;
    };

    for (int i = 0; i < k; ++i) {
        string word;
        cin >> word;
        insert_word(word);
    }

    int n = static_cast<int>(s.size());
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        int node = 0;
        for (int j = i; j < n; ++j) {
            int c = s[j] - 'a';
            node = trie[node].next[c];
            if (node == -1) {
                break;
            }
            if (trie[node].terminal_count > 0) {
                dp[i] = (dp[i] + 1LL * trie[node].terminal_count * dp[j + 1]) % MOD;
            }
        }
    }

    cout << dp[0] << '\n';
    return 0;
}
