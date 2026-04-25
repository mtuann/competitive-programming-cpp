# Topcoder One-Hard-Problem Clinic 01

## Who This Is For

Use this clinic if:

- you can ship easier contest slots, but one hard problem still collapses your whole session
- you keep opening multiple candidate approaches instead of choosing one line of attack and defending it
- your post-mortems say "hard problem" without naming whether the first leak was modeling, proof, or system-test fragility

## Entry Gate

Run this only if advanced topics already feel like review.

Good repo-native anchors:

- [Giant Pizza](../ladders/graphs/two-sat/giantpizza.md)
- [Ciel the Commander](../ladders/graphs/centroid-decomposition/cielthecommander.md)
- [Monster Game II](../ladders/dp/cht-li-chao/monstergame2.md)
- [Counting Coprime Pairs](../ladders/math/mobius-multiplicative/countingcoprimepairs.md)

## Clinic Goal

- practice the `one hard problem` discipline: one compact model, one proof ledger, one exact system-test plan

## Starter Reps

Pick **one** of these:

- [Giant Pizza](../ladders/graphs/two-sat/giantpizza.md)
- [Ciel the Commander](../ladders/graphs/centroid-decomposition/cielthecommander.md)
- [Monster Game II](../ladders/dp/cht-li-chao/monstergame2.md)

Do not rotate across several hard reps in the same session.

## Running Rules

### Step 1: Restate The Exact Contract

Write the task as one exact solver contract:

- input object
- output object
- correctness condition
- target complexity ceiling

If you cannot restate the contract in `4-5` lines, you are not ready for implementation yet.

### Step 2: Fill The Proof Ledger

| Item | Your answer |
| --- | --- |
| main primitive or reduction |  |
| core invariant |  |
| exact complexity story |  |
| first scary edge family |  |
| smallest system-test candidate |  |

### Step 3: Commit To One Route

Do **not** keep three half-ideas alive.

Choose one line:

- reduction
- decomposition
- optimization trick
- invariant-driven greedy or DP

Then push that route until one exact statement breaks.

### Step 4: Code The Skeleton That Matches The Ledger

Before polishing constants or helpers, make sure the skeleton reflects the proof ledger:

- the state really stores the promised information
- the merges or transitions match the invariant
- the complexity-critical loop is already visible

### Step 5: Run A Pre-System-Test Pass

Topcoder-style hard problems punish solutions that are almost right.

Before trusting the code, test:

- smallest legal instance
- empty or degenerate structure
- duplicated or symmetric case
- overflow boundary
- one case where two candidate transitions tie

## Allowed Refreshers

- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Build Kit](../../docs/build-kit.md)
- [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)

## Success Criteria

- you can state the exact primitive and invariant without reopening editorial prose
- one hard rep survives a deliberate pre-system-test pass
- the post-mortem names the first leak precisely: model, proof, implementation, or edge-case defense

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| the statement never became a compact object model | [Topcoder Weird-Task Clinic 01](topcoder-weird-task-clinic-01.md) |
| the invariant is still fuzzy | [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md) |
| the issue is advanced topic depth, not clinic process | the corresponding deep topic page and ladder |
| the code shape is the real bottleneck | [Build Kit](../../docs/build-kit.md) |

## After This Clinic

- rerun the same rep once without notes
- then write one `system-test family I almost missed` line in your review notes

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [Single Round Matches (SRMs) - Topcoder Support](https://help.topcoder.com/hc/en-us/articles/24954129102491-Single-Round-Matches-SRMs)
- [Competitive Programming at Topcoder](https://www.topcoder.com/community/arena)
- [Competing in a Topcoder Rated Event](https://www.topcoder.com/community/competitive-programming/how-to-compete/ratedEvent)

Repo anchors:

- [Giant Pizza](../ladders/graphs/two-sat/giantpizza.md)
- [Ciel the Commander](../ladders/graphs/centroid-decomposition/cielthecommander.md)
- [Monster Game II](../ladders/dp/cht-li-chao/monstergame2.md)
- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
