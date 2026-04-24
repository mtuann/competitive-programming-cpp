# Constructive

Constructive problems ask you to output an object, a sequence of moves, or a witness that satisfies the rules.

The point is usually not to optimize over all possible answers. The point is to build **one** valid answer by exploiting one strong structural promise in the statement.

This page is theory-led: the main payoff is learning how to spot the right promise, pick the right invariant, and turn a vague "there exists a solution" statement into a short reproducible recipe.

## At A Glance

- Use this page when:
  - the statement says "print any valid answer"
  - existence is guaranteed, or the failure cases are small and explicit
  - the output is a witness or move sequence, not only one numeric optimum
  - brute-force search over all outputs is hopeless, but one small pattern feels plausible
- Prerequisites:
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Algorithm Engineering](../algorithm-engineering/README.md)
  - [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
  - [Local Judge Workflow](../../../notebook/local-judge-workflow.md)
- Strongest cues:
  - "print any solution"
  - "it is guaranteed that a solution exists"
  - "construct a permutation / graph / sequence / set of operations"
  - a very specific promise seems too strong to be accidental
- Strongest anti-cues:
  - the real bottleneck is still discovering the right graph / DP / number-theory model
  - the statement asks for one optimum value rather than a witness
  - the space of valid outputs is huge and no structural promise is visible yet
- Success after studying this page:
  - you can name the one promise that collapses the state space
  - you can prove legality, progress, and final validity separately
  - you can decide whether the right move is explicit patterning, local repair, or tiny residual search
  - you can validate a many-answer solution without guessing

## Problem Model And Notation

A constructive problem usually has this shape:

- there is a universe of candidate outputs $\Omega$
- you must output one witness $w \in \Omega$
- the witness is accepted if a legality predicate $P(w)$ is true

Sometimes the problem also asks for:

- a bounded number of moves
- a canonical output family
- or a proof that no witness exists

The important shift is conceptual:

- optimization problems ask "which answer is best?"
- constructive problems ask "which structural promise makes **one** answer easy to build?"

Three words are useful on almost every constructive page:

- `promise`: a guarantee from the statement that makes a simpler construction possible
- `invariant`: the property that remains true while you build the answer
- `residual freedom`: the small part of the answer you still need to decide after the main structure is fixed

For many constructive solutions, the whole problem becomes:

1. find the right promise
2. lock most of the answer into a canonical skeleton
3. spend the remaining effort only on the residual freedom

## From Brute Force To The Right Idea

The naive view is:

- search over all candidate outputs
- test each one
- stop when one works

This fails because $\Omega$ is usually enormous:

- all permutations
- all subsets
- all graph rewires
- all move sequences

The right idea is to stop thinking about the full output space and instead search for one strong simplification.

Typical simplifications:

- **canonical form**:
  reorder the answer into a standard layout without losing validity
- **local gadget**:
  identify one repeated pattern that creates exactly the feature you need
- **monotone tail / safe side attachment**:
  build the important part first, then attach leftovers in a way that creates no new trouble
- **promise-driven fixed core**:
  keep most of the structure fixed and search only the remaining free part
- **small residual search**:
  once the skeleton is fixed, the leftover state is tiny enough for BFS or exhaustive search

The recurring contest move is:

- do **not** solve the more general problem
- solve the easiest version that the statement already guarantees for you

## Core Invariant And Why It Works

Every constructive proof should answer three questions cleanly:

1. Why is every step legal?
2. Why does the process terminate?
3. Why is the final object valid?

If even one of these is hand-wavy, the construction is usually not ready.

### Invariant 1: Legality

At each construction step, the partial object must stay inside the allowed family.

Examples:

- the prefix remains a valid partial permutation
- every printed move is legal in the current state
- a fixed core continues to match the target under one translation
- the tail attachment does not create extra local extrema

This is the part most people underwrite with intuition. In constructive problems, it must be explicit.

### Invariant 2: Progress

You need a monotone measure $\Phi$ showing that the process cannot loop forever.

Typical choices:

- number of undecided positions decreases
- number of unmatched items decreases
- size of the free residual shrinks
- number of misplaced tokens goes down
- a BFS on the residual state graph has finitely many states

Constructive proofs often fail because they show legality but never show why the method actually finishes.

### Invariant 3: Final Coverage

When the process stops, the remaining state must already imply validity.

Typical final arguments:

- the alternating core already creates all required extrema
- the leftover monotone tail cannot create new forbidden features
- the fixed core plus the tiny residual BFS covers all remaining freedom
- the final witness satisfies every count/adjacency/domain constraint by direct inspection

This is where many good ideas become excellent solutions: the ending condition is simple enough that the final proof is obvious.

## Complexity And Tradeoffs

Constructive problems vary a lot, but the main tradeoff is almost always:

- simpler proof and smaller residual state
versus
- more general but much harder construction

Typical cost patterns:

| Pattern | Typical cost | Main risk |
| --- | --- | --- |
| direct pattern construction | `O(n)` or `O(n log n)` | easy to miss one boundary case |
| greedy repair construction | `O(n log n)` | local step looks legal but global invariant is false |
| fixed core + tiny residual BFS | small polynomial or exponential in tiny residual | overestimating how small the residual really is |
| full search over output space | usually impossible | solving a more general problem than needed |

Important contest lesson:

- when the statement gives a strong promise, the right construction is usually the **smallest** one that uses that promise directly
- if your proof is getting longer than the construction, either the construction is wrong or you are still solving the wrong problem

## Variant Chooser

| Situation | Best first idea | Why it fits | Where it fails |
| --- | --- | --- | --- |
| exact counts of local features such as peaks / valleys / inversions | build one explicit pattern core | local features are created by a short repeated gadget | weak if leftover positions can still create extra features |
| output may be reordered into a standard shape | canonicalize the object first | removes symmetric clutter and shrinks the search space | weak if canonicalization itself destroys legality |
| one part of the answer can be fixed by a statement guarantee | keep a fixed core and search only the free boundary | converts a huge global state into tiny residual freedom | weak if the claimed core is not actually forced |
| the answer can be built greedily while preserving one condition | greedy repair with a visible invariant | lets each move be justified locally | weak if no monotone measure exists |
| many answers are valid and direct diff is meaningless | write a validator before trusting the construction | separates "valid" from "matches my imagination" | weak if the validator itself is too loose |
| the final flexible part is tiny | brute-force or BFS only the residual state | keeps the proof and code short | weak if the residual is not truly tiny |

## Worked Examples

### Example 1: Tiny Construction With An Obvious End Condition

Classic statement:

- for every positive integer $N$, construct $N$ consecutive composite numbers

Construction:

$$
(N+1)! + 2,\ (N+1)! + 3,\ \dots,\ (N+1)! + (N+1)
$$

Why it works:

- each term $(N+1)! + k$ is divisible by $k$ for $2 \le k \le N+1$
- so every number in the block is composite
- the object is explicit; no search is needed

This example is useful because it exposes the essence of constructive thinking:

- identify one object with a built-in divisibility promise
- write it down directly
- prove legality in one line per item

### Example 2: One Alternating Core Plus A Safe Tail

Use [Build the Permutation](../../../practice/ladders/advanced/constructive/buildthepermutation.md).

The raw problem sounds huge:

- search over all permutations with exact numbers of local maxima and minima

The right rewrite is much smaller:

1. local maxima and local minima must alternate
2. therefore feasibility is controlled by tiny arithmetic conditions such as `|a-b| <= 1`
3. all requested extrema can be created inside one alternating core
4. leftover values go into a monotone tail on the safe side so they create no new extrema

The proof naturally splits into the three constructive obligations:

- legality:
  the output is still a permutation
- progress:
  the explicit pattern fills the core and then the tail without backtracking
- final validity:
  the core creates exactly the requested extrema, and the tail cannot add extras

This is the cleanest "pattern core + safe attachment" constructive archetype in the repo.

### Example 3: Promise-Driven Fixed Core Plus Tiny Residual Search

Use [VMCOINS](../../../practice/ladders/advanced/constructive/vmcoins.md).

The naive view is:

- huge reconfiguration search on an infinite board

The statement promise is the real key:

- after the right translation, an `N - 2` common core can stay fixed

That collapses the problem to:

1. identify a translated target with a fixed common core
2. treat only two coins as free
3. run BFS on the residual state of those two free coins

This is still constructive, but not "print one fixed pattern and stop."

It shows an important higher-level rule:

- a constructive solution may still contain search
- the search is acceptable when the statement promise reduces it to a tiny residual state

## Algorithm And Pseudocode

There is no universal constructive algorithm, but there is a universal checklist.

```text
CONSTRUCT(instance I):
    identify the strongest promise in I
    choose a partial skeleton S that exploits that promise
    define:
        legality invariant L
        progress measure Phi
        final validity condition V

    while some residual freedom remains:
        choose one local gadget / placement / move
        apply it only if L is preserved
        ensure Phi decreases or the residual state stays bounded

    prove or check that V now holds
    return the witness
```

If the residual freedom is tiny, replace the loop with:

```text
search only the residual state graph
```

The central question is always:

- what part should be explicit patterning,
- and what part is small enough to search safely?

## Implementation Notes

### Write The Validator Earlier Than Usual

For many constructive tasks, a validator is more useful than a second implementation.

Check:

- domain correctness
- per-step legality
- final constraints
- duplicate / missing elements
- exact counts when the statement asks for them

If the problem accepts many outputs, comparing against one reference output is usually the wrong test.

### Separate Skeleton From Residual Logic

Good constructive code often has two layers:

1. build the canonical skeleton
2. handle the residual freedom

This separation makes proofs and debugging much easier.

Examples:

- alternating core first, monotone tail second
- fixed core first, BFS on two free coins second

### Deterministic Output Helps Debugging

Even when "any answer" is accepted, prefer deterministic tie-breaking if possible.

Benefits:

- reproducible failures
- smaller diffs between versions
- easier reasoning about boundary cases

### Assert Legality In LOCAL Mode

Constructive solutions are excellent candidates for local assertions:

- permutation uses each value exactly once
- every printed move is legal before you append it
- counts of created features match the target
- the final object passes the same validator you would trust in debugging

That fits naturally with [Algorithm Engineering](../algorithm-engineering/README.md) and [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md).

### Do Not Over-Solve

This is the most common constructive mistake:

- the statement gives a friendly promise
- you ignore it
- then you build machinery for the harder general problem

Whenever a constructive proof feels too complicated, ask:

- which promise am I still failing to use directly?

## Practice Archetypes

- `warm-up`: one explicit pattern with exact local features
  - [Build the Permutation](../../../practice/ladders/advanced/constructive/buildthepermutation.md)
  - why it belongs here: the whole answer is one alternating core plus one safe tail
- `core`: one promise-driven search where only a tiny residual remains free
  - [VMCOINS](../../../practice/ladders/advanced/constructive/vmcoins.md)
  - why it belongs here: the heavy promise about two special coins is what makes the construction tractable
- `stretch`: same topic, different flavor
  - [Constructive ladder](../../../practice/ladders/advanced/constructive/README.md)
  - why it belongs here: it trains the habit of isolating legality, progress, and final validity before trusting output

## References And Repo Anchors

- `Course`
  - [HKOI Training 2016: Constructive Algorithm](https://assets.hkoi.org/training2016/ca.pdf)
  - [Principles of Algorithmic Problem Solving](https://usaco.guide/PAPS.pdf)
- `Reference`
  - [USACO Guide](https://usaco.guide/)
- `Practice`
  - [Codeforces constructive algorithms tag](https://codeforces.com/problemset?tags=constructive+algorithms)
- `Repo anchors`
  - [Constructive ladder](../../../practice/ladders/advanced/constructive/README.md)
  - [Build the Permutation](../../../practice/ladders/advanced/constructive/buildthepermutation.md)
  - [VMCOINS](../../../practice/ladders/advanced/constructive/vmcoins.md)
  - [Algorithm Engineering](../algorithm-engineering/README.md)
  - [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
  - [Local Judge Workflow](../../../notebook/local-judge-workflow.md)
  - [Template Library](../../../template-library.md)

## Related Topics

- [Algorithm Engineering](../algorithm-engineering/README.md): use it when the construction idea is already known, but validation, constants, or trust are now the bottleneck
- [Randomized Algorithms](../randomized-algorithms/README.md): use it when randomness is part of the method itself rather than just a test generator
- [Reasoning](../../foundations/reasoning/README.md): use it for tighter invariant writing and proof hygiene
