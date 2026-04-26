# Stable Marriage Ladder

This lane is for the first time two-sided pairing stops being about size or cost and becomes about **blocking pairs under strict preferences**.

## Who This Is For

Use this lane if:

- [Matching](../../../../topics/graphs/matching/README.md) already feels comfortable
- you can explain why a bipartite graph captures one-to-one pairing
- you now need a stable outcome under full preference lists on both sides

This lane is intentionally narrow:

- one exact starter
- one flagship note built around the canonical Gale-Shapley benchmark
- one compare route against [Matching](../../../../topics/graphs/matching/README.md)
- one compare route against [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)

## Warm-Up

- explain what a blocking pair is
- explain why "stable" is not the same as "minimum total rank sum"
- hand-simulate one `3 x 3` Gale-Shapley run

Target skill:

- recognize when preference stability is the entire problem, not only a side condition

## Core

- two equal-sized sides
- complete strict preference lists
- deferred acceptance / Gale-Shapley
- exact flagship rep: [Stable Marriage](stablemarriage.md)

Target skill:

- trust the `O(n^2)` proposer-driven route and recover one valid stable matching

## Stretch

- rerun the same instance with the other side proposing and compare the outcomes
- explain why [Task Assignment](../hungarian-assignment/taskassignment.md) is a different problem even though it is still one-to-one pairing
- keep hospital-residents, ties, and stable roommates as out-of-lane follow-ups instead of mixing them into the first snippet

Target skill:

- separate stability from both cardinality matching and weighted assignment

## Retrieval Layer

- exact quick sheet -> [Stable Marriage hot sheet](../../../../notebook/stable-marriage-hot-sheet.md)
- exact starter -> [gale-shapley-stable-marriage.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gale-shapley-stable-marriage.cpp)
- compare route -> [Matching](../../../../topics/graphs/matching/README.md)
- compare route -> [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
- broader chooser -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Stable Marriage](../../../../topics/graphs/stable-marriage/README.md)
- flagship note -> [Stable Marriage](stablemarriage.md)
- compare point -> [Matching](../../../../topics/graphs/matching/README.md)
- compare point -> [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
- broader routing -> [Graphs ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Matching](../../../../topics/graphs/matching/README.md) just enough to keep the two-sided pairing model straight
2. learn the stability route in [Stable Marriage](../../../../topics/graphs/stable-marriage/README.md)
3. solve [Stable Marriage](stablemarriage.md)
4. compare the same mental model against [Task Assignment](../hungarian-assignment/taskassignment.md) so the "stability vs cost" boundary stays sharp

## Exit Criteria

You are ready to move on when:

- you can define a blocking pair without hesitation
- you know why Gale-Shapley is about stability, not total-score optimization
- you can explain why the proposing side gets its best stable outcome in this exact route

## External Practice

- [Library Checker - Stable Marriage Problem](https://judge.yosupo.jp/problem/stable_marriage_problem)
- [AMS - The Stable Marriage Problem and School Choice](https://www.ams.org/publicoutreach/feature-column/fc-2015-03)

## Tutorial Link

- [Stable Marriage](../../../../topics/graphs/stable-marriage/README.md)
