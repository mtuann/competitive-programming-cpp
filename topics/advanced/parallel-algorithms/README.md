# Parallel Algorithms

This lane exists as a **textbook-breadth advanced lane**, not as a claim that this repo now teaches full multicore engineering, GPU kernels, or concurrent programming.

The repo's exact first route is intentionally narrow:

- one associative operator
- one array
- one Blelloch scan tree
- one `work / span` lens
- one classical simulator that preserves the parallel structure

That means this page is **not**:

- an OpenMP tutorial
- a CUDA page
- a lock-free data-structures page
- a distributed-systems page
- a full lane for parallel graph algorithms or parallel sorting frameworks

It is the first clean algorithmic route for:

- PRAM-style thinking
- work and span
- Brent's theorem as a sanity lens
- Blelloch up-sweep / down-sweep scan
- one canonical parallel primitive that still fits honestly inside a sequential C++ repo

with [Parallel Prefix Sum Benchmark](../../../practice/ladders/advanced/parallel-algorithms/parallelprefixsum.md) as the flagship benchmark.

This page sits next to:

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md) because scan is the parallel sibling of the ordinary cumulative-sum idea
- [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md) because both lanes broaden the usual scalar execution model, but in very different ways
- [Algorithm Engineering](../algorithm-engineering/README.md) when the real question is wall-clock performance and hardware behavior rather than one clean theoretical primitive

## At A Glance

- **Use when:**
  - you want the first honest breadth benchmark for parallel algorithm design
  - the key lesson is `work O(n), span O(log n)` on an associative scan
  - you want to preserve the shape of a parallel tree computation in a sequential simulator
  - you are comfortable with this being theory-first, not a contest-core weapon
- **Prerequisites:**
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
  - [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md) only as a compare-point sibling
- **Boundary with nearby pages:**
  - use this page when the exact lesson is one PRAM-style scan benchmark with `work / span`
  - use [Prefix Sums](../../foundations/patterns/prefix-sums/README.md) when the job is just ordinary cumulative sums in a sequential contest solution
  - use [Algorithm Engineering](../algorithm-engineering/README.md) when the real problem is cache behavior, profiling, or multicore performance work
- **Strongest cues:**
  - `parallel prefix sum`
  - `scan`
  - `work-efficient`
  - `span`, `depth`, or `Brent's theorem`
  - `up-sweep / down-sweep`
- **Strongest anti-cues:**
  - the problem is simply asking for one ordinary prefix-sum array
  - the real topic is SIMD bit tricks rather than processor-level parallelism
  - the task needs practical threading, synchronization, or hardware APIs
  - the lane would have to pretend a sequential C++ snippet already proves real speedup
- **Success after studying this page:**
  - you can state the difference between `work` and `span`
  - you can explain why scan is the first canonical parallel primitive
  - you can implement or recognize a Blelloch exclusive scan
  - you know why this repo route is simulator-first and breadth-only

## Problem Model And Notation

The exact starter route in this repo uses:

- one array `a[0..n-1]`
- one associative operator, first fixed to `+`
- identity element `0`
- one **exclusive** scan:

$$
\text{out}[i] = \sum_{0 \le j < i} a[j].
$$

So for:

$$
[3,1,7,0,4,1,6,3]
$$

the exclusive scan is:

$$
[0,3,4,11,11,15,16,22].
$$

The exact route pads the array to the next power of two, then runs the classic Blelloch tree:

1. **up-sweep** to build partial sums
2. place identity at the root
3. **down-sweep** to push prefix information back to leaves

On the intended parallel model, this gives:

- `O(n)` work
- `O(log n)` span

The repo's implementation is a **sequential emulator** of that structure.

This is deliberate.

Why:

- it preserves the right algorithmic invariant
- it keeps the lane honest inside a standard C++ repo
- it teaches the first real parallel primitive before any hardware-specific tooling

## Why This Exists Next To Prefix Sums

[Prefix Sums](../../foundations/patterns/prefix-sums/README.md) teaches the sequential route:

- one left-to-right pass
- `O(n)` time
- no special execution model

This page teaches the breadth-first parallel lens:

- the operator must be associative
- the computation is organized as a tree
- the key measures are not just time and memory, but `work` and `span`

So the division of labor is:

- **prefix-sums page:** contest-core sequential cumulative sums
- **parallel-algorithms page:** first PRAM-style scan benchmark with work/span analysis

## Core Route In This Repo

The exact route is:

1. pad to one power-of-two length `m`
2. copy the input into the first `n` leaves and fill the rest with identities
3. run the **up-sweep**:
   - each internal node stores the sum of its two children
4. set the root to identity
5. run the **down-sweep**:
   - left child gets the parent's prefix
   - right child gets `parent_prefix + left_subtree_sum`
6. read the first `n` leaves as the exclusive scan

The exact starter contract is intentionally narrow:

- one operator only: addition
- one array only
- one Blelloch scan tree only
- one exclusive-scan benchmark only

The exact non-promises matter:

- no true multithreading
- no claim of measured parallel speedup
- no full coverage of list ranking, tree contraction, or parallel graph algorithms
- no hardware/runtime API layer

## Core Invariants

### 1. Associativity Is The Real Contract

The tree re-associates the computation.

So the exact route only makes sense because:

$$
(a \oplus b) \oplus c = a \oplus (b \oplus c).
$$

Without associativity, the tree shape changes the result.

### 2. The First Route Is Exclusive Scan

This lane does **not** start with "whatever prefix variant is convenient."

It starts with Blelloch's exclusive route because:

- the root is reset to identity cleanly
- the down-sweep invariant is clearer
- inclusive scan is just one tiny post-step away if needed

### 3. The Repo Route Preserves Structure, Not Hardware Speedup

This repo implementation is sequential.

That must be said directly.

The point is:

- preserve the algorithmic shape
- expose the correct `work / span` benchmark
- keep one parallel-breadth topic concrete

not:

- pretend the snippet alone proves real multicore performance

## Work, Span, And Brent's Theorem

On the intended parallel model:

- `work` = total operations across all processors
- `span` = longest dependency chain

For Blelloch scan on `n` values:

- work = `O(n)`
- span = `O(log n)`

Brent's theorem gives the basic simulator lens:

$$
T_p = O\!\left(\frac{W}{p} + S\right),
$$

where:

- `W` is total work
- `S` is span
- `p` is the processor count

The theorem is not the whole subject, but it is the right first sanity check:

- low span matters
- work-efficiency still matters
- too much parallelism with too much wasted work is not the ideal target

## Worked Example: Parallel Prefix Sum Benchmark

Use [Parallel Prefix Sum Benchmark](../../../practice/ladders/advanced/parallel-algorithms/parallelprefixsum.md).

Take:

$$
[3,1,7,0,4,1,6,3].
$$

The exact repo route computes the **exclusive** scan:

$$
[0,3,4,11,11,15,16,22].
$$

The key checkpoints are:

- after the up-sweep, the root holds the total sum `25`
- after replacing the root with `0`
- the down-sweep propagates the correct prefix before each leaf

That is the first benchmark the lane wants you to reopen quickly.

## Variant Chooser

| Situation | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| one first parallel primitive with clean `work / span` analysis | use this lane | Blelloch scan is exactly the intended benchmark | weak if the real goal is full multicore engineering or GPU kernels |
| one ordinary cumulative-sum array for a contest problem | use [Prefix Sums](../../foundations/patterns/prefix-sums/README.md) | the sequential route is simpler and is the real contest tool | weak if the lesson is specifically parallel structure |
| one huge boolean-state DP row packed into machine words | use [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md) | bitset packing is the real performance idea there | weak if the lesson is processor-level tree parallelism |
| the real question is measured throughput, caches, profiling, or multicore implementation | use [Algorithm Engineering](../algorithm-engineering/README.md) | that page owns practical performance work | weak if the missing piece is still the first PRAM-style benchmark |

## Complexity And Tradeoffs

For input length `n`, after padding to `m = 2^k >= n`:

- intended parallel work = `O(m)`
- intended parallel span = `O(log m)`
- sequential emulator runtime = `O(m)`

The main tradeoff is:

- very honest breadth coverage
versus
- zero pretense that this is already a production parallel runtime

That is why the lane belongs in `advanced` and `breadth`.

## Main Traps

- forgetting that associativity is the real contract
- mixing up **exclusive** and **inclusive** scan semantics
- overclaiming the sequential simulator as a real speed benchmark
- drifting into GPU / threading APIs when the route is still just scan + work/span
- ignoring padding and then reasoning as if the tree structure stayed clean

## Reopen Path

- Topic page: [Parallel Algorithms](README.md)
- Practice ladder: [Parallel Algorithms ladder](../../../practice/ladders/advanced/parallel-algorithms/README.md)
- Starter template: [blelloch-exclusive-scan.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/blelloch-exclusive-scan.cpp)
- Notebook refresher: [Parallel Algorithms hot sheet](../../../notebook/parallel-algorithms-hot-sheet.md)
- Compare points:
  - [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
  - [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md)
  - [Parallel Prefix Sum Benchmark](../../../practice/ladders/advanced/parallel-algorithms/parallelprefixsum.md)

## References And Practice

- [Blelloch, Prefix Sums and Their Applications](https://www.cs.cmu.edu/afs/cs/academic/class/15451-s14/www/LectureNotes/PrefixSumBlelloch.pdf)
- [MIT 6.854 parallel algorithms notes](https://courses.csail.mit.edu/6.854/16/Notes/n32-parallel.html)
- [CMU 15-210 Parallel & Sequential Data Structures and Algorithms overview](https://www.cs.cmu.edu/afs/cs/academic/class/15210-f12/www/index.html)
- [Sebastian Wild Unit 7: Parallel Algorithms](https://www.wild-inter.net/teaching/comp526/07-parallel-algorithms)
