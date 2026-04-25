# Longest Palindrome

- Title: `Longest Palindrome`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1111](https://cses.fi/problemset/task/1111)
- Secondary topics: `Manacher`, `Odd/even centers`, `Longest palindromic substring`
- Difficulty: `medium`
- Subtype: `Recover one longest palindromic substring from static-string palindrome radii`
- Status: `solved`
- Solution file: [longestpalindrome.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/palindromes/longestpalindrome.cpp)

## Why Practice This

This is the cleanest in-repo anchor for `Manacher`.

The statement asks for exactly one thing:

- the longest palindromic substring of one static string

So the real lesson is not dynamic updates, hash collision tradeoffs, or suffix machinery.

It is simply:

- why every palindrome has an odd or even center
- how `d1` and `d2` capture the maximal radii
- how one linear scan recovers the longest answer

## Recognition Cue

Reach for `Manacher` when:

- the string is static
- the obvious brute force is "expand around every center"
- the task wants longest palindrome or all palindrome radii
- exactness matters, but the full problem is still just one string scan

The strongest smell here is:

- "determine the longest palindromic substring"

That is the textbook first `Manacher` problem.

## Problem-Specific Transformation

Keep two arrays:

- `d1[i]` = odd radius count at center `i`
- `d2[i]` = even radius count at split `i`

Then:

- odd palindrome length at `i` is `2 * d1[i] - 1`
- even palindrome length at `i` is `2 * d2[i]`

So the statement becomes:

- compute all odd/even radii in `O(n)`
- scan those radii once
- recover the best substring bounds

## Core Idea

Run two linear passes:

1. odd centers
2. even centers

Each pass maintains the rightmost palindrome interval found so far.

If a new center lies inside that interval, its mirror center gives a safe starting radius.

Then:

- expand beyond the known boundary if possible
- update the rightmost interval if this palindrome reaches farther

Once all radii are known, the answer is just the maximum among:

- `2 * d1[i] - 1`
- `2 * d2[i]`

with the correct left bound formulas:

- odd -> `i - d1[i] + 1`
- even -> `i - d2[i]`

## Complexity

- odd pass: `O(n)`
- even pass: `O(n)`
- final scan for best bounds: `O(n)`

Total:

$$
O(n)
$$

This fits easily for `n <= 10^6`.

## Pitfalls / Judge Notes

- Even palindromes are centered on a split, not on a character.
- `d1[i]` is not the full length; odd length is `2 * d1[i] - 1`.
- `d2[i]` already counts matched layers, so even length is `2 * d2[i]`.
- The judge accepts any longest palindrome if several exist, so there is no extra lexicographic requirement.

## Reusable Pattern

- Topic page: [Palindromes / Manacher](../../../../topics/strings/palindromes/README.md)
- Practice ladder: [Palindromes ladder](README.md)
- Starter template: [manacher.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp)
- Notebook refresher: [Palindromes hot sheet](../../../../notebook/palindromes-hot-sheet.md)
- Compare points: [String Hashing](../../../../topics/strings/hashing/README.md), [Z-Function](../../../../topics/strings/z-function/README.md)
- This note adds: the direct longest-substring extraction layer on top of the raw odd/even radii arrays.

## Solutions

- Code: [longestpalindrome.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/palindromes/longestpalindrome.cpp)
