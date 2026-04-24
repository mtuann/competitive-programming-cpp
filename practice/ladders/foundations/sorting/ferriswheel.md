# Ferris Wheel

- Title: `Ferris Wheel`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1090](https://cses.fi/problemset/task/1090)
- Main topic: `Foundations -> Sorting`
- Secondary topics: `Opposite-end two pointers`, `Greedy pairing`, `Lightest-heaviest matching`
- Difficulty: `easy-medium`
- Subtype: `Minimize the number of gondolas when each gondola can carry at most two children`
- Status: `solved`
- Solution file: [ferriswheel.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/sorting/ferriswheel.cpp)

## Why Practice This

This is a very useful first anchor for the idea that sorting can turn a pairing problem into a one-pass greedy.

Before sorting, it feels like we must search over many possible pairings.

After sorting, the structure becomes:

- the heaviest remaining child is the hardest one to place
- we should try to pair that child with the lightest remaining child
- if even that pair is too heavy, then the heaviest child must ride alone

That is exactly the kind of reasoning that makes sorting feel like an algorithmic tool instead of just preprocessing.

## Key Idea

Sort the weights in nondecreasing order.

Then keep two pointers:

- `i` at the lightest remaining child
- `j` at the heaviest remaining child

At each step, child `j` must be assigned to some gondola now.

There are only two meaningful cases:

1. if `weight[i] + weight[j] <= x`, they can share a gondola
2. otherwise, child `j` is too heavy to pair even with the lightest remaining child, so `j` must ride alone

Why is this greedy safe?

If the heaviest child cannot pair with the lightest child, then the heaviest child cannot pair with anyone, because every other remaining child is at least as heavy as the lightest one.

If the heaviest child can pair with the lightest child, using that lightest child is never worse than saving them for later, because it removes the smallest possible partner while still fitting the heaviest child into one gondola.

So the algorithm is:

```text
sort weights
put one pointer at each end
always place the heaviest remaining child
pair with the lightest remaining child if possible
count one gondola
```

This is a classic combination of:

- sorting to create order
- opposite-end two pointers
- greedy pairing

## Complexity

- sorting: `O(n log n)`
- two-pointer scan: `O(n)`
- total: `O(n log n)`

## Pitfalls / Judge Notes

- The goal is to minimize the number of gondolas, not maximize the number of pairs.
- Always process the heaviest remaining child first. That is the constrained choice that drives the greedy proof.
- If `weight[i] + weight[j] > x`, do not try another partner for `j`; none can work.
- A single remaining child still needs one gondola.
- Using `long long` for weights and sums keeps the code comfortable even when limits are large.

## Reusable Pattern

- Topic page: [Sorting](../../../../topics/foundations/patterns/sorting/README.md)
- Practice ladder: [Sorting ladder](README.md)
- Starter template: [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: when a pairing problem only depends on order, try sorting and forcing the most constrained element first.
- This note adds: opposite-end two pointers as the clean greedy proof for minimizing containers.

## Solutions

- Code: [ferriswheel.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/sorting/ferriswheel.cpp)
