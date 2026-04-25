# ICPC Playbook

## Track Snapshot

ICPC-style contests reward breadth, switching speed, and team process.

The canonical model is:

- `3 contestants`
- `1 workstation`
- about `5 hours`
- ranked by `problems solved`, then `least total time`

At the World Finals and many regionals, one shared machine and limited or no external access are part of the real constraint, not a side detail. That is why this playbook is mostly about triage, handoff, notebook retrieval, and bailout rules rather than only new algorithms.

## Who This Is For

Use this page if:

- you already know the basics of graph, DP, and data-structure topics
- you want a stable team workflow instead of improvising every contest
- your main misses come from bad prioritization, slow switching, or buggy handoffs

Do **not** use this page as your first exposure to contest programming.

Go back first if:

- syntax and local testing still feel slow
- you cannot solve solo banker problems cleanly
- your notebook/template retrieval is still chaotic

## What To Optimize

The highest-payoff ICPC skills are:

1. `opening triage`
2. `one-machine team workflow`
3. `fast recognition across many topics`
4. `debugging without everyone staring at the same screen`
5. `late-contest bailout and revive discipline`

The right question is usually not "who can solve the hardest problem?"

It is:

- which solve is safest right now
- what should occupy the shared machine
- what should the two non-typing teammates do this minute

## Repo Route

| Layer | Best doors | Why |
| --- | --- | --- |
| Topics | [Shortest Paths](../../topics/graphs/shortest-paths/README.md), [BFS And DFS](../../topics/graphs/bfs-dfs/README.md), [Trees](../../topics/graphs/trees/README.md), [Flow](../../topics/graphs/flow/README.md), [Matching](../../topics/graphs/matching/README.md) | ICPC breadth is mostly graph/data-structure retrieval under pressure |
| Ladders | [Contest Engineering ladder](../ladders/advanced/contest-engineering/README.md), [Graphs ladders](../ladders/graphs/README.md), [Data Structures ladders](../ladders/data-structures/README.md) | build repeatable solve order and cleaner implementation habits |
| Mixed rounds | [Contest Core Switching 01](../mixed-rounds/contest-core-switching-01.md), [ICPC Breadth And Implementation 01](../mixed-rounds/icpc-breadth-and-implementation-01.md), [Graphs And DP Switching 01](../mixed-rounds/graphs-dp-switching-01.md) | closest current repo drills to ICPC-style switching, banker ordering, and one-machine execution pressure |
| Anchor notes | [Message Route](../ladders/graphs/bfs-dfs/messageroute.md), [Road Reparation](../ladders/graphs/mst/roadreparation.md), [Police Chase](../ladders/graphs/flow/policechase.md), [QBFLOWER](../ladders/graphs/matching/qbflower.md) | good recognition anchors for common contest-core families |
| Notebook | [Contest Checklist](../../notebook/contest-checklist.md), [Graph cheatsheet](../../notebook/graph-cheatsheet.md), [Data structures cheatsheet](../../notebook/data-structures-cheatsheet.md) | retrieval layer for the first 10-20 minutes of a bug or modeling stall |
| Workflow | [Local Judge Workflow](../../notebook/local-judge-workflow.md), [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) | best recovery loop when one attempted solve is close but unstable |
| Templates | [Template Library](../../template-library.md), `contest-main.cpp`, `fast-io.cpp` | small, rehearsed kit beats a giant kitchen sink |

## Training Rhythm

A strong weekly ICPC rhythm usually looks like:

1. one `mixed round` or archive-style team session
2. one `topic reinforcement` session on the weakest family from that round
3. one `retrieval` session where the goal is notebook/template speed, not new theory
4. one short `post-mortem` where the team logs triage, handoff, and debugging mistakes

If you are training solo for ICPC, keep the same structure but simulate roles:

- first pass as triager
- second pass as typist
- final pass as reviewer/debugger

## Before A Contest

Default checklist:

1. rehearse the opening `20-minute` triage on one recent set
2. verify that your notebook and template kit are instantly retrievable
3. agree on default roles:
   - primary typist / integrator
   - primary triager / modeler
   - primary verifier / debugger
4. reopen one short refresher page per likely weak area
5. do one clean banker warm-up, not a hard puzzle

The goal before ICPC is not to feel clever. It is to remove avoidable friction.

## Exact Drill Doors

- Start here: [ICPC Modeling Under Pressure 01](icpc-modeling-under-pressure-01.md)
- Then reinforce with: [ICPC Triage Drill 01](#icpc-triage-drill-01) and [Handoff Drill](#handoff-drill)
- Escalate to: [ICPC Breadth And Implementation 01](../mixed-rounds/icpc-breadth-and-implementation-01.md)

Treat the modeling drill as the canonical first executable session. The triage and handoff drills are supporting micro-drills inside this playbook, and the mixed round is the broader follow-up session.

## Opening Triage Board

Use one shared board in the first pass instead of letting triage stay verbal.

| Problem | banker / medium / investment | owner | machine priority | bailout minute | next route if parked |
| --- | --- | --- | --- | --- | --- |
| `A` |  |  | `high / medium / low` |  |  |
| `B` |  |  | `high / medium / low` |  |  |
| `C` |  |  | `high / medium / low` |  |  |

Fill it fast. The goal is not perfect prediction. The goal is to stop the team from improvising machine usage problem by problem.

## ICPC Triage Drill 01

Run this on one recent contest set or one curated five-problem block.

1. Spend `15-20 minutes` reading and tagging the set only.
2. Fill the triage board above before anyone writes real contest code.
3. Commit the workstation to the safest first solve.
4. At minute `25`, ask whether the board still matches reality or whether one tag should change.
5. After the session, log one triage miss and one machine-usage win.

This drill is good when your team often says “we knew the solve, but we started the wrong thing first.”

## During A Contest

### Opening 20 Minutes

Good default:

1. two people read the set from opposite ends
2. one person prepares environment and notes likely banker problems
3. tag each problem as:
   - `banker`
   - `medium`
   - `investment`
4. commit the machine to the safest first solve, not the most exciting one

### Handoff Rule

Before a teammate gives a problem to the typist, they should be able to say:

- the invariant or core idea
- expected complexity
- two or three edge cases
- whether the main risk is modeling, implementation, or proof

If that summary is not clean yet, the handoff is early.

## Handoff Drill

Force every handoff through one short summary card:

| idea | complexity | edge cases | current risk | exact next coding step |
| --- | --- | --- | --- | --- |
|  |  |  |  |  |

If the card cannot be filled in one or two minutes, the handoff is probably still too early.

### Bailout Rule

Use default bailout rules unless you have a specific reason not to:

- if `15-20` minutes pass with no clean invariant, park the problem
- if code exists but the bug is not localized after about `10` focused minutes, hand the machine back
- if a banker solve is available, the banker gets machine priority
- only revive a parked problem when you have genuinely new information

### Debugging Rule

When one solve is close:

1. one teammate reads the statement
2. one reads the code
3. one proposes the smallest failing case or complexity explanation

Do not let all three people tunnel on random edits.

### Late Contest / Freeze

In the last `60-90` minutes:

- prefer one more realistic solve over polishing a tie-break fantasy
- maintain your own internal board if public accepted notifications freeze
- revive old WA/TLE attempts only if the failure mode is now concrete

## After A Contest

Every missed or late problem should be tagged with exactly one primary failure:

- `unread`
- `mis-triaged`
- `modeled but not coded`
- `coded but buggy`
- `bad bailout`
- `bad handoff`
- `notebook retrieval miss`

Then choose one follow-up action:

- return to a topic page
- solve one ladder problem in that family
- add one notebook/template improvement
- build one new mixed-round slot

If a post-contest note ends with five vague lessons, it is too weak.

## Common Failure Modes

- letting one hard problem monopolize the machine too early
- having no default handoff protocol
- carrying a huge notebook that no one can navigate quickly
- debugging only by editing code instead of shrinking the failing case
- confusing "interesting" with "high-ROI" in the first hour

## Failure -> Next Repo Door

| Failure | Reopen |
| --- | --- |
| mis-triage or weak first `20` minutes | [ICPC Modeling Under Pressure 01](icpc-modeling-under-pressure-01.md), [ICPC Breadth And Implementation 01](../mixed-rounds/icpc-breadth-and-implementation-01.md), and this page's triage drill |
| bad handoff or unclear ownership | [Contest Engineering](../../topics/advanced/contest-engineering/README.md) |
| close solve died in debugging | [Build Kit](../../docs/build-kit.md), [Local Judge Workflow](../../notebook/local-judge-workflow.md) |
| standard graph/data-structure family was not recognized | [Ladders](../ladders/README.md) or the missed family's corresponding graph/data-structure ladder |

## Progress Markers

You are using the ICPC playbook well when:

- your team can explain a stable opening protocol without debate
- at least one mixed-round pack feels like retrieval practice, not first exposure
- your misses are increasingly about hard modeling, not bad machine usage
- post-contest review produces one concrete process fix per contest

Move back to topic ladders if:

- most misses are still recognition misses
- you repeatedly fail on standard graph or data-structure families
- your notebook is masking missing fundamentals

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Official / primary:

- [ICPC World Finals Programming Environment](https://docs.icpc.global/worldfinals-programming-environment/)
- [ICPC Regional Rules example (NCNA 2025/26)](https://nc.na.icpc.global/rules/)

Reference / essay:

- [KACTL](https://github.com/kth-competitive-programming/kactl)
- [Programming Contest Strategy](https://www.cs.otago.ac.nz/homepages/andrew/papers/2006-4.pdf)

Repo anchors:

- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Mixed Rounds](../mixed-rounds/README.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
- [Template Library](../../template-library.md)
