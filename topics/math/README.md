# Math

Math gives you the compact facts and transforms that keep many contest solutions short, fast, and correct. The challenge is sequencing it so the basics arrive early and the heavier tools do not bury the learner.

## Subtopics

- [Modular Arithmetic](modular-arithmetic/README.md)
- [Number Theory Basics](number-theory-basics/README.md)
- [GCD / LCM](gcd-lcm/README.md)
- [BSGS / Discrete Log](bsgs-discrete-log/README.md)
- [Modular Square Root / Discrete Root](modular-square-root-discrete-root/README.md)
- [Primitive Root](primitive-root/README.md)
- [Pollard-Rho](pollard-rho/README.md)
- [Gaussian Elimination / Linear Algebra](gaussian-elimination/README.md)
- [Chinese Remainder / Linear Congruences](chinese-remainder/README.md)
- [Lucas Theorem / Large Binomial Mod Prime](lucas-theorem/README.md)
- [Mobius And Multiplicative Counting](mobius-multiplicative/README.md)
- [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](dirichlet-prefix-sums/README.md)
- [Min_25 / Du Jiao](min25-du-jiao/README.md)
- [Linear Recurrence / Matrix Exponentiation](linear-recurrence/README.md)
- [Berlekamp-Massey / Kitamasa](berlekamp-massey-kitamasa/README.md)
- [XOR Basis / Linear Basis](xor-basis/README.md)
- [Game Theory / Sprague-Grundy](game-theory/README.md)
- [Probability](probability/README.md)
- [FFT And NTT](fft-ntt/README.md)
- [Polynomial / Formal Power Series](polynomial-fps/README.md)

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Defer for later: FFT / NTT, polynomial / FPS, and heavier algebraic transforms until modular arithmetic is comfortable

## Learn In Order

1. Core now
- number-theory basics, then gcd/lcm as the first bridge into prime-exponent constructions
- modular arithmetic
- counting and combinatorics basics
- prime tools and divisibility facts

2. Contest core
- modular inverses and binomial coefficients
- sieve patterns
- congruence-system merges and gcd consistency checks after the [GCD / LCM](gcd-lcm/README.md) bridge feels natural
- large binomial queries when `n` is too big for one factorial table
- divisor-frequency counting plus Mobius cancellation for exact gcd structure
- summatory arithmetic functions opened through one direct Dirichlet convolution
- quotient-grouping on equal `floor(n / d)` blocks
- implicit prefix sums of `phi` / `mu` recovered on the quotient set `Q_n`
- recurrence and matrix-exponentiation style tools
- fixed-size linear transitions under one modulus
- recurrence jumping through characteristic-polynomial reduction once dense matrices become too expensive
- dense linear systems over one field by pivoting and elimination
- xor-basis elimination over `GF(2)` for subset-xor span, representability, and maximum subset xor
- impartial normal-play game sums through Grundy numbers, `mex`, and xor across independent components
- finite-state probability processes through PMFs, total probability, and expectation

3. Advanced later
- BSGS / discrete log once exponent recovery itself becomes the bottleneck and `O(sqrt(m))` storage is still affordable
- modular square-root extraction under one odd prime once residue tests and repeated squaring are already comfortable
- primitive-root finding under one prime once factoring `p - 1` and generator/order language feel trustworthy
- 64-bit factorization once the factorization layer itself becomes the bottleneck for primitive-root, discrete-root, or verifier-style factor tasks
- discrete-root follow-ups only after the primitive-root lane and BSGS lane both feel trustworthy
- deeper arithmetic-function prefix-sum machinery after the first direct Dirichlet lane feels comfortable
- prime-side multiplicative-function prefix engines such as full Min_25 only after the Du Jiao worldview is already trusted
- FFT / NTT
- polynomial / FPS after exact convolution is trustworthy
- deeper number-theory machinery

## Recognition Cues

- the problem is really about arithmetic structure, divisibility, or counting
- brute force is blocked by repeated modular or combinatorial subcomputations
- the clean solution needs a known algebraic identity or preprocessing trick
- the real handoff is `Number Theory Basics -> GCD / LCM -> Chinese Remainder / Modular Arithmetic`, not a random jump into deeper algebra

## Common Pitfalls

- memorizing formulas without understanding when they apply
- mixing integer arithmetic and modular arithmetic carelessly
- jumping to advanced transforms when a simpler counting argument is enough

## Exit Criteria

After this section, you should be able to use modular arithmetic and standard counting tools confidently, recognize common number-theory substructures, and know when advanced transforms are actually justified.

## Solved Examples In This Repo

- [Exponentiation](../../practice/ladders/math/modular-arithmetic/exponentiation.md): the core fast-power pattern under modulo arithmetic
- [Throwing Dice](../../practice/ladders/math/linear-recurrence/throwingdice.md): fixed-order recurrence lifted into a companion matrix
- [K-th Term of Linearly Recurrent Sequence](../../practice/ladders/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.md): use Kitamasa to jump on the characteristic recurrence once the order is given
- [Counting Divisors](../../practice/ladders/math/number-theory-basics/countingdivisors.md): divisor-count sieve for many bounded queries
- [Common Divisors](../../practice/ladders/math/gcd-lcm/commondivisors.md): maximize pair gcd by scanning divisor frequencies
- [GCD on Blackboard](../../practice/ladders/math/gcd-lcm/gcdonblackboard.md): all-except-one gcd via prefix/suffix aggregates
- [CRYPTKEY - Chìa khóa mã số](../../practice/ladders/math/gcd-lcm/cryptkey.md): gcd/lcm construction through prime-exponent reasoning
- [General Chinese Remainder](../../practice/ladders/math/chinese-remainder/generalchineseremainder.md): merge congruences one pair at a time and detect impossible systems early
- [Discrete Logarithm Mod](../../practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md): recover exponents with gcd reduction first and BSGS second
- [Sqrt Mod](../../practice/ladders/math/modular-square-root-discrete-root/sqrtmod.md): test quadratic residues first, then extract one root with Tonelli-Shanks
- [Primitive Root](../../practice/ladders/math/primitive-root/primitiveroot.md): factor `p-1`, then reject candidates whose reduced-order powers collapse to `1`
- [Factorize](../../practice/ladders/math/pollard-rho/factorize.md): separate prime from composite first, then split 64-bit composites recursively with Pollard-Rho
- [System of Linear Equations](../../practice/ladders/math/gaussian-elimination/systemoflinearequations.md): pivot one variable at a time until any valid prime-mod assignment drops out
- [Binomial Coefficient (Prime Mod)](../../practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md): switch from one factorial table to digit-by-digit base-`p` binomial reconstruction
- [Counting Coprime Pairs](../../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md): divisor frequencies plus Mobius cancellation for unordered gcd-1 pair counts
- [Sum of Divisors](../../practice/ladders/math/dirichlet-prefix-sums/sumofdivisors.md): summatory sigma through `sigma = 1 * id` and quotient grouping on equal `floor(n / d)` blocks
- [Sum of Totient Function](../../practice/ladders/math/min25-du-jiao/sumoftotientfunction.md): recover `sum phi` on `Q_n` from the identity `phi * 1 = id`
- [XMAX - XOR Maximization](../../practice/ladders/math/xor-basis/xmax.md): maintain an xor basis instead of searching all subset xor combinations
- [S-Nim](../../practice/ladders/math/game-theory/snim.md): precompute Grundy values once for one subtraction set, then xor heap nimbers across each position
- [Dice Probability](../../practice/ladders/math/probability/diceprobability.md): exact PMF DP for repeated random trials with bounded sum state
- [POST2 - A cộng B version 2](../../practice/ladders/math/fft/post2.md): convolution modeling with FFT
- [Inv of Formal Power Series](../../practice/ladders/math/polynomial-fps/invofformalpowerseries.md): the first exact Newton + NTT route for FPS algebra under `998244353`

## Go Deeper

- Course: [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [CSES Problem Set](https://cses.fi/)
