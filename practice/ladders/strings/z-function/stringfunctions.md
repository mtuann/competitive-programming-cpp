# String Functions

- Title: `String Functions`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2107](https://cses.fi/problemset/task/2107)
- Secondary topics: `Prefix function`, `Borders`, `Prefix structure diagnostics`
- Difficulty: `easy`
- Subtype: `Compute both the Z array and the prefix-function of one string`
- Status: `solved`
- Solution file: [stringfunctions.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/z-function/stringfunctions.cpp)

## Why Practice This

This is a great bridge problem between the `Z` viewpoint and the `KMP / prefix-function` viewpoint. The task is not hidden inside a bigger application, so you can focus directly on what each array means and how the linear invariants differ.

## Recognition Cue

Reach for this diagnostic note when:

- you want to compare `Z` and `prefix-function` on the same string
- the value is in understanding what each array means, not in one outer application

The strongest smell is:

- "compute both arrays for the same string"

That is a direct chance to compare the two linear invariants side by side.

## Problem-Specific Transformation

The statement is rewritten as two independent primitives:

- compute the Z-array
- compute the prefix-function

So the problem is not about solving a higher-level task. It is about making sure you can implement and interpret both arrays correctly, under the same input and output conventions.

## Core Idea

The problem asks for two arrays on the same string:

- `z[i]`: longest prefix match starting at position `i`
- `pi[i]`: longest proper prefix that is also a suffix ending at position `i`

For the Z-function, maintain the current interval `[l, r)` such that:

```text
s[l..r) = s[0..r-l)
```

If `i < r`, then the position mirrored inside that interval already tells us a lower bound on `z[i]`. We only need fresh character comparisons when extending beyond `r`.

For the prefix-function, maintain `j = pi[i - 1]` and repeatedly fall back through border links until the next character can extend the current border.

The important lesson is that both arrays are linear, but they reuse previous work in different ways:

- Z reuses a best known prefix-match window
- prefix-function reuses the border chain of the previous position

## Complexity

- build Z array: `O(n)`
- build prefix-function: `O(n)`
- total: `O(n)`

## Pitfalls / Judge Notes

- By convention, print `z[0] = 0`.
- Keep Z with a half-open interval `[l, r)` to avoid off-by-one mistakes.
- In the prefix-function loop, the fallback is `pi[j - 1]`, not `pi[j]`.
- The output order for this problem is:
  - Z array
  - prefix-function array

## Reusable Pattern

- Topic page: [Z-Function](../../../../topics/strings/z-function/README.md)
- Practice ladder: [Z-Function ladder](README.md)
- Starter template: [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: the Z-box is a reuse window; know what substring equality it already guarantees.
- This note adds: the exact diagnostic or border logic extracted from the Z-values.

## Solutions

- Code: [stringfunctions.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/z-function/stringfunctions.cpp)
