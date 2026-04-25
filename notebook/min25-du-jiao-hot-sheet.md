# Min_25 / Du Jiao Hot Sheet

Use this page when the statement has already collapsed into:

```text
I need sum phi or sum mu up to one huge n,
and direct sieving to n is no longer the right scale
```

The first exact route in this repo is the **Du Jiao worldview** on the quotient set `Q_n`.

## Do Not Use When

- the function still opens directly into one divisor-side floor-sum; that is still [Dirichlet prefix sums hot sheet](dirichlet-prefix-sums-hot-sheet.md)
- the task is array-side gcd counting over bounded values; that is [Mobius hot sheet](mobius-hot-sheet.md)
- the real target is already prime counting or another prime-side multiplicative-prefix engine; that is the later Min_25 boundary

## Choose By Signal

- one huge `sum_{k<=n} phi(k)` or `sum_{k<=n} mu(k)` -> build `Q_n`, then recover the prefix sum from a Dirichlet-identity recurrence -> [`du-jiao-prefix-phi-mu.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/du-jiao-prefix-phi-mu.cpp)
- direct `sum sigma` / divisor-side floor-sum -> compare [Dirichlet prefix sums hot sheet](dirichlet-prefix-sums-hot-sheet.md)
- array-side Mobius cancellation -> compare [Mobius hot sheet](mobius-hot-sheet.md)
- prime-counting / full Min_25 follow-up -> reopen the topic; this first starter is intentionally narrower than the full lane title

## Core Invariants

- quotient set:

$$
Q_n = \left\{ \left\lfloor \frac{n}{i} \right\rfloor : 1 \le i \le n \right\}
$$

- closure fact:

$$
x \in Q_n \Rightarrow Q_x \subseteq Q_n
$$

- Dirichlet relations:

$$
\varphi * 1 = id,
\qquad
\mu * 1 = e
$$

- grouped recurrence shape:

$$
F(x) = base(x) - \sum_{l=2}^{x} (r-l+1)\,F\!\left(\left\lfloor \frac{x}{l} \right\rfloor\right)
$$

with:

- `base(x) = x(x+1)/2` for `phi`
- `base(x) = 1` for `mu`

## Main Traps

- treating this as just "another floor-sum trick" without deriving the Dirichlet identity first
- forgetting that the coefficients are block lengths `(r-l+1)`, not quotient values
- overclaiming the first starter as a full Min_25 implementation
- losing modulo discipline when the true prefix sum is far larger than 64-bit

## Exact Starter In This Repo

- exact starter -> [`du-jiao-prefix-phi-mu.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/du-jiao-prefix-phi-mu.cpp)
- flagship in-lane rep -> [Sum of Totient Function](../practice/ladders/math/min25-du-jiao/sumoftotientfunction.md)
- compare points:
  - [Dirichlet prefix sums hot sheet](dirichlet-prefix-sums-hot-sheet.md)
  - [Mobius hot sheet](mobius-hot-sheet.md)

## Reopen Paths

- full lesson and boundary -> [Min_25 / Du Jiao](../topics/math/min25-du-jiao/README.md)
- direct divisor-side compare -> [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../topics/math/dirichlet-prefix-sums/README.md)
- broader chooser -> [Number theory cheatsheet](number-theory-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
