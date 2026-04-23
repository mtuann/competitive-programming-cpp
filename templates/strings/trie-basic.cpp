// Template: lowercase trie.

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
