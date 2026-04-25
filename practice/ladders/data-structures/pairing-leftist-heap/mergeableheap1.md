# Mergeable Heap 1

- Title: `P3377 [Template] Mergeable Heap 1`
- Judge / source: `Luogu`
- Original URL: [https://www.luogu.com.cn/problem/P3377](https://www.luogu.com.cn/problem/P3377)
- Secondary topics: `Leftist heap`, `Meldable heap`, `DSU`
- Difficulty: `medium`
- Subtype: `Singleton heaps with online meld and delete-min by heap owner`
- Status: `solved`
- Solution file: [mergeableheap1.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/pairing-leftist-heap/mergeableheap1.cpp)

## Why It Fits This Lane

This is the cleanest first rep for `Pairing Heap / Leftist Heap` in the repo because the whole problem is exactly:

- every item starts as one singleton heap
- meld the heaps containing `x` and `y`
- delete the minimum from the heap containing `x`
- ignore operations on already deleted items

No extra modeling hides the data structure.

## Problem Restatement

You have `n` initial keys, one per item id.

Operations:

1. `1 x y`: merge the heaps containing `x` and `y` if both items are still alive and the heaps are different
2. `2 x`: print the minimum key in the heap containing `x` and delete that minimum; if `x` is already deleted, print `-1`

The task is to simulate the structure online.

## The Model

The first wrong instinct is:

- keep each heap as one container
- when two heaps merge, move all elements from one heap into the other

That works conceptually but wastes time across many melds.

The right model is:

- every heap is represented by one meldable root
- every merge is `root = merge(root_a, root_b)`
- deleting the minimum means removing the root, then merging its remaining children

Because queries name **items**, not heap ids, we also need one owner layer:

- `find_heap(x)` returns the current root of the live heap containing item `x`

That is exactly why a DSU-style representative layer pairs so naturally with leftist heaps here.

## Exact Route Used Here

This repo keeps the first route narrow and deterministic:

- min-heap ordered by `(value, id)`
- leftist heap for meld
- DSU-style representative lookup for "heap containing x"
- deleted roots are marked dead and rejected later

The tie-break by `id` matters:

- if two keys are equal, deleting a different root can change future heap ownership
- `(value, id)` makes the route deterministic and safe

## Core Invariant

For the leftist heap:

- heap order holds at every node
- `rank(left) >= rank(right)`

So merge only walks down the short right spine.

For the owner layer:

- every live item reaches the current live root of its heap through representative links

When the root is deleted:

- the merged children become the new root
- the deleted root now points to that new root
- future `find_heap(x)` calls repair the path automatically

## Implementation Sketch

Maintain arrays:

- `key[i]`
- `left[i]`, `right[i]`
- `rank[i]`
- `rep[i]`
- `alive[i]`

Operations:

1. `merge(a, b)`
   - return the root with smaller `(key, id)`
   - recursively merge into its right child
   - swap children if needed so leftist rank condition holds

2. `meld_items(x, y)`
   - reject if either item is deleted
   - find current roots
   - if roots differ, merge them and update representatives

3. `pop_min_from_item_heap(x)`
   - reject if `x` is deleted
   - find current root `r`
   - answer `key[r]`
   - mark `r` deleted
   - set the new root to `merge(left[r], right[r])`
   - redirect the old root representative to the new root

## Why Plain `priority_queue` Is Not Enough

`priority_queue` closes:

- `push`
- `top`
- `pop`

but it does **not** close:

- merge heap containing `x` with heap containing `y`

Once that is the main operation, you need a meldable heap family, not a standard array heap.

## Repo Route

- topic page -> [Pairing Heap / Leftist Heap](../../../../topics/data-structures/pairing-leftist-heap/README.md)
- hot sheet -> [Pairing / Leftist Heap hot sheet](../../../../notebook/pairing-leftist-heap-hot-sheet.md)
- starter -> [leftist-heap-meldable-pq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/leftist-heap-meldable-pq.cpp)

## Solution

Reference implementation:

- [mergeableheap1.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/pairing-leftist-heap/mergeableheap1.cpp)

## Stretch

After this rep, good follow-ups are:

- [Monkey King](https://www.luogu.com.cn/problem/P1456)
- [Roman Game](https://www.luogu.com.cn/problem/P2713)
