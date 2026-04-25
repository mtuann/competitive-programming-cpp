# Throwing Dice

- Title: `Throwing Dice`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1096](https://cses.fi/problemset/task/1096)
- Secondary topics: `Matrix exponentiation`, `Linear recurrence`, `Companion matrix`
- Difficulty: `medium`
- Subtype: `Order-6 recurrence with huge n under modulo arithmetic`
- Status: `solved`
- Solution file: [throwingdice.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/linear-recurrence/throwingdice.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first `linear recurrence -> matrix exponentiation` lane.

The real signal is not just "dice" or "counting."

It is:

- the recurrence width is fixed at `6`
- `n` is huge, so direct DP is impossible
- every step applies the same linear transition

So the lesson is:

- package the last six values into one state vector
- write one companion matrix for one time step
- jump to `n` by exponentiating that matrix

## Recognition Cue

Reach for matrix exponentiation when:

- `n` is around `10^18`
- the current answer is a fixed linear combination of the previous few answers
- the recurrence width is small and constant
- the statement is really "repeat one linear transition many times"

The strongest smell here is:

- a `k`-step recurrence that would be trivial DP if only `n` were small

## Problem-Specific Transformation

Let `f(s)` be the number of ordered dice sequences that sum to `s`.

Then:

$$
f(s) = f(s-1) + f(s-2) + f(s-3) + f(s-4) + f(s-5) + f(s-6)
$$

with:

$$
f(0) = 1
$$

and `f(s) = 0` for negative `s`.

Build the state:

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

where:

- the first row is all `1`s, because the new answer is the sum of the previous six
- the remaining rows shift the window down by one slot

So the problem stops being:

- "count dice sequences somehow"

and becomes:

- compute `T^(n-5) * S(5)`

because:

$$
S(5) =
\begin{pmatrix}
16 \\
8 \\
4 \\
2 \\
1 \\
1
\end{pmatrix}
$$

## Core Idea

Use a `6 x 6` companion matrix with binary exponentiation.

1. hardcode the first few recurrence values
2. build the companion matrix
3. if `n <= 5`, answer directly
4. otherwise compute `T^(n-5)`
5. multiply by the base state vector `S(5)`
6. read the first coordinate

The invariant is:

```text
state[0] is always the newest recurrence value
```

If that ordering is wrong, the whole matrix can still look plausible while producing wrong answers.

## Complexity

The matrix dimension is constant:

- matrix multiplication: `O(6^3)`
- exponentiation: `O(6^3 log n)`

So the total complexity is:

$$
O(\log n)
$$

up to a small constant.

That is exactly why the huge `n` constraint becomes manageable.

## Pitfalls / Judge Notes

- The recurrence is over **ordered** dice sequences.
- Keep `f(0) = 1`; that is what makes the base values correct.
- Be explicit about the base index. This solution uses `S(5)` and raises the matrix to `n - 5`.
- Use modulo reduction after every matrix cell update.
- Evaluate products with `__int128` before `% MOD`.

## Reusable Pattern

- Topic page: [Linear Recurrence / Matrix Exponentiation](../../../../topics/math/linear-recurrence/README.md)
- Practice ladder: [Linear Recurrence / Matrix Exponentiation ladder](README.md)
- Starter template: [matrix-exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp)
- Notebook refresher: [Linear Recurrence hot sheet](../../../../notebook/linear-recurrence-hot-sheet.md)
- Compare points:
  - [CSES - Fibonacci Numbers](https://cses.fi/problemset/task/1722)
  - [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md)
- This note adds: the first exact `order-k recurrence -> companion matrix -> fast power` route in the repo.

## Solutions

- Code: [throwingdice.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/linear-recurrence/throwingdice.cpp)
