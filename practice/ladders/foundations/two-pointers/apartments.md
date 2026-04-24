# Apartments

- Title: `Apartments`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1084](https://cses.fi/problemset/task/1084)
- Secondary topics: `Greedy matching`, `Sorted scan`, `Tolerance window`
- Difficulty: `easy-medium`
- Subtype: `Match applicants to apartments within an allowed size difference`
- Status: `solved`
- Solution file: [apartments.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/apartments.cpp)

## Why Practice This

This is a very friendly first two-pointers problem because the invariant is visual and easy to trust.

After sorting both lists:

- one pointer walks applicants
- one pointer walks apartments
- each move throws away one option that can never help later

That is a great beginner example of why two pointers is really about monotone scans, not just copy-pasting a sliding-window loop.

## Key Idea

Sort both arrays.

Let:

- `i` point to the current applicant request
- `j` point to the current apartment size

For the current pair:

- if the apartment is too small even after tolerance, move `j`
- if the apartment is too large even after tolerance, move `i`
- otherwise they can be matched, so count one answer and move both

More precisely, if the allowed difference is `k`:

```text
apartment < applicant - k  -> too small
apartment > applicant + k  -> too large
otherwise                  -> match
```

Every step removes one impossible candidate, so both pointers only move forward.

## Complexity

- sorting: `O(n log n + m log m)`
- scan: `O(n + m)`
- total: `O(n log n + m log m)`

## Pitfalls / Judge Notes

- Do not try every applicant against every apartment. The whole gain comes from sorted monotone movement.
- The comparison is about a tolerance interval, not exact equality.
- Once an apartment is too small for the current applicant, it will also be too small for every later applicant because requests are sorted.
- Likewise, once an apartment is used in a match, it is gone.

## Reusable Pattern

- Topic page: [Two Pointers And Sliding Window](../../../../topics/foundations/patterns/two-pointers/README.md)
- Practice ladder: [Two Pointers ladder](README.md)
- Starter template: [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: when two sorted streams only move forward, think in terms of discarding impossible candidates greedily.
- This note adds: tolerance-based matching rather than exact pair finding.

## Solutions

- Code: [apartments.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/apartments.cpp)
