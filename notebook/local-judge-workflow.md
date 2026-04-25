# Local Judge Workflow

This page is for the class of problems where "run the binary on stdin" is not enough.

- Trigger: interactive tasks, simulator-style judges, or hidden-state protocol tasks
- Inputs needed: a solution binary plus either fixed tests, a simulator, or a saved transcript / seed
- Output artifact: one reproducible failing transcript or enough evidence that the local harness is trustworthy
- Stop condition: one clean harness loop that you can rerun without guessing
- Pair with: [Foundations cheatsheet](foundations-cheatsheet.md), [Stress testing workflow](stress-testing-workflow.md), [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md), [Interactive Protocol Clinic 01](../practice/contest-playbooks/interactive-protocol-clinic-01.md)

Use it when:

- the task is interactive
- you want a local harness that behaves more like the real judge
- there is a simulator, hidden state, or query budget to enforce

If you are still on ordinary batch tasks like `Weird Algorithm` or `Missing Number`, this page is too early. Stay with the normal stdin/stdout loop from the [Foundations cheatsheet](foundations-cheatsheet.md) first.

If the harness exists but the leak is still `flush / budget / transcript / stop-condition`, pair this page with [Interactive Protocol Clinic 01](../practice/contest-playbooks/interactive-protocol-clinic-01.md).

## Which Workflow To Use Right Now

Choose this page only if simple stdin/stdout runs are not enough anymore:

- interactive protocol
- simulator or hidden-state harness
- query-budget enforcement

If the problem is still a normal batch task, go back to the [Foundations cheatsheet](foundations-cheatsheet.md) or, if trust is the issue, to [Stress testing workflow](stress-testing-workflow.md). If the task is batch but judged by a predicate or custom validator, go to [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md).

## Core Goal

Separate three roles clearly:

1. `solution`
2. `input generator` or fixed tests
3. `judge / validator / simulator`

When those roles are mixed together, debugging gets noisy very quickly.

## Minimum Setup

For most local-judge tasks, keep this file split:

- `sol.cpp`
- `judge.py` or `judge.cpp`
- optional `gen.cpp`
- one saved transcript or seed when something fails

This keeps the submission candidate clean while giving you one place to inspect protocol behavior.

## Interactive Baseline

For interactive problems, the default habits are:

- flush after every query or answer
- keep query count visible
- log judge-facing traffic to `stderr`, not `stdout`
- simulate the judge locally with a deterministic harness first

Minimal flush-safe pattern:

```cpp
cout << "? " << x << ' ' << y << endl;
```

or:

```cpp
cout << "? " << x << ' ' << y << '\n' << flush;
```

Never rely on accidental flushing.

## Recommended File Split

Use this shape when the task is complicated enough:

- `sol.cpp` for the actual submission candidate
- `judge.py` or `judge.cpp` for the local simulator
- optional `gen.cpp` for random instance generation

That keeps the contest binary clean while still letting you test protocol behavior.

## Batch Predicate Tasks

If the problem is not interactive but still needs a local validator for many valid answers or special judging, use [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md). This page is narrower: it is mainly for protocol loops, simulators, and hidden-state harnesses.

## Command-Line Loop

Typical local workflow:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic sol.cpp -o sol
python3 judge.py < input.txt
```

or, when the judge launches the solution:

```bash
python3 judge.py ./sol
```

For randomized protocol checks:

```bash
for seed in $(seq 1 200); do
  python3 judge.py ./sol "$seed" || break
done
```

The first goal is not “run many seeds.” The first goal is “make one seed fully reproducible.”

## Transcript Discipline

When debugging a local judge, keep one transcript per failure:

- seed
- initial hidden instance
- all queries and replies
- reason the judge rejected the run

This is much more useful than only seeing “Wrong Answer”.

## Query Budget Discipline

Interactive bugs are often not logic bugs, but process bugs:

- one extra query
- forgetting to stop after a final answer
- reading input after the protocol should have ended
- using buffered output without flushing

Make the harness enforce the query budget strictly.

## Done When

- the harness can reproduce one failure from a saved seed or transcript
- the protocol roles are clearly separated
- the solution no longer depends on accidental flushing
- one rerun command is stable enough that you would trust it tomorrow

## Good Pairings

- [Contest checklist](contest-checklist.md)
- [Stress testing workflow](stress-testing-workflow.md)
- [Anti-Hack Workflow](anti-hack-workflow.md)
- [Interactive Protocol Clinic 01](../practice/contest-playbooks/interactive-protocol-clinic-01.md)
- [Contest Engineering](../topics/advanced/contest-engineering/README.md)
