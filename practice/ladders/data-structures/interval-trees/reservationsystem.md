# Reservation System

- Title: `Reservation System`
- Judge / source: `AOJ 0360`
- Original URL: [https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360)
- Secondary topics: `Half-open intervals`, `Interval overlap`, `Augmented BST`
- Difficulty: `easy`
- Subtype: `Dynamic interval overlap predicate`
- Status: `solved`
- Solution file: [reservationsystem.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/interval-trees/reservationsystem.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Interval Trees`.

The benchmark is intentionally gentle:

- one new reservation `[a, b)`
- one set of existing reservations
- answer whether any overlap exists

That means the whole practice value is not raw difficulty.
It is the boundary lesson:

- the overlap predicate itself is exact and reusable
- the interval-tree augmentation is easy to see
- and you can still compare it honestly against lighter ordered-set logic

## Recognition Cue

Reach for the interval-tree worldview when:

- the input is a live set of intervals
- the query is "does anything overlap this new interval?"
- insert / erase / overlap all matter online
- you want an explicit conflicting interval witness, not only one aggregate count

The strongest smell here is:

- "check whether the new booking conflicts with the current bookings"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** force the heaviest possible data structure.

Because existing reservations are already pairwise non-overlapping, a lighter
ordered-set neighbor check can also solve it.

That is part of why the problem is a good flagship:

- it lets you drill the interval-tree overlap predicate
- without pretending the structure is mandatory on every reservation task

The interval-tree route is still clean:

1. insert each existing reservation `[s_i, f_i)` into one interval tree
2. query whether any stored interval overlaps `[a, b)`
3. print `1` if a conflict exists, else `0`

## Core Idea

The reusable pruning fact is:

- if one subtree has `max_r <= a`, then nothing in that subtree can overlap `[a, b)`

So one overlap query is not:

- scan every stored interval

It is:

- walk one BST ordered by left endpoints
- use subtree `max_r` to discard whole branches

That is the whole interval-tree lesson.

## Complexity

With the repo's treap-balanced interval-tree starter:

- build by `N` inserts: expected `O(N log N)`
- one overlap query: expected `O(log N)`
- memory: `O(N)`

For AOJ 0360 itself, `N <= 100`, so complexity is not the challenge.
The learning signal is the structure and the boundary.

## Input / Output Contract For This Repo

This benchmark uses:

- first line: new reservation `a b`
- second line: integer `N`
- next `N` lines: existing reservations `s_i f_i`

All intervals are half-open:

$$
[l, r)
$$

So touching at endpoints is **not** overlap.

The solution prints:

- `1` if any existing reservation overlaps `[a, b)`
- `0` otherwise

## Pitfalls / Judge Notes

- Do not treat endpoint touching as overlap.
- Keep the predicate as `max(l1, l2) < min(r1, r2)`.
- This benchmark is deliberately milder than the full lane.
- If you only need this exact AOJ task, a simpler ordered-set route is also acceptable; the repo solution uses interval-tree augmentation on purpose to teach the family.

## Reusable Pattern

- Topic page: [Interval Trees](../../../../topics/data-structures/interval-trees/README.md)
- Practice ladder: [Interval Trees ladder](README.md)
- Starter template: [interval-tree-overlap-treap.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/interval-tree-overlap-treap.cpp)
- Notebook refresher: [Interval Tree hot sheet](../../../../notebook/interval-tree-hot-sheet.md)
- Compare points:
  - [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
  - [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
  - [ODT / Chtholly](../../../../topics/data-structures/odt-chtholly/README.md)
- This note adds: the gentlest exact overlap benchmark before the lane branches into richer interval-set variants.

## Solutions

- Code: [reservationsystem.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/interval-trees/reservationsystem.cpp)
