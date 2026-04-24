# Sorting

Sorting is not just preprocessing.

In many contest problems, sorting is the move that creates the structure the proof needs:

- adjacency becomes meaningful
- greedy choices become comparable
- one-pass scanning becomes possible
- duplicates become grouped
- event order becomes canonical

That is why so many solutions secretly look like:

1. sort
2. maintain one small invariant
3. scan once

## At A Glance

- **Use when:** relative order matters more than original positions, or a greedy/sweep proof needs a canonical order
- **Core worldview:** sorting creates monotonicity and local structure
- **Main tools:** `sort`, custom comparators, tie rules, adjacency reasoning, earliest-finish greedy, opposite-end scans
- **Typical complexity:** `O(n \log n)` preprocessing plus linear or near-linear postprocessing
- **Main trap:** believing that sorting alone proves a greedy algorithm, or writing an inconsistent comparator

## Prerequisites

- [C++ Language For Contests](../../cpp-language/README.md)
- [Reasoning](../../reasoning/README.md)

Helpful neighboring topics:

- [Binary Search](../binary-search/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Sweep Line](../../../geometry/sweep-line/README.md)

## Problem Model And Notation

Suppose the input objects are:

$$
x_1, x_2, \dots, x_n.
$$

Sorting chooses an order according to one or more keys:

$$
\mathrm{key}_1(x), \mathrm{key}_2(x), \dots
$$

The most common uses are:

- sort by value
- sort by coordinate
- sort by finishing time
- sort by one key, then tie-break by another

The key question is always:

- what property becomes simple after the order is fixed?

## From Brute Force To The Right Idea

### Brute Force: Treat All Arrangements As Different

Many beginner problems look combinatorial only because the order is still arbitrary.

Examples:

- pairing children into gondolas
- selecting the most compatible intervals
- finding the closest pair on a line

Without order, it feels like:

- try many subsets
- try many pairings
- try many possible next choices

### The First Shift: Sort To Make One Choice Obviously Hardest Or Safest

After sorting, one element often becomes the natural anchor:

- the earliest finishing interval
- the heaviest remaining child
- the smallest or largest remaining value

That anchor is what makes the proof go through.

### The Second Shift: Nearby Elements Become The Only Interesting Ones

On a line, many global comparisons collapse after sorting.

For example, the minimum absolute difference among all pairs must occur between adjacent elements in sorted order.

So sorting can reduce:

$$
O(n^2)
$$

all-pairs reasoning to one linear scan.

### The Third Shift: Sorting And Scanning Is Often The Real Algorithm

The solution is often not:

- "use greedy"

It is:

- choose the correct order
- then greedy becomes forced

That distinction matters because the ordering is usually half of the proof.

## Core Invariants And Why They Work

## 1. Comparator Meaning Must Match The Proof

If you sort by finishing time, the proof must use finishing time.

If you sort by weight, the proof must use weight.

This sounds obvious, but many wrong solutions come from:

- sorting by one key
- proving correctness as if another key had been used

So the first invariant is conceptual:

```text
The chosen order must be the order the proof actually reasons about.
```

## 2. Exchange Argument Is The Main Greedy Proof

The standard sorting proof pattern is:

1. take any optimal solution
2. look at the first place where it differs from the sorted-order greedy choice
3. swap in the greedy-compatible choice
4. show the solution remains feasible and no worse

Repeat until the optimal solution agrees with the greedy one.

This is the proof behind interval scheduling and many other sort-first greedy problems.

## 3. Adjacency Reduction

Suppose:

$$
a_0 \le a_1 \le \cdots \le a_{n-1}.
$$

If you want the minimum difference pair, it is enough to check adjacent pairs:

$$
a_{i+1} - a_i.
$$

Why?

If the best pair were `(a_i, a_j)` with `i + 1 < j`, then some value lies between them, which yields an equal or smaller difference to one side.

Sorting turns a global search into a local scan.

## 4. Opposite-End Reasoning

After sorting, the two ends may represent:

- the most constrained remaining item
- the least costly possible partner

This is exactly why [Ferris Wheel](../../../../practice/ladders/foundations/sorting/ferriswheel.md) works:

- the heaviest remaining child is hardest to place
- pairing them with the lightest remaining child is the best remaining chance

## 5. Event Order Invariant

For sweep-like problems, sorting creates a forward timeline:

```text
After processing all events up to position x,
the maintained state reflects exactly those events.
```

This is the bridge from basic sorting to offline tricks and sweep line.

## Variant Chooser

### Use Sort + Greedy When

- one local choice should be made in a canonical order
- an exchange argument naturally fits

Canonical examples:

- earliest finishing interval first
- smallest/largest feasible item first
- pair the most constrained element first

### Use Sort + Adjacency Scan When

- the best candidate after sorting must be near a boundary or an adjacent element

Canonical examples:

- minimum difference
- duplicate detection
- coordinate compression preparation

### Use Sort + Two Pointers When

- feasibility depends on the two ends or on a monotone scan

Canonical examples:

- pair sums
- minimizing containers under a two-item limit
- merging two sorted lists

### Use Sort + Binary Search When

- the data becomes searchable after sorting
- many predecessor/successor or count queries follow

### Use `nth_element` Or Selection Instead When

- you only need one order statistic, not a full sorted order

That is a useful boundary: do not over-sort if only the median or `k`-th item matters.

## Worked Examples

### Example 1: Movie Festival

This is the repo's cleanest interval-scheduling anchor:

- [Movie Festival](../../../../practice/ladders/foundations/sorting/moviefestival.md)

Sort intervals by increasing finishing time.

Greedily pick the first interval compatible with the last chosen one.

Why is this safe?

Because among all currently compatible choices, the earliest finishing one leaves the most room for the future. Any optimal solution that starts with a later-finishing compatible interval can exchange it with the earlier-finishing one without reducing the number of intervals later.

### Example 2: Ferris Wheel

This is the repo's first `sort + opposite-end pairing` anchor:

- [Ferris Wheel](../../../../practice/ladders/foundations/sorting/ferriswheel.md)

Sort the weights. Let:

- `i` be the lightest remaining child
- `j` be the heaviest remaining child

If `a[i] + a[j]` fits, pair them.

If not, then `a[j]` cannot pair with anyone, because every other remaining child is at least as heavy as `a[i]`.

That is a sorting proof, not merely a two-pointer trick.

### Example 3: Minimum Difference

Sort the array.

Then check only adjacent pairs.

This is the standard example of sorting revealing locality: after ordering, global closeness becomes local closeness.

### Example 4: Event Sorting

Suppose intervals, jobs, or points are processed by coordinate or time.

Sorting gives one forward order where you can maintain a small active state instead of comparing every pair.

This is the base pattern behind:

- sweep line
- offline query sweeps
- many greedy scheduling problems

## Algorithms And Pseudocode

### Generic Sort With Tie Rule

```text
sort items by:
    primary key
    then explicit secondary key
```

### Interval Scheduling Skeleton

```text
sort intervals by increasing end time
last_end = -INF
answer = 0

for interval in sorted order:
    if interval.start >= last_end:
        take interval
        last_end = interval.end
        answer += 1
```

### Opposite-End Pairing Skeleton

```text
sort array
i = 0
j = n - 1
answer = 0

while i <= j:
    if i < j and a[i] + a[j] fits:
        i += 1
    j -= 1
    answer += 1
```

## Implementation Notes

- Your comparator must define a strict weak ordering. If `cmp(a, b)` and `cmp(b, a)` can both be true, the sort is invalid.
- If ties matter for proof or deterministic behavior, state them explicitly.
- `stable_sort` is only needed when equal-key original order must be preserved. Most contest problems do not need it.
- Sorting often destroys original indices, so store them when the output needs original positions.
- Use `long long` if comparisons or sums after sorting may overflow `int`.

## Practice Archetypes

You should strongly suspect sorting when you see:

- only relative order matters
- a greedy proof starts with "among all feasible choices, choose the earliest/smallest/largest..."
- nearby values become meaningful after ordering
- a scan becomes monotone only after sorting

Repo anchors:

- [Movie Festival](../../../../practice/ladders/foundations/sorting/moviefestival.md)
- [Ferris Wheel](../../../../practice/ladders/foundations/sorting/ferriswheel.md)

Starter template:

- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

Notebook refresher:

- [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)

## References And Repo Anchors

Course / proof style:

- [Princeton: Greedy Algorithms I](https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/04GreedyAlgorithmsI.pdf)
- [Virginia Tech: Interval Scheduling](https://courses.cs.vt.edu/cs5114/spring2013/lectures/lecture04-greedy-scheduling.pdf)
- [University of Washington: Greedy Algorithms / Interval Scheduling](https://courses.cs.washington.edu/courses/cse421/18au/lecture/lecture-7.pdf)

Reference:

- [cppreference: sort](https://en.cppreference.com/w/cpp/algorithm/sort)

Practice / repo anchors:

- [Sorting ladder](../../../../practice/ladders/foundations/sorting/README.md)
- [Movie Festival](../../../../practice/ladders/foundations/sorting/moviefestival.md)
- [Ferris Wheel](../../../../practice/ladders/foundations/sorting/ferriswheel.md)

## Related Topics

- [Binary Search](../binary-search/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Graph Modeling](../../../graphs/graph-modeling/README.md)
- [Sweep Line](../../../geometry/sweep-line/README.md)
