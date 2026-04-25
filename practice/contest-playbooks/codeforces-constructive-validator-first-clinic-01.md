# Codeforces Constructive / Validator-First Clinic 01

## Who This Is For

Use this clinic if:

- you often find a plausible construction in CF rounds but do not trust it enough to ship
- many-valid-answers tasks keep dying to hidden invalid states or weak local checking
- you want one repeatable way to turn “I think this witness should work” into a checked artifact

## Entry Gate

Run this only if basic constructive thinking already feels familiar.

Good starter anchors:

- [Build the Permutation](../ladders/advanced/constructive/buildthepermutation.md)
- [VMCOINS](../ladders/advanced/constructive/vmcoins.md)
- [Constructive](../../topics/advanced/constructive/README.md)

## Clinic Goal

- learn to write the validator or contract checker early enough that construction bugs do not survive on faith alone

## Starter Reps

Run the clinic on one of:

- [Build the Permutation](../ladders/advanced/constructive/buildthepermutation.md)
- [VMCOINS](../ladders/advanced/constructive/vmcoins.md)
- [A-B Palindrome](https://codeforces.com/problemset/problem/1512/C)

## Running Rules

### Step 1: Write The Output Contract First

State exactly what a legal answer must satisfy:

- output format
- domain validity
- per-step legality, if moves are printed
- final target condition

Do this before polishing the construction logic.

### Step 2: Fill The Validator Card

| Item | Your answer |
| --- | --- |
| output domain |  |
| per-step legality rule |  |
| final-state rule |  |
| smallest negative test |  |
| compare by exact output or by predicate? |  |

For many constructive CF tasks, the last row should say `predicate`, not `exact output`.

### Step 3: Build The Smallest Witness

Construct the easiest legal answer you can explain, not the fanciest one.

If there are many legal outputs, prefer the witness with:

- the shortest explanation
- the smallest number of moving parts
- the easiest validator

### Step 4: Attack It

Run [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md) on the witness:

- smallest `n`
- parity boundary
- all-equal or all-one regime
- impossible case
- one-step-away-from-impossible case

### Step 5: Only Then Generalize

If the witness survives, only then clean the general explanation or the full implementation.

Do **not** generalize first and validate later.

## Allowed Refreshers

- [Constructive](../../topics/advanced/constructive/README.md)
- [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)
- [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)

## Success Criteria

- you can say exactly what makes one output legal
- your first local checker catches one invalid witness quickly
- your final confidence comes from validation plus structure, not from samples alone

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| cannot state the witness invariant clearly | [Constructive](../../topics/advanced/constructive/README.md) |
| the task really needs a predicate-checked local validator loop | [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md) |
| the witness seems valid but collapses on edge families | [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md) |
| the issue is round pacing, not constructive logic | [Codeforces Playbook](codeforces.md) |

## After This Clinic

- rerun the constructive slot in [Codeforces Short Round 01](../mixed-rounds/codeforces-short-round-01.md)
- then log the miss in [Codeforces Upsolve Worksheet](codeforces-upsolve-worksheet.md)
