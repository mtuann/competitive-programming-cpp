// Problem: Cut and Paste
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2072
// Topic: implicit treap, split/merge sequence surgery, subtree size as position
// Idea: represent the string as an implicit treap. Each operation cuts one
// interval [a-1, b) via two splits, then pastes it to the end via two merges.

#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

struct ImplicitTreap {
    struct Node {
        char value = 0;
        uint32_t prior = 0;
        int size = 1;
        int left = -1;
        int right = -1;
    };

    int root = -1;
    vector<Node> nodes;
    mt19937 rng{712367821u};

    void build(const string& s) {
        root = -1;
        nodes.clear();
        for (char c : s) {
            root = merge(root, make_node(c));
        }
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
    int size(int v) const {
        return v == -1 ? 0 : nodes[v].size;
    }

    int make_node(char c) {
        nodes.push_back(Node());
        int id = static_cast<int>(nodes.size()) - 1;
        nodes[id].value = c;
        nodes[id].prior = rng();
        return id;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    ImplicitTreap treap;
    treap.build(s);

    while (m--) {
        int a, b;
        cin >> a >> b;
        treap.cut_paste_to_end(a - 1, b);
    }

    cout << treap.to_string() << '\n';
    return 0;
}
