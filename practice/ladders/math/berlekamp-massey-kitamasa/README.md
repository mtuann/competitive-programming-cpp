# Berlekamp-Massey / Kitamasa Ladder

## Who This Is For

Use this ladder when you already trust linear recurrences, but the matrix route feels too cubic or the recurrence itself must be recovered from a prefix first.

## Warm-Up

- fixed-order recurrence notation
- modular arithmetic over one trusted prime field
- knowing exactly what the first `d` terms mean

## Core

- Kitamasa / characteristic-polynomial reduction for the `k`-th term
- Berlekamp-Massey discrepancy updates for shortest-recurrence recovery

## Stretch

- move from "recurrence given" to "recurrence hidden in a prefix"
- compare this lane with matrix exponentiation and FPS / generating-function viewpoints

## Retrieval Layer

- exact starter -> [berlekamp-massey-kitamasa.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/berlekamp-massey-kitamasa.cpp)
- quick reminder sheet -> [Berlekamp-Massey / Kitamasa hot sheet](../../../../notebook/berlekamp-massey-kitamasa-hot-sheet.md)
- compare point -> [Linear Recurrence hot sheet](../../../../notebook/linear-recurrence-hot-sheet.md)

## Repo Anchors

- [K-th Term of Linearly Recurrent Sequence](kthtermoflinearlyrecurrentsequence.md)

## Exit Criteria

You are ready to move on when you can:

- translate the recurrence into the repo coefficient convention without guessing
- explain why reducing powers of `x` modulo the recurrence replaces matrix powers
- recover the shortest recurrence from a prefix with Berlekamp-Massey
- tell when the ordinary matrix route is still the better first tool

## External Practice

- [Library Checker - K-th Term of Linearly Recurrent Sequence](https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence)
- [Library Checker - Find Linear Recurrence](https://judge.yosupo.jp/problem/find_linear_recurrence)

## Tutorial Link

- [Berlekamp-Massey / Kitamasa](../../../../topics/math/berlekamp-massey-kitamasa/README.md)
