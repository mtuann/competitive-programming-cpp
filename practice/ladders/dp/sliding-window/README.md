# Sliding Window Ladder

## Who This Is For

Use this ladder when a problem sits between DP and window techniques, and the main challenge is maintaining the right bounded state while scanning.

## Warm-Up

- variable-window reasoning
- weighted windows over sorted structure

## Core

- combine window invariants with DP-style state interpretation
- avoid recomputing window contributions from scratch

## Example Notes

- [TFIELD](tfield.md)

## Exit Criteria

You are ready to move on when you can:

- explain what the active window means at every step
- tell whether a problem is really two-pointers, really DP, or a hybrid
- maintain weighted contributions incrementally
- move between geometric preprocessing and windowed counting without losing the model

## External Practice

- [USACO Guide - Two Pointers](https://usaco.guide/silver/two-pointers)
- [CSES Problem Set](https://cses.fi/problemset/)

## Related Tutorials

- [Two Pointers](../../../../topics/foundations/patterns/two-pointers/README.md)
- [DP Foundations](../../../../topics/dp/foundations/README.md)
