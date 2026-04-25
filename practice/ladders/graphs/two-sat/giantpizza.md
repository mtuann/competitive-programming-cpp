# Giant Pizza

- Title: `Giant Pizza`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1684](https://cses.fi/problemset/task/1684)
- Secondary topics: `2-SAT`, `Implication graph`, `SCC assignment extraction`
- Difficulty: `medium`
- Subtype: `Binary clause modeling with one recovered assignment`
- Status: `solved`
- Solution file: [giantpizza.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/two-sat/giantpizza.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the standard `2-SAT` route.

The statement is almost ideal:

- each topping is either included or excluded
- every person gives exactly two wishes
- at least one of those wishes must be satisfied
- any valid assignment is accepted

So the whole problem reduces directly to:

- binary variables
- 2-literal clauses
- implication graph
- SCC contradiction test
- assignment recovery

## Recognition Cue

Reach for `2-SAT` when:

- every object has exactly two states
- each constraint only talks about two literals
- the task asks for feasibility or one valid assignment
- pairwise logical constraints matter more than optimization

The strong smell here is:

- each family member contributes one clause with two wishes, and at least one wish must hold

That is almost the definition of a `2-CNF` instance.

## Problem-Specific Transformation

Let variable `x_i` mean:

- topping `i` is included on the pizza

Then:

- `+ i` becomes literal `x_i`
- `- i` becomes literal `not x_i`

Each family member gives a clause:

$$
(a \lor b)
$$

where `a` and `b` are those two literals.

That clause is rewritten as:

- `not a -> b`
- `not b -> a`

So the original problem becomes:

- build the implication graph on `2m` literals
- run SCC
- if some topping and its negation lie in the same SCC, print `IMPOSSIBLE`
- otherwise recover one assignment from SCC order

## Core Idea

Use the standard `2-SAT` construction.

For every topping `i`:

- one literal means `i` is included
- the other means `i` is excluded

For every family-member clause `(a or b)`:

- add implications `not a -> b` and `not b -> a`

Then:

- if literal `v` and `v ^ 1` are in the same SCC, the instance is unsatisfiable
- otherwise, the SCC order gives one valid truth assignment

The recovered truth values translate back to:

- `+` if the topping is included
- `-` if the topping is excluded

## Complexity

- `O(n + m)` over variables plus clause-derived implication edges
- in this statement that is linear in the number of toppings plus people/wishes

This easily fits the CSES limits.

## Pitfalls / Judge Notes

- Write down clearly whether `true` means `+` or `-` before building edges.
- The clause is `wish1 or wish2`, not “both must hold”.
- `exactly one` is **not** the constraint here; it is simply “at least one”.
- The output may be any valid assignment, so do not waste time forcing lexicographic behavior.

## Reusable Pattern

- Topic page: [2-SAT](../../../../topics/graphs/two-sat/README.md)
- Practice ladder: [Two-SAT ladder](README.md)
- Starter template: [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
- Notebook refresher: [Two-SAT hot sheet](../../../../notebook/two-sat-hot-sheet.md)
- Compare points: [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md), [Topological Sort And SCC](../../../../topics/graphs/scc-toposort/README.md)
- This note adds: the clean assignment-recovery layer on top of the SCC feasibility test.

## Solutions

- Code: [giantpizza.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/two-sat/giantpizza.cpp)
