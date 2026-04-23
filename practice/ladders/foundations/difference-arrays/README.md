# Difference Arrays Ladder

Difference-array practice should teach you to spot offline range-update problems and separate “apply all updates” from “answer while updating.”

## Who This Is For

Use this ladder if:

- you know prefix sums, but range updates still feel brute-force
- you are unsure when endpoint marking is enough
- you keep reaching for Fenwick too early

## Warm-Up

- add `x` on `[l, r]` for many intervals
- rebuild the final array once
- count active intervals per position

Target skill:

- encode one range update as two endpoint changes

## Core

- initial array plus many updates
- final max / count / threshold queries after rebuilding
- event-style sweeps on a line

Target skill:

- combine difference reconstruction with one final scan or check

## Stretch

- compare offline difference arrays against online Fenwick
- explain why range-update plus intermediate queries breaks the method
- combine difference arrays with coordinate compression

Target skill:

- choose the simplest offline tool confidently

## Exit Criteria

You are ready to move on when:

- you can derive the `diff[l] += x, diff[r+1] -= x` rule from first principles
- you never forget the boundary check at `r + 1`
- you know when the problem needs a dynamic structure instead

## External Practice

- [CSES Problem Set](https://cses.fi/problemset/)
- [CP-Algorithms](https://cp-algorithms.com/)

## Tutorial Link

- [Difference Arrays](../../../../topics/foundations/patterns/difference-arrays/README.md)
