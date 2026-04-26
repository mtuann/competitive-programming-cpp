# Randomized / Global Min-Cut Ladder

This lane is for the first time `max-flow / min-cut` is clearly nearby, but the statement gives **no source and sink at all**.

## Who This Is For

Use this lane if:

- [Maximum Flow](../../../../topics/graphs/flow/README.md) already feels comfortable for one explicit `s-t` cut
- you can extract one cut certificate from residual reachability
- the next graph problem wants **one global cut** in an undirected weighted graph

This lane is intentionally narrow:

- one exact deterministic starter
- one flagship benchmark that is almost pure global min-cut
- one compare route back to plain flow
- one compare route forward to [Gomory-Hu Tree](../../../../topics/graphs/gomory-hu/README.md)

## Warm-Up

- [FFLOW](../flow/fflow.md)
- [Police Chase](../flow/policechase.md)

Target skill:

- explain why "no source and sink" already changes the family boundary

## Core

- one undirected weighted graph
- no designated `s-t`
- one global cut value
- exact starter route: [stoer-wagner-global-mincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/stoer-wagner-global-mincut.cpp)
- flagship solved rep: [Minimum Cut](globalmincut.md)

Target skill:

- trust the Stoer-Wagner contraction route instead of brute-force pair enumeration

## Stretch

- compare deterministic Stoer-Wagner against randomized Karger / Karger-Stein as two views of the same family
- reopen [Gomory-Hu Tree](../../../../topics/graphs/gomory-hu/README.md) and explain why "one global cut" is still narrower than "many pairwise cuts"
- try one warm-up `s-t` cut task and one global cut task back-to-back, then explain the boundary in one sentence

Target skill:

- know when the right endpoint is:
  - plain flow
  - one global cut
  - or one cut tree

## Retrieval Layer

- exact quick sheet -> [Global Min-Cut hot sheet](../../../../notebook/global-min-cut-hot-sheet.md)
- prerequisite cut engine -> [Flow hot sheet](../../../../notebook/flow-hot-sheet.md)
- exact starter -> [stoer-wagner-global-mincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/stoer-wagner-global-mincut.cpp)
- compare route -> [Gomory-Hu hot sheet](../../../../notebook/gomory-hu-hot-sheet.md)
- broader chooser -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Randomized / Global Min-Cut](../../../../topics/graphs/global-min-cut/README.md)
- flagship note -> [Minimum Cut](globalmincut.md)
- one-cut compare point -> [Maximum Flow](../../../../topics/graphs/flow/README.md)
- many-cut compare point -> [Gomory-Hu Tree](../../../../topics/graphs/gomory-hu/README.md)
- broader routing -> [Graphs ladder](../README.md)

## Exit Criteria

You are ready to move on when:

- you can explain why the graph must be undirected
- you understand why the answer is the best phase cut across contractions
- you can say exactly why this is not yet a Gomory-Hu task
- you know where the randomized contraction worldview fits, even if the repo starter is deterministic

## External Practice

- [POJ 2914 - Minimum Cut](http://poj.org/problem?id=2914)
- [UVa 10480 - Sabotage](https://onlinejudge.org/external/104/10480.pdf)

## Tutorial Link

- [Randomized / Global Min-Cut](../../../../topics/graphs/global-min-cut/README.md)
