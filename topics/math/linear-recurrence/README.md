# Linear Recurrence / Matrix Exponentiation

This lane is for the moment when an ordinary DP recurrence is correct but the index `n` is too large to iterate one step at a time.

The key shift is:

- stop thinking of "next value" as one scalar update
- package the last `k` values into one state vector
- express one step as multiplication by one fixed matrix
- jump many steps by exponentiating that matrix

For contest work, this is the first exact route when the problem really says:

```text
the transition is linear, the state dimension is small, and n can be huge
```

## At A Glance

- **Use when:** one state is a fixed linear combination of a constant number of previous states, or one small linear state transition repeats many times
- **Core worldview:** one step is one matrix `T`; many steps are `T^p`
- **Main tools:** state vector, companion matrix, binary exponentiation on matrices
- **Typical complexity:** `O(k^3 log n)` for a `k x k` matrix
- **Main trap:** building the right recurrence but ordering the state vector incorrectly

Strong contest signals:

- `n` is up to `10^18` or similarly too large for linear DP
- the recurrence has constant width, like `f(n) = c1 f(n-1) + ... + ck f(n-k)`
- the statement is really "apply the same linear transition many times"
- a graph path count with exactly `k` edges can be written as repeated multiplication by one adjacency matrix

Strong anti-cues:

- the transition is not linear after algebraic cleanup
- the state dimension is large enough that `k^3 log n` is already too expensive
- the recurrence is special enough for a lighter route like Fibonacci fast doubling
- the task is ordinary small-`n` DP and you are about to overbuild

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)

Helpful neighboring topics:

- [DP Foundations](../../dp/foundations/README.md) if the hard part is still identifying the right repeated state
- [Number Theory Basics](../number-theory-basics/README.md) if modulo arithmetic and overflow discipline still feel shaky
- [Convex Hull Trick / Li Chao Tree](../../dp/cht-li-chao/README.md) as a compare point for "DP transition becomes another algebraic object"

## Problem Model And Notation

Suppose the state we want is `f(n)`, and there exists a fixed recurrence:

$$
f(n) = c_1 f(n-1) + c_2 f(n-2) + \dots + c_k f(n-k)
$$

for all large enough `n`.

Define the state vector:

$$
S(n) =
\begin{pmatrix}
f(n) \\
f(n-1) \\
\vdots \\
f(n-k+1)
\end{pmatrix}
$$

Then one step of the recurrence can be written as:

$$
S(n+1) = T \cdot S(n)
$$

for one fixed `k x k` matrix `T`.

That immediately gives:

$$
S(n+p) = T^p \cdot S(n)
$$

So once the state is linear and fixed-width, the problem becomes:

- build `T`
- exponentiate `T`
- multiply by one base state vector

## From Brute Force To The Right Idea

### Brute Force

If we compute the recurrence one index at a time, the running time is:

$$
O(nk)
$$

That is fine for:

- `n <= 2 * 10^6`

but hopeless for:

- `n <= 10^18`

### Structural Observation

The recurrence does not change from one step to the next.

That is the real opening.

If one step always transforms:

```text
current state vector -> next state vector
```

in the same linear way, then we are repeatedly applying the same operator.

Repeated application of one linear operator is exactly what matrix powers model.

### Why Binary Exponentiation Helps

Ordinary repeated squaring says:

$$
a^n
$$

can be computed in `O(log n)` multiplications.

The same idea works for matrices:

$$
T^n
$$

can be computed in `O(log n)` matrix multiplications.

So the giant index disappears from the loop count.

Only the state dimension remains.

## Core Invariant And Why It Works

## 1. State Vector Meaning

Choose a state ordering and never drift from it.

For the usual recurrence lane:

$$
S(i) =
\begin{pmatrix}
f(i) \\
f(i-1) \\
\dots \\
f(i-k+1)
\end{pmatrix}
$$

means:

```text
the first coordinate is the newest term
the last coordinate is the oldest term still needed next step
```

Everything else depends on preserving that meaning.

## 2. Companion Matrix Meaning

For a `k`-order recurrence, the first row of `T` computes the new term.

The remaining rows usually just shift the window:

$$
\begin{pmatrix}
f(i) \\
f(i-1) \\
\dots
\end{pmatrix}
\mapsto
\begin{pmatrix}
f(i+1) \\
f(i) \\
\dots
\end{pmatrix}
$$

So the standard companion matrix has:

- recurrence coefficients in the first row
- `1`s on the subdiagonal

That is not a trick. It is just the algebraic encoding of:

```text
compute one new value, then shift the window down by one slot
```

## 3. Why Powers Encode Many Steps

If:

$$
S(i+1) = T S(i)
$$

then:

$$
S(i+2) = T S(i+1) = T^2 S(i)
$$

and by induction:

$$
S(i+p) = T^p S(i)
$$

So exponentiating `T` is exactly the same as applying the recurrence `p` times.

## 4. Why Complexity Is Small Enough

For a dense `k x k` matrix:

- one multiplication costs `O(k^3)`
- exponentiation needs `O(log n)` multiplications

Therefore the standard route is:

$$
O(k^3 \log n)
$$

This is excellent when:

- `k` is small, like `2`, `6`, `20`, or even `50`

and usually poor when:

- `k` is large enough that cubic work dominates

## Variant Chooser

### Use Ordinary DP When

- `n` is small enough to iterate directly
- the recurrence width is small but there is no need to jump huge distances

This is the clean route for the warm-up problem:

- [Dice Combinations](https://cses.fi/problemset/task/1633)

### Use Matrix Exponentiation When

- the recurrence width is fixed and small
- the same linear transition repeats many times
- `n` is huge, often `10^18`

This is the first exact route for:

- [Throwing Dice](../../../practice/ladders/math/linear-recurrence/throwingdice.md)

### Use A Specialized Formula When

- the recurrence has extra structure

Example:

- Fibonacci numbers can be done by a `2 x 2` matrix
- but fast doubling is lighter and faster if the task is only Fibonacci

So matrix exponentiation is the general route, not always the lightest route.

### Reopen The Topic Before Reusing The Starter When

- the transition is matrix-shaped but the matrix dimension is large
- the matrix is sparse enough that a custom multiply should replace the dense `O(k^3)` multiply
- you really need a stronger recurrence tool like [Berlekamp-Massey / Kitamasa](../berlekamp-massey-kitamasa/README.md)

That is now a shipped follow-up lane, not part of this first matrix route.

## Worked Examples

## 1. Fibonacci

The recurrence is:

$$
F_n = F_{n-1} + F_{n-2}
$$

Use state:

$$
S(n) =
\begin{pmatrix}
F_n \\
F_{n-1}
\end{pmatrix}
$$

Then:

$$
\begin{pmatrix}
F_{n+1} \\
F_n
\end{pmatrix}
=
\begin{pmatrix}
1 & 1 \\
1 & 0
\end{pmatrix}
\begin{pmatrix}
F_n \\
F_{n-1}
\end{pmatrix}
$$

So:

$$
S(n) =
\begin{pmatrix}
1 & 1 \\
1 & 0
\end{pmatrix}^{n-1}
S(1)
$$

This is the smallest clean example of the whole lane.

## 2. Throwing Dice

Let `f(n)` be the number of ordered dice sequences summing to `n`.

Then:

$$
f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)
$$

with:

$$
f(0) = 1
$$

and `f(n) = 0` for negative `n`.

Take:

$$
S(i) =
\begin{pmatrix}
f(i) \\
f(i-1) \\
f(i-2) \\
f(i-3) \\
f(i-4) \\
f(i-5)
\end{pmatrix}
$$

Then:

$$
S(i+1) = T S(i)
$$

where the first row is all `1`s, and the remaining rows shift the window.

So [Throwing Dice](../../../practice/ladders/math/linear-recurrence/throwingdice.md) is not "just a math problem."

It is the first canonical `order-6 recurrence -> companion matrix` route.

## 3. Matrix Transition On A Graph

If `A` is an adjacency matrix, then:

$$
(A^k)_{u,v}
$$

counts walks of length `k` from `u` to `v`.

This is the same worldview:

- one step is one fixed linear transition
- many steps are one matrix power

That is a useful compare point once the recurrence version already feels natural.

## Pseudocode

```text
build transition matrix T
build base state vector S(base_index)

if n <= base_index:
    return direct base answer

P = mat_pow(T, n - base_index)
answer_state = P * S(base_index)
return answer_state[0]
```

## Implementation Notes

- Keep the state-vector order explicit in comments while building the matrix.
- If the problem is modulo `MOD`, reduce after every matrix cell update.
- Use `__int128` inside multiplication if `MOD` or coefficients can make `a * b` overflow `long long`.
- Dense matrix multiplication is fine for small `k`; do not overengineer sparse variants too early.
- For contest code, make the starter generic enough for one matrix and one vector, but not so generic that the invariant disappears.
- The base vector should be chosen at the first index where every coordinate you need is already known.

## Repo Anchors

- Topic-adjacent note: [Throwing Dice](../../../practice/ladders/math/linear-recurrence/throwingdice.md)
- Starter template: [`matrix-exponentiation.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp)
- Retrieval page: [Linear Recurrence hot sheet](../../../notebook/linear-recurrence-hot-sheet.md)
- Compare point:
  - [Modular Arithmetic](../modular-arithmetic/README.md)
  - [CSES - Graph Paths I](https://cses.fi/problemset/task/1723) for the same repeated-linear-transition idea on an adjacency matrix

## References

- Reference: [cp-algorithms - Fibonacci Numbers](https://cp-algorithms.com/algebra/fibonacci-numbers.html)
- Reference: [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf)
- Practice: [CSES - Fibonacci Numbers](https://cses.fi/problemset/task/1722)
- Practice: [CSES - Throwing Dice](https://cses.fi/problemset/task/1096)
- Practice: [CSES - Graph Paths I](https://cses.fi/problemset/task/1723)
