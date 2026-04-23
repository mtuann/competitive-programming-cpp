# Counting Numbers

- Title: `Counting Numbers`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2220](https://cses.fi/problemset/task/2220)
- Main topic: `DP -> Digit DP`
- Secondary topics: `Previous digit state`, `Leading zeros`, `Range counting`
- Difficulty: `medium`
- Subtype: `Count numbers in a range with no equal adjacent digits`
- Status: `solved`
- Solution file: [countingnumbers.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/digit-dp/countingnumbers.cpp)

## Why Practice This

This is one of the best first digit-DP problems because the extra state is tiny and meaningful:

- `tight`: are we still matching the upper bound?
- `started`: have we placed the first non-leading-zero digit yet?
- `prev`: what was the previous real digit?

Once those three ideas click, much larger digit-DP problems feel far less mysterious.

## Key Idea

Let `solve(x)` be the number of valid integers in `[0, x]`.

Then the final answer is:

```text
solve(b) - solve(a - 1)
```

To compute `solve(x)`, process the decimal digits from left to right with a memoized DFS.

State:

```text
dp[pos][prev][started][tight]
```

where:

- `pos` is the current digit position
- `prev` is the previous chosen digit, or a sentinel if the number has not started
- `started` says whether a non-leading-zero digit has appeared
- `tight` says whether the prefix still matches the bound exactly

Transition:

- choose the next digit `d`
- if `started` is already true and `d == prev`, skip it
- otherwise recurse to the next position with updated flags

Leading zeros need special care:

- while `started` is false and we place another `0`, we still have not chosen any real digit
- so there is no "adjacent equal digits" violation yet

That is why the `started` flag matters.

## Complexity

- positions: at most `19`
- previous-digit states: `11` including the sentinel
- each state tries at most `10` digits

So the total work is tiny, comfortably within limits.

## Pitfalls / Judge Notes

- The answer is `solve(b) - solve(a - 1)`, not `solve(b) - solve(a)`.
- `0` itself is valid.
- Leading zeros should not count as repeated adjacent digits.
- Memoize only states that are independent of the current bound suffix, typically the `tight = false` states.

## Solutions

- Code: [countingnumbers.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/digit-dp/countingnumbers.cpp)
