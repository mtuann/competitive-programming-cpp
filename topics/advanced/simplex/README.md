# Simplex

This lane is for the rare contest situation where the shortest honest route really is:

- write the optimization problem as one small continuous linear program
- normalize it to standard max form
- and run one numeric LP solver

The repo's exact first route is intentionally narrow:

$$
\text{maximize } c^T x
\quad
\text{subject to } Ax \le b,\ x \ge 0.
$$

This page is not a general linear-programming textbook, and it is definitely not an integer-programming page.

It is the contest route that sits next to:

- [Optimization And Duality](../optimization-and-duality/README.md) for the proof / benchmark lens
- [Min-Cost Flow](../../graphs/min-cost-flow/README.md) when the model is really a network
- [Lagrangian Relaxation / Aliens Trick](../../dp/lagrangian-relaxation/README.md) when the "LP feel" is actually one penalized DP family

## At A Glance

- **Use when:**
  - the variables are continuous real quantities such as pounds, liters, percentages, or fractional allocations
  - the objective and every constraint are linear
  - after light normalization, the model fits `Ax <= b, x >= 0`
  - you want one optimum value and one primal assignment, not an integral witness
- **Prerequisites:**
  - [Optimization And Duality](../optimization-and-duality/README.md)
  - [Reasoning](../../foundations/reasoning/README.md)
- **Boundary with nearby pages:**
  - use [Optimization And Duality](../optimization-and-duality/README.md) when the missing piece is the benchmark / certificate / proof language
  - use [Min-Cost Flow](../../graphs/min-cost-flow/README.md) when the structure is already a flow network with capacities and costs
  - use this page when the whole job is now "solve one small LP numerically"
- **Strongest cues:**
  - blending, diet, mixing, resource-allocation, or production-planning wording
  - coefficients are real-valued and the output itself is real-valued
  - the natural variables are "how much of each product / plan / action"
  - the editorial or intended route mentions `linear programming`, `simplex`, or `LP`
- **Strongest anti-cues:**
  - the variables must be integers or binary -> this is not integer programming
  - the real challenge is still graph / DP / geometry modeling
  - the task needs exact rational arithmetic or proof-grade certificates
  - the constraints do not naturally collapse into one small dense LP
- **Success after studying this page:**
  - you can map one contest story into `maximize c^T x, Ax <= b, x >= 0`
  - you can explain the meanings of `optimal`, `infeasible`, and `unbounded`
  - you know when simplex is the right shortcut and when it is the wrong abstraction

## Problem Model And Notation

The exact starter in this repo solves:

$$
\text{maximize } c^T x
\quad
\text{subject to } Ax \le b,\ x \ge 0
$$

where:

- `x_j` are continuous nonnegative decision variables
- row `i` of `A` and value `b_i` encode one upper-bound resource constraint
- `c_j` is the profit / score / gain per unit of variable `x_j`

This starter is meant for the contest normalization step:

- a constraint `a^T x >= beta` becomes `(-a)^T x <= -beta`
- an equality `a^T x = beta` usually becomes two inequalities
- a free variable is **not** in the exact first route; split it into `x^+ - x^-` only if the problem size still stays small and honest

The point of the lane is not "learn every LP form."

The point is:

- recognize when a statement already wants one small standard-form LP
- translate it cleanly
- trust one reusable solver

## Why This Exists Next To Optimization And Duality

[Optimization And Duality](../optimization-and-duality/README.md) teaches the language:

- lower bounds
- certificates
- relaxations
- primal-vs-dual thinking

This page teaches the narrower contest move:

- sometimes the continuous relaxation itself **is** the task you have to solve
- and a direct simplex implementation is the smallest exact route

That means the division of labor is:

- **duality page:** why LP language matters
- **simplex page:** how to solve one small LP when the statement really needs it

## Core Route In This Repo

The exact starter route is:

- dense tableau simplex
- two phases: first find feasibility, then optimize
- return:
  - status
  - optimal value when it exists
  - one primal assignment `x`

The exact contract is:

- objective: maximize
- constraints: `Ax <= b`
- variables: `x >= 0`
- arithmetic: floating-point (`long double`)

The exact non-promises are just as important:

- no integer-programming guarantee
- no exact rational certificate
- no claim of numerical perfection on pathological instances
- no promise that every LP modeling trick belongs here

## Core Invariants

### 1. Stay In One Honest Standard Form

Before calling the solver, every constraint must already mean:

$$
a_i^T x \le b_i
$$

with the same variable vector `x >= 0`.

If you are still mixing:

- `<=`
- `>=`
- free variables
- hidden integrality

then the modeling step is not finished yet.

### 2. Distinguish The Three Outcomes

The solver can return three qualitatively different answers:

- `optimal`: one best value exists
- `infeasible`: no feasible point exists
- `unbounded`: feasible points exist and the objective can grow without bound

Contest translation:

- `infeasible` usually means the normalized story has contradictory resource constraints
- `unbounded` usually means you forgot one real-world upper bound or modeled a quantity with the wrong sign

### 3. Numerical Stability Is A Contract Issue

Simplex in contest code is a floating-point implementation.

So:

- tiny `eps` comparisons are part of correctness
- noisy coefficients deserve scaling or careful normalization
- tasks that need exact combinatorial witnesses are usually a sign to step back and model differently

## Worked Example: Cheese, If You Please

Use [Cheese, If You Please](../../../practice/ladders/advanced/simplex/cheeseifyouplease.md).

Let:

- `x_j` = pounds of blend `j` we choose to produce

For cheese type `i`, each pound of blend `j` consumes:

$$
\frac{p_{ij}}{100}
$$

pounds of cheese `i`.

So every cheese type gives one resource constraint:

$$
\sum_j \frac{p_{ij}}{100} x_j \le w_i.
$$

The profit objective is:

$$
\max \sum_j t_j x_j.
$$

That is already the repo's exact route:

- continuous nonnegative variables
- one linear objective
- one upper-bound constraint per resource

No graph reduction is cleaner than the LP itself.

## Variant Chooser

| Situation | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| small continuous resource-allocation model with real-valued outputs | use simplex directly | the LP is already the natural object | weak if integrality is actually required |
| optimization story where the missing piece is the proof lens | use [Optimization And Duality](../optimization-and-duality/README.md) | the algorithm is known but the certificate is not | weak if you actually need a numeric solver |
| capacitated transport or path/cut model | use [Min-Cost Flow](../../graphs/min-cost-flow/README.md) or [Maximum Flow](../../graphs/flow/README.md) | network structure gives a stronger specialized solver | weak if the problem is not naturally a network |
| exact-`K` DP where one penalty removes the hard dimension | use [Lagrangian Relaxation / Aliens Trick](../../dp/lagrangian-relaxation/README.md) | the object is still a DP family, not a dense LP | weak if you force an LP viewpoint where a DP route is already exact |

## Complexity And Tradeoffs

The relevant contest tradeoff is:

- tiny modeling surface area
versus
- floating-point implementation risk

Practical notes:

- worst-case simplex complexity is exponential
- small contest LPs often run very well in practice
- the solver becomes more trustworthy when:
  - `x = 0` is already feasible
  - coefficients are not wildly scaled
  - the model is genuinely small and dense

This is why the lane belongs in `advanced`:

- it is powerful
- but it is not a first-choice hammer for routine core problems

## Main Traps

- forgetting that percentages must be divided by `100`
- modeling a variable that should be unrestricted as if it were nonnegative
- forcing an integer problem into continuous LP and then trusting the fractional optimum
- treating `unbounded` as a numeric bug instead of a modeling bug
- using simplex when a cleaner combinatorial model already exists

## Reopen Path

- Topic page: [Simplex](README.md)
- Practice ladder: [Simplex ladder](../../../practice/ladders/advanced/simplex/README.md)
- Starter template: [simplex-max-ax-le-b.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/simplex-max-ax-le-b.cpp)
- Notebook refresher: [Simplex hot sheet](../../../notebook/simplex-hot-sheet.md)
- Compare points:
  - [Optimization And Duality](../optimization-and-duality/README.md)
  - [Min-Cost Flow](../../graphs/min-cost-flow/README.md)
  - [Cheese, If You Please](../../../practice/ladders/advanced/simplex/cheeseifyouplease.md)

## References And Practice

- [KACTL Simplex header](https://raw.githubusercontent.com/kth-competitive-programming/kactl/main/content/numerical/Simplex.h)
- [Cheese, If You Please](https://open.kattis.com/problems/cheeseifyouplease)
- [ICPC World Finals 2016 Problem I: Road Times](https://icpc.global/worldfinals/problems/2016-ICPC-World-Finals/icpc2016.pdf)

