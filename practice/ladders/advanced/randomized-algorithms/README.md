# Randomized Algorithms Ladder

## Who This Is For

Use this ladder when deterministic contest tools feel familiar and you want to understand when randomness is a principled simplifier rather than a hack.

## Warm-Up

- expected-time reasoning
- collision probability intuition

## Core

- fingerprinting and low-failure verification

## Repo Case Study

- [Finding Borders](../../strings/hashing/findingborders.md): a clean internal example of probabilistic fingerprinting.

## Internal Material

- fingerprint starter -> [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)
- theory page -> [Randomized Algorithms](../../../../topics/advanced/randomized-algorithms/README.md)
- deterministic comparator -> [KMP](../../../../topics/strings/kmp/README.md)
- validation discipline -> [Stress Testing Workflow](../../../../notebook/stress-testing-workflow.md)

## Stretch

- randomized balancing
- compare Monte Carlo vs Las Vegas thinking
- use randomized stress generation to break weak assumptions

## Compare Points

- probabilistic fingerprinting -> [Finding Borders](../../strings/hashing/findingborders.md)
- exact linear alternative -> [String Matching](../../strings/kmp/stringmatching.md)
- engineering support -> [Algorithm Engineering](../algorithm-engineering/README.md)

This ladder is intentionally compare-point-heavy for now. Use it like this:

1. identify exactly what is random and what event can fail
2. compare the randomized tool against one deterministic baseline
3. reopen the stress/testing workflow before trusting a low-failure argument blindly

## Exit Criteria

You are ready to move on when you can:

- say what is random and what event can fail
- distinguish expected time from high-probability success
- explain why hashing is probabilistic
- know when a deterministic alternative is simpler and better

## External Practice

- [MIT Randomized Algorithms](https://courses.csail.mit.edu/6.856/current/)
- [CP-Algorithms - Treap](https://cp-algorithms.com/data_structures/treap.html)

## Tutorial Link

- [Randomized Algorithms](../../../../topics/advanced/randomized-algorithms/README.md)
