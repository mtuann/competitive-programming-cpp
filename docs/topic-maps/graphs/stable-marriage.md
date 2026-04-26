# Graphs -> Stable Marriage

Two-sided stable matching under complete strict preferences via Gale-Shapley deferred acceptance, with proposer-optimal output and blocking-pair avoidance.

- Topic slug: `graphs/stable-marriage`
- Tutorial page: [Open tutorial](../../../topics/graphs/stable-marriage/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/stable-marriage/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- stable-matching
- blocking-pair
- deferred-acceptance
- proposer-optimal
- preference-ranks
- two-sided-preferences

## Learning Sources

| Source | Type |
| --- | --- |
| [AMS stable marriage and school choice](https://www.ams.org/publicoutreach/feature-column/fc-2015-03) | `Reference` |
| [CACM stable marriage problem](https://cacm.acm.org/research/the-stable-marriage-problem/) | `Reference` |
| [Stable marriage interdisciplinary review](https://arxiv.org/abs/2103.11458) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker stable marriage problem](https://judge.yosupo.jp/problem/stable_marriage_problem) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Stable Marriage hot sheet](../../../notebook/stable-marriage-hot-sheet.md) | `quick reference` |
| [Stable Marriage starter route](../../../template-library.md) | `starter route` |
| [Stable Marriage note](../../../practice/ladders/graphs/stable-marriage/stablemarriage.md) | `anchor note` |
| [Matching tutorial](../../../topics/graphs/matching/README.md) | `compare point` |
| [Hungarian tutorial](../../../topics/graphs/hungarian-assignment/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Stable Marriage](https://www.ams.org/publicoutreach/feature-column/fc-2015-03) | `Canonical / Gale-Shapley` | `Medium` | Stable Matching, Gale-Shapley | Two-Sided Preferences; Canonical Benchmark | Bipartite Pairing Model; Strict Preferences | Blocking Pair; Deferred Acceptance | The cleanest in-repo flagship route where the whole job is just Gale-Shapley on complete strict preference lists. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Stable Marriage Problem](https://judge.yosupo.jp/problem/stable_marriage_problem) | `Library Checker` | `Medium` | Stable Matching, Gale-Shapley | Verifier-Style Problem; Stable Matching | Deferred Acceptance; Strict Preferences | Verify; Preferences | A natural verifier-style follow-up once the canonical Gale-Shapley route feels routine. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `STABLEMARRIAGE` | Stable Marriage | `primary` | `medium` | - | [Note](../../../practice/ladders/graphs/stable-marriage/stablemarriage.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/stable-marriage/stablemarriage.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
