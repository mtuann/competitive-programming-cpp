# Codeforces Implementation Clinic 01

## Who This Is For

Use this clinic if:

- you often identify the right family in a CF round but still leak medium slots to branch noise, indexing, or stale assumptions
- your post-round notes keep saying “implementation issue” without pinpointing the first real leak
- you want one compact routine for cleaning up implementation-heavy medium problems

## Entry Gate

Run this only if the topic family itself is already mostly known.

Typical good entry anchors:

- [Prefix Sum Addicts](../ladders/greedy/prefix-constraints/prefixsumaddicts.md)
- [Subtree Queries](../ladders/graphs/euler-tour-subtree/subtreequeries.md)
- [HORRIBLE](../ladders/data-structures/lazy-segment-tree/horriblequeries.md)

If these still feel like first exposure, go back to the relevant topic and ladder first.

## Clinic Goal

- turn “I know the idea” into one smaller, safer implementation surface that survives contest pressure

## Starter Reps

Pick **one** of these per clinic run:

- [Prefix Sum Addicts](../ladders/greedy/prefix-constraints/prefixsumaddicts.md)
- [Subtree Queries](../ladders/graphs/euler-tour-subtree/subtreequeries.md)
- [HORRIBLE](../ladders/data-structures/lazy-segment-tree/horriblequeries.md)

The goal is not variety. The goal is clean implementation compression.

## Running Rules

### Step 1: Normalize The Model

Before coding, state:

- one indexing convention
- one interval convention
- one data-shape contract

Do **not** allow two competing meanings for the same variable once coding starts.

### Step 2: Write The Dangerous Branches First

List the branches most likely to leak:

- empty or one-element case
- boundary move at the first or last index
- merge or push transition
- impossible case

If you cannot name these branches, your implementation story is still too fuzzy.

### Step 3: Fill The Compression Card

| Item | Your answer |
| --- | --- |
| core invariant |  |
| dangerous branch |  |
| smallest failing edge family |  |
| first assert or debug print to add locally |  |
| exact anti-hack family to try after samples |  |

### Step 4: Run The Right Safety Loop

- ordinary batch logic suspicion -> [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)
- validator / many-answer suspicion -> [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- “looks accepted but feels fragile” suspicion -> [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)

### Step 5: Patch One Leak Only

Do not rewrite the whole file after the first suspicious edge case.

Instead:

1. localize the first leak
2. patch one assumption
3. rerun the exact failing family

## Allowed Refreshers

- [Foundations cheatsheet](../../notebook/foundations-cheatsheet.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
- [Build Kit](../../docs/build-kit.md)
- [Stress Testing Workflow](../../notebook/stress-testing-workflow.md)
- [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)

## Success Criteria

- you can name the first implementation leak in one sentence
- one indexing or interval convention stays fixed through the whole solution
- your “implementation bug” post-mortem becomes specific enough to reproduce tomorrow

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| the topic itself is still unstable | the corresponding deep topic page and ladder |
| the code feels fragile under adversarial tests | [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md) |
| the solution needs a predicate checker rather than plain diffs | [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md) |
| the main issue is contest pacing, not code shape | [Codeforces Playbook](codeforces.md) |

## After This Clinic

- rerun one slot in [Codeforces Short Round 01](../mixed-rounds/codeforces-short-round-01.md)
- then fill one row in [Codeforces Upsolve Worksheet](codeforces-upsolve-worksheet.md)
