# Regex Membership

- Title: `Regex Membership`
- Judge / source: `Canonical Thompson-NFA benchmark`
- Original URL: [https://algs4.cs.princeton.edu/54regexp/](https://algs4.cs.princeton.edu/54regexp/)
- Secondary topics: `Thompson construction`, `Epsilon closure`, `Active-state-set simulation`
- Difficulty: `medium`
- Subtype: `Full-string regex membership under a small Thompson syntax`
- Status: `solved`
- Solution file: [regexmembership.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/regex-finite-automata/regexmembership.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Regular Expressions / Finite Automata`.

The benchmark is intentionally canonical:

- one regex
- one text
- one `1/0` full-match answer

So the hard part is exactly the lane itself:

- make concatenation explicit
- compile to Thompson NFA
- simulate the active state set under epsilon closure

## Recognition Cue

Reach for the regex-automaton worldview when:

- the pattern itself contains structure like `|` or `*`
- the real object is a small regular language, not one literal string
- you want the classical NFA route from Algorithms 4/e

The strongest smell is:

- "I want a canonical regex full-membership benchmark"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** want:

- KMP, because the pattern is not one literal string
- Aho-Corasick, because the automaton is not built from many literal patterns
- `std::regex`, because the lesson is not library syntax or engine behavior

The clean route is:

1. insert explicit concatenation operators
2. convert the regex to postfix
3. run Thompson construction to build one epsilon-NFA
4. simulate the text by repeated epsilon-closure + character transition steps
5. accept iff the final closure contains the match state

That is exactly the first regex / finite-automata route.

## Core Idea

The useful monotone fact is:

- after reading any prefix of the text, the only thing that matters is the set of NFA states reachable after that prefix

So the algorithm never has to backtrack over parse choices manually.
It only advances one reachable-state frontier.

That is the whole Thompson lesson.

## Complexity

With regex length `m` and text length `n`:

- build: `O(m)`
- match: `O(mn)`
- memory: `O(m)`

The point of this benchmark is not to mimic industrial regex engines.
The point is:

- regex as automaton
- exact supported syntax
- explicit state-set simulation

## Input / Output Contract For This Repo

This repo's canonical benchmark uses:

- one integer `q`
- then for each query:
  - one line containing regex `r`
  - one line containing text `t`

The solution prints:

- `1` if `t` fully matches `r`
- `0` otherwise

Supported metacharacters are exactly:

- `(`
- `)`
- `|`
- `*`
- `.`

Everything else is treated as a literal.

## Pitfalls / Judge Notes

- This route is full-string membership, not grep-style substring matching.
- The starter does not try to emulate Java / PCRE escaping or advanced operators.
- Epsilon-closure is required at the start and after every character step.
- `.` is wildcard in the regex, not a literal dot.

## Reusable Pattern

- Topic page: [Regular Expressions / Finite Automata](../../../../topics/strings/regex-finite-automata/README.md)
- Practice ladder: [Regex / Finite Automata ladder](README.md)
- Starter template: [regex-thompson-nfa.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/regex-thompson-nfa.cpp)
- Notebook refresher: [Regex / Finite Automata hot sheet](../../../../notebook/regex-finite-automata-hot-sheet.md)
- Compare points:
  - [KMP](../../../../topics/strings/kmp/README.md)
  - [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md)
  - [Suffix Automaton](../../../../topics/strings/suffix-automaton/README.md)
- This note adds: the canonical full-string Thompson-NFA route before grep-style substring wrappers or richer regex syntax.

## Solutions

- Code: [regexmembership.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/regex-finite-automata/regexmembership.cpp)
