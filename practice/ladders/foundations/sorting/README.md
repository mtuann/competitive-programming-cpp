# Sorting Ladder

Sorting is often the first nontrivial preprocess that turns a messy problem into a clean one-pass solution.

## Who This Is For

Use this ladder if:

- you know `sort`, but not when sorting is the main trick
- greedy-after-sorting proofs still feel magical
- custom comparators are still a source of bugs

## Warm-Up

- sort integers
- sort pairs by first key
- sort records by one field

Target skill:

- become comfortable with `sort` and simple comparators

## Core

- greedy after sorting
- interval ordering
- adjacent-pair reasoning after sorting
- event ordering for sweep-style processing

Target skill:

- recognize when ordering creates the needed structure

## Stretch

- comparator-heavy problems with careful tie rules
- prove one greedy-after-sorting solution with an exchange argument
- compare `sort`, `stable_sort`, and `nth_element` on suitable tasks

Target skill:

- connect sorted order to the proof, not just the code

## Exit Criteria

You are ready to move on when:

- you instinctively ask “what happens if I sort this?”
- you can write safe comparators quickly
- you can justify why the sorted order is valid for the algorithm

## External Practice

- [CSES Sorting and Searching](https://cses.fi/problemset/)
- [USACO Guide](https://usaco.guide/)
- [CPPReference - sort](https://en.cppreference.com/w/cpp/algorithm/sort)

## Tutorial Link

- [Sorting](../../../../topics/foundations/patterns/sorting/README.md)
