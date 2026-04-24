# Contest Engineering

Contest engineering is the operational layer: notebook quality, testing workflow, time management, and post-contest review habits.

## Prerequisites

- [Algorithm Engineering](../algorithm-engineering/README.md)
- [Notebook](../../../notebook/README.md)

## When To Suspect It

- your knowledge is decent but results are inconsistent
- you lose time to setup, debugging, or poor prioritization
- you want a repeatable training system rather than random problem grinding
- your biggest bottleneck is no longer theory, but contest execution

## Core Idea

Treat contest performance as a system:

- pre-contest preparation
- in-contest workflow
- post-contest upsolving and note capture

Good performance is usually not one heroic insight. It is many small systems working together:

- a trustworthy notebook
- strong template retrieval
- bug-catching habits
- time-boxed decision making

## Theory / Proof Sketch

This topic is less about asymptotic proof and more about repeatable process. Good teams and good individual contestants reduce decision fatigue by standardizing their environment, notebook, and review loop.

The real invariant is:

```text
under pressure, your default process should still be good
```

That means fewer avoidable mistakes, faster recovery after bugs, and better use of the problems you do solve.

## Complexity And Tradeoffs

- high practical value once you already know the core material
- mostly process payoff rather than new theoretical problem types

Tradeoffs:

- huge ROI for consistency
- easy to neglect because it looks less glamorous than new algorithms
- best when practiced repeatedly, not just read once

## Canonical Pattern

Useful contest loop:

1. scan all problems quickly
2. sort by confidence and estimated time-to-AC
3. lock in early solves cleanly
4. escalate only when a harder problem is clearly worth the cost
5. after contest, review misses and update notebook/process

## Worked Examples

Example 1: notebook retrieval

A template you cannot find or adapt quickly is not really part of your contest toolkit.

Example 2: debugging discipline

A standard checklist often beats random tinkering:

- input/model check
- small hand cases
- brute-force comparison
- edge-case sweep

Example 3: post-contest review

Capture:

- what pattern was missed
- what bug habit repeated
- what notebook/template change would have prevented it

## Internal Material

This topic is deliberately repo-led more than problem-led. The most useful internal pages are:

- [Contest Playbooks](../../../practice/contest-playbooks/README.md)
- [Contest Checklist](../../../notebook/contest-checklist.md)
- [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
- [Local Judge Workflow](../../../notebook/local-judge-workflow.md)
- [Template Library](../../../template-library.md)

## Recognition Cues

- strong practice performance but weak contest conversion
- repeated avoidable WA/TLE from rushed setup
- a team or individual workflow that feels improvisational every time
- lots of solved problems but little retention under time pressure

## Common Mistakes

- collecting templates without practicing retrieval
- doing many random problems without structured review
- not writing down recurring debugging and modeling mistakes
- overcommitting to one hard problem too early
- treating post-contest review as optional

## Standard Variants

- solo contest workflow
- team contest workflow
- notebook curation
- debugging checklist habits
- upsolving and retrospective process

## Practice Ladder

- [Contest engineering ladder](../../../practice/ladders/advanced/contest-engineering/README.md)

## Go Deeper

- Practice: [Contest Playbooks](../../../practice/contest-playbooks/README.md)
- Practice: [Contest Checklist](../../../notebook/contest-checklist.md)
- Practice: [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
- Practice: [Local Judge Workflow](../../../notebook/local-judge-workflow.md)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
- Blog/reference: [USACO Guide](https://usaco.guide/)

## Related Topics

- [Algorithm Engineering](../algorithm-engineering/README.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)
