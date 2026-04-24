# USACO Playbook

## Track Snapshot

USACO rewards solo problem solving with strong implementation discipline and steady progression through divisions.

The most important contest-shape facts are:

- you work alone
- official contests happen inside a contest window
- progression matters more than one lucky hard solve
- official conduct rules are stricter than normal personal-practice habits

This track is less about team workflow than ICPC and less about proof-heavy full-olympiad depth than IOI/OI. It sits in the middle:

- clean implementation
- correct reading of constraints
- reliable local validation
- deliberate Bronze -> Silver -> Gold progression

## Who This Is For

Use this page if:

- you are training for official USACO contests or using USACO-style archives as your main solo ladder
- you want a clear route from fundamentals toward stronger graph/DP/data-structure material
- your bottleneck is converting topic knowledge into clean, solo, timed solves

Do **not** use this page as a replacement for learning the basics.

Go back first if:

- compile/run/debug loops are still shaky
- you still misread easy implementation details often
- you have no stable local testing routine

## What To Optimize

The highest-payoff USACO skills are:

1. `reading constraints correctly`
2. `clean implementation`
3. `subtask and score awareness`
4. `steady division-appropriate progression`
5. `disciplined post-contest upsolving`

USACO often punishes sloppy code and rushed reading harder than flashy theory gaps.

## Repo Route

| Layer | Best doors | Why |
| --- | --- | --- |
| Topics | [C++ Language](../../topics/foundations/cpp-language/README.md), [Sorting](../../topics/foundations/patterns/sorting/README.md), [Binary Search](../../topics/foundations/patterns/binary-search/README.md), [Two Pointers](../../topics/foundations/patterns/two-pointers/README.md), [Prefix Sums](../../topics/foundations/patterns/prefix-sums/README.md) | strongest route for Bronze/Silver cleanup and early Gold readiness |
| Ladders | [Foundations ladders](../ladders/foundations/README.md), [Shortest Paths ladder](../ladders/graphs/shortest-paths/README.md), [Modular Arithmetic ladder](../ladders/math/modular-arithmetic/README.md) | good default progression once the very basics are stable |
| Mixed rounds | [Stage 0 Review Pack 01](../mixed-rounds/stage0-review-pack-01.md), [Contest Core Switching 01](../mixed-rounds/contest-core-switching-01.md) | use after the relevant ladders, not before |
| Anchor notes | [Weird Algorithm](../ladders/foundations/cpp-language/weirdalgorithm.md), [Apartments](../ladders/foundations/two-pointers/apartments.md), [Exponentiation](../ladders/math/modular-arithmetic/exponentiation.md), [Dynamic Range Sum Queries](../ladders/data-structures/segment-tree/dynamicrangesumqueries.md) | simple-to-core notes that map well onto USACO-style solo implementation work |
| Notebook | [Foundations cheatsheet](../../notebook/foundations-cheatsheet.md), [Contest Checklist](../../notebook/contest-checklist.md), [Local Judge Workflow](../../notebook/local-judge-workflow.md) | best short retrieval loop for solo timed work |
| Workflow | [Stress Testing Workflow](../../notebook/stress-testing-workflow.md), [Local Judge Workflow](../../notebook/local-judge-workflow.md) | highest ROI for reducing avoidable WAs and local judge confusion |
| Templates | [Template Library](../../template-library.md), `contest-main.cpp`, `fast-io.cpp` | useful for training, but see the rule below about official contests |

## Training Rhythm

Good default rhythm:

1. one focused topic ladder block
2. one timed solo session on archive-style problems
3. one short debugging or stress-testing session
4. one post-contest or post-session review where you log the first real mistake

Suggested emphasis by level:

- `Bronze / early Silver`: syntax, arrays, sorting, greedy implementation, prefix sums
- `Silver / early Gold`: binary search, graphs, DSU, ordered sets, implementation speed
- `Gold+`: DP families, stronger graph topics, offline reasoning, more deliberate proof checks

## Before A Contest

Default checklist:

1. reopen the one or two topic pages most likely to matter for your current division
2. warm up with one short implementation problem
3. make sure your local compile/test loop is instant
4. review one page of edge-case reminders, not a giant notebook
5. remind yourself of the official contest-conduct rules

### Important Rule About Templates

For **training**, templates are useful.

For **official USACO contests**, do **not** assume you can rely on a prewritten personal template kit the way you might in ICPC training. Recheck the current official instructions each season and follow them strictly.

This repo's template layer is for learning and practice speed. It is not a license to import your full personal codebook into official USACO submissions.

## During A Contest

### Opening Rule

Read all tasks and constraints first. Then classify:

- `safe`
- `likely with work`
- `too early right now`

Do not let a shiny hard idea stop you from taking the clean points first.

### Subtask Rule

If subtasks or easier score paths are visible:

- log them explicitly
- decide whether to bank them now or come back later

USACO rewards reliable point collection and steady promotion more than romantic full-solve gambling.

### Implementation Rule

When stuck, localize the failure before changing the algorithm:

- read constraints again
- hand-test the smallest failing case
- separate parse/indexing bugs from algorithm bugs
- only then refactor

### Time Rule

If you are no longer making progress and cannot state the next concrete step, park the task and move.

Solo contests still need bailout discipline.

## After A Contest

Default review loop:

1. upsolve every missed or only-partially-solved problem
2. log the first real mistake:
   - reading
   - modeling
   - implementation
   - testing
3. decide one next action:
   - reopen a topic
   - solve one more ladder problem
   - add one local judge or stress-testing habit
   - add one notebook reminder

The review should identify the first break in your process, not only the final algorithm you were missing.

## Common Failure Modes

- rushing into code before reading all constraints and subtasks
- overusing templates instead of understanding the implementation
- polishing one nearly-solved problem for too long while cleaner points are available
- doing no serious local validation because the code "looks right"
- skipping post-contest upsolve because the result felt good enough

## Progress Markers

You are using this playbook well when:

- your missed points increasingly come from hard ideas, not careless implementation
- you can explain what division-level skill is currently limiting you
- your post-contest notes repeatedly point to the same tractable next step
- your local testing loop catches more bugs before submission

Move back to fundamentals if:

- most misses are still indexing, overflow, or parsing mistakes
- you cannot solve the easier ladder problems in the same family cleanly

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Official / primary:

- [USACO Details / FAQ](https://usaco.org/current/current/index.php?page=details)
- [USACO Contest Instructions and Rules](https://usaco.org/index.php/current/tpcm/current/data/index.php?page=instructions)
- [USACO Training](https://usaco.org/index.php?page=training)

Reference:

- [USACO Guide](https://usaco.guide/)

Repo anchors:

- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Foundations cheatsheet](../../notebook/foundations-cheatsheet.md)
- [Local Judge Workflow](../../notebook/local-judge-workflow.md)
- [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)
