# Line Add Get Min

- Title: `Line Add Get Min`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/line_add_get_min](https://judge.yosupo.jp/problem/line_add_get_min)
- Secondary topics: `LineContainer`, `Convex hull trick`, `Online line minimum`
- Difficulty: `medium`
- Subtype: `Direct verifier for full-domain online add-line / query-min with arbitrary integer x queries`
- Status: `solved`
- Solution file: [lineaddgetmin.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/cht-li-chao/lineaddgetmin.cpp)

## Why Practice This

This is the cleanest exact in-repo anchor for the **LineContainer** refinement inside the `CHT / Li Chao` family.

The statement strips away DP modeling and leaves only the container contract:

- add a line `y = ax + b`
- query the minimum value at one integer `x`

So the lesson is not "derive the affine transform."

It is:

- know one second exact route beside Li Chao
- maintain the lower envelope by slope order and breakpoint ownership
- use LineContainer when the x-domain does not need to be declared up front and every line is active everywhere

## Recognition Cue

Reach for `LineContainer` when:

- lines are added online
- queries are online
- every line is active on the full domain
- x-queries are arbitrary integers
- you do not want to predeclare or discretize the x-domain

The strongest smell here is:

```text
online add-line / query-best with no bounded x-domain story in the statement.
```

## Problem-Specific Transformation

No extra DP modeling is needed.

Store every inserted affine function:

$$
y = ax + b
$$

inside one line container that maintains the current lower envelope.

Then:

- query type `0 a b` -> `add_line(a, b)`
- query type `1 p` -> `query(p)`

That is the whole problem.

## Core Idea

Keep lines ordered by slope.

For each line, store one breakpoint:

```text
p = the last integer x where this line is still the best one
```

Then:

- insertion fixes only neighboring breakpoints
- queries binary-search by `x` over those breakpoints

The exact in-repo starter implements a minimum container by:

- reusing the classic maximum-envelope multiset trick
- negating slope/intercept to turn min into max internally

That keeps the public API small while preserving the usual breakpoint invariant.

## Complexity

- add line: amortized `O(log n)`
- query: `O(log n)`
- memory: `O(n)`

This fits the official verifier comfortably.

## Pitfalls / Judge Notes

- This route assumes **full-domain** lines, not segment-limited lines.
- Breakpoints are for **integer x**, so the floor-division convention matters.
- Equal slopes must keep only the better intercept.
- Use `__int128` for `k * x + m` during evaluation to avoid overflow surprises.
- If x-domain is already known and bounded, Li Chao can be the simpler exact route.

## Reusable Pattern

- Topic page: [Convex Hull Trick / Li Chao Tree](../../../../topics/dp/cht-li-chao/README.md)
- Practice ladder: [CHT / Li Chao ladder](README.md)
- Starter template: [line-container.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/line-container.cpp)
- Notebook refresher: [CHT / Li Chao hot sheet](../../../../notebook/cht-hot-sheet.md)
- Compare points:
  - [Monster Game II](monstergame2.md)
  - [Library Checker - Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min)
- This note adds: the exact full-domain line-container route where breakpoint search replaces midpoint recursion.

## Solutions

- Code: [lineaddgetmin.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/cht-li-chao/lineaddgetmin.cpp)
