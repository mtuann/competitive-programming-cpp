# Sqrt Mod

- Title: `Sqrt Mod`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/sqrt_mod](https://judge.yosupo.jp/problem/sqrt_mod)
- Secondary topics: `Quadratic residues`, `Tonelli-Shanks`, `Modular arithmetic`
- Difficulty: `hard`
- Subtype: `Recover one modular square root modulo one prime, or report that none exists`
- Status: `solved`
- Solution file: [sqrtmod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-square-root-discrete-root/sqrtmod.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the `Modular Square Root / Discrete Root` lane because it forces the exact first route:

- one prime modulus per query
- one target of the form:

$$
x^2 \equiv y \pmod p
$$

- one valid root or `-1`

So the lesson is not primitive-root theory, not discrete roots in full generality, and not composite-mod lifting.

It is:

- normalize `y`
- test whether a root can exist
- run Tonelli-Shanks when the residue test passes

## Recognition Cue

Reach for this lane when:

- the modulus is prime
- the unknown is squared, not exponentiated
- the judge accepts any one valid root
- brute force over all residues is impossible

The strongest smell is:

- "given `y` and prime `p`, output `x` such that `x^2 ≡ y (mod p)`, or `-1`"

That is exactly the contract this repo starter is built for.

## Problem-Specific Transformation

For each query:

1. reduce `y mod p`
2. handle trivial cases:
   - `y = 0`
   - `p = 2`
3. use Euler's criterion to test whether `y` is a quadratic residue
4. if not, print `-1`
5. otherwise run Tonelli-Shanks to recover one root

The key simplification is:

```text
the judge only wants one root
```

So you do not need full root-set enumeration logic.

If the algorithm returns one root `r`, the other root is simply `p-r` whenever `r != 0`.

## Core Idea

Over an odd prime modulus:

- quadratic residues are exactly the values that pass Euler's criterion
- Tonelli-Shanks works by isolating the `2`-power part of `p-1`
- each round shrinks the remaining mismatch inside that `2`-power subgroup until the candidate becomes a true square root

This is the first exact route because it is:

- contest-clean
- reusable
- narrow enough to memorize safely

The broader `discrete root` family only comes later, once primitive-root and [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md) ideas are already comfortable.

## Complexity

Per query:

- modular arithmetic and residue checks: `O(log p)`
- Tonelli-Shanks: `O(log^2 p)`-style arithmetic in contest terms

This is fast enough for the verifier-style batch this judge uses.

## Solution Sketch

1. Normalize `y`.
2. If `y = 0`, answer `0`.
3. If `p = 2`, answer `y mod 2`.
4. Check Euler's criterion:

$$
y^{(p-1)/2} \pmod p
$$

If the result is `p-1`, there is no root.

5. Otherwise:
   - factor `p - 1 = q * 2^s` with `q` odd
   - find one quadratic non-residue `z`
   - initialize the Tonelli-Shanks state
   - repeatedly reduce the mismatch order until it becomes `1`
6. Output one deterministic representative, such as `min(r, p-r)`.

## Common Pitfalls

- forgetting that Euler's criterion only makes sense for odd prime `p`
- forgetting the `p = 2` edge case
- outputting one value without normalizing it back into `[0, p)`
- mixing up this task with discrete log or discrete root

## Related Paths

- Bigger theory step: [Modular Square Root / Discrete Root](../../../../topics/math/modular-square-root-discrete-root/README.md)
- Follow-up doorway: [Primitive Root](../../../../topics/math/primitive-root/README.md)
- Compare point: [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md)
- Retrieval page: [Modular Square Root hot sheet](../../../../notebook/modular-square-root-hot-sheet.md)
