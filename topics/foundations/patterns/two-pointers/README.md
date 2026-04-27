# Two Pointers And Sliding Window

Two pointers is the pattern where you stop recomputing every interval from scratch and instead keep one moving frontier of information that changes predictably.

The essential question is not:

- "can I write two indices?"

It is:

- "does the valid region move monotonically enough that both indices only need to move forward?"

When the answer is yes, a nested scan often collapses to linear time.

When the answer is no, forcing a two-pointer solution usually creates a subtle bug.

## At A Glance

- **Use when:** intervals, pairs, or two sorted streams can be scanned with one-direction pointer movement
- **Core worldview:** maintain one meaningful window or one meaningful pair state while pointers move monotonically
- **Main tools:** fixed-size window, variable-size sliding window, sorted two-end scan, merge-style scan
- **Typical complexity:** `O(n)` pointer movement plus the cost of maintaining the current summary
- **Main trap:** the condition is not monotone, especially for sum-based windows with negative values

## Problem Model And Notation

There are three common models.

### 1. Variable Window On One Array

We maintain a range:

$$
[l, r] \quad \text{or} \quad [l, r)
$$

and a summary of the current window, such as:

- sum
- frequency table
- number of distinct values
- number of violations

### 2. Two Ends On A Sorted Array

We keep:

- `l` at the left end
- `r` at the right end

and move one endpoint based on whether the current pair is:

- too small
- too large
- or acceptable

### 3. Merge-Style Scan On Two Sorted Sequences

We keep one pointer in each sorted stream and advance the smaller side, or advance both when a match is found.

All three variants rely on the same structural property:

- once a pointer move discards something, that thing never needs to come back

## Sliding Window Playground

<div class="visual-card" data-two-pointers-visualizer>
  <p class="visual-caption">
    Replay the standard nonnegative sliding-window loop for `sum <= K`. The important thing to watch is when adding to the
    right makes the window invalid, and why only moving `l` can repair it.
  </p>
  <div class="visual-controls">
    <label>
      Limit K
      <select data-role="limit">
        <option value="5">5</option>
        <option value="6" selected>6</option>
        <option value="7">7</option>
        <option value="8">8</option>
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
          <strong>Current phase</strong>
          <code data-role="phase"></code>
        </div>
        <div class="visual-stat">
          <strong>Current window</strong>
          <code data-role="window"></code>
        </div>
        <div class="visual-stat">
          <strong>Best valid window so far</strong>
          <code data-role="best"></code>
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

- while the window is valid, `r` only moves right and the highlighted interval grows by one candidate at a time
- once the sum exceeds `K`, the algorithm does not reconsider earlier right endpoints at all; it keeps `r` fixed and moves only `l` until the window is valid again

Why it matters:

- this is the shortest route from "I know the loop shape" to "I trust why the window never needs to move backward"
- it also exposes the real proof obligation: not "there are two pointers", but "extending and shrinking affect the summary in one monotone direction"

Code bridge:

- the widget is the classic nonnegative window skeleton: add `a[r]`, then while `sum > K`, subtract `a[l]` and increment `l`
- the recorded best interval is updated only after the repair loop, when `[l, r)` is valid again

Boundary:

- this visual is intentionally for nonnegative values only; if negative values are allowed, extending right may decrease the sum and the monotone-repair story breaks
- sorted two-end scans and merge-style scans live in the same family, but they use a different discard argument than this variable-window demo

## From Brute Force To The Right Idea

### Brute Force: Recompute Every Interval Or Pair

The naive approach for subarray or substring questions is usually:

- fix the left endpoint
- try every right endpoint
- recompute the condition from scratch

That costs:

$$
O(n^2)
$$

or worse.

For sorted-pair problems, the naive version is:

- try every pair

which is again quadratic.

### The First Shift: One Pointer Move Should Kill Many Candidates

Two pointers only pays off when one move lets you discard a whole class of possibilities.

Examples:

- in a sorted pair-sum problem, if `a[l] + a[r]` is too small, then `l` cannot pair successfully with any earlier right endpoint, because none exists and every later right endpoint is at least as large
- in a nonnegative sliding window, if the sum is too large, moving `l` right is the only sensible way to reduce it

### The Second Shift: Maintain A Summary, Not The Whole Interval

The current window is only useful if you can update its summary cheaply:

- add one element
- remove one element

So the real hidden question is:

- can I update the statistic of interest in `O(1)` or `O(log n)` when one boundary moves by one step?

If yes, the window can be maintained.

If no, two pointers may still be the wrong abstraction.

### The Third Shift: Monotonicity Is The Whole Proof

The standard linear proof is:

- `l` only increases
- `r` only increases
- each pointer moves at most `n` times

But that proof is valid only if the condition really supports one-direction movement.

So before you code, you should be able to explain:

- why expanding helps in one direction
- why shrinking repairs the window
- and why no backward move is ever needed

## Core Invariants And Why They Work

### 1. Variable Window With A Monotone Validity Condition

The classic loop is:

```text
for each r:
    add a[r]
    while window is invalid:
        remove a[l]
        l++
    update answer
```

The invariant is:

```text
After the inner while loop, [l, r] is the leftmost valid window ending at r
under the chosen summary and validity rule.
```

This works when:

- adding to the right can only move the window toward invalidity in one predictable direction
- removing from the left can only move it back toward validity

For example, if all values are nonnegative and the condition is:

$$
\text{sum} \le K,
$$

then:

- extending right never decreases the sum
- moving left never increases the sum

So the validity boundary moves monotonically.

### 2. Sorted Two-End Scan

Suppose the array is sorted and you inspect `a[l] + a[r]`.

If the sum is too small, moving `r` left would only make it smaller, so `r` is the wrong pointer to move.

The only hopeful move is:

```text
l++
```

Similarly, if the sum is too large, the only hopeful move is:

```text
r--
```

That is the invariant-level reason pair-scan works:

- one comparison tells you which side can be discarded safely

### 3. Merge-Style Scan

For two sorted sequences `A` and `B`, if `A[i] < B[j]`, then:

- `A[i]` cannot match any earlier `B` entry
- and keeping `i` fixed while advancing `j` cannot help with equality

So it is safe to advance `i`.

This is the same discard logic again, just in a two-stream setting.

### 4. Why Negative Numbers Break The Simple Sum Window

Suppose the condition is:

$$
\text{sum} \le K
$$

but the array can contain negative numbers.

Then:

- extending right may increase the sum
- or decrease it

So the validity boundary is no longer monotone.

The standard shrinking-window proof collapses.

This is the single most important "do not force two pointers" warning in foundations.

## Variant Chooser

### Use A Fixed-Size Window When

- every valid candidate interval has the same length
- you only need to slide by one step each time

Canonical examples:

- window sum / max / distinct count of size `k`

This is the easiest form because:

- both boundaries move together
- there is no validity loop

### Use A Variable-Size Sliding Window When

- the condition is monotone in one direction
- extending right grows the candidate
- shrinking left repairs invalidity

Canonical examples:

- longest subarray with sum at most `K` when all values are nonnegative
- shortest window satisfying a frequency requirement
- longest substring with at most `K` distinct characters

### Use Two Ends On A Sorted Array When

- the problem is about pairs
- sorting makes comparisons monotone

Canonical examples:

- exact pair sum
- closest pair under a target
- greedy tolerance matching

This is the right mental model for:

- [Apartments](../../../../practice/ladders/foundations/two-pointers/apartments.md)
- [Sum of Two Values](../../../../practice/ladders/foundations/two-pointers/sumoftwovalues.md)

### Use Merge-Style Scan When

- both inputs are already sorted
- you compare current representatives of two streams

Canonical examples:

- interval/event merges
- intersection of sorted lists
- advancing the smaller pointer

### Do Not Use Two Pointers When

- validity is not monotone
- the needed statistic cannot be updated cheaply under add/remove
- the true problem is prefix sums + binary search, monotonic queue, or DP

## Worked Examples

### Example 1: `Apartments`

The repo anchor here is:

- [Apartments](../../../../practice/ladders/foundations/two-pointers/apartments.md)

After sorting:

- applicant requests
- apartment sizes

look at the current applicant `a[i]` and apartment `b[j]`.

If:

$$
b[j] < a[i] - k,
$$

then this apartment is too small even under tolerance, so it can never help the current or any later applicant. Move `j`.

If:

$$
b[j] > a[i] + k,
$$

then the apartment is too large for the current applicant, so applicant `i` cannot be matched with this or any later apartment of even larger size. Move `i`.

Otherwise the pair is feasible, so match and move both.

This is a perfect illustration of:

- one comparison
- one safe discard

### Example 2: `Sum of Two Values`

The repo anchor here is:

- [Sum of Two Values](../../../../practice/ladders/foundations/two-pointers/sumoftwovalues.md)

After sorting pairs `(value, original_index)`, keep:

- `l` at the smallest remaining value
- `r` at the largest remaining value

If:

$$
a[l] + a[r] < x,
$$

then `l` is too small to pair with the current `r`, and also too small for every earlier right endpoint because there is none larger than the current `r`.

So it is safe to increment `l`.

That discard argument is the whole proof.

### Example 3: Longest Window With Sum At Most `K`

Assume all numbers are nonnegative.

Maintain:

- current sum of `[l, r]`

For each new `r`:

- add `a[r]`
- while sum exceeds `K`, move `l` right and subtract removed values
- once valid, the current window is a candidate answer

This works because the sum only moves in one direction under each pointer move.

### Example 4: A Counterexample With Negative Numbers

Take:

$$
[5, -10, 5]
$$

and suppose you try to maintain a sum-based sliding window under a monotonicity story.

Adding the next value can:

- increase the sum
- or decrease the sum

So "expand until invalid, shrink until valid" is no longer justified by a one-direction proof.

This is why the phrase:

- "subarray sum"

is not enough by itself to justify two pointers. The sign structure matters.

### Example 5: Merge Two Sorted Arrays

Suppose you want to merge sorted arrays `A` and `B`.

At any moment:

- compare `A[i]` and `B[j]`
- output the smaller one
- advance that pointer

The invariant is:

```text
the output built so far is the sorted merge of A[0..i) and B[0..j)
```

This is still a two-pointer algorithm, just not a window-shaped one.

## Algorithms And Pseudocode

Repo starter template:

- [two-pointers-variable-window.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/two-pointers-variable-window.cpp)

### Variable-Size Sliding Window

```text
l = 0
summary = empty

for r in [0..n-1]:
    add(a[r]) to summary
    while window is invalid:
        remove(a[l]) from summary
        l++
    use current valid window for the answer
```

### Sorted Two-End Scan

```text
l = 0
r = n - 1

while l < r:
    inspect a[l], a[r]
    if pair is too small:
        l++
    else if pair is too large:
        r--
    else:
        process match / answer
```

### Merge-Style Scan

```text
i = 0
j = 0

while i < n and j < m:
    compare A[i], B[j]
    advance one or both pointers according to the invariant
```

## Implementation Notes

### 1. Choose `[l, r]` Or `[l, r)` Once

Do not mix closed and half-open windows in the same solution.

Write down explicitly:

- what the current interval means
- when the answer is updated

Many off-by-one bugs in two pointers are really interval-convention drift.

### 2. Update The Answer At The Right Moment

For longest-valid-window tasks, update after the shrink loop, when the window is valid.

For shortest-valid-window tasks, update while shrinking as long as validity is preserved.

Tiny example:

- suppose you need the shortest subarray with sum at least `K`
- once the current window becomes valid, the interesting action is no longer "expand more"
- it is "record this valid window, then keep shrinking until it would become invalid"

The answer-update point is part of the algorithm, not a cosmetic placement detail.

### 3. Sorting Changes The Problem Model

In pair problems, sorting is not preprocessing fluff.

It creates the monotone order that makes discarding one side correct.

If you remove sorting, the proof usually disappears.

### 4. Distinct-Element Windows Need Careful Frequency Updates

If the window tracks counts, then `add` and `remove` must update:

- the frequency table
- and any derived statistic such as number of distinct values

consistently.

This is where most sliding-window bugs move from "reasoning error" to "bookkeeping error."

### 5. Negative Values Are A Red Flag For Sum Windows

If the window condition depends on the sum and values may be negative, pause immediately.

That often means the intended tool is something else, such as:

- prefix sums
- deque optimization
- binary search on prefix structure

### 6. Every Pointer Should Be Monotone

A real two-pointer proof usually ends with:

- `l` moved at most `n` times
- `r` moved at most `n` times

If your design needs one of them to oscillate backward, it is probably not a true two-pointer solution anymore.

## Practice Archetypes

The most common two-pointers-shaped tasks are:

- **tolerance matching on two sorted arrays**
- **pair sum / pair feasibility after sorting**
- **longest valid window**
- **shortest valid window**
- **distinct/frequency-constrained substring or subarray**
- **merge-style scan of two sorted streams**

Strong contest smells include:

- windows, substrings, subarrays
- pairing after sorting
- both boundaries seem to move only forward
- each discard argument eliminates many future candidates at once

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [Dartmouth CS31: Two Pointer Technique](https://www.cs.dartmouth.edu/~deepc/LecNotes/cs31/lec3-tptr.pdf)
- [MIT CSAIL 6.390 notes: Sliding Window Algorithm](https://people.csail.mit.edu/hasinoff/320/sliding-notes.pdf)

Reference:

- [USACO Guide: Two Pointers](https://usaco.guide/silver/two-pointers)
- [CP-Algorithms](https://cp-algorithms.com/)

Practice:

- [CSES Sorting and Searching](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [Two Pointers ladder](../../../../practice/ladders/foundations/two-pointers/README.md)
- practice note: [Apartments](../../../../practice/ladders/foundations/two-pointers/apartments.md)
- practice note: [Sum of Two Values](../../../../practice/ladders/foundations/two-pointers/sumoftwovalues.md)
- starter template: [two-pointers-variable-window.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/two-pointers-variable-window.cpp)
- notebook refresher: [Foundations Cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- adjacent topic: [Sorting](../sorting/README.md)
- adjacent topic: [Prefix Sums](../prefix-sums/README.md)

## Related Topics

- [Sorting](../sorting/README.md)
- [Prefix Sums](../prefix-sums/README.md)
- [Binary Search](../binary-search/README.md)
- [Difference Arrays](../difference-arrays/README.md)
- [Reasoning And Implementation Discipline](../../reasoning/README.md)
