#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Eertree {
    struct Node {
        array<int, 26> next;
        int len = 0;
        int link = 0;

        explicit Node(int palindrome_len = 0) : len(palindrome_len) {
            next.fill(-1);
        }
    };

    vector<Node> tree = {Node(-1), Node(0)};
    string s;
    int last = 1;

    Eertree() {
        tree[0].link = 0;
        tree[1].link = 0;
    }

    int get_link(int v, int pos) const {
        while (true) {
            int cur_len = tree[v].len;
            if (pos - 1 - cur_len >= 0 && s[pos - 1 - cur_len] == s[pos]) {
                return v;
            }
            v = tree[v].link;
        }
    }

    void add_char(char c) {
        s.push_back(c);
        int pos = static_cast<int>(s.size()) - 1;
        int x = c - 'a';

        int cur = get_link(last, pos);
        if (tree[cur].next[x] != -1) {
            last = tree[cur].next[x];
            return;
        }

        int now = static_cast<int>(tree.size());
        tree.push_back(Node(tree[cur].len + 2));
        tree[cur].next[x] = now;

        if (tree[now].len == 1) {
            tree[now].link = 1;
        } else {
            int link_parent = get_link(tree[cur].link, pos);
            tree[now].link = tree[link_parent].next[x];
        }

        last = now;
    }

    int distinct_count() const {
        return static_cast<int>(tree.size()) - 2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    Eertree ert;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        ert.add_char(s[i]);
        if (i) {
            cout << ' ';
        }
        cout << ert.distinct_count();
    }
    cout << '\n';
    return 0;
}
