# Many-Valid-Answers / Validator-First Workflow

This page is for batch tasks where the hardest part is not the core algorithm name, but the fact that many different outputs can be accepted.

- Trigger: constructive tasks, witness-building tasks, score-aware batch outputs, or any problem where exact stdout diffing is the wrong trust model
- Inputs needed: one candidate construction idea plus the statement-level legality contract
- Output artifact: one explicit output contract, one smallest positive witness, one smallest negative witness, and one clear route to a checker
- Stop condition: you are no longer trusting one pretty-looking sample output as proof of correctness
- Pair with: [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md), [Anti-Hack Workflow](anti-hack-workflow.md), [Stress testing workflow](stress-testing-workflow.md)

Use it when:

- the task accepts many legal answers
- your current confidence comes from `this output looks plausible`
- the statement defines correctness by a predicate, not by one exact target output
- you need to decide what the validator should check before you even write it

Do **not** use this page if:

- the task is fully interactive; use [Local Judge Workflow](local-judge-workflow.md)
- the answer is unique and plain diffing is enough; use [Stress testing workflow](stress-testing-workflow.md)
- the main issue is already implementing a checker loop, not defining the legality contract; use [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md)

## Which Workflow To Use Right Now

- unique-answer batch task -> [Stress testing workflow](stress-testing-workflow.md)
- interactive protocol task -> [Local Judge Workflow](local-judge-workflow.md)
- many valid outputs but the legality contract is still fuzzy -> this page
- many valid outputs and the contract is already clear, but you need a checker / scorer loop -> [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md)

## Core Goal

Separate four different jobs:

1. `construct a candidate witness`
2. `state the legality contract`
3. `validate the witness`
4. `attack the witness`

Many wrong answers come from jumping straight from `1` to `confidence`, while skipping `2` and `3`.

## Output Contract Card

Before coding the final construction, fill this card:

| Check | Your answer |
| --- | --- |
| exact output shape |  |
| output domain |  |
| object being constructed |  |
| local legality rule |  |
| global target predicate |  |
| compare by exact output or predicate? |  |
| if scored, what local score means |  |

If the last two rows are vague, you are not ready to trust one sample.

## Validator-First Loop

Default order:

1. write the contract in words
2. produce one tiny legal witness by hand
3. produce one tiny illegal witness by hand
4. describe the checker that would accept the first and reject the second
5. only then scale into the full constructive idea

This prevents the common failure mode:

- `I built something complicated`
- `samples passed`
- `I never actually stated what legality meant`

## Smallest Witness Discipline

When many outputs are legal, the first good candidate is not the fanciest one.

Prefer the witness with:

- the shortest proof
- the fewest moving parts
- the easiest checker
- the clearest impossible-case condition

That makes both the solution and the validator easier to trust.

## Negative Test Families

Attack these first:

- duplicated item in a supposed set / permutation / covering
- missing item in a supposed partition / assignment / pairing
- one-step-away-from-legal move sequence
- correct-looking score but illegal final structure
- empty, one-element, or smallest nontrivial case
- impossible case where the construction keeps printing something anyway

If the witness survives none of these attacks, you do not trust the witness yet.

## Predicate Split

For many-valid-answers tasks, separate:

1. `shape`
   - token count, sizes, bounds, formatting
2. `local legality`
   - each move, edge, assignment, or token is individually legal
3. `global goal`
   - the final structure satisfies the statement
4. `score` if any
   - only after legality is already safe

This split gives you a much cleaner route into a real checker.

## When To Reopen Special Judge Workflow

Switch to [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md) when:

- the legality contract is already clear
- you now need a runnable checker or predicate loop
- you need to separate checker / generator / solution binaries
- you need one stable local command that rejects a deliberate negative case

This page comes earlier in the pipeline; `Special Judge` comes when the checker needs to become executable.

## Done When

- you can explain exactly why exact-output comparison is the wrong model
- one legal witness and one illegal witness are both explicit
- the checker you need is now obvious enough to implement
- your confidence comes from contract plus validation, not from aesthetic similarity to samples

## Good Pairings

- [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md)
- [Anti-Hack Workflow](anti-hack-workflow.md)
- [Codeforces Constructive / Validator-First Clinic 01](../practice/contest-playbooks/codeforces-constructive-validator-first-clinic-01.md)
- [Code Jam / Kick Start Analysis-First Clinic 01](../practice/contest-playbooks/code-jam-kick-start-analysis-first-clinic-01.md)

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [Codeforces Contest Rules](https://codeforces.com/blog/entry/4088?locale=en)
- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)
- [Single Round Matches (SRMs) - Topcoder Support](https://help.topcoder.com/hc/en-us/articles/24954129102491-Single-Round-Matches-SRMs)

Repo anchors:

- [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md)
- [Anti-Hack Workflow](anti-hack-workflow.md)
- [Codeforces Constructive / Validator-First Clinic 01](../practice/contest-playbooks/codeforces-constructive-validator-first-clinic-01.md)
- [Build the Permutation](../practice/ladders/advanced/constructive/buildthepermutation.md)
