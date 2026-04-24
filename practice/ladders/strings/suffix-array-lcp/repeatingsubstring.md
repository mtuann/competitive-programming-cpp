# Repeating Substring

- Title: `Repeating Substring`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2106](https://cses.fi/problemset/task/2106)
- Main topic: `Strings -> Suffix Array And LCP`
- Secondary topics: `Doubling suffix array`, `Kasai LCP`, `Longest repeated substring`
- Difficulty: `medium`
- Subtype: `Find one longest substring that appears in at least two positions`
- Status: `solved`
- Solution file: [repeatingsubstring.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-array-lcp/repeatingsubstring.cpp)

## Why Practice This

This is one of the cleanest reasons to learn suffix array and `LCP` together.

The brute-force question is about substrings, but the exact structure lives on suffixes:

- every substring is a prefix of some suffix
- a repeated substring is a common prefix of two suffixes
- the longest repeated substring becomes a maximum common prefix query over suffixes

So the problem is a direct drill on the standard suffix-array workflow, not a disguised application.

## Key Idea

Sort all suffixes lexicographically and store their starting indices in the suffix array `sa`.

Now build the `lcp` array where:

```text
lcp[i] = longest common prefix of suffixes sa[i] and sa[i+1]
```

Why is this enough?

If some substring `x` appears at least twice, then there are at least two suffixes that start with `x`. In lexicographic order, all suffixes that start with `x` form one contiguous block. Inside that block, some adjacent pair must still share `x` as a prefix, so the longest repeated substring is exactly the maximum value in the `lcp` array.

That gives a simple plan:

- build suffix array with doubling
- build `lcp` with Kasai
- find the position of the maximum `lcp`
- print that many characters from one of the two suffix starts

If the maximum `lcp` is `0`, there is no repeating substring, so print `-1`.

## Complexity

- suffix array by doubling: `O(n log n)`
- LCP by Kasai: `O(n)`
- total: `O(n log n)`

## Pitfalls / Judge Notes

- The repeated occurrences may overlap; suffix-array/LCP handles that automatically.
- You only need to print **one** longest answer. If several exist, any is accepted.
- Remember that the `lcp` array has length `n - 1`, not `n`.
- If you append a sentinel while building the suffix array, remove its suffix before building `lcp` on the original string.

## Reusable Pattern

- Topic page: [Suffix Array And LCP](../../../../topics/strings/suffix-array-lcp/README.md)
- Practice ladder: [Suffix Array And LCP ladder](README.md)
- Starter template: [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: build suffix order first, then let LCP explain the repeated-structure question.
- This note adds: the exact LCP-based objective for this problem.

## Solutions

- Code: [repeatingsubstring.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-array-lcp/repeatingsubstring.cpp)
