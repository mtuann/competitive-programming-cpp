# Approximation And Relaxation

Approximation and relaxation matter when exact optimization is too expensive, but the problem still has enough structure that you can prove:

- your answer is feasible
- your answer is not too far from optimal
- and the gap comes from one explicit design step, not from wishful thinking

This page is theory-led. The main payoff is not “one more contest template.” The payoff is learning how to replace an impossible exact benchmark with a controlled one.

## At A Glance

- Use this page when:
  - exact unrestricted optimization looks too broad after you already checked the usual exact rescue routes
  - the explanation talks about `ratio`, `guarantee`, `relaxation`, `rounding`, `charging`, or `primal-dual`
  - a fractional or simplified version of the problem is much easier to solve or analyze than the integral one
  - you want a proof that the construction is near-optimal, not just plausible
- Prerequisites:
  - [Optimization And Duality](../optimization-and-duality/README.md)
  - [Reasoning](../../foundations/reasoning/README.md)
- Check first:
  - [Complexity And Hardness](../complexity-and-hardness/README.md)
- Strongest cues:
  - the problem family is hard in general, but a simple greedy or LP-shadow benchmark keeps appearing
  - the proof compares your solution against a lower bound or upper bound instead of against an explicit optimal solution
  - the statement or editorial cares more about “provably close” than about “exact optimum”
  - the right solution seems to trade one clean loss factor for much easier computation
- Strongest anti-cues:
  - there is still an obvious exact graph / DP / flow / string model you have not exploited yet
  - the real difficulty is implementation pressure, not the absence of an exact model
  - you are trying to learn full LP machinery before you can state one concrete approximation guarantee
  - the page you really need is [Algorithm Engineering](../algorithm-engineering/README.md), not approximation theory
  - the statement only asks for any legal witness, not a near-optimal one; that usually belongs under [Constructive](../constructive/README.md)
  - the guarantee is `in expectation` or `with high probability` because the solver uses random choices; that belongs under [Randomized Algorithms](../randomized-algorithms/README.md)
- Success after studying this page:
  - you can state an approximation ratio cleanly for minimization and maximization
  - you can identify whether a relaxation gives a lower bound or an upper bound
  - you can explain where the approximation loss happens
  - you can separate LP rounding, charging, primal-dual, local-ratio, and approximation-scheme thinking

## Quick Route

Use this page as a router first.

```text
1. Did I already rule out the standard exact routes?
   pseudo-polynomial DP, small-parameter exact search, meet-in-the-middle, promise-driven exact model?

2. Is the problem still too broad in general?
   If yes, approximation may be the right language.

3. What easier benchmark can I trust?
   fractional relaxation, matching/cut lower bound, dual prices, or a simplified local rule?

4. Where does the gap enter?
   rounding, greedy charging, dual fitting, local-ratio scaling, or ε-dependent scheme?
```

Approximation is not a first reflex. It is what you reach for after exact modeling has been checked honestly.

## Problem Model And Notation

Suppose `OPT` is the optimum objective value.

Throughout this section, assume:

- the algorithm returns a feasible solution
- objective values are nonnegative, so multiplicative guarantees are meaningful

### Minimization

For a minimization problem, an algorithm is an $\alpha$-approximation if:

$$
\mathrm{ALG} \le \alpha \cdot \mathrm{OPT}
$$

for every input, with $\alpha \ge 1$.

Smaller is better. Exact optimization corresponds to $\alpha = 1$.

### Maximization

For a maximization problem, an algorithm is an $\alpha$-approximation if:

$$
\mathrm{ALG} \ge \frac{\mathrm{OPT}}{\alpha}
$$

for every input, again with $\alpha \ge 1$.

Equivalent forms like `ALG >= β OPT` with `0 < β <= 1` are also common; they are just different ways of writing the same guarantee.

### Relaxation

A relaxation makes the feasible region easier.

Common moves:

- allow fractional choices
- drop integrality
- weaken a hard global constraint
- compare against a different simpler benchmark problem

The first three bullets are genuine relaxations of the same optimization problem.

The last bullet is broader:

- it can still be useful for approximation
- but it does **not** automatically inherit the lower/upper-bound direction rules below

The direction of the bound matters.

#### Minimization

If you enlarge the feasible region for a minimization problem, the relaxed optimum can only get **smaller**:

$$
\mathrm{OPT}_{\mathrm{relax}} \le \mathrm{OPT}_{\mathrm{int}}.
$$

So the relaxation gives a lower bound.

#### Maximization

If you enlarge the feasible region for a maximization problem, the relaxed optimum can only get **larger**:

$$
\mathrm{OPT}_{\mathrm{relax}} \ge \mathrm{OPT}_{\mathrm{int}}.
$$

So the relaxation gives an upper bound.

This is one of the most important sign conventions on the whole page.

### Approximation Schemes

Two families appear often enough to deserve names.

- `PTAS`: for every fixed `\varepsilon > 0`, returns a `(1+\varepsilon)`-approximation for minimization, or equivalently a `(1-\varepsilon)`-style guarantee for maximization, in polynomial time for fixed `\varepsilon`
- `FPTAS`: same guarantee style, but running time is polynomial in both input size and `1 / \varepsilon`

Contest translation:

- `FPTAS` often comes from carefully scaling a pseudo-polynomial DP
- `PTAS` may still be far too slow in practice if the dependence on `1 / \varepsilon` is terrible

## From Exact Optimization To The Right Approximation Lens

The naive exact view is:

- search over all integral feasible solutions
- compare them directly

That fails on many hard optimization problems.

Approximation changes the question from:

- “How do I compute the exact optimum?”

to:

- “What benchmark can I solve or analyze, and how much do I lose when I move back to a feasible integral solution?”

That creates five standard design lenses.

Ownership boundary with nearby pages:

- [Optimization And Duality](../optimization-and-duality/README.md) owns the benchmark or certificate itself
- this page owns the step where a feasible algorithm is only within an explicit factor of that benchmark after rounding, charging, or controlled loss

### Lens 1: LP Relaxation And Rounding

Solve or analyze an easier fractional version, then round it back to an integral solution.

The loss comes from the rounding step.

### Lens 2: Charging / Greedy Analysis

Run a local greedy rule, then prove that each greedy payment can be charged to an optimal or benchmark quantity.

The loss comes from how many times one optimal object gets charged.

### Lens 3: Primal-Dual / Dual Fitting

Grow a benchmark and the solution together, or analyze a greedy solution by converting its cost into a near-feasible dual.

The loss comes from bounded infeasibility or bounded overpayment.

### Lens 4: Local-Ratio

Decompose weights into simpler layers, prove that each layer is handled safely, and recombine.

The loss comes from the layer-wise guarantee.

### Lens 5: Approximation Schemes

Exploit one numeric or geometric scale parameter so that a pseudo-polynomial or discretized exact algorithm becomes `(1 + \varepsilon)`-accurate after scaling.

The loss comes from discretization.

## Core Invariant And Why It Works

Every good approximation proof answers four questions.

### Invariant 1: The Benchmark Really Is A Bound

Before proving a ratio, identify what benchmark you are using and why it bounds `OPT`.

Common valid benchmarks:

- LP relaxation optimum
- matching or packing lower bound
- cut lower bound
- dual-feasible solution
- exact optimum of a simpler proxy problem

If this step is missing, the rest of the proof is not analysis; it is storytelling.

### Invariant 2: The Rounded Or Greedy Output Is Feasible

Approximation is never just “close value.” It is:

- feasible solution
- with provable objective guarantee

So the first job after rounding or greedy construction is always:

- prove every original constraint is still satisfied

This is where many intuitive but invalid heuristics fail.

### Invariant 3: The Loss Happens In One Explicit Place

Mature approximation proofs identify one clean source of loss:

- every edge can force at most two chosen endpoints
- every uncovered element is charged at most `H_n` times
- scaling values changes the optimum by at most `\varepsilon \cdot \mathrm{OPT}`
- each primal choice is paid for by one bounded amount of dual growth

If you cannot point to the exact place where the factor comes from, the guarantee is usually not ready.

### Invariant 4: Schemes Trade Accuracy For Runtime Deliberately

For PTAS/FPTAS-style algorithms, the guarantee is not a free bonus. You intentionally spend more time as $\varepsilon$ shrinks.

Contest translation:

- approximation schemes are controlled compromises, not “exact algorithms that happen to be fast”

## Complexity And Tradeoffs

The main tradeoff is:

- better provable structure on hard optimization problems
versus
- weaker guarantees than exact optimization

Typical patterns:

| Pattern | What you gain | Main risk |
| --- | --- | --- |
| LP relaxation + rounding | a clean benchmark and explicit rounding loss | forgetting the direction of the relaxed bound |
| greedy charging | simple algorithm with transparent analysis | proving the algorithm sounds plausible but not bounding total charge |
| primal-dual / dual fitting | tighter proof structure and often cleaner design | using dual language without writing the actual benchmark |
| local-ratio | elegant weighted reductions | losing the thread of what the weight split is buying |
| PTAS / FPTAS | arbitrarily good approximation by paying more runtime | hiding an impractical dependence on `1 / \varepsilon` |

Important contest lesson:

- approximation theory becomes useful only after exact-model triage
- otherwise it is too easy to study it as abstract vocabulary instead of as a response to hardness

## Variant Chooser

| Situation | Best first lens | Why it fits | Where it fails |
| --- | --- | --- | --- |
| integral minimization has a natural fractional form | LP relaxation + rounding | the fractional optimum gives a clean lower bound | weak if the relaxation is too loose |
| greedy rule keeps paying for local fixes | charging / greedy analysis | the ratio often comes from bounded repeated charging | weak if the same optimal object can be charged arbitrarily many times |
| weighted covering constraints can be raised until objects become tight | primal-dual or dual fitting | benchmark and construction move together as prices grow | weak if you never define the priced constraints |
| weighted penalties share a common layer you can subtract without changing the key decision | local-ratio | layer-by-layer safety can be easier than direct analysis | weak if the decomposition obscures feasibility or destroys the useful structure |
| one numeric axis is moderate and exact DP is pseudo-polynomial | FPTAS / scaling | exact DP can be converted into a near-exact scheme | weak if the scaled DP is still too large or the problem has no useful numeric axis |

## Worked Examples

### Example 1: Vertex Cover And The First Honest Factor 2

Take an unweighted graph and build any maximal matching `M`.

Return both endpoints of every edge in `M`.

Why this is feasible:

- every uncovered edge could be added to the matching
- but the matching was maximal
- so every edge must touch at least one chosen endpoint

Why the factor is `2`:

- each edge in `M` contributes two chosen vertices
- any vertex cover must hit every edge in `M`
- because the edges in `M` are disjoint, every cover needs at least `|M|` vertices

So:

$$
|C| = 2|M| \le 2 \cdot \mathrm{OPT}.
$$

This is the cleanest packing-lower-bound approximation proof:

- feasibility from maximality
- lower bound from disjointness
- loss factor appears in one visible place: “two endpoints per matched edge”

Contrast this with Example 2:

- here the benchmark is a disjoint packing object
- there the proof is a true charging argument

### Example 2: Set Cover Greedy And Harmonic Charging

At each step, choose the set with the best cost-per-newly-covered-element ratio.

The proof is not just “greedy seems sensible.” The proof is:

- each newly covered element is charged its share of the chosen set’s price
- the total charge equals the algorithm’s final cost
- one optimal set of size `t` can be forced to pay at most:

$$
1 + \frac{1}{2} + \cdots + \frac{1}{t} = H_t
$$

across the elements it covers

So the algorithm is within a logarithmic factor of optimal.

This is the canonical charging lesson:

- approximation loss often comes from how many times one benchmark object can be blamed

### Example 3: Weighted Vertex Cover Via LP Relaxation

For weighted vertex cover, solve the LP relaxation:

$$
\text{minimize } \sum_{v \in V} w_v x_v
\quad
\text{subject to } x_u + x_v \ge 1 \text{ for each edge } (u, v),\ x_v \ge 0.
$$

Round by taking every vertex with:

$$
x_v \ge \frac{1}{2}.
$$

Why feasibility holds:

- every edge `(u, v)` satisfies `x_u + x_v \ge 1`
- so at least one endpoint must have value at least `1/2`

Why the factor is `2`:

$$
\sum_{v \in C} w_v
\le
\sum_{v \in C} 2 w_v x_v
\le
2 \sum_{v \in V} w_v x_v
\le
2 \cdot \mathrm{OPT}.
$$

This is the textbook LP-rounding pattern:

- relaxed optimum gives the benchmark
- threshold rounding creates feasibility
- the threshold itself explains the ratio

This same family also gives one of the cleanest primal-dual and local-ratio mental models:

- in a primal-dual view, raise dual weight on uncovered edges until a vertex becomes tight, then buy it
- in a local-ratio view, subtract a common weight layer from the endpoints of one uncovered edge and recurse

The code and proof change, but the router cue is similar:

- weighted covering constraints keep producing tight objects as you pay for uncovered requirements

### Example 4: Weighted Covering As A Primal-Dual / Local-Ratio Pattern

Suppose the problem is a weighted covering problem where:

- each uncovered requirement can “raise pressure” on a small set of candidate objects
- once an object becomes tight, buying it is natural

That is the structural cue for primal-dual thinking.

In weighted vertex cover, for example, one useful contest mental model is:

1. start all dual edge-prices at `0`
2. choose an uncovered edge
3. increase its price until one endpoint’s weight is fully paid for
4. buy that tight endpoint

The dual variables provide a lower bound, while the chosen tight vertices provide the feasible cover.

The local-ratio lens describes nearly the same phenomenon differently:

- peel off one common weight layer from the endpoints of an uncovered edge
- solve the residual problem
- show that any residual-good solution can be extended without losing more than the target factor

The real lesson is not to memorize both proofs immediately. It is to recognize the cue:

- weighted covering + tightness or common removable layers

### Example 5: Knapsack Approximation Schemes Come From Scaling

Use [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md) as the exact pseudo-polynomial anchor.

Exact `0/1` knapsack can be solved by pseudo-polynomial DP because one numeric axis is moderate.

When the numeric axis becomes too large, one standard rescue is:

- identify which exact axis has failed, usually the value / profit axis
- choose a scaling factor `K` proportional to `\varepsilon`
- replace each value `v_i` by a scaled value like `\lfloor v_i / K \rfloor`
- solve the exact pseudo-polynomial DP on the scaled instance
- recover a solution whose total value is within `(1-\varepsilon)` of optimal, equivalently within a `(1+\varepsilon)` minimization-style factor after the usual reparameterization

This is a good maturity checkpoint:

- `Book Shop` teaches that one number line can support exactness
- when that exact number line becomes too large, scaling shows how to keep the same DP skeleton but pay a controlled approximation loss instead

The loss now comes from discretization, not from greedily throwing structure away.

## Practice Archetypes

- covering problems where every local fix can be charged to a benchmark
- weighted minimization problems with a natural LP relaxation
- hard exact optimization problems where the best contest-facing story is “near-optimal with proof”
- pseudo-polynomial DPs that can be turned into approximation schemes by scaling
- editorials that say `tight`, `price`, `dual`, `round`, or `fractional optimum`

## References And Repo Anchors

### Primary / Course

- MIT 6.046J, [Complexity: Approximation Algorithms](https://www.ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/resources/lecture-17-complexity-approximation-algorithms/)
- MIT 6.854 Notes, [Approximation algorithms notes](https://courses.csail.mit.edu/6.854/20/Notes/n20-approx.html)
- Stanford CS261 notes, [Optimization Paradigms](https://web.stanford.edu/class/cs369/files/CS261-Notes.pdf)
- Berkeley CS 174, [Lecture notes archive](https://people.eecs.berkeley.edu/~jordan/courses/174-spring02/notes.html)
- Oxford, [Approximation Algorithms course page](https://www.cs.ox.ac.uk/teaching/courses/2025-2026/approxalg/)

### Reference

- Stanford / Trevisan, [Vertex Cover approximation notes](https://theory.stanford.edu/~trevisan/cs170/notes/lecture24.pdf)

### Repo Anchors

- check-first route: [Complexity And Hardness](../complexity-and-hardness/README.md)
- benchmark / certificate prerequisite: [Optimization And Duality](../optimization-and-duality/README.md)
- pseudo-polynomial anchor: [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md)
- nearby topic: [Randomized Algorithms](../randomized-algorithms/README.md)

## Related Topics

- [Complexity And Hardness](../complexity-and-hardness/README.md)
- [Optimization And Duality](../optimization-and-duality/README.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)
- [Constructive](../constructive/README.md)
