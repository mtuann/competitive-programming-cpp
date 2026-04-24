# Randomized Algorithms

Randomized algorithms use random choices as part of the solution method itself.

That is the key boundary of this page:

- using random tests to debug a deterministic solution is **algorithm engineering**
- using randomness inside the judge-facing algorithm is **randomized algorithms**

This page is theory-led. The real payoff is learning to say exactly:

- what is random
- what bad event can happen
- what type of guarantee you are actually claiming
- and how much probability of failure you are willing to spend

## At A Glance

- Use this page when:
  - a randomized choice makes balancing, partitioning, or sampling much simpler than a deterministic design
  - the intended guarantee is expected time or high-probability correctness
  - hashing, treaps, randomized pivoting, or repeated trials appear naturally
  - you can validate or amplify the result if one trial is not trustworthy enough
- Prerequisites:
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Algorithm Engineering](../algorithm-engineering/README.md)
  - [String Hashing](../../strings/hashing/README.md)
- Strongest cues:
  - the editorial says `in expectation`, `with high probability`, or `failure probability`
  - a deterministic version exists, but it is much heavier than the randomized one
  - the clean abstraction is “pick a random priority / pivot / fingerprint / sample”
  - a checker or verifier exists, so retries are realistic
- Strongest anti-cues:
  - there is already a short deterministic solution with the same asymptotic cost
  - the only randomness in sight is the local stress harness, not the actual solver
  - you cannot describe a concrete bad event or probability bound
  - the judge or statement effectively requires exact deterministic behavior and you have no verification layer
  - the real win comes from exploiting a deterministic statement promise to build any valid witness; that belongs under [Constructive](../constructive/README.md)
- Success after studying this page:
  - you can distinguish Monte Carlo from Las Vegas cleanly
  - you can write down the random experiment and the bad event before coding
  - you can budget failure probability across many checks
  - you can decide when randomization is principled and when it is just unfinished deterministic reasoning

## Problem Model And Notation

For an input instance $x$, a randomized algorithm can be viewed as:

$$
A(x; R),
$$

where $R$ is the random tape, seed, or stream of random choices.

Two outputs now matter:

- the returned answer
- the running time

Those lead to two different guarantee styles.

### Monte Carlo

A Monte Carlo algorithm has a bounded running time, but it may return a wrong answer with small probability.

Typical shape:

$$
\Pr[\text{wrong answer on } x] \le \varepsilon.
$$

Examples in contest practice:

- hashing used as a probabilistic equality oracle when the hash parameters are sampled from a random family
- randomized fingerprints for matching or set comparison
- repeated one-sided tests where a false positive or false negative is possible but rare

### Las Vegas

A Las Vegas algorithm is always correct, but the running time is random.

Typical shape:

$$
\Pr[\text{wrong answer on } x] = 0, \qquad \mathbb{E}[T(x; R)] \le f(x).
$$

Examples in contest practice:

- randomized balancing in treaps
- a Monte Carlo filter followed by exact verification
- retry-until-verified schemes when the checker is cheap

### The Three Objects You Must Name

On almost every randomized problem, name these explicitly:

- `random experiment`: what is random?
- `bad event`: what would make the algorithm slow or wrong?
- `budget`: how small must that bad event be?

If you cannot name those three things, the solution is usually not ready.

## From Deterministic Worst Case To The Right Random Model

The naive deterministic instinct is usually one of these:

- balance the structure for every possible insertion order
- choose a pivot that is always “good”
- compare huge objects exactly every time
- fight every adversarial corner case directly

That can be overkill.

The randomized idea is to make the hard global structure look average by injecting one carefully chosen source of randomness.

Typical simplifications:

- **random priorities**:
  a search tree behaves like a random BST instead of the worst insertion order
- **random pivot / partitioning**:
  expected subproblem sizes become easy to bound
- **random fingerprint**:
  comparing large objects becomes cheap, with a tiny error budget
- **random sample / repeated trials**:
  an existence witness is easier to find than to characterize deterministically, and membership can be checked exactly

The key contest move is not:

- “use randomness because I am stuck”

It is:

- “choose one random experiment whose bad event I can actually bound”

## Core Invariant And Why It Works

Randomized correctness still needs structure. The structure is just different from a deterministic invariant.

Every serious randomized solution should answer these four questions.

### Question 1: What Is Random?

Be concrete.

Good answers:

- each node gets an independent random priority
- the pivot is chosen uniformly from the current range
- the base or modulus is sampled once, then fixed
- each trial samples one candidate from a specified distribution

Bad answers:

- “some randomness helps”
- “I shuffled a bit”
- “the hash is random enough somehow”

If you cannot state the experiment precisely, you also cannot prove anything precise about it.

### Question 2: What Bad Event Are You Bounding?

Common bad events:

- the tree becomes too tall
- the pivot split is too unbalanced too many times
- two unequal objects collide under the fingerprint
- every sample misses the witness

The page becomes much cleaner once the proof is written around the bad event instead of around vague luck.

### Question 3: Is The Guarantee About Correctness Or Runtime?

This is where many contest explanations get muddy.

Two very different claims can both sound like “randomized algorithm”:

- `always correct, expected fast`
- `always fast, usually correct`

Write the type explicitly:

- treap: Las Vegas / expected-time data structure
- direct rolling-hash equality with runtime-randomized parameters: Monte Carlo
- hash match followed by exact verification: Las Vegas

### Question 4: How Do You Shrink Failure Probability?

There are only a few standard moves:

- repeat independent trials when success is self-certifying or an exact verifier exists
- use two independent fingerprints instead of one
- verify every candidate before trusting it
- union-bound a per-check failure probability across all checks

Two formulas matter constantly.

If one trial fails with probability at most $p$, then $k$ independent trials all fail with probability at most:

$$
p^k.
$$

If you perform $m$ comparisons, each with failure probability at most $p$, then a crude but useful union bound gives:

$$
\Pr[\text{any failure}] \le mp.
$$

That is often enough for contest budgeting.

## Complexity And Tradeoffs

The main tradeoff is usually:

- much simpler design and code
versus
- only expected-time or high-probability guarantees

Typical patterns:

| Pattern | Typical guarantee | Why people use it | Main risk |
| --- | --- | --- | --- |
| randomized balancing (treap) | expected `O(\log n)` height / operations | much simpler than many deterministic balanced trees | assuming “random” without defining the distribution |
| fingerprinting / hashing | tiny collision probability per comparison | very light and fast equality filter | treating hash equality as proof |
| randomized pivoting | expected good partition sizes | simpler than deterministic median machinery | forgetting adversarial fixed-seed behavior |
| retry with verifier | always correct, random running time | converts a Monte Carlo core into Las Vegas | verifier may be too expensive |

Important contest lesson:

- a randomized algorithm is only as trustworthy as its failure accounting
- if you cannot explain the error budget, the implementation is probably not contest-ready

## Variant Chooser

| Situation | Best first idea | Why it fits | Where it fails |
| --- | --- | --- | --- |
| balanced BST operations are needed but a deterministic self-balancing tree is too heavy | randomized treap / randomized BST | random priorities make the tree shape behave like a random BST | weak if you need deterministic worst-case guarantees |
| many large equality checks dominate | Monte Carlo fingerprinting | one short hash replaces many long comparisons | weak if the problem demands exact proof and no verification is possible |
| candidate matches are few enough to verify exactly | hash or sample first, verify second | the filter stays fast and final correctness becomes exact | weak if the verifier is as expensive as full brute force everywhere |
| partition quality drives runtime | randomized pivot / selection | analysis moves from worst-case arrangement to expected split quality | weak if constants or repeated reseeding are mishandled |
| one trial has a small failure chance but retries are cheap | independent amplification | drives failure probability down exponentially | weak if trials are not really independent or the checker is weak |

## Worked Examples

### Example 1: Treap Priorities Turn Order Into Shape

Suppose keys are inserted in adversarial order:

$$
1, 2, 3, 4, 5, \dots
$$

A plain BST degenerates into a chain.

A treap stores:

- BST order on keys
- heap order on random priorities

Now the key order is fixed, but the tree shape is determined by the random priorities. Equivalently:

- if priorities are independent and ties are negligible or broken consistently, the final treap shape has the same distribution as a plain BST built from the keys in random order

That changes the proof target completely:

- you no longer prove balance for every insertion order
- you prove expected logarithmic depth under the random priority assignment

This is a Las Vegas pattern:

- search results are exact
- updates are exact
- the randomness only affects shape and therefore running time

### Example 2: Hash Equality As Monte Carlo, Then As Las Vegas

Suppose you compare many substrings with one rolling hash whose base or other fingerprint parameters are sampled at runtime and then fixed for the whole run.

If you trust:

$$
\text{hash}(u) = \text{hash}(v)
$$

as immediate equality, then the algorithm is Monte Carlo:

- each comparison is very likely correct
- but collisions are not logically impossible

If instead you do:

1. hash-filter candidate equalities quickly
2. run an exact character-by-character check only on candidates that survive

then the final answer becomes Las Vegas:

- the hash still saves work
- the verifier removes false positives

This is one of the most important mindset shifts in contest randomization:

- the same probabilistic primitive can support either Monte Carlo or Las Vegas behavior depending on the final trust boundary

### Example 3: Randomized Pivoting Avoids Deterministic Worst Cases

Suppose a partition-based algorithm becomes slow only when the pivot is repeatedly terrible.

If each step chooses the pivot uniformly from the current subarray, then the proof target changes:

- you no longer promise a perfect split every time
- you only need to show that sufficiently balanced splits happen often enough in expectation

This is the randomized-pivoting archetype:

- the algorithm is exact
- the randomness controls runtime, not correctness
- the benefit is that you stop fighting the worst fixed input order directly

### Example 4: Amplification With Verifier-Backed Retries

Assume one randomized subroutine returns a candidate witness that passes an exact verifier with probability at least:

$$
\frac{3}{4}.
$$

Then one run fails with probability at most:

$$
\frac{1}{4}.
$$

Run it independently `k` times and accept the first candidate that passes the verifier.

The probability that all runs fail is at most:

$$
\left(\frac{1}{4}\right)^k.
$$

For `k = 5`, that is already:

$$
\frac{1}{1024}.
$$

This is the standard amplification move behind many randomized contest arguments with exact checking:

- make the base trial simple
- then buy confidence by repeating it a few times

## Algorithm And Pseudocode

There is no single randomized template, but there is a standard checklist.

```text
RANDOMIZED_SOLVE(instance I):
    define the random experiment R
    define the bad event B
    decide the guarantee type:
        Monte Carlo  -> bounded time, tiny error probability
        Las Vegas    -> always correct, random running time

    if Monte Carlo:
        budget the total failure probability
        if many checks occur:
            use a stronger fingerprint,
            or amplification only when retries are verifier-backed or otherwise self-certifying

    if a verifier exists:
        consider filter + verify
        this may convert a Monte Carlo core into a Las Vegas algorithm

    implement one RNG policy:
        one generator
        one seed strategy
        no ad hoc reseeding inside hot loops

    document what is random, what can fail, and why the failure budget is acceptable
```

The central question is always:

- am I randomizing the hard part itself,
- or am I only using randomness as a debugging companion?

If it is the second one, the topic probably belongs under [Algorithm Engineering](../algorithm-engineering/README.md), not here.

## Implementation Notes

### Seed Once, Not Everywhere

The common contest pattern is:

- create one RNG
- seed it once
- reuse it for all random choices

Repeatedly reseeding inside hot code often makes behavior less clear, not more random.

### Separate Local Reproducibility From Judge Behavior

In `LOCAL` mode, reproducibility is often more valuable than perfect unpredictability.

Useful habits:

- print or log the seed when chasing a failing run
- keep one easy switch between fixed-seed local debugging and normal contest mode

That is a companion habit, not the proof of the algorithm.

### A Weak Checker Destroys A Strong Randomized Idea

If you rely on `filter + verify`, the verifier becomes part of correctness.

Check that it is:

- exact
- cheaper than full brute force in the intended regime
- applied at the right trust boundary

### Budget Failure Probability Across The Whole Algorithm

Do not only ask:

- what is the chance that one comparison fails?

Also ask:

- how many such comparisons happen?
- do I need a union bound?
- is one hash enough or should I use two?

This is where many “probably fine” solutions become contest-safe.

### Random Testing Is A Companion, Not A Randomized Solution

Generating random test cases and diffing against a brute-force checker is excellent practice.

But that belongs with:

- [Algorithm Engineering](../algorithm-engineering/README.md)
- [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)

It does **not** mean the submitted algorithm itself is randomized.

## Practice Archetypes

- `warm-up`: probabilistic fingerprinting with a very clear trust boundary
  - [Finding Borders](../../../practice/ladders/strings/hashing/findingborders.md)
  - why it belongs here: equal hashes are treated as a probabilistic equality filter, not as a structural proof
- `advanced companion`: randomized structure inside a heavier algorithmic stack
  - [VMWTREE](../../../practice/ladders/graphs/trees/vmwtree.md)
  - why it belongs here: the implicit-treap layer is a genuine randomized data-structure component, but the note itself is still mainly a trees/HLD lesson
- `route hub`: current internal navigation page for this area
  - [Randomized algorithms ladder](../../../practice/ladders/advanced/randomized-algorithms/README.md)
  - why it belongs here: it is the current route entry for the topic, not yet a full solved-note progression

## References And Repo Anchors

- `Course`
  - [MIT OCW 6.856J: Randomized Algorithms](https://ocw.mit.edu/courses/6-856j-randomized-algorithms-fall-2002/resources/lecture-notes/)
  - [Berkeley CS170: Randomization Notes](https://www-inst.cs.berkeley.edu/~cs170/sp20/assets/notes/notes-randomization.pdf)
  - [Stanford CS174: Randomized Algorithms](https://theory.stanford.edu/~trevisan/cs174/)
- `Primary / classic`
  - [Seidel and Aragon: Randomized Search Trees (dblp bibliographic entry)](https://dblp.org/rec/journals/algorithmica/SeidelA96)
  - [Karp papers page: Efficient randomized pattern-matching algorithms](https://www.icir.org/karp/papers.html)
- `Reference`
  - [CP-Algorithms: Treap](https://cp-algorithms.com/data_structures/treap.html)
  - [CP-Algorithms: String Hashing](https://cp-algorithms.com/string/string-hashing.html)
  - [USACO Guide: Hashing](https://usaco.guide/gold/hashing)
- `Repo anchors`
  - [Randomized algorithms ladder](../../../practice/ladders/advanced/randomized-algorithms/README.md)
  - [String Hashing](../../strings/hashing/README.md)
  - [Finding Borders](../../../practice/ladders/strings/hashing/findingborders.md)
  - [VMWTREE](../../../practice/ladders/graphs/trees/vmwtree.md)
- `Implementation companions`
  - [Algorithm Engineering](../algorithm-engineering/README.md)
  - [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
  - [Local Judge Workflow](../../../notebook/local-judge-workflow.md)

## Related Topics

- [Constructive](../constructive/README.md): use it when the hard part is building one witness by exploiting a statement promise, not by randomization
- [Algorithm Engineering](../algorithm-engineering/README.md): use it when randomness only appears in the test harness, benchmark plan, or reproducibility workflow
- [String Hashing](../../strings/hashing/README.md): use it when the real primitive is probabilistic substring equality or fingerprinting
- [Complexity And Hardness](../complexity-and-hardness/README.md): use it when the real question is what class of guarantees is even possible
