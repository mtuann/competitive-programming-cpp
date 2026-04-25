# Eertree / Palindromic Tree

This topic is about the string structure that treats:

- **each distinct palindrome**
- **its longest proper palindromic suffix**
- **the current longest palindromic suffix of the processed prefix**

as the main objects.

That worldview is different from the neighboring palindrome lane:

- [Palindromes / Manacher](../palindromes/README.md) is about odd/even radii in one static string
- `Eertree` is about the **dictionary of distinct palindromic substrings** as one string grows left to right

For contest work, this matters because some palindrome tasks are not really asking:

- "what is the longest palindrome?"

They are asking:

- how many **distinct** palindromes exist?
- what is the longest palindromic suffix after each append?
- can we run DP or counting over the set of distinct palindromes?

That is where `Eertree` becomes the clean exact lane.

## At A Glance

- **Use when:** one string is processed left to right and you need a node-level structure over distinct palindromic substrings
- **Core worldview:** every node is one distinct palindrome, and suffix links organize palindromes by longest proper palindromic suffix
- **Main tools:** two roots, suffix-link walk, extend-by-character transitions, `last` = longest palindromic suffix of the current prefix
- **Typical complexity:** `O(n)` total for one lowercase string in the repo starter
- **Main trap:** mixing up "palindromic suffix of the current prefix" with "arbitrary palindrome anywhere in the string"

Strong contest signals:

- "after each appended character, report how many distinct palindromes exist"
- "maintain longest palindromic suffix while scanning one string"
- "build one structure with one node per distinct palindrome"
- "Manacher gives radii, but the task really wants the palindrome dictionary itself"

Strong anti-cues:

- the string is static and the whole task is just longest palindrome or raw radius arrays -> [Palindromes / Manacher](../palindromes/README.md)
- the real task is many arbitrary substring-palindrome checks -> compare [String Hashing](../hashing/README.md)
- the core structure is "all substrings" rather than "all distinct palindromic substrings" -> compare [Suffix Automaton](../suffix-automaton/README.md)

The repo's exact first route for this family is:

- starter -> [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp)
- flagship note -> [Distinct Palindromic Substrings](../../../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md)
- compare point -> [Palindromes / Manacher](../palindromes/README.md)

## Prerequisites

- [Strings overview](../README.md)
- [Palindromes / Manacher](../palindromes/README.md) only as the nearby "static scan" compare point

Helpful neighboring topics:

- [Suffix Automaton](../suffix-automaton/README.md): also one node per substring-equivalence object, but for **all substrings**, not just palindromes
- [String Hashing](../hashing/README.md): useful compare point when the task is about substring checks rather than a persistent palindrome structure

## Problem Model And Notation

Let:

$$
s = s_0 s_1 \dots s_{n-1}
$$

be processed from left to right.

An `Eertree` stores one node for each **distinct nonempty palindromic substring** of the processed prefix, plus two special roots:

- odd root with length `-1`
- even root with length `0`

Each ordinary node `v` stores:

- `len[v]`: palindrome length
- `link[v]`: the node of the longest proper palindromic suffix of `v`
- `next[v][c]`: the palindrome `c + pal(v) + c` if it exists in the processed string

The critical live pointer is:

- `last`: node of the longest palindromic suffix of the current processed prefix

That pointer is the whole reason updates stay fast:

- new palindromes are always found by walking suffix links from the current longest suffix palindrome

## From Brute Force To The Right Idea

### Brute Force

Suppose characters are appended one by one and after each append we want:

- the number of distinct palindromic substrings in the current prefix

The brute-force route is ugly:

1. enumerate all suffixes ending at the new position
2. test which are palindromes
3. deduplicate them against everything already seen

That is already too slow for `n = 10^5`.

### The Structural Observation

When a new character is appended, any new palindrome must:

- end at the new position

So the search space is not "all palindromes in the string."

It is:

- palindromic suffixes of the new prefix

Even better:

- there can be **at most one new distinct palindrome** after one append

That is the key contest fact behind the whole structure.

So the update problem becomes:

- find the longest suffix palindrome that can be extended by the new character
- either move to an existing transition or create exactly one new node

### Why Suffix Links Are The Right Search Order

Suppose `last` is the longest palindromic suffix of the current prefix before appending the new character.

If that palindrome cannot be extended by the new character on both ends, then the next best candidate is:

- its longest proper palindromic suffix

That is exactly `link[last]`.

So the correct search order is:

- follow suffix links until extension becomes possible

This is the palindrome analogue of failure-link fallback in automaton-style string structures.

## Core Invariant And Why It Works

### 1. Two Roots Remove Boundary Special Cases

The odd root has length `-1`.

The even root has length `0`.

Together they guarantee that the suffix-link walk always bottoms out in a state where extension logic is well-defined.

This is why the update loop does not need many separate edge cases for:

- empty palindrome
- first character
- odd versus even start

### 2. Each Node Is One Distinct Palindrome

This is the core semantic contract:

```text
node <-> one distinct palindrome string
```

So:

- number of ordinary nodes = number of distinct palindromic substrings

That makes counting distinct palindromes trivial once the tree is maintained correctly:

```text
answer = node_count - 2
```

### 3. `last` Is The Longest Palindromic Suffix Of The Current Prefix

After processing prefix `s[0..i]`, `last` points to the longest palindrome that is also a suffix of that prefix.

This matters because the only palindromes worth checking after appending `s[i+1]` are on the suffix-link chain of `last`.

So `last` is not just one convenience pointer.

It is the update frontier.

### 4. `link[v]` Jumps To The Next Best Extendable Candidate

If palindrome `v` cannot be extended by the new character, the next candidate is:

- the longest proper palindromic suffix of `v`

That is exactly `link[v]`.

So the suffix-link walk is the natural descending chain of candidate suffix palindromes.

### 5. Why At Most One New Node Appears Per Append

After the suffix-link walk finds the first extendable palindrome:

- if the transition by the new character already exists, no new distinct palindrome is created
- otherwise, that transition creates the unique new longest palindromic suffix, so exactly one new node is added

This is why the structure stays linear in size:

- at most one ordinary node per processed character

Hence a string of length `n` has at most `n` distinct nonempty palindromic substrings, and the Eertree has at most `n + 2` nodes including the roots.

## Worked Examples

### Example 1: Prefix Counts Of Distinct Palindromes

This repo's flagship note:

- [Distinct Palindromic Substrings](../../../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md)

String:

```text
aba
```

Prefix by prefix:

- `a` -> distinct palindromes: `{a}` -> `1`
- `ab` -> `{a, b}` -> `2`
- `aba` -> `{a, b, aba}` -> `3`

This is the cleanest first benchmark because:

- the structure is append-only
- every update is visible
- the answer is literally `nodes - 2`

### Example 2: Why Manacher Is Not The Same Task

For one static string:

- `Manacher` gives all odd/even radii

But if the real question is:

- "how many distinct palindromes exist so far after each append?"

then raw center radii are the wrong object.

The task wants the **set of distinct palindromes**, not just maximal radii around centers.

That is the Eertree worldview.

### Example 3: Relation To Suffix Automaton

In [Suffix Automaton](../suffix-automaton/README.md):

- each state represents an endpos-equivalence class of substrings

In `Eertree`:

- each node represents one exact distinct palindrome

So both are online substring structures, but they compress different worlds:

- suffix automaton -> all substrings
- Eertree -> only palindromic substrings

## Variant Chooser

### Use Manacher When

- the string is static
- you need longest palindrome or all odd/even center radii
- the answer comes straight from one scan of center information

That is the lane of [Palindromes / Manacher](../palindromes/README.md).

### Use Eertree When

- the string grows left to right
- you need distinct palindromes, palindromic suffix structure, or one node per distinct palindrome
- the update story is "append one character, then update palindrome state"

That is the lane of this page.

### Use String Hashing When

- the task is many substring-palindrome checks or comparisons
- you do not need to maintain the dictionary of distinct palindromes itself

### Use Suffix Automaton When

- the core object is all substrings, not just palindromes
- you need generic substring counting or occurrence aggregation

## Complexity And Tradeoffs

For one lowercase string processed left to right:

- total nodes: `O(n)`
- total suffix-link walk work: `O(n)` in the standard contest implementation
- total build: `O(n)`

Tradeoffs:

- perfect for distinct-palindrome structure and append-only updates
- not the easiest tool if the whole task is just longest palindrome
- not a direct fit for arbitrary substring queries or range updates

## Starter Fit

The starter in this repo is intentionally narrow:

- lowercase English letters
- one string built by repeated appends
- `add_char`
- `build`
- `distinct_palindrome_count`
- `longest_suffix_length`
- `prefix_distinct_counts`

That exact route is enough for:

- per-prefix distinct-palindrome counts
- longest palindromic suffix tracking
- many first Eertree practice problems

If the task needs more, treat the starter as the spine and extend carefully:

- occurrence propagation
- DP on suffix-link tree
- richer node metadata

## Common Pitfalls

- forgetting the two-root setup and then drowning in parity edge cases
- walking suffix links from the wrong starting node
- confusing "palindrome ending at the current position" with "any palindrome somewhere in the string"
- assuming every append creates a new palindrome node
- overusing Eertree when `Manacher` already solves the static version more simply

## Repo Routes

- exact starter -> [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp)
- quick recall -> [Eertree hot sheet](../../../notebook/eertree-hot-sheet.md)
- flagship note -> [Distinct Palindromic Substrings](../../../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md)
- compare static route -> [Palindromes / Manacher](../palindromes/README.md)
- compare all-substrings route -> [Suffix Automaton](../suffix-automaton/README.md)

## References

- [Rubinchik and Shur, *EERTREE: An Efficient Data Structure for Processing Palindromes in Strings*](https://arxiv.org/abs/1506.04862)
- [Timus 1960 - Palindromes and Super Abilities](https://acm.timus.ru/problem.aspx?num=1960&space=1)
- [Library Checker - Eertree](https://judge.yosupo.jp/problem/eertree)
