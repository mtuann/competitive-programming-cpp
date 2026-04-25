// Template: suffix tree
// Signal: one static lowercase text should behave like a compressed substring index for existence or earliest-occurrence queries.
// Assumes: text and patterns use lowercase `a-z`; build(text) appends a unique terminator internally.
// Exposes: SuffixTree with build(text), contains(pattern), first_position(pattern), and distinct_substrings().
// Complexity: O(n * alphabet) build with fixed-array transitions, O(m) per query.
// Main trap: pattern matching can finish in the middle of a compressed edge, while the answer still comes from that child subtree's metadata.
// Links:
//   Topic: topics/strings/suffix-tree/README.md
//   Note: practice/ladders/strings/suffix-tree/patternpositions.md

#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct SuffixTree {
    struct Node {
        int l = 0;
        int r = 0;
        int par = -1;
        int link = -1;
        int min_start = numeric_limits<int>::max();
        array<int, 27> next{};

        Node() { next.fill(-1); }

        Node(int l_, int r_, int par_) : l(l_), r(r_), par(par_) { next.fill(-1); }

        int len() const { return r - l; }
    };

    struct State {
        int v = 0;
        int pos = 0;
    };

    string s;
    int n = 0;
    int original_n = 0;
    vector<Node> t;
    State ptr{0, 0};

    static constexpr int INF = numeric_limits<int>::max();

    int idx(char ch) const {
        if ('a' <= ch && ch <= 'z') return ch - 'a';
        if (ch == '{') return 26;
        return -1;
    }

    State go(State st, int l, int r) const {
        while (l < r) {
            if (st.pos == t[st.v].len()) {
                int c = idx(s[l]);
                int to = t[st.v].next[c];
                if (to == -1) return {-1, -1};
                st = {to, 0};
            } else {
                if (s[t[st.v].l + st.pos] != s[l]) return {-1, -1};
                int remain = t[st.v].len() - st.pos;
                if (r - l < remain) return {st.v, st.pos + (r - l)};
                l += remain;
                st.pos = t[st.v].len();
            }
        }
        return st;
    }

    int split(State st) {
        if (st.pos == t[st.v].len()) return st.v;
        if (st.pos == 0) return t[st.v].par;

        Node v = t[st.v];
        int id = static_cast<int>(t.size());
        t.push_back(Node(v.l, v.l + st.pos, v.par));
        t[v.par].next[idx(s[v.l])] = id;
        t[id].next[idx(s[v.l + st.pos])] = st.v;
        t[st.v].par = id;
        t[st.v].l += st.pos;
        return id;
    }

    int get_link(int v) {
        if (t[v].link != -1) return t[v].link;
        if (t[v].par == -1) return 0;
        int to = get_link(t[v].par);
        int start = t[v].l + (t[v].par == 0);
        return t[v].link = split(go({to, t[to].len()}, start, t[v].r));
    }

    void tree_extend(int pos) {
        while (true) {
            State next_ptr = go(ptr, pos, pos + 1);
            if (next_ptr.v != -1) {
                ptr = next_ptr;
                return;
            }

            int mid = split(ptr);
            int leaf = static_cast<int>(t.size());
            t.push_back(Node(pos, n, mid));
            t[mid].next[idx(s[pos])] = leaf;

            ptr.v = get_link(mid);
            ptr.pos = t[ptr.v].len();
            if (mid == 0) break;
        }
    }

    void compute_min_starts() {
        vector<vector<int>> children(t.size());
        for (int v = 1; v < static_cast<int>(t.size()); ++v) {
            children[t[v].par].push_back(v);
        }

        vector<int> depth(t.size(), 0);
        vector<pair<int, int>> stack = {{0, 0}};

        while (!stack.empty()) {
            int v = stack.back().first;
            int phase = stack.back().second;
            stack.pop_back();

            if (phase == 0) {
                stack.push_back({v, 1});
                for (int to : children[v]) {
                    depth[to] = depth[v] + t[to].len();
                    stack.push_back({to, 0});
                }
            } else {
                int best = INF;
                if (children[v].empty()) {
                    int start = n - depth[v];
                    if (start < original_n) best = start;
                } else {
                    for (int to : children[v]) {
                        best = min(best, t[to].min_start);
                    }
                }
                t[v].min_start = best;
            }
        }
    }

    void build(const string &text) {
        original_n = static_cast<int>(text.size());
        s = text + '{';
        n = static_cast<int>(s.size());
        t.assign(1, Node());
        t[0].par = -1;
        t[0].link = 0;
        ptr = {0, 0};
        for (int i = 0; i < n; ++i) {
            tree_extend(i);
        }
        compute_min_starts();
    }

    int first_position(const string &pattern) const {
        if (pattern.empty()) return 0;
        int v = 0;
        int i = 0;
        while (i < static_cast<int>(pattern.size())) {
            int c = idx(pattern[i]);
            if (c < 0 || c >= 26) return -1;
            int to = t[v].next[c];
            if (to == -1) return -1;
            v = to;
            int edge_pos = t[v].l;
            while (edge_pos < t[v].r && i < static_cast<int>(pattern.size())) {
                if (s[edge_pos] != pattern[i]) return -1;
                ++edge_pos;
                ++i;
            }
            if (i == static_cast<int>(pattern.size())) {
                return t[v].min_start == INF ? -1 : t[v].min_start;
            }
        }
        return t[v].min_start == INF ? -1 : t[v].min_start;
    }

    bool contains(const string &pattern) const { return first_position(pattern) != -1; }

    long long distinct_substrings() const {
        long long answer = 0;
        for (int v = 1; v < static_cast<int>(t.size()); ++v) {
            int usable_r = min(t[v].r, original_n);
            if (usable_r > t[v].l) answer += usable_r - t[v].l;
        }
        return answer;
    }
};

int main() {
    SuffixTree tree;
    tree.build("abaa");
    cout << tree.first_position("baa") << '\n';
    cout << tree.contains("aaa") << '\n';
    cout << tree.distinct_substrings() << '\n';
    return 0;
}
