# VOTELPH

- Title: `VOTELPH - Bà Nà`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/VOTELPH/](https://vn.spoj.com/problems/VOTELPH/)
- Mirror URL: [https://oj.vnoi.info/problem/votelph](https://oj.vnoi.info/problem/votelph)
- Main topic: `Geometry -> Sweep Line`
- Secondary topics: `Concave quadratics`, `Offline preprocessing`, `Range maximum query`
- Difficulty: `hard`
- Subtype: `Maximum mountain height over many interval queries`
- Status: `solved`
- Solution file: [votelph.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/votelph.cpp)

## Why Practice This

This problem looks like an upper-envelope or segment-tree problem at first, but the right simplification is more geometric: for a concave parabola, the maximum on `[L, R]` is always at the clipped vertex.

That turns a scary `max over all k and all x in [L, R]` into three smaller max queries.

## Core Idea

For one parabola `f(x) = ax^2 + bx + c` with `a < 0`, let:

- `v = -b / (2a)` be its vertex
- `peak = f(v)`

Then:

- if `v < L`, its maximum on `[L, R]` is `f(L)`
- if `v > R`, its maximum on `[L, R]` is `f(R)`
- if `L <= v <= R`, its maximum is `peak`

So for one query `[L, R]`:

```text
answer - 1 =
max(
    max(f_i(L)   over all i with vertex_i <= L),
    max(f_i(R)   over all i with vertex_i >= R),
    max(peak_i   over all i with L <= vertex_i <= R)
)
```

That gives three independent preprocessing tasks:

1. `left_best[x]`: best value at endpoint `x` among parabolas whose vertex is on the left
2. `right_best[x]`: best value at endpoint `x` among parabolas whose vertex is on the right
3. range max of peak values over sorted vertex positions

The crucial input detail is that every query endpoint has at most `2` digits after the decimal point. So all `L, R` lie on the fixed grid:

```text
{-1000.00, -999.99, ..., 999.99, 1000.00}
```

That is only `200001` positions, which makes preprocessing feasible.

## Complexity

- preprocess left endpoint table: `O(N * 200001)` in the worst case
- preprocess right endpoint table: `O(N * 200001)` in the worst case
- peak RMQ preprocessing: `O(N log N)`
- each query: `O(log N)`

With `N <= 2000`, `Q <= 500000`, this fits.

## Pitfalls / Judge Notes

- The problem is hidden on SPOJ, so do not assume the intended tag is the intended solution.
- The important hidden detail is the `0.01` endpoint grid. Without that, many heavier structures would be tempting.
- Use exact scaled integer arithmetic for endpoint values:
  - if coefficients are scaled by `100`
  - and `x` is scaled by `100`
  - then `f(x)` on query endpoints is exact in units of `1e-6`
- The vertex itself is **not** restricted to the `0.01` grid. Only endpoint evaluations are discretized.
- Remember to add the final safety margin `+1`.

## Solutions

- Code: [votelph.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/votelph.cpp)
