# Combinatorics Cheatsheet

Use this page when you can already name the counting family, but still need to stabilize the shape of the objects, slots, and constraints.

## Do Not Use When

- the problem is really about modular arithmetic implementation, not counting structure
- you still cannot tell whether order matters
- the main difficulty is graph modeling or DP state design rather than counting

## Choose By Signal

- choose positions directly -> binomial / combinations
- split a total into slots -> stars and bars / compositions
- upper bounds per slot -> bounded compositions or inclusion-exclusion
- count good objects by subtracting bad ones -> inclusion-exclusion
- lexicographic generation or k-th object -> enumeration / ranking
- count colorings or arrangements up to rotation / explicit symmetry -> reopen [Burnside / Pólya hot sheet](burnside-polya-hot-sheet.md)

## Common Moves

- choose positions
- split into runs
- distribute identical items into slots
- count bad cases and subtract

## Standard Forms

```text
x1 + x2 + ... + xn = S
xi >= 0
xi >= 1
xi <= K
```

## Questions To Ask

- are objects distinguishable?
- are slots distinguishable?
- is order important?
- is the target exact, at least, or at most?

## Main Trap

The most common wrong turn is counting the right structure with the wrong model of identity:

- identical vs distinct objects
- labeled vs unlabeled slots
- exact total vs at most total

Fix those three decisions before writing any formula.

## Reopen Paths

- topic pages -> [Counting Basics](../topics/combinatorics/counting-basics/README.md), [Burnside / Pólya / Group Actions](../topics/combinatorics/burnside-polya/README.md), [Inclusion-Exclusion](../topics/combinatorics/inclusion-exclusion/README.md)
- repo anchors -> [Distributing Apples](../practice/ladders/combinatorics/counting-basics/distributingapples.md), [Counting Necklaces](../practice/ladders/combinatorics/burnside-polya/countingnecklaces.md), [Prime Multiples](../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)
