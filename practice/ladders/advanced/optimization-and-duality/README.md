# Optimization And Duality Ladder

## Who This Is For

Use this ladder when you already understand approximation at a high level and want the proof-side intuition behind relaxations, bounds, and primal-vs-dual thinking.

## Warm-Up

- lower-bound intuition
- fractional benchmark vs integral solution

## Core

- relaxation as a design lens
- primal-dual or dual-fitting style reasoning

## Repo Bridge Note

- [Police Chase](../../graphs/flow/policechase.md): compute max flow, then read off a minimum cut certificate from the residual graph.
- [MINCOST](../../graphs/flow/mincost.md): potentials and reduced-cost thinking from the contest side.

## Stretch

- explain one greedy/approximation proof through a dual or lower-bound lens
- connect one editorial argument to an optimization viewpoint

## Compare Points

- exact dual certificate -> [Police Chase](../../graphs/flow/policechase.md)
- reduced-cost / potential view -> [MINCOST](../../graphs/flow/mincost.md)
- contest-time numeric LP solver -> [Cheese, If You Please](../simplex/cheeseifyouplease.md)
- optional exchange-style compare point -> [C11XU](../../data-structures/dsu/c11xu.md)
- theory pages -> [Optimization And Duality](../../../../topics/advanced/optimization-and-duality/README.md), [Simplex](../../../../topics/advanced/simplex/README.md), [Maximum Flow](../../../../topics/graphs/flow/README.md), [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)

This ladder is sparse on direct note count, so the right move is to compare one exact certificate, one reduced-cost style argument, and one exchange-style proof before leaving the lane.

## Exit Criteria

You are ready to move on when you can:

- say what benchmark or lower bound a proof is using
- distinguish “algorithm” from “analysis lens”
- explain why duality matters even without contest-time LP code
- explain when a generic LP solver is justified and when a specialized combinatorial algorithm is the better exact route
- connect this page naturally to approximation and hardness

## External Reading / Courses

- [Princeton COS 521](https://www.cs.princeton.edu/~hy2/teaching/fall25-cos521/index.html)
- [Cornell CS 6820](https://www.cs.cornell.edu/courses/cs6820/2025fa/syllabus.html)

## Tutorial Link

- [Optimization And Duality](../../../../topics/advanced/optimization-and-duality/README.md)
