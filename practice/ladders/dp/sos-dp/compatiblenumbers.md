# Compatible Numbers

- Title: `Compatible Numbers`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/165/E](https://codeforces.com/problemset/problem/165/E)
- Secondary topics: `Bitwise complements`, `Subset zeta sweep`, `Witness propagation`
- Difficulty: `2200`
- Subtype: `Any disjoint partner via subset witness propagation`
- Status: `solved`
- Solution file: [compatiblenumbers.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sos-dp/compatiblenumbers.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `SOS DP` lane.

The problem is not "find one best subset DP state."

It is:

- bucket all present values on one fixed `22`-bit cube
- propagate one witness to every mask
- answer each query by looking at the complement mask

That makes it an ideal first rep for:

- subset zeta direction
- complement-mask modeling
- using the sweep for "any valid representative" instead of numeric sums

## Recognition Cue

Reach for this lane when:

- the statement gives many integers inside one moderate bit universe
- the predicate is bitwise, such as:

$$
x \mathrel{\&} y = 0
$$

- any valid witness is enough
- the brute force is "for every number, scan all other numbers"

The strongest smell here is:

```text
every query wants one value whose set bits must stay inside the complement of this mask
```

## Problem-Specific Transformation

Let:

$$
full = (1 \ll 22) - 1.
$$

For one fixed number `x`, a compatible value `y` must satisfy:

$$
x \mathrel{\&} y = 0.
$$

That is equivalent to:

$$
y \subseteq (full \hat{} x).
$$

So the task becomes:

- for every mask `m`
- know whether some present number is a submask of `m`
- and if yes, keep one witness

Initialize:

- `witness[v] = v` for every present value `v`
- `witness[m] = -1` otherwise

Then run the **subset sweep**:

- if bit `b` is set in `mask`
- and `witness[mask]` is still missing
- copy from `witness[mask ^ (1 << b)]`

After all bits:

- `witness[m]` stores some present number `z` with `z ⊆ m`, if one exists

So each answer is simply:

$$
witness[full \hat{} x].
$$

## Core Idea

The exact contest route is:

1. build one dense witness array over all `22`-bit masks
2. propagate subset witnesses with the SOS subset sweep
3. query the complement mask for every original value

This is not ordinary bitmask DP:

- there is no evolving `dp[mask]` state
- there is one full-cube offline transform

It is also not a numeric sum problem:

- the same sweep skeleton carries one witness value instead of `+`

## Implementation Notes

The repo solution uses:

- `BITS = 22`
- `witness[mask] = -1` as the sentinel
- one subset-direction propagation loop

The key invariant is:

- after processing all bits, `witness[mask]` is any present submask of `mask`

Then for each `x`:

- answer `witness[full ^ x]`

The Codeforces constraints have `a_i >= 1`, so there is no zero-only self-match corner to special-case.

## Complexity

- transform: `O(22 * 2^22)`
- answer extraction: `O(n)`
- memory: `O(2^22)`

That is the intended contest route.

## Pitfalls / Judge Notes

- If you propagate in the wrong direction, you will answer a different problem.
- The query mask is `full ^ x`, not `x`.
- This note wants **one witness**, not counts over all compatible values.
- Do not overcomplicate the first route with Walsh-Hadamard or subset convolution.

## Reusable Pattern

- Topic page: [SOS DP](../../../../topics/dp/sos-dp/README.md)
- Practice ladder: [SOS DP ladder](README.md)
- Starter template: [sos-dp-zeta.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/sos-dp-zeta.cpp)
- Notebook refresher: [SOS DP hot sheet](../../../../notebook/sos-dp-hot-sheet.md)
- Compare points:
  - [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md)
  - [Broken Profile / Plug DP](../../../../topics/dp/broken-profile/README.md)
- This note adds: the exact route where subset witness propagation over the mask cube answers a complement-based compatibility predicate.

## Solutions

- Code: [compatiblenumbers.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sos-dp/compatiblenumbers.cpp)
