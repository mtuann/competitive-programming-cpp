# Monotonic Stack / Queue Hot Sheet

Use this sheet when one linear scan plus one permanent domination rule is enough.

## Do Not Use When

- updates happen online after the scan starts
- the active set is not monotone and old candidates may become relevant again
- the query is an arbitrary interval rather than one structured scan -> [Sparse Table hot sheet](sparse-table-hot-sheet.md), [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- you need median / arbitrary quantile maintenance, not only min / max / nearest boundary

## Choose By Signal

- first smaller / greater to the left or right -> monotonic stack
- largest rectangle / nearest blocking boundary -> monotonic stack with widths from indices
- minimum / maximum of every fixed-width window -> monotonic deque
- one DP transition asks for the best value over a forward-only interval -> monotonic deque
- online interval queries or non-monotone activation -> ordered set / heap / segment tree instead

## Core Invariants

- the structure stores indices, not only values
- the value order inside the stack / deque is monotone by the chosen comparator
- once a new element dominates an older tail candidate, the older one can never matter again
- every index is pushed once and popped once, so the total pop count is `O(n)`

## Main Traps

- mixing `<` and `<=` tie policy; equal values change whether you want strictly smaller or smaller-or-equal
- storing only values and then losing the boundary / width / expiry information
- forgetting that deque expirations happen from the front, while domination pops happen from the back
- reaching for segment tree or multiset before checking whether one monotone sweep already closes the whole statement

## Exact Starter Route

- stack-side starter -> [monotonic-stack-nearest-smaller.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-stack-nearest-smaller.cpp)
- queue-side starter -> [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- flagship in-lane rep -> [Nearest Smaller Values](../practice/ladders/data-structures/monotonic-stack-queue/nearestsmallervalues.md)
- queue-side compare rep -> [Sliding Window Minimum](../practice/ladders/dp/sliding-window/slidingwindowminimum.md)
- stretch sibling -> histogram / rectangle boundary problems such as `Advertisement`

## Reopen Paths

- full topic page -> [Monotonic Stack / Queue](../topics/data-structures/monotonic-stack-queue/README.md)
- broader chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
- compare heavier structures -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md), [Segment Tree](../topics/data-structures/segment-tree/README.md)
