# Graphs -> Tree DP

Tree-rooted dynamic programming from local subtree states to rerooting and path decomposition.

- Topic slug: `graphs/tree-dp`
- Tutorial page: [Open tutorial](../../../topics/dp/tree-dp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/tree-dp/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `7`

## Microtopics

- subtree-dp
- rerooting
- independent-set
- tree-knapsack
- diameter-dp
- states-on-rooting

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 6.006 structural DP on trees](https://courses.csail.mit.edu/6.006/fall09/lecture_notes/lecture21.pdf) | `Course` |
| [OI Wiki tree DP](https://en.oi-wiki.org/dp/tree/) | `Reference` |
| [USACO Guide DP on trees](https://usaco.guide/gold/dp-trees) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `Practice` |
| [IOI tasks archive](https://stats.ioinformatics.org/tasks/) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Choosing Capital for Treeland](https://codeforces.com/problemset/problem/219/D) | `Codeforces` | `Medium` | Rerooting, Tree DP On Directed Edges | One Reroot Pass; Edge-Cost Delta | Tree Traversal; Edge Orientation Counts | Directed Tree | Re-rooting the tree changes the inversion count by one edge at a time. |
| [Tree Distances I](https://cses.fi/problemset/task/1132) | `CSES` | `Medium` | Rerooting | Two DFS Passes; Diameter Endpoints | Tree Diameter Intuition; Distance Propagation | Distance | Standard rerooting practice for maximum distance from every node. |
| [Tree Distances II](https://cses.fi/problemset/task/1133) | `CSES` | `Hard` | Rerooting | Subtree Sums; Rerooting Formulas | Subtree Sizes; Distance Sum Identities | Distance Sums; Sum Of Distances | Classic rerooting DP on trees. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p) | `AtCoder DP Contest` | `Medium` | Coloring DP | Bottom-Up DFS; Two-State DP | Rooted Tree; State Design; Modular Arithmetic | Mod Arithmetic | Canonical tree DP where each node keeps take/skip states. |
| [Tree Matching](https://cses.fi/problemset/task/1130) | `CSES` | `Medium` | Matching On Trees | Postorder DFS; Local State Merge | Rooted Tree DP; Independent-Edge Choices | Matching; Matching DP; States | Classic tree DP for maximum matching on a tree. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Subtree](https://atcoder.jp/contests/dp/tasks/dp_v) | `AtCoder DP Contest` | `Hard` | Rerooting | Prefix/Suffix Rerooting; Subtree Products | Rooted Tree; Subtree Aggregation; Modular Arithmetic | Mod Arithmetic; Mod DP; Rooted Tree; Independent Set | The go-to rerooting pattern for answering every root. |
| [Zero Tree](https://codeforces.com/problemset/problem/274/B) | `Codeforces` | `Hard` | Difference Accumulation | Postorder Balancing; Sign-Aware Subtree Merge | Rooted Tree; Subtree Contributions | Greedy | A strong tree DP where subtree balances determine the answer. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VOSTRIP` | VOSTRIP | `primary` | `hard` | tree endpoint pairing; path decomposition; local imbalance formula | [Note](../../../practice/ladders/graphs/tree-dp/vostrip.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-dp/vostrip.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
