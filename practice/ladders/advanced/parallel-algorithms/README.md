# Parallel Algorithms Ladder

## Who This Is For

Use this ladder only when you intentionally want one breadth-first parallel benchmark inside an algorithms repo, not because you expect a normal contest lane with dense judge reps.

## Warm-Up

- state the difference between `work` and `span`
- explain why associativity matters for scan
- explain the difference between **exclusive** and **inclusive** scan

## Core

- Blelloch up-sweep / down-sweep
- exclusive scan on a padded power-of-two tree
- `O(n)` work and `O(log n)` span
- Brent's theorem as the first simulator sanity check

## Repo Anchors

- [Parallel Prefix Sum Benchmark](parallelprefixsum.md)
- [Prefix Sums](../../foundations/prefix-sums/README.md)
- [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md)

## Stretch

- read one note on compaction or list ranking and explain why scan is the primitive underneath
- compare Blelloch scan with Hillis-Steele and explain the `work-efficient` boundary
- explain why real multicore speed still belongs to engineering work, not just the abstract PRAM lens

## Compare Points

- first parallel breadth benchmark -> [Parallel Prefix Sum Benchmark](parallelprefixsum.md)
- same cumulative object in ordinary sequential contest form -> [Prefix Sums](../../foundations/prefix-sums/README.md)
- broader execution-model widening through word packing instead of processors -> [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md)

This ladder is intentionally tiny.

The point is not to transform the repo into a full parallel-computing curriculum.
The point is to keep one source-backed `work / span + scan` lane explicit and honest.

## Exit Criteria

You are ready to move on when you can:

- explain `work` vs `span` cleanly
- derive or simulate the Blelloch exclusive scan route
- say clearly why this repo lane is simulator-first and breadth-only

## External Practice

- [Blelloch, Prefix Sums and Their Applications](https://www.cs.cmu.edu/afs/cs/academic/class/15451-s14/www/LectureNotes/PrefixSumBlelloch.pdf)
- [Sebastian Wild Unit 7: Parallel Algorithms](https://www.wild-inter.net/teaching/comp526/07-parallel-algorithms)
- [MIT 6.854 parallel algorithms notes](https://courses.csail.mit.edu/6.854/16/Notes/n32-parallel.html)

## Tutorial Link

- [Parallel Algorithms](../../../../topics/advanced/parallel-algorithms/README.md)
