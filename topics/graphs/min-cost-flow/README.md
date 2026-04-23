# Min-Cost Flow

Min-cost flow is the right model when you must route flow and also optimize the total transportation cost.

## Prerequisites

- [Maximum Flow](../flow/README.md)
- [Shortest Paths](../shortest-paths/README.md)

## When To Suspect It

- exact amount `k` of flow must be sent
- each unit of flow pays a cost
- the task asks for the cheapest transportation plan

## Core Idea

Use successive shortest augmenting paths.

The standard robust implementation uses:

- residual graph
- reverse edges with negative cost
- potentials to keep Dijkstra valid on reduced costs

## Theory / Proof Sketch

Reduced costs preserve shortest augmenting structure while allowing Dijkstra after each augmentation.

Each augmentation sends flow along a cheapest currently valid residual path, and the potentials keep the reduced costs consistent.

## Complexity And Tradeoffs

Min-cost flow is heavier than plain max flow and should be used only when cost really matters.

## Canonical Pattern

Template in this repo:

- [min-cost-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)

## Worked Examples

Example 1: send exactly `k` units with minimum cost

Example 2: transportation or assignment style modeling

Example 3: [MINCOST](../../../practice/ladders/graphs/flow/mincost.md)

## Common Mistakes

- forgetting reverse costs
- using `int` for total cost
- reconstructing the original-road answer incorrectly

## Practice Ladder

- [Flow ladder](../../../practice/ladders/graphs/flow/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Min-Cost Flow](https://cp-algorithms.com/graph/min_cost_flow.html)
- Practice: [MINCOST note](../../../practice/ladders/graphs/flow/mincost.md)

## Related Topics

- [Maximum Flow](../flow/README.md)
- [Shortest Paths](../shortest-paths/README.md)
