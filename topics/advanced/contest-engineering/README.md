# Contest Engineering

Contest engineering is the operational layer that sits between:

- knowing algorithms
- and reliably converting that knowledge into accepted solutions under time pressure

This page is not about one more theorem or one more data structure.

It is about engineering the default process that runs when:

- you are tired
- the clock is visible
- and the cost of one avoidable mistake is much higher than during ordinary practice

## At A Glance

- Use this page when:
  - your topic knowledge is decent, but contest conversion is inconsistent
  - you lose time to setup, retrieval, debugging loops, or bad problem-order decisions
  - your notebook, templates, and workflows exist, but do not yet behave like one coherent system
  - the bottleneck is no longer “learn the algorithm” but “execute the contest loop cleanly”
- Prerequisites:
  - [Notebook](../../../notebook/README.md)
  - [Template Library](../../../template-library.md)
- Nearby layer:
  - [Algorithm Engineering](../algorithm-engineering/README.md)
- Boundary with nearby pages:
  - use [Algorithm Engineering](../algorithm-engineering/README.md) when the question is how to validate or optimize one solution
  - use this page when the question is how to run the whole contest loop repeatedly with fewer avoidable losses
  - use [Contest Playbooks](../../../practice/contest-playbooks/README.md) for track-specific operating manuals like `ICPC`, `USACO`, or `IOI / OI`
  - use this page for the reusable cross-track system underneath those playbooks
- Strongest cues:
  - you solve ideas after the contest, but miss them during the contest
  - your main losses come from retrieval, setup, or debugging drift rather than from missing theory completely
  - your post-contest review feels unstructured, so the same failure modes repeat
  - you want one repeatable process for `before / during / after`, not ad-hoc heroics
- Strongest anti-cues:
  - you still need basic syntax and first-topic fluency more than process design
  - the main blocker is concept mastery, not execution discipline
  - you are looking for track-specific rules, which belong in [Contest Playbooks](../../../practice/contest-playbooks/README.md)
  - the problem is one isolated buggy solution, not contest workflow
- Success after studying this page:
  - you can describe one contest loop that you would trust tomorrow, not only today
  - you can separate retrieval failures from modeling failures and debugging failures
  - you can choose the right workflow quickly: normal batch, stress, or local judge
  - your post-contest review produces concrete repo changes instead of vague regret

## Quick Route

Use this page first as a failure-mode router.

```text
1. Do I know the topic, but cannot retrieve the right asset fast enough?
   reopen Notebook / Template Library / Build Kit

2. Do I get ideas, but lose them to WA/TLE/debug drift?
   start with the ordinary batch loop, then escalate to Stress Testing Workflow or Local Judge Workflow

3. Do I burn too much time on the wrong problem?
   use the cross-track bailout heuristic here, then reopen the right Contest Playbook for format-specific rules

4. Do I keep repeating the same mistakes next week?
   write one retrospective artifact and attach one concrete repo or workflow change
```

Contest engineering is what turns those four questions into one stable system.

## Problem Model And Notation

Think of contest performance as a loop with three phases:

1. `prepare`
2. `execute`
3. `review`

This page uses a simple internal vocabulary.

- `asset`: something reusable under pressure
  - notebook entry
  - template
  - workflow page
  - mixed round
- `retrieval cost`: how long it takes to find and adapt the right asset
- `decision cost`: how much contest time is spent choosing what to do next
- `unforced error`: a wrong answer, TLE, or dead-end caused by process drift rather than by the underlying idea being beyond reach
- `feedback loop`: the path from one failure to one durable repo or habit change

Contest translation:

- if an asset exists but cannot be found and adapted fast, it is not contest-ready
- if a workflow exists but is not your default under stress, it is not yet engineered

## From Ad-Hoc Execution To The Right System

The naive contest style is:

- skim problems vaguely
- improvise a solve order
- debug reactively
- move on after the contest without updating the system

That style can work on a very good day. It usually does not scale.

The engineered version asks:

1. what is the first confident solve I should lock in?
2. what asset should I reopen before I start coding?
3. what workflow do I escalate to when ordinary testing is not enough?
4. what exact repo or habit change will prevent this same loss next time?

That produces four reusable loops.

### Loop 1: Retrieval

Move from:

- “I know I saw this somewhere”

to:

- “I know which page or template to reopen, and why”

### Loop 2: Execution

Move from:

- random local testing

to:

- one clean loop for batch tasks, one for stress, one for local-judge / interactive tasks

### Loop 3: Triage

Move from:

- “this hard problem feels interesting”

to:

- “this is the right problem to spend the next 25 minutes on”

### Loop 4: Retrospective

Move from:

- “I should review later”

to:

- one captured failure mode, one root cause, one system change

## Core Invariant And Why It Works

Every useful contest-engineering loop protects five invariants.

### Invariant 1: Your Default Process Should Still Be Good Under Stress

Contest pressure removes spare decision bandwidth.

So the default process should already encode the good choices:

- where to look first
- what to test first
- when to bail out
- what to record afterward

If the process only works when you are fresh and patient, it is not yet engineered.

### Invariant 2: Contest-Ready Assets Must Have Low Retrieval Cost

A template or note is only valuable in contest conditions if:

- you know it exists
- you know when it applies
- you can reopen and adapt it quickly

This is why the repo has:

- [Notebook](../../../notebook/README.md) for recall
- [Template Library](../../../template-library.md) for code retrieval
- [Build Kit](../../../docs/build-kit.md) for workflow routing

The invariant is:

- retrieval must be fast enough that reopening the asset beats improvising from scratch

### Invariant 3: Debugging Loops Must Escalate Cleanly

There are at least three different classes of testing loop:

- ordinary batch loop
- stress / brute-force comparison loop
- local judge / validator / interactive loop

One of the most expensive contest mistakes is using the wrong loop for too long.

That is why the escalation path matters:

- ordinary batch task -> use [Foundations cheatsheet](../../../notebook/foundations-cheatsheet.md) for the default compile / run / sample / hand-case loop
- logic seems suspicious on small random inputs -> use [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
- protocol or many-valid-answers issue -> use [Local Judge Workflow](../../../notebook/local-judge-workflow.md)

### Invariant 4: Triage Must Protect Solve Count First

Many contest losses are not theorem losses. They are solve-order losses.

The engineered triage rule is:

- bank high-confidence progress early
- protect early score / acceptance / partial-credit opportunities from avoidable variance
- escalate to harder problems only when the expected return is worth the cost

This is not “play safe forever.”

It is:

- spend decision energy where it buys the most contest value

Minimal cross-track bailout heuristic:

- if one focused block produces no concrete model progress, no trustworthy reduction in uncertainty, and another open task has materially higher confidence, park the current task
- leave one restart note before switching

Format-specific thresholds and substitutions belong in:

- [ICPC](../../../practice/contest-playbooks/icpc.md)
- [USACO](../../../practice/contest-playbooks/usaco.md)
- [IOI / OI](../../../practice/contest-playbooks/ioi-oi.md)

### Invariant 5: Post-Contest Review Must End In One Concrete System Change

A retrospective is only useful if it produces one change that survives into the next contest:

- notebook wording
- template metadata
- mixed-round choice
- bailout rule
- debugging checklist update
- problem-note addition

Without that final step, the same failure mode usually returns.

## Complexity And Tradeoffs

The main tradeoff here is:

- more discipline and less improvisation
versus
- more up-front structure and maintenance

Typical patterns:

| Pattern | What you gain | Main risk |
| --- | --- | --- |
| curated notebook and template chooser | faster retrieval and lower setup cost | collecting assets you never rehearse |
| explicit triage and bailout rules | better contest conversion under time pressure | becoming too rigid to react to real contest information |
| separate testing workflows | faster bug isolation | using an expensive workflow too early |
| written retrospective loop | durable improvement between contests | writing vague reflections with no concrete repo change |

Important contest lesson:

- contest engineering does not replace topic study
- it makes topic study show up in results more consistently

## Variant Chooser

| Failure mode | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| you know the idea but cannot start coding cleanly | reopen notebook + template chooser | the missing step is retrieval, not theory | weak if you still do not understand the model |
| you keep shipping avoidable WA/TLE on ordinary tasks | use batch-to-stress escalation | process errors usually show up on small random checks | weak if the task really needs a validator or simulator |
| the task has many valid outputs or an interaction protocol | use local-judge workflow | you need a harness, not more samples | weak if the task is just an ordinary batch problem |
| you lose too much time on one hard problem | apply triage / bailout rule | contest value is suffering from decision drift | weak if you quit before testing one real idea properly |
| the same loss pattern repeats across contests | run a written retrospective | the bottleneck is failure capture, not raw practice volume | weak if the retrospective ends without a concrete system change |

## Worked Examples

### Example 1: A Template You Cannot Retrieve Is Not Yet Part Of Your Toolkit

Suppose you have:

- a tested HLD template
- a matching notebook entry
- a solved note such as [Path Queries II](../../../practice/ladders/graphs/hld/pathqueries2.md)

but in contest conditions you still spend 20 minutes rebuilding the structure from memory.

The failure is not:

- “I do not know HLD”

It is:

- “my retrieval system is not contest-ready”

The fix is usually not “study HLD harder.” The fix is:

- tighten the notebook entry
- improve template metadata
- practice one timed retrieval through a [Mixed Round](../../../practice/mixed-rounds/README.md)

This is the simplest contest-engineering lesson:

- asset existence is not the same as asset availability

### Example 2: Debugging Drift Dies When The Workflow Switch Is Explicit

Suppose a batch problem fails on hidden tests.

Naive reaction:

- add more print statements
- rerun samples
- tweak random lines

Engineered reaction:

1. small hand case
2. brute-force oracle if possible
3. random differential testing through [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
4. escalate to [Local Judge Workflow](../../../notebook/local-judge-workflow.md) only if the task has protocol / validator complexity

The key insight is that the workflows are not interchangeable.

You lose a lot of time if you:

- keep stress-testing a protocol problem
- or build a heavy harness for a plain batch bug that a brute-force oracle would expose immediately

### Example 3: Triage Protects Progress Better Than Curiosity

Imagine a contest block where:

- Problem A: near-certain solve in 10 minutes
- Problem B: near-certain solve in 20 minutes
- Problem C: medium confidence, 35-minute modeling risk
- Problem D/E: unclear

The unengineered choice is often:

- jump to C because it looks interesting

The engineered choice is usually:

- lock A
- lock B
- then decide whether C is worth the next block

This is not a theorem. It is a systems invariant:

- early concrete progress lowers pressure and preserves optionality

That same logic appears in the track-specific pages, but the reusable engineering lesson is broader:

- protect high-confidence contest value before you optimize for brilliance

### Example 4: A Good Retrospective Ends In A Repo Change

Suppose the real loss was:

- you knew binary search on the answer was possible
- but wasted 15 minutes because the predicate / invariant was not written down cleanly

A weak retrospective says:

- “need to be more careful”

A strong retrospective says:

- update [Binary Search](../../foundations/patterns/binary-search/README.md) notes you reopen most
- add or tighten the corresponding binary-search template entry through the [Template Library](../../../template-library.md)
- schedule one retrieval-oriented [Mixed Round](../../../practice/mixed-rounds/README.md) that forces this pattern again

The durable change is the point.

Generic retrospective artifact:

```text
Failure class:
  theory / retrieval / debugging / triage

What actually went wrong:
  one sentence

What will change:
  one repo page, template, workflow, or rule

Where to rehearse it:
  one topic, mixed round, or playbook section
```

## Contest Loop Checklist

Use this as the short cross-track invariant checklist. Playbooks own any format-dependent substitution.

```text
Before:
  1. open the right build kit: notebook, templates, workflows
  2. make sure the local compile/run path is frictionless
  3. know which fallback workflows are available

During:
  1. scan and rank by confidence and expected contest value
  2. bank early high-confidence progress cleanly
  3. reopen assets deliberately, not reactively
  4. escalate debug workflow instead of guessing
  5. bail out when one focused block yields no concrete progress and another path is clearly better

After:
  1. classify the miss: theory, retrieval, debugging, or triage
  2. write one concrete fix into the repo or your workflow
  3. attach that fix to a future practice route
```

## Practice Archetypes

- inconsistent contest conversion despite decent topic depth
- repeated retrieval failures under time pressure
- repeated avoidable WA/TLE from poor testing escalation
- strong upsolve performance but weak live triage
- large practice volume with weak retention because review never hardens into system changes

## References And Repo Anchors

### Primary / Official

- ICPC World Finals, [Programming Environment](https://docs.icpc.global/worldfinals-programming-environment/)
- ICPC regional rules example, [NCNA rules page](https://nc.na.icpc.global/rules/)
- USACO, [Contest Instructions and Rules](https://usaco.org/index.php/current/tpcm/current/data/index.php?page=instructions)
- IOI, [Regulations](https://ioinformatics.org/files/regulations03.pdf)

### Reference

- KTH, [KACTL](https://github.com/kth-competitive-programming/kactl)
- [USACO Guide](https://usaco.guide/)
- track-specific strategy references live in [Contest Playbooks](../../../practice/contest-playbooks/README.md)

### Repo Anchors

- note: the workflows and defaults on this page are repo operating defaults synthesized from the playbooks and workflow pages below, not direct mandates from official rule documents
- contest-system hub: [Contest Playbooks](../../../practice/contest-playbooks/README.md)
- recall hub: [Notebook](../../../notebook/README.md)
- workflow hub: [Build Kit](../../../docs/build-kit.md)
- checklist: [Contest Checklist](../../../notebook/contest-checklist.md)
- stress loop: [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
- local harness loop: [Local Judge Workflow](../../../notebook/local-judge-workflow.md)
- retrieval drills: [Mixed Rounds](../../../practice/mixed-rounds/README.md)
- code retrieval: [Template Library](../../../template-library.md)

## Related Topics

- [Algorithm Engineering](../algorithm-engineering/README.md)
- [Constructive](../constructive/README.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)
- [Complexity And Hardness](../complexity-and-hardness/README.md)
