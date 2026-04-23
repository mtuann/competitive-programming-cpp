# Repo Problem Index

This page lists every current solved problem note in the repo and maps it back to the learning structure.

- Total tracked problem notes: `23`
- Data files: [problem-catalog.json](../data/problem-catalog.json), [repo-problem-catalog.csv](repo-problem-catalog.csv)
- External companion index: [external-problem-index.md](external-problem-index.md)
- Topic maps: [topic-maps/index.md](topic-maps/index.md)
- Recommended use: start from the `Primary topic`, open the `Topic map`, then solve from the linked notes.

## Coverage Snapshot

| Area | Count |
| --- | ---: |
| Data Structures | 2 |
| Graphs | 8 |
| DP | 3 |
| Greedy | 1 |
| Math | 3 |
| Combinatorics | 2 |
| Geometry | 3 |
| Advanced | 1 |

## Current Catalog

### Data Structures

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `C11XU` | Bộ sưu tập đồng xu | `Data Structures -> DSU` | Advanced -> Optimization And Duality | xor-independence; forest selection; augmenting exchange | `hard` | VN SPOJ, OI-style | [Map](topic-maps/data-structures/dsu.md) / [Ladder](../practice/ladders/data-structures/dsu/README.md) / [Tutorial](../topics/data-structures/dsu/README.md) | [Note](../practice/ladders/data-structures/dsu/c11xu.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu/c11xu.cpp) |
| `CVP00001` | Ô ăn quan | `Data Structures -> Fenwick Tree` | Foundations -> Prefix Sums | circular updates; range-add point-query; query-from-initial-state | `hard` | VN SPOJ, OI-style | [Map](topic-maps/data-structures/fenwick-tree.md) / [Ladder](../practice/ladders/data-structures/fenwick-tree/README.md) / [Tutorial](../topics/data-structures/fenwick-tree/README.md) | [Note](../practice/ladders/data-structures/fenwick-tree/cvp00001.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/fenwick-tree/cvp00001.cpp) |

### Graphs

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `FFLOW` | Fast Maximum Flow | `Graphs -> Maximum Flow` | - | maximum flow; undirected capacities; capacity scaling | `medium` | VN SPOJ, ICPC-style | [Map](topic-maps/graphs/flow.md) / [Ladder](../practice/ladders/graphs/flow/README.md) / [Tutorial](../topics/graphs/flow/README.md) | [Note](../practice/ladders/graphs/flow/fflow.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/fflow.cpp) |
| `MCQUERY` | MinCut Query | `Graphs -> Maximum Flow` | Data Structures -> DSU; Graphs -> Trees; Graphs -> Gomory-Hu Tree | all-pairs min-cut; cut tree; count pairs by threshold | `hard` | VN SPOJ, ICPC-style | [Map](topic-maps/graphs/flow.md) / [Ladder](../practice/ladders/graphs/flow/README.md) / [Tutorial](../topics/graphs/flow/README.md) | [Note](../practice/ladders/graphs/flow/mcquery.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mcquery.cpp) |
| `MINCOST` | Luồng với chi phí nhỏ nhất | `Graphs -> Maximum Flow` | Graphs -> Min-Cost Flow | transportation network; flow reconstruction; duplicate-edge overwrite | `hard` | VN SPOJ, ICPC-style | [Map](topic-maps/graphs/flow.md) / [Ladder](../practice/ladders/graphs/flow/README.md) / [Tutorial](../topics/graphs/flow/README.md) | [Note](../practice/ladders/graphs/flow/mincost.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mincost.cpp) |
| `QBFLOWER` | Tặng hoa | `Graphs -> Matching` | - | minimum edge cover; general matching; graph transformation | `medium` | VN SPOJ, OI-style | [Map](topic-maps/graphs/matching.md) / [Ladder](../practice/ladders/graphs/matching/README.md) / [Tutorial](../topics/graphs/matching/README.md) | [Note](../practice/ladders/graphs/matching/qbflower.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/matching/qbflower.cpp) |
| `QOS` | Chất lượng dịch vụ | `Graphs -> Shortest Paths` | DP -> Foundations | shortest path plus dp; kth lexicographic path; bounded slack states | `hard` | VN SPOJ, OI-style | [Map](topic-maps/graphs/shortest-paths.md) / [Ladder](../practice/ladders/graphs/shortest-paths/README.md) / [Tutorial](../topics/graphs/shortest-paths/README.md) | [Note](../practice/ladders/graphs/shortest-paths/qos.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos.cpp) |
| `VOSTRIP` | VOSTRIP | `Graphs -> Tree DP` | DP -> Tree DP; Graphs -> Trees | tree endpoint pairing; path decomposition; local imbalance formula | `hard` | VN SPOJ, OI-style | [Map](topic-maps/graphs/tree-dp.md) / [Ladder](../practice/ladders/graphs/tree-dp/README.md) / [Tutorial](../topics/dp/tree-dp/README.md) | [Note](../practice/ladders/graphs/tree-dp/vostrip.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-dp/vostrip.cpp) |
| `MTREECOL` | Color a tree | `Graphs -> Trees` | - | ratio greedy; tree contraction; exchange argument | `hard` | VN SPOJ, OI-style | [Map](topic-maps/graphs/trees.md) / [Ladder](../practice/ladders/graphs/trees/README.md) / [Tutorial](../topics/graphs/trees/README.md) | [Note](../practice/ladders/graphs/trees/mtreecol.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/mtreecol.cpp) |
| `VMWTREE` | Lại là cây khung | `Graphs -> Trees` | Data Structures -> Segment Tree; Graphs -> Heavy-Light Decomposition | path reverse; path sequence queries; heavy-light decomposition | `hard` | VN SPOJ, OI-style | [Map](topic-maps/graphs/trees.md) / [Ladder](../practice/ladders/graphs/trees/README.md) / [Tutorial](../topics/graphs/trees/README.md) | [Note](../practice/ladders/graphs/trees/vmwtree.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/vmwtree.cpp) |

### DP

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `VMMARBLE` | Phân loại bi | `DP -> Bitmask DP` | Advanced -> Constructive | final-color assignment; residual-state dp; capacity-2 moves | `medium` | VN SPOJ, OI-style | [Map](topic-maps/dp/bitmask-dp.md) / [Ladder](../practice/ladders/dp/bitmask-dp/README.md) / [Tutorial](../topics/dp/bitmask-dp/README.md) | [Note](../practice/ladders/dp/bitmask-dp/vmmarble.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/bitmask-dp/vmmarble.cpp) |
| `VMSCALE` | Chiếc cân kỳ diệu | `DP -> Foundations` | Math -> Number Theory Basics | budget dp; balanced ternary; decision-tree optimization | `hard` | VN SPOJ, OI-style | [Map](topic-maps/dp/foundations.md) / [Ladder](../practice/ladders/dp/foundations/README.md) / [Tutorial](../topics/dp/foundations/README.md) | [Note](../practice/ladders/dp/foundations/vmscale.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/foundations/vmscale.cpp) |
| `TFIELD` | Ruộng bậc thang | `DP -> Sliding Window And Window DP` | Foundations -> Two Pointers; Geometry -> Polygon Area And Point Location | nested polygons; weighted sliding window; shoelace preprocessing | `hard` | VN SPOJ, OI-style | [Map](topic-maps/dp/sliding-window.md) / [Ladder](../practice/ladders/dp/sliding-window/README.md) / [Tutorial](../topics/foundations/patterns/two-pointers/README.md) | [Note](../practice/ladders/dp/sliding-window/tfield.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/tfield.cpp) |

### Greedy

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `VODIVIDE` | Chia phần | `Greedy -> Prefix Constraints` | - | prefix quota greedy; heap maintenance; pair reconstruction | `hard` | VN SPOJ, OI-style | [Map](topic-maps/greedy/prefix-constraints.md) / [Ladder](../practice/ladders/greedy/prefix-constraints/README.md) | [Note](../practice/ladders/greedy/prefix-constraints/vodivide.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/vodivide.cpp) |

### Math

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `POST2` | A cộng B version 2 | `Math -> FFT And NTT` | - | convolution; digit aggregation; big integer addition | `medium` | VN SPOJ, ICPC-style | [Map](topic-maps/math/fft.md) / [Ladder](../practice/ladders/math/fft/README.md) / [Tutorial](../topics/math/fft-ntt/README.md) | [Note](../practice/ladders/math/fft/post2.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/fft/post2.cpp) |
| `CRYPTKEY` | Chìa khóa mã số | `Math -> GCD And LCM` | Math -> Number Theory Basics | gcd-lcm closure; prime-power characterization; constructibility | `hard` | VN SPOJ, OI-style | [Map](topic-maps/math/gcd-lcm.md) / [Ladder](../practice/ladders/math/gcd-lcm/README.md) / [Tutorial](../topics/math/number-theory-basics/README.md) | [Note](../practice/ladders/math/gcd-lcm/cryptkey.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/cryptkey.cpp) |
| `LAMP` | Dàn đèn màu | `Math -> Number Theory Basics` | Math -> GCD And LCM; Combinatorics -> Inclusion-Exclusion | density formula; pairwise coprime products; big integer fractions | `hard` | VN SPOJ, OI-style | [Map](topic-maps/math/number-theory-basics.md) / [Ladder](../practice/ladders/math/number-theory-basics/README.md) / [Tutorial](../topics/math/number-theory-basics/README.md) | [Note](../practice/ladders/math/number-theory-basics/lamp.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/lamp.cpp) |

### Combinatorics

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `VOSFENCE` | Xay hang rao | `Combinatorics -> Bounded Compositions` | Combinatorics -> Counting Basics; Combinatorics -> Inclusion-Exclusion | bounded compositions; run decomposition; gap distribution | `hard` | VN SPOJ, OI-style | [Map](topic-maps/combinatorics/bounded-compositions.md) / [Ladder](../practice/ladders/combinatorics/bounded-compositions/README.md) / [Tutorial](../topics/combinatorics/bounded-compositions/README.md) | [Note](../practice/ladders/combinatorics/bounded-compositions/vosfence.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/bounded-compositions/vosfence.cpp) |
| `VOITSORT` | Cây hoán vị | `Combinatorics -> Lexicographic Enumeration` | Graphs -> Trees | lexicographic enumeration; stack-sortability; cartesian tree view | `hard` | VN SPOJ, OI-style | [Map](topic-maps/combinatorics/lexicographic-enumeration.md) / [Ladder](../practice/ladders/combinatorics/lexicographic-enumeration/README.md) / [Tutorial](../topics/combinatorics/lexicographic-enumeration/README.md) | [Note](../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/lexicographic-enumeration/voitsort.cpp) |

### Geometry

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `PRAVO` | Tam giác vuông | `Geometry -> Right Triangles` | Geometry -> Counting Geometry; Geometry -> Vector And Orientation | count right triangles; normalized directions; perpendicular pairing | `medium` | VN SPOJ, OI-style | [Map](topic-maps/geometry/right-triangles.md) / [Ladder](../practice/ladders/geometry/right-triangles/README.md) / [Tutorial](../topics/geometry/counting-geometry/README.md) | [Note](../practice/ladders/geometry/right-triangles/pravo.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo.cpp) |
| `KINGDOMS` | KINGDOMS | `Geometry -> Sweep Line` | Graphs -> Trees; Geometry -> Polygon Area And Point Location | laminar regions; sweep events; containment tree | `hard` | VN SPOJ, OI-style | [Map](topic-maps/geometry/sweep-line.md) / [Ladder](../practice/ladders/geometry/sweep-line/README.md) / [Tutorial](../topics/geometry/sweep-line/README.md) | [Note](../practice/ladders/geometry/sweep-line/kingdoms.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/kingdoms.cpp) |
| `VOTELPH` | Bà Nà | `Geometry -> Sweep Line` | Geometry -> Polygon Area And Point Location | piecewise maximum; endpoint preprocessing; parabola envelopes | `hard` | VN SPOJ, ICPC-style | [Map](topic-maps/geometry/sweep-line.md) / [Ladder](../practice/ladders/geometry/sweep-line/README.md) / [Tutorial](../topics/geometry/sweep-line/README.md) | [Note](../practice/ladders/geometry/sweep-line/votelph.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/votelph.cpp) |

### Advanced

| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `VMCOINS` | Trò chơi với những đồng xu | `Advanced -> Constructive` | Geometry -> Vector And Orientation | promise-driven constructive; translation matching; small residual search | `hard` | VN SPOJ, OI-style | [Map](topic-maps/advanced/constructive.md) / [Ladder](../practice/ladders/advanced/constructive/README.md) / [Tutorial](../topics/advanced/constructive/README.md) | [Note](../practice/ladders/advanced/constructive/vmcoins.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/constructive/vmcoins.cpp) |

## Maintenance

Regenerate the catalog and topic maps with:

```bash
python3 scripts/generate_problem_catalog.py
```
