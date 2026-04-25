# Segment Tree Beats Ladder

This lane is for the first moment when "lazy propagation" is no longer enough because the update family depends on the segment distribution itself.

## Who This Is For

Use this lane if:

- ordinary segment tree already feels routine
- additive or assign-style lazy tags are no longer the hard part
- you now see `range chmin` / `range chmax` style updates
- you want the canonical Beats lane, not just one narrow modulo trick

## Warm-Up

- [Dynamic Range Sum Queries](../segment-tree/dynamicrangesumqueries.md)
- [HORRIBLE - Horrible Queries](../lazy-segment-tree/horriblequeries.md)

Target skill:

- say clearly why ordinary lazy tags work for `range add` but not for generic `chmin/chmax`

## Core

- stronger `tag condition` instead of unconditional full-cover tags
- `max1 / max2 / maxc` and `min1 / min2 / minc`
- one exact flagship verifier-style rep: [Range Chmin Chmax Add Range Sum](rangechminchmaxaddrangesum.md)

Target skill:

- explain in words when only the current maxima or minima change, and why that makes the node update `O(1)`

## Stretch

- compare the canonical lane against [The Child and Sequence](https://codeforces.com/problemset/problem/438/D), where the pruning idea is beats-like but narrower
- revisit historic-information or modulo variants later, after the canonical lane is stable
- combine this with tree reductions only after HLD / Euler flattening already feels automatic

Target skill:

- know when the repo starter fits exactly, and when a problem belongs to a beats-inspired custom implementation instead

## Retrieval Layer

- exact quick sheet -> [Segment Tree Beats hot sheet](../../../../notebook/segment-tree-beats-hot-sheet.md)
- exact starter -> [segment-tree-beats.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp)
- compare against simpler lazy route -> [Lazy Segment Tree hot sheet](../../../../notebook/lazy-segment-tree-hot-sheet.md)
- parent chooser -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Exit Criteria

You are ready to move on when:

- you can state the break condition and the stronger tag condition for both `chmin` and `chmax`
- you know why second extrema matter
- you can tell whether a problem needs canonical Beats or only a beats-like custom pruning trick

## External Practice

- [Library Checker - Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)
- [Codeforces - The Child and Sequence](https://codeforces.com/problemset/problem/438/D)

## Tutorial Link

- [Segment Tree Beats](../../../../topics/data-structures/segment-tree-beats/README.md)
