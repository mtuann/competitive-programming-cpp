# Codeforces Playbook

## Track Snapshot

Codeforces rewards fast shipping, compact modeling, and disciplined post-round upsolving.

Unlike `USACO`, `IOI / OI`, or `ICPC`, this track is not one single fixed contest format.

Common current shapes include:

- `Div. 2`: about `2 hours`, usually `5-6` problems
- `Educational` / many `Div. 3` and `Div. 4` rounds: extended `ICPC` scoring with `10` minute penalties and an open-hack phase afterward
- special rounds that may explicitly use `no hacks`, custom scoring, or extra contest-specific rules

So the first Codeforces habit is not “assume the platform always behaves one way.”

It is:

- read the round announcement
- check whether the round has hacks or not
- check whether interactive tasks may appear
- and recheck the current AI rule before the contest

## Who This Is For

Use this page if:

- you already solve some core topics, but short rounds still feel noisy
- your main misses come from shipping too slowly, weak anti-hack discipline, or chaotic upsolving
- you want a repeatable route for `before / during / after` a Codeforces round instead of improvising every time

Do **not** use this page as your first exposure to contest programming.

Go back first if:

- your compile / run / debug loop is still shaky
- you still miss too many banker problems because of syntax or indexing mistakes
- most misses come from missing the topic entirely rather than from round execution

## What To Optimize

The highest-payoff Codeforces skills are:

1. `short-round shipping`
2. `statement compression into one clean primitive`
3. `anti-hack and rejudge awareness`
4. `validator-first discipline on constructive or many-answer tasks`
5. `post-round upsolve quality`

The key mentality shift is:

- do not ask only “what is the hardest idea I can find?”
- ask “what can I ship cleanly in this format, and what can survive rejudge or hacks?”

## Repo Route

| Layer | Best doors | Why |
| --- | --- | --- |
| Topics | [Constructive](../../topics/advanced/constructive/README.md), [Prefix Constraints](../../topics/greedy/prefix-constraints/README.md), [Binary Search](../../topics/foundations/patterns/binary-search/README.md), [Sorting](../../topics/foundations/patterns/sorting/README.md), [2-SAT](../../topics/graphs/two-sat/README.md) | CF short rounds often reward quick reframing, feasibility checks, and one compact primitive more than broad theorem-hunting |
| Ladders | [Constructive ladder](../ladders/advanced/constructive/README.md), [Greedy ladders](../ladders/greedy/README.md), [Foundations ladders](../ladders/foundations/README.md), [2-SAT ladder](../ladders/graphs/two-sat/README.md) | best route when one round exposes one narrow family that should become routine |
| Mixed rounds | [Codeforces Short Round 01](../mixed-rounds/codeforces-short-round-01.md), [Contest Core Switching 01](../mixed-rounds/contest-core-switching-01.md) | best current repo drills for short-round shipping and banker-first pacing |
| Anchor notes | [Build the Permutation](../ladders/advanced/constructive/buildthepermutation.md), [Prefix Sum Addicts](../ladders/greedy/prefix-constraints/prefixsumaddicts.md), [Giant Pizza](../ladders/graphs/two-sat/giantpizza.md) | compact, high-signal notes that mirror common CF transforms: construction, feasibility, late-slot graph modeling |
| Notebook | [Contest Checklist](../../notebook/contest-checklist.md), [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md), [Foundations cheatsheet](../../notebook/foundations-cheatsheet.md) | best retrieval layer when the issue is not theory depth but round execution discipline |
| Workflow | [Stress Testing Workflow](../../notebook/stress-testing-workflow.md), [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md), [Local Judge Workflow](../../notebook/local-judge-workflow.md), [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md) | the right loop depends on whether the risk is raw correctness, predicate-checked output, interactive protocol, or hack sensitivity |
| Templates | [Template Library](../../template-library.md), `contest-main.cpp`, `fast-io.cpp` | the Codeforces default should still be a small, trusted kit rather than a giant contest blob |

## Training Rhythm

A strong weekly Codeforces rhythm usually looks like:

1. one live or simulated `short-round` block
2. one `upsolve worksheet` pass on that block
3. one `anti-hack / validator-first` session on the leakiest missed problem
4. one focused `topic reinforcement` block for the weakest family exposed by the round

The default loop should be:

- round first
- then diagnosis
- then one exact reinforcement

not:

- random editorial binge
- then no behavior change next round

## Before A Contest

Default checklist:

1. read the specific round announcement
2. check:
   - duration
   - scoring shape
   - whether hacks exist
   - whether interactive tasks may appear
   - whether any special rules or AI wording were repeated there
3. warm up on one banker-style implementation, not one hard puzzle
4. keep retrieval small:
   - one cheatsheet
   - one workflow page
   - one or two topic families only
5. decide your default policy for the round:
   - `ship first`
   - `hack later only if EV is real`

## Exact Drill Doors

- Start here: [Codeforces Short Round 01](../mixed-rounds/codeforces-short-round-01.md)
- Pair it with: [Codeforces Upsolve Worksheet](codeforces-upsolve-worksheet.md)
- If constructive or many-valid-answers tasks keep leaking: [Codeforces Constructive / Validator-First Clinic 01](codeforces-constructive-validator-first-clinic-01.md)
- If medium implementation slots keep leaking: [Codeforces Implementation Clinic 01](codeforces-implementation-clinic-01.md)
- If the main fear is hacks or rejudge fragility: [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)

Treat the short round as the executable session, the worksheet as the review artifact, and the clinics as targeted repair loops.

## During A Contest

### Opening 10 Minutes

Read all problems quickly and classify each as:

- `ship now`
- `one idea away`
- `park`

Then choose:

- the safest first solve
- and the safest second solve

Many Codeforces losses start when contestants spend the first `25-35` minutes admiring a future slot instead of shipping an actual current one.

### Shipping Rule

Default rule:

- bank the clean points first
- keep accepted-looking code stable
- and only reopen a “finished” slot when the EV is clearly better than the next solve

This is especially important in short rounds where one extra shipped task often matters more than one almost-solved late slot.

### Hack / Rejudge Rule

If the round has an open-hack phase or post-round rejudge dynamics:

- remember that pretests are not the finish line
- run one short anti-hack pass after the solution looks done
- look for:
  - smallest legal case
  - all-equal / duplicate-heavy case
  - parity or count boundary
  - “already sorted / reverse sorted / one bad block”
  - impossible case hidden by optimistic assumptions
  - overflow or type-width edge

If another clean solve is available, do **not** spend large chunks of live contest time guessing hacks blindly.

Use hack time only when you have:

- a precise vulnerable assumption
- or a concrete failing family to test

### Constructive / Many-Valid-Answers Rule

On constructive or multi-answer tasks, do **not** compare against one reference output and feel done.

Instead:

1. write the output contract first
2. write the smallest local validator or predicate check you can
3. only then trust your construction

This is why the repo pairs Codeforces constructive work with:

- [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md)
- [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)

### Interactive Rule

If the round announcement says an interactive problem may appear:

- reopen the official guide before the round if you are rusty
- treat flushing, transcript discipline, and query counts as first-class constraints

Do **not** rely on memory fragments from one old interactive problem.

### Late Round Rule

In the last `20-30` minutes:

- prefer one stable extra solve over one theatrical new investment
- if the round has hacks, only switch into hack mode when the next solve really looks dead
- leave one-line restart notes before abandoning a parked problem

## After A Contest

Default review loop:

1. fill [Codeforces Upsolve Worksheet](codeforces-upsolve-worksheet.md)
2. classify each miss by its *first* real leak:
   - reading
   - model
   - implementation
   - anti-hack / rejudge
   - proof / correctness
   - time allocation
3. finish the closest missed problem first
4. then do one editorial reconstruction for the hardest meaningful miss
5. end with one durable system patch:
   - notebook reminder
   - workflow change
   - one new edge-family check
   - one new topic revisit

If your post-round review ends with “I should get stronger,” it is too vague.

## Common Failure Modes

- treating all Codeforces rounds as if they share one exact ruleset
- shipping code that passes samples but has never seen one adversarial edge-family pass
- using hacks as an excuse to avoid solving
- comparing one constructive output against one reference answer instead of validating the actual contract
- reading editorials too early and learning the final idea without diagnosing the first personal leak
- doing no clean upsolve classification, so the next short round repeats the same failure

## Failure -> Next Repo Door

| Failure | Reopen |
| --- | --- |
| got hacked or fear rejudge on “accepted-looking” code | [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md) |
| constructive or many-answer task kept leaking | [Codeforces Constructive / Validator-First Clinic 01](codeforces-constructive-validator-first-clinic-01.md), [Constructive](../../topics/advanced/constructive/README.md), and [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md) |
| medium implementation slots keep leaking | [Codeforces Implementation Clinic 01](codeforces-implementation-clinic-01.md) and [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) |
| can solve after the round but not inside it | [Codeforces Short Round 01](../mixed-rounds/codeforces-short-round-01.md) and [Contest Engineering](../../topics/advanced/contest-engineering/README.md) |
| the missed family is genuinely weak | the corresponding ladder in [Ladders](../ladders/README.md), then come back through the worksheet |

## Progress Markers

You are using this playbook well when:

- you can tag the set quickly and name the first two likely ships without drama
- your first accepted solution arrives earlier and more reliably than before
- hack-sensitive tasks now get one real adversarial pass before you trust them
- your upsolve notes separate `model`, `implementation`, and `anti-hack` misses instead of lumping them together
- the next round changes because of one concrete system patch from the last one

Move back to core ladders if:

- most misses are still plain topic-recognition misses
- your banker problems still die mostly to syntax or local workflow issues
- every “round skill” diagnosis is really a missing family underneath

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Official / primary:

- [Codeforces Contest Rules](https://codeforces.com/blog/entry/4088?locale=en)
- [Rule Restricting the Use of AI [revision 2024-09-14]](https://codeforces.com/topic/134567/en4)
- [Interactive Problems: Guide for Participants](https://codeforces.com/blog/entry/45307?mobile=true)
- [Educational Codeforces Round 188 announcement](https://codeforces.com/blog/entry/151001)
- [Codeforces Round 1090 (Div. 4) announcement](https://codeforces.com/blog/entry/152610)

Repo anchors:

- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
- [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md)
- [Codeforces Short Round 01](../mixed-rounds/codeforces-short-round-01.md)
- [Codeforces Upsolve Worksheet](codeforces-upsolve-worksheet.md)
- [Build the Permutation](../ladders/advanced/constructive/buildthepermutation.md)
- [Prefix Sum Addicts](../ladders/greedy/prefix-constraints/prefixsumaddicts.md)
