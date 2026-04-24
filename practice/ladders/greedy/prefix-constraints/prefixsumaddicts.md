# Prefix Sum Addicts

- Title: `Prefix Sum Addicts`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/1738/B](https://codeforces.com/problemset/problem/1738/B)
- Secondary topics: `Prefix sums`, `Difference reasoning`, `Feasibility check`
- Difficulty: `medium`
- Subtype: `Decide whether a sorted array can match a known suffix of prefix sums`
- Status: `solved`
- Solution file: [prefixsumaddicts.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/prefixsumaddicts.cpp)

## Why Practice This

This is a strong second anchor for the topic because it looks like a prefix-sum reconstruction problem, but the winning move is really greedy feasibility reasoning.

You are not asked to build the whole sorted array. You only need to decide whether one **could** exist.

That shifts the mindset to:

- extract the forced tail values
- check whether they are monotone
- verify that the unknown first block still has enough room to fit

## Recognition Cue

Reach for greedy feasibility on prefix constraints when:

- a sorted hidden sequence is partially described by prefix sums
- only a suffix of those prefix sums is known
- the task is yes/no, not explicit reconstruction

The strongest smell is:

- "known suffix of prefix sums of a sorted array"

That usually means convert the known part to forced differences, then check whether the unknown prefix could still exist.

## Problem-Specific Transformation

The statement is rewritten as:

- consecutive known prefix sums determine the tail values exactly
- the unknown front block only has one aggregate constraint: its total sum

So the task becomes:

- check that the forced tail is nondecreasing
- check that the first block can fit under the next forced value

That is a feasibility argument, not a reconstruction problem.

## Core Idea

Let the given values be:

```text
s[n-k+1], s[n-k+2], ..., s[n]
```

Because the array `a` must be sorted, the consecutive differences of these known prefix sums are forced tail values:

```text
a[n-k+2] = s[n-k+2] - s[n-k+1]
a[n-k+3] = s[n-k+3] - s[n-k+2]
...
```

Those tail values must already be nondecreasing. So if the differences ever go down, the answer is immediately `NO`.

The only remaining uncertainty is the first block of length:

```text
len = n - k + 1
```

Its total sum is `s[n-k+1]`.

Every value in that block must be at most the next known value:

```text
a[n-k+2] = s[n-k+2] - s[n-k+1]
```

So the **largest** possible sum of the first block is:

```text
len * a[n-k+2]
```

If:

```text
s[n-k+1] > len * a[n-k+2]
```

then even the most generous nondecreasing first block cannot reach the required sum, so the answer is `NO`.

Otherwise the answer is `YES`.

Special case:

- if `k = 1`, there is no tail-difference constraint, so the answer is always `YES`

## Complexity

- per test case: `O(k)`
- total across input: linear in the total number of given prefix sums

## Pitfalls / Judge Notes

- The known suffix of prefix sums determines actual array values through **differences**, not through direct comparison of prefix sums themselves.
- The first block check is a capacity upper bound, not an equality construction.
- `k = 1` is always possible.
- Use `long long`; the products in the first-block bound can exceed 32-bit range.

## Reusable Pattern

- Topic page: [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md)
- Practice ladder: [Prefix Constraints ladder](README.md)
- Starter template: [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: when a sorted hidden sequence is constrained by known prefix data, convert the known suffix to differences and check monotonic feasibility first.
- This note adds: the first-block capacity bound `s[first] <= len * next_value`.

## Solutions

- Code: [prefixsumaddicts.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/prefixsumaddicts.cpp)
