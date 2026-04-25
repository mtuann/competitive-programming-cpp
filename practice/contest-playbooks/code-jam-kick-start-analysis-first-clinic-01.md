# Code Jam / Kick Start Analysis-First Clinic 01

## Who This Is For

Use this clinic if:

- you often reach the right family only after reading the full analysis
- you can solve the `small` model in your head, but you do not promote it cleanly into the `large` version
- your writeups keep saying "I should have seen the pattern earlier" without naming the first missing bridge

## Entry Gate

Run this only if the relevant core families already feel like review.

Good repo-native starter anchors:

- [Factory Machines](../ladders/foundations/binary-search/factorymachines.md)
- [Counting Numbers](../ladders/dp/digit-dp/countingnumbers.md)
- [Throwing Dice](../ladders/math/linear-recurrence/throwingdice.md)

If these still feel like first exposure, go back to the corresponding topic and ladder first.

## Clinic Goal

- learn the `analysis-first` habit: write the small model, name the bottleneck, and state the promotion rule before polishing the final code

## Starter Reps

Pick **one** of these per clinic run:

- [Factory Machines](../ladders/foundations/binary-search/factorymachines.md)
- [Counting Numbers](../ladders/dp/digit-dp/countingnumbers.md)
- [Throwing Dice](../ladders/math/linear-recurrence/throwingdice.md)

These are not Google archive problems, but they are good repo-native drills for the same escalation move:

- naive or small model
- bottleneck
- promoted large solution

## Running Rules

### Step 1: Fill The Analysis Card Before Coding

Write this card first:

| Item | Your answer |
| --- | --- |
| smallest obviously-correct model |  |
| main bottleneck in that model |  |
| monotone / state / algebra clue |  |
| promoted family |  |
| exact reason the promoted family is sufficient |  |

If the last two rows are vague, you are still too early to code.

### Step 2: Separate `Small` From `Large`

Write one sentence for each:

- what the `small` model proves
- what the `large` data invalidates
- what information survives the promotion

This is the key habit behind old `small / large` Google-style practice, even when the exact contest format no longer runs live.

### Step 3: Name The Promotion Rule

Do **not** settle for "optimize the brute force."

State the exact bridge:

- simulation -> monotone predicate -> [Binary Search](../../topics/foundations/patterns/binary-search/README.md)
- digit brute force -> position state -> [Digit DP](../../topics/dp/digit-dp/README.md)
- recurrence expansion -> linear transition -> [Linear Recurrence / Matrix Exponentiation](../../topics/math/linear-recurrence/README.md)
- local counting -> divisor-side aggregation -> [Mobius And Multiplicative Counting](../../topics/math/mobius-multiplicative/README.md)

### Step 4: Delay Final Code Until The Large Story Is Compact

Before you code, answer:

- what is the exact state or predicate?
- what is the exact transition or merge?
- why is the final complexity safe?
- which smallest case would still break this story?

If you cannot answer these in a few lines, reopen the topic page instead of forcing code.

### Step 5: Use The Right Validation Loop

- ordinary batch solution, trust is low -> [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)
- predicate-checked or many-valid-answers batch task -> [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- statement compression is still fuzzy -> [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)

## Allowed Refreshers

- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
- [Binary Search](../../topics/foundations/patterns/binary-search/README.md)
- [Digit DP](../../topics/dp/digit-dp/README.md)
- [Linear Recurrence / Matrix Exponentiation](../../topics/math/linear-recurrence/README.md)
- [Build Kit](../../docs/build-kit.md)

## Success Criteria

- you can explain the `small -> large` promotion in one clean paragraph
- the first coded version already matches the promoted model instead of the brute-force model
- your post-mortem identifies the first missing bridge, not just the final named algorithm

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| the topic family itself is still unstable | the corresponding deep topic page and ladder |
| the statement never became a compact model | [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md) |
| the answer is predicate-checked and local validation is noisy | [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md) |
| the issue is implementation trust, not analysis | [Build Kit](../../docs/build-kit.md) |

## After This Clinic

- run one archived Google problem through the same analysis card using the [coding-competitions-archive](https://github.com/google/coding-competitions-archive)
- then log the first broken bridge in your normal review notes

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [Celebrate Google's Coding Competitions with a final round of programming fun](https://developers.googleblog.com/celebrate-googles-coding-competitions-with-a-final-round-of-programming-fun/)
- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)
- [A Decade of Kick Start](https://developers.googleblog.com/en/a-decade-of-kick-start/)

Repo anchors:

- [Factory Machines](../ladders/foundations/binary-search/factorymachines.md)
- [Counting Numbers](../ladders/dp/digit-dp/countingnumbers.md)
- [Throwing Dice](../ladders/math/linear-recurrence/throwingdice.md)
- [Reasoning And Implementation Discipline](../../topics/foundations/reasoning/README.md)
