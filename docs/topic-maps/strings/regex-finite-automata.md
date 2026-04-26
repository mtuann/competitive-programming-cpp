# Strings -> Regular Expressions / Finite Automata

Theory-breadth string lane for Thompson-style epsilon-NFA construction and full-string regex membership under a small regex syntax.

- Topic slug: `strings/regex-finite-automata`
- Tutorial page: [Open tutorial](../../../topics/strings/regex-finite-automata/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/regex-finite-automata/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- regex-syntax
- implicit-concatenation
- postfix-conversion
- thompson-construction
- epsilon-closure
- nfa-simulation

## Learning Sources

| Source | Type |
| --- | --- |
| [Algorithms 4/e regular expressions](https://algs4.cs.princeton.edu/54regexp/) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Regex / Finite Automata hot sheet](../../../notebook/regex-finite-automata-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Regex Membership note](../../../practice/ladders/strings/regex-finite-automata/regexmembership.md) | `anchor note` |
| [KMP](../../../topics/strings/kmp/README.md) | `compare point` |
| [Aho-Corasick](../../../topics/strings/aho-corasick/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Regex Membership Benchmark](https://algs4.cs.princeton.edu/54regexp/) | `Algorithms 4/e` | `Medium` | Regular-Expressions, Finite-Automata | Automaton Construction; Simulation | Implicit Concatenation; Postfix Conversion; Epsilon Closure | Thompson Nfa; Epsilon Closure; Regex Membership | Canonical textbook benchmark where the whole lesson is regex-to-postfix, Thompson construction, and active-state-set simulation rather than library regex semantics. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `REGEXMEMBERSHIP` | Regex Membership | `primary` | `medium` | - | [Note](../../../practice/ladders/strings/regex-finite-automata/regexmembership.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/regex-finite-automata/regexmembership.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
