# Game Theory / Sprague-Grundy

This lane is for the moment when a game problem stops being:

- plain minimax over a short state space
- score-difference DP on one interval
- one direct parity trick

and becomes:

- an **impartial** normal-play game
- with finite acyclic state transitions
- where positions may split into independent subgames
- and the right invariant is a `mex`-defined nimber

In contest terms, the key shift is:

- stop asking only "winning or losing?"
- assign each position one Grundy value
- xor those values when the position is a sum of independent games

This is the exact lane for the repo's first `Sprague-Grundy` route.

## At A Glance

- **Use when:** both players have the same moves from any state, the player with no move loses, and the game decomposes into independent heaps / components or one finite move graph
- **Core worldview:** every finite impartial normal-play position is equivalent to one Nim heap of size `SG(state)`
- **Main tools:** `mex`, Grundy recurrence, xor of independent subgames
- **Typical complexity:** `O(states * transitions)` for one finite precompute, then `O(number of components)` per test
- **Main trap:** applying Sprague-Grundy to score-maximization, misere play, or non-independent sums

Strong contest signals:

- "players alternately move, same legal moves for both players"
- "if you cannot move, you lose"
- "several heaps / piles / components are played together"
- "the move set is fixed and each heap can be analyzed separately"
- "one move can split the state into smaller independent games"

Strong anti-cues:

- the game is about maximizing score difference -> [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)
- legal moves depend on which player you are -> not an impartial game
- the losing condition is misere rather than normal play
- the move graph can cycle and the statement does not promise a finite acyclic reduction

The repo's exact first route for this family is:

- starter -> [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp)
- flagship note -> [S-Nim](../../../practice/ladders/math/game-theory/snim.md)
- compare point -> [Stick Game](https://cses.fi/problemset/task/1729/)
- compare point -> [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)

## Prerequisites

- [Reasoning And Implementation Discipline](../../foundations/reasoning/README.md) for state invariants and proof by induction on smaller states
- [C++ Language For Contests](../../foundations/cpp-language/README.md) for dense table precompute and careful xor bookkeeping

Helpful neighboring topics:

- [XOR Basis / Linear Basis](../xor-basis/README.md): a compare point for "xor is the invariant," but over vectors rather than Nim heaps
- [Interval DP](../../dp/interval-dp/README.md): the main anti-cue when a game is really score DP, not impartial normal-play theory
- [Tree DP](../../dp/tree-dp/README.md): useful later when subgames come from recursive decomposition

## Problem Model And Notation

Let `G(v)` be the set of positions reachable from position `v` in one move.

For a finite impartial normal-play game:

- both players share the same move graph
- terminal positions have no outgoing edges
- terminal positions are losing

Define the Grundy value:

$$
\operatorname{SG}(v) = \operatorname{mex} \{ \operatorname{SG}(u) \mid u \in G(v) \}
$$

where `mex` is the smallest non-negative integer missing from the reachable set.

Key consequences:

- `SG(v) = 0` iff `v` is losing
- if a position is a sum of independent subgames `v_1 + v_2 + \dots + v_k`, then

$$
\operatorname{SG}(v_1 + \dots + v_k) =
\operatorname{SG}(v_1) \oplus \dots \oplus \operatorname{SG}(v_k)
$$

That is the bridge from one component to many.

## From Brute Force To The Right Idea

### Brute Force

The naive route is minimax:

- recursively try all moves
- mark a state winning if it can move to one losing state
- mark it losing if all moves go to winning states

That already works for tiny one-state games, but it breaks down when:

- the same state appears many times
- multiple heaps are combined
- you need more than just win/lose, because xor over independent components matters

### The Structural Observation

For impartial normal-play games, a state is not just `winning` or `losing`.

It has one **nimber**:

- `0` means losing
- nonzero means winning
- and the exact number matters because independent games combine by xor

So the right object is not only:

- win/lose DP

but:

- `mex`-based Grundy DP

### Why `mex` Is The Right Compression

Suppose a state can move to positions with Grundy values:

$$
\{0,1,3\}
$$

Then:

- it can move to Nim-heaps of sizes `0`, `1`, and `3`
- the smallest missing heap size is `2`

So the current position behaves exactly like one Nim heap of size `2`.

That is why:

$$
\operatorname{SG}(v) = \operatorname{mex}(\text{reachable Grundy values})
$$

and not some other summary.

## Core Invariant And Why It Works

### 1. Terminal States Have Grundy `0`

If a position has no legal moves, then:

$$
\operatorname{SG}(v) = \operatorname{mex}(\emptyset) = 0
$$

This matches the game meaning exactly:

- no move available -> losing

### 2. `SG(v) = 0` Means Losing

If `SG(v) = 0`, then `0` is missing from the reachable Grundy values.

So every legal move goes to a position with nonzero Grundy value.

That means every move hands the opponent a winning state.

### 3. `SG(v) != 0` Means Winning

If `SG(v) = g > 0`, then by `mex` definition every value in:

$$
\{0,1,\dots,g-1\}
$$

appears among reachable positions, in particular `0`.

So there exists one move to a losing state.

### 4. Why Xor Combines Independent Games

If a position is the disjoint sum of independent games, one move changes exactly one component while the others stay untouched.

Nim has the same structure:

- one move changes exactly one heap

So independent impartial games combine exactly like Nim heaps do:

- xor their Grundy values

This is the whole payoff of the theorem under contest pressure.

## Worked Examples

### Example 1: Single-Heap Subtraction Game

This compare problem:

- [Stick Game](https://cses.fi/problemset/task/1729/)

has one heap and a fixed move set `S`.

Let `sg[x]` be the Grundy value for a heap of size `x`.

Then:

$$
sg[x] = \operatorname{mex}\{sg[x-s] \mid s \in S,\ s \le x\}
$$

If you only need win/lose, checking `sg[x] == 0` is enough.

This is the cleanest first dynamic-programming doorway.

### Example 2: Many Heaps With The Same Move Set

This repo's flagship note:

- [S-Nim](../../../practice/ladders/math/game-theory/snim.md)

Each heap uses the same subtraction set `S`, so:

1. precompute `sg[x]` once for every heap size up to the maximum
2. xor all heap Grundy values in one position
3. xor `0` means losing, nonzero means winning

This is the exact first route for the repo starter.

### Example 3: Why `Removal Game` Is Not This Lane

In [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md):

- players maximize score
- the value of a state is score difference, not a nimber
- the opponent's response is modeled by subtraction in the DP

So although the statement "sounds like game theory," it is not a Sprague-Grundy problem.

### Example 4: Bigger Games Often Collapse To Patterns

Problems like:

- [Nim Game II](https://cses.fi/problemset/task/1098/)
- [Grundy's Game](https://cses.fi/problemset/task/2207/)
- [Dividing Game](https://atcoder.jp/contests/abc368/tasks/abc368_f)

often start with SG reasoning but then simplify:

- to a short periodic pattern
- to a direct arithmetic invariant
- or to a known closed form

That is why the starter route stays small and honest.

## Variant Chooser

### Route A: One Heap, Need Only Win/Lose

Use this when:

- the state is one integer or one small DAG node id
- there is no sum of independent components in the final answer

Often a plain winning/losing DP is enough.

Still, SG is useful if you want the route to scale later into summed games.

### Route B: Many Independent Heaps / Components

Use this when:

- each component can be solved in isolation
- the whole position is their disjoint sum

Then:

1. compute each component Grundy value
2. xor them

This is the repo starter's exact route.

### Route C: One Move Splits Into Independent Subgames

Use this when one move turns a state into:

$$
A + B + \dots
$$

Then that transition contributes:

$$
\operatorname{SG}(A) \oplus \operatorname{SG}(B) \oplus \dots
$$

before the outer `mex`.

This is the generalization behind many split-game problems.

### Route D: Not This Lane

Do **not** use Sprague-Grundy first when:

- the game is misere
- moves differ by player
- the payoff is total score, not last-move win
- the state graph is cyclic without a safe finite reduction

## Complexity And Tradeoffs

For the repo's exact first route:

- precompute all `sg[x]` for `0 <= x <= M`
- each state checks all legal moves in a fixed set `S`

Time:

$$
O(M \cdot |S|)
$$

Space:

$$
O(M)
$$

Then each multi-heap query is:

$$
O(\text{number of heaps})
$$

Tradeoff:

- this is excellent when one bounded state parameter is reused many times
- it is not the right exact snippet for arbitrary DAG games or for huge-state split games that need pattern discovery

## Starter Fit

The starter in this repo is intentionally narrow:

- one fixed subtraction move set
- one integer state per component
- finite precompute up to one maximum heap size
- xor of independent heaps afterward

That covers:

- subtraction games
- `S`-Nim style problems
- many first SG contest tasks

It does **not** directly advertise:

- arbitrary DAG SG
- split-interval games with expensive transition enumeration
- misere variants
- games whose intended solution is "observe a closed form" instead of table precompute

## Common Pitfalls

- forgetting that xor only combines **independent** subgames
- using Sprague-Grundy on score-maximization games like [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)
- mixing normal-play and misere rules
- computing only win/lose states, then later needing exact nimbers for summed games
- assuming every SG-heavy game is meant to be solved by brute-force precompute all the way to `10^9`

## Repo Routes

- topic lane -> [Math overview](../README.md)
- practice ladder -> [Game Theory / Sprague-Grundy ladder](../../../practice/ladders/math/game-theory/README.md)
- exact starter -> [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp)
- flagship note -> [S-Nim](../../../practice/ladders/math/game-theory/snim.md)
- hot sheet -> [Sprague-Grundy hot sheet](../../../notebook/sprague-grundy-hot-sheet.md)
- compare point -> [Interval DP](../../dp/interval-dp/README.md)
- compare point -> [XOR Basis / Linear Basis](../xor-basis/README.md)

## References

- [cp-algorithms: Sprague-Grundy theorem. Nim](https://cp-algorithms.com/game_theory/sprague-grundy-nim.html)
- [OI Wiki: Impartial Game](https://en.oi-wiki.org/math/game-theory/impartial-game/)
- [Kattis: S-Nim](https://open.kattis.com/problems/snim)
- [CSES: Stick Game](https://cses.fi/problemset/task/1729/)
- [CSES: Nim Game II](https://cses.fi/problemset/task/1098/)
- [CSES: Grundy's Game](https://cses.fi/problemset/task/2207/)
- [AtCoder ABC368 F: Dividing Game](https://atcoder.jp/contests/abc368/tasks/abc368_f)
