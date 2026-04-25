# Chinese Remainder Hot Sheet

Use this page when the problem has already collapsed into:

```text
several congruences must hold at the same time
```

and the real question is whether to merge them, reject them, or reduce one linear congruence with extended Euclid first.

## Do Not Use When

- the real task is only `powmod`, inverse, or factorial tables under one prime modulus
- you only need one Bézout witness or one composite-mod inverse
- the statement is counting-heavy and congruences are only side arithmetic

## Choose By Signal

- `x ≡ ai (mod mi)` for several conditions -> merge pairwise with gcd consistency -> [`chinese-remainder.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp)
- two congruences, moduli maybe not coprime -> check `(a2 - a1) % gcd(m1, m2)` first -> CRT merge lane
- `a x ≡ b (mod m)` -> reduce with extended Euclid first -> compare [`extended-gcd-diophantine.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- pairwise-coprime CRT theorem is in your head, but the statement uses composite moduli -> reopen the topic before coding

## Core Invariants

- current pair `(a, m)` means every processed congruence is equivalent to `x ≡ a (mod m)`
- merge succeeds iff the residue difference is divisible by `gcd(m1, m2)`
- successful merge produces one residue modulo `lcm(m1, m2)`
- always normalize the public residue into `[0, m)`

## Main Traps

- assuming non-coprime moduli automatically mean "no solution"
- trying to invert `m1` modulo `m2` before dividing out the gcd
- forgetting to normalize negative residues after reconstruction
- overflowing `m1 * step` or `lcm` when the arithmetic is close to `10^18`

## Exact Starter In This Repo

- exact starter -> [`chinese-remainder.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp)
- flagship in-lane rep -> [General Chinese Remainder](../practice/ladders/math/chinese-remainder/generalchineseremainder.md)
- compare point -> [Euclid Problem](../practice/ladders/math/gcd-lcm/euclidproblem.md)

## Reopen Paths

- full merge derivation and linear-congruence doorway -> [Chinese Remainder / Linear Congruences](../topics/math/chinese-remainder/README.md)
- inverse / Bézout sanity -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- number-theory recall -> [Number theory cheatsheet](number-theory-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
