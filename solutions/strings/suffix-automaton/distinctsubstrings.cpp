// Problem: Distinct Substrings
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2105
// Topic: suffix automaton
// Idea: each non-root SAM state v represents substring lengths in
// (len(link[v]), len[v]], so it contributes len[v] - len(link[v])
// distinct substrings. Build the automaton online and sum these values.

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct SuffixAutomaton {
    struct State {
        array<int, 26> next{};
        int link = -1;
        int len = 0;

        State() {
            next.fill(-1);
        }
    };

    vector<State> states;
    int last = 0;

    explicit SuffixAutomaton(int max_length = 0) {
        states.reserve(max_length > 0 ? 2 * max_length : 1);
        states.push_back(State());
    }

    void extend(char ch) {
        int c = static_cast<int>(ch - 'a');
        int cur = static_cast<int>(states.size());
        states.push_back(State());
        states[cur].len = states[last].len + 1;

        int p = last;
        while (p != -1 && states[p].next[c] == -1) {
            states[p].next[c] = cur;
            p = states[p].link;
        }

        if (p == -1) {
            states[cur].link = 0;
        } else {
            int q = states[p].next[c];
            if (states[p].len + 1 == states[q].len) {
                states[cur].link = q;
            } else {
                int clone = static_cast<int>(states.size());
                states.push_back(states[q]);
                states[clone].len = states[p].len + 1;

                while (p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone;
                    p = states[p].link;
                }

                states[q].link = clone;
                states[cur].link = clone;
            }
        }

        last = cur;
    }

    long long count_distinct_substrings() const {
        long long total = 0;
        for (int v = 1; v < static_cast<int>(states.size()); ++v) {
            total += static_cast<long long>(states[v].len - states[states[v].link].len);
        }
        return total;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    SuffixAutomaton sam(static_cast<int>(s.size()));
    for (char ch : s) {
        sam.extend(ch);
    }

    cout << sam.count_distinct_substrings() << '\n';
    return 0;
}
