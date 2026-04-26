# Regex / Finite Automata Hot Sheet

Use this page when the pattern is a small regular language and the right worldview is "compile to one epsilon-NFA and simulate reachable states," not "run one exact string matcher."

## Do Not Use When

- the pattern is one literal string -> reopen [KMP](../topics/strings/kmp/README.md)
- there are many literal patterns against one text -> [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md)
- the task expects industrial regex features, escapes, captures, or backreferences

## Choose By Signal

- one literal pattern in one text -> `KMP` or `Z`
- many literal patterns in one text -> `Aho-Corasick`
- one regex language with `|`, `*`, parentheses, and wildcard `.` -> `Thompson NFA`

## Core Invariants

- implicit concatenation is made explicit before building the automaton
- Thompson fragments mean `start + unpatched exits`
- every simulation step uses full epsilon-closure
- full-string match means the accept state is reachable after the whole text

## Main Traps

- confusing this lane with regex-library semantics
- forgetting that `.` is wildcard and every other unsupported metachar is just a literal in the starter
- trying to use this when one exact fixed-pattern route is already enough

## Exact Starter Route

- exact starter -> [`regex-thompson-nfa.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/regex-thompson-nfa.cpp)
- flagship rep -> [Regex Membership](../practice/ladders/strings/regex-finite-automata/regexmembership.md)
- compare route -> [KMP](../topics/strings/kmp/README.md)
- compare route -> [Aho-Corasick](../topics/strings/aho-corasick/README.md)

## Reopen Paths

- full lesson -> [Regular Expressions / Finite Automata](../topics/strings/regex-finite-automata/README.md)
- many fixed patterns -> [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md)
- one base-string automaton instead of one regex automaton -> [Suffix Automaton](../topics/strings/suffix-automaton/README.md)
- broader chooser -> [String cheatsheet](string-cheatsheet.md)
