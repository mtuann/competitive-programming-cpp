// Template: Regex Thompson NFA
// Signal: one small regex language where full-string membership is the real
// task, not one literal pattern or many fixed dictionary patterns.
// Supports: literals, implicit concatenation, '|', '*', parentheses, '.'.
// Exposes: RegexNFA with matches(text).
// Complexity: build O(m), match O(mn).
// Main trap: this is a tiny Thompson-syntax engine, not std::regex / PCRE.
// Links:
//   Topic: topics/strings/regex-finite-automata/README.md
//   Note: practice/ladders/strings/regex-finite-automata/regexmembership.md

#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct RegexNFA {
    struct State {
        enum Type { CHAR, SPLIT, MATCH } type = CHAR;
        char ch = 0;
        int out1 = -1;
        int out2 = -1;
    };

    struct Fragment {
        int start = -1;
        vector<pair<int, int>> outs;
    };

    vector<State> states;
    int start_state = -1;
    int match_state = -1;

    explicit RegexNFA(const string& regexp) { build(regexp); }

    bool matches(const string& text) const {
        vector<int> current;
        vector<char> seen(states.size(), 0);
        add_state(start_state, current, seen);
        for (char c : text) {
            vector<int> next;
            vector<char> next_seen(states.size(), 0);
            for (int id : current) {
                const State& s = states[id];
                if (s.type == State::CHAR && (s.ch == '.' || s.ch == c)) {
                    add_state(s.out1, next, next_seen);
                }
            }
            current.swap(next);
        }
        for (int id : current) {
            if (states[id].type == State::MATCH) {
                return true;
            }
        }
        return false;
    }

private:
    static bool is_atom(char c) {
        return c != '(' && c != ')' && c != '|' && c != '*' && c != '&';
    }

    static int precedence(char op) {
        if (op == '|') {
            return 1;
        }
        if (op == '&') {
            return 2;
        }
        return -1;
    }

    static string add_concat(const string& re) {
        string out;
        for (int i = 0; i < (int)re.size(); i++) {
            char c = re[i];
            out.push_back(c);
            if (i + 1 == (int)re.size()) {
                continue;
            }
            char d = re[i + 1];
            bool left = is_atom(c) || c == ')' || c == '*';
            bool right = is_atom(d) || d == '(';
            if (left && right) {
                out.push_back('&');
            }
        }
        return out;
    }

    static string to_postfix(const string& re) {
        string with_concat = add_concat(re);
        string out;
        vector<char> ops;
        for (char c : with_concat) {
            if (is_atom(c)) {
                out.push_back(c);
            } else if (c == '(') {
                ops.push_back(c);
            } else if (c == ')') {
                while (!ops.empty() && ops.back() != '(') {
                    out.push_back(ops.back());
                    ops.pop_back();
                }
                if (!ops.empty() && ops.back() == '(') {
                    ops.pop_back();
                }
            } else if (c == '*') {
                out.push_back(c);
            } else {
                while (!ops.empty() && ops.back() != '(' &&
                       precedence(ops.back()) >= precedence(c)) {
                    out.push_back(ops.back());
                    ops.pop_back();
                }
                ops.push_back(c);
            }
        }
        while (!ops.empty()) {
            out.push_back(ops.back());
            ops.pop_back();
        }
        return out;
    }

    int new_state(State::Type type, char ch = 0, int out1 = -1, int out2 = -1) {
        states.push_back(State{type, ch, out1, out2});
        return (int)states.size() - 1;
    }

    void patch(const vector<pair<int, int>>& outs, int target) {
        for (auto [id, slot] : outs) {
            if (slot == 1) {
                states[id].out1 = target;
            } else {
                states[id].out2 = target;
            }
        }
    }

    static vector<pair<int, int>> append_outs(vector<pair<int, int>> a,
                                              const vector<pair<int, int>>& b) {
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }

    void build(const string& regexp) {
        string postfix = to_postfix(regexp);
        if (postfix.empty()) {
            match_state = new_state(State::MATCH);
            start_state = match_state;
            return;
        }

        vector<Fragment> st;
        for (char c : postfix) {
            if (is_atom(c)) {
                int id = new_state(State::CHAR, c, -1, -1);
                st.push_back(Fragment{id, {{id, 1}}});
            } else if (c == '&') {
                Fragment b = st.back();
                st.pop_back();
                Fragment a = st.back();
                st.pop_back();
                patch(a.outs, b.start);
                st.push_back(Fragment{a.start, b.outs});
            } else if (c == '|') {
                Fragment b = st.back();
                st.pop_back();
                Fragment a = st.back();
                st.pop_back();
                int id = new_state(State::SPLIT, 0, a.start, b.start);
                st.push_back(Fragment{id, append_outs(a.outs, b.outs)});
            } else if (c == '*') {
                Fragment a = st.back();
                st.pop_back();
                int id = new_state(State::SPLIT, 0, a.start, -1);
                patch(a.outs, id);
                st.push_back(Fragment{id, {{id, 2}}});
            }
        }

        Fragment result = st.back();
        st.pop_back();
        match_state = new_state(State::MATCH);
        patch(result.outs, match_state);
        start_state = result.start;
    }

    void add_state(int id, vector<int>& dst, vector<char>& seen) const {
        if (id == -1 || seen[id]) {
            return;
        }
        seen[id] = 1;
        const State& s = states[id];
        if (s.type == State::SPLIT) {
            add_state(s.out1, dst, seen);
            add_state(s.out2, dst, seen);
        } else {
            dst.push_back(id);
        }
    }
};

int main() {
    RegexNFA nfa("a*b");
    cout << nfa.matches("aaab") << '\n';
    cout << nfa.matches("aba") << '\n';
    RegexNFA nfa2("(a|b)*c");
    cout << nfa2.matches("ababc") << '\n';
    return 0;
}
