# Probability Ladder

This ladder covers contest probability where:

- the randomness is in the statement
- the state space is finite or bounded
- the answer is one exact probability or expected value

Use it when a problem asks you to analyze a random process exactly, not to design a randomized algorithm.

## Recommended Route

1. bounded-sum distribution DP
2. expectation from a known PMF
3. expectation through linearity / independence
4. harder process models only after the first three feel routine

## Anchor Problems

- [Dice Probability](diceprobability.md): the repo's exact first route, one PMF DP over repeated fair-die throws

## Retrieval / Build Path

- topic page -> [Probability](../../../../topics/math/probability/README.md)
- hot sheet -> [Probability hot sheet](../../../../notebook/probability-hot-sheet.md)
- starter -> [probability-distribution-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/probability-distribution-dp.cpp)

## Compare Points

- [Candy Lottery](https://cses.fi/problemset/task/1727/): expectation from a derived distribution of the maximum
- [Moving Robots](https://cses.fi/problemset/task/1726/): repeated transition probabilities plus independence/complements
- [Randomized Algorithms](../../../../topics/advanced/randomized-algorithms/README.md): anti-cue when the randomness belongs to the algorithm rather than the statement

## Exit Criteria

You are ready to leave this ladder when you can:

- decide whether to build a PMF or compute expectation directly
- use linearity of expectation without needing the full joint process
- recognize when simulation is the wrong instinct
- separate probability-in-the-problem from randomized-algorithm analysis

## External Practice

- [CSES Dice Probability](https://cses.fi/problemset/task/1725/)
- [CSES Candy Lottery](https://cses.fi/problemset/task/1727/)
- [CSES Moving Robots](https://cses.fi/problemset/task/1726/)
- [CSES Inversion Probability](https://cses.fi/problemset/task/1728/)
