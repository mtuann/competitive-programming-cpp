# Complexity And Hardness

Complexity and hardness are useful in contest programming for one reason above all:

- they tell you what kind of exact algorithm is still realistic
- and, just as importantly, when the current model is asking for something structurally impossible at full scale

This page is theory-led. The payoff is not “memorize more class names.” The payoff is learning to triage an optimization or search problem before you waste an hour polishing the wrong state space.

## At A Glance

- Use this page when:
  - the brute-force search space grows like `2^n`, `n!`, set partitions, coverings, or arbitrary subset choices
  - the statement exposes a small side parameter, a moderate numeric budget, or a suspiciously tiny alphabet / mask / answer size
  - you need to decide whether the right compromise is pseudo-polynomial DP, FPT, meet-in-the-middle, or a complete reformulation
  - you want to understand why some problem families keep reappearing as “hard in general, but manageable under one extra promise”
- Prerequisites:
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Knapsack Family](../../dp/knapsack-family/README.md)
  - [Bitmask DP](../../dp/bitmask-dp/README.md)
  - [Approximation And Relaxation](../approximation-and-relaxation/README.md)
- Strongest cues:
  - the naive model is “choose any subset / partition / ordering” and nothing about it looks monotone or decomposable
  - one constraint is huge in value but small in count, or small in count but huge in value
  - the editorial flavor is “the general problem is hard, but here one quantity is tiny”
  - the right algorithm depends more on what is small than on what the story says
- Strongest anti-cues:
  - the statement already has obvious graph, DP, or data-structure structure and you have not exploited it yet
  - the true blocker is implementation discipline, not search-space size
  - you are trying to prove NP-hardness during a contest instead of extracting a modeling signal from the constraints
  - the problem already lives in a core family with a known exact algorithm and clean constraints
- Success after studying this page:
  - you can distinguish polynomial, pseudo-polynomial, FPT, meet-in-the-middle, and “probably still too large”
  - you can explain why `O(nW)` is not polynomial in the real input length
  - you can tell when a bitmask exact algorithm is smart and when it is just disguised brute force
  - you can use hardness as a design signal without overusing theory jargon

## Quick Triage

Use this page first as a router, then as a theory reference.

```text
0. Did I miss an ordinary core model first?
   graph, DP, prefix, flow, matching, string, geometry, data structure?

1. If the raw model is still subset / partition / cover / ordering:
   what quantity is actually small?

2. If a numeric bound is small:
   try pseudo-polynomial DP.

3. If a genuine side parameter is small:
   try FPT / bitmask / bounded branching.

4. If the search is subset-like and n is around 35-45:
   try meet-in-the-middle.

5. If none of those shrink the state space:
   treat hardness as a signal to reformulate, exploit a promise, or relax.
```

This is a chooser by signal, not a universal fixed pipeline.

## Problem Model And Notation

This page is about identifying which quantity should carry the exponential cost, if any.

Three different “sizes” often matter at once:

- `n`: number of objects, vertices, items, positions, or choices
- `U`: numeric magnitude such as capacity, budget, coordinate bound, or value limit
- `k`: a small structural parameter such as answer size, number of colors, mask width, or number of special vertices

Those give four important exact-algorithm shapes.

### Truly Polynomial

If the full encoded input is `x`, polynomial-time means a running time bounded by:

$$
|x|^{O(1)}
$$

in the total input length.

Contest translation:

- if every numeric field is written in binary, the number of bits needed to describe a value `U` is about `\log U`
- so a runtime polynomial in `U` itself is usually **not** polynomial in the real input size

### Pseudo-Polynomial

A pseudo-polynomial algorithm looks like:

$$
\mathrm{poly}(n, U),
$$

where `U` is a numeric magnitude, not its bitlength.

Typical contest example:

$$
O(nW)
$$

for knapsack with capacity `W`.

This can be excellent in practice when `W` is at most `2 \cdot 10^5`, but it is not “polynomial” if `W` can be as large as `10^{12}`.

### Fixed-Parameter Tractable

A parameterized exact algorithm is FPT if it runs in:

$$
f(k)\, n^{O(1)}
$$

for some function `f`.

Contest translation:

- exponential in the right tiny parameter can be a win
- exponential in the wrong “parameter” is just brute force with nicer notation

Examples:

- `O(2^k \cdot n)`
- `O(3^k \cdot n)`
- `O(k! \cdot n^2)`

### Small-`n` Exact Search

Some contest algorithms are completely reasonable even though they are exponential in the full problem size, simply because `n` itself is tiny.

Typical shapes:

- `O(2^n \cdot n)` for `n <= 20`
- `O(3^n)` for `n <= 18`
- `O(n^2 2^n)` for `n <= 20`

This is **not** a parameterized-complexity claim by itself.

It is just exact search on a small instance.

That distinction matters because:

- a mask over `M <= 10` colors is often genuine FPT-style thinking
- a mask over all `n` objects is often just small-`n` exact DP

### Meet-In-The-Middle

Meet-in-the-middle is not a complexity class, but it is an important compromise:

$$
2^n \longrightarrow 2^{n/2}
$$

plus sorting or hashing overhead.

Contest translation:

- `n = 40` is hopeless for plain subset brute force
- `2^{20}` on each side is often very reasonable

## From Brute Force To The Right Idea

The naive instinct usually sounds like:

- “enumerate all subsets”
- “try all partitions”
- “pick an order for everything”
- “search all covers / assignments / pairings”

That is often the correct conceptual starting point, but the wrong final model.

The mature move is to ask:

1. what is the *true* combinatorial search space?
2. which quantity is actually small: `n`, `U`, `k`, or half of `n`?
3. can I pay exponential only in that small quantity?
4. if not, is the general problem likely hard enough that I should stop fighting the current formulation?

This produces four common rescue routes.

### Route 1: Numeric DP

If the obstruction is a moderate budget, sum, or value bound, the right move is often pseudo-polynomial DP.

### Route 2: Small-Parameter Exact Search

If one structural parameter is tiny, use bitmask DP, bounded branching, or another FPT-style exact algorithm.

### Route 3: Small-`n` Exact Search

If the entire instance size is tiny, a full-state exact DP or search may already be the intended solution.

### Route 4: Split The Search Space

If the raw search is subset-like and `n` is around `35` to `45`, meet-in-the-middle may be the real answer.

### Route 5: Admit The Model Is Too General

If none of the above applies, hardness intuition becomes valuable. It tells you to look for:

- extra promises
- a different objective
- a relaxation or approximation
- a certificate rather than an exact global optimum

Common pivots from that point:

- to [Approximation And Relaxation](../approximation-and-relaxation/README.md) if exact unrestricted optimization still looks too broad
- to [Optimization And Duality](../optimization-and-duality/README.md) if the real missing piece is a benchmark or certificate
- to [Constructive](../constructive/README.md) if the statement’s special promise is what actually collapses the space

That is the real contest meaning of hardness:

- not “prove a theorem mid-round”
- but “stop polishing a fundamentally oversized model”

## Core Invariant And Why It Works

This page has four core invariants.

### Invariant 1: Input Length Is About Bitlength, Not Numeric Magnitude

If a problem contains an integer `W`, the encoded size of that value is only:

$$
O(\log W).
$$

So an `O(nW)` algorithm may still be exponential in the real input length if `W` is huge.

This is why pseudo-polynomial and polynomial are not the same thing.

If you forget this invariant, you will misclassify knapsack-like DP as “efficient in general” instead of “efficient only when the numeric bound is small enough.”

### Invariant 2: The Exponential Cost Must Land On The Right Quantity

An exact exponential algorithm is only acceptable when the thing carrying the exponential blow-up is truly small.

Good examples:

- `O(2^M \cdot N)` when `M <= 20`
- `O(3^k \cdot n)` when `k <= 25`
- `O(n^2 2^n)` when the full `n` is at most about `20`
- `O(2^{n/2} \cdot n)` when `n <= 40`

Bad examples:

- `O(2^n)` with `n = 100`
- `O(W^2)` when `W` is a binary-encoded budget around `10^9`
- `O(2^k)` where `k` is just another name for `n`

The invariant is simple:

- the exponential or superlinear part must be attached to the smallest meaningful dimension in the statement

### Invariant 3: Pseudo-Polynomial Only Helps Against Numeric Magnitude

Pseudo-polynomial DP works when the hard dimension is a moderate number line:

- capacity
- sum
- value

It does **not** magically solve arbitrary combinatorial explosion.

This is why strong NP-hardness matters conceptually:

- for many strongly NP-hard problems, you should not expect a useful pseudo-polynomial rescue in the clean “DP on the number line” sense
- the useful intuition is that the difficulty survives even when numeric values are polynomially bounded or unary-encoded

Contest translation:

- “just DP on the value” is only a real idea if the value dimension is modest enough to be materialized

### Invariant 4: Hardness Is A Modeling Signal, Not A Coding Template

Hardness language becomes useful when it changes your behavior:

- from “keep micro-optimizing this exact search”
- to “search for the missing promise, small parameter, or relaxation”

That is the right maturity goal.

The wrong use is:

- dropping `NP-hard` as trivia without extracting any algorithmic consequence

## Complexity And Tradeoffs

The biggest tradeoff on this topic is between ambition and realism.

| Lens | What you gain | Main risk |
| --- | --- | --- |
| pseudo-polynomial DP | exact algorithm for moderate numeric bounds | forgetting that `U` is not the input length |
| FPT / bounded branching / tiny side-mask | exactness under a small structural parameter | pretending the parameter is small when it really is not |
| small-`n` exact search | exactness when the whole instance is tiny | describing it as a parameterized breakthrough when it is just brute force at small scale |
| meet-in-the-middle | huge reduction in subset-search scale | forcing it onto problems whose combine step is not clean |
| hardness intuition | faster rejection of doomed models | overusing theory language where a core exact algorithm already exists |

Important contest lesson:

- complexity knowledge does not replace algorithm design
- it helps you choose the right *scale* of algorithm design

## Variant Chooser

| Situation | Best first lens | Why it fits | Where it fails |
| --- | --- | --- | --- |
| one numeric capacity / sum / value bound is moderate | pseudo-polynomial DP | the hard search collapses onto a bounded number line | weak if the numeric bound is too large or encoded in huge binary values |
| one side parameter is tiny, like colors, terminals, or picked objects | FPT / tiny-side-parameter exact search | exponential cost is paid only in the side parameter | weak if the “parameter” grows with the full instance |
| the entire instance size is tiny, like `n <= 20` | small-`n` exact search | full-state DP or branching may already fit comfortably | weak if you pretend this scales beyond the tiny-`n` regime |
| brute force is subset-style and `n` is around `35-45` | meet-in-the-middle | `2^{n/2}` is often practical where `2^n` is not | weak if combining halves is as hard as the full problem |
| the problem family is hard in general, but the statement has a special promise | switch to the promise-driven model or a narrower topic | many contest problems are hard only before the promise is used | weak if the promise is cosmetic and does not shrink the state space |
| exact unrestricted optimization still looks too large after every rescue attempt | reformulate or relax | hardness is telling you the model is oversized | weak if you give up before checking for a small parameter or numeric rescue |

## Worked Examples

### Example 1: `Book Shop` Is Exact, But Only Pseudo-Polynomial

Use [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md).

The straightforward `0/1` knapsack DP runs in:

$$
O(nX),
$$

where `X` is the budget.

That is excellent for the contest instance because `X` is moderate.

But it is not polynomial in the encoded input length, because storing `X` only costs about `\log X` bits.

This is the cleanest contest-facing pseudo-polynomial pattern:

- exact algorithm
- excellent under moderate numeric limits
- not a “general polynomial-time solution” to knapsack

The real lesson is not only that the DP works. The real lesson is:

- the number line is the dimension paying for exactness

### Example 2: `VMMARBLE` Works Because The Mask Is Small

Use [VMMARBLE](../../../practice/ladders/dp/bitmask-dp/vmmarble.md).

The raw story talks about moving marble groups between boxes. That sounds like a complicated transportation search.

The right model instead pays exponential only in the number of colors:

- mask = which colors already have at least one keeper
- transitions add one local keeper decision at a time

So the running time behaves like:

$$
O(N \cdot M \cdot 2^M),
$$

which is fine precisely because `M` is small.

This is the FPT-style contest lesson:

- the global story is hard
- the hidden small structural parameter makes exactness realistic

It is also a good place to draw the boundary carefully:

- this is not “small-`n` exact search” in disguise
- the exponential part is attached to the color count, not to the total raw story size

### Example 3: Meet-In-The-Middle Is A Scale Change, Not A Different Problem

Suppose you want a subset-sum-style search on `n = 40` items.

Plain brute force costs:

$$
2^{40},
$$

which is already too large.

Split the items into two halves of size `20` and enumerate both halves:

$$
2^{20} + 2^{20}
$$

plus sorting or hashing.

Nothing about the combinatorial object changed. The only thing that changed was the scale at which you pay the search cost.

This is why meet-in-the-middle belongs on this page:

- it is a complexity compromise before it is a specific template

In this repository, this branch is currently theory-backed rather than repo-backed:

- there is not yet a dedicated internal note focused on meet-in-the-middle itself

For external practice, use:

- CSES, [Meet in the Middle](https://cses.fi/problemset/task/1628)

### Example 4: Strong NP-Hardness Explains Why Numeric DP Usually Will Not Save You

Many contest solvers learn one useful reflex:

- “if there is a budget, maybe I can DP on it”

That reflex is good, but not universal.

When a problem family is strongly NP-hard, the message is roughly:

- the difficulty is not just that one numeric quantity happens to be large
- even when the numeric sizes are kept tame, the combinatorial structure remains hard

Contest translation:

- `Book Shop` is saved because one moderate number line is genuinely carrying the hard part
- if your current model still looks like arbitrary covering / partition / scheduling and your only rescue idea is “DP on the number line,” you should be suspicious

This is the practical reason strong NP-hardness matters here:

- it tells you which rescue route probably will **not** work

## Decision Checklist

Use this before you commit to an exact model.

```text
0. Did I miss an ordinary core family first?
   graph, DP, string, geometry, flow, matching, data structure?

1. Write the raw brute-force object:
   subset? ordering? partition? cover? assignment?

2. Estimate the real search size:
   2^n? n!? Bell-like partitions? pairings?

3. Ask what is actually small:
   n, numeric bound U, side parameter k, or half of n?

4. Choose the rescue route by signal:
   numeric bound -> pseudo-polynomial DP
   small side parameter -> FPT / tiny-side-parameter exact search
   tiny whole instance -> small-n exact search
   subset-like n around 40 -> meet-in-the-middle
   nothing shrinks -> reformulate / relax / exploit promise

5. If none fit, stop optimizing the wrong model.
```

That last line is the real value of this topic.

## Practice Archetypes

- subset or cover optimization where one small parameter changes everything
- knapsack-like problems where `O(nW)` is the intended compromise
- “story problems” that collapse to a tiny mask
- subset-search problems around `n = 40` where meet-in-the-middle becomes the only realistic exact route
  external practice: [CSES Meet in the Middle](https://cses.fi/problemset/task/1628)
- advanced theory/editorial problems whose solution begins by rejecting the unrestricted model
  next stop: [Approximation And Relaxation](../approximation-and-relaxation/README.md) or [Optimization And Duality](../optimization-and-duality/README.md)

## References And Repo Anchors

### Primary / Course

- MIT 6.046J, [Complexity: P, NP, NP-completeness, Reductions](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/resources/lecture-16-complexity-p-np-np-completeness-reductions/)
- Stanford CME 305, [Lecture 14: P vs. NP / NP-hardness](https://web.stanford.edu/class/cme305/Files/l14.pdf)
- MIT 6.854 Notes, [Approximation notes with pseudopolynomial algorithms and strong NP-hardness discussion](https://courses.csail.mit.edu/6.854/20/Notes/n20-approx.html)
- Cornell CS 6810, [A Brief Introduction to Parameterized Complexity](https://www.cs.cornell.edu/courses/cs6810/2023fa/Parameterized.pdf)
- Illinois CS 473, [Fixed Parameter Tractable Algorithms](https://courses.grainger.illinois.edu/CS473/fa2023/lec/notes/07_fpt.pdf)

### Reference

- MIT, [Computational Intractability draft](https://hardness.mit.edu/drafts/2025-01-29.pdf)

### Repo Anchors

- practice ladder: [Complexity And Hardness ladder](../../../practice/ladders/advanced/complexity-and-hardness/README.md)
- pseudo-polynomial anchor: [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md)
- small-parameter exact anchor: [VMMARBLE](../../../practice/ladders/dp/bitmask-dp/vmmarble.md)
- related topic: [Knapsack Family](../../dp/knapsack-family/README.md)
- related topic: [Bitmask DP](../../dp/bitmask-dp/README.md)

## Related Topics

- [Approximation And Relaxation](../approximation-and-relaxation/README.md)
- [Optimization And Duality](../optimization-and-duality/README.md)
- [Algorithm Engineering](../algorithm-engineering/README.md)
