# Advanced -> Online Algorithms

Competitive analysis for decisions without future knowledge, taught first through deterministic ski-rental threshold policies and then compared against paging and randomized adversaries.

- Topic slug: `advanced/online-algorithms`
- Tutorial page: [Open tutorial](../../../topics/advanced/online-algorithms/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/online-algorithms/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- competitive-ratio
- online-algorithm
- ski-rental
- threshold-policy
- adversarial-future
- paging-compare
- randomized-compare

## Learning Sources

| Source | Type |
| --- | --- |
| [Stanford CS369 notes](https://web.stanford.edu/class/cs369/files/cs369-notes.pdf) | `Course` |
| [MIT OCW lecture note on ski rental](https://ocw.mit.edu/courses/6-854j-advanced-algorithms-fall-2005/resources/lec19_2003/) | `Course` |
| [Princeton COS 521 lecture note](https://faculty.cc.gatech.edu/~ssingla7/courses/Fall20cos521/lec18.pdf) | `Course` |

## Follow-Up Reading

| Source | Type |
| --- | --- |
| [JHU Lecture 24: Online Algorithms](https://www.cs.jhu.edu/~mdinitz/classes/IntroAlgorithms/Fall2021/Lectures/Lecture24/lecture24slides.pdf) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Online Algorithms hot sheet](../../../notebook/online-algorithms-hot-sheet.md) | `quick reference` |
| [Ski Rental note](../../../practice/ladders/advanced/online-algorithms/skirental.md) | `flagship note` |
| [Randomized Algorithms tutorial](../../../topics/advanced/randomized-algorithms/README.md) | `compare point` |
| [Optimization And Duality tutorial](../../../topics/advanced/optimization-and-duality/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Ski Rental Benchmark](https://www.cs.jhu.edu/~mdinitz/classes/IntroAlgorithms/Fall2021/Lectures/Lecture24/lecture24slides.pdf) | `JHU Intro Algorithms` | `Theory` | Competitive Analysis | Competitive Analysis; Theory Benchmark | Threshold Reasoning; Offline Optimum; Adversarial Analysis | Ski Rental; Competitive Ratio; Threshold Policy; Adversarial Future | The canonical first online-algorithms benchmark where the whole lesson is to compare one deterministic threshold policy against the offline optimum. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Online Algorithms Notes: Ski Rental and Paging](https://web.stanford.edu/class/cs369/files/cs369-notes.pdf) | `Stanford CS369` | `Theory` | Paging, Randomized Compare | Lecture Notes; Theory Breadth | Ski Rental; Competitive Ratio; Basic Randomized Algorithms | Competitive Ratio; Randomized Adversary; List Update | A clean follow-up once ski rental clicks and you want the next canonical online examples plus the randomized paging contrast. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SKIRENTAL` | Ski Rental | `primary` | `medium` | - | [Note](../../../practice/ladders/advanced/online-algorithms/skirental.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/online-algorithms/skirental.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
