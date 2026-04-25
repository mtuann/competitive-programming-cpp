# Simplex Ladder

## Who This Is For

Use this ladder when the optimization story is already continuous and linear, and you now need one contest-time LP solver instead of one more proof-only lens.

## Warm-Up

- normalize every constraint into `Ax <= b`
- tell continuous LP apart from integer programming

## Core

- variable-per-product or variable-per-plan modeling
- trust the three status outcomes: `optimal`, `infeasible`, `unbounded`

## Repo Anchors

- [Cheese, If You Please](cheeseifyouplease.md)
- [Optimization And Duality](../optimization-and-duality/README.md)
- [MINCOST](../../graphs/flow/mincost.md)

## Stretch

- read one LP-heavy official statement and decide whether the numeric solver is actually the right route
- explain why one flow-style task should *not* be solved with generic simplex even if it can be written as an LP

## Compare Points

- direct continuous LP solver route -> [Cheese, If You Please](cheeseifyouplease.md)
- benchmark / certificate lens without a solver -> [Optimization And Duality](../optimization-and-duality/README.md)
- network-specialized optimization instead of generic LP -> [MINCOST](../../graphs/flow/mincost.md)
- exact-count relaxation on a DP family instead of a dense tableau -> [Red and Blue Lamps](../../dp/lagrangian-relaxation/redandbluelamps.md)

This ladder is intentionally sparse. The point is not to collect many simplex tasks. The point is to know when one LP solver is the cleanest honest route.

## Exit Criteria

You are ready to move on when you can:

- translate a blend / diet / resource-allocation statement into `maximize c^T x, Ax <= b, x >= 0`
- explain the meanings of `optimal`, `infeasible`, and `unbounded`
- reject simplex quickly when the task is really flow, DP, or integer programming

## External Practice

- [Kattis - Cheese, If You Please](https://open.kattis.com/problems/cheeseifyouplease)
- [ICPC World Finals 2016 Problem I: Road Times](https://icpc.global/worldfinals/problems/2016-ICPC-World-Finals/icpc2016.pdf)

## Tutorial Link

- [Simplex](../../../../topics/advanced/simplex/README.md)

