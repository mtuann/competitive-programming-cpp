// Template: Eertree / Palindromic Tree
// Signal: one lowercase string is built left to right, and the task needs
// distinct palindromic substrings, longest palindromic suffixes, or one node
// per distinct palindrome.
// Assumes: lowercase English letters; the string is append-only in the exact
// starter route here.
// Exposes: Eertree with add_char(), build(), distinct_palindrome_count(),
// longest_suffix_length(), and prefix_distinct_counts().
// Complexity: O(n) total to build one string in the ordinary contest lane.
// Main trap: breaking the two-root setup or confusing "existing transition"
// with "must create a new palindrome node".
// Links:
//   Topic: topics/strings/eertree/README.md
//   Note: practice/ladders/strings/eertree/distinctpalindromicsubstrings.md

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Eertree {
    static constexpr int ALPHABET = 26;

    struct Node {
        array<int, ALPHABET> next;
        int len = 0;
        int link = 0;
        int occ = 0;
        int first_pos = -1;

        explicit Node(int palindrome_len = 0) : len(palindrome_len) {
            next.fill(-1);
        }
    };

    vector<Node> tree;
    string s;
    int last = 1;

    Eertree() {
        init();
    }

    void init() {
        tree.clear();
        tree.push_back(Node(-1));  // odd root
        tree.push_back(Node(0));   // even root
        tree[0].link = 0;
        tree[1].link = 0;
        s.clear();
        last = 1;
    }

    static int letter_id(char c) {
        return c - 'a';
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

    bool add_char(char c) {
        s.push_back(c);
        int pos = static_cast<int>(s.size()) - 1;
        int x = letter_id(c);

        int cur = get_link(last, pos);
        if (tree[cur].next[x] != -1) {
            last = tree[cur].next[x];
            ++tree[last].occ;
            return false;
        }

        int now = static_cast<int>(tree.size());
        tree.push_back(Node(tree[cur].len + 2));
        tree[now].occ = 1;
        tree[now].first_pos = pos;
        tree[cur].next[x] = now;

        if (tree[now].len == 1) {
            tree[now].link = 1;
        } else {
            int link_parent = get_link(tree[cur].link, pos);
            tree[now].link = tree[link_parent].next[x];
        }

        last = now;
        return true;
    }

    void build(const string& t) {
        init();
        for (char c : t) {
            add_char(c);
        }
    }

    int distinct_palindrome_count() const {
        return static_cast<int>(tree.size()) - 2;
    }

    int longest_suffix_length() const {
        return tree[last].len;
    }

    vector<int> prefix_distinct_counts(const string& t) {
        init();
        vector<int> ans;
        ans.reserve(t.size());
        for (char c : t) {
            add_char(c);
            ans.push_back(distinct_palindrome_count());
        }
        return ans;
    }
};

int main() {
    Eertree ert;
    vector<int> prefix_counts = ert.prefix_distinct_counts("ababa");
    for (int i = 0; i < static_cast<int>(prefix_counts.size()); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << prefix_counts[i];
    }
    cout << '\n';
    cout << ert.longest_suffix_length() << '\n';
    return 0;
}
