# Bitmask DP Ladder

This ladder is about making small-state exponential DP feel controlled rather than scary.

## Who This Is For

Use this ladder if:

- `2^n` state counts still feel abstract
- assignment and Hamiltonian-style DP still seem unrelated
- you want better instinct for when bitmask DP is feasible

## Warm-Up

- subset iteration
- simple assignment DP

Target skill:

- read and manipulate masks comfortably

## Core

- `dp[mask]`
- `dp[mask][last]`
- transitions by adding one bit

Target skill:

- connect mask meaning to transition cost and complexity

## Stretch

- [SOS DP](../sos-dp/README.md) / subset-over-subset ideas later
- broken profile / frontier-mask DP later
- combine with shortest paths or BFS on subsets
- [VMMARBLE](vmmarble.md)

Target skill:

- distinguish plain bitmask DP from heavier subset-transform territory

## Exit Criteria

You are ready to move on when:

- you can estimate `O(n * 2^n)` from the constraints quickly
- you can choose between `dp[mask]` and `dp[mask][last]`
- you know when the state is too large and a different model is needed

## External Practice

- [USACO Guide - Bitmask DP](https://usaco.guide/gold/dp-bitmasks)
- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Tutorial Link

- [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md)
