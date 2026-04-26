# FWHT / XOR Convolution / Subset Convolution

This family begins when a problem already lives on the full boolean cube

```text
mask in [0, 2^bits)
```

and the bottleneck is no longer:

```text
aggregate one array over all submasks / supersets
```

but instead:

```text
combine two mask-indexed functions under xor or under an exact subset split
```

This repo teaches that family in one intentionally narrow first route:

- exact starter = `xor convolution` via the `Walsh-Hadamard transform`
- `subset convolution` stays inside the same family, but as the next stretch once SOS DP already feels stable

So this page is not "every transform on the boolean cube."

It is the first contest-ready doorway from:

- [SOS DP](../sos-dp/README.md)

into:

- xor convolution
- Walsh-Hadamard style diagonalization
- subset convolution by popcount layering

## At A Glance

- **Use when:** two full mask arrays must be pair-combined under `xor`, or one subset-split convolution is the real bottleneck
- **Core worldview:** this is `convolution on the boolean cube`, not ordinary prefix sweeps and not additive-index FFT
- **Main tools:** FWHT butterfly, inverse normalization by `1 / 2^bits`, popcount layers for subset convolution
- **Typical complexity:** `O(bits * 2^bits)` for xor convolution, `O(bits^2 * 2^bits)` for subset convolution
- **Main trap:** confusing `xor convolution`, `subset zeta sweeps`, and ordinary `FFT/NTT` convolution because they all look like "fast transforms"

Strong contest signals:

- the state space is already one full array of size `2^bits`
- the combine rule is:
  - `i xor j = k`, or
  - `T subseteq S` with the complement piece forced to be `S \\ T`
- the modulus is one friendly prime and exact arithmetic matters
- the brute force is one `O(4^bits)` pair loop over masks

Strong anti-cues:

- each mask only needs one aggregate over all submasks or supersets -> [SOS DP](../sos-dp/README.md)
- the indexing rule is additive like `i + j = k` -> [FFT / NTT](../../math/fft-ntt/README.md)
- the mask is just an evolving DP state instead of a whole function on the cube -> [Bitmask DP](../bitmask-dp/README.md)
- the bit width is too large to even store arrays of length `2^bits`

## Prerequisites

- [Bitmask DP](../bitmask-dp/README.md)
- [SOS DP](../sos-dp/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

Helpful nearby anchors:

- [FFT / NTT](../../math/fft-ntt/README.md)
- [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

## Problem Model And Notation

Let:

$$
N = 2^{bits}
$$

and let:

$$
f[mask], g[mask]
$$

be functions on the full boolean cube.

### XOR Convolution

The xor convolution is:

$$
h[k] = \sum_{i \oplus j = k} f[i] g[j]
     = \sum_i f[i] g[i \oplus k].
$$

This is the first exact route of this lane.

### Subset Convolution

The subset convolution is:

$$
h[S] = \sum_{T \subseteq S} f[T] g[S \setminus T].
$$

This is a sibling in the same family, but not the first starter snippet.

The reason both belong together is structural:

- both live on the full boolean cube
- both combine two mask-indexed functions
- both need a transform / layering trick beyond plain SOS zeta sweeps

## From Brute Force To The Right Idea

### XOR Convolution Brute Force

If `N = 2^bits`, the direct implementation is:

```text
for k in [0, N):
    for i in [0, N):
        h[k] += f[i] * g[i xor k]
```

That is:

$$
O(N^2) = O(4^{bits})
$$

which dies quickly once `bits` reaches the low twenties.

### Why SOS DP Is Not Enough

SOS DP speeds up:

- all-submask aggregation
- all-supermask aggregation

But xor convolution is not asking for one side of the cube to fold into another.

It is asking for a pair-combine rule:

```text
combine by xor of indices
```

So the right move is not another zeta sweep on one array. The right move is to find a basis where xor convolution becomes pointwise multiplication.

### Why FFT / NTT Is Also The Wrong Family

`FFT / NTT` handles:

$$
c[k] = \sum_i a[i] b[k-i]
$$

which is additive indexing.

Here the relation is:

$$
i \oplus j = k.
$$

That is a different group law, so we need a different transform.

## Core Invariant For FWHT

The Walsh-Hadamard butterfly for one pair `(x, y)` is:

$$
(x, y) \mapsto (x + y, x - y).
$$

Apply that bit by bit across the whole cube.

After processing the first `t` bits:

- every transformed value already represents a signed combination over the `2^t` masks that only differ inside those processed dimensions
- the signs are determined by parity on the processed bits

That is the boolean-cube analogue of "diagonalize the convolution operator."

Once both arrays are transformed:

- xor convolution turns into pointwise multiplication

Then the inverse transform is:

- the same butterfly shape again
- followed by multiplying every value by:

$$
(2^{bits})^{-1}
$$

under the chosen modulus

That is the exact starter route in:

- [fwht-xor-convolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/fwht-xor-convolution.cpp)

## Where Subset Convolution Fits

Subset convolution looks close to SOS DP, but it is not just:

```text
zeta(f) * zeta(g)
```

because each term must preserve the exact split:

$$
T \cup (S \setminus T) = S
$$

with disjoint parts and exact total popcount.

The standard route is:

1. split values by popcount layer
2. run subset zeta transforms on every layer
3. multiply compatible layers
4. inverse-zeta back

That gives:

$$
O(bits^2 \cdot 2^{bits})
$$

and is the right stretch after xor convolution feels routine.

So the family progression in this repo is:

1. [SOS DP](../sos-dp/README.md): one-array subset/superset sweeps
2. `FWHT / XOR Convolution`: pair-combine by xor
3. `Subset Convolution`: pair-combine by exact subset split plus popcount layers

## Common Traps

### 1. Forgetting The Inverse Normalization

For xor convolution, the inverse transform is not just "run the same loops backward."

You must also divide every entry by:

$$
N = 2^{bits}.
$$

Under a modulus, that means multiply by `inv(N)`.

### 2. Using The Wrong Transform Family

If the indexing law is:

- `i + j = k` -> [FFT / NTT](../../math/fft-ntt/README.md)
- `i xor j = k` -> this lane
- `T subseteq S` aggregate on one array -> [SOS DP](../sos-dp/README.md)

Mixing these up is the most common modeling failure.

### 3. Treating Subset Convolution As Plain SOS DP

Plain zeta sweeps do not preserve the exact size split between `T` and `S \setminus T`.

That is exactly why subset convolution needs the extra popcount-layer dimension.

### 4. Forgetting The Power-Of-Two Contract

The starter route assumes one full cube of size `2^bits`.

If your array size is not a power of two, your model is probably not the full boolean cube yet.

## Use This Lane When

- the full cube array already exists naturally
- the statement wants every xor-combined answer at once
- or two subset-indexed functions must combine into one third function on the same cube

## Do Not Use This Lane When

- one transformed array is enough and only subset/superset aggregation is needed
- the real bottleneck is item-order DP, not transform algebra
- the statement is secretly one additive convolution problem

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Books:

- [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- [Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-031-61794-2)

Official benchmarks:

- [Library Checker - Bitwise XOR Convolution](https://judge.yosupo.jp/problem/bitwise_xor_convolution)
- [Library Checker - Subset Convolution](https://judge.yosupo.jp/problem/subset_convolution)

Repo anchors:

- practice ladder: [FWHT / XOR Convolution / Subset Convolution ladder](../../../practice/ladders/dp/fwht-subset-convolution/README.md)
- flagship note: [Bitwise XOR Convolution](../../../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md)
- starter template: [fwht-xor-convolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/fwht-xor-convolution.cpp)
- notebook refresher: [FWHT / XOR Convolution / Subset Convolution hot sheet](../../../notebook/fwht-subset-convolution-hot-sheet.md)

## Related Topics

- [Bitmask DP](../bitmask-dp/README.md)
- [SOS DP](../sos-dp/README.md)
- [FFT / NTT](../../math/fft-ntt/README.md)
