# Combinatorics

<div class="badge-row" markdown>
  <span class="route-badge route-badge--bridge">Bridge</span>
  <span class="route-badge route-badge--deep">Deep</span>
</div>

Combinatorics is the counting layer of the repo. It is where "how many?" stops being ad hoc and becomes structured.

## Use This Area When

- the real question is counting valid arrangements rather than finding one witness
- choices are constrained by runs, bounds, or symmetry
- direct brute force is blocked, but the structure of the objects is regular

## Start With One Route

| If your bottleneck is... | Open first | Then |
| --- | --- | --- |
| basic counting patterns | [Counting Basics](counting-basics/README.md) | [Bounded Compositions](bounded-compositions/README.md) |
| overcounting and cancellation | [Inclusion-Exclusion](inclusion-exclusion/README.md) | one subset-style counting anchor |
| symmetry and orbit counting | [Burnside / Pólya / Group Actions](burnside-polya/README.md) | compare against plain counting first |
| ranking and constructive counting | [Lexicographic Enumeration](lexicographic-enumeration/README.md) | one ranking/unranking flavored note |

## Core Progression

1. `Core first`
- Counting Basics
- Bounded Compositions

2. `Then add`
- Inclusion-Exclusion
- Lexicographic Enumeration

3. `Later`
- Burnside / Pólya / Group Actions
- generating functions and deeper transform-heavy counting outside the current core

## Good First Repo Anchors

- [Distributing Apples](../../practice/ladders/combinatorics/counting-basics/distributingapples.md)
- [Prime Multiples](../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)
- [Counting Necklaces](../../practice/ladders/combinatorics/burnside-polya/countingnecklaces.md)
- [VOSFENCE](../../practice/ladders/combinatorics/bounded-compositions/vosfence.md)
- [VOITSORT](../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md)

## Browse All Subtopics

- [Counting Basics](counting-basics/README.md)
- [Burnside / Pólya / Group Actions](burnside-polya/README.md)
- [Inclusion-Exclusion](inclusion-exclusion/README.md)
- [Bounded Compositions](bounded-compositions/README.md)
- [Lexicographic Enumeration](lexicographic-enumeration/README.md)

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
