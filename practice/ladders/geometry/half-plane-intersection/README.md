# Half-Plane Intersection Ladder

## Who This Is For

Use this lane when geometry tasks stop being about one predicate and start being about the whole feasible region cut out by many directed lines.

## Warm-Up

- orientation and sidedness
- line intersection
- polygon area
- the difference between point-set hulls and line-constraint intersections

## Core

- keep the left side of every directed boundary line
- sort half-planes by angle
- deduplicate equal directions by keeping the most restrictive one
- maintain the surviving feasible boundary with a deque
- flagship polygon-kernel rep: [Big Brother](bigbrother.md)

## Stretch

- explain why bounded polygon output is a narrower contract than general half-plane feasibility
- compare polygon kernels against convex hull anti-cues
- say when sweep line is the wrong abstraction even though "many lines" appear in the statement

## Retrieval Layer

- exact starter -> [`half-plane-intersection.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/half-plane-intersection.cpp)
- quick reminder sheet -> [Half-Plane Intersection hot sheet](../../../../notebook/half-plane-intersection-hot-sheet.md)
- compare point -> [Convex Hull](../../../../topics/geometry/convex-hull/README.md)

## Repo Anchors

- [Big Brother](bigbrother.md)

## Exit Criteria

You are ready to move on when you can:

- state the left-side convention without hesitation
- explain why equal-direction tie-breaking matters
- describe why deque pops only happen at the ends
- spot when a polygon-kernel problem is just half-plane intersection in disguise

## External Practice

- [Kattis - Big Brother](https://open.kattis.com/problems/bigbrother)
- [cp-algorithms - Half-plane intersection](https://cp-algorithms.com/geometry/halfplane-intersection.html)

## Tutorial Link

- [Half-Plane Intersection](../../../../topics/geometry/half-plane-intersection/README.md)
