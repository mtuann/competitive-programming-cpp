# Bounded Compositions

Bounded compositions are what remains after plain stars and bars stops being exact.

The base problem is still:

$$
x_1 + x_2 + \cdots + x_n = S,
$$

but now each variable has extra constraints such as:

- `x_i \ge L_i`
- `x_i \le U_i`
- some slots must be positive
- different classes of slots have different caps

This topic is the bridge between:

- [Counting Basics](../counting-basics/README.md), where lower bounds are removed by a simple shift

and

- [Inclusion-Exclusion](../inclusion-exclusion/README.md), where upper bounds are repaired by alternating-sign corrections

It also connects naturally to small-sum DP when the total `S` is small enough.

## At A Glance

- **Use when:** identical units are distributed into ordered bins, but some bins have upper bounds or forced minimums
- **Core worldview:** reduce lower bounds first, then decide whether upper bounds are best handled by stars-and-bars plus PIE or by direct DP
- **Main tools:** shifting, stars and bars, inclusion-exclusion on violated caps, small-sum DP
- **Typical complexity:** formula/PIE in `O(2^n)` over slot types or constraints; DP often in `O(nS)` or `O(nSK)`
- **Main trap:** applying plain stars and bars after upper bounds already broke the model

## Problem Model And Notation

We count ordered `n`-tuples of integers:

$$
(x_1, x_2, \dots, x_n)
$$

such that:

$$
x_1 + x_2 + \cdots + x_n = S.
$$

The basic variants are:

- nonnegative compositions: `x_i \ge 0`
- positive compositions: `x_i \ge 1`
- bounded compositions: `0 \le x_i \le U`
- mixed bounds: `L_i \le x_i \le U_i`

The key modeling fact is:

- the bins are ordered / distinguishable
- the units are identical

So this is still a stars-and-bars family, but with extra restrictions.

## From Brute Force To The Right Idea

### Brute Force: Enumerate Every Tuple

A naive solution is:

- try every `n`-tuple summing to `S`
- test which ones obey the slot bounds

This is hopeless even for moderate parameters.

But the problem already has a clean algebraic shape:

$$
x_1 + \cdots + x_n = S.
$$

The real question is only:

- what do the lower bounds and upper bounds do to the base stars-and-bars model?

### The First Shift: Remove Lower Bounds First

If:

$$
x_i \ge L_i,
$$

set:

$$
y_i = x_i - L_i \ge 0.
$$

Then:

$$
y_1 + \cdots + y_n = S - \sum_i L_i.
$$

This step is mandatory before anything else.

Lower bounds are usually easy.

### The Second Shift: Upper Bounds Are The Real Difficulty

If after shifting you still have:

$$
0 \le y_i \le U_i',
$$

then plain stars and bars is no longer valid, because it counts solutions that overshoot some cap.

So now you must choose one of two directions:

- if the caps are small or the total `S` is small, use DP
- if the number of constrained slots is small and intersections are easy, use inclusion-exclusion

### The Third Shift: Count Violations Rather Than Valid Objects

The clean PIE viewpoint is:

- count all nonnegative solutions first
- then subtract those where at least one slot exceeds its upper bound

This is exactly the kind of overlap correction PIE is made for.

## Core Invariants And Why They Work

### 1. Shifting Lower Bounds

Suppose:

$$
x_i \ge L_i.
$$

Define:

$$
y_i = x_i - L_i.
$$

Then:

$$
y_i \ge 0
$$

and:

$$
y_1 + \cdots + y_n = S - \sum_i L_i.
$$

This is a bijection:

- every valid `x`-tuple corresponds to exactly one nonnegative `y`-tuple
- and vice versa

So the count is preserved.

This is why lower bounds are considered "easy" in this family.

### 2. Plain Stars And Bars For The Unbounded Version

For nonnegative solutions:

$$
x_1 + \cdots + x_n = S,
\qquad x_i \ge 0,
$$

the count is:

$$
\binom{S+n-1}{n-1}.
$$

For positive solutions:

$$
x_i \ge 1,
$$

the count becomes:

$$
\binom{S-1}{n-1}
$$

after shifting by `1`.

This is the baseline count that upper bounds will later correct.

### 3. Inclusion-Exclusion For Upper Bounds

Suppose after shifting we want:

$$
0 \le y_i \le U
$$

for all `i`.

Let `A_i` be the bad set where:

$$
y_i \ge U+1.
$$

To count valid solutions, we compute:

$$
\#(\text{all nonnegative solutions}) - \left| \bigcup_i A_i \right|.
$$

Now if a subset `T` of variables is forced to violate the cap, then for each `i \in T`, write:

$$
z_i = y_i - (U+1) \ge 0.
$$

This reduces the total sum by:

$$
|T|(U+1).
$$

So one `|T| = t` intersection contributes:

$$
\binom{S - t(U+1) + n - 1}{n - 1}
$$

when the top is nonnegative, and `0` otherwise.

That gives the standard bounded-composition formula:

$$
\sum_{t=0}^{n} (-1)^t \binom{n}{t}
\binom{S - t(U+1) + n - 1}{n - 1}.
$$

This is the cleanest proof that upper-bounded stars and bars is really just stars and bars plus PIE.

### 4. Why Small-Sum DP Is Often Safer

If:

- slot bounds vary by position
- there are several slot classes
- `S` is only around `100` or `1000`

then a direct DP is often clearer than writing one complicated PIE formula.

The basic DP is:

$$
dp[i][s] = \text{number of ways to fill the first } i \text{ slots with total } s.
$$

Transitions:

$$
dp[i+1][s+v] += dp[i][s]
$$

for every allowed value `v` of the next slot.

This is often the right contest choice because:

- the state meaning is explicit
- mixed bounds are easy to encode
- the risk of sign mistakes disappears

## Variant Chooser

### Use Plain Stars And Bars When

- there are no upper bounds
- and after shifting, every slot is simply nonnegative

This is the `[Counting Basics](../counting-basics/README.md)` layer.

### Use Bounded-Composition PIE When

- many slots share the same upper bound
- or the intersection after violating some caps still has a clean closed form
- and the number of bounded slots is small enough to tolerate subset-size or subset iteration logic

Canonical smells:

- "each bin can contain at most `K` items"
- "no run can exceed `K-1`"
- all constrained slots look structurally similar

When every bounded slot has the same cap, the PIE often compresses from "iterate all subsets" into "sum over the number of violated slots `t`".

### Use DP When

- the total sum `S` is small
- bounds differ by slot
- slots come in several structural classes
- the counting model is already decomposed into a manageable number of gaps/groups

This is often the better route in olympiad-style practice problems.

### Use Counting-Then-DP Hybrid When

- first count a skeleton combinatorially
- then count how extra mass is distributed into bounded gaps

This is exactly the shape of [VOSFENCE](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md):

- count the red/blue skeleton
- then count white-gap placements under positivity and cap constraints

### Move To Full Inclusion-Exclusion Or Another Topic When

- upper bounds are irregular and the bad-set intersections are the real structure
- or the overlap logic is now the main difficulty

Then you are really in [Inclusion-Exclusion](../inclusion-exclusion/README.md), not just bounded compositions.

## Worked Examples

### Example 1: Positive To Nonnegative

Count:

$$
x_1 + x_2 + x_3 = 10,
\qquad x_i \ge 1.
$$

Shift:

$$
y_i = x_i - 1 \ge 0.
$$

Then:

$$
y_1 + y_2 + y_3 = 7.
$$

So the answer is:

$$
\binom{7+3-1}{3-1} = \binom{9}{2}.
$$

This is the basic lower-bound shift.

### Example 2: Uniform Upper Bound

Count:

$$
x_1 + x_2 + x_3 = 7,
\qquad 0 \le x_i \le 3.
$$

Start with all nonnegative solutions:

$$
\binom{7+3-1}{2} = \binom{9}{2}.
$$

Now subtract bad solutions where some `x_i \ge 4`.

For one chosen violating variable, shift by `4`, leaving:

$$
\binom{3+3-1}{2} = \binom{5}{2}.
$$

There are `3` choices of violating variable, so subtract:

$$
3\binom{5}{2}.
$$

For two simultaneous violations, the remaining sum would be negative, so those terms vanish.

Final answer:

$$
\binom{9}{2} - 3\binom{5}{2}.
$$

This is the cleanest bounded-stars-and-bars PIE example.

### Example 3: Why DP Can Be Cleaner Than PIE

Suppose there are:

- some forced-positive gaps
- some optional gaps
- and different gaps have different caps

You could still try to force a formula, but the DP:

$$
dp[i][s]
$$

often matches the statement more directly.

That is not a failure of combinatorics. It is good modeling discipline.

### Example 4: VOSFENCE

[VOSFENCE](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md) is a strong example because it splits one messy problem into two layers:

1. count the red/blue skeleton by transition structure
2. count bounded white-gap placements

The bounded-composition layer appears after:

- some gaps are forced positive
- every gap has cap `K-1`
- the total white count is fixed

The final solution uses small DP because the totals are small and the gap classes are explicit.

## Algorithms And Pseudocode

### Shift Lower Bounds

```text
for each slot i:
    S -= lower_bound[i]
if S < 0:
    answer = 0
else:
    continue with nonnegative model
```

### DP For Bounded Compositions

```text
dp[0][0] = 1
for i in 0..n-1:
    for s in 0..S:
        for v in allowed_values_of_slot_i:
            if s + v <= S:
                dp[i+1][s+v] += dp[i][s]
```

With prefix sums, many such transitions can be optimized, but the conceptual baseline is this slot-by-slot DP.

### PIE For Uniform Upper Bounds

```text
answer = 0
for t in 0..n:
    remaining = S - t * (U + 1)
    if remaining < 0:
        break
    term = C(n, t) * C(remaining + n - 1, n - 1)
    if t is even: answer += term
    else:         answer -= term
```

This is the standard bounded-stars-and-bars formula in executable form.

## Implementation Notes

### 1. Lower Bounds First, Always

Do not mix lower-bound handling and upper-bound handling in the same step unless you are very sure of the algebra.

First shift:

- remove the minimums

Then solve the remaining nonnegative problem.

### 2. Plain Stars And Bars Dies The Moment Upper Bounds Matter

Once caps are present, the simple formula is no longer exact.

That is the most common wrong turn in this topic.

### 3. Negative Remaining Sum Means Zero Ways

After shifts or PIE corrections, if the remaining sum becomes negative, that branch contributes `0`.

This sounds trivial, but it is one of the most frequent algebra-to-code mistakes.

### 4. DP Is Not "Less Mathematical"

If the slots fall into several classes and `S` is small, DP is often the cleanest implementation of the composition model.

Using DP here is still doing combinatorics correctly.

### 5. Ordered Bins Are Part Of The Model

These are compositions, not partitions.

So:

- `(2, 1, 0)` and `(1, 2, 0)` are different unless the statement explicitly says otherwise

### 6. Tiny Brute Force Is Great Here Too

For small `n`, `S`, and `U`, brute-force enumeration is a very good sanity check for:

- the lower-bound shift
- the cap interpretation
- DP versus PIE agreement

### 7. Unequal Caps Usually Destroy The Clean Closed Formula

The compact alternating-sum formula is cleanest when every bounded slot behaves the same way.

If caps differ heavily by slot, the uniform `t`-based formula usually disappears, and the better choices are often:

- full subset PIE
- or direct DP

## Practice Archetypes

The most common bounded-composition-shaped tasks are:

- **bounded stars and bars**
- **distribute identical mass into gaps with caps**
- **count after some gaps are forced positive**
- **choose a skeleton first, then fill bounded gaps**
- **small-total counting where DP is the clean bounded-composition engine**

Strong contest smells include:

- an equation like `x_1 + \cdots + x_n = S`
- some `x_i` must be positive
- some `x_i` cannot exceed a cap
- the statement is really about gaps, runs, or separators with bounded sizes

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [Washington CSE 312: Counting, stars and bars, inclusion-exclusion](https://courses.cs.washington.edu/courses/cse312/25wi/lecture/03-inclusion-exclusion.pdf)
- [UCSD compositions and partitions slides](https://mathweb.ucsd.edu/~gptesler/184a/slides/184a_ch5slides_f17-handout.pdf)

Reference:

- [CP-Algorithms: Stars and Bars](https://cp-algorithms.com/combinatorics/stars_and_bars.html)
- [CP-Algorithms: Inclusion-Exclusion Principle](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html)

Practice:

- [VOSFENCE](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md)

Repo anchors:

- ladder: [Bounded Compositions ladder](../../../practice/ladders/combinatorics/bounded-compositions/README.md)
- notebook refresher: [Combinatorics Cheatsheet](../../../notebook/combinatorics-cheatsheet.md)
- adjacent topic: [Counting Basics](../counting-basics/README.md)
- adjacent topic: [Inclusion-Exclusion](../inclusion-exclusion/README.md)

## Related Topics

- [Counting Basics](../counting-basics/README.md)
- [Inclusion-Exclusion](../inclusion-exclusion/README.md)
- [DP Foundations](../../dp/foundations/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
