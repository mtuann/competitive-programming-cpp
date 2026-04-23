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

        Node() {
            next.fill(-1);
        }
    };

    vector<Node> trie = {Node()};
    vector<int> bfs_order;

    int add_word(const string &s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = static_cast<int>(trie.size());
                trie.push_back(Node());
            }
            v = trie[v].next[c];
        }
        return v;
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
            bfs_order.push_back(v);

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    int k;
    cin >> text >> k;

    AhoCorasick ac;
    vector<int> terminal(k);
    for (int i = 0; i < k; ++i) {
        string pattern;
        cin >> pattern;
        terminal[i] = ac.add_word(pattern);
    }

    ac.build();

    vector<int> visits(ac.trie.size(), 0);
    int state = 0;
    for (char ch : text) {
        state = ac.trie[state].next[ch - 'a'];
        ++visits[state];
    }

    for (int i = static_cast<int>(ac.bfs_order.size()) - 1; i >= 0; --i) {
        int v = ac.bfs_order[i];
        visits[ac.trie[v].link] += visits[v];
    }

    for (int i = 0; i < k; ++i) {
        cout << (visits[terminal[i]] > 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
