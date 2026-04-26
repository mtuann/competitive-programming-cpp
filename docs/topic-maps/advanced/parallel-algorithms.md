# Advanced -> Parallel Algorithms

Theory-breadth parallel coverage taught first through work/span reasoning and a Blelloch exclusive-scan simulator over an explicit array.

- Topic slug: `advanced/parallel-algorithms`
- Tutorial page: [Open tutorial](../../../topics/advanced/parallel-algorithms/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/parallel-algorithms/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- parallel-prefix-sum
- blelloch-scan
- work-span
- brents-theorem
- pram
- upsweep-downsweep
- exclusive-scan

## Learning Sources

| Source | Type |
| --- | --- |
| [Blelloch, Prefix Sums and Their Applications](https://www.cs.cmu.edu/afs/cs/academic/class/15451-s14/www/LectureNotes/PrefixSumBlelloch.pdf) | `Course` |
| [MIT 6.854 parallel algorithms notes](https://courses.csail.mit.edu/6.854/16/Notes/n32-parallel.html) | `Course` |
| [CMU 15-210 overview](https://www.cs.cmu.edu/afs/cs/academic/class/15210-f12/www/index.html) | `Course` |

## Follow-Up Reading

| Source | Type |
| --- | --- |
| [Sebastian Wild Unit 7: Parallel Algorithms](https://www.wild-inter.net/teaching/comp526/07-parallel-algorithms) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Parallel Algorithms hot sheet](../../../notebook/parallel-algorithms-hot-sheet.md) | `quick reference` |
| [Parallel Prefix Sum Benchmark](../../../practice/ladders/advanced/parallel-algorithms/parallelprefixsum.md) | `flagship note` |
| [Prefix Sums tutorial](../../../topics/foundations/patterns/prefix-sums/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Parallel Prefix Sum Benchmark](https://www.cs.cmu.edu/afs/cs/academic/class/15451-s14/www/LectureNotes/PrefixSumBlelloch.pdf) | `CMU / Blelloch` | `Theory` | Scan | Theory Benchmark; Simulator | Associativity; Prefix Sums; Tree Reduction | Prefix Sum; Blelloch Scan; Work Span; Pram | The canonical first parallel benchmark for this repo because scan makes the work-vs-span lens concrete without pretending the repo already provides a full multicore runtime. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Parallel algorithms notes: Brent and work-efficient scan](https://courses.csail.mit.edu/6.854/16/Notes/n32-parallel.html) | `MIT 6.854` | `Theory` | Further Theory | Lecture Notes; Theory Breadth | Prefix Sum; Work Span | Brent's Theorem; Work Efficient; Pram; Parallel Prefix | A strong follow-up once the scan route clicks and you want the first serious work-efficient simulation lens instead of only the tree mechanics. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PARALLELPREFIXSUM` | Parallel Prefix Sum Benchmark | `primary` | `medium` | - | [Note](../../../practice/ladders/advanced/parallel-algorithms/parallelprefixsum.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/parallel-algorithms/parallelprefixsum.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
