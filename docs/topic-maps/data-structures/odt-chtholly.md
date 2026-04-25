# Data Structures -> ODT / Chtholly

Ordered-set interval partition for piecewise-constant arrays where range assign keeps collapsing runs and range walks are acceptable.

- Topic slug: `data-structures/odt-chtholly`
- Tutorial page: [Open tutorial](../../../topics/data-structures/odt-chtholly/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/odt-chtholly/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- split
- interval-partition
- range-assign
- piecewise-constant
- kth-over-runs
- expected-complexity

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki ODT](https://oi-wiki.org/misc/odt/) | `Reference` |
| [Codeforces Round #449 Editorial](https://codeforces.com/topic/56423/en2?mobile=false) | `Reference` |
| [CF896C Willem, Chtholly and Seniorious](https://codeforces.com/problemset/problem/896/C?mobile=true) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CF915E Physical Education Lessons](https://codeforces.com/problemset/problem/915/E) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [ODT / Chtholly hot sheet](../../../notebook/odt-chtholly-hot-sheet.md) | `quick reference` |
| [Willem, Chtholly and Seniorious](../../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md) | `flagship note` |
| [Lazy Segment Tree tutorial](../../../topics/data-structures/lazy-segment-tree/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [896C - Willem, Chtholly and Seniorious](https://codeforces.com/problemset/problem/896/C?mobile=true) | `Codeforces` | `Hard` | Interval-Partition | Data-Structure-Heavy; Implementation; Randomized-Input | Ordered Set Iteration; Split(l) / Split(r + 1); Range Assign | Range Assign; Ordered Set; Expected Complexity; Kth Query | The canonical Chtholly-tree benchmark where split, assign, and interval walks over the current runs are the whole model. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [915E - Physical Education Lessons](https://codeforces.com/problemset/problem/915/E) | `Codeforces` | `Hard` | Interval-Partition | Data-Structure-Heavy; Query-Heavy | Ordered Set Iteration; Range Assign; Current Interval Partition | Range Assign; Piecewise Constant; Interval Counting | A clean deterministic bridge where interval assign and counting over the current partition are the real invariants even without the full CF896C random-data flavor. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `WILLEMCHTHOLLYANDSENIORIOUS` | Willem, Chtholly and Seniorious | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/odt-chtholly/willemchthollyandseniorious.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
