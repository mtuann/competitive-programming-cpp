# Local Judge Workflow

This page is for the class of problems where “run the binary on stdin” is not enough.

Use it when:

- the task is interactive
- the output can have many valid forms and needs a validator
- you want a local harness that behaves more like the real judge

## Core Goal

Separate three roles clearly:

1. `solution`
2. `input generator` or fixed tests
3. `judge / validator / simulator`

When those roles are mixed together, debugging gets noisy very quickly.

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

## Local Validator Pattern

For constructive or multi-answer tasks, a local validator should check:

- output format
- domain validity
- per-step legality
- final target condition

Examples:

- a printed permutation really uses each value once
- a cut or matching certificate is valid
- a move sequence never violates the rules

If the problem has many correct answers, this validator matters more than a brute-force reference output.

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

## Good Pairings

- [Contest checklist](contest-checklist.md)
- [Stress testing workflow](stress-testing-workflow.md)
- [Contest Engineering](../topics/advanced/contest-engineering/README.md)
