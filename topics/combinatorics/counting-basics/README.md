# Counting Basics

Counting basics is the layer where you learn to turn a story problem into one clean combinatorial object and count it exactly once.

This topic is not about memorizing many formulas. It is about stabilizing four questions:

- what is the object being counted?
- are the choices independent or split into disjoint cases?
- does order matter?
- are repeated objects or repeated slot occupancies allowed?

If you answer those correctly, most "easy combinatorics" problems collapse into a short formula or a short case split.

## At A Glance

- **Use when:** the statement asks "how many?" and the core difficulty is modeling, not state transitions
- **Core worldview:** count a well-defined object by a bijection or a disjoint decomposition
- **Main tools:** sum rule, product rule, binomial coefficients, permutations, stars and bars, complementary counting
- **Typical complexity:** often `O(1)` after the right formula, or `O(n)` if one simple loop/case split remains
- **Main trap:** counting the right-looking formula for the wrong object

## Problem Model And Notation

The basic operations of counting are:

- **sum rule:** add counts of disjoint cases
- **product rule:** multiply counts of independent choices

Standard notation:

$$
\binom{n}{k}
$$

counts ways to choose `k` positions/items from `n` when order does not matter.

$$
P(n, k) = n (n-1) \cdots (n-k+1)
$$

counts ordered selections without repetition.

The core modeling questions are:

1. are the objects distinguishable?
2. are the slots distinguishable?
3. does order matter?
4. are repetitions allowed?

Most beginner counting mistakes are really mistakes about one of those four.

## From Brute Force To The Right Idea

### Brute Force: Enumerate All Candidates

A naive approach to many counting problems is:

- generate all strings
- generate all distributions
- generate all subsets / permutations
- filter the valid ones

This is usually exponential.

But counting problems often have strong hidden structure:

- choose positions first
- split by first special event
- distribute identical items into ordered bins
- subtract bad objects from all objects

The real work is to find the right representation of the counted object.

### The First Shift: Count Constructions, Not Outcomes Written In Words

Suppose the problem says:

- "binary strings with exactly `k` ones"
- "distribute `m` apples among `n` children"
- "arrangements with exactly `r` runs"

The statement is verbal. The solution should not stay verbal.

You need to replace it by a construction such as:

- choose the `k` positions of the ones
- place `n-1` separators among `m+n-1` slots
- choose run lengths, then choose the initial color

Once the construction is precise, the formula often becomes obvious.

### The Second Shift: Sum Versus Product Is A Structural Decision

This is the most important fork in basic combinatorics.

Use the sum rule when:

- you partition the answer set into disjoint structural cases

Use the product rule when:

- every valid object is produced by one sequence of independent choices

If you multiply overlapping cases, or add non-disjoint cases, the whole solution breaks.

### The Third Shift: "Choose Positions" Is Often The Right Abstraction

Many contest counting problems are secretly:

- choose which positions carry a special symbol
- or choose where separators go

That is why binomial coefficients appear so often.

For example:

- choose `k` positions among `n`
- choose `n-1` bars among `m+n-1` total slots
- choose where color changes happen among internal edges

These are different stories, but the same combinatorial move.

## Core Invariants And Why They Work

### 1. Product Rule

If a combinatorial object is built in two stages, and:

- every stage-1 choice can be combined with every stage-2 choice
- and each final object corresponds to exactly one pair of choices

then:

$$
\#(\text{objects}) = \#(\text{stage 1 choices}) \cdot \#(\text{stage 2 choices}).
$$

This is why counting often begins by breaking a construction into:

- choose positions
- then assign labels

or:

- choose run lengths
- then choose colors

The proof is simply that the Cartesian product of the two choice sets is in bijection with the answer set.

### 2. Sum Rule

If the answer set is partitioned into disjoint cases:

$$
A_1, A_2, \dots, A_t,
$$

then:

$$
\#A = \sum_{i=1}^{t} \#A_i.
$$

The crucial word is **disjoint**.

So when you split by:

- first special position
- number of runs
- leftmost chosen position
- whether a boundary condition occurs

you must check that no object belongs to two cases at once.

### 3. Binomial Coefficients Count Unordered Position Choices

The coefficient

$$
\binom{n}{k}
$$

counts the number of `k`-element subsets of an `n`-element set.

In contest language, it usually appears when you are really doing:

- choose which `k` positions are occupied by a special type

For binary strings of length `n` with exactly `k` ones:

- choose the `k` positions of the ones
- the zeros are then forced

So the answer is:

$$
\binom{n}{k}.
$$

This is the canonical "choose positions, the rest is determined" pattern.

### 4. Stars And Bars

To count nonnegative integer solutions of

$$
x_1 + x_2 + \cdots + x_n = m,
\qquad x_i \ge 0,
$$

represent:

- each unit as a star
- separators between bins as bars

With `m` stars and `n-1` bars, we arrange:

$$
m + n - 1
$$

symbols in total, and choose which `n-1` positions hold bars.

So:

$$
\#\{(x_1,\dots,x_n)\mid x_i \ge 0,\; \sum x_i = m\}
= \binom{m+n-1}{n-1}.
$$

If instead every variable must be positive:

$$
x_i \ge 1,
$$

write:

$$
y_i = x_i - 1 \ge 0.
$$

Then:

$$
y_1 + \cdots + y_n = m - n,
$$

so the count becomes:

$$
\binom{m-1}{n-1}.
$$

The formula is not the point. The shift is the point.

### 5. Complementary Counting

Sometimes counting the desired set directly is awkward, but counting all objects is easy.

Then:

$$
\#(\text{good}) = \#(\text{all}) - \#(\text{bad}).
$$

This only helps if:

- the "all" set is simple
- the bad set is easier to count
- or the bad structure is what decomposes naturally

This is often the bridge into [Inclusion-Exclusion](../inclusion-exclusion/README.md), but many basic problems stop before that heavier machinery is needed.

## Variant Chooser

### Use Direct Binomial / "Choose Positions" Counting When

- some positions are marked special
- once those positions are chosen, the rest is forced
- order among the chosen positions does not matter

Canonical smells:

- binary strings with exactly `k` ones
- choose breakpoints, pivots, separators, or change positions

### Use Permutation / Ordered Selection When

- order itself is part of the object
- or you are filling slots one by one with distinct labels

### Use Stars And Bars When

- identical units are distributed into ordered bins
- the counted object is a solution to:

$$
x_1 + \cdots + x_n = m
$$

with lower-bound constraints like `x_i \ge 0` or `x_i \ge 1`

If the bins themselves are not distinguishable, this model changes completely. Plain stars and bars is an ordered-bin argument.

### Use Run / Transition Counting When

- the object is naturally described by contiguous blocks
- the right model is "choose where the changes happen" or "choose run lengths"

### Use Complementary Counting When

- the good set is ugly
- the total set is simple
- the bad set has one clean structural description

### Move To Bounded Compositions Or Inclusion-Exclusion When

- upper bounds per slot appear
- the basic stars-and-bars count overcounts forbidden configurations

That is the boundary where [Bounded Compositions](../bounded-compositions/README.md) or [Inclusion-Exclusion](../inclusion-exclusion/README.md) becomes the right next topic.

## Worked Examples

### Example 1: Binary Strings With Exactly `k` Ones

Object:

- a length-`n` binary string with exactly `k` ones

Construction:

- choose the `k` positions of the ones

Once those positions are chosen, the zeros are forced.

So:

$$
\# = \binom{n}{k}.
$$

This is the simplest "choose positions" pattern in the whole topic.

### Example 2: Distributing Apples

Object:

- nonnegative solutions to

$$
x_1 + x_2 + \cdots + x_n = m
$$

where `x_i` is how many apples child `i` gets

Construction:

- `m` stars
- `n-1` bars

So the answer is:

$$
\binom{m+n-1}{n-1}.
$$

This is exactly what [Distributing Apples](../../../practice/ladders/combinatorics/counting-basics/distributingapples.md) teaches.

### Example 3: Positive Compositions

Suppose:

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
y_1 + y_2 + y_3 = 7,
$$

so the count is:

$$
\binom{7+3-1}{3-1} = \binom{9}{2}.
$$

The lesson is not the number. The lesson is that lower bounds are often removed by shifting first.

### Example 4: Count By Number Of Runs

Suppose you count colorings of a strip by:

- first choosing how many runs exist
- then choosing the run lengths
- then choosing the initial color

This is a standard structure because:

- run count and run lengths often create a cleaner decomposition than coloring cells directly

That is the bridge toward problems like [VOSFENCE](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md).

## Algorithms And Pseudocode

Counting-basics problems often need no algorithm heavier than one modeling pass.

The generic checklist is:

```text
1. define the exact object
2. decide whether order matters
3. decide whether objects and slots are distinguishable
4. find one construction that counts each valid object exactly once
5. identify whether the construction uses:
   - product rule
   - sum rule
   - choose positions
   - stars and bars
   - complement
6. only then write the formula
```

If the final answer is needed modulo a prime, the implementation layer often reduces to one binomial query using:

- [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)

## Implementation Notes

### 1. "Order Matters" Must Be Answered Before Everything Else

This is the first branch to settle.

If you get this wrong, the whole count is off even if every later step is technically correct.

### 2. Distinguishable Objects Versus Distinguishable Slots

These are different choices.

For stars and bars:

- stars are identical
- bins are ordered / distinguishable

If either of those changes, the model changes.

### 3. Lower Bounds Often Mean "Shift First"

When you see:

$$
x_i \ge L_i,
$$

the first reflex should be:

$$
y_i = x_i - L_i.
$$

Many basic distribution problems become standard only after this shift.

### 4. Upper Bounds Break Plain Stars And Bars

If the problem says:

$$
x_i \le K,
$$

then plain stars and bars usually overcounts.

This is the signal to move to:

- bounded compositions
- inclusion-exclusion
- or small DP

### 5. Tiny Brute Force Is A Great Sanity Check

For counting problems, brute-forcing tiny cases is extremely valuable.

Before trusting a derived formula, test:

- very small `n`
- edge cases like `0`, `1`, empty or forced choices
- the first few outputs you can enumerate by hand

### 6. Separate Modeling From Mod Arithmetic

Many contest tasks ask for the count modulo `1e9+7`, but the modular part is often routine.

If the combinatorial model is wrong, perfect modular code will still fail.

If the final answer is a binomial coefficient modulo a prime, also check that the precompute strategy matches the numeric range. For very large `n`, the modeling may still be basic while the modular-computation layer stops being basic.

## Practice Archetypes

The most common counting-basics-shaped tasks are:

- **choose positions, rest is forced**
- **distribute identical items into ordered bins**
- **split by a small number of disjoint structural cases**
- **count by runs, changes, or separators**
- **count all, then subtract a simpler bad family**

Strong contest smells include:

- the statement asks "how many?" but heavy DP feels unnatural
- you can describe the object in slots, runs, bars, or chosen positions
- the modeling step is harder than the implementation
- tiny brute force seems able to validate the formula

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [MIT Mathematics for Computer Science: Sum and Product Counting Rules](https://openlearninglibrary.mit.edu/assets/courseware/v1/3516ad6170983ee96d9127c98bff33b9/asset-v1%3AOCW%2B6.042J%2B2T2019%2Btype%40asset%2Bblock/MIT6_042JS16_SumProduct.pdf)
- [MIT Mathematics for Computer Science notes](https://dspace.mit.edu/bitstream/handle/1721.1/104426/6-042j-spring-2010/contents/readings/MIT6_042JS10_notes.pdf)
- [Stanford CS109: Counting and Combinatorics](https://web.stanford.edu/class/cs109/lecture-notes/)

Course / notes:

- [Stanford combinatorial theory notes with stars and bars](https://web.stanford.edu/class/archive/cs/cs109/cs109.1218/files/student_drive/1.2.pdf)

Reference:

- [CP-Algorithms: Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)
- [USACO Guide: Intro to Combinatorics](https://usaco.guide/gold/combo)

Practice:

- [Distributing Apples](../../../practice/ladders/combinatorics/counting-basics/distributingapples.md)
- [VOSFENCE](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md)

Repo anchors:

- ladder: [Counting Basics ladder](../../../practice/ladders/combinatorics/counting-basics/README.md)
- notebook refresher: [Combinatorics Cheatsheet](../../../notebook/combinatorics-cheatsheet.md)
- starter template for binomial queries: [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)

## Related Topics

- [Bounded Compositions](../bounded-compositions/README.md)
- [Inclusion-Exclusion](../inclusion-exclusion/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
