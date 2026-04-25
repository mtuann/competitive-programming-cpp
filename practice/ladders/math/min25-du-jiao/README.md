# Min_25 / Du Jiao Ladder

## Who This Is For

Use this ladder when direct divisor-side prefix sums feel comfortable, but `sum phi` or `sum mu` over one huge `n` still feels like "the prefix sum itself is hidden behind another formula."

## Warm-Up

- quotient set `Q_n`
- grouped floor-division blocks
- why:
  - `phi * 1 = id`
  - `mu * 1 = e`
  turn into prefix-sum recurrences

## Core

- recover one implicit prefix sum on `Q_n`
- group equal quotient blocks
- solve `sum phi` first, keep `sum mu` as the immediate sibling
- flagship rep: [Sum of Totient Function](sumoftotientfunction.md)

## Stretch

- explain why the first route is Du Jiao-first, not full Min_25
- compare direct `sum sigma` prefix sums with implicit `sum phi` / `sum mu` recurrences
- say when prime-counting or other prime-side tasks should push you into the full Min_25 follow-up

## Retrieval Layer

- exact starter -> [du-jiao-prefix-phi-mu.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/du-jiao-prefix-phi-mu.cpp)
- quick reminder sheet -> [Min_25 / Du Jiao hot sheet](../../../../notebook/min25-du-jiao-hot-sheet.md)
- compare point -> [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../../../../topics/math/dirichlet-prefix-sums/README.md)

## Repo Anchors

- [Sum of Totient Function](sumoftotientfunction.md)

## Exit Criteria

You are ready to move on when you can:

- derive the recurrence for `sum phi`
- derive the sibling recurrence for `sum mu`
- explain why `Q_x subseteq Q_n` matters
- distinguish block lengths from quotient values in the grouped recurrence
- say when this route is still enough and when the full Min_25 follow-up becomes the right next step

## External Practice

- [Library Checker - Sum of Totient Function](https://judge.yosupo.jp/problem/sum_of_totient_function)
- [CSES - Totient sums](https://cses.fi/ioi17/task/947)
- [USACO Guide - Prefix Sums of Number-Theoretic Functions (Part 2)](https://usaco.guide/adv/prefix-sums-nt-2)

## Tutorial Link

- [Min_25 / Du Jiao](../../../../topics/math/min25-du-jiao/README.md)
