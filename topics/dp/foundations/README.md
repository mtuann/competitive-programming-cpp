# DP Foundations

Dynamic programming starts when you can say exactly:

- what part of the instance has already been solved
- what information still matters for the future
- why many different histories can be collapsed into one state

That is why DP is less about memorizing recurrences and more about designing the right state space.

If the state is right, the recurrence usually becomes short.

If the state is vague, even a familiar-looking recurrence is hard to trust.

## At A Glance

- **Use when:** brute force revisits the same subproblems, greedy feels unsafe, and the future depends only on a small summary of the past.
- **Core worldview:** DP is evaluation on an acyclic dependency graph whose vertices are states; shortest/longest-path style relaxations are one important special case.
- **Main tools:** state design, recurrence design, base cases, dependency order, memoization vs tabulation, memory compression.
- **Main trap:** writing a recurrence before you know what one DP entry means.
- **Success after studying this page:** you can define states precisely, justify why the recurrence is complete, choose a safe evaluation order, and estimate `states × transitions` before coding.

## Quick Route

Use this page as the first router inside the DP family.

```text
1. The state is "first i items" plus one resource.
   Start with prefix DP or knapsack-style DP.

2. The state is a range [l, r].
   Go to Interval DP.

3. The state is a subtree or root-to-child interaction.
   Go to Tree DP.

4. The state is a subset or subset + last element.
   Go to Bitmask DP.

5. The state is a decimal prefix under an upper bound.
   Go to Digit DP.

6. I am not sure whether the problem is even DP.
   Use the anti-cues and boundary section here before committing.
```

## Prerequisites

- [Reasoning, Invariants, And Proof Discipline](../../foundations/reasoning/README.md)

Helpful neighboring topics:

- [Knapsack Family](../knapsack-family/README.md)
- [Interval DP](../interval-dp/README.md)
- [Tree DP](../tree-dp/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Digit DP](../digit-dp/README.md)

## Problem Model And Notation

Let the set of states be:

$$
\mathcal{S}.
$$

For each state $s \in \mathcal{S}$, define:

$$
\mathrm{dp}[s] = \text{the answer for subproblem } s.
$$

There are three things to specify before the recurrence is trustworthy:

1. **state meaning**
   - what one state represents
2. **transition set**
   - which smaller states can lead into the current one
3. **evaluation order**
   - why those smaller states are already available when the current state is computed

The cleanest unifying picture is:

- states are vertices
- valid dependencies are directed edges
- edges point from prerequisite states to states that use them

If that dependency graph is acyclic, then:

- top-down DP is DFS + memoization on that DAG
- bottom-up DP is a topological order over that DAG

This is why "DP vs graph shortest path" is often a boundary question, not a completely different idea.

Useful recurring notation:

- `state`: the summary that future transitions are allowed to look at
- `base case`: a smallest state with known answer
- `transition`: one legal way to derive the current state from smaller states
- `answer location`: which final state or aggregation contains the problem answer

## From Brute Force To The Right Idea

### Brute Force: Remember The Whole History

The naive version of many DP problems is:

- recursively try every decision
- carry the full history implicitly
- recompute the same suffix / interval / subset / subtree many times

That usually explodes because many different decision paths arrive at the same future situation.

### The Real Compression

The key observation is:

> if two histories lead to the same future-relevant summary, they should collapse into the same state.

Examples:

- in `0/1` knapsack, after processing the first `i` items, only the remaining capacity matters
- in digit DP, only `(position, previous digit, tight, started)` matters, not the full numeric prefix as a raw integer
- in interval DP, only `[l, r]` matters, not the exact sequence of earlier recursive calls that produced that interval

That compression is the whole reason DP exists.

### The Dependency Graph View

Once the state is fixed, the recurrence becomes:

- one state looks at a small set of earlier states
- combine those earlier answers with one local choice cost
- store the result

If every transition moves to a smaller or earlier state, the dependency graph is acyclic.

Then the only remaining design questions are:

- what counts as a smaller state?
- how many such states exist?
- how expensive is one transition?

### Why Greedy Often Fails Exactly Where DP Starts

DP is often the right next step when:

- one local choice can change the value of many future options
- no exchange argument is obvious
- but the future still depends only on a small summary

That is the classic "greedy feels tempting, but unsafe" signal.

## Core Invariant And Why It Works

This page is really about six core DP obligations.

### 1. One State Must Mean One Precise Subproblem

Good DP states look like:

- `dp[i] = best answer using the first i items`
- `dp[i][j] = number of ways after processing i positions with extra parameter j`
- `dp[l][r] = answer for interval [l, r]`
- `dp[mask][last] = best answer over exactly the set mask, ending at last`

Bad DP states look like:

- "`dp[i]` is something about the first part of the array"
- "`dp[x][y]` stores the current best somehow"

If the state meaning is imprecise, the proof cannot be precise either.

### 2. The State Must Forget Everything That No Longer Matters

DP works only if histories can be merged.

So ask:

- what information affects future legality or value?
- what information is now irrelevant and can be forgotten?

If two histories lead to the same future options and same objective value from now on, they should land in the same state.

This is the key DP invariant:

> every DP state keeps all future-relevant information.

For strong modeling, we also try to remove information that no longer matters, but that second part is an efficiency goal, not the core correctness requirement.

Too little information:

- the recurrence becomes wrong because the future depends on something that was dropped

Too much information:

- the state space blows up and the recurrence becomes harder than necessary

### 3. Every Transition Must Correspond To One Legal Last Step

The most robust way to derive a recurrence is:

1. describe the current state
2. ask what the last decision could have been
3. remove that last decision
4. identify the smaller state left behind

That is why many recurrence proofs read like:

- "consider the last chosen item"
- "consider the first split point"
- "consider the previous digit"
- "consider the child matched to the parent"

If a transition cannot be explained as one legal structural decomposition, it is often suspicious.

### 4. The Recurrence Must Be Complete And Non-Overlapping

For correctness, transitions must satisfy two conditions:

- **completeness:** every valid solution is represented by at least one transition branch
- **non-accidental duplication:** if the problem is counting, the same object should not be counted multiple times unless the state definition intends that

Optimization DP can sometimes tolerate overlapping candidate descriptions because `max` or `min` removes duplicates harmlessly.

Counting DP usually cannot.

That is why counting variants need especially careful transition design.

### 5. The Evaluation Order Must Respect Dependencies

A DP recurrence is only executable when the states it reads are already known.

Typical safe orders:

- increasing prefix length
- increasing interval length
- increasing bitcount of `mask`
- DFS postorder on rooted trees
- memoized DFS over acyclic state graph

This is the DP analogue of a loop invariant:

> whenever a state is evaluated, every dependency it reads is already correct.

### 6. Correctness Proof Usually Mirrors The Recurrence

DP correctness is usually an induction proof over:

- processed prefix length
- interval length
- subtree depth / postorder
- number of chosen elements
- topological order of states

The proof pattern is:

1. prove base cases
2. assume all prerequisite states are correct
3. show the recurrence examines exactly the legal decompositions
4. conclude the stored value is correct for the current state

If the proof feels harder than the code, the state is often still wrong.

## Complexity And Tradeoffs

The first complexity estimate should almost always be:

$$
\text{number of states} \times \text{transitions per state}.
$$

Then refine for preprocessing and constants.

Examples:

- `dp[i]` with `O(1)` transition: `O(n)`
- `dp[i][j]` with `O(1)` transition: `O(nm)`
- interval DP with split point `k`: often `O(n^3)`
- bitmask DP on `2^n` subsets: often `O(n 2^n)` or `O(n^2 2^n)`

Important tradeoffs:

| Choice | Benefit | Main risk |
| --- | --- | --- |
| top-down memoization | closest to the recurrence, easy to derive | recursion depth, hidden constant factors, accidental hash-map overhead |
| bottom-up tabulation | explicit order, predictable memory access | easy to fill in the wrong order |
| full table | simplest to reason about | too much memory |
| compressed memory | smaller memory and often faster | overwriting dependencies if loop direction is wrong |
| exact state | clean proof | might be too large |
| aggressive state compression | faster/smaller | easy to forget future-relevant information |

Boundary with nearby techniques:

- if the dependency graph is truly a DAG and transitions are edge relaxations, sometimes the cleanest view is shortest or longest path in a DAG, not table DP
- if one local choice can be proved safe by exchange or monotonicity, greedy or binary search may be lighter
- if the state graph has cycles and weighted relaxations, it may be more natural to think in graph terms than in DP-table terms

## Variant Chooser

| Situation | Default DP shape | When it fits | Where to go next |
| --- | --- | --- | --- |
| first `i` items / positions | prefix DP | one-directional processing, small carry state | [Knapsack Family](../knapsack-family/README.md) |
| one resource budget | capacity DP | one main budget / weight axis | [Knapsack Family](../knapsack-family/README.md) |
| contiguous subarray or substring | interval DP | state is literally `[l, r]` | [Interval DP](../interval-dp/README.md) |
| rooted tree with local combine rules | tree DP | child subtrees are conditionally independent | [Tree DP](../tree-dp/README.md) |
| subset or subset + endpoint | bitmask DP | `n` is small, subsets are the natural state | [Bitmask DP](../bitmask-dp/README.md) |
| decimal-bound counting / optimization | digit DP | property depends on digits built left-to-right | [Digit DP](../digit-dp/README.md) |
| simple acyclic dependencies between explicit states | DAG DP / shortest-path view | transitions look like relaxations on a DAG | [Shortest Paths](../../graphs/shortest-paths/README.md) |

Anti-cues:

- if one sort + greedy rule has a clean exchange argument, stop before forcing DP
- if the "state" is almost the full history, the compression is not good enough yet
- if transitions need future information that is not in the state, the model is incomplete

## Worked Examples

### Example 1: Tiny Mechanical DP

Suppose:

$$
\mathrm{dp}[i] = \text{maximum sum obtainable from the first } i \text{ items, choosing no adjacent items}.
$$

Then for the `i`-th item:

- either we skip it, giving `dp[i - 1]`
- or we take it, forcing the previous item to be skipped, giving `dp[i - 2] + a[i]`

So:

$$
\mathrm{dp}[i] = \max(\mathrm{dp}[i-1], \mathrm{dp}[i-2] + a[i]).
$$

Why is this a good first DP example?

- the state meaning is exact
- the last-step decomposition is obvious
- the induction proof mirrors the recurrence directly

This is the right level of clarity to demand before moving to bigger DP families.

### Example 2: A Middle-Weight Prefix/Resource DP

Take [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md).

The brute force is:

- for each book, take or skip it
- explore all subsets

That is exponential.

The right compression is:

- how many books have been processed
- how much budget remains or has been used

So a clean state is:

$$
\mathrm{dp}[i][j] = \text{best pages using the first } i \text{ books with budget } j.
$$

Why is this enough?

- once we know which prefix of books is available and what budget remains, the exact earlier subset no longer matters
- future choices only depend on those two summaries

This is a good checkpoint because it is richer than 1D prefix DP, but still much more ordinary than digit or subset DP.

### Example 3: Contest-Style State Design

Take [Counting Numbers](../../../practice/ladders/dp/digit-dp/countingnumbers.md).

Brute force would inspect every number in `[L, R]`, which is impossible when the range is huge.

The right compression is:

- current digit position
- previous real digit
- whether the number has already started
- whether the current prefix is still tight to the bound

So the state is something like:

$$
\mathrm{dp}[pos][prev][started][tight].
$$

Why is this enough?

- the future only cares about the next position, the previous chosen digit, and whether the bound is still active
- the full numeric prefix itself is no longer needed

That is the essence of DP state design:

> keep only the information that changes future legality or value.

### Example 4: DP As A Dependency DAG

Take [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md).

One state is:

$$
\mathrm{dp}[i][j] = \text{best value after processing the first } i \text{ books with budget } j.
$$

Each state depends only on states from the previous item layer:

- skip book `i`
- take book `i` if budget allows

So the dependency graph points from layer `i-1` to layer `i`. That graph is acyclic by construction.

Bottom-up tabulation is then just evaluation in layer order.

### Example 5: When DP Is The Wrong Hammer

Suppose a problem asks for the minimum number of edges from one source in an unweighted graph.

You could write a recurrence over paths, but that is the wrong abstraction.

The cleaner model is:

- graph vertices are states
- BFS gives the shortest path directly

This example matters because many learners overfit to tables and miss that some "DP-looking" tasks are more naturally graph problems.

## Algorithm And Pseudocode

For DP, the most reusable pseudocode is a design checklist.

```text
DesignDP(problem):
    choose a candidate state
    write one sentence for dp[state]
    list all legal predecessor or smaller states
    write the recurrence from those states
    prove:
        base cases are correct
        transitions are complete
        no future-relevant information was forgotten
    count states and transitions
    choose evaluation style:
        top-down memoization
        or bottom-up order respecting dependencies
    identify where the final answer lives
```

A tabulation skeleton looks like:

```text
Initialize all base states
For states in dependency-safe order:
    combine all legal predecessor states
Return the designated answer state or aggregation
```

The order is problem-specific, but the design contract is not.

## Implementation Notes

- Write the state meaning in a comment before you write the recurrence.
- Decide early whether the state table stores:
  - maximum value
  - minimum cost
  - feasibility
  - count of ways
- In counting DP, be much stricter about double-counting than in optimization DP.
- Start with the uncompressed version when possible; compress memory only after the dependency order is trusted.
- Top-down is often easier for derivation; bottom-up is often easier for iteration-order control.
- If the state graph is sparse and acyclic but awkward as a dense table, memoized DFS may be clearer.
- Useful repo templates:
  - [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp)
  - [interval-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/interval-dp.cpp)
  - [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)
  - [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)
  - [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp)
- If your DP keeps failing on hidden tests, reopen:
  - [DP Cheatsheet](../../../notebook/dp-cheatsheet.md)
  - [Reasoning, Invariants, And Proof Discipline](../../foundations/reasoning/README.md)
  - [Build Kit](../../../docs/build-kit.md)

## Practice Archetypes

- **Warm-up**
  - [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md)
    Why: clean 0/1 prefix-resource DP with one unmistakable loop-order invariant.
  - [VMSCALE](../../../practice/ladders/dp/foundations/vmscale.md)
    Why: shows that the real challenge can be state design, not recurrence memorization.
- **Core**
  - [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)
    Why: interval state and induction on segment length.
  - [Tree Matching](../../../practice/ladders/dp/tree-dp/treematching.md)
    Why: rooted-subtree states and child independence.
  - [Counting Numbers](../../../practice/ladders/dp/digit-dp/countingnumbers.md)
    Why: digit-state compression where the full history is impossible but a tiny summary is enough.
- **Stretch**
  - [Path Queries II](../../../practice/ladders/graphs/hld/pathqueries2.md)
    Why: useful reminder that some problems that look like table DP actually belong to a different state-decomposition framework.
  - [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)
    Why: good anti-example showing that repeated subproblems alone do not automatically make DP the cleanest model.

## References And Repo Anchors

- **Course**
  - [Stanford CS161: Guide to Dynamic Programming](https://web.stanford.edu/class/archive/cs/cs161/cs161.1138/handouts/140%20Guide%20to%20Dynamic%20Programming.pdf)
  - [CMU 15-210: Dynamic Programming notes](https://www.cs.cmu.edu/afs/cs/academic/class/15210-s15/www/lectures/dp-notes.pdf)
  - [Stanford EE365: Dynamic Programming Proof](https://web.stanford.edu/class/ee365/lectures/dpproof.pdf)
- **Reference**
  - [CP-Algorithms: Introduction to Dynamic Programming](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)
  - [USACO Guide: Introduction to DP](https://usaco.guide/gold/intro-dp?lang=cpp)
- **Practice**
  - [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
  - [CSES Problem Set](https://cses.fi/problemset/)
- **Repo anchors**
  - [DP Foundations Ladder](../../../practice/ladders/dp/foundations/README.md)
  - [DP Cheatsheet](../../../notebook/dp-cheatsheet.md)
  - [Knapsack Family](../knapsack-family/README.md)
  - [Interval DP](../interval-dp/README.md)
  - [Tree DP](../tree-dp/README.md)
  - [Bitmask DP](../bitmask-dp/README.md)
  - [Digit DP](../digit-dp/README.md)

## Related Topics

- [Reasoning, Invariants, And Proof Discipline](../../foundations/reasoning/README.md)
- [Knapsack Family](../knapsack-family/README.md)
- [Interval DP](../interval-dp/README.md)
- [Tree DP](../tree-dp/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Digit DP](../digit-dp/README.md)
- [Shortest Paths](../../graphs/shortest-paths/README.md)
