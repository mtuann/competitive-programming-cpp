# IOI / OI Playbook

## Track Snapshot

IOI/OI-style contests reward deep modeling, proof discipline, and controlled point collection.

The canonical IOI model is:

- `individual`
- `two competition days`
- scores built from task points, often through subtasks or partial progress

Even when a national OI differs in exact format, the training signal is similar:

- prove more
- checkpoint more carefully
- and treat partial score as a real strategic layer, not a consolation prize

## Who This Is For

Use this page if:

- you already solve core graph/DP/math topics, but struggle to convert them into high-stakes olympiad results
- you want a slower and deeper review loop than ICPC-style breadth training
- your main misses come from false proof confidence, weak checkpointing, or poor subtask planning

Go back first if:

- basic implementation still leaks too many points
- you cannot explain why your optimization is correct
- you do not yet have a stable local testing/stress workflow

## What To Optimize

The highest-payoff IOI/OI skills are:

1. `subtask reading and score planning`
2. `proof discipline`
3. `checkpointed implementation`
4. `stress testing at subtask boundaries`
5. `post-contest reconstruction of the best editorial-quality path`

The key mentality shift is:

- do not ask only "can I fully solve this?"
- ask "what is the best proven score path right now?"

## Repo Route

| Layer | Best doors | Why |
| --- | --- | --- |
| Topics | [Reasoning](../../topics/foundations/reasoning/README.md), [Graph Modeling](../../topics/graphs/graph-modeling/README.md), [Tree DP](../../topics/dp/tree-dp/README.md), [Bitmask DP](../../topics/dp/bitmask-dp/README.md), [Digit DP](../../topics/dp/digit-dp/README.md) | these are common places where proof confidence and state design matter more than speed |
| Ladders | [DP ladders](../ladders/dp/README.md), [Graphs ladders](../ladders/graphs/README.md), [Combinatorics ladders](../ladders/combinatorics/README.md) | best route for deepening one weak family after a contest |
| Mixed rounds | [Graphs And DP Switching 01](../mixed-rounds/graphs-dp-switching-01.md), [Strings, Math, And Counting 01](../mixed-rounds/strings-math-counting-01.md) | useful after the basics are stable, but not a substitute for deep topic study |
| Anchor notes | [TFIELD](../ladders/dp/sliding-window/tfield.md), [QOS](../ladders/graphs/shortest-paths/qos.md), [CRYPTKEY](../ladders/math/gcd-lcm/cryptkey.md), [VOITSORT](../ladders/combinatorics/lexicographic-enumeration/voitsort.md), [VOSTRIP](../ladders/graphs/tree-dp/vostrip.md) | closest current repo notes to VOI/olympiad-style modeling |
| Notebook | [Contest Checklist](../../notebook/contest-checklist.md), [DP cheatsheet](../../notebook/dp-cheatsheet.md), [Graph cheatsheet](../../notebook/graph-cheatsheet.md), [Number theory cheatsheet](../../notebook/number-theory-cheatsheet.md) | retrieval layer after the proof idea is already mostly known |
| Workflow | [Stress Testing Workflow](../../notebook/stress-testing-workflow.md), [Local Judge Workflow](../../notebook/local-judge-workflow.md) | crucial because partial-score tasks magnify small validation mistakes |
| Templates | [Template Library](../../template-library.md), `contest-main.cpp`, `tree-dp-rerooting.cpp` | use only snippets you can re-derive and adapt confidently |

## Training Rhythm

A strong IOI/OI week usually looks like:

1. one `deep topic` session
2. one `hard problem or official task` session
3. one `rewrite/proof` session where you restate the clean solution from memory
4. one `validation` session focused on brute force, stress tests, or grader workflow

The main rule is:

- fewer tasks
- but much higher review depth per task

## Before A Contest

Default checklist:

1. reopen one proof-heavy topic page and one implementation-heavy topic page
2. rehearse your local workflow on one graded or partially-scored task
3. decide your checkpoint discipline before the contest starts
4. make sure stress-test or brute-force scaffolding feels automatic
5. warm up with one modeling problem, not only a syntax problem

## Exact Drill Doors

- Start here: [IOI Checkpoint / Score-Path Drill 01](ioi-checkpoint-score-path-drill-01.md)
- Pair it with: [IOI Subtask-First Worksheet](ioi-subtask-first-worksheet.md)

Treat the drill as the executable session and the worksheet as the artifact it runs on.

Use these as the executable layer. Keep this playbook as the router and failure map.

## During A Contest

### Worksheet Route

Use [IOI Subtask-First Worksheet](ioi-subtask-first-worksheet.md) as the live worksheet during the contest. Fill it before you commit hard to the full route, then update only the columns that changed:

- `proof status`
- `validation plan`
- `submit checkpoint`

This keeps one canonical artifact instead of two slightly different subtask tables.

### Checkpoint Rule

Keep one always-compiling branch of the solution.

Submit when you have:

- one genuinely proven subtask or point bucket
- a clean implementation for that bucket
- and at least one stress or brute-force sanity pass

Do **not** overwrite safe points too early with an unproven full attempt.

## Checkpoint / Score-Path Drill

Run [IOI Checkpoint / Score-Path Drill 01](ioi-checkpoint-score-path-drill-01.md) when you want the timed protocol instead of only the worksheet.

### Proof Discipline

Before trusting an optimization, force yourself to state:

- the state
- the invariant
- why the transition is complete
- why the optimization preserves correctness
- and what complexity bound is actually proved

If you cannot say that yet, you probably have an intuition, not a proof.

## Proof Gate Before Coding

Use this gate before trusting a nontrivial optimization or DP state design:

| item | your answer |
| --- | --- |
| state |  |
| invariant |  |
| transition completeness |  |
| optimization justification |  |
| failure example if false |  |

If any row stays vague, delay the optimization and bank the safer score path first.

### Validation Rule

Stress-test by subtask boundary, not only by random whole-task cases:

- smallest legal sizes
- all-equal / all-zero / all-one structures
- extreme sparse vs extreme dense cases
- adversarial cases that break the naive invariant

If the task has a grader or unusual output format, validate against the harness first.

## After A Contest

For each task, log:

- `final score`
- `highest proven score path during contest`
- `best unimplemented idea`
- `first false assumption`
- `first implementation bug`
- `what should be studied next: modeling, proof, or code`

Then choose one follow-up action:

- reopen a topic page
- solve one ladder problem in the same family
- write one cleaner proof note
- add one testing harness or notebook reminder

The goal is not only to know the editorial. It is to know where your own proof or scoring process first broke.

## Common Failure Modes

- chasing the full solution before banking safe subtasks
- confusing "works for this subtask" with "works in general"
- submitting unstable code and losing a safe score floor
- doing no brute-force or stress validation near subtask boundaries
- finishing a contest with vague lessons instead of one precise next step

## Failure -> Next Repo Door

| Failure | Reopen |
| --- | --- |
| unsafe proof or hand-wavy optimization | [Reasoning](../../topics/foundations/reasoning/README.md) |
| missed safe partial score | [IOI Subtask-First Worksheet](ioi-subtask-first-worksheet.md) and [IOI Checkpoint / Score-Path Drill 01](ioi-checkpoint-score-path-drill-01.md) |
| grader or validation issue | [Local Judge Workflow](../../notebook/local-judge-workflow.md) and [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) |
| topic depth still too weak | the missed family's corresponding ladder or deep topic page in `topics/` |

## Progress Markers

You are using this playbook well when:

- you can reliably bank safe partial points before gambling on the full route
- your post-contest notes separate proof misses from implementation misses
- your best unimplemented idea is usually close to the editorial, not far away from it
- stress testing catches bugs before the judge does more often than before

Move back to core topic study if:

- you still cannot explain the state or invariant of your own attempted solution
- most missed points come from standard topic gaps rather than olympiad-specific pressure

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Official / primary:

- [IOI Regulations](https://ioinformatics.org/files/regulations03.pdf)
- [IOI Syllabus](https://ioinformatics.org/page/syllabus/)
- [IOI Statistics](https://stats.ioinformatics.org/tasks/)

Reference:

- [USACO Guide: Contest Strategy](https://usaco.guide/general/contest-strategy)
- [USACO Guide: Basic Debugging / Stress Testing](https://usaco.guide/general/basic-debugging)

Repo anchors:

- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Reasoning](../../topics/foundations/reasoning/README.md)
- [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
