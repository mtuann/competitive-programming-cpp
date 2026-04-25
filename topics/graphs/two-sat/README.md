# 2-SAT

2-SAT is the cleanest graph tool for feasibility problems where:

- every variable is binary
- every constraint talks about at most two literals
- the task asks for `possible / impossible` or any one valid assignment

The reason it belongs in the graph section is not aesthetic. The real engine is:

- build the implication graph
- compress it into SCCs
- detect contradictions
- extract one assignment from the condensation order

So 2-SAT should be learned as a **specialized SCC reduction**, not as "Boolean logic for its own sake."

## At A Glance

Use this page when:

- each object has exactly two modes
- each condition says at least one of two literals must be true
- pairwise logical constraints dominate the statement
- you only need one feasible assignment, not the optimal one

Strong contest triggers:

- choose `yes / no`, `left / right`, `on / off`, `take / skip`
- each person gives two wishes and at least one must hold
- each item must choose one of two slots or sides
- constraints look like `a or b`, `if a then b`, `not both`, `exactly one`

Strong anti-cues:

- clauses regularly contain `3` or more literals
- variables have many states and there is no clean binary encoding yet
- the task is optimization-heavy rather than feasibility-heavy
- the bottleneck is counting all assignments, not finding one

What success looks like after studying this page:

- you can turn a clause into implication-graph edges without hesitation
- you can explain why `x` and `not x` in the same SCC is impossible
- you can recover one assignment from SCC order instead of only checking feasibility
- you know when to stop and say "this is no longer 2-SAT"

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [Topological Sort And SCC](../scc-toposort/README.md)

Helpful neighboring topics:

- [Reasoning And Implementation Discipline](../../foundations/reasoning/README.md)
- [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Problem Model And Notation

Let there be boolean variables:

$$
x_0, x_1, \dots, x_{n-1}.
$$

Each variable contributes two literals:

- `x_i`
- `not x_i`

A 2-CNF formula is a conjunction of clauses:

$$
(\ell_1 \lor r_1)\ \land\ (\ell_2 \lor r_2)\ \land\ \cdots
$$

where each `\ell_k` and `r_k` is a literal.

The implication graph has one vertex for every literal. For one clause:

$$
(a \lor b),
$$

we add two implications:

$$
\neg a \to b,\qquad \neg b \to a.
$$

This graph is the whole problem. Feasibility and assignment extraction both come from it.

## From Brute Force To The Right Idea

### Brute Force

If there are `n` binary variables, brute force tries all:

$$
2^n
$$

assignments and checks every clause.

That is already hopeless at contest scales.

### Why The Clause Structure Is Special

A clause:

$$
(a \lor b)
$$

fails only in one case:

- `a = false`
- `b = false`

Equivalently:

- if `a` is false, then `b` must be true
- if `b` is false, then `a` must be true

So each clause is really a pair of implications.

This changes the problem from:

- search over assignments

into:

- reason about forced consequences in a directed graph

### Why SCCs Appear Naturally

If the graph contains both:

$$
x \leadsto \neg x
$$

and

$$
\neg x \leadsto x,
$$

then `x` and `not x` force each other. That means:

- assuming `x` true eventually forces `x` false
- assuming `x` false eventually forces `x` true

So the contradiction is not local to one clause. It is structural across the implication graph.

That is exactly what SCCs capture.

## Core Invariant And Why It Works

### 1. Clause-To-Implication Equivalence

For one clause:

$$
(a \lor b),
$$

the only invalid assignment is:

$$
a = false,\quad b = false.
$$

So:

- if `a` is false, `b` must be true
- if `b` is false, `a` must be true

Therefore:

$$
(a \lor b)\quad\Longleftrightarrow\quad (\neg a \to b)\ \land\ (\neg b \to a).
$$

This is the one rewrite you must trust completely.

### 2. Why `x` And `not x` In One SCC Means Impossible

Suppose `x` and `not x` lie in the same SCC.

Then:

$$
x \leadsto \neg x
$$

and

$$
\neg x \leadsto x.
$$

If you set `x = true`, the implications force `not x = true`.
If you set `x = false`, then `not x = true`, and the implications force `x = true`.

So either choice forces a contradiction.

Hence:

> A 2-SAT instance is unsatisfiable if some variable and its negation belong to the same SCC.

### 3. Why Separation Of SCCs Is Enough

Now assume every variable `x` satisfies:

$$
\mathrm{SCC}(x) \ne \mathrm{SCC}(\neg x).
$$

Compress the implication graph into its condensation DAG.

Because the condensation graph is a DAG, its components have a topological order. If we process SCCs in reverse topological order and decide a variable by whichever literal appears later than its complement, we never create a forward contradiction.

Contest implementation version:

- run SCC decomposition
- if `comp[x] == comp[not x]`, answer `IMPOSSIBLE`
- otherwise assign:

$$
x = true \quad\text{iff}\quad \mathrm{comp}(x) > \mathrm{comp}(\neg x)
$$

when the SCC ids come from the standard Kosaraju/Tarjan extraction order used in the starter

The real idea is not the comparison sign itself. The real idea is:

- choose the literal whose component is later in the condensation order
- that choice cannot be forced false by any still-unresolved implication

### 4. Why Assignment Extraction Works

Take a variable `x`.

Its two literals live in different SCCs. One of those SCCs appears later in the condensation DAG than the other. Set the later one to `true` and the earlier one to `false`.

Why is this safe?

- if a chosen true literal implied some false chosen literal, then there would be a path from the later SCC to an earlier SCC that should already have forced the earlier choice
- reverse-topological choice prevents that

This is why 2-SAT is more than a yes/no SCC test: the same condensation order also gives a witness assignment.

## Common Clause Rewrites

These are the rewrites you want to do almost mechanically.

### At Least One

$$
a \lor b
$$

Add:

- `not a -> b`
- `not b -> a`

### Implication

$$
a \to b
$$

Rewrite as:

$$
\neg a \lor b
$$

### Not Both

$$
\neg(a \land b)
$$

Rewrite as:

$$
\neg a \lor \neg b
$$

### Exactly One

Exactly one of `a` and `b` means:

$$
(a \lor b)\ \land\ (\neg a \lor \neg b).
$$

So `exactly one` is two 2-SAT clauses, not one magical primitive.

## Worked Examples

### 1. Giant Pizza

Let variable `x_i` mean:

- topping `i` is included

Then:

- `+ i` becomes literal `x_i`
- `- i` becomes literal `not x_i`

If one family member says:

$$
(+1)\ \text{or}\ (-3),
$$

the clause is:

$$
x_1 \lor \neg x_3.
$$

So we add:

- `not x_1 -> not x_3`
- `x_3 -> x_1`

After all clauses are added, the problem is exactly:

- feasibility of one 2-CNF formula
- plus extraction of one assignment

### 2. Two Time Slots For One Event

Suppose event `i` may be placed in:

- early slot
- late slot

Let `x_i = true` mean early.

If events `i` and `j` cannot both be early, that is:

$$
\neg(x_i \land x_j),
$$

which becomes:

$$
\neg x_i \lor \neg x_j.
$$

This is still a 2-SAT clause.

### 3. Exactly One Of Two Modes

If an object must choose exactly one of `A` or `B`, then one boolean variable already encodes that:

- `x = true` means `A`
- `x = false` means `B`

Do **not** create two unrelated booleans unless the statement really needs them.

That modeling discipline often decides whether the reduction stays small and clean.

## Complexity And Tradeoffs

With `n` boolean variables and `m` clauses:

- vertices = `2n`
- edges = `2m`

Using SCC on the implication graph:

- time: `O(n + m)`
- memory: `O(n + m)`

This is why 2-SAT is contest-core while general SAT is not.

Tradeoffs:

- 2-SAT is great for feasibility with binary choices
- it is the wrong tool when clause width grows
- it is also the wrong tool when the real problem is optimization rather than satisfiability

## Algorithm And Pseudocode

```text
build graph on 2 * n literals

for each clause (a or b):
    add edge (not a -> b)
    add edge (not b -> a)

run SCC decomposition

for each variable x:
    if scc(x) == scc(not x):
        return impossible

for each variable x:
    x = (scc(x) comes later than scc(not x))

return assignment
```

## Implementation Notes

### Literal Encoding

A standard encoding is:

- `2 * i` = literal `x_i`
- `2 * i + 1` = literal `not x_i`

Then the complement is just:

```cpp
v ^ 1
```

That keeps clause code small and reliable.

### Keep Statement Semantics Explicit

Always write down:

- what `true` means
- what `false` means

before you build the graph.

Most 2-SAT bugs are not SCC bugs. They are:

- wrong modeling of the boolean meaning
- wrong complement edges
- wrong statement-to-literal translation

### Assignment Extraction Needs A Trusted SCC Order

Do not compare SCC ids blindly unless you trust the decomposition order used by your starter.

The repo starter uses the standard SCC-order extraction where:

```cpp
assignment[i] = comp[true_literal] > comp[false_literal];
```

is correct.

## Practice Archetypes

The most common 2-SAT tasks look like:

- each item has two modes
- pairwise constraints eliminate some combinations
- the output is `YES/NO` or any one valid assignment
- scheduling / seating / switch / sign choices reduce to two literals per clause

The strongest smell is:

- feasibility with binary choices and pairwise logical constraints

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary:

- [Aspvall, Plass, Tarjan - A linear-time algorithm for testing the truth of certain quantified Boolean formulas](https://collaborate.princeton.edu/en/publications/a-linear-time-algorithm-for-testing-the-truth-of-certain-quantifi-2/)

Reference:

- [CP-Algorithms - 2-SAT](https://cp-algorithms.com/graph/2SAT.html)
- [OI Wiki - 2-SAT](https://en.oi-wiki.org/graph/2-sat/)

Practice:

- [CSES - Giant Pizza](https://cses.fi/problemset/task/1684)
- [Codeforces - The Door Problem](https://codeforces.com/problemset/problem/776/D)
- [Library Checker - two_sat](https://judge.yosupo.jp/problem/two_sat)

Repo anchors:

- flagship note -> [Giant Pizza](../../../practice/ladders/graphs/two-sat/giantpizza.md)
- starter -> [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
- retrieval sheet -> [Two-SAT hot sheet](../../../notebook/two-sat-hot-sheet.md)
- SCC foundation -> [Topological Sort And SCC](../scc-toposort/README.md)
- modeling bridge -> [Graph Modeling](../graph-modeling/README.md)

## Related Topics

- [Topological Sort And SCC](../scc-toposort/README.md)
- [Graph Modeling](../graph-modeling/README.md)
- [Graphs ladder](../../../practice/ladders/graphs/README.md)
