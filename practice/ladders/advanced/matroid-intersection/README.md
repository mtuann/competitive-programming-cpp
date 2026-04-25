# Matroid Intersection Ladder

## Who This Is For

Use this ladder when the hidden object is one common independent set of two matroids, not one ordinary graph structure or one plain xor basis.

## Warm-Up

- tell ordinary matching apart from "matching as one example of matroid intersection"
- say what `Z1`, `Z2`, and the exchange graph mean

## Core

- maximum-cardinality common independent set
- shortest augmenting path in the exchange graph
- recognize when one side is partition and the other is linear

## Repo Anchors

- [Pick Your Own Nim](pickyourownnim.md)
- [Optimization And Duality](../optimization-and-duality/README.md)
- [Matching tutorial](../../../../topics/graphs/matching/README.md)
- [XOR Basis tutorial](../../../../topics/math/xor-basis/README.md)

## Stretch

- explain why bipartite matching is the intersection of two partition matroids
- read one weighted-matroid-intersection source and decide why it does **not** belong in the exact starter route here

## Compare Points

- hidden matching via two partition constraints -> [Matching](../../../../topics/graphs/matching/README.md)
- pure xor-span independence without a second matroid -> [XOR Basis / Linear Basis](../../../../topics/math/xor-basis/README.md)
- continuous optimization instead of combinatorial exchange -> [Simplex](../simplex/README.md)
- exact theorem / certificate lens -> [Optimization And Duality](../optimization-and-duality/README.md)

This ladder is intentionally sparse. The point is not to collect many generic matroid-intersection reps. The point is to know when the model is real and when to exploit structure once it is.

## Exit Criteria

You are ready to move on when you can:

- recognize one common-independent-set model without forcing it everywhere
- build the exchange graph for one current set `Y`
- explain why `Pick Your Own Nim` is really `linear matroid + partition matroid`
- reject the generic route quickly when matching / flow / xor basis is already cleaner

## External Practice

- [Codeforces Gym 102156 D - Pick Your Own Nim](https://codeforces.com/gym/102156/problem/D)
- [Extremal Combinatorics notes: Matroid Intersection](https://extremalcombinatorics.com/optimization/notes/sec_matroidIntersection.html)

## Tutorial Link

- [Matroid Intersection](../../../../topics/advanced/matroid-intersection/README.md)
