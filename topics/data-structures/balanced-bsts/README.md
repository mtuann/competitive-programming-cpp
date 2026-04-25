# Balanced BSTs For Contests

This page is the repo's **balanced-BST compare note**, not a new high-ROI lane.

Its job is to answer one question cleanly:

```text
If I want a self-hosted BST family tool, why does the repo usually teach PBDS or treap first, and where do AVL, Red-Black, Scapegoat, Size Balanced Tree, and Splay fit?
```

The repo policy is deliberate:

- `PBDS / Order Statistics Tree` is the first contest route when rank or `k`-th
  queries are the real invariant
- `Treap / Implicit Treap` is the first self-hosted split/merge family
- `AVL`, `Red-Black`, `Scapegoat`, and `Size Balanced Tree` are usually better
  treated as **compare notes**
- `Splay Tree` gets its own narrow lane only because it directly enables
  [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

So this page exists to keep those textbook families from becoming blind spots
without pretending they deserve equal contest priority.

## At A Glance

- **Use this page when:** you want to understand the balanced-BST family map, or
  you explicitly want to code AVL / Red-Black / Scapegoat / Size Balanced Tree
  as an implementation exercise
- **Core worldview:** pick the tree from the job, not from the fact that it is a
  "balanced BST"
- **Main decision split:** rank / `k`-th -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md),
  split/merge by key or position -> [Treap / Implicit Treap](../treap-implicit/README.md),
  dynamic trees -> [Link-Cut Tree](../../graphs/link-cut-tree/README.md)
- **Main trap:** spending contest time hand-coding AVL when an existing route is
  simpler and safer

## The Family Map

### The Real Jobs In Contests

Most "BST" tasks in CP are actually one of these jobs:

- predecessor / successor / erase-one in one ordered set
- online rank or `k`-th
- split / merge ordered sets by key
- mutable sequence edits by position
- dynamic-tree path queries through splay-based auxiliary trees

That is why this repo routes you to:

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)
- [Persistent Treap](../persistent-treap/README.md)
- [Splay Tree](../splay-tree/README.md)
- [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

before it routes you to textbook balancing variants.

### What AVL Actually Is

AVL is a binary search tree with a stronger local balance invariant:

```text
for every node, height(left) - height(right) is in {-1, 0, +1}
```

That stronger invariant implies:

- worst-case `O(log n)` search
- worst-case `O(log n)` insert
- worst-case `O(log n)` erase

and it is maintained by the classic rotation cases:

- `LL`
- `RR`
- `LR`
- `RL`

So AVL is a perfectly valid way to build:

- one ordered set
- one ordered multiset with counts
- one self-hosted rank / `k`-th tree if you also maintain subtree sizes

## Where AVL Fits Well

AVL is a good fit when:

- you want a **deterministic**, self-hosted balanced BST
- the operation set is still ordinary ordered-set work:
  - insert
  - erase-one
  - predecessor / successor
  - rank / `k`-th if sizes are augmented
- you are deliberately practicing balanced-BST implementation, not minimizing
  contest risk

Good mental model:

```text
AVL is the "strictly balanced ordered-set engine" compare point.
```

## What Red-Black Tree Actually Is

Red-Black Tree is another self-balancing BST, but with a looser invariant than
AVL.

The mental model is:

- every node is `red` or `black`
- the root is black
- no red node has a red child
- every root-to-null path has the same black-height

That looser invariant still gives:

- worst-case `O(log n)` search
- worst-case `O(log n)` insert
- worst-case `O(log n)` erase

but the tree is allowed to be less tightly balanced than AVL.

Good contest-facing mental model:

```text
Red-Black is the "library-style ordered container" compare point.
```

It fits best when you want to understand:

- why `std::set` / `std::map` are commonly implemented with Red-Black-like trees
- why PBDS uses `rb_tree_tag`
- why ordered-set APIs in libraries often look easier to trust than hand-coded
  deterministic balancing

What it usually is **not** in this repo:

- not the first hand-coded ordered-set route
- not the first split/merge route
- not the first dynamic-tree route

So the repo teaches Red-Black mostly as:

- a **compare note**
- a framing tool around PBDS / `std::set`
- a way to understand library-style balancing tradeoffs

## Where Red-Black Fits Well

Red-Black is a good fit when:

- you want a deterministic balanced BST with less strict balancing than AVL
- you care about the library-style ordered-set story more than about split/merge
- you want to reason about why `std::set` and PBDS feel like the natural contest
  default for ordinary ordered-set work

Relative to AVL:

- insert/delete balancing is usually more tolerant
- the tree may be a little taller
- the invariants are less local and less immediately visual than AVL height
  differences

Relative to treap:

- no randomness
- no split/merge-first worldview
- usually more painful to hand-code under contest pressure

So the cleanest way to think about it here is:

```text
AVL = stricter textbook balancing compare point
Red-Black = library-style balancing compare point
```

## What Scapegoat Tree Actually Is

Scapegoat Tree is a self-balancing BST that maintains balance by **rebuilding
whole subtrees** instead of doing small local rotations after every update.

The mental model is:

- search is just ordinary BST descent
- insert / erase track subtree sizes or live sizes
- when a balance criterion fails, find one "scapegoat" ancestor
- flatten and rebuild that subtree into a balanced BST

Good contest-facing mental model:

```text
Scapegoat = rebuild-based deterministic balanced BST compare point.
```

What makes it different from AVL / Red-Black:

- no LL / RR / LR / RL rotation cases to memorize
- balancing is not incremental; it happens through occasional rebuilds
- lazy deletion is common in CP implementations
- subtree-size bookkeeping matters more than color or height bookkeeping

What it fits best for in this repo:

- understanding the rebuild-based branch of balanced BST design
- one deliberate implementation exercise when you want to compare
  rotation-heavy balancing against rebuild-heavy balancing
- seeing why "no rotations" does **not** automatically make it the best contest
  route

What it usually is **not** in this repo:

- not the first ordinary ordered-set route
- not the first rank / `k`-th route when PBDS is available
- not the first self-hosted split/merge route

So the repo teaches Scapegoat mostly as:

- a **compare note**
- a rebuild-based alternative to AVL / Red-Black
- not a default retrieval route

## Where Scapegoat Fits Well

Scapegoat is a good fit when:

- you want a deterministic balanced BST without learning many rotation cases
- you are willing to accept occasional rebuilds as the balancing mechanism
- the learning goal is the design contrast itself, not shortest contest code

Relative to AVL:

- fewer local balancing cases to memorize
- more subtree flatten/rebuild machinery
- less "repair locally", more "rebuild when needed"

Relative to Red-Black:

- easier invariants to explain at a high level
- less library-like and less directly connected to `std::set` / PBDS framing
- still not the default route for rank / `k`-th under time pressure

Relative to treap:

- deterministic instead of randomized
- rebuild-based instead of split/merge-first
- much weaker match for sequence surgery or persistence workflows

So the cleanest way to think about it here is:

```text
AVL = stricter local balancing
Red-Black = library-style balancing
Scapegoat = rebuild-based balancing
```

## What Size Balanced Tree Actually Is

Size Balanced Tree (SBT) is a self-balancing BST whose balancing logic is driven
directly by **subtree sizes**.

The mental model is:

- every node stores subtree size
- size is not only for rank / `k`-th queries, it is also the balancing signal
- rotations are triggered when one side becomes too small relative to certain
  nephew subtrees

Good contest-facing mental model:

```text
SBT = size-driven balancing compare point for ordered-set + order-statistics work.
```

What makes it different from the earlier compare points:

- unlike AVL, balance is not expressed by subtree heights
- unlike Red-Black, balance is not expressed by colors / black-height
- unlike Scapegoat, balance is not repaired by subtree rebuilds
- unlike PBDS, you are still hand-coding the whole structure yourself

What it fits best for in this repo:

- understanding a balanced BST where the augmentation used for rank queries is
  also the balancing signal
- one deliberate implementation exercise if you want to compare "size-guided
  rotations" against AVL height-guided rotations
- seeing why "rank-friendly augmentation" still does not automatically beat the
  repo's first-line routes

What it usually is **not** in this repo:

- not the first rank / `k`-th route when PBDS is available
- not the first self-hosted split/merge route
- not the first balanced BST to learn under contest pressure

So the repo teaches Size Balanced Tree mostly as:

- a **compare note**
- a size-driven counterpart to AVL / Red-Black / Scapegoat
- not a default retrieval route

## Where Size Balanced Tree Fits Well

Size Balanced Tree is a good fit when:

- you want a deterministic balanced BST whose core augmentation is already
  subtree size
- rank / `k`-th is part of the story, and you want to understand a textbook
  self-hosted order-statistics tree
- the learning goal is balanced-BST design space, not shortest contest code

Relative to AVL:

- the balancing signal is size rather than height
- rank / `k`-th augmentation feels more native
- you still pay hand-coded rotation and maintenance cost

Relative to Red-Black:

- easier to connect to order-statistics queries conceptually
- less useful as a framing tool for `std::set` / PBDS internals
- still a weaker contest retrieval route than PBDS itself

Relative to treap:

- deterministic instead of randomized
- not split/merge-first
- much less natural for sequence surgery or persistence work

So the cleanest way to think about it here is:

```text
AVL = height-driven local balancing
Red-Black = color-driven library-style balancing
Scapegoat = rebuild-driven balancing
SBT = size-driven balancing
```

## Why The Repo Still Does Not Teach AVL First

Even though AVL is correct and theoretically clean, it is rarely the best first
contest route.

### 1. PBDS Is Usually Shorter

If the job is:

- one dynamic ordered set
- online rank / `k`-th

then [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md) is
usually the shortest exact route.

### 2. Treap Is Usually More Flexible

If the job is:

- split / merge by key
- sequence surgery by position
- persistence through path copying

then [Treap / Implicit Treap](../treap-implicit/README.md) or
[Persistent Treap](../persistent-treap/README.md) is the cleaner family.

### 3. AVL, Red-Black, Scapegoat, And SBT Still Lose On Retrieval ROI

Compared with treap or PBDS:

- insert/erase code is longer
- delete balancing is easier to get wrong under pressure
- split/merge is not the natural primitive
- Red-Black fix-up logic is harder to recall cleanly than PBDS usage
- AVL fix-up logic is more local but still longer than the repo's first-line
  routes
- Scapegoat rebuild logic is conceptually neat, but it still adds custom
  subtree-flatten/rebuild machinery where PBDS or treap usually gives a more
  direct contest route
- SBT makes rank / `k`-th feel native, but PBDS already gives that exact job
  with drastically lower contest overhead

So the repo teaches AVL / Red-Black / Scapegoat / SBT as:

- a **compare note**
- an implementation exercise
- not the default retrieval route

## Compare Table

| Route | Best when | Why the repo prefers it |
| --- | --- | --- |
| [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md) | one dynamic ordered set with rank / `k`-th | shortest exact contest route when GNU extensions are allowed |
| [Treap / Implicit Treap](../treap-implicit/README.md) | self-hosted split/merge ordered set or mutable sequence | flexible primitives match CP jobs directly |
| `AVL` | deterministic self-hosted ordered set and you deliberately want textbook balancing | solid compare point, but longer code and weaker contest ROI |
| `Red-Black` | library-style ordered containers and PBDS framing | usually hidden behind `std::set` / PBDS instead of hand-coded |
| `Scapegoat Tree` | rebuild-based deterministic balancing experiments | neat compare point, but still weaker retrieval than PBDS / treap for most CP jobs |
| `Size Balanced Tree` | size-driven deterministic order-statistics balancing | elegant compare point for size-based invariants, but still weaker retrieval than PBDS / treap |
| [Splay Tree](../splay-tree/README.md) | self-adjusting ordered sets and direct LCT bridge | taught as a narrow enabling lane, not as the repo's first ordered-set route |

## AVL Implementation Checklist

If you deliberately code AVL, the minimum augmented node story is:

- `key`
- `count` if duplicates matter
- `height`
- `size` if rank / `k`-th is needed
- `left`, `right`

The maintenance steps are:

1. recurse like a BST
2. update `height` and `size`
3. compute the balance factor
4. repair by one of `LL / RR / LR / RL`

Main traps:

- forgetting to update `size` after rotations
- getting duplicate handling wrong on erase-one
- mixing "height" and "balance factor" reasoning during delete
- trying to stretch AVL into split/merge-heavy jobs where treap is the natural fit

## Red-Black Implementation Checklist

If you deliberately code Red-Black by hand, the minimum node story is usually:

- `key`
- `color`
- `count` if duplicates matter
- `size` if rank / `k`-th is needed
- `parent`, `left`, `right`

The maintenance story is:

1. BST insert / erase
2. recolor / rotate through case analysis
3. preserve black-height and no-red-red adjacency
4. keep augmented `size` data consistent through every rotation

Main traps:

- forgetting that delete fix-up is usually the ugly part
- mixing up sentinel/null handling with real-node color logic
- maintaining subtree sizes through rotations and transplants
- hand-coding Red-Black because it "sounds standard" when PBDS already solves
  the exact contest job

## Scapegoat Implementation Checklist

If you deliberately code Scapegoat by hand, the minimum node story is usually:

- `key`
- `count` if duplicates matter
- `size`
- sometimes `live_size` if lazy deletion is used
- `left`, `right`

The maintenance story is:

1. BST insert / erase
2. update subtree sizes on the search path
3. detect a violated balance criterion
4. flatten one subtree in-order
5. rebuild it into a balanced BST

Main traps:

- forgetting that rebuild cost is the whole point, so stale size bookkeeping
  breaks everything
- mixing physical deletion and lazy deletion without a clean policy
- assuming "no rotations" automatically means easier contest code
- reaching for Scapegoat when the real invariant is still just PBDS-style rank
  / `k`-th or treap-style split/merge

## Size Balanced Tree Implementation Checklist

If you deliberately code Size Balanced Tree by hand, the minimum node story is
usually:

- `key`
- `count` if duplicates matter
- `size`
- `left`, `right`

The maintenance story is:

1. BST insert / erase
2. update subtree sizes on the way back
3. test the size-balance inequalities
4. repair with one or two rotations
5. ensure subtree sizes stay correct after every rotation

Main traps:

- forgetting that every balancing decision depends on correct subtree sizes
- mixing duplicate counts with subtree size semantics incorrectly
- assuming "rank support is built in" means the implementation is automatically
  shorter than PBDS
- reaching for SBT when the real job is still split/merge or library-backed
  ordered-set work

## Practice Strategy

If you want to study AVL / Red-Black / Scapegoat / SBT deliberately, do it in
this order:

1. solve one ordinary balanced-tree template task with AVL
2. compare the same task against Red-Black at the invariant level
3. compare rebuild-based Scapegoat against both of them
4. compare size-driven SBT against all of them
5. compare self-adjusting splay against the same ordered-set interface
6. compare the whole family against PBDS or treap
7. decide whether the hand-coded BST route bought you anything

The best first rep is:

- [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369)

but use it as an **implementation challenge**, not as evidence that AVL,
Red-Black, Scapegoat, or SBT should replace the repo's main BST routes.

## Use / Avoid Signals

### Reach For AVL When

- you explicitly want to practice deterministic rotations
- you want to understand textbook balanced BST mechanics better
- the operation set is ordinary ordered-set work, not split/merge work

### Reach For Red-Black When

- you explicitly want to understand the balancing idea behind library-style
  ordered containers
- you want a deterministic ordered-set compare point that is less strictly
  balanced than AVL
- the real learning goal is `std::set` / PBDS framing, not faster contest
  retrieval

### Reach For Scapegoat When

- you explicitly want the rebuild-based balanced BST compare point
- you want to contrast "rebuild whole subtree" against rotation-heavy balancing
- the learning goal is balanced-BST design space, not shortest implementation

### Reach For SBT When

- you explicitly want the size-driven balanced BST compare point
- you want a textbook self-hosted order-statistics tree where `size` is both
  augmentation and balancing signal
- the learning goal is balanced-BST design space, not shortest implementation

### Avoid AVL When

- GNU PBDS is available and the job is just rank / `k`-th
- split/merge by key or sequence position is the real invariant
- persistence or dynamic-tree operations are the actual next stop

### Avoid Red-Black When

- you are under contest pressure and PBDS already solves the exact job
- you need split/merge as first-class primitives
- you only want one hand-coded deterministic BST exercise and AVL already gave
  you that learning signal

### Avoid Scapegoat When

- GNU PBDS already gives the exact ordered-set interface you need
- split/merge or sequence surgery is the real job
- you want one hand-coded deterministic BST and do not care about the rebuild
  design branch specifically

### Avoid SBT When

- PBDS already solves the rank / `k`-th interface you need
- split/merge or sequence surgery is the real job
- you do not specifically care about the "size as balancing signal" design
  branch

## Retrieval Map

- quick recall -> [Balanced BST hot sheet](../../../notebook/balanced-bst-hot-sheet.md)
- ordinary ordered-set route -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- GNU contest route -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- self-hosted split/merge route -> [Treap / Implicit Treap](../treap-implicit/README.md)
- persistence follow-up -> [Persistent Treap](../persistent-treap/README.md)
- dynamic-tree follow-up -> [Link-Cut Tree](../../graphs/link-cut-tree/README.md)
- self-adjusting bridge -> [Splay Tree](../splay-tree/README.md)

## References And Repo Anchors

Reference / practice:

- [OI Wiki - AVL Tree](https://oi-wiki.org/ds/avl/)
- [OI Wiki - Red-Black Tree](https://oi-wiki.org/ds/rbtree/)
- [OI Wiki - Scapegoat Tree](https://oi-wiki.org/ds/sgt/)
- [OI Wiki - Size Balanced Tree](https://oi-wiki.org/ds/sbt/)
- [cppreference - std::set](https://en.cppreference.com/w/cpp/container/set)
- [GCC PBDS manual](https://gcc.gnu.org/onlinedocs/gcc-9.3.0/libstdc%2B%2B/manual/manual/policy_data_structures.html)
- [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369)

Repo anchors:

- [Balanced BST hot sheet](../../../notebook/balanced-bst-hot-sheet.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)
- [Persistent Treap](../persistent-treap/README.md)
