# Practice Ladders

Practice ladders are the `focused practice` layer of this repo.

Use a ladder when you already know the rough idea and want enough same-family reps to make recognition and execution stable.

## What This Layer Is For

Use ladders when:

- you want to stay inside one subtopic long enough to stop guessing
- the topic page made sense, but you still need deliberate repetition
- you want a small ordered progression instead of a random judge list

Do **not** use ladders as the first door when:

- syntax or local workflow is still the bottleneck
  next door: [Start Here](../../docs/start-here.md)
- you cannot yet explain why the technique works
  next door: [Learning Areas](../../topics/README.md)
- you want contest-style switching across several families
  next door: [Mixed Rounds](../mixed-rounds/README.md)

## The Default Ladder Loop

The repo-wide default loop is:

1. read one topic page in `topics/`
2. open the matching ladder here
3. solve one anchored repo note
4. compare your solution against the note's `Recognition Cue` and `Problem-Specific Transformation`
5. reopen [Notebook](../../notebook/README.md) or [Build Kit](../../docs/build-kit.md) only if retrieval or implementation is the weak point
6. move to [Mixed Rounds](../mixed-rounds/README.md) or a track playbook only after the family feels stable

## Choose A Ladder

| If you need reps in... | Start with | Representative first note |
| --- | --- | --- |
| C++ workflow and first contest habits | [Foundations -> C++ Language](foundations/cpp-language/README.md) | [Weird Algorithm](foundations/cpp-language/weirdalgorithm.md) |
| bread-and-butter array patterns | [Foundations -> Prefix Sums](foundations/prefix-sums/README.md) | [Static Range Sum Queries](foundations/prefix-sums/staticrangesumqueries.md) |
| ordered scans and greedy matching | [Foundations -> Two Pointers](foundations/two-pointers/README.md) | [Apartments](foundations/two-pointers/apartments.md) |
| connectivity and offline unions | [Data Structures -> DSU](data-structures/dsu/README.md) | [C11XU](data-structures/dsu/c11xu.md) |
| range queries and updates | [Data Structures -> Fenwick Tree](data-structures/fenwick-tree/README.md) | [CVP00001](data-structures/fenwick-tree/cvp00001.md) |
| state design over subsets or sequences | [DP -> Bitmask DP](dp/bitmask-dp/README.md) | [VMMARBLE](dp/bitmask-dp/vmmarble.md) |
| trees, paths, and graph structure | [Graphs -> LCA](graphs/lca/README.md) or [Graphs -> Tree DP](graphs/tree-dp/README.md) | [Company Queries II](graphs/lca/companyqueries2.md) or [VOSTRIP](graphs/tree-dp/vostrip.md) |
| string matching and reuse of prefix structure | [Strings -> KMP](strings/kmp/README.md) or [Strings -> Trie](strings/trie/README.md) | [String Matching](strings/kmp/stringmatching.md) or [Word Combinations](strings/trie/wordcombinations.md) |
| geometric predicates and polygon basics | [Geometry -> Vector And Orientation](geometry/vector-orientation/README.md) | [Point Location Test](geometry/vector-orientation/pointlocationtest.md) |
| advanced modeling / olympiad-style construction | [Advanced -> Constructive](advanced/constructive/README.md) | [Build the Permutation](advanced/constructive/buildthepermutation.md) |

## What To Do Inside One Ladder

Use the same rhythm for every mature ladder:

1. read the ladder page to see scope, entry gate, and nearby topics
2. solve the first note with an honest no-notes attempt
3. read only the note sections that reveal the transformation you missed
4. write or clean one reusable solution
5. move to the next note only after the cue and invariant feel transferable

## Exit Doors

When a ladder exposes a weakness, use the smallest next door:

| If the problem is... | Reopen |
| --- | --- |
| I still do not trust the idea | the matching tutorial in [topics/](../../topics/README.md) |
| I know the idea but my code drifts | [Build Kit](../../docs/build-kit.md) |
| I know the family and need more reps | [Problem Finder](../../docs/problem-finder.md) |
| I know several ladders and switch badly | [Mixed Rounds](../mixed-rounds/README.md) |
| I am now training toward one format | [Contest Playbooks](../contest-playbooks/README.md) |

## Representative Ladder Doors

- [Foundations -> Sorting](foundations/sorting/README.md)
- [Data Structures -> Segment Tree](data-structures/segment-tree/README.md)
- [DP -> Interval DP](dp/interval-dp/README.md)
- [Graphs -> Shortest Paths](graphs/shortest-paths/README.md)
- [Graphs -> Flow](graphs/flow/README.md)
- [Strings -> Suffix Automaton](strings/suffix-automaton/README.md)
- [Geometry -> Sweep Line](geometry/sweep-line/README.md)
- [Advanced -> Randomized Algorithms](advanced/randomized-algorithms/README.md)

## Ladder Contract

Every mature ladder should make these things easy to answer:

- what this subtopic is really for
- which repo notes are the best first anchors
- which topic page to reopen when the idea is still fuzzy
- which template or notebook page helps when implementation is the weak point
- where to go next after the ladder is no longer the bottleneck
