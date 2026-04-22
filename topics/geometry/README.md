# Geometry

Geometry is rewarding but unforgiving. This section should start with robust integer geometry and only later expand into broader continuous or implementation-heavy ideas.

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Defer for later: circle-heavy and precision-sensitive topics until orientation and hull basics are stable

## Learn In Order

1. Core now
- vectors, dot product, cross product
- orientation tests
- segment and line intersection basics

2. Contest core
- convex hull
- rotating calipers
- sweep-line basics

3. Advanced later
- circle geometry
- half-plane style ideas
- precision-heavy continuous cases

## Recognition Cues

- the statement is really about points, lines, angles, or area relations
- the clean solution uses orientation, projection, or ordering by angle
- integer-only formulas might avoid floating-point headaches

## Common Pitfalls

- mixing floating point into problems that can stay integer
- skipping convention choices for orientation and line representation
- treating geometry as memorization instead of a small set of invariants

## Exit Criteria

After this section, you should be comfortable with standard vector-based reasoning, able to implement robust integer geometry primitives, and cautious about when precision changes the problem.

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
