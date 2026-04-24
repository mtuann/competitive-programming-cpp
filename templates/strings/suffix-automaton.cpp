// Use: one fixed base string, all substrings matter, and you want state-based aggregation.
// Invariant: each state is one endpos class; len/link delimit the represented substring-length interval.
// Complexity: O(n * alphabet) with fixed-array transitions, O(n) states.

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct SuffixAutomaton {
    struct State {
        int len = 0;
        int link = -1;
        long long occ = 0;
        array<int, 26> next{};

        State() { next.fill(-1); }
    };

    vector<State> st = {State()};
    int last = 0;

    void extend(char ch) {
        int c = ch - 'a';
        int cur = static_cast<int>(st.size());
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        st[cur].occ = 1;

        int p = last;
        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = static_cast<int>(st.size());
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                st[clone].occ = 0;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = clone;
                st[cur].link = clone;
            }
        }

        last = cur;
    }

    void build(const string &s) {
        for (char ch : s) {
            extend(ch);
        }
    }

    long long distinct_substrings() const {
        long long answer = 0;
        for (int v = 1; v < static_cast<int>(st.size()); ++v) {
            answer += st[v].len - st[st[v].link].len;
        }
        return answer;
    }
};

int main() {
    SuffixAutomaton sam;
    sam.build("abaa");
    cout << sam.distinct_substrings() << '\n';
    return 0;
}
