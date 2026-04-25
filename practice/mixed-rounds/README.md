# Mixed Rounds

Mixed rounds are for `breadth and retrieval`, not first exposure.

Use them when you already know the basics of several areas and want to practice switching gears under light contest pressure.

Last reviewed against official follow-up pools: `2026-04-24`

## Who This Folder Is For

Use mixed rounds when:

- you can already solve focused ladder problems in several topics
- your bottleneck is recognition and switching, not syntax alone
- you want a short review session or contest-style drill without opening a full contest archive first

Do **not** use this folder as the first place you learn a topic. Go through the corresponding topic page and ladder first.

## Pack Contract

Each pack should say:

- who it is for
- what the entry gate is
- what type of round it is
- what topics are under test
- how many problems it contains
- how long one sitting should take
- what refreshers are allowed
- what the running rules are
- how to debrief afterward
- where to go back next if one slot exposed a weak topic

## How To Run A Pack

Good mixed-round usage looks like this:

1. learn the topic in `topics/`, then stabilize it in its ladder
2. use a mixed round to test retrieval and switching
3. go back to the weakest topic family afterward

Default operating loop:

1. start each slot with an honest no-notes attempt
2. if recognition is still fuzzy after about `10-15 minutes`, allow one notebook or topic refresher
3. if you are still blocked after about `25-30 minutes`, log the missed recognition cue and move on
4. after the full pack, only then read the stored note and code carefully

## Recovery Doors

When one slot exposes a weak point, do not guess where to go next:

- weak topic understanding -> the corresponding deep topic page in [topics/](../../topics/README.md), then the corresponding ladder for that slot
- weak problem selection -> [Problem Finder](../../docs/problem-finder.md)
- weak retrieval of invariant/template -> [Notebook](../../notebook/README.md) or [Template Library](../../template-library.md)
- weak implementation trust or local-testing discipline -> [Build Kit](../../docs/build-kit.md)
- weak contest behavior -> [Contest Playbooks](../contest-playbooks/README.md)

Minimal pack contract:

- `Who This Is For`
- `Entry Gate`
- `Pack Shape`
- `Topics Under Test`
- `Suggested Order`
- `How To Run It`
- `Allowed Refreshers`
- `Debrief`
- `Go Back Next`

## Starter Packs

| If your bottleneck is... | Start with |
| --- | --- |
| first retrieval session after the beginner route | [Stage 0 Review Pack 01](stage0-review-pack-01.md) |
| short-round shipping, anti-hack discipline, and clean CF-style debrief | [Codeforces Short Round 01](codeforces-short-round-01.md) |
| broad contest-core switching | [Contest Core Switching 01](contest-core-switching-01.md) |
| one-machine-style banker prioritization plus implementation stability | [ICPC Breadth And Implementation 01](icpc-breadth-and-implementation-01.md) |
| switching between graph modeling and DP state design | [Graphs And DP Switching 01](graphs-dp-switching-01.md) |
| switching between string processing, modular reasoning, and counting | [Strings, Math, And Counting 01](strings-math-counting-01.md) |
| switching across static, dynamic, offline, and greedy data-structure choices | [Data Structures And Offline 01](data-structures-and-offline-01.md) |
| rooted-tree retrieval keeps drifting between ancestor, DP, and path-query views | [Trees And Queries 01](trees-and-queries-01.md) |

- [Stage 0 Review Pack 01](stage0-review-pack-01.md): first retrieval session after the beginner route
- [Codeforces Short Round 01](codeforces-short-round-01.md): short-round shipping drill with one anti-hack-heavy mid slot and one optional late-slot model
- [Contest Core Switching 01](contest-core-switching-01.md): five-topic contest-core drill
- [ICPC Breadth And Implementation 01](icpc-breadth-and-implementation-01.md): banker-first ICPC-style breadth drill with one late implementation-heavy slot
- [Graphs And DP Switching 01](graphs-dp-switching-01.md): alternate between graph modeling and state design
- [Strings, Math, And Counting 01](strings-math-counting-01.md): pattern matching, modular reasoning, and combinatorial counting in one sitting
- [Data Structures And Offline 01](data-structures-and-offline-01.md): switch across static RMQ, online updates, ordered containers, offline sweeps, and Fenwick-style range aggregation
- [Trees And Queries 01](trees-and-queries-01.md): move between rooted-tree reasoning, ancestor jumps, rerooting, heavy-light decomposition, and a non-DP tree reduction

## Official Follow-Up Pools

Research snapshot: reviewed against official pages on `2026-04-24`.

- [CSES Problem Set](https://cses.fi/problemset): best official follow-up pool when a pack reveals one weak core topic
- [Codeforces Problemset](https://codeforces.com/problemset): best official follow-up pool when a short-round drill reveals one weak `CF` slot you want to replace immediately with another rep
- [USACO Training](https://usaco.org/index.php?page=training): good for slower, lesson-style follow-up after a mixed round exposes a concept gap
- [USACO Training Gateway](https://usaco.training/): legacy training gateway if you want a second official progression path

## Design Rules

- mixed rounds should reinforce already-learned ideas, not introduce brand-new heavy material
- each pack should mix topics on purpose instead of feeling like a random judge list
- every pack should leave the learner with a clear “go back to this topic next” signal
- one pack should usually fit in one sitting
- allowed refreshers should be explicit so the drill stays honest and repeatable

## Choose Your Next Pack

| Bottleneck | Time budget | Start with | If it breaks, go back to |
| --- | --- | --- | --- |
| first retrieval session after the beginner route | `90-120 min` | [Stage 0 Review Pack 01](stage0-review-pack-01.md) | [Foundations ladders](../ladders/foundations/README.md) or [BFS And DFS ladder](../ladders/graphs/bfs-dfs/README.md) |
| short-round shipping, anti-hack, and upsolve discipline | `2-2.5 h` | [Codeforces Short Round 01](codeforces-short-round-01.md) | [Codeforces Playbook](../contest-playbooks/codeforces.md), [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md), [Constructive ladder](../ladders/advanced/constructive/README.md), or [Prefix Constraints ladder](../ladders/greedy/prefix-constraints/README.md) |
| broad contest-core switching | `2.5-3.5 h` | [Contest Core Switching 01](contest-core-switching-01.md) | the weakest corresponding ladder for the failed slot, then [Problem Finder](../../docs/problem-finder.md) |
| banker-first ICPC breadth plus implementation reliability | `3-4 h` | [ICPC Breadth And Implementation 01](icpc-breadth-and-implementation-01.md) | [ICPC Playbook](../contest-playbooks/icpc.md), [Foundations ladders](../ladders/foundations/README.md), [Graphs ladders](../ladders/graphs/README.md), or [Segment Tree ladder](../ladders/data-structures/segment-tree/README.md) |
| graph-modeling vs DP-state reset | `3-4 h` | [Graphs And DP Switching 01](graphs-dp-switching-01.md) | [Graph Modeling](../ladders/graphs/graph-modeling/README.md), [Knapsack Family](../ladders/dp/knapsack-family/README.md), or [Digit DP](../ladders/dp/digit-dp/README.md) |
| symbolic switching across strings, modular arithmetic, and counting | `2.5-3.5 h` | [Strings, Math, And Counting 01](strings-math-counting-01.md) | [KMP](../ladders/strings/kmp/README.md), [Modular Arithmetic](../ladders/math/modular-arithmetic/README.md), or [Counting Basics](../ladders/combinatorics/counting-basics/README.md) |
| data-structure choice keeps drifting between static, dynamic, ordered, and offline | `3-4 h` | [Data Structures And Offline 01](data-structures-and-offline-01.md) | [Sparse Table](../ladders/data-structures/sparse-table/README.md), [Heaps And Ordered Sets](../ladders/data-structures/heaps-and-ordered-sets/README.md), [Offline Tricks](../ladders/data-structures/offline-tricks/README.md), or [Segment Tree](../ladders/data-structures/segment-tree/README.md) |
| rooted-tree queries still feel like separate tricks instead of one family | `3-4 h` | [Trees And Queries 01](trees-and-queries-01.md) | [Trees](../ladders/graphs/trees/README.md), [LCA](../ladders/graphs/lca/README.md), [Tree DP](../ladders/dp/tree-dp/README.md), or [HLD](../ladders/graphs/hld/README.md) |
