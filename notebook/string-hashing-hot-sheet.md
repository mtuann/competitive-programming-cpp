# String Hashing Hot Sheet

Use this page when many substring comparisons are the bottleneck and you want the fastest route back to a safe fingerprint primitive.

## Do Not Use When

- one exact pattern against one text is the real task, so KMP or Z is cleaner
- the solution needs zero-collision certainty from the string primitive itself
- the query count is tiny enough that direct comparison is simpler

## Choose By Signal

- many same-length substring equality checks -> [`rolling-hash.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)
- borders or prefix-suffix equality tests -> string hashing
- binary search on LCP / first mismatch -> string hashing as the comparison primitive
- palindrome queries -> hashing plus reverse-string preprocessing
- one static longest-palindrome scan -> compare [Palindromes hot sheet](palindromes-hot-sheet.md)

## Core Invariants

- `get(l, r)` is meaningful as a same-length substring fingerprint
- prefix hashes plus powers are the string analogue of prefix-sum subtraction
- equal hashes are evidence, not proof, unless the overall solution adds verification or can tolerate collision risk
- the repo starter uses unsigned-64 overflow, not a modular double-hash interface

## Main Traps

- comparing fingerprints of different-length substrings as if length did not matter
- forgetting that collisions are still possible
- reaching for hashing when KMP or Z already gives an exact simpler route
- copying the u64 starter into an adversarial-proof setting without a verification story

## Exact Starters In This Repo

- same-length substring fingerprints -> [`rolling-hash.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)
- flagship repo note -> [Finding Borders](../practice/ladders/strings/hashing/findingborders.md)
- compare exact static palindrome route -> [Palindromes hot sheet](palindromes-hot-sheet.md)
- compare exact tools first -> [String cheatsheet](string-cheatsheet.md)

## Reopen Paths

- collision model, `get(l, r)`, and chooser boundaries -> [String Hashing](../topics/strings/hashing/README.md)
- neighboring exact families -> [String cheatsheet](string-cheatsheet.md)
- template map -> [Template Library](../template-library.md)
