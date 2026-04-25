# Matroid Intersection Hot Sheet

Use this page when the honest route is:

- one explicit ground set
- two independence systems that are actually matroids
- maximum **cardinality** common independent set

## Do Not Use When

- the task is weighted -> this starter is not weighted matroid intersection
- the ground set is huge or only implicit
- the real route is already [Matching](../topics/graphs/matching/README.md), [Maximum Flow](../topics/graphs/flow/README.md), or [XOR Basis / Linear Basis](../topics/math/xor-basis/README.md)
- you only want the theorem / certificate story -> use [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)

## Exact Route In This Repo

- current common independent set `Y`
- `Z1`: outside elements directly addable in `M1`
- `Z2`: outside elements directly addable in `M2`
- exchange graph with:
  - `y -> z` if swapping keeps `M1`
  - `z -> y` if swapping keeps `M2`
- shortest `Z1 -> Z2` path gives one augmentation

## Recognition Cues

- "pick one from each group but keep another independence property"
- partition / graphic / linear matroids appear naturally
- the intended proof smells like alternating exchanges, not cuts or DP states
- bipartite matching is a comparison point, not the actual end model

## Core Invariants

- `Y` stays independent in both matroids at every step
- arcs certify one-sided swap validity only
- the alternating path is what combines those one-sided swap certificates
- no `Z1 -> Z2` path means the current set is already maximum

## Main Traps

- forgetting that weighted MI is a different lane
- letting the oracles dominate runtime before the exchange graph even starts
- using the generic route where a specialized matching / xor-basis reduction is already smaller
- confusing "can add in `M1`" with "globally addable"

## Exact Starter In This Repo

- starter -> [`matroid-intersection-oracle.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/matroid-intersection-oracle.cpp)
- flagship rep -> [Pick Your Own Nim](../practice/ladders/advanced/matroid-intersection/pickyourownnim.md)
- theory sibling -> [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)

## Reopen Paths

- full tutorial -> [Matroid Intersection](../topics/advanced/matroid-intersection/README.md)
- compare point -> [Matching](../topics/graphs/matching/README.md)
- compare point -> [XOR Basis / Linear Basis](../topics/math/xor-basis/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)
