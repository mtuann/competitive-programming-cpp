# Online Algorithms Ladder

## Who This Is For

Use this ladder when the benchmark itself is the lesson:

- decisions happen without future knowledge
- the right comparison is against an offline optimum
- you want the first honest competitive-analysis route before richer online families

## Warm-Up

- state clearly what the online algorithm knows and what it does not know
- compute `OPT(d)` for the ski-rental benchmark
- explain why any deterministic threshold rule has one adversarial bad horizon

## Core

- deterministic ski-rental threshold policy
- competitive ratio as the main quality metric
- worst-case adversarial horizon lands on the first buy day

## Repo Anchors

- [Ski Rental](skirental.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)
- [Optimization And Duality](../optimization-and-duality/README.md)

## Stretch

- reframe the elevator / wait-or-commit variant as the same threshold benchmark
- read one paging lecture and explain why it is the next canonical online example
- compare deterministic ski rental with the idea of randomized online algorithms against oblivious adversaries

## Compare Points

- first deterministic competitive-analysis benchmark -> [Ski Rental](skirental.md)
- randomness becomes the real design tool -> [Randomized Algorithms](../randomized-algorithms/README.md)
- the missing lens is "compare against a benchmark optimum" rather than a specific data structure -> [Optimization And Duality](../optimization-and-duality/README.md)

This ladder is intentionally sparse.

The point is not to collect many online-algorithm problems at once.
The point is to anchor the first benchmark cleanly, then know where the family branches next.

## Exit Criteria

You are ready to move on when you can:

- define the competitive ratio without mixing up online and offline information
- derive the ski-rental threshold policy and its worst-case ratio
- explain why paging or randomized online design is a different next step, not already included here

## External Practice

- [JHU Lecture 24: Online Algorithms](https://www.cs.jhu.edu/~mdinitz/classes/IntroAlgorithms/Fall2021/Lectures/Lecture24/lecture24slides.pdf)
- [Stanford CS369 notes](https://web.stanford.edu/class/cs369/files/cs369-notes.pdf)
- [Princeton COS 521 lecture note](https://faculty.cc.gatech.edu/~ssingla7/courses/Fall20cos521/lec18.pdf)

## Tutorial Link

- [Online Algorithms](../../../../topics/advanced/online-algorithms/README.md)
