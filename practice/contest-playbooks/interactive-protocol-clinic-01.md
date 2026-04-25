# Interactive Protocol Clinic 01

## Who This Is For

Use this clinic if:

- interactive tasks keep leaking even when the core algorithm is mostly known
- your post-mortems say `forgot to flush`, `blew the query budget`, or `the judge got desynced`
- you can often explain the search or state logic after the round, but the live protocol loop still feels fragile

## Entry Gate

Run this clinic only if the underlying idea is already mostly in review mode.

Good prerequisite doors:

- [Local Judge Workflow](../../notebook/local-judge-workflow.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
- [Foundations cheatsheet](../../notebook/foundations-cheatsheet.md)
- [Codeforces Playbook](codeforces.md)

If the real issue is still `what algorithm should I use?`, go back to the topic and ladder first.

## Clinic Goal

- turn `I know the idea` into `I can drive the judge cleanly, stop on time, and replay failures locally`

The exact target is not a full solution archive. The target is one stable protocol loop:

- wrapped queries
- visible budget
- deterministic local harness
- one saved failing transcript when something breaks

## Starter Drills

Pick **one** drill shape per clinic run:

- one monotone hidden-answer task with a strict query budget
- one history-dependent task where each judge reply changes the next legal move
- one transcript-replay drill where the solution must stop immediately after printing the final answer

The point is not problem variety. The point is protocol discipline.

## Running Rules

### Step 1: Fill The Protocol Card Before Coding

Write this card first:

| Item | Your answer |
| --- | --- |
| legal query format |  |
| legal reply alphabet |  |
| max query budget |  |
| exact final-answer format |  |
| when the program must terminate |  |
| what goes to `stdout` vs `stderr` |  |

If any row is blank, you are still trusting memory fragments instead of the actual protocol.

### Step 2: Wrap The Judge API

Do **not** scatter raw protocol prints everywhere.

Create one tiny interface:

- `ask(...)`
- `answer(...)`

and keep these responsibilities there:

- printing the exact token format
- flushing
- incrementing or checking the query counter
- handling impossible or end-of-protocol replies

This is the shortest path to catching `budget`, `format`, and `forgot to stop` leaks.

### Step 3: Build A Deterministic Local Harness First

Before you chase performance or edge modeling, make one deterministic loop:

- fixed hidden instance or fixed seed
- one command to rerun it
- one saved transcript when it fails

If the harness is not reproducible, every later debug step becomes emotional noise.

### Step 4: Keep Judge Traffic Off `stdout` Except For The Protocol

Use:

- `stdout` only for legal judge-facing traffic
- `stderr` for local logs, counters, and transcript breadcrumbs

Never let debug prints pollute the protocol stream.

### Step 5: Treat Query Budget As Logic, Not Decoration

Interactive failures are often process failures:

- one extra query
- querying after the final answer
- consuming one reply too many
- forgetting that a branch spends budget even when the logic later backtracks

Make budget checks explicit enough that you can point to them in code.

### Step 6: Freeze One Failing Transcript Immediately

When the first leak appears, save:

- hidden state or seed
- every query and reply
- the line where the protocol first diverged
- whether the failure was `format`, `flush`, `budget`, `termination`, or `model`

This is the artifact that makes the next rerun fast.

## Allowed Refreshers

- [Local Judge Workflow](../../notebook/local-judge-workflow.md)
- [Build Kit](../../docs/build-kit.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
- [Binary Search](../../topics/foundations/patterns/binary-search/README.md) when the interactive logic is really a monotone search

## Success Criteria

- one tiny `ask / answer` wrapper owns the protocol contract
- one rerun command reproduces a local transcript without guessing
- query budget is visible and enforced locally
- the solution stops immediately after the final answer instead of drifting into undefined reads or writes

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| the task is actually batch with predicate-checked output, not interactive | [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md) |
| the harness itself is still unstable or non-reproducible | [Local Judge Workflow](../../notebook/local-judge-workflow.md) |
| the search / state model is the part that is shaky | [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md) or the relevant topic page |
| the main issue is adversarial batch hardening, not query/reply protocol | [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md) |
| the round-level issue is pacing and contest conversion, not protocol correctness | [Codeforces Playbook](codeforces.md) |

## After This Clinic

- rerun one interactive task with a saved transcript or fixed seed
- then write one line in your review notes naming the first leak:
  - `format`
  - `flush`
  - `budget`
  - `termination`
  - `model`

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [Interactive Problems: Guide for Participants](https://codeforces.com/blog/entry/45307?mobile=true)
- [ICPC World Finals Programming Environment](https://docs.icpc.global/worldfinals-programming-environment/)
- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)

Repo anchors:

- [Local Judge Workflow](../../notebook/local-judge-workflow.md)
- [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- [Codeforces Playbook](codeforces.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
