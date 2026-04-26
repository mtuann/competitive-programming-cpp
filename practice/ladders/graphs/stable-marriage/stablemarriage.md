# Stable Marriage

- Title: `Stable Marriage`
- Judge / source: `Canonical Gale-Shapley benchmark`
- Original URL: [https://www.ams.org/publicoutreach/feature-column/fc-2015-03](https://www.ams.org/publicoutreach/feature-column/fc-2015-03)
- Secondary topics: `Deferred acceptance`, `Blocking pairs`, `Proposer-optimal stable matching`
- Difficulty: `medium`
- Subtype: `Equal-size stable matching with complete strict preferences`
- Status: `solved`
- Solution file: [stablemarriage.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/stable-marriage/stablemarriage.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Stable Marriage`.

The benchmark is intentionally canonical instead of judge-idiosyncratic:

- `n` proposers
- `n` accepters
- each side gives one strict permutation of the other side
- print one stable matching

So the hard part is exactly the lane itself:

- recognize that stability is the objective
- trust deferred acceptance
- keep the boundary against assignment and cardinality matching sharp

## Recognition Cue

Reach for Gale-Shapley when:

- each side ranks the other side
- every participant must end matched
- the statement forbids blocking pairs, envy pairs, or mutually preferred deviations
- any stable witness is accepted

The strongest smell here is:

- "find a stable matching under two-sided preferences"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** want:

- Hopcroft-Karp, because the objective is not maximum number of pairs
- Hungarian, because there is no additive cost matrix to optimize
- min-cost flow, because the whole point is stability under preferences, not transport under capacities

The clean route is:

1. let proposers walk their lists from best to worst
2. let each accepter keep only the best proposal seen so far
3. requeue any rejected proposer
4. stop when nobody is free with remaining options

That is exactly Gale-Shapley deferred acceptance.

## Core Idea

The useful monotone fact is:

- once accepter `a` rejects proposer `p`, `a` will never end with anyone worse than `p`

So rejections are permanent.

That means each proposer advances only forward through the list, and the whole process makes at most `n^2` proposals.

When the queue empties, no blocking pair can remain:

- if proposer `p` preferred accepter `a` over the final partner, then `p` must have proposed to `a` earlier
- so `a` rejected `p` in favor of someone preferred more
- therefore `a` cannot prefer `p` over the final partner

That contradiction is the stability proof.

## Complexity

- Gale-Shapley with inverse rank tables: `O(n^2)`
- memory: `O(n^2)` for the two preference tables plus accepter-rank lookup

## Input / Output Contract For This Repo

This repo's canonical benchmark uses:

- one integer `n`
- next `n` lines: proposers' preference lists, each a permutation of `1..n`
- next `n` lines: accepters' preference lists, each a permutation of `1..n`

The solution prints:

- `n` lines
- line `i` prints `i matched_partner`
- both ids are `1`-based

Any stable perfect matching is acceptable for this benchmark contract.
The repo solution prints the proposer-optimal one produced by Gale-Shapley.

## Pitfalls / Judge Notes

- Stability is **not** the same as minimum total rank sum.
- The proposing side matters.
- Precompute `rank[a][p]` so one preference comparison is `O(1)`.
- Convert to `0`-based internally even if the I/O stays `1`-based.

## Reusable Pattern

- Topic page: [Stable Marriage](../../../../topics/graphs/stable-marriage/README.md)
- Practice ladder: [Stable Marriage ladder](README.md)
- Starter template: [gale-shapley-stable-marriage.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gale-shapley-stable-marriage.cpp)
- Notebook refresher: [Stable Marriage hot sheet](../../../../notebook/stable-marriage-hot-sheet.md)
- Compare points:
  - [Matching](../../../../topics/graphs/matching/README.md)
  - [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
- This note adds: the clean canonical benchmark where stability itself is the target, not only a modeling detail under some larger flow or assignment story.

## Solutions

- Code: [stablemarriage.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/stable-marriage/stablemarriage.cpp)
