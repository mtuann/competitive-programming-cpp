# Greedy -> Prefix Constraints

Greedy selection under prefix or feasibility quotas, usually proved with exchange arguments and heap maintenance.

- Topic slug: `greedy/prefix-constraints`
- Ladder page: [Open ladder](../../../practice/ladders/greedy/prefix-constraints/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `8`

## Microtopics

- prefix-quota
- feasible-prefix
- heap-greedy
- exchange-proof
- offline-selection
- representative-reconstruction

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki greedy](https://en.oi-wiki.org/basic/greedy/) | `trusted guide` |
| [Principles of Algorithmic Problem Solving](https://usaco.guide/PAPS.pdf) | `reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |
| [IOI tasks archive](https://stats.ioinformatics.org/tasks/) | `contest archive` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Lemonade Line](https://usaco.org/index.php?cpid=835&page=viewproblem2) | `USACO 2018 US Open Silver` | `Easy-Medium` | - | - | - | Sort+Greedy; Threshold | keep a valid prefix by descending willingness |

### Binary Construction

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Two Binary Strings](https://codeforces.com/problemset/problem/1861/B) | `Codeforces` | `Easy` | Construction | Greedy-Construction | String Scanning; Invariants | Binary-Strings; Prefix-Conditions | A constructive greedy where valid prefixes constrain how the final string can be assembled. |

### Extremal Constraints

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Prefix Min and Suffix Max](https://codeforces.com/problemset/problem/2123/C) | `Codeforces` | `Easy` | Prefix-Extrema | Greedy-Check | Suffix Extrema | Prefix-Min; Suffix-Max | A nice prefix/suffix constraint problem that rewards tracking the right extrema at the right time. |

### Prefix Extrema

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Prefix Max](https://codeforces.com/problemset/problem/2185/B) | `Codeforces` | `Easy` | Prefix-Extrema | Greedy-Check | Prefix Maxima; Comparisons | Prefix-Max; Arrays | A crisp prefix-max problem where the greedy invariant is both simple and central. |

### Prefix Feasibility

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Prefix Sum Addicts](https://codeforces.com/problemset/problem/1738/B) | `Codeforces` | `Easy` | Prefix-Feasibility | Greedy-Check | Prefix Sums; Parity Reasoning | Prefix-Sum; Construction | The prefix-sum structure is the whole problem, so it is a nice fit for prefix-constrained greedy reasoning. |

### Prefix Monotonicity

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Keep it Beautiful](https://codeforces.com/problemset/problem/1841/B) | `Codeforces` | `Easy` | Stateful-Greedy | Greedy-Check | Sequence Invariants; Two-State Logic | Binary-Array | A good example of maintaining a global prefix condition while processing the sequence online. |

### Prefix Trimming

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Remove Prefix](https://codeforces.com/problemset/problem/1714/B) | `Codeforces` | `Easy` | Prefix-Invariant | Greedy-Check | Arrays; Set Membership | Construction | A very direct prefix-invariant greedy where the answer is determined by the first repeated prefix pattern. |

### Structured Prefix Cleanup

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Binary Removals](https://codeforces.com/problemset/problem/1499/B) | `Codeforces` | `Easy` | Prefix-Structure | Greedy-Check | String Scanning; Prefix/Suffix Reasoning | Binary-String | A compact prefix-constraint problem where the feasibility check is driven by a simple greedy invariant. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VODIVIDE` | Chia phần | `primary` | `hard` | prefix quota greedy; heap maintenance; pair reconstruction | [Note](../../../practice/ladders/greedy/prefix-constraints/vodivide.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/vodivide.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
