# Stress Testing Workflow

This page is the shortest reusable route from “I think the idea is right” to “I have actual evidence that the implementation is trustworthy.”

Use it when:

- your fast solution is nontrivial enough that a few hand tests do not feel convincing
- the bug is probably in implementation details, not in the high-level algorithm choice
- you can write a slower checker, brute-force solver, or property validator on small cases

## Fast Loop

The default loop is:

1. write the clearest correct fast solution you can
2. write a tiny brute-force or slower checker for small limits
3. generate many small random tests
4. compare outputs or compare a shared invariant
5. stop only after the first mismatch is explained

If a problem has many valid answers, do **not** compare raw output strings. Compare a predicate or a normalized property instead.

## Compile Baseline

Use the same baseline flags the repo already recommends:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic fast.cpp -o fast
c++ -std=c++20 -O2 -Wall -Wextra -pedantic brute.cpp -o brute
c++ -std=c++20 -O2 -Wall -Wextra -pedantic gen.cpp -o gen
```

That does two jobs at once:

- catches avoidable warnings early
- keeps local verification closer to the contest build you actually use

## Three Levels Of Confidence

### 1. Hand Cases

Start with a few hand-written tests before any automation:

- smallest valid input
- smallest invalid or edge-shaped input
- all-equal / already-sorted / reverse-sorted cases
- repeated values if the problem allows them
- the exact boundary where your branch logic changes

This stage is about catching obvious model mistakes quickly.

### 2. Brute-Force Comparison

If the constraints allow a tiny checker, compare the fast solution against it.

Typical pattern:

```bash
for seed in $(seq 1 2000); do
  ./gen "$seed" > input.txt
  ./fast < input.txt > fast.txt
  ./brute < input.txt > brute.txt
  diff -u fast.txt brute.txt || break
done
```

Use this when:

- the answer is unique
- the brute-force output format matches the fast one exactly

### 3. Property-Based Checking

For constructive problems or problems with many valid outputs, compare properties instead of exact answers.

The checker should answer:

- is the output well-formed?
- does it satisfy the statement?
- does it hit the required counts or invariants?

Examples:

- permutation really uses `1..n` exactly once
- number of local maxima/minima matches the request
- returned path is legal and has the claimed length
- printed sequence of moves is valid at every step

## Construction Problems

For constructive tasks, the best local verifier is usually a dedicated predicate checker.

The order should be:

1. write a validator for one output
2. use the validator on hand cases
3. only then generate random small inputs

Do not compare against one “reference construction” if the problem accepts many different valid answers.

Instead, validate:

- domain correctness
- invariants after every operation
- final-state correctness

## Generator Habits

Good random generators:

- stay inside the real constraints of the statement
- hit edge regimes on purpose, not just uniform random noise
- accept a seed so failures are reproducible

Once a mismatch appears, freeze that case into a permanent hand test or note snippet.

## What To Print On Mismatch

When the first failure appears, print enough context to reproduce it instantly:

- seed
- generated input
- fast output
- checker output or brute output
- one short explanation of the first violated invariant, if known

Do not keep testing past the first unexplained mismatch.

## Interactive And Judge-Like Tasks

When the task is interactive or protocol-heavy, local checking changes a bit:

- verify flushing discipline
- verify query count or operation count
- simulate the judge with a small deterministic harness if possible
- log the transcript of one failing run

For those tasks, local confidence often comes more from protocol simulation than from random brute force.

## When To Stop

You are usually ready to submit when:

- warnings are clean
- hand cases pass
- small brute-force comparison or property checking passes for many seeds
- the first boundary cases around each branch condition have been exercised deliberately

The goal is not “prove the program correct by testing.” The goal is to make hidden implementation mistakes very hard to survive.

## Good Pairings

- [Contest checklist](contest-checklist.md)
- [Template library](../template-library.md)
- [Algorithm Engineering](../topics/advanced/algorithm-engineering/README.md)
- [Contest Engineering](../topics/advanced/contest-engineering/README.md)
