# Regex / Finite Automata Ladder

This lane is for the first time one string-matching lesson is really about
**a pattern language and an automaton simulation**, not one exact literal pattern.

## Who This Is For

Use this lane if:

- you already trust exact one-pattern tools like [KMP](../../../../topics/strings/kmp/README.md)
- [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md) already makes sense as the many-literal-pattern automaton
- you now want the classical regex-to-NFA story itself

This lane is intentionally narrow:

- one exact starter
- one flagship note built around a canonical full-match benchmark
- one compare route against [KMP](../../../../topics/strings/kmp/README.md)
- one compare route against [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md)

## Warm-Up

- explain why `|` and `*` turn one pattern into one language
- explain why implicit concatenation must be made explicit before Thompson construction
- explain why epsilon-closure is part of every simulation step

Target skill:

- recognize when the real lesson is "regex as automaton," not "which exact string matcher do I like more?"

## Core

- infix-to-postfix conversion with explicit concatenation
- Thompson fragment construction
- epsilon-closure
- active-state-set simulation
- exact flagship rep: [Regex Membership](regexmembership.md)

Target skill:

- trust the Thompson-NFA route for small regex syntax and know exactly what contract it does and does not support

## Stretch

- reopen grep-style substring matching only after full-string membership feels automatic
- compare against [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md) so regex languages stay separate from many fixed patterns
- compare against [Suffix Automaton](../../../../topics/strings/suffix-automaton/README.md) so "automaton from regex" and "automaton from base string" do not blur together

Target skill:

- separate regex automata from the rest of the repo's string-automaton family

## Retrieval Layer

- exact quick sheet -> [Regex / Finite Automata hot sheet](../../../../notebook/regex-finite-automata-hot-sheet.md)
- exact starter -> [regex-thompson-nfa.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/regex-thompson-nfa.cpp)
- compare route -> [KMP](../../../../topics/strings/kmp/README.md)
- compare route -> [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md)
- broader chooser -> [String cheatsheet](../../../../notebook/string-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Regular Expressions / Finite Automata](../../../../topics/strings/regex-finite-automata/README.md)
- flagship note -> [Regex Membership](regexmembership.md)
- compare point -> [KMP](../../../../topics/strings/kmp/README.md)
- compare point -> [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md)
- compare point -> [Suffix Automaton](../../../../topics/strings/suffix-automaton/README.md)
- broader routing -> [String ladders](../README.md)

The cleanest in-repo loop here is:

1. reopen [KMP](../../../../topics/strings/kmp/README.md) just enough to keep literal matching separate from language matching
2. learn the Thompson route in [Regular Expressions / Finite Automata](../../../../topics/strings/regex-finite-automata/README.md)
3. solve [Regex Membership](regexmembership.md)
4. compare back against [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md) so "regex language vs many literal patterns" stays sharp

## Exit Criteria

You are ready to move on when:

- you can explain why epsilon-closure is necessary
- you know exactly which metacharacters the starter supports
- you know why this is not a replacement for regex library semantics

## External Practice

- [Algorithms 4/e - Regular Expressions](https://algs4.cs.princeton.edu/54regexp/)

## Tutorial Link

- [Regular Expressions / Finite Automata](../../../../topics/strings/regex-finite-automata/README.md)
