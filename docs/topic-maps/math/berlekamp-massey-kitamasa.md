# Math -> Berlekamp-Massey / Kitamasa

Recover the shortest linear recurrence from a prefix when needed, then jump to the k-th term by characteristic-polynomial reduction instead of dense matrix powers.

- Topic slug: `math/berlekamp-massey-kitamasa`
- Tutorial page: [Open tutorial](../../../topics/math/berlekamp-massey-kitamasa/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/berlekamp-massey-kitamasa/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `2`

## Microtopics

- berlekamp-massey
- kitamasa
- linear-recurrence-jump
- characteristic-polynomial
- discrepancy-update
- kth-term

## Learning Sources

| Source | Type |
| --- | --- |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |
| [Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-031-61794-2) | `Reference` |
| [Library Checker K-th Term of Linearly Recurrent Sequence](https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Find Linear Recurrence](https://judge.yosupo.jp/problem/find_linear_recurrence) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Berlekamp-Massey / Kitamasa hot sheet](../../../notebook/berlekamp-massey-kitamasa-hot-sheet.md) | `quick reference` |
| [Linear Recurrence tutorial](../../../topics/math/linear-recurrence/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [K-th Term of Linearly Recurrent Sequence](https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence) | `Library Checker` | `Hard` | Linear Recurrence | Math; Algebra; Implementation | Modular Arithmetic; Linear Recurrence Modeling | Characteristic Polynomial; K-Th Term | The clean first verifier where the recurrence is already known and the whole point is to trust the O(d^2 log k) jump instead of a dense matrix. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Find Linear Recurrence](https://judge.yosupo.jp/problem/find_linear_recurrence) | `Library Checker` | `Hard` | Berlekamp-Massey, Linear Recurrence | Math; Algebra; Implementation | Modular Arithmetic; Discrepancy Updates | Minimal Recurrence; Sequence Recovery | The natural sibling verifier where recurrence recovery itself is the task before any future Kitamasa-style jump. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `KTHTERMOFLINEARLYRECURRENTSEQUENCE` | K-th Term of Linearly Recurrent Sequence | `primary` | `hard` | - | [Note](../../../practice/ladders/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
