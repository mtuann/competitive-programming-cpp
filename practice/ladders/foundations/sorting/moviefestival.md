# Movie Festival

- Title: `Movie Festival`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1629](https://cses.fi/problemset/task/1629)
- Main topic: `Foundations -> Sorting`
- Secondary topics: `Interval scheduling`, `Finish-time ordering`, `Exchange argument`
- Difficulty: `easy`
- Subtype: `Pick the maximum number of non-overlapping intervals`
- Status: `solved`
- Solution file: [moviefestival.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/sorting/moviefestival.cpp)

## Why Practice This

This is one of the cleanest examples of sorting as the real idea, not just a convenience step.

Before sorting, the problem looks like a combinatorial search over subsets of movies.

After sorting by finishing time, it becomes:

- keep the earliest-finishing compatible movie
- scan once
- count how many choices fit

That is exactly the instinct the sorting topic is meant to build.

## Key Idea

Sort all movies by:

1. earlier ending time
2. earlier starting time as a harmless tie-breaker

Then greedily watch a movie whenever its start time is at least the ending time of the last chosen movie.

Why does sorting by end time work?

Suppose we are about to choose the next movie. Among all compatible movies, taking the one that finishes earliest leaves the most room for future movies. Any optimal solution that picks a later-finishing compatible movie can swap that choice with the earlier-finishing one without reducing the number of movies watched.

That is the classic exchange argument for interval scheduling.

So the whole algorithm is:

```text
sort by ending time
scan left to right
take a movie if it starts after or when the previous chosen movie ends
```

## Complexity

- sorting movies: `O(n log n)`
- greedy scan: `O(n)`
- total: `O(n log n)`

## Pitfalls / Judge Notes

- The compatibility test is `start >= last_end`, not `start > last_end`.
- If two movies end at the same time, the tie-break does not change the answer, but keeping it explicit makes the order deterministic.
- This is not weighted interval scheduling. Every chosen movie contributes exactly `1`.

## Solutions

- Code: [moviefestival.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/sorting/moviefestival.cpp)
