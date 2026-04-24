# Binary Search Ladder

Binary search practice should build confidence in monotonicity and boundary control, not just memorization of one loop.

## Who This Is For

Use this ladder if:

- you can code binary search, but still mistrust the final answer
- `lower_bound` makes sense but answer-search feels shaky
- hidden tests often expose endpoint mistakes

## Warm-Up

- search in a sorted array
- first position `>= x`
- last position `<= x`

Target skill:

- understand what the returned index means

## Core

- binary search on answer
- feasibility predicates
- monotone capacity, time, or threshold questions

Target skill:

- define one monotone predicate and one stable boundary convention

## Repo Anchor

- [Factory Machines](factorymachines.md): a strong first answer-search note because the predicate is simple and the boundary meaning is easy to explain.

## Stretch

- combine binary search with prefix sums or greedy checking
- compare `lower_bound` style search with answer-search
- rewrite one solution in both “first true” and “last false” style

Target skill:

- treat binary search as invariant management, not magic

## Exit Criteria

You are ready to move on when:

- you can explain why `l` and `r` are initialized the way they are
- you know whether the final answer is `l` or `r`
- you can spot non-monotone checks before writing the loop

## External Practice

- [USACO Guide - Binary Search](https://usaco.guide/silver/binary-search)
- [CSES Problem Set](https://cses.fi/problemset/)
- [CP-Algorithms - Binary Search](https://cp-algorithms.com/num_methods/binary_search.html)

## Tutorial Link

- [Binary Search](../../../../topics/foundations/patterns/binary-search/README.md)
