# Heaps And Ordered Sets Ladder

This ladder is about operation choice: learn to pick heap, set, or multiset from what the problem needs, not from whatever container you used last.

## Who This Is For

Use this ladder if:

- you know the syntax, but still choose the wrong structure
- duplicates and stale values still trip you up
- active-set problems feel ad hoc

## Warm-Up

- current minimum / maximum maintenance
- scheduling with a heap

Target skill:

- recognize when “only the best candidate matters”

## Core

- active interval sets
- sliding median style maintenance
- predecessor / successor queries

Target skill:

- reason from operations: insert, erase, top, predecessor, successor, duplicates

## Stretch

- lazy deletion patterns
- compare heap and set solutions on the same task
- decide when PBDS or order-statistics logic is actually needed

Target skill:

- avoid overengineering while still choosing the right dynamic ordered structure

## Retrieval Layer

- stale heap cleanup -> [heap-lazy-delete.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/heap-lazy-delete.cpp)
- predecessor in active multiset -> [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp)
- sliding median maintenance -> [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- exact rank / `k`-th route -> [PBDS / Order Statistics Tree ladder](../pbds-order-statistics/README.md)
- quick reminder sheet -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Exit Criteria

You are ready to move on when:

- you know when `multiset` is required
- you can explain why lazy deletion is often the easiest heap cleanup strategy
- you no longer use ordered sets when a plain heap is enough

## External Practice

- [CSES Sorting and Searching](https://cses.fi/problemset/)
- [USACO Guide](https://usaco.guide/)
- [CPPReference](https://en.cppreference.com/w/)

## Tutorial Link

- [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
