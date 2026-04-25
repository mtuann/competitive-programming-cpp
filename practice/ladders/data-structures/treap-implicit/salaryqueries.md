# Salary Queries

- Title: `Salary Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1144](https://cses.fi/problemset/task/1144)
- Secondary topics: `Key-based treap`, `Order statistics`, `Pair-key wrapper`, `Dynamic range count`
- Difficulty: `medium`
- Subtype: `Dynamic ordered multiset via unique pair keys, with online count-in-range queries`
- Status: `solved`
- Solution file: [salaryqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/treap-implicit/salaryqueries.cpp)

## Why Practice This

This is the cleanest first exact benchmark for the **key-based** side of the treap family in this repo.

The statement asks for:

- online updates to employee salaries
- online count of salaries inside one inclusive range
- duplicates that are real state, not collapsed values

So the real lesson is:

- turn each employee into one unique ordered key
- keep the whole active set in one split/merge tree
- answer counts with rank differences

## Recognition Cue

Reach for a key-based treap when:

- one changing ordered set needs online rank queries
- duplicates matter, but can be made unique by pairing with an id
- you want a self-hosted ordered structure instead of GNU PBDS
- rebuilding sorted order or compressing into a different offline structure would be clumsier

The strongest smell here is:

- "dynamic multiset + count how many keys lie in `[a, b]` under updates"

## Problem-Specific Transformation

Store each employee as the unique key:

$$
(salary_i, i)
$$

inside one key-based treap.

That does two useful things at once:

- salaries stay ordered by the first component
- equal salaries remain distinct because the employee id breaks ties

Now the two query types become:

- `! k x`:
  erase `(old_salary_k, k)`, then insert `(x, k)`
- `? a b`:
  count keys in the inclusive range `[a, b]`

The range count is:

$$
\# [a, b] = \operatorname{order\_of\_key}(b, +\infty) - \operatorname{order\_of\_key}(a, -\infty)
$$

In the implementation, that becomes a pair-sentinel trick such as:

- left sentinel `(a, 0)`
- right sentinel `(b, n + 1)`

because employee ids lie in `1..n`.

## Core Idea

The treap keeps all live `(salary, id)` keys in sorted order.

Then:

- `order_of_key((a, 0))` counts employees with salary `< a`
- `order_of_key((b, n + 1))` counts employees with salary `<= b`

So one range-count query is just the difference of two ranks.

The tree is still an ordered set, but the pair-key trick turns the duplicate-salary multiset into unique keys without changing sorted salary order.

## Complexity

- update: `O(log n)` expected
- count-in-range query: `O(log n)` expected
- memory: `O(n)`

## Pitfalls / Judge Notes

- Duplicates are real, so use `(salary, employee_id)` instead of raw salary keys.
- The query asks for salaries in the **inclusive** range `[a, b]`.
- Employee ids are stable; only the salary component changes.
- The exact sentinels matter:
  use a lower sentinel that is smaller than every real id and an upper sentinel that is larger than every real id.

## Reusable Pattern

- Topic page: [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- Practice ladder: [Treap / Implicit Treap ladder](README.md)
- Starter template: [treap-key-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/treap-key-ordered-set.cpp)
- Notebook refresher: [Treap / Implicit Treap hot sheet](../../../../notebook/treap-hot-sheet.md)
- Compare points:
  - [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
  - [Fenwick Tree](../../../../topics/data-structures/fenwick-tree/README.md)
- Carry forward: when duplicates can be made unique with one stable id, key-based treap can answer dynamic range counts by rank differences.
- This note adds: the exact `(value, id)` transform for duplicate-safe order statistics under one self-hosted balanced BST.

## Solutions

- Code: [salaryqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/treap-implicit/salaryqueries.cpp)
