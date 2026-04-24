# Removal Game

- Title: `Removal Game`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1097](https://cses.fi/problemset/task/1097)
- Main topic: `DP -> Interval DP`
- Secondary topics: `Score-difference DP`, `Take from ends game`, `Minimax`
- Difficulty: `medium`
- Subtype: `Optimal play on an interval where each move removes one end`
- Status: `solved`
- Solution file: [removalgame.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/interval-dp/removalgame.cpp)

## Why Practice This

This is one of the cleanest interval-DP games in the standard curriculum:

- every state is just a subarray `[l, r]`
- each move removes either the left end or the right end
- the opponent immediately faces another interval of the same form

It is also a great example of a useful DP modeling trick: instead of storing the absolute score of the first player, store the **score difference** between the current player and the other player. That turns a minimax-looking game into a short recurrence.

## Key Idea

Let:

```text
dp[l][r] = maximum possible (current player's score - other player's score)
           when the remaining numbers are a[l..r]
```

If the current player takes the left end `a[l]`, then the opponent becomes the "current player" on interval `[l + 1, r]`, so the net advantage is:

```text
a[l] - dp[l + 1][r]
```

If the current player takes the right end `a[r]`, the net advantage is:

```text
a[r] - dp[l][r - 1]
```

So the recurrence is:

```text
dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1])
```

Base case:

```text
dp[i][i] = a[i]
```

because with one number left, the current player just takes it.

Once we know the final difference `diff = dp[0][n - 1]`, recover the first player's actual score using:

```text
first + second = total_sum
first - second = diff
```

Therefore:

```text
first = (total_sum + diff) / 2
```

The implementation below compresses the interval DP to one dimension. Iterate `l` from right to left, and for each fixed `l`, sweep `r` from `l + 1` to `n - 1`. Then:

- the old `dp[r]` still means `dp[l + 1][r]`
- the already updated `dp[r - 1]` means `dp[l][r - 1]`

That gives the same recurrence in `O(n)` memory.

## Complexity

- states: `O(n^2)`
- transition per state: `O(1)`
- total: `O(n^2)`
- memory: `O(n)` with the compressed implementation

This is the intended complexity for the CSES constraints.

## Pitfalls / Judge Notes

- `dp[l][r]` is a **difference**, not the first player's score directly.
- The transition uses subtraction because after taking one end, the opponent gets the next move.
- Use `long long`; sums can grow well beyond `int`.
- For the 1D compression, the loop order matters: `l` must go downward, and `r` must go upward.

## Solutions

- Code: [removalgame.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/interval-dp/removalgame.cpp)
