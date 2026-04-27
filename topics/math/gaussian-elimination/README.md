# Gaussian Elimination / Linear Algebra

This lane starts when modular arithmetic stops being about one scalar identity and becomes about a whole system:

$$
Ax = b
$$

The reusable contest move is usually not "do linear algebra in general."

It is:

- model the statement as one linear system
- pick pivots one column at a time
- eliminate everything else in that column
- recover one solution, or prove that no solution exists

Gaussian elimination is a **field** technique. The same worldview appears:

- over the reals
- over a prime modulus
- over `GF(2)` in xor-basis problems

The repo keeps the exact first route deliberately narrow:

```text
solve one linear system modulo one prime with Gaussian elimination
```

That route is contest-clean, exact, and avoids the extra noise of floating-point `eps` handling.

## At A Glance

- **Use when:** the statement gives many linear equations in many unknowns and one field structure is explicit or easy to model
- **Core worldview:** row operations preserve the solution set, so we can reshape the augmented matrix until each pivot column is isolated
- **Main tools:** augmented matrix, pivot row selection, row normalization, row elimination, free-variable detection
- **Typical complexity:** `O(min(n, m) * n * m)`
- **Main trap:** forgetting that "every nonzero pivot is invertible" is a field property, so the clean first route needs a prime modulus or another field

Strong contest signals:

- "find any values `x1 ... xm` satisfying all equations"
- the equations are modulo one prime such as `1e9+7`
- the statement allows any valid assignment, not one special lexicographic optimum
- the real object is an augmented matrix, not a graph or DP state
- `GF(2)` reasoning feels close, but the coefficients are not just `0/1`

Strong anti-cues:

- the task is really xor-subset span over bits -> [XOR Basis / Linear Basis](../xor-basis/README.md)
- the matrix only describes one repeated transition -> [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md)
- the modulus is composite and you were about to invert every nonzero pivot with Fermat
- numerical conditioning under real numbers is the real challenge, not exact contest algebra

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

Helpful neighboring routes:

- [XOR Basis / Linear Basis](../xor-basis/README.md): Gaussian elimination specialized to `GF(2)` bitmasks
- [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md): repeated linear transitions, not system solving
- [Modular Arithmetic hot sheet](../../../notebook/modular-arithmetic-hot-sheet.md)

## Problem Model And Notation

We want to solve:

$$
Ax = b
$$

where:

- `A` is an `n x m` coefficient matrix
- `x` is the unknown vector of size `m`
- `b` is the right-hand side vector of size `n`

Contest code usually stores this as one augmented matrix:

$$
[A \mid b]
$$

The central question is not just "what is the answer?"

It is:

- does a solution exist?
- if yes, is it unique or are there free variables?
- can we output one valid assignment quickly and safely?

In this repo's first route, the arithmetic lives in:

$$
\mathbb{F}_p
$$

for one prime modulus `p`. That means every nonzero pivot is invertible, so row normalization is always legal.

## From Brute Force To The Right Idea

### Why Brute Force Dies Immediately

If there are `m` variables and each one can take many values modulo `p`, brute force is hopeless.

Even for tiny-looking systems, the state space is:

$$
p^m
$$

which is not a contest route.

### The Structural Observation

Every equation is linear.

So instead of searching assignments directly, we transform the equations themselves.

Allowed row moves:

- swap two rows
- multiply one row by a nonzero scalar
- add a multiple of one row to another row

Each move preserves the solution set.

That means we can keep changing the matrix shape without changing which `x` vectors are valid.

### The Pivoting View

Process the matrix column by column.

For one column:

1. find a row with a nonzero coefficient there
2. swap it into the current pivot row
3. normalize that row so the pivot becomes `1`
4. eliminate the same column from every other row

Repeat until no more pivot columns can be created.

Then the matrix tells us immediately:

- which variables are fixed by pivots
- which variables are free
- whether some row says `0 = nonzero`, which means no solution

## Core Invariants And Why They Work

## 1. Row Operations Preserve The Solution Set

If one vector `x` satisfies the old system, it also satisfies every row-equivalent system, because each new row is just a linear combination of old ones.

That is why elimination is not a heuristic.

It is an exact transformation.

## 2. One Pivot Means One Dependent Variable

When column `c` gets a pivot row, that column is now controlled by one distinguished equation.

After elimination:

- the pivot row has `1` in column `c`
- every other row has `0` in column `c`

So that variable is no longer ambiguous relative to previously processed pivot columns.

## 3. Free Variables Are Real Structure, Not Failure

If a column never gets a pivot, then that variable is free.

For contest tasks that ask for **any** valid solution, the usual first route is:

- set every free variable to `0`
- recover the pivot variables from the row-reduced matrix

That gives one canonical solution quickly.

## 4. Inconsistency Has One Simple Signature

After elimination, if some row becomes:

$$
0x_1 + 0x_2 + \dots + 0x_m = c
$$

with `c != 0`, then the system is impossible.

In matrix terms:

```text
all-zero left side + nonzero RHS -> no solution
```

## Why The Repo Starts With Prime-Mod Elimination

Gaussian elimination itself is broader than this.

But the first exact contest route is best taught over one prime modulus because:

- every nonzero pivot has an inverse
- the arithmetic is exact, not `eps`-driven
- many contest statements already live modulo a prime
- the compare point to `GF(2)` xor-basis becomes very clean

This first route intentionally does **not** try to teach all of:

- floating-point stability and partial pivoting over reals
- composite-mod systems where not every nonzero pivot is invertible
- determinant / inverse / rank as separate full lanes
- sparse matrix engineering

## Elimination Playground

<div class="visual-card" data-gaussian-visualizer>
  <p class="visual-caption">
    Replay the same modulo-`7` micro example used on this page. The goal is to make `pivot -> normalize -> eliminate`
    feel mechanical before you look back at the full template.
  </p>
  <div class="visual-controls">
    <button type="button" data-role="prev">Previous stage</button>
    <button type="button" data-role="next">Next stage</button>
    <button type="button" data-role="reset">Reset</button>
  </div>
  <div class="visual-grid">
    <div class="visual-panel">
      <div class="visual-surface" data-role="canvas"></div>
    </div>
    <div class="visual-panel">
      <h4>What to watch</h4>
      <div class="visual-stats">
        <div class="visual-stat">
          <strong>Invariant</strong>
          <div data-role="invariant"></div>
        </div>
        <div class="visual-stat">
          <strong>Current stage</strong>
          <code data-role="stage"></code>
        </div>
        <div class="visual-stat">
          <strong>Row operation</strong>
          <code data-role="operation"></code>
        </div>
        <div class="visual-stat">
          <strong>Pivot map</strong>
          <code data-role="where"></code>
        </div>
        <div class="visual-stat">
          <strong>Matrix meaning</strong>
          <div data-role="status"></div>
        </div>
        <div class="visual-stat">
          <strong>Local formulas</strong>
          <ul data-role="formulas"></ul>
        </div>
      </div>
      <p class="visual-note" data-role="note"></p>
    </div>
  </div>
</div>

### Visual Reading Guide

What to notice:

- one pivot column is processed at a time; once a pivot is chosen, the goal is to make that column `1` at the pivot row and `0` everywhere else
- the augmented `rhs` column changes together with the coefficient columns, because row operations preserve the whole solution set, not just the left side

Why it matters:

- this is the shortest route from the abstract phrase "row operations preserve solutions" to the exact contest loop structure you implement
- it also makes the prime-mod first route feel justified: normalization is safe exactly because every nonzero pivot is invertible

Code bridge:

- each stage is one template move: choose pivot row, optionally swap, normalize by inverse, eliminate the pivot column from other rows
- the `where[col]` mapping in code is just the bookkeeping version of the highlighted pivot map in the widget

Boundary:

- this example is intentionally tiny and consistent, so it does not show row swaps, free variables, or inconsistency rows
- those cases use the same mechanics, but after elimination you must additionally detect missing pivots and rows of the form `0 = nonzero`

## Worked Micro Example

Solve modulo `7`:

$$
\begin{aligned}
x + y &= 3 \\
2x + y &= 4
\end{aligned}
$$

Augmented matrix:

$$
\left[
\begin{array}{cc|c}
1 & 1 & 3 \\
2 & 1 & 4
\end{array}
\right]
$$

Use the first row as the pivot for column `0`.

Eliminate column `0` from row `1`:

$$
R_2 \leftarrow R_2 - 2R_1
$$

giving:

$$
\left[
\begin{array}{cc|c}
1 & 1 & 3 \\
0 & -1 & -2
\end{array}
\right]
\equiv
\left[
\begin{array}{cc|c}
1 & 1 & 3 \\
0 & 6 & 5
\end{array}
\right]
\pmod 7
$$

Normalize the second row by multiplying with `6^{-1} ≡ 6 (mod 7)`:

$$
\left[
\begin{array}{cc|c}
1 & 1 & 3 \\
0 & 1 & 2
\end{array}
\right]
$$

Eliminate column `1` from row `0`:

$$
R_1 \leftarrow R_1 - R_2
$$

So:

$$
\left[
\begin{array}{cc|c}
1 & 0 & 1 \\
0 & 1 & 2
\end{array}
\right]
$$

and the solution is:

$$
x = 1,\quad y = 2
$$

## Recognition Cues

Reach for Gaussian elimination when:

- the variables interact only linearly
- the statement asks for any satisfying assignment
- a matrix model appears directly or after a simple reformulation
- free variables are allowed by the problem contract
- "rank / consistency / affine solution space" is the real substructure

The strongest smell in this repo's first lane is:

- "solve one linear system modulo one prime"

## Implementation Notes

- Use an augmented matrix with `m + 1` columns.
- Track `where[col] = pivot_row` so you know which variables are fixed by pivots.
- Over a prime modulus, normalize each pivot row with Fermat inverse:

$$
a^{-1} \equiv a^{p-2} \pmod p
$$

- For "any solution" tasks, set all free variables to `0`.
- Check for inconsistency after elimination before printing anything.

## Common Pitfalls

- treating composite-mod elimination like prime-mod elimination
- forgetting to normalize negative values back into `[0, MOD)`
- assuming every variable gets a pivot
- forgetting the inconsistency check after elimination
- confusing this lane with xor-basis elimination, which has much stronger `GF(2)` structure

## Exit Criteria

You are ready to move on when you can:

- explain why row operations preserve the solution set
- detect pivot columns versus free columns without guessing
- produce one valid assignment by setting free variables to `0`
- explain why prime-mod elimination is safe but composite-mod elimination needs extra care
- distinguish this lane from both [XOR Basis / Linear Basis](../xor-basis/README.md) and [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md)

## Retrieval And Practice

- Starter template: [`gaussian-elimination-mod-prime.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/gaussian-elimination-mod-prime.cpp)
- Hot sheet: [Gaussian Elimination hot sheet](../../../notebook/gaussian-elimination-hot-sheet.md)
- Practice ladder: [Gaussian Elimination / Linear Algebra ladder](../../../practice/ladders/math/gaussian-elimination/README.md)
- Flagship note: [System of Linear Equations](../../../practice/ladders/math/gaussian-elimination/systemoflinearequations.md)

## Go Deeper

- Reference: [cp-algorithms - Gauss & System of Linear Equations](https://cp-algorithms.com/linear_algebra/linear-system-gauss.html)
- Reference: [OI Wiki - Gaussian elimination](https://en.oi-wiki.org/math/gauss/)
- Practice: [CSES - System of Linear Equations](https://cses.fi/problemset/task/3154/)
