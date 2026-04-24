# Lexicographic Enumeration

Lexicographic enumeration is the topic where you stop generating objects one by one and start skipping whole ordered blocks.

The canonical questions are:

- what is the `k`-th object in lexicographic order?
- how many valid objects start with this prefix?
- can I rank or unrank objects without enumerating all of them?

This topic sits at the intersection of:

- combinatorial counting
- greedy reconstruction
- and sometimes DP over prefixes

The essential move is always the same:

- process candidate next choices in lexicographic order
- count how many full objects lie under each choice
- skip entire blocks until the target falls inside one of them

## At A Glance

- **Use when:** lexicographic order matters, but brute-force generation is too large
- **Core worldview:** a fixed prefix defines one lexicographic block; if you can count that block, you can skip it
- **Main tools:** block sizes, ranking/unranking, factorial-number-system logic, DP counts under prefixes, cap-at-`k` arithmetic
- **Typical complexity:** often output length times branching factor, plus the cost of one prefix-count query
- **Main trap:** confusing "next lexicographic object" generation with direct ranking/unranking

## Problem Model And Notation

Suppose the objects are strings, permutations, or other sequences over an ordered alphabet.

Lexicographic order means:

- compare from left to right
- the first differing position decides the order

For a prefix `P`, define:

$$
\mathrm{count}(P)
=
\text{number of valid full objects whose first } |P| \text{ symbols equal } P.
$$

This is the central function of the topic.

If you know `count(Pc)` for every possible next choice `c` in sorted order, then:

- the whole lexicographic block under prefix `Pc` has size `count(Pc)`
- and you can skip it if your target rank is larger than that block

## From Brute Force To The Right Idea

### Brute Force: Generate Everything In Order

The naive way to answer "what is the `k`-th object?" is:

- generate the 1st object
- then the 2nd
- then the 3rd
- stop at `k`

This is fine only when the object class is tiny.

For permutations, strings, constrained sequences, or ranked combinatorial objects, the full order is usually enormous.

### The First Shift: Lexicographic Order Comes In Blocks

All objects starting with the same first symbol form one contiguous lexicographic block.

Then inside that block:

- all objects starting with the same first two symbols form a smaller contiguous block

and so on.

This is the core structural fact of lexicographic enumeration:

- prefixes partition the order into contiguous intervals

So if you can count a block, you can jump over it without seeing its internal elements.

### The Second Shift: Ranking And Unranking Are Inverse Problems

There are two complementary tasks:

- **ranking:** given an object, find its position
- **unranking:** given a position `k`, find the object

Both are usually solved with the same block logic.

For unrestricted objects like plain permutations or combinations, the block sizes come from closed formulas.

For constrained objects, the block sizes usually come from:

- DP
- automaton states
- prefix-feasibility counting

### The Third Shift: Cap Counts When Only Comparisons Matter

Many contest tasks only need to know whether a block size is:

- less than `k`
- or at least `k`

Then exact huge counts are unnecessary and dangerous.

A common and correct trick is:

- cap every count at `k` or `k+1`

This avoids overflow and keeps the ranking logic intact.

## Core Invariants And Why They Work

### 1. Prefix Blocks Are Contiguous

Fix any prefix `P`.

All objects beginning with `P` appear consecutively in lexicographic order.

Why?

Because:

- every object with prefix `P` agrees on the first `|P|` positions
- any object with a smaller prefix decision appears entirely before the block
- any object with a larger prefix decision appears entirely after the block

This is why a count attached to one prefix can be used as a block size.

### 2. Greedy Unranking By Block Skipping

Suppose we want the `k`-th object.

At one step, try next symbols in increasing order:

- `c_1`
- `c_2`
- `c_3`
- ...

If:

$$
\mathrm{count}(Pc_1) = b_1,
$$

then:

- if `k \le b_1`, the answer lies inside that block
- otherwise skip it and set `k \leftarrow k - b_1`

Then continue to `Pc_2`, and so on.

This greedy procedure is correct because lexicographic blocks are contiguous and disjoint.

### 3. Ranking Is The Same Logic In Reverse

To rank one fixed object:

- walk left to right
- at each position, sum the sizes of all lexicographically smaller valid next-choice blocks
- then move into the block matching the actual next symbol

That cumulative sum is the rank offset created by earlier blocks.

### 4. Unrestricted Permutations Use Factorial Blocks

For permutations of `n` distinct items:

- fix the first element
- the remaining suffix can be any permutation of `n-1` items

So each first-choice block has size:

$$
(n-1)!.
$$

Then inside a chosen block, each second-choice block has size:

$$
(n-2)!,
$$

and so on.

This is the factorial-number-system viewpoint behind `k`-th permutation algorithms.

### 5. Constrained Objects Replace Closed Form By DP Counts

If the object must satisfy constraints, then `count(P)` is no longer a simple factorial or binomial.

But the same lexicographic logic still holds.

You simply compute:

$$
\mathrm{count}(P)
$$

by a DP over the remaining suffix state.

This is why lexicographic enumeration often looks like:

- greedy reconstruction outside
- DP counting inside

## Variant Chooser

### Use Closed-Form Unranking When

- the objects are unrestricted permutations / combinations / multisets
- block sizes come from factorials or binomials

Canonical examples:

- `k`-th permutation
- rank/unrank combinations

### Use Prefix-DP Enumeration When

- the objects obey local constraints
- one prefix defines a manageable suffix-count state

Canonical smells:

- strings accepted by an automaton
- valid parentheses / bounded paths / monotone constraints
- prefix choices are easy, but suffix counts need DP

This is the right mental model when there is no clean closed-form rank formula, but lexicographic blocks are still well-defined by prefixes.

### Use Local `next_permutation` Only When The Window Is Small

Sometimes the whole object space is huge, but the statement only asks about:

- a short lexicographic interval
- or a tiny moving suffix

Then local generation can be enough.

This is the pattern in [VOITSORT](../../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md):

- the full permutation space is enormous
- but only a suffix block of size at most `10!` needs explicit movement

### Use Rank/Unrank Instead Of Generation When

- `k` is large
- the order space is huge
- or generating each previous object would be wasteful

### Cap Counts When

- you only compare against `k`
- or the full count can overflow

This is one of the most useful contest implementation rules in this topic.

## Worked Examples

### Example 1: `k`-th Permutation

For permutations of `1..n`, the objects split into `n` top-level blocks:

- those starting with `1`
- those starting with `2`
- ...
- those starting with `n`

Each block has size:

$$
(n-1)!.
$$

So if we want the `k`-th permutation:

1. find which block contains `k`
2. choose that first symbol
3. recurse on the remaining symbols with the residual rank

This is direct unranking from factorial block sizes.

### Example 2: Binary Strings With A Constraint

Suppose you want the `k`-th binary string of length `n` with no consecutive ones.

At any prefix `P`, there are at most two next choices:

- append `0`
- append `1` if allowed

If you know how many valid completions each choice has, then the reconstruction is:

- try `0` first
- if its suffix count is at least `k`, keep it
- otherwise subtract that block and move to `1`

This is the standard "greedy reconstruction with DP counts" pattern.

### Example 3: Ranking A Combination

To rank a sorted `k`-subset:

- scan positions left to right
- at each position, count how many legal smaller choices could have appeared there
- add all those skipped blocks

This is the combination analogue of permutation ranking.

### Example 4: VOITSORT

[VOITSORT](../../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md) is a strong example because the lexicographic interval is not attacked by a full rank/unrank formula.

Instead:

- identify the hidden one-stack-sortable property
- exploit the fact that the interval length `k` is much smaller than `10!`
- freeze the large prefix
- enumerate only a tiny suffix block

This is still lexicographic enumeration, but in a "block-local" way rather than a full closed-form unranking way.

## Algorithms And Pseudocode

### Greedy Unranking With Block Counts

```text
prefix = empty
for each position:
    iterate legal next choices c in sorted order
    block = count(prefix + c)
    if k > block:
        k -= block
    else:
        choose c
        prefix += c
        break
```

### Ranking By Summing Earlier Blocks

```text
rank = 1   // or 0, depending on convention
prefix = empty
for each position of the target object:
    for each legal smaller next choice c:
        rank += count(prefix + c)
    append the actual next choice to prefix
```

### Count Capping

```text
count = exact_or_dp_value
count = min(count, LIMIT)
```

This is correct whenever only comparisons against `LIMIT` matter.

## Implementation Notes

### 1. Fix The Rank Convention First

Decide whether the target rank is:

- `0`-indexed
- or `1`-indexed

Then keep that convention everywhere.

Many lexicographic bugs are just off-by-one errors in rank convention.

### 2. "Prefix Count" Must Mean Full Completions

When you compute `count(P)`, it must count:

- all valid full objects extending `P`

not:

- only objects of one exact suffix shape
- or only immediate next moves

If this semantic slips, the whole skipping logic breaks.

### 3. Count Capping Is Usually Better Than Huge Integers

If you only need to compare against `k`, then exact giant counts are unnecessary.

Capping makes code:

- safer
- faster
- less overflow-prone

### 4. Lexicographic Order Must Match The Choice Iteration Order

The order you iterate candidate next symbols must be exactly the lexicographic order used by the statement.

If you iterate the wrong local order, the global ranking is wrong even if every count is correct.

### 5. `next_permutation` Is A Local Tool, Not A Universal Ranking Method

It is perfect when:

- the interval is tiny
- or only a short suffix moves

It is the wrong abstraction for:

- direct `k`-th-object queries in huge spaces

### 6. DP State Design Is The Hard Part For Constrained Objects

In constrained lexicographic enumeration, the reconstruction loop is usually easy.

The real work is designing:

- the suffix state
- the transition rules
- the count function attached to each prefix

### 7. Prefix Blocks Must Match The Actual Order Model

Most contest objects are plain strings or permutations, so "all completions of one prefix" really is one contiguous lexicographic block.

But if the implementation re-encodes the state in a non-obvious way, be careful:

- the counted suffix family must still correspond exactly to one contiguous interval of the statement's order

If that semantic link breaks, block skipping is no longer justified.

## Practice Archetypes

The most common lexicographic-enumeration-shaped tasks are:

- **`k`-th permutation / combination**
- **rank/unrank under a clean combinatorial family**
- **greedy reconstruction using DP counts**
- **count and skip lexicographic prefix blocks**
- **tiny lexicographic interval with large frozen prefix**

Strong contest smells include:

- "find the `k`-th"
- "lexicographically smallest / largest valid object"
- "how many valid objects begin with this prefix?"
- brute-force generation is too big, but counting under one prefix seems feasible

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course / notes:

- [Ranking and Unranking of Combinatorial Objects (book excerpt)](https://catalogimages.wiley.com/images/db/pdf/9780470044926.excerpt.pdf)
- [Harvey Mudd ACM: Kth Permutation](https://www.cs.hmc.edu/ACM/Problems/Spring01/kthperm/kthperm.html)

Reference / research:

- [Lexicographic Unranking of Combinations Revisited](https://wkerl.me/papers/algorithms2021.pdf)
- [Combinatorial Number System](https://en.wikipedia.org/wiki/Combinatorial_number_system)

Practice:

- [VOITSORT](../../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md)

Repo anchors:

- ladder: [Lexicographic Enumeration ladder](../../../practice/ladders/combinatorics/lexicographic-enumeration/README.md)
- notebook refresher: [Combinatorics Cheatsheet](../../../notebook/combinatorics-cheatsheet.md)
- adjacent topic: [Counting Basics](../counting-basics/README.md)
- adjacent topic: [Bitmask DP](../../dp/bitmask-dp/README.md)

## Related Topics

- [Counting Basics](../counting-basics/README.md)
- [Bitmask DP](../../dp/bitmask-dp/README.md)
- [Binary Search](../../foundations/patterns/binary-search/README.md)
