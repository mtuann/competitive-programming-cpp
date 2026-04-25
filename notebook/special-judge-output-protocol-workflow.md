# Special Judge / Output Protocol Workflow

This page is for batch tasks where exact stdout diffing is the wrong trust model.

- Trigger: special judge, custom validator, many-valid-answers output, or predicate-checked batch tasks
- Inputs needed: one candidate solution plus a checker, validator, predicate script, or score-aware harness
- Output artifact: one reproducible local validation loop with at least one negative case and one accepted-looking positive case
- Stop condition: legality and output protocol are separated cleanly from the solving logic
- Pair with: [Local judge workflow](local-judge-workflow.md), [Anti-Hack Workflow](anti-hack-workflow.md)

Use it when:

- the task accepts many valid outputs
- correctness depends on a predicate, not one reference output
- the judge computes legality or score through custom logic
- simple stdin/stdout replay does not tell you whether the output is actually valid

Do **not** use this page if:

- the task is fully interactive; use [Local judge workflow](local-judge-workflow.md)
- the task is an ordinary unique-answer batch task; use [Stress testing workflow](stress-testing-workflow.md)
- the real issue is adversarial batch hacking after the idea is known; use [Anti-Hack Workflow](anti-hack-workflow.md)

## Which Workflow To Use Right Now

- ordinary unique-answer batch task -> [Stress testing workflow](stress-testing-workflow.md)
- interactive simulator or transcript problem -> [Local judge workflow](local-judge-workflow.md)
- hack-sensitive constructive task -> start here, then pair with [Anti-Hack Workflow](anti-hack-workflow.md)
- predicate-checked batch output or special judge -> this page

## Core Goal

Separate these roles clearly:

1. `solution`
2. `validator / checker / scorer`
3. `instance source`

If the same binary or script is implicitly doing all three jobs, debugging becomes too emotional and too noisy.

## Minimum Setup

For most special-judge tasks, keep this split:

- `sol.cpp`
- `check.py` or `check.cpp`
- optional `gen.cpp`
- optional `oracle.cpp` if a small exact model exists
- one saved failing input or seed

The goal is not to mimic the official judge perfectly. The goal is to reproduce the legality contract locally.

## Output Contract Card

Before you trust the solution, fill this card:

| Check | Your answer |
| --- | --- |
| exact output format |  |
| output domain |  |
| per-step legality rule |  |
| final acceptance predicate |  |
| if scored, what score means locally |  |

If any row is blank, you are still comparing vibes, not contracts.

## Validator-First Loop

Default loop:

1. write the legality checker first
2. produce one tiny invalid output by hand
3. make sure the checker rejects it
4. run the candidate solution on a tiny valid case
5. only then scale into generated or larger tests

This is the shortest route to avoiding "samples passed, but the custom judge hated it."

## Negative Test Families

When you do not know what to attack first, try:

- correct format, wrong values
- legal values, illegal move sequence
- duplicated item in a purported set or permutation
- missing item in a purported covering or partition
- empty or one-element boundary
- one-step-away-from-legal witness
- same score-looking output that actually violates the predicate

## Score-Aware Caution

If your local scorer is only a partial reconstruction of the official one:

- trust legality first
- treat score as directional only
- save the exact local assumption the scorer is making

Do **not** overfit to a fake local score model and call that correctness.

## Batch Output Protocol Split

For many special-judge tasks, it helps to separate two checks:

1. `protocol check`
   - did the output shape and token count follow the statement?
2. `meaning check`
   - does the output actually satisfy the predicate?

This split catches a lot of "the answer idea is fine, but the serialized output is not."

## Done When

- you can rerun one stable checker command without guessing
- the checker rejects at least one deliberate invalid output
- the candidate output passes the checker on at least one nontrivial case
- legality is no longer being inferred from a raw diff against one reference file

## Good Pairings

- [Local judge workflow](local-judge-workflow.md)
- [Anti-Hack Workflow](anti-hack-workflow.md)
- [Codeforces Constructive / Validator-First Clinic 01](../practice/contest-playbooks/codeforces-constructive-validator-first-clinic-01.md)
- [Code Jam / Kick Start Analysis-First Clinic 01](../practice/contest-playbooks/code-jam-kick-start-analysis-first-clinic-01.md)

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [Celebrate Google's Coding Competitions with a final round of programming fun](https://developers.googleblog.com/celebrate-googles-coding-competitions-with-a-final-round-of-programming-fun/)
- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)
- [Single Round Matches (SRMs) - Topcoder Support](https://help.topcoder.com/hc/en-us/articles/24954129102491-Single-Round-Matches-SRMs)

Repo anchors:

- [Local judge workflow](local-judge-workflow.md)
- [Anti-Hack Workflow](anti-hack-workflow.md)
- [Build the Permutation](../practice/ladders/advanced/constructive/buildthepermutation.md)
- [Giant Pizza](../practice/ladders/graphs/two-sat/giantpizza.md)
