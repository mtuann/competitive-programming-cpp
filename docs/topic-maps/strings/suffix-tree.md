# Strings -> Suffix Tree

Compressed suffix-trie index for one static text, edge-interval matching, and subtree metadata over suffix leaves.

- Topic slug: `strings/suffix-tree`
- Tutorial page: [Open tutorial](../../../topics/strings/suffix-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/suffix-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- compressed-suffix-trie
- ukkonen
- terminator
- edge-intervals
- subtree-minimum
- pattern-walk

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms suffix tree](https://cp-algorithms.com/string/suffix-tree-ukkonen.html) | `Reference` |
| [USACO Guide string suffix structures](https://usaco.guide/adv/string-suffix) | `Reference` |
| [OI Wiki suffix tree](https://en.oi-wiki.org/string/suffix-tree/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Pattern Positions](https://cses.fi/problemset/task/2104) | `Practice` |
| [CSES Distinct Substrings](https://cses.fi/problemset/task/2105/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Suffix Tree hot sheet](../../../notebook/suffix-tree-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Pattern Positions note](../../../practice/ladders/strings/suffix-tree/patternpositions.md) | `anchor note` |
| [Suffix Array And LCP](../../../topics/strings/suffix-array-lcp/README.md) | `compare point` |
| [Suffix Automaton](../../../topics/strings/suffix-automaton/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Pattern Positions](https://cses.fi/problemset/task/2104) | `CSES` | `Hard` | Substring-Index | Many Queries; Suffix Processing | Compressed Edges; Suffix Leaves; Subtree Minimum | Earliest Occurrence; Pattern Matching | The cleanest first verifier for one static text used as a compressed substring index with earliest-occurrence metadata. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Substrings](https://cses.fi/problemset/task/2105) | `CSES` | `Medium` | - | Counting; Suffix Processing | Compressed Edges; Unique Terminator | Distinct Substrings; Compressed Edges | A good compare-point problem once the tree is trusted and you want the usable-edge-length counting view. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PATTERNPOSITIONS` | Pattern Positions | `primary` | `hard` | - | [Note](../../../practice/ladders/strings/suffix-tree/patternpositions.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-tree/patternpositions.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
