# ICPC Modeling Under Pressure 01

## Who This Is For

Use this drill if:

- your team often says “we knew the algorithm later, but we read the problem badly”
- handoffs are noisy because the model never became compact
- the opening `20` minutes feel chaotic even when the topic knowledge is there

## Entry Gate

Run this only if standard contest-core families already feel like review.

At minimum, most of these should feel recognizable:

- [Message Route](../ladders/graphs/bfs-dfs/messageroute.md)
- [Road Reparation](../ladders/graphs/mst/roadreparation.md)
- [Dynamic Range Sum Queries](../ladders/data-structures/segment-tree/dynamicrangesumqueries.md)
- [Book Shop](../ladders/dp/knapsack-family/bookshop.md)
- [String Matching](../ladders/strings/kmp/stringmatching.md)

## Drill Goal

- practice turning raw statements into one-machine-ready models fast enough that triage and handoff stay clean

## Starter Block

Use this repo-native `5-problem` block:

- [Message Route](../ladders/graphs/bfs-dfs/messageroute.md)
- [Road Reparation](../ladders/graphs/mst/roadreparation.md)
- [Dynamic Range Sum Queries](../ladders/data-structures/segment-tree/dynamicrangesumqueries.md)
- [Book Shop](../ladders/dp/knapsack-family/bookshop.md)
- [String Matching](../ladders/strings/kmp/stringmatching.md)

These fit Wave A because they are all anchor notes with sharp recognition cues and they force five different first models without collapsing into one giant investment problem.

## Round Setup

- time budget: `60-75 minutes`
- inputs:
  - the `5` statements above
  - one blank `Opening Triage Board`
  - one blank `Model Brief Card` for the top `3` candidates
- output artifacts:
  - one filled triage board
  - one clean model summary for the top `3` candidates
  - one explicit first-solve choice and one backup solve

## Good Repo Anchors

- [ICPC Playbook](icpc.md)
- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
- [Graph cheatsheet](../../notebook/graph-cheatsheet.md)
- [Data structures cheatsheet](../../notebook/data-structures-cheatsheet.md)

## Running Rules

### `0-12 min`: Cold Read

- read all `5` problems
- tag each as `banker`, `medium`, or `investment`
- do not touch real contest code yet

### `12-25 min`: Model Brief For The Top `3`

For the top `3` candidates only, write one compact model brief:

| family / primitive | complexity | main pitfall | first test | machine priority |
| --- | --- | --- | --- | --- |
|  |  |  |  | `high / medium / low` |

If this card cannot be filled in about `90` seconds, the problem is not machine-ready yet.

### `25-40 min`: Pressure-Test The Choice

Ask:

- is this still the safest first solve?
- did one “investment” problem actually collapse into a medium or banker once modeled clearly?
- is the machine priority based on solve safety or just excitement?

### `40-55 min`: Commit One First Solve And One Backup

- choose one first solve
- choose one backup solve
- state the first concrete coding step for both

### `55-70 min`: Debrief

Log exactly:

1. one problem whose first model was wrong
2. one problem whose model was clean enough for a handoff
3. one machine-priority decision you would keep next time

## Triage Board

Use the board from [ICPC Playbook](icpc.md#opening-triage-board).

## Model Brief Card

Use this compact card for the top `3` candidates only:

| family / primitive | complexity | main pitfall | first test | exact next coding step |
| --- | --- | --- | --- | --- |
|  |  |  |  |  |

## Allowed Refreshers

- [Contest Checklist](../../notebook/contest-checklist.md)
- [Graph cheatsheet](../../notebook/graph-cheatsheet.md)
- [Data structures cheatsheet](../../notebook/data-structures-cheatsheet.md)
- [DP cheatsheet](../../notebook/dp-cheatsheet.md)
- [String cheatsheet](../../notebook/string-cheatsheet.md)

## Success Criteria

- the top candidates have compact model briefs instead of vague verbal summaries
- the machine priority is explicit
- at least one problem changed category because the model became clearer

## Debrief

Write down:

1. first wrong triage tag
2. first wrong primitive
3. the problem that should have received machine priority earlier
4. whether the failure was mainly `mis-triage`, `wrong primitive`, `implementation stall`, `bad bailout`, or `bad handoff`

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| no clean opening protocol | [ICPC Playbook](icpc.md) |
| topic recognition is weak, not modeling | [Ladders](../ladders/README.md) |
| implementation trust is the real bottleneck | [Build Kit](../../docs/build-kit.md) |
| switching is weak across many slots | [ICPC Breadth And Implementation 01](../mixed-rounds/icpc-breadth-and-implementation-01.md) |

## After This Drill

- run [ICPC Triage Drill 01](icpc.md#icpc-triage-drill-01) if the opening board itself is still unstable
- run [ICPC Breadth And Implementation 01](../mixed-rounds/icpc-breadth-and-implementation-01.md) if the modeling is acceptable but execution still collapses under breadth

Research snapshot refreshed against official ICPC sources on `2026-04-24`.
