# Heaps And Ordered Sets

This topic is about choosing the smallest dynamic ordered structure that matches the operations in the statement.

In contest code, these structures often solve problems that feel "dynamic" without needing a segment tree:

- `priority_queue`
- `set`
- `multiset`
- sometimes PBDS / order-statistics trees, but only when rank or `k`-th queries are truly required

The key skill is not syntax. It is recognizing the operation set:

- do you only need the current best element?
- do you need predecessor / successor?
- do duplicates matter?
- do deletions happen only at the top, or at arbitrary values?

## At A Glance

- **Use when:** a changing active set matters, but the operation set is still lightweight
- **Core worldview:** choose the container from the operations, not from the story
- **Main tools:** heap for "best current candidate", `set` / `multiset` for sorted active values
- **Typical complexity:** `O(log n)` updates, `O(1)` or `O(log n)` access depending on the container
- **Main trap:** using a heap when you really need predecessor / erase-one, or using an ordered set when only the top matters

## Problem Model And Notation

Think of the statement as defining an active multiset `S` that changes over time.

Typical operations are:

- `insert(x)`
- `erase(x)` or `erase one copy of x`
- `best()` where "best" means min or max
- `pred(x)` = largest active value `< x` or `<= x`
- `succ(x)` = smallest active value `> x` or `>= x`

The right container depends on which subset you need.

### Heap Model

A heap is the right model when the only value you care about is the current extremum under one priority order.

You should mentally read it as:

- "I keep throwing candidates in"
- "I repeatedly need the best current one"
- "I do **not** need arbitrary predecessor/successor queries"

### Ordered-Set Model

An ordered set or multiset is the right model when the active values need to stay globally sorted.

You should mentally read it as:

- "I need the current ordered active set"
- "I care about neighbors in sorted order"
- "I may need to erase a specific value or exactly one copy of it"

## From Brute Force To The Right Idea

### Brute Force: Recompute The Active Order Every Time

A common beginner solution is:

- keep everything in a `vector`
- sort whenever you need min/max/predecessor
- linearly scan to find what to erase

This is often:

$$
O(n \log n)
$$

or

$$
O(n)
$$

per operation, which becomes too slow as the active set changes many times.

### The First Shift: The Statement Is Really About Operations

Many problems do not care about the full array or the full list of active objects.

They only care about one of these:

- the best active candidate
- the predecessor of a query value
- the median of the active window
- one active ordered neighborhood

Once you identify that, a lightweight dynamic structure often replaces repeated re-sorting.

### The Second Shift: Distinguish "Top Only" From "Sorted Active Set"

This is the central conceptual split.

If you only need the best active element, use a heap.

If you need:

- predecessor
- successor
- exact erase of one duplicate
- ordered active-window maintenance

then you have left heap territory and entered ordered-set territory.

### The Third Shift: Lazy Deletion Is Sometimes The Right Heap Deletion

Competitive-programming heaps do not support arbitrary erase well.

So if stale values naturally appear, the pattern is often:

- push everything normally
- mark deletions separately
- keep popping while the top is stale

That is not a workaround to be embarrassed about. It is often the cleanest correct model.

## Core Invariants And Why They Work

### 1. Heap Invariant

For a min-heap:

- every node's key is at most its children's keys

For a max-heap:

- every node's key is at least its children's keys

This is enough to guarantee:

- the root is the global minimum or maximum

That is why heaps support:

- `top()` in `O(1)`
- `push()` / `pop()` in `O(log n)`

But the invariant says nothing about arbitrary relative order among non-root elements. So heaps do **not** support predecessor/successor logic naturally.

### 2. Ordered-Set Invariant

A `set` / `multiset` stores the active elements in sorted order under one strict weak ordering.

That is why:

- `begin()` gives the smallest active element
- `prev(end())` gives the largest active element
- `lower_bound` and `upper_bound` locate predecessors/successors in logarithmic time

The structure is strictly richer than a heap:

- it exposes the whole order, not just the best element

### 3. `set` Versus `multiset`

This is not a performance distinction. It is a state-model distinction.

Use `set` when duplicates should collapse.

Use `multiset` when duplicates are part of the state.

If the active data can contain:

- multiple equal ticket prices
- repeated window values
- repeated interval endpoints

then using `set` changes the problem.

### 4. Lazy Deletion Invariant

For lazy deletion with two heaps:

- one heap stores all inserted candidates
- one heap stores values scheduled for deletion

The normalization rule is:

- while both tops are equal, pop both

After normalization, the visible top of the main heap is the true best active candidate.

This works because the only value you ever expose is the top.

## Variant Chooser

### Use `priority_queue` When

- you only need the current minimum or maximum
- deletions happen naturally by repeated `pop`
- or stale values can be cleaned lazily

Canonical smells:

- repeatedly take the best currently available item
- schedule tasks by earliest finish / largest reward / smallest cost
- Dijkstra-style frontier

### Use `set` When

- active values must stay distinct
- you need predecessor / successor
- you erase specific active values by iterator or exact key

### Use `multiset` When

- the ordered active set can contain duplicates
- you need erase-one semantics
- you need predecessor or sliding-window order maintenance

Canonical smells:

- "largest ticket not exceeding budget"
- dynamic median
- active sweep values with duplicates

### Use Two Heaps Or Two Multisets When

- you split the active set into lower half and upper half
- you maintain a median or a balanced partition

The important invariant is usually:

- lower half size differs from upper half by at most `1`
- and every lower-half value is `<=` every upper-half value

### Use PBDS / Order-Statistics Trees Only When

- you genuinely need rank or `k`-th online

If the task only needs:

- min/max
- predecessor/successor
- erase one copy

then plain `set` / `multiset` is usually simpler and safer.

If rank or `k`-th is the real invariant, continue with:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)

If you are reaching for a hand-coded textbook balanced BST on purpose, reopen:

- [Balanced BSTs For Contests](../balanced-bsts/README.md)

If meld is the real invariant, continue with:

- [Pairing Heap / Leftist Heap](../pairing-leftist-heap/README.md)

## Worked Examples

### Example 1: Heap Scheduling

Suppose tasks appear over time, and whenever you are allowed to choose one, you only need:

- the currently best reward

Then the operation set is:

- insert newly available tasks
- pop the best one

There is no need to know the second-best task until the best is removed.

This is exactly heap territory.

### Example 2: Concert Tickets

For each buyer with budget `x`, you need:

- the largest remaining ticket price `<= x`
- erase exactly one copy of that price

That is not a heap problem. The operation set is:

- predecessor under `<=`
- erase one occurrence

So the right model is a `multiset`, not a `priority_queue`.

This is exactly what [Concert Tickets](../../../practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md) teaches.

### Example 3: Sliding Median

For each window, you need:

- insert one value
- erase one outgoing value
- read the lower median

A single heap fails because:

- outgoing values are not necessarily on top
- the answer is not just global min/max

Two multisets work cleanly because they maintain:

- one lower half
- one upper half
- balanced sizes
- direct erase of one exact outgoing value

### Example 4: Lazy Deletion

Suppose you want a min-heap, but deletions arrive by value and are relatively rare.

Instead of forcing arbitrary erase into the heap, keep:

- `in_heap`
- `deleted`

Whenever the visible top is scheduled for deletion, cancel both copies.

This preserves the "top only" contract while keeping heap code simple.

## Algorithms And Pseudocode

### Heap

```text
for each event:
    push newly active candidates
    while top is stale:
        pop
    answer uses top only
```

### Predecessor In Multiset

```text
it = ms.upper_bound(x)
if it == ms.begin():
    no predecessor <= x
else:
    --it
    *it is the largest value <= x
```

### Strict Predecessor

```text
it = ms.lower_bound(x)
if it == ms.begin():
    no predecessor < x
else:
    --it
```

### Sliding Median With Two Multisets

```text
maintain lo and hi
invariant:
    |lo| = |hi| or |lo| = |hi| + 1
    every element in lo <= every element in hi

median = largest element in lo
```

## Implementation Notes

### 1. `priority_queue` Is Not An Ordered Set

This sounds basic, but it is the most common modeling mistake.

A heap gives you:

- one extremum

It does **not** give you:

- predecessor
- successor
- ordered iteration
- clean erase by value

### 2. Erase One Copy, Not All Copies

With `multiset`, this matters:

```cpp
auto it = ms.find(x);
if (it != ms.end()) ms.erase(it);
```

This erases one occurrence.

By contrast:

```cpp
ms.erase(x);
```

erases all occurrences of `x`.

### 3. `lower_bound` And `upper_bound` Encode Policy

You should be explicit about whether you need:

- `< x`
- `<= x`
- `>= x`
- `> x`

These are not cosmetic changes. They are the boundary policy of the ordered-set query.

### 4. `priority_queue` Comparator Syntax Is Easy To Misread

In C++, the default `priority_queue<T>` is a max-heap.

For a min-heap, the usual contest form is:

```cpp
priority_queue<T, vector<T>, greater<T>> pq;
```

The important mental model is:

- `Compare` describes the weak ordering
- but `top()` returns the element that comes last under that ordering

This is why the template syntax often feels backwards at first sight.

### 5. Lazy Deletion Works Only If Top Is The Only Observable Value

If the problem needs full active-order reasoning, lazy deletion in a heap is not enough.

It is appropriate when:

- all queries go through the current extremum

It is not a substitute for a real ordered set.

### 6. Median Structures Need Size And Order Invariants

For two-heaps or two-multisets median maintenance, the algorithm is not "just rebalance somehow".

The exact invariant is:

- all lower-half values are `<=` all upper-half values
- sizes differ by at most `1`
- the chosen side stores the conventionally defined median

### 7. Comparator Meaning Must Stay Stable

For ordered sets, the comparator must define one stable strict weak ordering.

If the intended order changes with time or with sweep position, then:

- a plain `set` comparator may be invalid for that problem

That boundary is where topics like [Sweep Line](../../geometry/sweep-line/README.md) become more delicate.

## Practice Archetypes

The most common problems in this family are:

- **take the current best item repeatedly**
- **find predecessor / successor in a dynamic active set**
- **erase one duplicate while keeping global order**
- **maintain sliding median or balanced halves**
- **do active-set maintenance without needing a segment tree**

Strong contest smells include:

- "most expensive remaining item not exceeding x"
- "smallest available time / largest reward / best next candidate"
- "window median"
- "keep active values sorted while updates arrive"

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / reference:

- [cppreference: `std::priority_queue`](https://en.cppreference.com/w/cpp/container/priority_queue)
- [cppreference: `std::set`](https://en.cppreference.com/w/cpp/container/set)
- [cppreference: `std::multiset`](https://en.cppreference.com/w/cpp/container/multiset)

Course / notes:

- [Stanford CS106B: Binary Heaps](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1206/lectures/heaps/)
- [Cornell CS312: Priority Queues, Heaps, Huffman Coding](https://www.cs.cornell.edu/courses/cs312/2002sp/lectures/lec19.asp)
- [MIT 6.006: Balanced Binary Search Trees](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/83cdd705cd418d10d9769b741e34a2b8_MIT6_006F11_lec06.pdf)

Reference / practice:

- [USACO Guide: More Operations on Sorted Sets](https://usaco.guide/gold/intro-sorted-sets)
- [USACO Guide: Sliding Median](https://usaco.guide/problems/cses-1076-sliding-median/solution)

Practice:

- [Concert Tickets](../../../practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md)

Repo anchors:

- starter template: [heap-lazy-delete.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/heap-lazy-delete.cpp)
- starter template: [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp)
- starter template: [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- ladder: [Heaps And Ordered Sets ladder](../../../practice/ladders/data-structures/heaps-and-ordered-sets/README.md)
- notebook refresher: [Data structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)

## Related Topics

- [Sorting](../../foundations/patterns/sorting/README.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Pairing Heap / Leftist Heap](../pairing-leftist-heap/README.md)
- [Offline Tricks](../offline-tricks/README.md)
- [Sweep Line](../../geometry/sweep-line/README.md)
