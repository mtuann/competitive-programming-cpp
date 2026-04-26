# Regular Expressions / Finite Automata

This lane is for the moment string matching stops being about:

- one fixed literal pattern
- or many fixed dictionary patterns

and becomes about:

- **a pattern language**
- Thompson-style epsilon automata
- and matching by simulating a nondeterministic state set instead of backtracking by hand

The repo's exact first route for this family is:

- starter -> [regex-thompson-nfa.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/regex-thompson-nfa.cpp)
- flagship note -> [Regex Membership](../../../practice/ladders/strings/regex-finite-automata/regexmembership.md)
- compare point -> [KMP](../kmp/README.md)
- compare point -> [Aho-Corasick](../aho-corasick/README.md)
- compare point -> [Suffix Automaton](../suffix-automaton/README.md)

This lane intentionally teaches the **full-string membership route first** for a small regex syntax:

- literal characters
- concatenation
- `|`
- `*`
- parentheses
- `.`

It does **not** start from:

- backreferences
- capture groups
- lazy quantifiers
- escaping rules of one industrial regex library
- or DFA minimization

## At A Glance

- **Use when:** the pattern itself is a small regular language, not one fixed literal string
- **Core worldview:** compile the regex into one epsilon-NFA, then scan the text by maintaining the reachable state set
- **Main tools:** infix-to-postfix conversion with implicit concatenation, Thompson construction, epsilon-closure, and per-character NFA simulation
- **Typical complexity:** build in `O(m)`, simulate one text of length `n` in `O(mn)` where `m` is regex length
- **Main trap:** confusing this lane with industrial regex libraries or with exact fixed-pattern tools that are much simpler

Strong study signals:

- "the pattern contains `|` or `*`, so the pattern is now a language"
- "I want the classical regex-as-NFA story from Algorithms 4/e"
- "the point is to understand automaton simulation, not to call `std::regex`"

Strong anti-cues:

- there is only one literal pattern -> [KMP](../kmp/README.md) or [Z-Function](../z-function/README.md)
- there are many fixed patterns against one text -> [Aho-Corasick](../aho-corasick/README.md)
- the real problem is all substrings of one base string -> [Suffix Automaton](../suffix-automaton/README.md) or [Suffix Tree](../suffix-tree/README.md)
- the task expects PCRE-style features, captures, or backreferences

## Prerequisites

- [KMP](../kmp/README.md), because you should already know what "one fixed exact pattern" feels like before upgrading to a pattern language
- [Trie](../trie/README.md) helps as a structural compare point, because automata are still states plus labeled transitions
- [Aho-Corasick](../aho-corasick/README.md) helps as a compare note, because it is the exact-matching automaton route for many fixed patterns

Helpful compare points:

- [KMP](../kmp/README.md): use this when the pattern is one literal string and exact matching is all you need
- [Aho-Corasick](../aho-corasick/README.md): use this when many literal patterns are known first
- [Suffix Automaton](../suffix-automaton/README.md): use this when one base string generates the automaton, not one regex
- [String Hashing](../hashing/README.md): not a fit when exact language membership is the point

## Problem Model And Syntax Contract

The canonical task in this lane is:

- given regex `R`
- given text `T`
- decide whether `T` matches `R` **fully**

The repo starter gives special meaning only to:

- `(` and `)`
- `|`
- `*`
- `.`

Everything else is treated as a literal character.

The starter semantics are:

- implicit concatenation
- `*` applies to the previous atom or parenthesized group
- `.` matches any single character
- the whole text must match the whole regex

So this lane is **not** teaching the syntax contract of Java / PCRE / Python regex libraries.

## From Literal Matching To Regular-Language Matching

### One Literal Pattern

With KMP or Z, the pattern is one fixed string.

That means:

- every next transition is determined by characters already matched
- there is no branching from `|`
- there is no repetition operator creating many possible parse lengths

### What Changes With Regex

The moment the pattern contains:

- alternation like `a|bc`
- repetition like `(ab)*`

the pattern is no longer one string.
It is one **set of strings**.

That is why direct prefix-function style matching is no longer the natural lens.

### The Thompson Pivot

Instead of backtracking over all choices manually:

1. compile the regex into an epsilon-NFA
2. keep the current epsilon-closed state set
3. consume the text left to right

This converts:

- "which parse branch should I try next?"

into:

- "which NFA states are reachable after this prefix?"

That is the core mental upgrade of this lane.

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. Postfix Form Makes Concatenation Explicit

Before building the automaton:

- implicit concatenation is inserted explicitly
- the regex is converted to postfix

That is what makes Thompson construction local and stack-based.

### 2. Every Fragment Represents One Regex Subexpression

During Thompson construction, each fragment means:

- one start state
- one list of still-unpatched exits

That is why `concat`, `|`, and `*` can be assembled cleanly without global rewrites.

### 3. Epsilon-Closure Must Be Complete

At every text position, the active state set is not just the states reached by characters.
It must also include everything reachable through epsilon transitions.

Missing this closure is the classic bug that makes correct regexes fail spuriously.

### 4. Match Means Reach The Final Accept State After The Full Text

This starter teaches **full-string membership**.

So success means:

- after consuming all characters of `T`
- the epsilon-closed active set contains the accept state

This is different from "find a substring match somewhere inside the line."

## Complexity And Tradeoffs

With regex length `m` and text length `n`:

- construction: `O(m)`
- simulation of one text: `O(mn)`
- memory: `O(m)`

Rule of thumb:

- one literal pattern -> [KMP](../kmp/README.md)
- many literal patterns -> [Aho-Corasick](../aho-corasick/README.md)
- one regex language with Thompson syntax -> this lane

## Worked Examples

### Example 1: Repo Canonical Benchmark

This repo's flagship note:

- [Regex Membership](../../../practice/ladders/strings/regex-finite-automata/regexmembership.md)

The benchmark is intentionally canonical:

- input one regex
- input one text
- answer `1/0` for full match

So the whole focus is:

- parse to postfix
- build epsilon-NFA
- simulate the active state set

### Example 2: Why This Is Not KMP First

If the task is:

- text `T`
- literal pattern `P`
- count or locate exact occurrences

then the regex language view is unnecessary overhead.

That is:

- [KMP](../kmp/README.md)

### Example 3: Why This Is Not Aho-Corasick First

If the task is:

- one text
- many literal patterns

then the natural automaton is built from the **dictionary**, not from one regex expression.

That is:

- [Aho-Corasick](../aho-corasick/README.md)

## Repo Starter Contract

The starter:

- compiles one regex into one epsilon-NFA
- supports the Thompson-style syntax listed above
- answers one full-string membership query

It does **not** advertise:

- substring matching by implicit `.*`
- backreferences
- captures
- escapes
- industrial regex compatibility

## Main Traps

- forgetting that this lane is about a small explicit regex syntax, not library regex behavior
- trying to use backtracking reasoning instead of state-set simulation
- missing epsilon-closure transitions
- choosing this route when one literal exact matcher already solves the task

## Reopen Paths

- quick recall -> [Regex / Finite Automata hot sheet](../../../notebook/regex-finite-automata-hot-sheet.md)
- one exact literal pattern -> [KMP](../kmp/README.md)
- many literal patterns -> [Aho-Corasick](../aho-corasick/README.md)
- one base string as an automaton -> [Suffix Automaton](../suffix-automaton/README.md)
