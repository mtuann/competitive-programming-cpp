# FFT And NTT

FFT and NTT are the standard way to turn one expensive quadratic pair-combination into a near-linear-logarithmic pipeline:

1. encode the problem as a convolution
2. transform the coefficient arrays
3. multiply pointwise
4. inverse-transform back

This topic is really about one core idea, `convolution via evaluation at roots of unity`, with two implementation variants:

- `FFT`: complex numbers, flexible, but rounding-sensitive
- `NTT`: modular arithmetic, exact, but only under friendly modulus conditions

## At A Glance

Suspect this topic when:

- the brute force is "for every `i`, for every `j`"
- the quantity you need depends on `i + j`, `i - j`, or another additive index relation
- values can be bucketed into frequency arrays
- the statement is secretly asking for polynomial multiplication or generating-function coefficients

Strong contest triggers:

- count all pair sums or pair differences
- count matches between two shifted histograms
- multiply two large coefficient arrays
- compute every answer for all sums at once, not one sum at a time

Strong anti-cues:

- the data is sparse and the direct method is already small enough
- the combination rule is not additive after indexing
- the main bottleneck is graph structure, DP state explosion, or geometry rather than pair aggregation
- you only need one or two query values and there is a much lighter direct method

What success looks like after studying this page:

- you can explain why polynomial multiplication and convolution are the same object
- you know the difference between `linear` and `cyclic` convolution
- you can derive radix-2 FFT from the even/odd split
- you know exactly when to trust `FFT(double)` and when to move to `NTT`

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

## Problem Model And Notation

Let

$$
A(x) = \sum_{i=0}^{n-1} a_i x^i,
\qquad
B(x) = \sum_{j=0}^{m-1} b_j x^j
$$

and define the `linear convolution` of the coefficient arrays by

$$
c_k = \sum_{i=0}^{k} a_i b_{k-i},
\qquad
0 \le k \le n + m - 2,
$$

where coefficients outside range are treated as `0`.

Then the product polynomial is

$$
A(x)B(x) = \sum_{k=0}^{n+m-2} c_k x^k.
$$

So `convolution` is not just analogous to polynomial multiplication. It is polynomial multiplication, written in coefficient language.

When using a length-`N` transform, we also need an `N`-th primitive root of unity, written as $\omega$, meaning:

- $\omega^N = 1$
- $\omega^t \ne 1$ for every `0 < t < N`

For complex FFT we use

$$
\omega = e^{2\pi i / N}.
$$

For NTT we work in a finite field, usually $\mathbb{F}_p$, and need an element of exact order `N`.

## From Brute Force To The Right Idea

### Running Problem: Count All Pair Sums

Suppose we have two arrays of values, and we want to count how many ordered pairs produce each sum.

The direct brute force is:

```text
for every i:
    for every j:
        answer[a[i] + b[j]]++
```

That is `O(n^2)` pair work.

If the values lie in a manageable range, a better model is:

- `f[u]`: how many times value `u` appears in the first array
- `g[v]`: how many times value `v` appears in the second array

Then the number of pairs with sum `s` is

$$
h[s] = \sum_u f[u] g[s-u].
$$

That formula is exactly a convolution.

### Convolution Before Fourier

This modeling step is the real gateway:

- values become indices
- frequencies become coefficients
- pair combinations become coefficient multiplication

At this point the problem is no longer "count pairs". It is "multiply two coefficient arrays fast".

### Polynomial View

Associate the frequency arrays with polynomials:

$$
F(x) = \sum_u f[u]x^u,
\qquad
G(x) = \sum_v g[v]x^v.
$$

Then

$$
F(x)G(x) = \sum_s \left( \sum_u f[u]g[s-u] \right)x^s,
$$

so the coefficient of $x^s$ is exactly the number of pairs producing sum `s`.

That is the central bridge:

`quadratic pair counting -> polynomial multiplication -> convolution`

### Why Roots Of Unity Help

Naively, multiplying two degree-`d` polynomials is still quadratic.

The escape hatch is to stop thinking in coefficient form and temporarily switch to value form:

- evaluate both polynomials at many points
- multiply those values pointwise
- interpolate the product back

Roots of unity are the special evaluation points that make both evaluation and interpolation fast.

## Core Invariant And Why It Works

### The One Geometric-Series Lemma

If $\omega$ is a primitive `N`-th root of unity, then

$$
\sum_{t=0}^{N-1} \omega^{rt}
=
\begin{cases}
N, & N \mid r, \\
0, & N \nmid r.
\end{cases}
$$

Why this is true:

- if `N | r`, every term is `1`
- otherwise it is a nontrivial geometric series whose ratio is not `1`, so the sum collapses to `0`

This lemma is the algebraic reason the inverse transform exists.

### DFT, IDFT, And Orthogonality

For a length-`N` array `a`, define its transform by

$$
\widehat{a}_t = \sum_{j=0}^{N-1} a_j \omega^{jt}.
$$

Then the inverse formula is

$$
a_j = \frac{1}{N} \sum_{t=0}^{N-1} \widehat{a}_t \omega^{-jt}.
$$

The proof is one line after expanding the definition:

$$
\frac{1}{N}\sum_{t=0}^{N-1} \left( \sum_{k=0}^{N-1} a_k \omega^{kt} \right)\omega^{-jt}
=
\frac{1}{N}\sum_{k=0}^{N-1} a_k \sum_{t=0}^{N-1} \omega^{(k-j)t},
$$

and the inner sum is `N` when `k = j` and `0` otherwise, by the lemma above.

### Why Convolution Becomes Pointwise Multiplication

Let `deg A + deg B < N`, so there is no wrap-around.

If we evaluate both polynomials at the same `N` roots of unity, then for each `t`:

$$
(AB)(\omega^t) = A(\omega^t)B(\omega^t).
$$

So if $\widehat{a}$ and $\widehat{b}$ are the transforms of the coefficient arrays, then:

$$
\widehat{c}_t = \widehat{a}_t \widehat{b}_t
$$

is the transform of the product polynomial. Applying the inverse transform recovers the coefficient array `c`, which is the convolution.

This is the convolution theorem in the exact form contest code uses.

### Why Radix-2 FFT Is Fast

Now assume `N = 2^k`.

Split the polynomial into even and odd coefficients:

$$
A(x) = A_{\text{even}}(x^2) + x A_{\text{odd}}(x^2),
$$

where

$$
A_{\text{even}}(x) = a_0 + a_2x + a_4x^2 + \cdots,
\qquad
A_{\text{odd}}(x) = a_1 + a_3x + a_5x^2 + \cdots.
$$

Evaluate at $\omega_N^t$:

$$
A(\omega_N^t)
=
A_{\text{even}}(\omega_N^{2t})
+
\omega_N^t A_{\text{odd}}(\omega_N^{2t}).
$$

But $\omega_N^2$ is a primitive `(N/2)`-th root of unity, so the even and odd pieces are just two transforms of length `N/2`.

Also, since $\omega_N^{t + N/2} = -\omega_N^t$,

$$
A(\omega_N^{t+N/2})
=
A_{\text{even}}(\omega_N^{2t})
-
\omega_N^t A_{\text{odd}}(\omega_N^{2t}).
$$

So one pair of half-size transforms gives two outputs at once:

$$
Y_t = E_t + \omega_N^t O_t,
\qquad
Y_{t+N/2} = E_t - \omega_N^t O_t.
$$

That yields the recurrence

$$
T(N) = 2T(N/2) + O(N),
$$

so

$$
T(N) = O(N \log N).
$$

### From Recursive Splits To Bit-Reversal And Butterflies

The proof above is recursive, but most contest implementations are iterative.

Those two views are the same computation laid out differently.

- the recursive view says "first separate by the last bit of the index: even vs odd"
- the next level separates by the second-last bit
- after `k` levels, the coefficients have been grouped by all `k` low bits

If we reorder the array by reversing the binary representation of each index, then the leaves of that recursion appear in the exact order the iterative butterflies expect.

That is why iterative FFT starts with a `bit-reversal permutation`: it linearizes the recursion tree so that stage `len = 2, 4, 8, ...` can perform all butterflies in-place.

Each butterfly is just the local rule

$$
(u, v) \mapsto (u + \omega v,\; u - \omega v),
$$

where the twiddle factor $\omega$ depends on the stage and the position inside the block.

When you debug FFT code, this bridge matters:

- the proof tells you why the butterfly formulas are correct
- the bit-reversal layout tells you why the iterative loops touch the entries in the order they do

### Why NTT Exists

The same algebra works over a finite field as long as the field contains an `N`-th primitive root of unity.

For a prime `p`, the nonzero elements of $\mathbb{F}_p$ form a cyclic multiplicative group of size `p - 1`. Therefore:

- if `N | (p - 1)`, there exists an element of order `N`
- if `g` is a primitive root modulo `p`, then

$$
\omega = g^{(p-1)/N}
$$

has exact order `N`

That is the whole reason NTT is possible.

For radix-2 NTT, we want `N = 2^k`, so the practical condition becomes:

$$
2^k \mid (p - 1).
$$

This is why contest NTT implementations use primes of the form

$$
p = c \cdot 2^k + 1.
$$

## Complexity And Tradeoffs

- direct convolution: `O(nm)`
- FFT / NTT transform: `O(N log N)`
- convolution after padding to length `N`: `O(N log N)`
- memory: `O(N)`

Practical tradeoffs:

- `FFT(double)` is flexible and often easiest when there is no modulus in the problem
- `NTT` is exact and avoids rounding bugs
- `NTT` is constrained by modulus and transform length
- if the frequency range is tiny or sparse enough, direct counting can still win

## Variant Chooser

| Approach | Exact? | Best use case | What it needs | Main risk |
| --- | --- | --- | --- | --- |
| Direct nested loops | yes | tiny arrays or tiny value range | no transform | wastes time on large quadratic pair work |
| `FFT(double)` | no, but usually accurate enough | unrestricted integer convolution, pair counting, histogram products | zero-padding, rounding discipline | floating-point noise |
| `NTT(mod p)` | yes | exact convolution modulo a friendly prime | prime `p`, root of unity, `N | (p-1)` | not every modulus works |
| Reverse-one-array convolution | yes | difference counting or correlation-style tasks | same transform machinery | indexing mistakes |
| Cyclic convolution | yes | problems that really wrap modulo `N` | no zero-padding | wrong for ordinary polynomial multiplication |

Keep the topic boundary tight:

- this page covers ordinary linear convolution by radix-2 FFT/NTT
- CRT across multiple NTT primes, Bluestein, and formal power series belong later

Two indexing changes are worth seeing once before they appear in a contest:

- `difference / correlation` tasks often become convolution only after reversing one array. If you want counts of `a_i - b_j = d`, then after shifting indices into nonnegative range, convolving `f` with `reverse(g)` turns differences into coefficient positions.
- `cyclic convolution` is genuinely different from linear convolution. For example, multiplying `[1, 1]` by `[1, 1]` with transform length `2` gives cyclic result `[2, 2]`, while the ordinary polynomial product is linear result `[1, 2, 1]`. Zero-padding is exactly what prevents that wrap-around.

## Worked Examples

### Example 1: Tiny Polynomial Multiply, And Why Padding Matters

Let

$$
A(x) = 1 + 2x + 3x^2,
\qquad
B(x) = 4 + 5x.
$$

Then the coefficient arrays are `[1, 2, 3]` and `[4, 5]`, and the linear convolution is:

$$
[4, 13, 22, 15].
$$

You can verify the coefficients directly:

- coefficient of $x^0$: `1 * 4 = 4`
- coefficient of $x^1$: `1 * 5 + 2 * 4 = 13`
- coefficient of $x^2$: `2 * 5 + 3 * 4 = 22`
- coefficient of $x^3$: `3 * 5 = 15`

So

$$
(1 + 2x + 3x^2)(4 + 5x) = 4 + 13x + 22x^2 + 15x^3.
$$

Now the important implementation point:

- the result has length `3 + 2 - 1 = 4`
- if you use a transform shorter than `4`, the coefficients wrap around and you get cyclic convolution instead of linear convolution

That is why zero-padding is not a cosmetic detail. It is part of the correctness proof.

If you want to see one transform pipeline fully spelled out, use an even smaller pair:

- `a = [1, 1, 0, 0]`
- `b = [1, 1, 0, 0]`
- `N = 4`
- complex root $\omega = i$

Then the forward transforms are:

$$
\widehat{a} = [2,\; 1+i,\; 0,\; 1-i],
\qquad
\widehat{b} = [2,\; 1+i,\; 0,\; 1-i].
$$

Pointwise multiplication gives:

$$
\widehat{c} = [4,\; 2i,\; 0,\; -2i].
$$

Applying the inverse transform recovers:

$$
c = [1,\; 2,\; 1,\; 0].
$$

So the nonzero coefficients are exactly the linear convolution of `[1, 1]` with `[1, 1]`.

This is the whole algorithm in miniature:

1. zero-pad to a legal transform length
2. transform both arrays
3. multiply pointwise
4. inverse-transform
5. discard the padded tail

### Example 2: `POST2` And The Modeling Pipeline

In [POST2](../../../practice/ladders/math/fft/post2.md), we want to count ordered triples `(i, j, k)` such that

$$
A_i + B_j = C_k.
$$

The direct `O(n^2)` pair enumeration is too slow.

The right modeling pipeline is:

1. build frequency arrays for `A`, `B`, and `C`
2. shift by a fixed offset because values can be negative
3. convolve the frequency arrays of `A` and `B`
4. interpret the coefficient at index `s` as "how many ordered pairs sum to `s`"
5. multiply by the frequency of `C = s`

So the hard part is not the transform itself. The hard part is recognizing that a pair-sum count over values is exactly a coefficient product.

That is why `POST2` is the right repo anchor for this topic:

- it exercises value shifting
- it separates modeling from transform mechanics
- it shows how the final coefficients still need problem-specific interpretation

## Algorithm And Pseudocode

The contest skeleton for both FFT and NTT is the same. Only the underlying arithmetic changes.

```text
convolution(a, b):
    choose n as the smallest power of two with n >= |a| + |b| - 1
    resize a and b to length n with zeros

    transform(a, invert = false)
    transform(b, invert = false)

    for i from 0 to n - 1:
        a[i] = a[i] * b[i]

    transform(a, invert = true)
    truncate to the first |a_original| + |b_original| - 1 entries
    return a

transform(v, invert):
    bit-reverse permute v

    for len = 2, 4, 8, ..., n:
        choose the principal len-th root w_len
        if invert:
            replace w_len by its inverse

        for each block of length len:
            w = 1
            for j from 0 to len/2 - 1:
                u = v[block + j]
                t = v[block + j + len/2] * w
                v[block + j] = u + t
                v[block + j + len/2] = u - t
                w = w * w_len

    if invert:
        divide every entry by n
```

For `FFT(double)`, `w_len` is a complex root of unity.

For `NTT`, `w_len` is a modular root of unity, and "divide by `n`" means multiply by `n^{-1} mod p`.

## Implementation Notes

### Linear vs Cyclic Convolution

This is the first question to ask before coding.

The transform itself naturally gives cyclic convolution modulo the transform length. To recover ordinary linear convolution, you must pad with zeros until

$$
N \ge |a| + |b| - 1.
$$

If this condition fails, high-degree coefficients wrap around and contaminate low-degree ones.

### Array Bounds And Shifts

If the values can be negative, shift them before turning them into indices.

If the maximum shifted value is `V`, then the result can go up to roughly `2V`, so size the frequency arrays and final interpretation logic accordingly.

### FFT Rounding Policy

The repo template uses `llround` after inverse FFT. This is appropriate only when:

- the true result is integral
- coefficient growth stays within safe floating-point tolerance

If the coefficients become very large, or the problem already lives modulo a prime, prefer NTT.

### FFT Or NTT In A Contest

Use this decision rule:

- if the statement already asks for answers modulo a friendly prime, prefer `NTT`
- if the final coefficients must be exact integers and coefficient growth is large, prefer `NTT`
- if there is no modulus and coefficient growth is moderate, `FFT(double)` is usually the simplest valid choice

In other words, `FFT(double)` is the flexible default for real-number evaluation, while `NTT` is the trustworthy default for exact modular arithmetic.

### Choosing An NTT Modulus

For a radix-2 NTT of length `N = 2^k`, you need:

- `p` prime
- `N | (p - 1)`

The official AtCoder Library convolution docs express this as:

$$
2^c \mid (m - 1),
\qquad
|a| + |b| - 1 \le 2^c.
$$

That is exactly the contest-friendly condition for a length-`2^c` NTT modulo `m`.

### Friendly-Primes Mindset

In practice, competitive programmers often use primes like

$$
998244353 = 119 \cdot 2^{23} + 1
$$

because a large power of two divides `p - 1`, which supports radix-2 lengths up to that power.

### One Concrete NTT Setup

The repo template [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp) uses:

- `MOD = 998244353`
- primitive root `g = 3`

For a stage of length `len`, the principal stage root is

$$
w_{\mathrm{len}} = g^{(MOD - 1)/\mathrm{len}} \pmod{MOD}.
$$

For example, when `len = 8`, the stage uses

$$
w_8 = 3^{(998244353 - 1)/8} \pmod{998244353}.
$$

The inverse transform uses $w_{\mathrm{len}}^{-1}$ instead, and the very end multiplies every coefficient by

$$
n^{-1} \pmod{MOD}.
$$

That is the concrete implementation meaning of the abstract condition `N | (p - 1)`.

### Bit-Reversal And Butterfly Bugs

Most wrong implementations fail in one of four places:

- incorrect bit-reversal permutation
- wrong sign or inverse root in the inverse transform
- forgetting the final normalization by `n`
- choosing `n` too small

If the output looks almost right but not exactly, suspect the transform layer.

If the output is wildly wrong, suspect the modeling layer first.

### Validation Loop

Whenever you write or modify a transform implementation, validate it against naive convolution on tiny random arrays.

The standard loop is:

1. generate many random arrays of length at most `8` or `10`
2. compute convolution with the transform code
3. compute convolution with the `O(nm)` double loop
4. compare every coefficient

For `FFT(double)`, this is how you catch rounding or normalization bugs early.

For `NTT`, this is how you catch wrong stage roots, inverse roots, or missing normalization.

## Common Mistakes

- forgetting that the default transform computes cyclic, not linear, convolution
- padding to `max(|a|, |b|)` instead of `|a| + |b| - 1`
- forgetting to shift negative values before building frequencies
- using FFT when exact modular arithmetic is required
- forgetting self-pair, unordered-pair, or diagonal corrections in the problem interpretation
- assuming every modulus supports NTT
- treating "polynomial multiplication" and "pair counting" as separate ideas instead of the same coefficient identity

## Practice Archetypes

### Warm-Up

- multiply two small polynomials:
  why it fits: this isolates the coefficient identity before any modeling noise
- pair-sum frequency counting:
  why it fits: the cleanest bridge from nested loops to convolution

### Core

- histogram matching or correlation by reversing one array:
  why it fits: teaches the difference between sums and differences
- exact convolution modulo a friendly prime:
  why it fits: this is where NTT starts to feel natural instead of magical

### Stretch

- [POST2](../../../practice/ladders/math/fft/post2.md):
  why it fits: full contest pipeline with negative shifts, duplicate counts, and coefficient interpretation
- larger coefficient-growth tasks:
  why it fits: forces the judgment call between `FFT(double)` and `NTT`

## References And Repo Anchors

- Repo anchor: [FFT ladder](../../../practice/ladders/math/fft/README.md)
- Repo anchor: [Canonical FFT template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp)
- Repo anchor: [Canonical NTT template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp)
- Repo anchor: [Strong repo note - POST2](../../../practice/ladders/math/fft/post2.md)
- Primary: [Cooley and Tukey, 1965](https://web.stanford.edu/class/cme324/classics/cooley-tukey.pdf)
- Course: [Stanford CS168 - Fourier Transform and Convolution](https://web.stanford.edu/class/cs168/l15.pdf)
- Course: [MIT 6.046J - FFT, IFFT, and Polynomial Multiplication](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/3dc84e78914f226665357234d6f4e25c_MIT6_046JS15_lec03.pdf)
- Course: [MIT 18.310 - The Finite Fourier Transform](https://math.mit.edu/~djk/18.310/Lecture-Notes/23_finite_fourier.html)
- Course: [MIT 18.310 - Implementing the FFT and Multiplying Numbers](https://math.mit.edu/~djk/18.310/Lecture-Notes/fft_mult.html)
- Reference: [AtCoder Library - convolution](https://atcoder.github.io/ac-library/production/document_en/convolution.html)
- Reference: [CP-Algorithms - Fast Fourier transform](https://cp-algorithms.com/algebra/fft.html)
- Essay / Blog: [Mark Newman - How the Cooley-Tukey FFT Algorithm Works, Part 1](https://www.dsprelated.com/showarticle/1709.php)
- Essay / Blog: [Mark Newman - How the Cooley-Tukey FFT Algorithm Works, Part 2](https://www.dsprelated.com/showarticle/1710.php)
- Background: [MIT 18.781 - Primitive Roots](https://www.ocw.mit.edu/courses/18-781-theory-of-numbers-spring-2012/resources/mit18_781s12_lec7/)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)
- [Combinatorics](../../combinatorics/README.md)
