// Template: Aho-Corasick automaton for lowercase strings.

#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct AhoCorasick {
    struct Node {
        array<int, 26> next{};
        int link = 0;
        int out = 0;
        Node() { next.fill(-1); }
    };

    vector<Node> trie = {Node()};

    void add_word(const string &s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = static_cast<int>(trie.size());
                trie.push_back(Node());
            }
            v = trie[v].next[c];
        }
        trie[v].out++;
    }

    void build() {
        queue<int> q;
        for (int c = 0; c < 26; ++c) {
            int u = trie[0].next[c];
            if (u != -1) {
                trie[u].link = 0;
                q.push(u);
            } else {
                trie[0].next[c] = 0;
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            trie[v].out += trie[trie[v].link].out;
            for (int c = 0; c < 26; ++c) {
                int u = trie[v].next[c];
                if (u != -1) {
                    trie[u].link = trie[trie[v].link].next[c];
                    q.push(u);
                } else {
                    trie[v].next[c] = trie[trie[v].link].next[c];
                }
            }
        }
    }
};

int main() {
    AhoCorasick ac;
    ac.add_word("he");
    ac.add_word("she");
    ac.build();
    cout << ac.trie.size() << '\n';
    return 0;
}
