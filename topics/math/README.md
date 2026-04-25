# Math

Math gives you the compact facts and transforms that keep many contest solutions short, fast, and correct. The challenge is sequencing it so the basics arrive early and the heavier tools do not bury the learner.

## Subtopics

- [Modular Arithmetic](modular-arithmetic/README.md)
- [Number Theory Basics](number-theory-basics/README.md)
- [Chinese Remainder / Linear Congruences](chinese-remainder/README.md)
- [Lucas Theorem / Large Binomial Mod Prime](lucas-theorem/README.md)
- [Mobius And Multiplicative Counting](mobius-multiplicative/README.md)
- [Linear Recurrence / Matrix Exponentiation](linear-recurrence/README.md)
- [XOR Basis / Linear Basis](xor-basis/README.md)
- [FFT And NTT](fft-ntt/README.md)

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Defer for later: FFT / NTT and heavier algebraic transforms until modular arithmetic is comfortable

## Learn In Order

1. Core now
- gcd, lcm, and modular arithmetic
- counting and combinatorics basics
- prime tools and divisibility facts

2. Contest core
- modular inverses and binomial coefficients
- sieve patterns
- congruence-system merges and gcd consistency checks
- large binomial queries when `n` is too big for one factorial table
- divisor-frequency counting plus Mobius cancellation for exact gcd structure
- recurrence and matrix-exponentiation style tools
- fixed-size linear transitions under one modulus
- xor-basis elimination over `GF(2)` for subset-xor span, representability, and maximum subset xor

3. Advanced later
- FFT / NTT
- deeper number-theory machinery

## Recognition Cues

- the problem is really about arithmetic structure, divisibility, or counting
- brute force is blocked by repeated modular or combinatorial subcomputations
- the clean solution needs a known algebraic identity or preprocessing trick

## Common Pitfalls

- memorizing formulas without understanding when they apply
- mixing integer arithmetic and modular arithmetic carelessly
- jumping to advanced transforms when a simpler counting argument is enough

## Exit Criteria

After this section, you should be able to use modular arithmetic and standard counting tools confidently, recognize common number-theory substructures, and know when advanced transforms are actually justified.

## Solved Examples In This Repo

- [Exponentiation](../../practice/ladders/math/modular-arithmetic/exponentiation.md): the core fast-power pattern under modulo arithmetic
- [Throwing Dice](../../practice/ladders/math/linear-recurrence/throwingdice.md): fixed-order recurrence lifted into a companion matrix
- [Counting Divisors](../../practice/ladders/math/number-theory-basics/countingdivisors.md): divisor-count sieve for many bounded queries
- [Common Divisors](../../practice/ladders/math/gcd-lcm/commondivisors.md): maximize pair gcd by scanning divisor frequencies
- [GCD on Blackboard](../../practice/ladders/math/gcd-lcm/gcdonblackboard.md): all-except-one gcd via prefix/suffix aggregates
- [CRYPTKEY - Chìa khóa mã số](../../practice/ladders/math/gcd-lcm/cryptkey.md): gcd/lcm construction through prime-exponent reasoning
- [General Chinese Remainder](../../practice/ladders/math/chinese-remainder/generalchineseremainder.md): merge congruences one pair at a time and detect impossible systems early
- [Binomial Coefficient (Prime Mod)](../../practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md): switch from one factorial table to digit-by-digit base-`p` binomial reconstruction
- [Counting Coprime Pairs](../../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md): divisor frequencies plus Mobius cancellation for unordered gcd-1 pair counts
- [XMAX - XOR Maximization](../../practice/ladders/math/xor-basis/xmax.md): maintain an xor basis instead of searching all subset xor combinations
- [POST2 - A cộng B version 2](../../practice/ladders/math/fft/post2.md): convolution modeling with FFT

## Go Deeper

- Course: [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [CSES Problem Set](https://cses.fi/)
