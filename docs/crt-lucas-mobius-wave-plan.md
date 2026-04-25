# CRT / Lucas / Möbius Wave Plan

- Purpose: split the remaining `Phase 7` math backlog into repo-fit waves that can ship without dropping quality
- Scope: topic pages, starter templates, hot sheets, ladders, flagship notes, and route wiring for the `CRT / Lucas / Möbius` family
- Doc type: planning
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-25
- Canonical companion docs: [Expansion Roadmap](expansion-roadmap.md), [Roadmap](roadmap.md), [Topic Template](topic-template.md), [Source Map](source-map.md)

This file exists so the remaining `math modern wave` does not get shipped as one oversized batch.

## Why This Needs A Split

These ideas are related, but they do **not** teach well as one bulk topic dump.

- `CRT` is about combining congruence systems.
- `Lucas` is about binomial coefficients modulo a prime when `n` is too large for ordinary factorial tables.
- `Möbius` is about multiplicative inversion and divisor-structured counting.

They share number-theory language, but the contest signals are different enough that the repo should not pretend they are one technique.

The right split for this repo is:

1. `Congruence Systems And Large Binomials`
2. `Möbius And Multiplicative Counting`

That keeps the teaching lane aligned with what the learner actually sees in statements.

## Existing Assets To Reuse

These waves should build on the math layer that already exists instead of starting from zero.

- topics:
  - [Modular Arithmetic](../topics/math/modular-arithmetic/README.md)
  - [Number Theory Basics](../topics/math/number-theory-basics/README.md)
  - [Linear Recurrence / Matrix Exponentiation](../topics/math/linear-recurrence/README.md)
- templates:
  - [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
  - [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
  - [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
  - [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- retrieval:
  - [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md)
  - [Number theory cheatsheet](../notebook/number-theory-cheatsheet.md)
- existing solved anchors:
  - [Euclid Problem](../practice/ladders/math/gcd-lcm/euclidproblem.md)
  - [Exponentiation II](../practice/ladders/math/modular-arithmetic/exponentiation2.md)
  - [Counting Divisors](../practice/ladders/math/number-theory-basics/countingdivisors.md)

## Wave Split

## Wave A. Congruence Systems And Large Binomials

This is the first wave because it has the cleanest route from current repo assets.

### Main Goal

Teach the learner to recognize:

- one or many congruences that must be solved together
- when moduli are pairwise coprime vs when gcd consistency matters
- when plain factorial / inverse-factorial tables stop working because `n` is too large relative to `p`

### Families To Cover

1. `Chinese Remainder / Linear Congruence Systems`
2. `Lucas Theorem / Large Binomial Mod Prime`

### Planned Topic Surfaces

#### A1. Chinese Remainder / Linear Congruences

Status:

- shipped on `2026-04-25`

Planned lane:

- topic: `topics/math/chinese-remainder/README.md`
- starter: `templates/math/chinese-remainder.cpp`
- hot sheet: `notebook/chinese-remainder-hot-sheet.md`
- ladder: `practice/ladders/math/chinese-remainder/README.md`
- flagship note + solution: one exact congruence-system problem

What this lane should teach:

- solve `x ≡ a_i (mod m_i)` as a system, not as unrelated modular facts
- distinguish:
  - pairwise-coprime CRT
  - general merge with gcd consistency checks
- route back to extended Euclid when modular inverses are not "prime-mod easy"
- mention `Garner` only as a compare point, not as the first shipped route

Preferred flagship candidates:

- [Library Checker - System of Linear Congruence](https://judge.yosupo.jp/problem/system_of_linear_congruence)
- [Kattis - General Chinese Remainder](https://open.kattis.com/problems/generalchineseremainder)

Strong compare points:

- [Euclid Problem](../practice/ladders/math/gcd-lcm/euclidproblem.md)
- [Modular Arithmetic](../topics/math/modular-arithmetic/README.md)

Out of scope for the first ship:

- generalized CRT for nontrivial prime-power decomposition plus full residue reconstruction across many layers
- CRT as a helper inside multi-prime NTT

#### A2. Lucas Theorem / Large Binomial Mod Prime

Planned lane:

- topic: `topics/math/lucas-theorem/README.md`
- starter: `templates/math/lucas-binomial.cpp`
- hot sheet: `notebook/lucas-hot-sheet.md`
- ladder: `practice/ladders/math/lucas-theorem/README.md`
- flagship note + solution: one prime-mod binomial problem where `n` is too large for ordinary precompute

What this lane should teach:

- ordinary factorial tables solve:
  - many `nCk mod p` queries when `max_n < p`
- Lucas takes over when:
  - `n` and `k` are huge
  - modulus is a prime
  - the statement still asks for one binomial modulo `p`
- base-`p` digit decomposition is the real invariant, not memorizing a formula blindly

Preferred flagship shape:

- one problem where the intended jump is explicitly:
  - "factorial table route fails"
  - "digit-by-digit Lucas route works"

Research gate before shipping:

- choose one official or project-primary reference strong enough for the proof walkthrough
- choose one flagship problem whose signal is unmistakably Lucas, not merely modular arithmetic

Out of scope for the first ship:

- prime-power Lucas variants
- full `nCk mod composite` with CRT reconstruction in the same page

### Why Wave A Is One Wave

`CRT` and `Lucas` both live in the same repo neighborhood:

- modular arithmetic boundaries
- inverse existence
- prime vs composite modulus policy
- when "mod prime helper" contracts stop being enough

So they can be shipped together **if** the wave stays capped at exactly two topic lanes and reuses the current math retrieval layer heavily.

If the Lucas flagship or source pass is not clean enough, ship `CRT` first and keep Lucas as the follow-up wave inside the same phase.

## Wave B. Möbius And Multiplicative Counting

This should ship only after Wave A lands cleanly.

### Main Goal

Teach the learner to recognize when inclusion-exclusion over gcd/divisibility structure is better expressed as:

- multiplicative precomputation
- Möbius inversion
- divisor iteration over frequencies

### Planned Topic Surface

This wave should start as **one family page**, not two thin leaves.

Planned lane:

- topic: `topics/math/mobius-multiplicative/README.md`
- starter: `templates/math/mobius-linear-sieve.cpp`
- hot sheet: `notebook/mobius-hot-sheet.md`
- ladder: `practice/ladders/math/mobius-multiplicative/README.md`
- flagship note + solution: one gcd-counting problem where Möbius is the real unlock

Preferred flagship candidates:

- [CSES - Counting Coprime Pairs](https://cses.fi/problemset/task/2417)
- one second compare-point problem if the lane needs a cleaner divisor-sum contrast

What this lane should teach:

- Möbius as inversion over divisor structure, not as a symbol to memorize
- relationship to:
  - inclusion-exclusion
  - divisor sums
  - multiplicative functions
  - linear sieve precomputation
- when a direct divisor-frequency count is enough and when full Möbius inversion is the cleaner route

Strong compare points:

- [Number Theory Basics](../topics/math/number-theory-basics/README.md)
- [Inclusion-Exclusion](../topics/combinatorics/inclusion-exclusion/README.md)
- [Counting Coprime Pairs](https://cses.fi/problemset/task/2417)

Out of scope for the first ship:

- Dirichlet convolution as a full standalone topic
- Min_25 sieve
- prefix sums of multiplicative functions over very large `n`

### Why Möbius Is Its Own Wave

Even though Möbius sits under "number theory," its contest smell is much closer to:

- arithmetic inclusion-exclusion
- gcd-counting
- divisor transforms

than to CRT or Lucas.

If shipped together with congruence topics, one of the lanes will almost certainly get underexplained.

## Research And Shipping Order

Use this order for the remaining math phase:

1. ship `Chinese Remainder / Linear Congruences`
2. decide whether `Lucas` is clean enough to remain in the same wave or should become the next small wave
3. only then ship `Möbius And Multiplicative Counting`

This preserves the repo rule:

```text
no wave may introduce more than 2 deep topics
```

and also respects the teaching rule:

```text
do not bulk-ship unrelated number-theory lanes just because they all live under math
```

## Definition Of Done For This Plan

This plan is only considered complete when:

- [x] the split into `Wave A` and `Wave B` is documented
- [x] each wave has a clear scope boundary
- [x] each planned lane has a target `topic / template / hot sheet / ladder / flagship note`
- [x] likely flagship candidates are named
- [x] `Expansion Roadmap` points to this file
- [x] this file is routed in nav so it is not orphaned

## Immediate Next Action

The next highest-leverage math task after this plan is:

1. ship `Chinese Remainder / Linear Congruences`
2. then reassess whether `Lucas` should stay paired in the same wave or become its own small follow-up
