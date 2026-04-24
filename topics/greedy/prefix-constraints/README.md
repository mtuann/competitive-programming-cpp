# Prefix Constraints

Prefix-constraint greedy problems are not "pick the locally best item" problems.

They are:

- order the objects so feasibility becomes easy to express
- maintain a statement about every prefix
- repair the chosen set only when the current prefix would otherwise break

That is why these problems often look confusing at first:

- the final object you want is global
- but the proof is about all prefixes

The right way to think about them is:

- every decision spends some prefix capacity
- the greedy algorithm must keep the chosen partial answer as cheap or as permissive as possible

## At A Glance

- **Use when:** every prefix of the constructed order/set must satisfy a feasibility rule
- **Core worldview:** sort or reveal items in a proof-friendly order, then maintain the cheapest or most permissive feasible prefix
- **Main tools:** sorting by threshold, prefix-capacity reasoning, heap-based repair, difference reasoning on known prefix data
- **Typical complexity:** commonly `O(n \log n)` after sorting
- **Main trap:** checking only the final chosen set instead of every prefix, or using the wrong ordering so the prefix invariant is no longer monotone

## Prerequisites

- [Sorting](../../foundations/patterns/sorting/README.md)
- [Reasoning](../../foundations/reasoning/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

Helpful neighboring topics:

- [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md)
- [Offline Tricks](../../data-structures/offline-tricks/README.md)

## Problem Model And Notation

The usual shape is:

- process items in some order
- maintain a chosen set or a hidden sequence
- for every prefix of processed items, some inequality must hold

Typical prefix rule:

$$
\mathrm{chosenCount}(1..p) \le C(p),
$$

or:

$$
\mathrm{prefixFeature}(1..p) \text{ must remain monotone / feasible}.
$$

The exact object varies by problem:

- a set of chosen items
- a line of cows
- a hidden sorted sequence implied by prefix sums
- a pairing role assignment after sorting

But the common structure is always:

- every prefix has to be legal

## From Brute Force To The Right Idea

### Brute Force: Search Over All Global Choices

The raw statement often looks like:

- choose a subset
- choose an order
- choose which side of each pair an item belongs to

That sounds combinatorial.

### The First Shift: Make Prefix Feasibility Visible

After the correct sorting or rewriting, the real condition is usually not global at all.

It becomes:

- after processing the first `p` items, have we used too much capacity?
- do the forced tail values remain nondecreasing?
- does the line size still satisfy the next item's tolerance?

Now the problem has become a prefix-invariant problem instead of a search-over-all-orders problem.

### The Second Shift: Greedy Works Only If Feasibility Is Nested

These problems usually work because prefix constraints are laminar or nested:

- every later prefix contains every earlier prefix

So if a prefix is over capacity, the repair you make now matters forever.

That is exactly why heap-based "remove the worst chosen item" repairs can be globally safe.

### The Third Shift: Some Problems Are Hidden Greedy Checks, Not Constructions

Sometimes you do not even build the final object explicitly.

For example, in [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md), the task is only to decide whether a sorted sequence *could* exist.

The whole solution is:

- decode forced tail values from prefix differences
- check monotonicity
- verify the first block has enough capacity

That is still a prefix-constraint problem because the hidden sequence must be feasible at every prefix.

## Core Invariants And Why They Work

## 1. Prefix Feasibility Must Be Explicit

The first invariant should be written as an inequality or monotonicity statement.

Examples:

- number of chosen Vinh positions in the first `p` sorted coins is at most `\lfloor p/2 \rfloor`
- current line size is at most each accepted cow's tolerance
- consecutive recovered tail values are nondecreasing

If you cannot state the prefix condition explicitly, the greedy proof is not ready yet.

## 2. Sorting Must Make The Prefix Rule Monotone

The chosen order is part of the algorithm.

For [Lemonade Line](../../../practice/ladders/greedy/prefix-constraints/lemonadeline.md), descending tolerance is the right order because:

- once larger tolerances are placed first, the current line length is the only relevant state

For [VODIVIDE](../../../practice/ladders/greedy/prefix-constraints/vodivide.md), sorting by `a[i]` reveals the laminar prefix capacities.

So the real invariant is:

```text
The sorted order is the order in which the prefix condition becomes checkable.
```

## 3. Why "Remove The Worst Chosen Item" Can Be Safe

Suppose the current prefix is allowed to contain at most `C` chosen items, but after tentatively adding one more item you now have `C + 1`.

You must delete one chosen item from this prefix.

If the objective is to minimize total cost, the best repair is:

- remove the chosen item with largest cost

Why?

Because every future feasible solution must also satisfy the current prefix cap. Keeping a more expensive chosen item spends exactly the same prefix capacity while making the objective worse.

This is the standard heap-repair exchange argument.

## 4. Difference Reasoning Can Turn Prefix Data Into Actual Values

In [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md), known suffix prefix sums determine actual tail values by differences.

If those tail values are not nondecreasing, no sorted hidden array can exist.

This is a good reminder that some prefix-constraint problems are solved not by choosing items, but by proving a hidden monotone sequence can or cannot exist.

## Variant Chooser

### Use Sort + Threshold Scan When

- each item accepts the current prefix size only if a threshold is large enough

Canonical example:

- [Lemonade Line](../../../practice/ladders/greedy/prefix-constraints/lemonadeline.md)

### Use Sort + Heap Repair When

- every prefix has a capacity
- you want the minimum or maximum total value among chosen items
- if the prefix is too large, deleting one worst chosen item repairs feasibility

Canonical example:

- [VODIVIDE](../../../practice/ladders/greedy/prefix-constraints/vodivide.md)

### Use Prefix-Difference Feasibility When

- the statement gives prefix sums or cumulative information
- the hidden sequence must be sorted or monotone

Canonical example:

- [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md)

### Do Not Use This Family When

- feasibility is not nested by prefixes
- the real state depends on arbitrary subsets rather than prefixes
- local repair does not preserve global feasibility

Then the problem may actually be:

- DP
- flow / matching
- or a more general optimization problem

## Worked Examples

### Example 1: Lemonade Line

This is the cleanest beginner anchor:

- [Lemonade Line](../../../practice/ladders/greedy/prefix-constraints/lemonadeline.md)

Sort tolerances in descending order.

Let `cnt` be the current line size.

Accept the next cow iff:

$$
w_i \ge cnt.
$$

Why is descending order safe?

Because a more tolerant cow is never harmed by standing earlier, while placing a less tolerant cow too early only increases the future prefix size seen by stricter cows.

### Example 2: Prefix Sum Addicts

This is the strongest "hidden sequence feasibility" anchor:

- [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md)

Take differences of the known suffix of prefix sums.

Those differences are forced tail values of the sorted array, so they must already be nondecreasing.

Then check whether the unknown first block can fit under the smallest forced tail value.

If:

- the first unknown block has length `len`
- its total required sum is `s[first]`
- the next forced tail value is `x`

then every element in that first block must be at most `x`, so the decisive inequality is:

$$
s[\text{first}] \le len \cdot x.
$$

If that fails, no sorted hidden sequence can exist.

This is greedy reasoning over prefix data, even though no explicit subset is chosen.

### Example 3: VODIVIDE

This is the heap-repair anchor:

- [VODIVIDE](../../../practice/ladders/greedy/prefix-constraints/vodivide.md)

After sorting by `a[i]`, the problem becomes:

- choose exactly `n/2` positions for one side
- in every prefix of length `p`, choose at most `\lfloor p/2 \rfloor`
- minimize total chosen `b[i]`

The greedy scan:

- tentatively include each item
- if the current prefix is over capacity, remove the chosen item with largest `b`

works because prefix capacities are nested.

Tiny trace:

- suppose the current prefix cap is `2`
- the chosen costs after tentative inclusion are `{4, 7, 10}`
- then the prefix is over capacity by exactly one item

The only legal repair is to remove one chosen item from this prefix.

Removing `10` is always at least as good as removing `7` or `4`, because every later solution must still respect this same prefix cap while using exactly two kept items here.

## Algorithms And Pseudocode

### Threshold-Scan Skeleton

```text
sort items by the proof-friendly key
state = 0

for item in sorted order:
    if item can accept current state:
        take item
        update state
```

### Heap-Repair Skeleton

```text
sort items
heap = empty

for each item in sorted order:
    tentatively choose item
    push its cost into heap

    if current prefix violates the capacity:
        remove the worst chosen item from heap
```

### Hidden-Sequence Feasibility Skeleton

```text
recover forced tail values from prefix differences
check tail monotonicity
check whether the unknown first block can fit under the first forced tail value
```

## Implementation Notes

- The sorting order is usually the hardest part of the proof, not an implementation detail.
- When using heap repair, decide clearly whether the heap stores:
  - chosen item costs
  - indices
  - or both
- For hidden sorted-sequence problems, use `long long` for prefix differences and capacity checks.
- Prefix-constraint problems are proof-heavy. Write the prefix invariant in plain words before coding.

## Practice Archetypes

You should strongly suspect this family when you see:

- "every prefix must satisfy..."
- "at most this many among the first `p` items"
- "sort first, then maintain feasibility"
- "if infeasible, remove one bad chosen item and continue"

Repo anchors:

- [Lemonade Line](../../../practice/ladders/greedy/prefix-constraints/lemonadeline.md)
- [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md)
- [VODIVIDE](../../../practice/ladders/greedy/prefix-constraints/vodivide.md)

Starter bridge:

- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

Notebook refresher:

- [Foundations cheatsheet](../../../notebook/foundations-cheatsheet.md)

## References And Repo Anchors

Course / greedy-proof style:

- [Princeton: Greedy Algorithms I](https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/04GreedyAlgorithmsI.pdf)
- [OI Wiki: Greedy](https://en.oi-wiki.org/basic/greedy/)
- [USACO Guide](https://usaco.guide/)

Practice / repo anchors:

- [Prefix Constraints ladder](../../../practice/ladders/greedy/prefix-constraints/README.md)
- [Lemonade Line](../../../practice/ladders/greedy/prefix-constraints/lemonadeline.md)
- [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md)
- [VODIVIDE](../../../practice/ladders/greedy/prefix-constraints/vodivide.md)

## Related Topics

- [Sorting](../../foundations/patterns/sorting/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md)
- [Offline Tricks](../../data-structures/offline-tricks/README.md)
