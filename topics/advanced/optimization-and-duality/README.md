# Optimization And Duality

Optimization and duality matter when the algorithm itself is only half of the story.

The other half is the benchmark, lower bound, or certificate that explains:

- why no solution can be better than some number
- why your computed object is already optimal
- or why a greedy/approximation step is paying for the right quantity

This page is theory-led. The main payoff is not “learn one more template.” The main payoff is learning to see the hidden witness on the other side of an optimization problem.

## At A Glance

- Use this page when:
  - the proof compares your solution against a benchmark rather than against another explicit construction
  - the right explanation involves a lower bound, a fractional relaxation, or a cut / packing / price interpretation
  - the statement asks for a certificate, not only an optimum value
  - you want to understand why a greedy or flow-based method is optimal or approximately optimal
- Prerequisites:
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Maximum Flow](../../graphs/flow/README.md)
- Boundary with nearby pages:
  - use [Maximum Flow](../../graphs/flow/README.md) when the hard part is modeling the residual network and running the algorithm
  - use this page when the algorithm is already known and the missing piece is the benchmark, certificate, or proof lens
- Strongest cues:
  - the proof language says `lower bound`, `certificate`, `fractional optimum`, `dual`, `tight`, or `complementary slackness`
  - a max-flow computation is followed by a cut extraction
  - the algorithm chooses objects while some constraints become “tight”
  - the integral problem is hard, but a fractional shadow problem is easy to analyze
- Strongest anti-cues:
  - the real difficulty is still modeling the graph / DP / number theory object
  - you only need to code a routine and no proof lens is changing
  - the page you really need is [Algorithm Engineering](../algorithm-engineering/README.md), not an optimization benchmark
  - you are trying to learn full LP machinery before you can state one concrete lower bound
- Success after studying this page:
  - you can say what the benchmark is and why it is valid
  - you can distinguish primal solution, dual certificate, and relaxation cleanly
  - you can explain why `max flow = min cut` is an exact duality statement, not just a theorem to memorize
  - you can recognize when a proof is really using complementary-slackness or charging intuition

## Problem Model And Notation

A large part of optimization-and-duality thinking can be taught through one canonical minimization form:

$$
\text{minimize } c^T x
\quad
\text{subject to } Ax \ge b,\ x \ge 0.
$$

Think of this as:

- `primal variables` $x$: the solution you build or pay for
- `constraints` $Ax \ge b$: what feasibility demands
- `objective` $c^T x$: what you want to minimize

Its standard dual is:

$$
\text{maximize } b^T y
\quad
\text{subject to } A^T y \le c,\ y \ge 0.
$$

Think of this dual as:

- `dual variables` $y$: prices, packed witness, or lower-bound weights on constraints
- `dual feasibility` $A^T y \le c$: no primal object is overpaid
- `dual objective` $b^T y$: the lower bound you can certify

This is already enough to explain most contest-relevant duality language.

Tiny contest dictionary:

- in weighted vertex cover, primal variables choose vertices and dual variables price edges
- in max flow / min cut, the primal object is the flow and the dual object is the cut
- in min-cost flow with potentials, reduced-cost feasibility behaves like a dual-flavored certificate

### Weak Duality

For every primal-feasible $x$ and dual-feasible $y$,

$$
b^T y \le c^T x.
$$

This is the universal benchmark statement:

- every dual-feasible solution gives a valid lower bound for a minimization problem
- every primal-feasible solution gives a valid upper bound

### Strong Duality

Under standard LP conditions, the best primal value equals the best dual value.

That means:

- if you find a primal-feasible solution and a dual-feasible certificate with the same value
- then both are optimal

This is exactly the logic behind many exact graph theorems:

- `max flow = min cut`
- bipartite matching / vertex cover correspondences
- shortest paths with feasible potentials

### Complementary Slackness Intuition

At optimum, not every variable and constraint matters equally.

Complementary slackness says, roughly:

- if a primal variable is positive, the corresponding dual constraint should be tight
- if a dual variable is positive, the corresponding primal constraint should be tight

Contest translation:

- if your algorithm “selects” an object, some price or bound often becomes exactly saturated there
- if a dual variable grows, it is usually paying for a real obstruction

You do not need full LP formalism to benefit from this intuition.

## From Brute Force To The Right Idea

The naive exact view is:

- search over all integral feasible solutions
- compare their objective values directly

That often explodes.

The duality move is to stop comparing candidate solutions only against each other and instead compare them against a benchmark that every feasible solution must respect.

Typical benchmark moves:

- **cut certificate**:
  every flow is bounded by every cut, so a matching-value cut proves optimality
- **fractional relaxation**:
  the relaxed optimum is easier to analyze and lower-bounds the integral optimum
- **price interpretation**:
  assign nonnegative weights to constraints so that any feasible primal object must pay at least the total price
- **tightness interpretation**:
  understand why greedy choices are safe because they saturate the right inequalities

The recurring contest move is:

- do not ask only “what solution do I output?”
- also ask “what witness explains that no better solution can exist?”

## Core Invariant And Why It Works

Every useful duality proof answers three questions.

### Invariant 1: The Benchmark Is Valid

Before using a bound, prove it is actually a bound.

This is weak duality in practice:

- every feasible flow is at most every cut capacity
- every feasible dual price assignment lower-bounds every feasible primal minimization solution
- a fractional relaxation lower-bounds the integral minimization optimum because it enlarges the feasible region

If this first step is missing, everything after it is storytelling.

### Invariant 2: The Algorithm Never Spends More Than It Can Justify

When an algorithm is compared against a benchmark, each step should be payable by some piece of the bound.

This appears in different forms:

- primal-dual growth: raise dual variables until some primal object becomes tight
- dual fitting: analyze a greedy solution by retrospectively turning its charges into a near-feasible dual
- cut extraction: the residual reachability set exposes exactly the saturated bottleneck

This is the place where optimization language explains algorithm design instead of only certifying the end.

### Invariant 3: Matching Values Or Bounded Gap Finish The Proof

There are two standard endings.

#### Exact optimality

Show:

$$
\text{primal value} = \text{dual value}.
$$

Then the solution is optimal.

#### Approximate optimality

Show:

$$
\text{algorithm value} \le \alpha \cdot \text{dual or relaxed benchmark}
$$

for minimization, or the symmetric inequality for maximization.

Then the algorithm is an $\alpha$-approximation.

This is why the same language bridges exact graph theorems and approximation proofs.

## Complexity And Tradeoffs

The main tradeoff here is conceptual:

- you gain a much stronger proof lens
versus
- you often write less code and more reasoning

Typical patterns:

| Pattern | What you gain | Main risk |
| --- | --- | --- |
| exact dual certificate | a proof of optimality plus an object to print | treating theorem names as substitutes for the actual witness |
| LP relaxation benchmark | a clean lower bound and design guide | forgetting whether the relaxed optimum is an upper or lower bound |
| primal-dual / dual fitting | an explanation of why greedy steps are safe | using dual language without stating the actual dual object |
| reduced-cost / potential view | cleaner correctness for shortest-path or flow subroutines | mixing implementation invariants with full LP theory too early |

Important contest lesson:

- the fastest way to mature on this topic is not to memorize more LP terminology
- it is to learn to name one real benchmark and say why it is valid

## Variant Chooser

| Situation | Best first lens | Why it fits | Where it fails |
| --- | --- | --- | --- |
| exact flow-style optimization with a cut object on the other side | exact dual certificate | strong duality gives matching values and a printable witness | weak if you still cannot model the problem as a flow/cut pair |
| integral minimization problem looks rigid but fractional version is natural | LP relaxation benchmark | the relaxed optimum lower-bounds the integral optimum | weak if the relaxation is too loose to be informative |
| greedy or approximation proof keeps “paying for constraints” | primal-dual or dual-fitting lens | dual variables explain where the paid cost comes from | weak if you never define the priced constraints |
| shortest augmenting path or reduced-cost arguments appear | feasible-potential lens | dual-like potentials certify nonnegative reduced costs | weak if you treat potentials as black magic rather than a benchmark device |
| editorial keeps saying `tight`, `saturated`, or `equal by theorem` | complementary-slackness intuition | equality at tight constraints explains why the chosen objects are the right ones | weak if no actual primal/dual pair has been identified |

## Worked Examples

### Example 1: Max Flow / Min Cut As Exact Duality

Use [Police Chase](../../../practice/ladders/graphs/flow/policechase.md).

Primal view:

- send as much flow as possible from `s` to `t`

Dual view:

- block every `s-t` route by cutting a minimum-capacity set of edges

Weak duality in this setting says:

$$
\text{value of any feasible flow} \le \text{capacity of any } s\text{-}t \text{ cut}.
$$

So every cut is already a certificate that no flow can exceed it.

Why the theorem becomes algorithmically useful:

1. run a max-flow algorithm
2. inspect the residual graph
3. let $S$ be the set of vertices still reachable from `s`
4. the edges from $S$ to $V \setminus S$ form a minimum cut

Now you have both:

- a primal witness: the max flow value
- a dual witness: the minimum cut itself

That is the cleanest contest example of strong duality:

$$
\text{max flow value} = \text{min cut value}.
$$

### Example 2: Fractional Relaxation For Weighted Vertex Cover

Assume nonnegative vertex weights $w_v \ge 0$.

Weighted vertex cover can be written as:

$$
\text{minimize } \sum_{v \in V} w_v x_v
$$

subject to:

$$
x_u + x_v \ge 1 \quad \text{for every edge } (u, v),
\qquad
x_v \in \{0, 1\}.
$$

Relax the integrality to:

$$
x_v \ge 0.
$$

For nonnegative weights, the explicit bound $x_v \le 1$ is redundant in the optimum, because increasing a variable above `1` only raises the cost and never helps additional edge constraints.

Now the LP is easier to reason about, and its optimum is a lower bound on every integral vertex cover.

Why this matters even before approximation algorithms:

- the relaxation gives you a benchmark
- any integral solution must cost at least the LP optimum
- if the gap is small or your rounding is controlled, the LP has real design value

This is the standard “optimization shadow problem” pattern:

- exact combinatorial object on one side
- easier fractional benchmark on the other

Tiny trace:

- take a triangle on vertices `a, b, c`
- set every vertex weight to `1`
- every integral vertex cover needs at least two vertices, so the best integral cost is `2`
- the fractional assignment

$$
x_a = x_b = x_c = \frac{1}{2}
$$

is feasible because every edge sees two endpoints summing to `1`

Its cost is:

$$
\frac{1}{2} + \frac{1}{2} + \frac{1}{2} = \frac{3}{2}.
$$

So the LP relaxation already certifies:

$$
\frac{3}{2} \le \text{OPT}_{\text{integral}} = 2.
$$

### Example 3: Dual Prices For Weighted Vertex Cover

The dual of the relaxed weighted vertex cover LP is:

$$
\text{maximize } \sum_{e \in E} y_e
$$

subject to:

$$
\sum_{e \ni v} y_e \le w_v
\quad \text{for every vertex } v,
\qquad
y_e \ge 0.
$$

Continue the same triangle with unit weights.

Set:

$$
y_{ab} = y_{bc} = y_{ca} = \frac{1}{2}.
$$

This dual solution is feasible because each vertex is incident to exactly two edges, so its total incident dual price is:

$$
\frac{1}{2} + \frac{1}{2} = 1 = w_v.
$$

The dual value is therefore:

$$
\frac{1}{2} + \frac{1}{2} + \frac{1}{2} = \frac{3}{2}.
$$

So in one tiny graph you can literally see:

- primal LP value: `3/2`
- dual LP value: `3/2`
- integral optimum: `2`

Interpretation:

- each edge wants one unit of coverage
- each dual variable $y_e$ is a price placed on that demand
- each vertex has a budget $w_v$ for the total incident price it can absorb

Why this is a beautiful contest-proof lens:

- dual feasibility means you never charge more to a vertex than its weight
- when a vertex becomes tight, it is a natural candidate to include
- a primal-dual algorithm can be read as “grow prices until a useful object tightens”

This is where complementary slackness becomes intuition rather than theorem language:

- chosen primal objects should often correspond to tight dual constraints

### Example 4: Potentials As A Dual-Flavored Side Window

In min-cost flow with successive shortest augmenting paths, vertex potentials maintain nonnegative reduced costs:

$$
c'(u, v) = c(u, v) + \pi(u) - \pi(v).
$$

Why this belongs here:

- the potentials are not just an implementation trick for Dijkstra
- they act like a feasible dual-style certificate for the current residual costs

Tiny bridge:

- if every reduced cost $c'(u, v)$ is nonnegative
- then Dijkstra is safe on the reweighted residual graph
- and the original path costs are preserved up to one telescoping potential difference

This is a good reminder that optimization language sometimes hides inside ordinary code. If you want one internal side mention rather than a primary anchor, see [MINCOST](../../../practice/ladders/graphs/flow/mincost.md).

## Algorithm And Pseudocode

There is no universal code template here, but there is a universal proof checklist.

```text
OPTIMIZATION_LENS(instance I):
    write the original objective clearly
    choose one benchmark:
        exact dual certificate
        LP / fractional relaxation
        dual prices or feasible potentials

    prove the benchmark is valid:
        weak duality
        relaxation lower bound
        feasible cut / certificate / price assignment

    if the goal is exact optimality:
        find matching primal and dual values
        or output the dual witness directly

    if the goal is approximation:
        compare the algorithm cost to the benchmark
        say exactly where the approximation factor is lost

    if the proof uses “tight” language:
        identify which constraints or variables become tight and why that matters
```

The central question is always:

- what benchmark is proving that my answer cannot be improved?

If you cannot answer that, the duality story is still too vague.

## Implementation Notes

### Output The Certificate When The Statement Wants It

Some problems do not want only the optimum value.

They want:

- a cut
- a matching
- a chosen set
- a transportation plan

In those problems, the “dual object” is often exactly the required output.

[Police Chase](../../../practice/ladders/graphs/flow/policechase.md) is the cleanest internal example.

### Do Not Oversell LP Machinery

Most contest users do **not** need:

- simplex
- interior point methods
- full formal derivations of every dual

What they do need is:

- a valid benchmark
- a clear inequality direction
- and an explanation of where equality or bounded gap comes from

### Name The Direction Of The Bound

This sounds basic, but it is the easiest place to drift:

- for minimization, a dual-feasible solution or relaxed optimum is usually a **lower bound**
- for maximization, it is often an **upper bound** after the right transformation

Write the direction explicitly.

### Potentials And Reduced Costs Are Not “Just An Optimization”

When you use feasible potentials in shortest paths or min-cost flow, there is usually a deeper optimization story:

- reduced costs stay nonnegative
- shortest-path logic becomes safe again
- the potential function is carrying certificate-like information

You do not always need the full dual derivation, but it is worth recognizing the flavor.

## Practice Archetypes

- `warm-up`: exact dual certificate you can literally print
  - [Police Chase](../../../practice/ladders/graphs/flow/policechase.md)
  - why it belongs here: the residual graph exposes a minimum cut certificate whose value matches the computed flow
- `lightweight navigation page`: current internal route for this area
  - [Optimization And Duality ladder](../../../practice/ladders/advanced/optimization-and-duality/README.md)
  - why it belongs here: it is the repo’s current bridge from approximation language to exact certificate language, not yet a full solved-note progression

## References And Repo Anchors

- `Course`
  - [MIT 6.854: Duality notes](https://courses.csail.mit.edu/6.854/18/Notes/n12-duality.html)
  - [MIT OCW 6.854J: Duality notes PDF](https://ocw.mit.edu/courses/6-854j-advanced-algorithms-fall-2005/99eac3e02c1e1c317f20ef3cad4f6a28_dualitynotes.pdf)
  - [MIT 18.310: Linear Programming notes](https://math.mit.edu/~shor/18.310/lpnotes310.pdf)
  - [Stanford CS161: Max Flow lecture](https://web.stanford.edu/class/archive/cs/cs161/cs161.1168/lecture16.pdf)
  - [Cornell CS6820: Approximation algorithms notes](https://www.cs.cornell.edu/courses/cs6820/2021fa/handouts/approx_algs.pdf)
  - [Cornell CS6820: Matchings / primal-dual notes](https://www.cs.cornell.edu/courses/cs6820/2024fa/handouts/matchings.pdf)
- `Repo anchors`
  - [Optimization And Duality ladder](../../../practice/ladders/advanced/optimization-and-duality/README.md)
  - [Police Chase](../../../practice/ladders/graphs/flow/policechase.md)
  - [Maximum Flow](../../graphs/flow/README.md)
  - [Approximation And Relaxation](../approximation-and-relaxation/README.md)
  - [Complexity And Hardness](../complexity-and-hardness/README.md)

## Related Topics

- [Approximation And Relaxation](../approximation-and-relaxation/README.md): use it when the main goal is an approximation ratio or rounding guarantee
- [Maximum Flow](../../graphs/flow/README.md): use it when the main entry point is the algorithm, not the dual certificate behind it
- [Complexity And Hardness](../complexity-and-hardness/README.md): use it when the main question is what kind of guarantees are even realistic
- [Algorithm Engineering](../algorithm-engineering/README.md): use it when the proof is settled and the remaining bottleneck is implementation trust or performance
