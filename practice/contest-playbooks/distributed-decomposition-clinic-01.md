# Distributed Decomposition Clinic 01

## Who This Is For

Use this clinic if:

- you can solve the single-machine version of a problem, but freeze when the task asks what each worker or shard may know locally
- you keep proposing global data structures before you have written the local summary contract
- you want one repeatable way to practice `split -> summarize -> merge` even though the repo does not yet have a full distributed lane

## Entry Gate

Run this only if the following already feel like review:

- [Graph Modeling](../../topics/graphs/graph-modeling/README.md)
- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
- [Euler Tour / Subtree Queries](../../topics/graphs/euler-tour-subtree/README.md)
- [Linear Recurrence / Matrix Exponentiation](../../topics/math/linear-recurrence/README.md)

Good repo-native compare points:

- [Subtree Queries](../ladders/graphs/euler-tour-subtree/subtreequeries.md)
- [Throwing Dice](../ladders/math/linear-recurrence/throwingdice.md)
- [Dynamic Connectivity](../ladders/data-structures/dsu-rollback/dynamicconnectivity.md)

## Clinic Goal

- learn to write one local summary and one merge contract before imagining the full global execution

## Running Rules

### Step 1: Draw The Split

For one problem or model, write:

- what one worker sees
- what the worker cannot see
- what must be summarized, not transmitted raw

If the split is not explicit, every later "merge" sentence is probably hand-wavy.

### Step 2: Fill The Summary Contract

| Item | Your answer |
| --- | --- |
| local input slice |  |
| local summary fields |  |
| merge operator |  |
| information intentionally discarded |  |
| why that discard is safe |  |

### Step 3: Count The Communication Budget

Ask:

- how large is one summary?
- is the merge associative or order-sensitive?
- what is the smallest counterexample where the summary is insufficient?

The point is not to imitate one exact platform API. The point is to stop smuggling global information into a fake "local" story.

### Step 4: Prove Recomposition

State the exact claim:

- if every shard emits this summary
- and summaries are merged in this way
- then the global answer or next-layer state is recoverable

If you cannot write that claim cleanly, your summary is probably missing one field or carrying too much hidden context.

### Step 5: Recast It Into A Single-Machine Compare Point

Before coding anything, name the closest single-machine analogue:

- subtree flattening plus range aggregation
- DP state transition and matrix composition
- prefix summary and merge
- offline segmentation plus rollback

This keeps the distributed exercise anchored to something the repo already teaches well.

## Allowed Refreshers

- [Graph Modeling](../../topics/graphs/graph-modeling/README.md)
- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
- [Subtree Queries hot sheet](../../notebook/subtree-queries-hot-sheet.md)
- [Linear Recurrence hot sheet](../../notebook/linear-recurrence-hot-sheet.md)
- [Build Kit](../../docs/build-kit.md)

## Success Criteria

- you can name one exact summary contract instead of saying "send enough information"
- you can produce one concrete counterexample that would break a weaker summary
- your decomposition is traceable back to one trusted single-machine compare point

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| cannot state the object model cleanly | [Graph Modeling](../../topics/graphs/graph-modeling/README.md) |
| cannot defend the summary formally | [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md) |
| the real issue is tree flattening or local aggregation | [Euler Tour / Subtree Queries](../../topics/graphs/euler-tour-subtree/README.md) |
| the real issue is implementation scaffolding, not decomposition | [Build Kit](../../docs/build-kit.md) |

## After This Clinic

- inspect one `distributed_codejam` problem in the [coding-competitions-archive](https://github.com/google/coding-competitions-archive)
- then write only the split and summary card, even if you do not code the full solution

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [Celebrate Google's Coding Competitions with a final round of programming fun](https://developers.googleblog.com/celebrate-googles-coding-competitions-with-a-final-round-of-programming-fun/)
- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)

Repo anchors:

- [Graph Modeling](../../topics/graphs/graph-modeling/README.md)
- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
- [Subtree Queries](../ladders/graphs/euler-tour-subtree/subtreequeries.md)
- [Throwing Dice](../ladders/math/linear-recurrence/throwingdice.md)
- [Dynamic Connectivity](../ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
