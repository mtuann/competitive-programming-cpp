# Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions Ladder

## Who This Is For

Use this ladder when arithmetic-function basics feel comfortable, but summatory number-theory problems still look like "too many divisors across too many numbers."

## Warm-Up

- divisor function versus summatory divisor function
- arithmetic progression sums
- why `floor(n / d)` stays constant on long divisor ranges

## Core

- open one direct Dirichlet convolution first
- exchange the summation order cleanly
- group equal `floor(n / d)` values into `O(sqrt(n))` blocks
- flagship rep: [Sum of Divisors](sumofdivisors.md)

## Stretch

- explain why this first lane is narrower than `sum phi`, `sum mu`, `Du Jiao`, or `Min_25`
- compare direct convolution expansion with divisor-side Mobius cancellation
- say what kind of block helper would still keep the same quotient-grouping worldview

## Retrieval Layer

- exact starter -> [dirichlet-convolution-sigma-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/dirichlet-convolution-sigma-sum.cpp)
- quick reminder sheet -> [Dirichlet prefix sums hot sheet](../../../../notebook/dirichlet-prefix-sums-hot-sheet.md)
- compare point -> [Mobius And Multiplicative Counting](../../../../topics/math/mobius-multiplicative/README.md)

## Repo Anchors

- [Sum of Divisors](sumofdivisors.md)

## Exit Criteria

You are ready to move on when you can:

- derive the `sigma` summatory formula from `sigma = 1 * id`
- compute quotient blocks without off-by-one mistakes
- explain why the number of distinct quotients is only `O(sqrt(n))`
- tell when this direct route is enough and when the task has crossed into a later prefix-sum multiplicative-function lane

## External Practice

- [CSES - Sum of Divisors](https://cses.fi/problemset/task/1082)
- [USACO Guide - Prefix Sums of Number-Theoretic Functions (Part 1)](https://usaco.guide/adv/prefix-sums-nt-1)

## Tutorial Link

- [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../../../../topics/math/dirichlet-prefix-sums/README.md)
