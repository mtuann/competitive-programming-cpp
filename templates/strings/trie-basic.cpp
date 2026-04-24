// Template: lowercase trie
// Signal: many words with shared-prefix transitions.
// Assumes: alphabet is lowercase `a`-`z` and prefix traversal is more important than lexicographic order alone.
// Exposes: Trie with insert(s), contains(s), and node counters end_count / pass_count.
// Complexity: O(total inserted length) build and O(|s|) query.
// Main trap: forgetting whether pass_count should be updated at the root as well as along the path.
// Links:
//   Topic: topics/strings/trie/README.md
//   Note: practice/ladders/strings/trie/wordcombinations.md

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        array<int, 26> next{};
        int end_count = 0;
        int pass_count = 0;
        Node() { next.fill(-1); }
    };

    vector<Node> nodes = {Node()};

    void insert(const string &s) {
        int cur = 0;
        nodes[cur].pass_count++;
        for (char ch : s) {
            int c = ch - 'a';
            if (nodes[cur].next[c] == -1) {
                nodes[cur].next[c] = static_cast<int>(nodes.size());
                nodes.push_back(Node());
            }
            cur = nodes[cur].next[c];
            nodes[cur].pass_count++;
        }
        nodes[cur].end_count++;
    }
};

int main() {
    Trie trie;
    trie.insert("cat");
    trie.insert("car");
    cout << trie.nodes[0].pass_count << '\n';
    return 0;
}
