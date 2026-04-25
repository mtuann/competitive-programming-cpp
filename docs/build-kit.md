# Build Kit

Use this page when the algorithm is mostly known and the bottleneck is now:

- implementing it cleanly
- reopening the right snippet quickly
- checking one invariant under pressure
- stabilizing a suspicious solution locally

This is the repo's `retrieve and execute` layer.

## Quick Split

- `Notebook` = recall the invariant, signal, or trap
- `Template Library` = retrieve the smallest reusable snippet
- `Build Kit` = choose between notebook, templates, and workflow pages

## What Lives Here

| Need | Best door |
| --- | --- |
| reusable contest code | [Template Library](../template-library.md) |
| short invariant/trap reminders | [Notebook](../notebook/README.md) |
| debug a suspicious implementation | [Stress testing workflow](../notebook/stress-testing-workflow.md) |
| validator-heavy / interactive / many-valid-answers local loop | [Local judge workflow](../notebook/local-judge-workflow.md) |
| before-contest checklist | [Contest checklist](../notebook/contest-checklist.md) |

## Exact Starter Routes

Use these when the topic is already mostly trusted and you want the shortest path back to code plus one concrete compare target.

| Need | Learn / check first | Reuse | Compare against |
| --- | --- | --- | --- |
| exact one-pattern matching | [KMP](../topics/strings/kmp/README.md) | [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp) | [String Matching](../practice/ladders/strings/kmp/stringmatching.md) |
| static tree, point updates, path maximum | [Heavy-Light Decomposition](../topics/graphs/hld/README.md) | [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp) | [Path Queries II](../practice/ladders/graphs/hld/pathqueries2.md) |
| exact convolution modulo `998244353` | [FFT / NTT](../topics/math/fft-ntt/README.md) | [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp) | [FFT ladder](../practice/ladders/math/fft/README.md) |
| one inverse under composite modulus or `ax + by = c` | [Modular Arithmetic](../topics/math/modular-arithmetic/README.md) | [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp) | [GCD / LCM ladder](../practice/ladders/math/gcd-lcm/README.md) |

## Choose The Smallest Useful Tool

### Template Library

Open [Template Library](../template-library.md) when:

- you already know the family
- you want the smallest contest-ready implementation
- you need one fast chooser table, not a tutorial
- you already have a topic page or note anchor and now need the smallest reusable code shape

Do **not** open it first if you still do not trust the topic itself.

### Notebook

Open [Notebook](../notebook/README.md) when:

- you mostly know the idea
- you need the main invariant, trap, or signal fast
- you want the shortest route back to the right family

Do **not** use it as first exposure.

### Workflows

Open a workflow page when the algorithm feels right but the solution still feels unsafe:

- [Stress testing workflow](../notebook/stress-testing-workflow.md)
- [Local judge workflow](../notebook/local-judge-workflow.md)

## Build Kit Routes

| If the problem feels like... | Open first | Then |
| --- | --- | --- |
| “I know the topic, just give me the snippet” | [Template Library](../template-library.md) | the matching topic page only if trust is low |
| “I know the topic, but I forgot the invariant” | [Notebook](../notebook/README.md) | the matching template |
| “The code compiles, but I do not trust it” | [Stress testing workflow](../notebook/stress-testing-workflow.md) | the matching note or template |
| “This task has a judge/protocol quirk” | [Local judge workflow](../notebook/local-judge-workflow.md) | the matching playbook or note |

## Best Pairings

- shortest paths -> [Shortest Paths hot sheet](../notebook/shortest-paths-hot-sheet.md) + graph templates
- tree path queries -> [Graph cheatsheet](../notebook/graph-cheatsheet.md) + [Heavy-Light Decomposition](../topics/graphs/hld/README.md)
- range-query structures -> [Segment Tree hot sheet](../notebook/segment-tree-hot-sheet.md) + [Data structures cheatsheet](../notebook/data-structures-cheatsheet.md)
- flow or cuts -> [Flow hot sheet](../notebook/flow-hot-sheet.md) + graph templates
- matching -> [Matching hot sheet](../notebook/matching-hot-sheet.md) + [Flow hot sheet](../notebook/flow-hot-sheet.md) when the reduction is ambiguous
- modular arithmetic -> [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md) + math templates
- geometry predicates -> [Geometry cheatsheet](../notebook/geometry-cheatsheet.md) + geometry templates

## After This Page

- if trust in the snippet is still low, go back to `topics/`
- if you now need the next problem, go to [Problem Finder](problem-finder.md)
- if you want a contest-format workflow, go to [Contest Playbooks](../practice/contest-playbooks/README.md)
