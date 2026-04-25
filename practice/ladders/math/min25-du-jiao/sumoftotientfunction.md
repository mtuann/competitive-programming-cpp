# Sum of Totient Function

- Title: `Sum of Totient Function`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/sum_of_totient_function](https://judge.yosupo.jp/problem/sum_of_totient_function)
- Secondary topics: `Du Jiao sieve`, `Quotient set`, `Dirichlet inverse recurrence`
- Difficulty: `hard`
- Subtype: `Prefix phi via phi * 1 = id on Q_n`
- Status: `solved`
- Solution file: [sumoftotientfunction.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/min25-du-jiao/sumoftotientfunction.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `Min_25 / Du Jiao` lane.

The statement is just:

```text
compute sum_{k<=n} phi(k)
```

but the reusable lesson is:

- direct sieving to `n` is no longer the right scale
- the answer is recovered from a Dirichlet relation
- the real state space is the quotient set `Q_n`

It is the first point in this repo where the prefix sum itself becomes the unknown object solved by recurrence.

## Recognition Cue

Reach for this lane when:

- the target is one huge prefix sum of `phi` or `mu`
- direct `O(n)` sieving is too large
- the repeated subproblems are values of `floor(n / i)`
- the statement is about one large arithmetic-function prefix query, not an array of bounded values

The strongest smell here is:

```text
I know a Dirichlet identity for the function,
but I need the prefix sum itself, not the point values.
```

## Problem-Specific Transformation

Start from:

$$
\varphi * 1 = id
$$

Summing over all `m <= n` gives:

$$
\sum_{k=1}^{n} \Phi\!\left(\left\lfloor \frac{n}{k} \right\rfloor\right)
=
\frac{n(n+1)}{2}
$$

where:

$$
\Phi(x) = \sum_{i \le x} \varphi(i)
$$

Now isolate the `k = 1` term:

$$
\Phi(n)
=
\frac{n(n+1)}{2}
-
\sum_{k=2}^{n} \Phi\!\left(\left\lfloor \frac{n}{k} \right\rfloor\right)
$$

Then group equal quotients:

$$
q = \left\lfloor \frac{n}{l} \right\rfloor,
\qquad
r = \left\lfloor \frac{n}{q} \right\rfloor
$$

so the whole block contributes:

$$
(r-l+1)\,\Phi(q)
$$

## Core Idea

Solve the recurrence on the quotient set:

$$
Q_n = \left\{ \left\lfloor \frac{n}{i} \right\rfloor \right\}
$$

not on every integer from `1..n`.

That works because:

$$
x \in Q_n \Rightarrow Q_x \subseteq Q_n
$$

So once the values of `Phi(q)` for smaller quotient states are known, the current `Phi(x)` is computed by grouped subtraction from:

$$
\frac{x(x+1)}{2}
$$

The implementation in this repo builds `Q_n`, processes it in ascending order, and stores:

- `prefix_phi(x)`
- `prefix_mu(x)`

for every `x` in the set.

## Complexity

- state count: `|Q_n| = O(sqrt(n))`
- each state uses grouped floor-division blocks
- overall: sublinear in `n`, good enough for the intended large single-query route

This repo starter is the clean introductory implementation, not the last word on asymptotics.

## Pitfalls / Judge Notes

- The problem asks for the answer modulo `998244353`.
- Do not try to sieve `phi` all the way to `n`.
- The grouped recurrence uses block lengths `(r-l+1)`, not the quotient `q` itself as the coefficient.
- If you treat this as the same lane as `sum sigma`, you will miss that `Phi` is now the unknown.
- Full Min_25 machinery is outside the first starter even though the lane title includes it.

## Reusable Pattern

- Topic page: [Min_25 / Du Jiao](../../../../topics/math/min25-du-jiao/README.md)
- Practice ladder: [Min_25 / Du Jiao ladder](README.md)
- Starter template: [du-jiao-prefix-phi-mu.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/du-jiao-prefix-phi-mu.cpp)
- Notebook refresher: [Min_25 / Du Jiao hot sheet](../../../../notebook/min25-du-jiao-hot-sheet.md)
- Compare points:
  - [Sum of Divisors](../dirichlet-prefix-sums/sumofdivisors.md)
  - [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../../../../topics/math/dirichlet-prefix-sums/README.md)
- This note adds: the first in-repo route where one arithmetic-function prefix sum is recovered implicitly on `Q_n` instead of opened directly by one divisor-side formula.

## Solutions

- Code: [sumoftotientfunction.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/min25-du-jiao/sumoftotientfunction.cpp)
