# Heuristic / Marathon Intro

## Who This Is For

Use this intro if:

- you want to understand the contest style where there may be **no single correct optimum**
- a score improves over repeated submissions, local search, or iterative refinement
- you want the shortest honest bridge from classic CP into `marathon / heuristic` thinking

Do **not** open this page if:

- you still need a unique-answer theorem or data structure first
- the current task is ordinary batch, interactive, or predicate-checked but still exact
- you want a full heuristic toolkit already shipped inside this repo

This page is an orientation layer, not a full heuristic lane.

## What This Format Rewards

Typical heuristic / marathon contests reward:

- baseline quality first
- iterative score improvement
- creativity in search or construction
- careful local evaluation
- disciplined experimentation over time

The core mindset shift is:

- stop asking only `is this correct?`
- start asking `what baseline is legal, what score does it get, and what controlled change improves it?`

This is why the format feels closer to engineering and experimentation than to short-round theorem recall.

## Current Repo Fit

This repo does **not** yet have a dedicated heuristic template family or a flagship solved-note lane for marathon tasks.

So the honest current use of this page is:

- learn the operating model
- use the repo's engineering / workflow pages as support
- then practice on official external marathon-style archives if you want real tasks

Current best repo companions:

- [Algorithm Engineering](../../topics/advanced/algorithm-engineering/README.md)
- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Many-Valid-Answers / Validator-First Workflow](../../notebook/many-valid-answers-validator-first-workflow.md)
- [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- [Petrozavodsk / OpenCup Hard Mixed 01](../mixed-rounds/petrozavodsk-opencup-hard-mixed-01.md)

## Clinic Goal

- replace `I will try random tweaks and hope` with one controlled loop:
  - build a legal baseline
  - define a local evaluator
  - freeze one experiment bucket
  - keep the best incumbent
  - change one heuristic family at a time

## First Principles

### 1. Baseline Before Cleverness

Your first target is not a strong score.

It is:

- one legal output
- one reproducible local evaluation
- one score you can beat later

Without that baseline, every later improvement is hard to trust.

### 2. Separate Four Roles

For heuristic work, split these clearly:

1. `instance`
2. `evaluator / scorer`
3. `construction or search policy`
4. `incumbent result`

If one script or binary is implicitly doing all four jobs, debugging and tuning become noisy very quickly.

### 3. Improve One Family At A Time

Typical heuristic families:

- greedy baseline
- local moves
- randomized restarts
- beam / population / candidate pools
- score-guided pruning

Do not change three families in one jump and then trust one leaderboard bump.

### 4. Guard Against Leaderboard Overfitting

Long-form contests often have:

- a provisional or visible score phase
- then stronger system testing or hidden cases later

So a score bump is evidence, not proof.

Keep one local bucket of seeds or instances that you do **not** tune against too casually.

### 5. Logs And Seeds Are First-Class

Freeze:

- the seed set
- the baseline score
- the incumbent score
- the exact change you just made

This is the only way to know whether an improvement is real or noise.

## One Safe Intro Loop

1. define the legality contract
2. build the simplest legal baseline
3. create one local evaluator or score harness
4. run the baseline on a fixed seed bucket
5. record the score
6. choose one heuristic family to change
7. rerun the exact same bucket
8. keep the incumbent only if the evidence is strong enough

This loop is deliberately conservative. It is the best bridge from exact CP into heuristic work.

## Common Failure Modes

- starting with a clever search before a legal baseline exists
- tuning to a visible leaderboard without stable local evidence
- changing multiple heuristic ideas at once
- having no saved seeds, so no score comparison is reproducible
- overusing floating or noisy scoring without recording variance
- treating a one-week optimization task like a two-hour exact contest

## Allowed Refreshers

- [Algorithm Engineering](../../topics/advanced/algorithm-engineering/README.md)
- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Many-Valid-Answers / Validator-First Workflow](../../notebook/many-valid-answers-validator-first-workflow.md)
- [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- [Build Kit](../../docs/build-kit.md)

## Success Criteria

- you can explain the baseline / evaluator / incumbent split clearly
- you never lose the best-known legal solution while experimenting
- each score change can be tied to one specific heuristic change
- you understand why provisional leaderboard gains may not survive final testing

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| you still need per-solution benchmarking and reproducible engineering habits first | [Algorithm Engineering](../../topics/advanced/algorithm-engineering/README.md) |
| the issue is many-valid-answers legality, not score improvement yet | [Many-Valid-Answers / Validator-First Workflow](../../notebook/many-valid-answers-validator-first-workflow.md) |
| you need a runnable scorer / checker loop | [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md) |
| the real bottleneck is hard exact modeling under fatigue, not heuristic search | [Petrozavodsk / OpenCup Hard Mixed 01](../mixed-rounds/petrozavodsk-opencup-hard-mixed-01.md) |
| you want a single hard exact slot, not an open-ended scoring task | [Topcoder One-Hard-Problem Clinic 01](topcoder-one-hard-problem-clinic-01.md) |

## After This Intro

If you want to continue honestly from here:

1. pick one official Topcoder Marathon Match or similar archive task
2. build a legal baseline and local scorer first
3. keep a score log for one fixed seed bucket
4. only then decide whether this repo should open a real heuristic lane with a flagship note

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [Marathon Matches (MM) – Topcoder Support](https://help.topcoder.com/hc/en-us/articles/24954728938011-Marathon-Matches-MM)
- [Marathon Match Tournament Overview](https://www.topcoder.com/marathon-match-tournament/overview)
- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)

Repo anchors:

- [Algorithm Engineering](../../topics/advanced/algorithm-engineering/README.md)
- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Many-Valid-Answers / Validator-First Workflow](../../notebook/many-valid-answers-validator-first-workflow.md)
- [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- [Petrozavodsk / OpenCup Hard Mixed 01](../mixed-rounds/petrozavodsk-opencup-hard-mixed-01.md)
