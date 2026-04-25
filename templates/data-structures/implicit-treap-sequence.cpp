// Template: implicit treap (sequence surgery)
// Signal: one mutable sequence needs cut/paste, insert/erase by position, or
// split/merge sequence edits where explicit indices would shift too often.
// Assumes: zero-based positions; sequence payload is char in this exact starter;
// split(root, k) means first k elements vs the rest; no range aggregates or
// lazy tags are included here.
// Exposes: ImplicitTreapSequence with build(string), insert(), erase(),
// cut_paste_to_end(), and to_string().
// Complexity: expected O(log n) per split/merge/insert/erase/cut-paste.
// Main trap: forgetting that implicit positions come from subtree sizes, not
// stored node indices.
// Links:
//   Topic: topics/data-structures/treap-implicit/README.md
//   Note: practice/ladders/data-structures/treap-implicit/cutandpaste.md

#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

struct ImplicitTreapSequence {
    struct Node {
        char value = 0;
        uint32_t prior = 0;
        int size = 1;
        int left = -1;
        int right = -1;
    };

    int root = -1;
    vector<Node> nodes;
    mt19937 rng;

    ImplicitTreapSequence() : rng(712367821u) {}

    explicit ImplicitTreapSequence(const string& s) : rng(712367821u) {
        build(s);
    }

    void build(const string& s) {
        root = -1;
        nodes.clear();
        for (char c : s) {
            root = merge(root, make_node(c));
        }
    }

    void insert(int pos, char c) {
        int a, b;
        split(root, pos, a, b);
        root = merge(merge(a, make_node(c)), b);
    }

    void erase(int pos) {
        int a, bc, b, c;
        split(root, pos, a, bc);
        split(bc, 1, b, c);
        root = merge(a, c);
    }

    void cut_paste_to_end(int l, int r) {
        int a, bc, b, c;
        split(root, l, a, bc);
        split(bc, r - l, b, c);
        root = merge(merge(a, c), b);
    }

    string to_string() const {
        string out;
        out.reserve(size(root));
        dfs(root, out);
        return out;
    }

private:
    int make_node(char c) {
        nodes.push_back(Node());
        int id = static_cast<int>(nodes.size()) - 1;
        nodes[id].value = c;
        nodes[id].prior = rng();
        return id;
    }

    int size(int v) const {
        return v == -1 ? 0 : nodes[v].size;
    }

    void pull(int v) {
        if (v == -1) {
            return;
        }
        nodes[v].size = 1 + size(nodes[v].left) + size(nodes[v].right);
    }

    int merge(int a, int b) {
        if (a == -1 || b == -1) {
            return a == -1 ? b : a;
        }
        if (nodes[a].prior > nodes[b].prior) {
            nodes[a].right = merge(nodes[a].right, b);
            pull(a);
            return a;
        }
        nodes[b].left = merge(a, nodes[b].left);
        pull(b);
        return b;
    }

    void split(int v, int k, int& a, int& b) {
        if (v == -1) {
            a = b = -1;
            return;
        }
        int left_size = size(nodes[v].left);
        if (k <= left_size) {
            split(nodes[v].left, k, a, nodes[v].left);
            b = v;
            pull(b);
        } else {
            split(nodes[v].right, k - left_size - 1, nodes[v].right, b);
            a = v;
            pull(a);
        }
    }

    void dfs(int v, string& out) const {
        if (v == -1) {
            return;
        }
        dfs(nodes[v].left, out);
        out.push_back(nodes[v].value);
        dfs(nodes[v].right, out);
    }
};

int main() {
    ImplicitTreapSequence treap("AYBABTU");
    treap.cut_paste_to_end(2, 5);
    cout << treap.to_string() << '\n';
    treap.insert(1, 'X');
    treap.erase(3);
    cout << treap.to_string() << '\n';
    return 0;
}
