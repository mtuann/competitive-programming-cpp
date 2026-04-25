#include <array>
#include <iostream>
#include <vector>

using namespace std;

struct BinaryTrie {
    struct Node {
        array<int, 2> child = {-1, -1};
        int cnt = 0;
    };

    static constexpr int MAX_BIT = 30;
    vector<Node> trie = {Node()};

    void insert(int x) {
        int v = 0;
        ++trie[v].cnt;
        for (int bit = MAX_BIT; bit >= 0; --bit) {
            int b = (x >> bit) & 1;
            if (trie[v].child[b] == -1) {
                trie[v].child[b] = static_cast<int>(trie.size());
                trie.push_back(Node());
            }
            v = trie[v].child[b];
            ++trie[v].cnt;
        }
    }

    void erase_one(int x) {
        vector<int> path = {0};
        int v = 0;
        for (int bit = MAX_BIT; bit >= 0; --bit) {
            int b = (x >> bit) & 1;
            v = trie[v].child[b];
            path.push_back(v);
        }
        for (int idx : path) {
            --trie[idx].cnt;
        }
    }

    int max_xor_value(int x) const {
        int v = 0;
        int ans = 0;
        for (int bit = MAX_BIT; bit >= 0; --bit) {
            int b = (x >> bit) & 1;
            int want = b ^ 1;
            int to = trie[v].child[want];
            if (to != -1 && trie[to].cnt > 0) {
                ans |= (1 << bit);
                v = to;
            } else {
                v = trie[v].child[b];
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    BinaryTrie trie;
    trie.insert(0);

    while (q--) {
        char type;
        int x;
        cin >> type >> x;
        if (type == '+') {
            trie.insert(x);
        } else if (type == '-') {
            trie.erase_one(x);
        } else {
            cout << trie.max_xor_value(x) << '\n';
        }
    }
    return 0;
}
