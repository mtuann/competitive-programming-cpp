# Data Structures -> X-Fast / Y-Fast Tries

Bounded-universe integer ordered-set family where x-fast stores all prefixes for doubly-logarithmic predecessor / successor search, and y-fast refines the family with sampled representatives and balanced buckets.

- Topic slug: `data-structures/x-fast-y-fast-tries`
- Tutorial page: [Open tutorial](../../../topics/data-structures/x-fast-y-fast-tries/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/x-fast-y-fast-tries/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- bounded-universe
- prefix-hashing
- deepest-existing-prefix
- leaf-linked-order
- jump-pointer
- y-fast-buckets

## Learning Sources

| Source | Type |
| --- | --- |
| [Open Data Structures - Data Structures for Integers](https://opendatastructures.org/newhtml/ods/latex/integers.html) | `Reference` |
| [Open Data Structures (C++) PDF](https://opendatastructures.org/versions/edition-0.1e/ods-cpp.pdf) | `Reference` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [X-Fast / Y-Fast hot sheet](../../../notebook/x-fast-y-fast-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [X-Fast Dictionary note](../../../practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md) | `anchor note` |
| [Binary Trie / XOR Queries tutorial](../../../topics/data-structures/binary-trie-xor/README.md) | `compare point` |
| [PBDS / Order Statistics Tree tutorial](../../../topics/data-structures/pbds-order-statistics/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [X-Fast Dictionary Benchmark](https://opendatastructures.org/newhtml/ods/latex/integers.html) | `Open Data Structures` | `Hard` | X-Fast Trie, Textbook Breadth | Data-Structure-Heavy; Implementation-Heavy | Bounded Universe; Deepest Existing Prefix; Leaf Linked Order | Bounded-Universe; Prefix-Hashing; Predecessor-Successor | A clean breadth benchmark where the whole lesson is bounded-universe predecessor / successor through deepest-existing-prefix search and leaf-linked order, before y-fast bucket sampling is layered in. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `XFASTDICTIONARY` | X-Fast Dictionary | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/x-fast-y-fast-tries/xfastdictionary.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
