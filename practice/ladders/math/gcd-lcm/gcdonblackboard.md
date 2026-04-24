# GCD on Blackboard

- Title: `GCD on Blackboard`
- Judge / source: `AtCoder`
- Original URL: [https://atcoder.jp/contests/abc125/tasks/abc125_c](https://atcoder.jp/contests/abc125/tasks/abc125_c)
- Secondary topics: `Prefix/suffix gcd`, `Remove one element`, `Array gcd`
- Difficulty: `medium`
- Subtype: `Maximize the gcd after replacing one array element arbitrarily`
- Status: `solved`
- Solution file: [gcdonblackboard.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/gcdonblackboard.cpp)

## Why Practice This

This is one of the cleanest first `prefix/suffix gcd` problems:

- the operation sounds strange at first
- but the real quantity is just the gcd of all elements except one

It is a very useful bridge from one-line gcd formulas into array-structure reasoning.

## Recognition Cue

Reach for prefix/suffix gcd when:

- the answer depends on "all elements except one position"
- gcd is associative and easy to combine from left and right aggregates
- recomputing one gcd from scratch for every removed index would be too slow

The strongest smell is:

- "best answer after removing or replacing one element"

That is usually a signal to precompute left and right aggregates.

## Problem-Specific Transformation

The statement sounds like arbitrary replacement, but the reusable rewrite is:

- after choosing index `i`, the best final gcd is exactly the gcd of all elements except `A[i]`

So the problem becomes:

- compute gcd of prefix before `i`
- compute gcd of suffix after `i`
- combine them

That removes the replacement story entirely and turns the task into a classic "all except one" aggregate problem.

## Core Idea

If we replace `A[i]` with any number we like, then the final gcd cannot exceed:

```text
gcd(all elements except A[i])
```

And that bound is actually achievable, because we can replace `A[i]` by exactly that gcd (or any multiple of it).

So the answer is:

```text
max over i of gcd(array without A[i])
```

To compute that quickly:

- `prefix[i]` = gcd of `A[0..i-1]`
- `suffix[i]` = gcd of `A[i..n-1]`

Then the gcd of all elements except `A[i]` is:

```text
gcd(prefix[i], suffix[i + 1])
```

Check every position and take the maximum.

## Complexity

- prefix gcd pass: `O(n log V)`
- suffix gcd pass: `O(n log V)`
- final scan: `O(n log V)`

Overall this is linear in the array size up to gcd cost, and easily fast enough.

## Pitfalls / Judge Notes

- The replacement is arbitrary, so this is not “remove one and keep the rest” by restriction; it becomes equivalent because the replaced number can be chosen to match the target gcd.
- `gcd(0, x) = x` is what makes the prefix/suffix boundary cases clean.
- Do not recompute gcd from scratch for every removed index.

## Reusable Pattern

- Topic page: [GCD And LCM](../../../../topics/math/number-theory-basics/README.md)
- Practice ladder: [GCD And LCM ladder](README.md)
- Starter template: [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: for “all except one” gcd problems, think prefix/suffix aggregates immediately.
- This note adds: the interpretation that arbitrary replacement collapses to “best gcd of the remaining elements”.

## Solutions

- Code: [gcdonblackboard.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/gcdonblackboard.cpp)
