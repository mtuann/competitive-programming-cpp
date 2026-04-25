# Codeforces Short Round 01

This pack is for `Codeforces-style short-round shipping`: one fast banker, one compact constructive slot, one hack-sensitive feasibility slot, and one optional late model.

## Who This Is For

Use this pack if:

- you already know the core families here in isolation
- your main Codeforces losses come from slow shipping or weak anti-hack habits
- you want a short, repeatable block that feels closer to a live CF round than a long archive grind

## Entry Gate

Try this pack only if these already feel like review:

- [Constructive](../../topics/advanced/constructive/README.md)
- [Prefix Constraints](../../topics/greedy/prefix-constraints/README.md)
- [2-SAT](../../topics/graphs/two-sat/README.md) for the optional late slot

At minimum, these should no longer feel like first exposure:

- [Build the Permutation](../ladders/advanced/constructive/buildthepermutation.md)
- [Prefix Sum Addicts](../ladders/greedy/prefix-constraints/prefixsumaddicts.md)

## Pack Shape

- Type: `Codeforces short-round shipping drill`
- Topic mix: `constructive + feasibility + adversarial checking + late-slot graph modeling`
- Problems: `4`
- Suggested time: `2-2.5 hours`

## Topics Under Test

- banker-first ordering in a short round
- fast construction without overexplaining the entire proof to yourself
- anti-hack discipline on feasibility-heavy code
- knowing when to park an optional late slot instead of burning the whole round on it

## Suggested Order

| Slot | Problem | Topic | Why it is here |
| --- | --- | --- | --- |
| 1 | [Same Parity Summands](https://codeforces.com/problemset/problem/1352/B) | `constructive banker` | Fast first ship: small statement, quick parity split, and low setup cost. |
| 2 | [Build the Permutation](../ladders/advanced/constructive/buildthepermutation.md) | `constructive / witness building` | Typical CF mid-early slot: easy to overcomplicate if you do not lock one clean construction fast. |
| 3 | [Prefix Sum Addicts](../ladders/greedy/prefix-constraints/prefixsumaddicts.md) | `feasibility / anti-hack` | Strong slot for practicing boundary checks, impossible cases, and “looks right on samples” traps. |
| 4 | [The Door Problem](https://codeforces.com/problemset/problem/776/D) | `2-SAT` | Optional late slot: compact graph transform, but only worth opening after the earlier ships are stable. |

## How To Run It

1. spend `8-10 minutes` reading all `4` slots
2. classify each as:
   - `ship now`
   - `one idea away`
   - `park`
3. solve in the suggested order unless you can justify swapping `1` and `2`
4. after each supposedly-finished slot, spend `3-5` minutes on one anti-hack pass:
   - smallest legal case
   - impossible or parity boundary
   - duplicate / degenerate family
5. do **not** open slot `4` if slot `3` still has a vague correctness story

This pack is about `shipping and hardening`, not about starting the fanciest slot earliest.

## Allowed Refreshers

- [Codeforces Playbook](../contest-playbooks/codeforces.md)
- [Contest Checklist](../../notebook/contest-checklist.md)
- [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)
- [Constructive](../../topics/advanced/constructive/README.md)
- [Prefix Constraints](../../topics/greedy/prefix-constraints/README.md)
- [2-SAT](../../topics/graphs/two-sat/README.md)

## Debrief

After the pack, log:

1. first slot that should have shipped earlier
2. first bug or fear that was really an anti-hack miss, not a theorem miss
3. whether slot `4` was opened too early, too late, or at the right time
4. one concrete next action:
   - topic revisit
   - implementation clinic
   - constructive / validator-first clinic
   - upsolve worksheet

## Go Back Next

- if slot `1` or `2` was weak, revisit [Constructive ladder](../ladders/advanced/constructive/README.md)
- if slot `3` was weak, revisit [Prefix Constraints ladder](../ladders/greedy/prefix-constraints/README.md) and [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)
- if slot `4` was weak, revisit [2-SAT ladder](../ladders/graphs/two-sat/README.md)
- if the whole block felt strategically bad, reopen [Codeforces Playbook](../contest-playbooks/codeforces.md)
