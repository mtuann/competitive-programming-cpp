# Binary Search

Binary search is not "the algorithm for finding one value in a sorted array."

That is only the smallest special case.

In contest work, binary search is really the technique of:

- choosing an ordered search space
- defining a monotone predicate on that space
- maintaining one invariant that never loses the answer

If those three pieces are clear, the loop becomes routine.

If any one of them is vague, the loop becomes bug-prone very quickly.

## At A Glance

- **Use when:** the answer space is ordered and a predicate changes only once
- **Core worldview:** binary search is invariant management over a monotone boundary
- **Main tools:** `lower_bound`, `upper_bound`, first-true / last-false templates, answer-space search, exponential search for bounds
- **Typical complexity:** `O(\log n)` checks for explicit sorted search, or `O(T \log \text{range})` when one feasibility check costs `T`
- **Main trap:** the predicate is not actually monotone, or the meaning of `l` and `r` drifts during the loop

## Problem Model And Notation

Let the search domain be an ordered set of candidates:

$$
x_0 < x_1 < x_2 < \cdots < x_m.
$$

We usually define a predicate:

$$
\mathrm{good}(x)
$$

with the intended shape:

- false, false, false, ...
- then true, true, true, ...

In other words, there is one transition point.

The classic discrete formulation is:

- `l` is a known bad state
- `r` is a known good state
- the first good answer lies in `(l, r]`

This page uses that formulation as the default because it makes proof and implementation line up cleanly.

## Binary Search Playground

<div class="visual-card" data-binary-search-visualizer>
  <p class="visual-caption">
    The hidden predicate is <code>good(x) = (x &gt;= answer)</code>. Step through the search and watch how the invariant
    keeps the first good answer trapped inside <code>(l, r]</code>.
  </p>
  <div class="visual-controls">
    <label>
      Hidden first good
      <select data-role="target">
        <option value="2">2</option>
        <option value="4">4</option>
        <option value="6" selected>6</option>
        <option value="9">9</option>
        <option value="12">12</option>
      </select>
    </label>
    <button type="button" data-role="step">Step once</button>
    <button type="button" data-role="run">Run to finish</button>
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
          <strong>Current interval</strong>
          <code data-role="interval"></code>
        </div>
        <div class="visual-stat">
          <strong>Decision</strong>
          <code data-role="decision"></code>
        </div>
        <div class="visual-stat">
          <strong>Observed result</strong>
          <code data-role="result"></code>
        </div>
      </div>
      <p class="visual-note" data-role="note"></p>
    </div>
  </div>
</div>

### Visual Reading Guide

What to notice:

- the search never needs to know the whole answer space at once; it only needs one bad endpoint, one good endpoint, and the guarantee that the first good answer remains inside `(l, r]`
- each step throws away half the interval because `good(mid)` tells us which side can no longer contain the first transition

Why it matters:

- this is the shortest route from "I know the loop shape" to "I trust why the loop returns the first good answer"
- it also explains why endpoint meaning matters more than memorizing one `while` condition

Code bridge:

- the widget is the standard first-true template with `l` bad, `r` good, `mid = floor((l + r) / 2)`, then either `r = mid` or `l = mid`
- the final `r` is the answer because the loop stops only when the invariant has collapsed to adjacent sentinels

Boundary:

- this demo isolates the monotone-predicate core only; real problems still need you to design the ordered domain and prove that `good(x)` is actually monotone
- if the predicate is not monotone, or if the domain is really continuous optimization without a boolean boundary, this exact template is not the right hammer

## From Brute Force To The Right Idea

### Brute Force: Check Every Candidate

Suppose the answer is one integer in a huge range, and `good(x)` tells us whether `x` is feasible.

The brute-force solution is:

- test `x = 0`
- then `x = 1`
- then `x = 2`
- continue until the first feasible answer appears

That is correct, but only practical when the range is tiny.

When the range is large, the real question is:

- can we exploit order to skip most candidates?

### The First Shift: Sorted Search Is Really Boundary Search

Even in the textbook "search in sorted array" version, binary search is not about equality first.

It is about locating a boundary:

- first index with `a[i] >= x`
- first index with `a[i] > x`
- last index with `a[i] <= x`

This is why `lower_bound` and `upper_bound` are such good mental models. They expose the boundary view directly.

### The Second Shift: Binary Search On Answer

Many contest problems are not given as "find `x` in a sorted list."

They ask things like:

- minimum time to finish all jobs
- maximum minimum distance
- smallest capacity that allows completion

There is no explicit sorted array of answers.

But there is still an ordered answer space, and still a monotone question:

- "is answer `x` feasible?"

That is enough.

### The Third Shift: The Loop Is Easy Once The Predicate Is Right

Most binary-search bugs are not caused by arithmetic in the loop.

They come from one of these:

- the search space was chosen badly
- the predicate was not monotone
- the endpoints were given inconsistent meanings
- the return value did not match the invariant

So the real work is done before the `while` loop starts.

## Core Invariants And Why They Work

### 1. Ordered Search Space

Binary search needs a space where "left of" and "right of" mean something.

That space might be:

- array indices
- times
- capacities
- distances
- answer values after coordinate compression

If there is no meaningful order, binary search is the wrong tool.

### 2. Monotone Predicate

The central condition is:

$$
x \le y \text{ and } \mathrm{good}(x) \Rightarrow \mathrm{good}(y)
$$

for first-true search.

Or equivalently, the false region and true region each form one contiguous block.

If the predicate looks like:

- false, true, false

or:

- true, false, true

then binary search is not justified.

### 3. Stable Boundary Meaning

The safest contest template is:

```text
l is bad
r is good
the first good answer is in (l, r]
```

Suppose:

- `mid` is good

Then the first good answer cannot lie to the right of `mid`, so the new interval is:

$$
(l, mid].
$$

So set:

```text
r = mid
```

If instead:

- `mid` is bad

then the first good answer cannot lie at or left of `mid`, so the new interval is:

$$
(mid, r].
$$

So set:

```text
l = mid
```

This preserves the invariant exactly.

### 4. Why Termination Gives The Answer

In the integer version, if we loop while:

```text
r - l > 1
```

then each iteration strictly shrinks the number of candidates.

When the loop ends:

$$
r = l + 1.
$$

Since:

- `l` is bad
- `r` is good

there is no room for any other transition point, so `r` must be the first good answer.

### 5. Last-False And Last-True Are The Same Idea

If your invariant is:

- `l` bad
- `r` good

then:

- `r` is the first good
- `l` is the last bad

So "first true" and "last false" are not different algorithms. They are different interpretations of the same invariant.

### 6. Real-Valued Search Changes The Stopping Rule

For reals, you do not stop at adjacent endpoints because reals are dense.

Instead, you stop after:

- enough iterations
- or when the interval width is below a desired precision

The invariant logic is the same; only the termination criterion changes.

## Variant Chooser

### Use `lower_bound` / `upper_bound` When

- the data is already sorted
- you are searching in explicit values or indices
- the desired boundary matches a standard STL contract

Canonical examples:

- first value `>= x`
- first value `> x`
- count of values in an interval via two bounds

This is the cleanest form of binary search and should be your first instinct for sorted containers.

### Use First-True / Last-False Templates When

- you have an integer answer space
- you can write `good(x)`
- you can initialize one bad endpoint and one good endpoint

This is the default contest form for answer search.

### Use Binary Search On Answer When

- the statement asks for minimum / maximum feasible answer
- checking one candidate is easy
- scanning all candidates is too expensive

Canonical smells:

- "minimum time such that..."
- "maximum value for which..."
- "smallest capacity that allows..."

### Use Exponential Search For Bounds When

- the predicate is monotone
- but you do not know a valid upper bound in advance

Then:

- start with a small candidate
- double until it becomes good
- binary-search inside the bracket you just found

### Use Real-Valued Binary Search When

- the answer is continuous
- the predicate or target function behaves monotonically over a real interval
- an `eps` or fixed iteration count is acceptable

This is common in geometry, optimization, and some average-value problems.

### Do Not Use Binary Search When

- the predicate is not monotone
- the domain is tiny enough for direct scan or formula
- there is a direct `O(n)` greedy/DP without the extra `\log`
- you are really solving ternary-search or peak-finding logic instead

## Worked Examples

### Example 1: First Position `>= x`

Suppose `a` is sorted increasingly and we want:

$$
\min \{ i : a[i] \ge x \}.
$$

Define:

$$
\mathrm{good}(i) := a[i] \ge x.
$$

Then `good(i)` is monotone on indices:

- once an index is good, every later index is also good

This is exactly the `lower_bound` pattern.

The cleanest invariant bridge to code is:

- let `l = -1` be a virtual bad index
- let `r = n` be a virtual good boundary candidate

and interpret:

- `r = n` as "no good index exists inside the array"

Then the same first-true template works on array boundaries without any special casing.

### Example 2: `Factory Machines`

The repo anchor here is:

- [Factory Machines](../../../../practice/ladders/foundations/binary-search/factorymachines.md)

Suppose machine `i` makes one product every `k_i` time units, and we want the minimum time `t` to produce at least `m` products.

Define:

$$
\mathrm{good}(t) :=
\sum_i \left\lfloor \frac{t}{k_i} \right\rfloor \ge m.
$$

Why is this monotone?

Because if time `t` is enough, then any larger time is also enough.

This is the classic answer-space pattern:

- search space = time
- predicate = feasibility
- first true = minimum feasible time

### Example 3: One Fully Traced Integer Search

Suppose:

$$
\mathrm{good}(x) := x^2 \ge 30
$$

and we search over integers with invariant:

- `l = 0` is bad
- `r = 30` is good

We want the first good value.

1. `mid = 15`, good because $15^2 \ge 30$, so set `r = 15`
2. `mid = 7`, good, so set `r = 7`
3. `mid = 3`, bad because $3^2 < 30$, so set `l = 3`
4. `mid = 5`, bad, so set `l = 5`
5. `mid = 6`, good, so set `r = 6`

Now:

$$
r - l = 1.
$$

So stop and return:

$$
r = 6.
$$

That is the smallest integer with $x^2 \ge 30$.

### Example 4: A Non-Monotone Predicate That Looks Tempting

Suppose you ask:

- "does there exist a subarray of length exactly `x` whose sum is at least `K`?"

This predicate is **not** automatically monotone in `x`.

It may be:

- true for one length
- false for a larger length

So you cannot binary-search over `x` just because the statement asks about a length.

This is one of the most common binary-search mistakes:

- ordered answer space
- but no monotone feasibility boundary

### Example 5: Binary Search Versus Direct Formula

Sometimes you can binary-search an answer, but a formula already exists.

For example, if the answer is:

- first position where prefix sum reaches a threshold

and the prefix array is monotone, then:

- `lower_bound` on the prefix array is cleaner than writing a custom answer-search loop

Binary search is a technique, not an obligation.

## Algorithms And Pseudocode

Repo starter templates:

- [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp)
- [binary-search-last-false.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-last-false.cpp)

### First True On Integers

```text
assume:
    l is bad
    r is good
    first good answer is in (l, r]

while r - l > 1:
    mid = l + (r - l) / 2
    if good(mid):
        r = mid
    else:
        l = mid

return r
```

### Last False On Integers

With the same invariant:

```text
return l
```

at the end.

### `lower_bound` Mental Model

```text
good(i) = a[i] >= target
return first index i where good(i) is true
```

This is why `lower_bound` is the STL embodiment of binary search as boundary search.

### Real-Valued Search

```text
repeat for enough iterations:
    mid = (l + r) / 2
    if good(mid):
        r = mid
    else:
        l = mid
return one endpoint according to the invariant
```

The invariant logic is the same; only adjacency is replaced by precision control.

## Implementation Notes

### 1. Write The Invariant In Comments First

Before coding the loop, fill these lines:

```text
good(x) =
l means =
r means =
return =
```

If one line feels fuzzy, the loop is not ready.

This is the fastest beginner guardrail in the topic.

### 2. Midpoint Overflow Still Matters

For integer search, prefer:

```cpp
long long mid = l + (r - l) / 2;
```

instead of:

```cpp
(l + r) / 2
```

The safer form preserves meaning even when endpoints are large.

### 3. Infinite Loops Usually Mean Boundary Semantics Drifted

If you use a closed interval like `while (l <= r)` with ad hoc updates, it becomes easy to:

- fail to shrink the interval
- skip the true boundary
- patch the wrong endpoint at the end

That is why the repo defaults to:

- one bad endpoint
- one good endpoint
- loop while `r - l > 1`

### 4. The Predicate Must Be Pure Enough

`good(x)` should behave like a real predicate:

- same input, same result
- no hidden mutation that changes future checks

If every call changes shared state in a complicated way, the binary search may become impossible to reason about.

### 5. Saturate Counts When Only Feasibility Matters

In answer search, the check often computes a large count, for example:

$$
\sum_i \left\lfloor \frac{t}{k_i} \right\rfloor.
$$

If all you need is whether that count reaches a threshold `m`, then:

- cap at `m`
- or stop accumulation once the sum reaches `m`

This prevents overflow and keeps the predicate logic unchanged.

### 6. Search Space And Data Space Are Different

Do not binary-search over indices just because the input is stored in an array.

Ask:

- what is the true candidate answer?

Sometimes it is:

- an array index

but sometimes it is:

- time
- capacity
- distance
- budget

Confusing those two spaces creates very plausible but wrong loops.

### 7. If A Good Upper Bound Is Missing, Derive One By Doubling

When you know:

- some bad starting point
- the predicate is monotone

but no obvious good upper bound exists, do:

```text
r = 1
while not good(r):
    r *= 2
```

Then binary-search inside the bracket you found.

This is often cleaner than inventing a magic constant such as `1e18`.

### 8. Lower Bound And Answer Search Are The Same Pattern

These are not two unrelated topics.

Both are:

- first-true boundary search

The only difference is what the domain is:

- sorted indices
- or an abstract answer space

## Practice Archetypes

The most common binary-search-shaped tasks are:

- **first index satisfying a sorted-array boundary**
- **minimum feasible answer**
- **maximum feasible answer**
- **continuous search to required precision**
- **binary search combined with greedy or prefix-sum check**

Strong contest smells include:

- "minimum value such that..."
- "maximum value for which..."
- a check is easy, but scanning the answer space is impossible
- `lower_bound`-style language such as first `>=`, first `>`, last `<=`

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [Cornell CS2112: Loop Invariants and Searching](https://www.cs.cornell.edu/courses/cs2112/2012fa/lectures/lec20.html)
- [CMU 15-122 Lecture Notes on Binary Search](https://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/15122-s14/www/06-binsearch.pdf)
- [University of Toronto: Notes on Proving Correctness of Binary Search](https://www.cs.toronto.edu/~maclean/csc238/binary-search.pdf)
- [UTK CS302: Using `lower_bound` and `upper_bound`](https://web.eecs.utk.edu/~jplank/plank/classes/cs302/Notes/Upper-Bound/)

Reference:

- [CP-Algorithms: Binary Search](https://cp-algorithms.com/num_methods/binary_search.html)
- [USACO Guide: Binary Search](https://usaco.guide/silver/binary-search)

Essay / blog:

- [TopCoder Tutorial: Binary Search](https://www.topcoder.com/community/competitive-programming/tutorials/binary-search)

Practice:

- [CSES Sorting and Searching](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [Binary Search ladder](../../../../practice/ladders/foundations/binary-search/README.md)
- practice note: [Factory Machines](../../../../practice/ladders/foundations/binary-search/factorymachines.md)
- starter template: [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp)
- starter template: [binary-search-last-false.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-last-false.cpp)
- notebook refresher: [Foundations Cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- adjacent topic: [Reasoning And Implementation Discipline](../../reasoning/README.md)

## Related Topics

- [Sorting](../sorting/README.md)
- [Prefix Sums](../prefix-sums/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Reasoning And Implementation Discipline](../../reasoning/README.md)
