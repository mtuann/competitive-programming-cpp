# Parallel Algorithms Hot Sheet

Use this page when the repo's exact parallel route is:

- one associative scan
- one `work / span` benchmark
- one Blelloch tree
- one sequential simulator that preserves the parallel structure

## Do Not Use When

- the task is just an ordinary sequential prefix sum
- the real topic is SIMD / bitset packing
- the real topic is OpenMP, CUDA, locks, atomics, or runtime scheduling
- the problem needs a full parallel graph / sorting / dynamic-data-structure lane

## Exact Route In This Repo

- read one array
- pad to one power of two with identities
- up-sweep partial sums
- set root to identity
- down-sweep prefixes
- output the first `n` leaves as the **exclusive** scan

## Recognition Cues

- `parallel prefix sum`
- `scan`
- `work-efficient`
- `Brent's theorem`
- `up-sweep / down-sweep`

## Core Invariants

- the operator must be associative
- the exact first route is **exclusive** scan
- `work O(n)` and `span O(log n)` are the real benchmark values
- the repo snippet is a structure-preserving simulator, not a multicore performance claim

## Main Traps

- confusing exclusive scan with inclusive scan
- skipping padding and then hand-waving the tree shape
- treating the route as hardware programming instead of algorithmic breadth
- claiming real speedup from a sequential demo

## Exact Starter In This Repo

- starter -> [`blelloch-exclusive-scan.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/blelloch-exclusive-scan.cpp)
- flagship rep -> [Parallel Prefix Sum Benchmark](../practice/ladders/advanced/parallel-algorithms/parallelprefixsum.md)
- classical sibling -> [Prefix Sums](../topics/foundations/patterns/prefix-sums/README.md)

## Reopen Paths

- full tutorial -> [Parallel Algorithms](../topics/advanced/parallel-algorithms/README.md)
- parent router -> [Advanced overview](../topics/advanced/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)
