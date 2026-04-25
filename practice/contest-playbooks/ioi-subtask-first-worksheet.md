# IOI Subtask-First Worksheet

Use when: one problem has visible subtasks, partial-score routes, or several plausible upgrade paths.

Inputs:

- one statement
- one score table or subtask breakdown
- one honest first pass on constraints and edge cases

Output artifact:

- one filled worksheet that decides the safest next score path instead of leaving it vague

Done when:

- you can name one `bank / upgrade / park` decision and justify it with proof + validation, not instinct alone

## Fill In This Order

1. list the visible score buckets or natural checkpoints
2. write the smallest valid algorithm for each bucket before you think about the full solve
3. choose one current target and complete the proof gate for only that path
4. write the exact validation plan before coding
5. decide the trigger that promotes the next bucket or parks the problem

## Main Worksheet

| Subtask / score bucket | points | constraint signature | smallest valid algorithm | proof state | implementation state | validation plan | submit checkpoint | promote / park trigger |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `1` |  |  |  | `idea / proved / coded` | `not started / partial / stable` |  |  |  |
| `2` |  |  |  | `idea / proved / coded` | `not started / partial / stable` |  |  |  |
| `3` |  |  |  | `idea / proved / coded` | `not started / partial / stable` |  |  |  |
| `4` |  |  |  | `idea / proved / coded` | `not started / partial / stable` |  |  |  |

## Current Target Proof Gate

Fill only for the score path you are about to trust right now.

| Item | Your answer |
| --- | --- |
| target bucket |  |
| state / maintained object |  |
| invariant |  |
| transition completeness |  |
| optimization justification |  |
| failure example if false |  |

## Validation Box

| Check | Your answer |
| --- | --- |
| smallest legal cases |  |
| subtask-boundary cases |  |
| brute / checker / grader route |  |
| first stop rule |  |

## Bank / Upgrade / Park

| If this happens... | Action |
| --- | --- |
| proof gate is clean and validation passed | `bank` the checkpoint |
| proof is clean but implementation is the bottleneck | `stabilize`, then bank |
| implementation is stable and one next bucket is clearly adjacent | `upgrade` |
| proof is still fuzzy or validation keeps moving the target | `park` and protect the safe score |

## Next Repo Door

| Bottleneck | Reopen |
| --- | --- |
| proof is fuzzy | [Reasoning](../../topics/foundations/reasoning/README.md) |
| implementation trust is weak | [Build Kit](../../docs/build-kit.md) and [Template Library](../../template-library.md) |
| validation plan is weak | [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) or [Local Judge Workflow](../../notebook/local-judge-workflow.md) |
| topic depth is weak | the missed family's corresponding page in [Topics](../../topics/README.md) and then its [Ladder](../ladders/README.md) |
| you need the full timed protocol | [IOI Checkpoint / Score-Path Drill 01](ioi-checkpoint-score-path-drill-01.md) |

## Pair This With

- [IOI / OI Playbook](ioi-oi.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
- [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)

Research snapshot refreshed against official IOI sources on `2026-04-24`.
