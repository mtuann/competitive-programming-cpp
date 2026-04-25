# Data Structures -> Balanced BSTs For Contests

Compare note for AVL, Red-Black, Scapegoat, Size Balanced Tree, and sibling textbook balancing families, explaining when PBDS or treap is still the cleaner contest retrieval route.

- Topic slug: `data-structures/balanced-bsts`
- Tutorial page: [Open tutorial](../../../topics/data-structures/balanced-bsts/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/balanced-bsts/README.md)
- Repo problems currently tagged here: `0`
- Repo companion pages: `6`
- Curated external problems: `3`

## Microtopics

- avl-balance-invariant
- red-black-invariants
- scapegoat-rebuilds
- size-balanced-tree-invariants
- ll-rr-lr-rl-rotations
- deterministic-balanced-bst
- library-style-ordered-container
- rebuild-based-balancing
- size-driven-balancing
- ordered-set-compare
- pbds-vs-treap-vs-avl
- duplicates-via-count

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki AVL](https://oi-wiki.org/ds/avl/) | `Reference` |
| [OI Wiki Red-Black Tree](https://oi-wiki.org/ds/rbtree/) | `Reference` |
| [OI Wiki Scapegoat Tree](https://oi-wiki.org/ds/sgt/) | `Reference` |
| [OI Wiki Size Balanced Tree](https://oi-wiki.org/ds/sbt/) | `Reference` |
| [cppreference std::set](https://en.cppreference.com/w/cpp/container/set) | `Primary` |
| [GCC PBDS manual](https://gcc.gnu.org/onlinedocs/gcc-9.3.0/libstdc%2B%2B/manual/manual/policy_data_structures.html) | `Primary` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369) | `Practice` |
| [SPOJ ORDERSET](https://www.spoj.com/problems/ORDERSET/) | `Practice` |
| [CSES Salary Queries](https://cses.fi/problemset/task/1144) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Balanced BST hot sheet](../../../notebook/balanced-bst-hot-sheet.md) | `quick reference` |
| [PBDS / Order Statistics Tree tutorial](../../../topics/data-structures/pbds-order-statistics/README.md) | `compare point` |
| [Treap / Implicit Treap tutorial](../../../topics/data-structures/treap-implicit/README.md) | `compare point` |
| [Splay Tree tutorial](../../../topics/data-structures/splay-tree/README.md) | `compare point` |
| [Balanced BSTs ladder](../../../practice/ladders/data-structures/balanced-bsts/README.md) | `compare track` |
| [Heaps And Ordered Sets tutorial](../../../topics/data-structures/heaps-and-ordered-sets/README.md) | `adjacent tutorial` |

## Curated External Problems

### Compare

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [ORDERSET - Order Statistic Set](https://www.spoj.com/problems/ORDERSET/) | `SPOJ` | `Medium` | Balanced Bst Compare, Order Statistics | Data-Structure-Heavy; Classic | Ordered Set Invariant; Rank Queries; K-Th Queries | Rank-Query; Kth-Smallest; Compare-Route | Good compare practice after the AVL note because the same interface is often better served by PBDS than by hand-coding deterministic balancing. |
| [Salary Queries](https://cses.fi/problemset/task/1144) | `CSES` | `Medium` | Balanced Bst Compare, Treap Compare | Data-Structure-Heavy; Query-Heavy | Duplicate Counts; Order Statistics; Pair-Key Wrapper | Duplicate-Safe-Wrapper; Range-Count; Compare-Route | A strong compare exercise showing that once split/merge by key or duplicate-safe wrappers matter, treap or PBDS is usually the cleaner in-repo route than AVL. |

### Implementation Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369) | `Luogu` | `Hard` | Avl, Red-Black, Scapegoat, Size-Balanced-Tree, Balanced Bst | Data-Structure-Heavy; Implementation-Heavy | Avl Balance Invariant; Rotations; Duplicate Counts | Rotations; Order-Statistics; Predecessor-Successor | A canonical implementation challenge if you want to hand-code AVL-style, Red-Black-style, Scapegoat-style, or SBT-style balancing and support the textbook ordered-set operation bundle end to end. |

## Repo Problems

_No repo problem note is attached yet. Use the repo companion material above for this theory/process-heavy topic._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
