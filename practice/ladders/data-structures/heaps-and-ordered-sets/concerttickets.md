# Concert Tickets

- Title: `Concert Tickets`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1091](https://cses.fi/problemset/task/1091)
- Main topic: `Data Structures -> Heaps And Ordered Sets`
- Secondary topics: `Multiset predecessor`, `Erase one occurrence`, `Greedy matching`
- Difficulty: `medium`
- Subtype: `For each buyer, sell the most expensive remaining ticket within budget`
- Status: `solved`
- Solution file: [concerttickets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/heaps-and-ordered-sets/concerttickets.cpp)

## Why Practice This

This is the canonical “ordered container by operations” problem.

For each customer, we need:

- find the largest ticket price `<= budget`
- remove exactly one copy of that price

That operation pair is almost a direct definition of `multiset` plus predecessor search.

## Key Idea

Store all remaining ticket prices in a `multiset<int>`.

For a customer with budget `x`, we want the predecessor of `x` in the ordered multiset.

The clean trick is:

```text
it = tickets.upper_bound(x)
```

- if `it == begin()`, then every remaining ticket is too expensive
- otherwise decrement once, and now `*it` is the largest affordable ticket

After printing that value, erase exactly that iterator.

Why `multiset` and not `set`?

Because duplicate ticket prices matter. If the input contains two tickets with price `5`, selling one should still leave the other available.

## Complexity

- building the multiset: `O(n log n)`
- each customer query: `O(log n)`
- total: `O((n + m) log n)`

## Pitfalls / Judge Notes

- Use `multiset`, not `set`, because duplicates are part of the state.
- `upper_bound(x)` returns the first value `> x`, so the predecessor is one step before it.
- Erase by iterator, not by value. `tickets.erase(value)` would remove *all* copies of that price.
- A heap is not enough here because we need predecessor search, not just the global minimum or maximum.

## Solutions

- Code: [concerttickets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/heaps-and-ordered-sets/concerttickets.cpp)
