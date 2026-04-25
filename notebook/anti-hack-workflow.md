# Anti-Hack Workflow

This page is the shortest reusable route from:

- “the code passed samples and pretests”

to:

- “I have actually tried to break my own assumptions before someone else or a rejudge does it for me”

- Trigger: hack-sensitive rounds, open-hack phases, constructive tasks, or suspicious “accepted-looking” code with fragile assumptions
- Inputs needed: one candidate solution plus either a vulnerability table, a checker, a validator, or a tiny brute-force model
- Output artifact: one concrete counterexample family, one failing test, or one signed-off vulnerability table
- Stop condition: the first unexplained vulnerability is localized, or all main vulnerability families have been checked honestly
- Pair with: [Stress testing workflow](stress-testing-workflow.md), [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md), [Local judge workflow](local-judge-workflow.md), [Contest checklist](contest-checklist.md)

Use it when:

- the round has open hacks or explicit rejudge dynamics
- the task is constructive or has many valid answers
- the idea is probably right, but one hidden corner case could still sink it
- you want a faster and more adversarial loop than vague “more hand tests”

Do **not** open this page first if:

- the topic itself is still unknown
- the solution does not even pass obvious hand cases
- the real problem is interactive protocol handling, not adversarial batch testing

## Which Workflow To Use Right Now

Choose this page only if you already mostly trust the main idea and now need to attack its assumptions.

- ordinary unique-answer batch task, trust is low -> [Stress testing workflow](stress-testing-workflow.md)
- constructive / many-valid-answers / open-hack fear -> this page, then pair with [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md) if legality is predicate-checked
- interactive protocol or simulator-heavy task -> [Local judge workflow](local-judge-workflow.md)

## Core Goal

Separate three different jobs:

1. `solve`
2. `validate`
3. `attack`

Many failed CF submissions skip job `3`.

The goal here is to create one short adversarial loop that asks:

- what hidden assumption would a hacker, rejudge, or stronger testcase generator try first?

## Minimum Anti-Hack Artifact

Keep one compact table while checking a fragile solution:

| assumption | smallest breaker | generator family | status |
| --- | --- | --- | --- |
|  |  |  | `unchecked / passed / broke` |

If you cannot fill this table with at least `3-5` meaningful assumptions, you are probably trusting the code too emotionally.

## Fast Loop

Default anti-hack loop:

1. write the candidate solution
2. list the hidden assumptions it seems to rely on
3. try to generate the *smallest* legal breaker for each assumption
4. if the answer is not unique, validate the contract instead of comparing raw outputs
5. stop at the first unexplained break

The goal is not to produce hundreds of random tests.

The goal is to attack the exact assumptions that feel “probably fine.”

## Standard Vulnerability Families

When you do not know where to start, attack these first:

- smallest legal input
- largest legal input or type-width boundary
- all-equal values
- all-distinct values
- duplicates clustered in one block
- already-sorted or reverse-sorted order
- one-element or one-interval special case
- parity / odd-even boundary
- impossible case that the main loop quietly assumes away
- disconnected / empty / isolated structure

These families catch a surprising fraction of Codeforces leaks.

## Constructive And Many-Answer Tasks

For constructive tasks, anti-hack starts with a validator, not with one guessed “reference answer.”

Default order:

1. write the output contract
2. write the validator or predicate checker
3. only then search for break cases

Typical validator checks:

- output format
- domain validity
- per-step legality
- final property required by the statement

If the task accepts many outputs, exact-output comparison is usually the wrong tool.

## Tiny Brute Or Property Model

When a small oracle is possible, use it.

Typical split:

- `fast.cpp` = contest candidate
- `brute.cpp` = tiny correct model on small cases
- `gen.cpp` = seed-based generator
- `check.cpp` or predicate = contract validator if exact answers are not unique

If no brute-force answer exists, use a property checker and attack the output contract instead.

## Hack-Or-Solve Decision Rule

In an open-hack round, do **not** brute-force hacks forever just because hacking exists.

Switch into hack mode only if:

- the next clean solve is currently lower EV
- and you have one precise vulnerability family to test

If you do not have a precise failing family after a few focused minutes, go back to solving.

Anti-hack discipline is still about contest conversion, not about role-playing as a hacker forever.

## Good Counterexample Habits

When the first break appears, freeze it immediately:

- save the exact input
- save the seed if the test was generated
- write one line for the violated assumption
- decide whether the bug is:
  - model
  - implementation
  - type-width / overflow
  - many-answer validation
  - statement-reading drift

This is much better than simply remembering “there was some weird case.”

## Output Before Submission

Before trusting one fragile solution, answer:

| Check | Your answer |
| --- | --- |
| smallest legal case checked? |  |
| worst-looking boundary checked? |  |
| duplicate / parity / impossible family checked? |  |
| validator or brute route used if needed? |  |
| first real hidden assumption written down? |  |

If two or more rows are blank, the solution is not anti-hack-ready yet.

## Done When

- the first suspicious assumption has either been broken or defended with a concrete test family
- one constructive or many-answer task has a validator you actually trust
- a future rerun would reproduce the same break immediately
- you can say *why* the code feels robust now, not only that it passed more tests

## Good Pairings

- [Stress testing workflow](stress-testing-workflow.md)
- [Local judge workflow](local-judge-workflow.md)
- [Contest checklist](contest-checklist.md)
- [Codeforces Playbook](../practice/contest-playbooks/codeforces.md)
- [Constructive](../topics/advanced/constructive/README.md)
