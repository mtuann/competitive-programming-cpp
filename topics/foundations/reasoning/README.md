# Reasoning, Invariants, And Proof Discipline

This page is the bridge between:

- knowing a technique
- and being able to say why your implementation is correct

In contest work, many wrong answers are not really "algorithm gaps". They are reasoning gaps:

- a variable no longer means what you think it means
- a loop invariant was never stated
- the stop condition does not imply the claimed answer
- the asymptotic cost was hand-waved instead of estimated

If this page becomes a habit instead of a one-time read, a large fraction of hidden-test failures become easier to prevent.

Inside this repo, this page is also the theory companion behind the more practice-facing
[Complexity And Invariants Ladder](../../../practice/ladders/foundations/complexity-and-invariants/README.md).

## At A Glance

- **Use when:** your code passes samples but breaks on hidden tests, or you can repeat an editorial idea without being able to justify the actual implementation.
- **Core worldview:** every serious solution should be explainable as `state meaning + invariant + progress + stop condition + complexity`.
- **Main tools:** loop invariants, induction on processed work, exchange arguments, monotonicity, counterexample search.
- **Main trap:** coding transitions before the state meaning and boundary convention are fixed.
- **Success after studying this page:** you can explain what each important variable means, why each update preserves correctness, why the process terminates in the right state, and why the complexity bound is believable.

## Quick Route

Use this page as a router for proof style.

```text
1. My algorithm is a loop that grows, shrinks, or sweeps.
   Use loop invariants.

2. My algorithm builds answers for larger states from smaller ones.
   Use induction on processed work or problem size.

3. My algorithm makes one local greedy choice.
   Use an exchange argument or a stays-ahead argument.

4. My algorithm binary-searches an answer.
   Use monotonicity plus a boundary invariant.

5. My implementation fails on hidden tests and I do not know where to start.
   Use boundary audit + counterexample search before editing code.
```

## Prerequisites

- [C++ Language For Contests](../cpp-language/README.md)

Helpful neighboring topics:

- [Binary Search](../patterns/binary-search/README.md)
- [Prefix Sums](../patterns/prefix-sums/README.md)
- [Two Pointers](../patterns/two-pointers/README.md)
- [Sorting](../patterns/sorting/README.md)

## Problem Model And Notation

This page uses one compact correctness vocabulary.

- $Q$: precondition
- $P$: invariant or maintained claim
- $B$: loop guard or "continue working" condition
- $R$: postcondition
- $V$: progress measure or variant proving termination

For a loop, the reusable proof shape is:

1. initialization makes $P$ true
2. the body preserves $P$ whenever $P$ and $B$ both hold
3. when the loop stops, $P \land \lnot B$ implies $R$
4. a well-founded progress measure $V$ strictly decreases, or a bounded counter strictly advances toward its limit, so the loop cannot continue forever

That separates two different jobs:

- **partial correctness:** if the algorithm stops, the answer is correct
- **termination:** the algorithm really does stop

Contest code often proves the first informally and forgets the second, or vice versa.

One tiny translation helps keep the symbols grounded.

For first-true binary search:

- $Q$: there exists at least one bad value and one good value in the searched interval
- $P$: `l` is bad, `r` is good, and the first good answer lies in `(l, r]`
- $B$: `r - l > 1`
- $R$: `r` is the first good answer
- $V$: `r - l`

For recursive or DP-style algorithms, the analogous vocabulary is:

- state definition
- recurrence / transition
- base cases
- induction hypothesis
- claimed complexity

The details change, but the discipline does not.

## From "The Idea Seems Right" To The Right Discipline

### The Common Naive Workflow

The fragile workflow is:

1. notice a familiar topic
2. write the template quickly
3. hope the boundaries line up
4. test only the sample
5. start editing random lines when hidden tests fail

That workflow is fast on very easy problems, but unstable everywhere else.

### The Better Compression

The stable workflow is:

1. define what each important variable means
2. state what stays true after every iteration or transition
3. state why the process stops in the right state
4. estimate time and memory before coding
5. attack the model with tiny counterexamples before trusting the sample

The key shift is:

> correctness is not something you check after the code exists; it is a structure you design into the code.

### Why This Matters In CP

Competitive programming problems usually compress quickly into a few proof shapes:

- prefix / sweep invariant
- interval invariant
- induction on index, mask, or subtree
- exchange argument after sorting
- monotone predicate for binary search

Once you recognize the proof shape, implementation becomes much less random.

## Core Invariant And Why It Works

This page is really about seven reusable reasoning moves.

### 1. State Meaning Comes Before Updates

Before proving an update is correct, you must know what the state means *right now*.

Good examples:

- `pref[i]` means the sum of the first `i` elements
- `dp[mask][last]` means the best value over exactly the cities in `mask`, ending at `last`
- `l` is a known bad answer and `r` is a known good answer
- window `[l, r)` currently satisfies the maintained predicate

Bad examples:

- "`cur` stores something useful"
- "`ans` is the current answer somehow"
- "`l` and `r` are the binary search endpoints" without saying what they certify

If the state meaning is vague, every later proof step becomes vague too.

### 2. Loop Invariants: The Fastest Contest-Proof Tool

For a loop, the right question is not "why does this line seem reasonable?"

It is:

> what statement is true every time control returns to the loop guard?

Cornell's "four loopy questions" are a very practical contest checklist:

1. does initialization establish the invariant?
2. does the loop body preserve it?
3. does the body make progress toward termination?
4. when the loop exits, does invariant + exit condition imply the goal?

That is almost the whole proof.

#### Tiny Example: Prefix Sums

Let

$$
\mathrm{pref}[i] = a_1 + a_2 + \cdots + a_i.
$$

In the one-pass build loop, a natural invariant is:

> after processing index `i`, `pref[i]` equals the sum of the first `i` values.

Initialization:

- before processing anything, the empty prefix sum is `0`

Preservation:

- if `pref[i - 1]` is the sum of the first `i - 1` values, then after
  `pref[i] = pref[i - 1] + a[i]`,
  `pref[i]` is the sum of the first `i` values

Exit:

- once all indices are processed, every prefix entry has the intended meaning

The code is simple, but the invariant is what makes the code *non-magical*.

### 3. Induction On Processed Work

Induction is the native proof style for:

- DP
- recursive tree algorithms
- divide and conquer
- scans where each step extends a solved prefix

The pattern is:

1. define the exact meaning of the state
2. prove base cases
3. assume smaller states are solved correctly
4. show the transition builds the current state correctly

#### Tiny Example: DP

If

$$
\mathrm{dp}[i]
$$

means "best answer using the first `i` items", then the proof is usually:

- base case `dp[0]` is obviously correct
- assume all states with smaller `i` are correct
- each candidate transition to `dp[i]` corresponds to one valid last choice
- taking the best over all valid last choices is therefore correct

The proof and the recurrence should mirror each other. If they do not, the state is often wrong or incomplete.

For example, in interval DP you often define:

$$
\mathrm{dp}[l][r] = \text{best answer on the subarray } a[l..r].
$$

Then the proof is by increasing segment length:

- base case: length `1` or `0`
- induction hypothesis: all shorter intervals are already solved correctly
- current step: every legal first move or split reduces to shorter intervals
- conclusion: taking the best among those legal reductions gives the right answer for `[l, r]`

If your transition needs a state that is not encoded in `dp[l][r]`, that is usually evidence that the state is too weak.

### 4. Exchange Arguments For Greedy Algorithms

Greedy correctness often does **not** come from "it feels locally best".

It comes from showing that an optimal solution can be rearranged to agree with the greedy choice without becoming worse.

Typical shape:

1. take any optimal solution
2. compare its first disagreement with the greedy solution
3. swap or replace one local choice
4. show the result is still optimal
5. repeat until the optimal solution matches the greedy structure

#### Tiny Example: Interval Scheduling

Sort intervals by finishing time and always take the earliest finishing compatible interval.

Why is that safe?

- suppose an optimal solution starts with some compatible interval that finishes later
- swapping it with the earliest finishing compatible interval never reduces the room left for future intervals
- therefore there exists an optimal solution that agrees with the greedy first choice

That is an exchange argument.

Without that structure, "earliest finish seems smart" is not yet a proof.

### 5. Monotonicity For Binary Search

Binary search is a proof technique disguised as a loop.

You need two ingredients:

1. an ordered search space
2. a predicate that changes only once

For first-true search, the central property is:

$$
x \le y \text{ and } \mathrm{good}(x) \Rightarrow \mathrm{good}(y).
$$

Then the classic invariant is:

- `l` is bad
- `r` is good
- the first good answer lies in `(l, r]`

The loop is easy once those meanings are fixed.

What usually goes wrong is one of these:

- the predicate is not actually monotone
- `l` and `r` silently change meaning mid-loop
- the return value does not match the invariant

### 6. Counterexample Search Is Part Of Proof, Not A Separate Phase

When a proof sketch feels fragile, do not immediately change the code.

Attack the model with tiny cases:

- smallest legal input
- all equal
- empty / singleton / full boundary
- extreme values
- a case where the tempting local move is wrong

This is not "testing after proving".

It is often the fastest way to discover that:

- the invariant was too weak
- one state dimension was missing
- the boundary convention was inconsistent
- a claimed monotonicity statement was false

### 7. Strong Enough, But Not Too Strong

Many proof failures come from picking the wrong invariant strength.

Too weak:

- easy to maintain
- impossible to derive the answer from at exit

Too strong:

- sounds elegant
- hard or impossible to preserve mechanically

Good contest invariants usually say exactly what the loop needs and no more.

Example:

- for binary search, "left part is all bad, right part is all good" is enough
- you do not need a stronger invariant that classifies every interior point individually

## Complexity And Tradeoffs

Reasoning is not only about correctness. It is also about believable cost.

Before coding, estimate:

- how many states or iterations exist
- what one transition costs
- what preprocessing costs
- how much memory the state table or graph needs

Useful rough guide:

- `O(n)` is routine
- `O(n log n)` is the contest workhorse
- `O(n^2)` needs moderate `n`
- `O(2^n)` or `O(3^n)` requires very small `n`

But the more important habit is:

> derive the complexity from the model you just defined.

Examples:

- binary search on answer: `O(T log range)` where `T` is the check cost
- sparse table: `O(n log n)` build, `O(1)` idempotent query
- interval DP: number of intervals times number of split points

Proof tradeoffs also matter:

| Choice | Benefit | Risk |
| --- | --- | --- |
| very weak invariant | easy to preserve | cannot prove the final claim |
| very strong invariant | clean final step | hard to establish or maintain |
| informal proof only | quick to write | hidden bugs survive |
| small explicit proof contract | slightly slower start | much faster debugging later |

## Variant Chooser

Use this section to choose the right proof tool before coding.

| Situation | Default reasoning tool | What to state explicitly |
| --- | --- | --- |
| one pass over an array or sweep line | loop invariant | meaning of processed prefix / active region |
| DP or recursion | induction on state size / processed work | state meaning, base case, transition meaning |
| greedy after sorting | exchange argument or stays-ahead | what local choice is forced into some optimal solution |
| binary search on answer | monotonicity + boundary invariant | what is bad, what is good, why the predicate changes once |
| two pointers / sliding window | interval invariant | what property `[l, r)` currently satisfies and why moves preserve it |
| graph traversal | traversal invariant | what is already discovered / finalized / on stack |
| hidden WA with no obvious bug | counterexample search | smallest case that attacks the claimed model |

Anti-chooser:

- if you cannot state the state meaning in one sentence, stop and fix that before choosing a proof style
- if the proof needs too many ad-hoc exceptions, the model is often wrong

## Worked Examples

### Example 1: Binary Search Invariant

Suppose `good(x)` is monotone and we want the first good integer.

Maintain:

- `l` is bad
- `r` is good
- answer lies in `(l, r]`

If `mid` is good:

- the first good answer cannot be to the right of `mid`
- update `r = mid`

If `mid` is bad:

- the first good answer cannot be at or left of `mid`
- update `l = mid`

When `r = l + 1`, there is no room for any other boundary point, so `r` is the first good answer.

This tiny proof is stronger than memorizing one template mechanically.

### Example 2: Prefix Sums As A Loop Contract

Take

$$
\mathrm{pref}[0] = 0, \qquad \mathrm{pref}[i + 1] = \mathrm{pref}[i] + a[i].
$$

The loop contract is:

- state meaning: `pref[i]` is the sum of the first `i` values, so `pref` uses the repo's usual half-open convention
- invariant: after finishing array index `i`, `pref[i + 1]` is correct
- progress: `i` increases by `1`
- exit: once all indices are processed, every prefix entry is correct

Then half-open range sums follow by algebra:

$$
\sum_{k=l}^{r-1} a[k] = \mathrm{pref}[r] - \mathrm{pref}[l].
$$

Most bugs here are boundary bugs:

- mixing half-open and closed formulas
- forgetting the sentinel `pref[0]`

The reasoning catches those before the sample does.

### Example 3: Greedy Interval Scheduling

Sort intervals by finishing time and repeatedly choose the earliest finishing compatible interval.

Recognition cue:

- the local choice leaves the most room for later decisions

Proof shape:

- let an optimal solution choose some other first compatible interval
- replacing it with the earlier-finishing greedy interval does not make later compatibility worse
- therefore some optimal solution agrees with the greedy first choice
- recurse on the remaining suffix

This is exactly why the implementation should sort by end time, not start time.

### Example 4: Induction On Segment Length

Take [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md).

One useful state is:

$$
\mathrm{dp}[l][r] = \text{maximum score difference current player can force on } a[l..r].
$$

Why is induction on interval length natural?

- every move removes either `a[l]` or `a[r]`
- the remainder is a strictly shorter interval
- so all recursive references go to smaller states

The proof skeleton is:

- base case: for `l = r`, the difference is just `a[l]`
- induction hypothesis: every interval of length `< len` is solved correctly
- transition:
  - take left gives `a[l] - dp[l + 1][r]`
  - take right gives `a[r] - dp[l][r - 1]`
- conclusion: the larger of those two values is exactly the best achievable difference on `[l, r]`

This is the kind of proof that makes interval DP feel systematic instead of mysterious.

### Example 5: Debugging A Hidden WA

Suppose a two-pointer solution fails only on hidden tests.

Do not start by rewriting the code.

Ask:

1. what does `[l, r)` mean?
2. what property is guaranteed true for that window?
3. after incrementing `r`, what could become false?
4. after incrementing `l`, what becomes true again?
5. what is the smallest case that stresses the repair step?

That is reasoning used as a debugging tool, not as a textbook ornament.

## Algorithm And Pseudocode

For this page, the "algorithm" is a pre-code proof checklist.

```text
Reasoning Contract(problem):
    define the state or main variables in one sentence each
    choose the proof style:
        invariant / induction / exchange / monotonicity / counterexample
    write the central maintained claim
    write the boundary convention
    write the progress measure
    write the claimed time and memory complexity
    generate one tiny case that attacks the model
    only then start coding
```

For loops specifically:

```text
Loop Proof Skeleton(Q, P, B, body, R):
    show initialization makes P true
    show P and B imply body preserves P
    show a well-founded variant measure strictly decreases, or a bounded counter strictly advances toward its explicit limit
    show P and not B imply R
```

That skeleton is not formal-methods ceremony. It is the shortest reusable correctness checklist for many contest loops.

## Implementation Notes

- Write one-line contracts in comments when the state is nontrivial:
  - `dp[mask][last] = ...`
  - `l bad, r good`
  - `window [l, r) is valid`
- Prefer half-open interval conventions when possible; they reduce fencepost mistakes.
- In binary search, keep midpoint arithmetic overflow-safe and keep endpoint meaning stable.
- In DP, most wrong answers come from wrong state meaning or wrong iteration order, not from syntax.
- In greedy implementations, the bug is often in the sort key or tie policy because that is where the proof lives.
- If hidden tests keep failing, reopen:
  - [Foundations Cheatsheet](../../../notebook/foundations-cheatsheet.md)
  - [Build Kit](../../../docs/build-kit.md)
  - [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
  - [Local Judge Workflow](../../../notebook/local-judge-workflow.md)
- Use assertions locally when a maintained claim is cheap to check. They are a reasoning aid, not a crutch.

## Practice Archetypes

- **Warm-up**
  - [Increasing Array](../../../practice/ladders/foundations/complexity-and-invariants/increasingarray.md)
    Why: forces you to state what the running target means and why each repair is sufficient.
  - [Static Range Sum Queries](../../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)
    Why: pure prefix-sum invariant with boundary discipline.
- **Core**
  - [Factory Machines](../../../practice/ladders/foundations/binary-search/factorymachines.md)
    Why: monotone predicate + explicit bad/good boundary reasoning.
  - [Apartments](../../../practice/ladders/foundations/two-pointers/apartments.md)
    Why: sliding invariant and repair logic.
  - [Movie Festival](../../../practice/ladders/foundations/sorting/moviefestival.md)
    Why: classic exchange-argument greedy after sorting.
- **Stretch**
  - [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)
    Why: interval-DP state meaning and induction on segment length.
  - [Company Queries II](../../../practice/ladders/graphs/lca/companyqueries2.md)
    Why: correctness depends on precise meaning of preprocessing tables, not only code memorization.

## References And Repo Anchors

- **Course**
  - [Cornell CS2110: Loop invariants and the four loopy questions](https://www.cs.cornell.edu/courses/cs2110/2017sp/online/loops/01aloop1.html)
  - [Cornell CS2112: Loop invariants](https://www.cs.cornell.edu/courses/cs2112/2019fa/lectures/loopinv/)
  - [Stanford CS161: Greedy algorithms and exchange arguments](https://web.stanford.edu/class/archive/cs/cs161/cs161.1138/lectures/14/Slides14.pdf)
  - [CMU 15-210 DP notes](https://www.cs.cmu.edu/afs/cs/academic/class/15210-s15/www/lectures/dp-notes.pdf)
- **Reference**
  - [CP-Algorithms: Binary search on arbitrary predicate](https://cp-algorithms.com/num_methods/binary_search.html)
- **Practice**
  - [CSES Problem Set](https://cses.fi/problemset/)
  - [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- **Repo anchors**
  - [Complexity And Invariants Ladder](../../../practice/ladders/foundations/complexity-and-invariants/README.md)
  - [Foundations Cheatsheet](../../../notebook/foundations-cheatsheet.md)
  - [Build Kit](../../../docs/build-kit.md)
  - [Binary Search](../patterns/binary-search/README.md)
  - [Prefix Sums](../patterns/prefix-sums/README.md)
  - [Two Pointers](../patterns/two-pointers/README.md)
  - [Sorting](../patterns/sorting/README.md)

## Related Topics

- [C++ Language For Contests](../cpp-language/README.md)
- [Binary Search](../patterns/binary-search/README.md)
- [Two Pointers](../patterns/two-pointers/README.md)
- [DP Foundations](../../dp/foundations/README.md)
- [Contest Engineering](../../advanced/contest-engineering/README.md)
