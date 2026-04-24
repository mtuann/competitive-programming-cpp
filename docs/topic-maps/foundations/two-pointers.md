# Foundations -> Two Pointers

Exploit monotone movement to replace nested loops with linear scans, sliding windows, or opposite-end sweeps.

- Topic slug: `foundations/two-pointers`
- Tutorial page: [Open tutorial](../../../topics/foundations/patterns/two-pointers/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/two-pointers/README.md)
- Repo problems currently tagged here: `4`
- Repo companion pages: `3`
- Curated external problems: `6`

## Microtopics

- opposite-ends
- sliding-window
- sorted-two-sum
- monotone-window
- amortized-linear
- longest-valid-segment

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide two pointers](https://usaco.guide/silver/two-pointers) | `trusted guide` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces two-pointers tag](https://codeforces.com/problemset?tags=two+pointers) | `problem set` |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Foundations cheatsheet](../../../notebook/foundations-cheatsheet.md) | `quick reference` |
| [DP cheatsheet](../../../notebook/dp-cheatsheet.md) | `adjacent reference` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Playlist](https://cses.fi/problemset/task/1141) | `CSES` | `Medium` | Sliding Window | Implementation-Heavy; Proof-Heavy | Two Pointers; Hash Maps; Window Invariants | Distinctness; Subarrays; Distinct | A clean sliding-window benchmark where the main skill is maintaining the window invariant. |
| [Subarray Sums I](https://cses.fi/problemset/task/1660) | `CSES` | `Medium` | Sliding Window | Implementation-Heavy | Two Pointers; Positive Numbers; Window Sums | Subarrays; Positive-Sums; Positive-Array | A standard positive-array window problem that helps lock in the expand-shrink pattern. |
| [Sum of Two Values](https://cses.fi/problemset/task/1640) | `CSES` | `Medium` | - | Implementation-Heavy | Sorting; Hash Maps; Pair Sums | Pair-Sum; Hash-Map | A common first pair-sum problem that can be solved with either hashing or sorted two pointers. |

### Variants

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Distinct Values](https://cses.fi/problemset/task/3222) | `CSES` | `Medium` | - | Implementation-Heavy | Two Pointers; Frequency Maps; Window Maintenance | Sliding-Window; Frequency-Counting; Distinct-Count | A direct sliding-window variant that reinforces the same pattern with a slightly different output. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Ferris Wheel](https://cses.fi/problemset/task/1090) | `CSES` | `Easy` | - | Greedy-Heavy | Sorting; Two Pointers; Greedy Matching | Pairing | A textbook two-pointer pairing problem that is easy to teach and easy to reuse. |
| [Distinct Values Subarrays](https://cses.fi/problemset/task/3420) | `CSES` | `Medium` | Sliding Window | Proof-Heavy; Implementation-Heavy | Two Pointers; Frequency Counts; Subarray Counting | Distinctness; Distinct-Count | A classic counting-by-window problem that builds strong two-pointer intuition. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `APARTMENTS` | Apartments | `primary` | `easy-medium` | two sorted pointers; tolerance matching; greedy monotone scan | [Note](../../../practice/ladders/foundations/two-pointers/apartments.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/apartments.cpp) |
| `FERRISWHEEL` | Ferris Wheel | `secondary` | `easy-medium` | opposite end pointers; greedy pairing; sorted capacity matching | [Note](../../../practice/ladders/foundations/sorting/ferriswheel.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/sorting/ferriswheel.cpp) |
| `SUMOFTWOVALUES` | Sum of Two Values | `primary` | `medium` | sort and scan; opposite end pointers; index restoration | [Note](../../../practice/ladders/foundations/two-pointers/sumoftwovalues.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/sumoftwovalues.cpp) |
| `TFIELD` | Ruộng bậc thang | `secondary` | `hard` | nested polygons; weighted sliding window; shoelace preprocessing | [Note](../../../practice/ladders/dp/sliding-window/tfield.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/tfield.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
