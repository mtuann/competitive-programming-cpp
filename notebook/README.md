# Notebook

This folder is the short-reference layer of the repo.

Use it for:

- notebook-ready snippets
- formulas
- checklist pages
- contest-time reminders

It should stay denser and shorter than `topics/`.

## Quick Split

- `Notebook` = recall the main invariant, signal, or trap fast
- `Template Library` = retrieve the smallest reusable snippet fast
- `Build Kit` = route between notebook, templates, and workflow pages

## Contract

This layer answers one question:

```text
I already mostly know the area. What is the shortest route back to the right invariant, trap, and reusable snippet?
```

Every mature cheatsheet should bias toward:

- `Use when`
- `Do not use when`
- `Choose by signal`
- one or two core invariants
- one or two main traps
- direct jumps to topic pages, templates, and repo notes

It should not try to reteach the full topic. If you need proofs or slower walkthroughs, jump back to `topics/`.

## Use This Layer When

- the area is mostly known, but retrieval feels slow
- you want the lightest viable template family quickly
- you need the main invariant or failure mode under contest pressure
- you want one nearby repo note to reopen, not a long tutorial

## Do Not Use This Layer When

- you are learning the topic for the first time
- you still do not know the brute-force baseline
- you cannot yet explain why the main technique works
- the problem needs a slower decision page more than a compact reminder

## Fast Retrieval Loop

When you are mid-problem and want the shortest route back to something reusable:

1. open the matching cheatsheet for the family
2. pick a template or invariant from there
3. jump back into the topic page only if you need proof, pitfalls, or a slower explanation

This is meant to be the layer you skim during implementation, not the layer you study first.

## Sheet Contract In Practice

The shortest useful scan order is:

1. `Use when`
2. `Do not use when`
3. `Choose by signal`
4. `Invariant / trap`
5. one template or repo anchor

## Representative Anchors

- Data structures -> [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- Graphs -> [QOS](../practice/ladders/graphs/shortest-paths/qos.md), [MINCOST](../practice/ladders/graphs/flow/mincost.md)
- DP -> [TFIELD](../practice/ladders/dp/sliding-window/tfield.md)
- Number theory -> [CRYPTKEY](../practice/ladders/math/gcd-lcm/cryptkey.md)
- Geometry -> [KINGDOMS](../practice/ladders/geometry/sweep-line/kingdoms.md), [PRAVO](../practice/ladders/geometry/right-triangles/pravo.md)

## Current Sheets

- [Foundations cheatsheet](foundations-cheatsheet.md)
- [Data structures cheatsheet](data-structures-cheatsheet.md)
- [Graph cheatsheet](graph-cheatsheet.md)
- [DP cheatsheet](dp-cheatsheet.md)
- [Combinatorics cheatsheet](combinatorics-cheatsheet.md)
- [Number theory cheatsheet](number-theory-cheatsheet.md)
- [String cheatsheet](string-cheatsheet.md)
- [Geometry cheatsheet](geometry-cheatsheet.md)
- [Contest checklist](contest-checklist.md)
- [Stress testing workflow](stress-testing-workflow.md)
- [Local judge workflow](local-judge-workflow.md)

## Good Pairings

- shortest paths -> [Graph cheatsheet](graph-cheatsheet.md) + [Template library](../template-library.md)
- ordered sets / sliding windows -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- modular arithmetic / `nCk` -> [Number theory cheatsheet](number-theory-cheatsheet.md)
- polygon and segment geometry -> [Geometry cheatsheet](geometry-cheatsheet.md)
- debugging a suspicious implementation -> [Stress testing workflow](stress-testing-workflow.md)
- interactive or validator-heavy tasks -> [Local judge workflow](local-judge-workflow.md)

## Learn -> Practice -> Retrieve

Use this layer as the `Retrieve` step, not the first step:

| If you need... | Open first | Then |
| --- | --- | --- |
| proof or slower explanation | [Topics](../topics/README.md) | come back here after the idea is trusted |
| a concrete next problem | [Problem Finder](../docs/problem-finder.md) | then reopen the matching sheet |
| a pasteable snippet | [Build Kit](../docs/build-kit.md) | then the matching template |

## Reopen Rules

- if you need proofs, go to `topics/`
- if you need a pasteable skeleton, go to [Template library](../template-library.md)
- if you need the exact next problem or next short set, go to [Problem Finder](../docs/problem-finder.md)
