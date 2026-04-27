# Digit DP

Digit DP is the standard contest answer for:

- "count integers in a huge range"
- where the property depends on the digits of the integer
- and brute force over the range is impossible

The technique feels mysterious only when the state is introduced as a formula first. The right mental model is simpler:

1. build the number from left to right
2. remember whether your prefix is still glued to the upper bound
3. remember only the smallest extra state needed to decide whether future digits are still valid

So digit DP is really **bounded prefix construction plus one carefully chosen property state**.

This page is designed to make four things feel automatic:

1. define `solve(x)` on the range `[0, x]`
2. reduce `[L, R]` to `solve(R) - solve(L - 1)`
3. explain `tight` and `started` in plain English before writing code
4. choose an extra state that is sufficient, small, and memoizable

## At A Glance

Reach for digit DP when:

- the range endpoints are huge, often up to `10^18`, `10^100`, or a decimal string
- validity depends on digits, adjacent digits, digit sum, remainder, used digits, or automaton state
- the task is "how many numbers in a range satisfy ..."
- the natural brute force is "loop from `L` to `R` and check each number", and that is obviously too slow

Strong contest triggers:

- "count integers in `[L, R]` with no adjacent equal digits"
- "count integers whose digit sum is divisible by `k`"
- "count integers that avoid a forbidden substring in decimal representation"
- "count integers whose remainder modulo `m` satisfies ..."
- "count numbers with exactly `c` nonzero digits"

Strong anti-cues:

- the range is small enough to brute force directly
- the property depends mostly on the value, not on decimal structure
- the problem is really combinatorics on length classes with no upper bound interaction
- the state needed to remember the property explodes and another viewpoint is cleaner

What success looks like after studying this page:

- you can define `tight` without hand-waving
- you know exactly when `started` is necessary
- you can explain why `solve(R) - solve(L - 1)` is the standard range reduction
- you know why memoizing only non-tight states is often the clean contest default
- you can look at a new problem and say what the extra digit-DP state should be

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md) when the count itself is taken modulo `MOD`
- comfort with memoized DFS or small-state dynamic programming

Helpful neighboring topics:

- [Aho-Corasick](../../strings/aho-corasick/README.md) when the digit property is "contains / avoids a pattern"
- [Bitmask DP](../bitmask-dp/README.md) when the extra state tracks a small used-set

## Problem Model And Notation

Let `f(x)` denote:

$$
f(x) = \text{number of valid integers in } [0, x].
$$

Then the answer on an arbitrary range is:

$$
\text{answer}(L, R) = f(R) - f(L - 1).
$$

That reduction is the first thing to internalize. Once you can solve the prefix-bounded problem `[0, x]`, the general range problem is essentially finished.

Let the decimal digits of `x` be:

$$
d_0 d_1 \dots d_{n-1},
$$

from most significant to least significant.

A standard digit-DP state is written as:

$$
\text{dp}(pos,\ tight,\ started,\ extra).
$$

Read each component in plain English:

- `pos`: which digit are we filling now?
- `tight`: is the prefix we built so far still exactly equal to the prefix of the bound?
- `started`: have we already placed the first non-leading-zero digit?
- `extra`: the smallest extra information needed by the property

Examples of `extra`:

- previous real digit
- current digit sum
- current remainder modulo `m`
- count of nonzero digits used so far
- automaton state for forbidden/required patterns

## State Playground

<div class="visual-card" data-digit-dp-visualizer>
  <p class="visual-caption">
    Walk one branch of digit DP for upper bound `325` with the property "no equal adjacent real digits". The point is to see
    exactly what `tight`, `started`, and `prev` mean before worrying about the full memo table.
  </p>
  <div class="visual-controls">
    <label>
      Choose next digit
      <select data-role="digit"></select>
    </label>
    <button type="button" data-role="take">Take digit</button>
    <button type="button" data-role="undo">Undo</button>
    <button type="button" data-role="reset">Reset</button>
  </div>
  <div class="visual-grid">
    <div class="visual-panel">
      <h4>Upper bound digits</h4>
      <div class="visual-strip visual-strip--six" data-role="bound-strip"></div>
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
          <strong>Current state</strong>
          <code data-role="state"></code>
        </div>
        <div class="visual-stat">
          <strong>Chosen prefix</strong>
          <code data-role="prefix"></code>
        </div>
        <div class="visual-stat">
          <strong>Digit limit at this position</strong>
          <code data-role="limit"></code>
        </div>
        <div class="visual-stat">
          <strong>Latest transition</strong>
          <code data-role="result"></code>
        </div>
      </div>
      <p class="visual-note" data-role="note"></p>
      <div class="visual-stats" data-role="choices"></div>
    </div>
  </div>
</div>

### Visual Reading Guide

What to notice:

- while `tight = 1`, the current position is capped by the matching bound digit; as soon as you choose a smaller digit, `tight` flips to `0` and the future becomes free
- while `started = 0`, choosing another `0` does not create a previous real digit yet, so leading zeros do not trigger the adjacency rule

Why it matters:

- this is the shortest route from "digit DP state names look abstract" to "I know what real information the DP is carrying from one position to the next"
- it also makes clear that the property state should be minimal: here `prev` is enough, because the next digit only cares about the previous real digit

Code bridge:

- the branch logic is the standard digit-DP transition: loop `dig` from `0` to `limit`, compute `next_tight`, compute `next_started`, and update `prev` only after the number has started
- once the state is defined this way, memoization works because the future depends only on `(pos, tight, started, prev)`, not on the exact full prefix

Boundary:

- this widget teaches state meaning, not the whole counting recursion; the real DP still sums over all valid outgoing digits instead of following one branch
- if the property were "digit sum modulo k" or "forbidden substring", the same `pos / tight / started` frame would stay, but `prev` would be replaced by a different extra state

## From Brute Force To The Right Idea

### Brute Force

Suppose we want to count valid numbers in `[L, R]`.

The naive algorithm is:

1. loop through every integer `v` from `L` to `R`
2. inspect its digits
3. test whether it satisfies the property

If `R - L` can be as large as `10^18`, this is hopeless.

### The First Structural Observation

The problem is not really about integers as arithmetic objects. It is about:

- decimal strings
- of bounded length
- that do not exceed a given bound
- and satisfy a digit-local or digit-aggregated property

So instead of enumerating numbers, we enumerate **prefix decisions**.

At each position:

- choose the next digit
- keep only choices that do not violate the upper bound
- update the small property state

This is already a DP shape.

### Why Prefix Construction Is Enough

When you have already fixed the first `pos` digits, the future only depends on:

- where you are (`pos`)
- whether you are still equal to the bound prefix (`tight`)
- whether the number has actually started (`started`)
- the compact property summary (`extra`)

You do **not** need to remember the whole prefix explicitly.

That is the entire reason digit DP works: many different partial prefixes collapse into the same future subproblem.

### The Range Trick

Digit DP is almost always written for `[0, x]`, not directly for `[L, R]`.

That is because a single upper bound is much easier than two simultaneous bounds.

So the standard workflow is:

1. write `solve(x)` for `[0, x]`
2. answer the original query as `solve(R) - solve(L - 1)`

If `L = 0`, then the answer is just `solve(R)`.

## Core State And Why Each Piece Exists

### `pos`

`pos` says which digit we are about to fill.

If the bound has `n` digits, then `pos` ranges from `0` to `n`.

When `pos = n`, the number is fully built, so we return:

- `1` if the accumulated state represents a valid number
- `0` otherwise

### `tight`

This is the most important flag in digit DP.

`tight = 1` means:

- every digit chosen so far is exactly equal to the bound's prefix
- so the next digit may not exceed the corresponding bound digit

`tight = 0` means:

- at some earlier position, we already chose a smaller digit
- so the rest of the number is completely free to use digits `0..9`

The key transition is:

- if the current bound digit is `limit`
- and we place digit `dig`

then:

$$
next\_tight =
\begin{cases}
1 & \text{if tight was 1 and } dig = limit \\
0 & \text{otherwise}
\end{cases}
$$

Once `tight` becomes `0`, it never comes back to `1`.

That one-way behavior is a huge reason the state space stays small.

### `started`

This flag answers:

- "have we already placed the first non-leading-zero digit?"

Why it matters:

- many digit properties should ignore leading zeros
- before the number starts, there is no "previous digit"
- before the number starts, zeros do not yet count as repeated adjacent digits

For example, in [Counting Numbers](../../../practice/ladders/dp/digit-dp/countingnumbers.md), the number `00057` should be treated as the integer `57`, not as a string containing repeated leading zeros.

So while `started = 0` and we place another `0`:

- the number still has not started
- adjacency constraints on real digits still do not apply

### `extra`

This is where the actual problem lives.

The best way to choose `extra` is:

1. say the property in plain English
2. ask what information from the prefix the suffix really needs
3. keep only that information

Examples:

| Property | Good extra state |
| --- | --- |
| no equal adjacent digits | previous real digit, or sentinel if none yet |
| digit sum equals / is divisible by `k` | current sum or current sum modulo `k` |
| number modulo `m` | current remainder modulo `m` |
| exactly `c` nonzero digits | count of nonzero digits used so far |
| avoid substring pattern | automaton state |

Bad sign:

- if your state is trying to store the entire prefix, the DP has not been compressed enough

## Core Invariant And Why It Works

### Prefix Construction Invariant

At state `(pos, tight, started, extra)`, we have already fixed the first `pos` digits of some candidate number.

The invariant is:

- those chosen digits form a valid prefix with respect to the property
- `tight` correctly describes whether that prefix still equals the bound's prefix
- `started` correctly describes whether any real digit has appeared
- `extra` contains exactly the property information needed to continue

The future depends only on this state, not on the exact path that produced it.

That is why memoization is legal.

### Why `tight` Is Sufficient For The Upper Bound

Suppose the prefix built so far is already smaller than the bound prefix.

Then no future suffix can make the final number exceed the bound, because the first differing position has already decided the comparison.

So once `tight = 0`, the remaining digits are unconstrained by the bound.

Conversely, if `tight = 1`, then the next digit must remain within the one-position limit imposed by the bound.

Therefore `tight` is the only bound-related memory we need.

### Why `started` Solves Leading-Zero Ambiguity

Without `started`, the DP cannot distinguish between:

- "I have already placed a real zero digit"
- "I am still padding with leading zeros"

That distinction is essential in many problems.

For instance, in the property "no equal adjacent digits":

- `1002` is invalid if it has adjacent equal real digits
- but the padded representation `00057` should not be disqualified because of the leading zeros

So `started` lets us separate:

- structural padding before the number begins
- genuine digits after the number begins

### Why The Extra State Must Be Sufficient

The extra state must answer:

- if I know this state and choose the next digit `d`, can I determine the next state?

If the answer is no, the state is missing information.

Example:

- for "no equal adjacent digits", knowing only the current digit sum is not enough
- you must know the previous real digit to decide whether the next digit is allowed

Example:

- for "remainder modulo `m` equals `0`", the current remainder is enough because:

$$
new\_rem = (10 \cdot rem + d) \bmod m.
$$

### Why Range Reduction Is Correct

Every integer in `[L, R]` lies in `[0, R]`.

The only integers counted by `f(R)` but not belonging to `[L, R]` are those in `[0, L-1]`.

So:

$$
\# [L, R] = \# [0, R] - \# [0, L-1].
$$

This is simple set subtraction, but it is worth treating as a theorem you should use reflexively in digit DP.

### When Memoization Is Safe

Contest code often caches only states with `tight = 0`.

Why?

- when `tight = 0`, the suffix is completely free from the specific bound string
- so the answer from that state depends only on the DP parameters

When `tight = 1`, the answer still depends on the exact remaining suffix of the bound. If you solve one bound at a time and clear the memo between solves, you may still cache tight states too. But:

- caching only `tight = 0` is a very common safe default
- it avoids subtle bugs when people reuse memo tables incorrectly

For example, in a plain count up to `347`, both prefixes `1` and `2` immediately fall into the same state:

$$
dp(pos = 1,\ tight = 0).
$$

From there, each branch has exactly `100` free suffixes left, so memoizing that non-tight state is safe and useful.

But the prefix `3` lands in:

$$
dp(pos = 1,\ tight = 1),
$$

which is different because the remaining suffix is still bounded by `47`.

## Complexity And Tradeoffs

If the bound has `n` digits and the extra state has size `S`, then the state count is roughly:

$$
O(n \cdot 2 \cdot 2 \cdot S),
$$

and each state tries up to `10` next digits.

So the total complexity is typically:

$$
O(n \cdot S \cdot 10).
$$

That is tiny whenever `S` is small.

Typical examples:

- no adjacent equal digits: `S \approx 11` for previous digit plus sentinel
- digit sum modulo `k`: `S = k`
- remainder modulo `m`: `S = m`
- count of used digits by bitmask: `S = 2^{10}`, still sometimes fine

Practical tradeoffs:

| Approach | Best when | Why it wins | Where it breaks |
| --- | --- | --- | --- |
| brute force over values | range is small | simplest possible | impossible for huge bounds |
| direct combinatorics by length | property is easy without upper bound | often cleaner than DP | hard once the upper bound matters position by position |
| digit DP | huge bounded range, digit-defined property | handles upper bound exactly | state design is the real difficulty |
| automaton + digit DP | property is "contains / avoids pattern" | pattern logic stays compact | state becomes larger and harder to debug |
| bitwise DP | property is naturally binary | same idea on bits instead of digits | decimal intuition no longer applies directly |

## Variant Chooser

| Variant | Use it when | Typical state | Main pitfall |
| --- | --- | --- | --- |
| plain prefix-bounded count | every number in `[0, x]` is valid | `(pos, tight)` | too trivial to teach the real technique alone |
| leading-zero aware property | the property should ignore padded zeros | `(pos, tight, started, extra)` | forgetting that zeros before start are not real digits |
| previous-digit constrained | rule depends on adjacency | `(pos, tight, started, prev)` | treating leading zeros as actual previous digits |
| sum / remainder constrained | property aggregates digits | `(pos, tight, started, rem_or_sum)` | state too large if you track exact sum unnecessarily |
| exact count in `[L, R]` | original problem gives two bounds | `solve(R) - solve(L - 1)` | off-by-one on `L - 1` |
| automaton digit DP | digits must avoid/match string pattern | `(pos, tight, started, automaton_state)` | forgetting that automaton is the true extra state |

## Worked Examples

### Example 1: The Simplest Prefix Count

Suppose `x = 347`, and imagine every number is valid.

Then `solve(x)` should count all integers in `[0, 347]`, so the answer is clearly `348`.

That sounds too simple, but it teaches the `tight` logic cleanly.

At position `0`, the bound digit is `3`, so we may place:

- `0`, `1`, or `2` -> then `tight` becomes `0`
- `3` -> then `tight` stays `1`

If we place `1` first, every remaining suffix is free, so there are:

$$
10 \cdot 10 = 100
$$

choices below that branch.

If we place `3` first, we remain tied to the bound and must inspect the next digit under the limit `4`, then the final digit under the limit `7`.

This is the whole point of `tight`:

- while tied, respect the bound digit
- once smaller, count all free suffixes

Two different prefixes can collapse into the same non-tight state immediately. In this toy count:

- choosing first digit `1` gives `dp(1, 0)`
- choosing first digit `2` also gives `dp(1, 0)`

That shared state is exactly why the memo table saves work.

### Example 2: No Equal Adjacent Digits

This is the core pattern from [Counting Numbers](../../../practice/ladders/dp/digit-dp/countingnumbers.md).

We want to count valid integers in `[0, x]` such that no two adjacent real digits are equal.

The extra state is:

- `prev`: previous real digit, or a sentinel if none yet

The full state becomes:

$$
dp(pos,\ tight,\ started,\ prev).
$$

Why it is sufficient:

- if the number has not started, any digit is allowed
- if the number has started, the only local information needed to validate the next digit is the previous real digit

Now trace the prefix of `x = 325`.

At `pos = 0`, we may choose:

- `0`, `1`, `2` -> immediately become non-tight
- `3` -> remain tight

Suppose we choose `3`, so state becomes:

- `pos = 1`
- `tight = 1`
- `started = 1`
- `prev = 3`

The next bound digit is `2`, so the allowed next digits are `0, 1, 2`.

If we choose `2`, we remain tight and go to:

- `pos = 2`
- `prev = 2`

Now the last bound digit is `5`, and the valid choices are:

- `0, 1, 3, 4, 5`

but not `2`, because it would repeat the previous real digit.

That is exactly why `prev` is the right extra state.

### Example 3: Why `started` Matters

Take the same property "no equal adjacent digits" and consider the padded representation of `57` inside a 4-digit solve:

$$
0057.
$$

If we forgot `started` and treated those leading zeros as real digits, then we would incorrectly say:

- the first two digits are equal
- so the number is invalid

But the integer `57` should absolutely be valid.

Correct handling is:

- while `started = 0` and we place `0`, remain in "not started" mode
- once we place `5`, switch `started` to `1`
- only after that do adjacency checks use `prev`

Now follow the all-zero path all the way:

```text
0 -> 0 -> 0 -> 0
```

At `pos == n`, that path represents the integer `0`.

So:

- if the problem counts numbers in `[0, x]`, this terminal state should return `1`
- if the problem counts only positive integers, this terminal state should return `0`

This one distinction explains a huge fraction of beginner bugs in digit DP.

### Example 4: The Zero Path Is A Real Base Case

Suppose we solve over 4 digits and the bound is large enough that the path

```text
0000
```

is legal.

If the DP reaches:

```text
pos = 4, started = 0
```

then you must decide whether that means:

- "we formed the integer `0`" -> return `1`
- or "we never formed a positive number" -> return `0`

That choice is not cosmetic. It is one of the core semantics of the problem statement.

### Example 5: From `[0, x]` To `[L, R]`

Suppose the problem asks for the number of valid integers in `[80, 325]`.

We do **not** write a two-bounds DP first.

Instead:

$$
\text{answer} = solve(325) - solve(79).
$$

This is almost always the right contest route:

- one solve for the upper endpoint
- one solve for the predecessor of the lower endpoint
- subtract

This is cleaner, less bug-prone, and far easier to explain.

## Algorithm And Pseudocode

The repo starter template is:

- [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)

Here is the generic memoized DFS shape:

```text
solve_bound(x):
    if x < 0:
        return 0
    digits = decimal representation of x
    clear memo
    return dfs(0, 1, 0, initial_extra)
```

```text
dfs(pos, tight, started, extra):
    if pos == number_of_digits:
        return 1 if terminal_condition(started, extra) else 0

    if this state is memoized safely:
        return memoized value

    limit = digits[pos] if tight else 9
    ans = 0

    for dig from 0 to limit:
        next_tight = tight and (dig == limit)

        if started == 0 and dig == 0:
            next_started = 0
            next_extra = state_for_still_not_started
        else:
            next_started = 1
            if placing dig violates the property under extra:
                continue
            next_extra = transition(extra, dig, started)

        ans += dfs(pos + 1, next_tight, next_started, next_extra)

    memoize if appropriate
    return ans
```

Range wrapper:

```text
count_range(L, R):
    return solve_bound(R) - solve_bound(L - 1)
```

### Example Specialization: No Equal Adjacent Digits

For the [Counting Numbers](../../../practice/ladders/dp/digit-dp/countingnumbers.md) pattern:

- `extra = prev`
- sentinel `prev = 10` means "no previous real digit yet"
- a transition is illegal iff `started = 1` and `dig = prev`

That is exactly the kind of small, meaningful extra state you want digit DP to teach first.

## Implementation Notes

### 1. Define The State In English Before The Array

Before writing:

```text
dp[pos][tight][started][...]
```

write one sentence for each dimension in plain English.

If you cannot explain a dimension clearly, the state is usually not mature yet.

### 2. Decide What `started = 0` Means For The Extra State

Common conventions:

- previous digit sentinel
- remainder `0`
- digit sum `0`
- automaton root state

Pick one consistent meaning and document it in code comments.

### 3. Be Careful With `next_tight`

If `limit` is defined as:

```text
limit = tight ? digits[pos] : 9
```

then:

```text
next_tight = tight && (dig == limit)
```

is correct.

Why?

- when `tight = 0`, `next_tight` must stay `0`
- when `tight = 1`, `limit` is exactly the bound digit at this position

Many people write a more explicit version using the bound digit directly. Either is fine if you are consistent.

### 4. The Terminal Condition Must Match The Problem

At `pos == n`, do not blindly return `1`.

Sometimes the terminal condition is:

- every constructed number counts, including `0`

Sometimes it is:

- the number must have started
- the final sum / remainder / count must satisfy a target condition

So the terminal line is part of the math, not a throwaway base case.

### 5. Memoize Only What Is Bound-Independent

The safest contest habit is:

- cache only states with `tight = 0`

because those states no longer depend on the exact remaining suffix of the bound.

If you cache all states, be sure the memo table is cleared for every bound solve.

### 6. `L - 1` Needs Care

If the original query is `[L, R]`, then:

- if `L = 0`, skip the subtraction edge case cleanly
- if your bound type is signed 64-bit, make sure `L - 1` does not underflow accidentally

A common safe helper is:

```text
solve_bound(x):
    if x < 0:
        return 0
    ...
```

### 7. Keep The Extra State Minimal

Good digit DP usually feels small after the state is chosen correctly.

If the memo dimensions are exploding, ask:

- can the property be represented by remainder instead of full value?
- can the state be compressed to a count, a previous digit, or an automaton node?
- am I storing history that the suffix never needs?

### 8. Recursive Memoization Is Usually The Best First Implementation

There are iterative digit-DP styles too, and some are excellent. But for most first passes:

- memoized DFS matches the mental model
- it is easier to attach problem-specific transitions
- it is easier to debug with print statements or a tiny hand trace

## Practice Archetypes

The standard archetypes to recognize are:

- **adjacency constraint**: previous digit or previous few digits matter
- **digit aggregate**: sum, count, parity, remainder
- **pattern containment / avoidance**: automaton state plus digit DP
- **used-set / distinctness**: bitmask over digits
- **range counting**: solve upper prefix twice and subtract

If a problem says:

- count numbers in a huge range
- property depends on decimal digits
- brute force over the interval is impossible

then digit DP should be in your shortlist almost immediately.

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [USACO Guide: Digit DP](https://usaco.guide/gold/digit-dp?lang=cpp)
- [Dynamic Programming for Computing Contests](https://dp-book.com/Dynamic_Programming.pdf)

Reference:

- [GeeksforGeeks: Digit DP Introduction](https://www.geeksforgeeks.org/dsa/digit-dp-introduction/)

Essay / blog:

- [Codeforces: DIGIT DP Tutorial [ITERATIVE]](https://codeforces.com/blog/entry/77096)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice note: [Counting Numbers](../../../practice/ladders/dp/digit-dp/countingnumbers.md)
- practice ladder: [Digit DP ladder](../../../practice/ladders/dp/digit-dp/README.md)
- starter template: [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)
- notebook refresher: [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Aho-Corasick](../../strings/aho-corasick/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
