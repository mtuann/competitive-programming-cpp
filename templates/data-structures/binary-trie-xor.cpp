// Template: Binary Trie / XOR Queries
// Signal: dynamic insert / erase-one / best-xor query over one multiset of
// non-negative integers under one fixed bit width.
// Assumes: every stored value and query uses the same max_bit convention;
// counts, not physical node deletion, define whether a branch is alive.
// Exposes: BinaryTrieXor with insert(), erase_one(), count_value(), empty(),
// and max_xor_value() for the ordinary multiset maximum-xor lane.
// Complexity: O(max_bit + 1) per insert, erase, count, or max-xor query.
// Main trap: mixing bit widths across operations or querying an empty trie.
// Links:
//   Topic: topics/data-structures/binary-trie-xor/README.md
//   Note: practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md

#include <array>
#include <iostream>
#include <vector>

using namespace std;

struct BinaryTrieXor {
    struct Node {
        array<int, 2> child = {-1, -1};
        int cnt = 0;
    };

    int max_bit;
    vector<Node> trie;

    explicit BinaryTrieXor(int max_bit = 30) : max_bit(max_bit), trie(1) {}

    bool empty() const {
        return trie[0].cnt == 0;
    }

    void insert(int x) {
        int v = 0;
        ++trie[v].cnt;
        for (int bit = max_bit; bit >= 0; --bit) {
            int b = (x >> bit) & 1;
            if (trie[v].child[b] == -1) {
                trie[v].child[b] = static_cast<int>(trie.size());
                trie.push_back(Node());
            }
            v = trie[v].child[b];
            ++trie[v].cnt;
        }
    }

    int count_value(int x) const {
        int v = 0;
        for (int bit = max_bit; bit >= 0; --bit) {
            int b = (x >> bit) & 1;
            int to = trie[v].child[b];
            if (to == -1 || trie[to].cnt == 0) {
                return 0;
            }
            v = to;
        }
        return trie[v].cnt;
    }

    bool erase_one(int x) {
        vector<int> path = {0};
        int v = 0;
        for (int bit = max_bit; bit >= 0; --bit) {
            int b = (x >> bit) & 1;
            int to = trie[v].child[b];
            if (to == -1 || trie[to].cnt == 0) {
                return false;
            }
            v = to;
            path.push_back(v);
        }
        for (int idx : path) {
            --trie[idx].cnt;
        }
        return true;
    }

    int max_xor_value(int x) const {
        if (empty()) {
            return -1;
        }
        int v = 0;
        int ans = 0;
        for (int bit = max_bit; bit >= 0; --bit) {
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
    BinaryTrieXor trie(4);
    trie.insert(0);
    trie.insert(5);
    trie.insert(10);

    cout << trie.max_xor_value(7) << '\n';
    trie.erase_one(10);
    cout << trie.max_xor_value(7) << '\n';
    return 0;
}
