# Combinatorics

Combinatorics is the counting layer of the repo. It is where “how many?” problems stop being ad hoc and become structured: compositions, runs, inclusion-exclusion, lexicographic counting, and counting under constraints.

## Entry

- Prereqs: [Foundations](../foundations/README.md), [Math](../math/README.md)
- Defer for later: generating functions and heavier transform-based counting

## Subtopics

- [Counting Basics](counting-basics/README.md)
- [Burnside / Pólya / Group Actions](burnside-polya/README.md)
- [Inclusion-Exclusion](inclusion-exclusion/README.md)
- [Bounded Compositions](bounded-compositions/README.md)
- [Lexicographic Enumeration](lexicographic-enumeration/README.md)

## Learn In Order

1. Core now
- permutations and combinations
- stars and bars
- bounded distributions
- run counting

2. Contest core
- inclusion-exclusion
- lexicographic ranking and counting
- constructive counting with structure
- orbit counting under explicit symmetries

3. Advanced later
- generating functions
- Möbius-flavored counting transforms
- deeper combinatorial identities

## Recognition Cues

- the problem is really about counting valid arrangements
- choices are constrained by adjacency, runs, or resource limits
- direct brute force is blocked, but the structure of the arrangements is regular
- many raw representations become the same object after rotation or another explicit symmetry

## Common Pitfalls

- counting the same object multiple times under different constructions
- using formulas without checking the assumptions
- missing that “exactly” and “at least” often need different tools

## Exit Criteria

After this section, you should be able to recognize common counting patterns, break them into structured choices, and attach the right formula or DP.

## Solved Examples In This Repo

- [Distributing Apples](../../practice/ladders/combinatorics/counting-basics/distributingapples.md): stars and bars turned into one modular binomial coefficient
- [Counting Necklaces](../../practice/ladders/combinatorics/burnside-polya/countingnecklaces.md): first Burnside route where cyclic shifts turn raw strings into orbit counting
- [Prime Multiples](../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md): direct subset inclusion-exclusion with safe product guards
- [VOSFENCE - Xay hang rao](../../practice/ladders/combinatorics/bounded-compositions/vosfence.md): constrained run decomposition and bounded distributions
- [VOITSORT - Sắp xếp đổi chỗ](../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md): ranking and unranking flavored constructive counting

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
