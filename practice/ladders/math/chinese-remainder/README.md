# Chinese Remainder / Linear Congruences Ladder

## Who This Is For

Use this ladder when you are comfortable with modular arithmetic basics, but statements that combine several residue conditions still feel slippery.

## Warm-Up

- gcd and lcm
- extended Euclid / Bézout coefficients
- modular normalization into `[0, m)`

## Core

- merge two congruences into one equivalent congruence
- detect impossible systems with the gcd-consistency check
- solve one linear congruence by reducing to extended Euclid, even if the exact starter here focuses on system merges

## Stretch

- explain why coprime CRT is only the clean theorem case, not the whole contest lane
- compare one composite-mod inverse with a full congruence-system merge
- compare pairwise merge against richer reconstruction techniques like Garner

## Retrieval Layer

- exact starter -> [chinese-remainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp) for congruence merges
- quick reminder sheet -> [Chinese Remainder hot sheet](../../../../notebook/chinese-remainder-hot-sheet.md)
- compare-point doorway for one `a x ≡ b (mod m)` equation -> [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)

## Repo Anchors

- [General Chinese Remainder](generalchineseremainder.md)

## Exit Criteria

You are ready to move on when you can:

- merge two congruences without guessing the algebra
- explain exactly when a non-coprime system is inconsistent
- reduce `a x ≡ b (mod m)` to the same extended-Euclid worldview
- decide when the task is only one inverse and does not need a full CRT merge

## External Practice

- [Kattis - General Chinese Remainder](https://open.kattis.com/problems/generalchineseremainder)
- [Library Checker - System of Linear Congruence](https://judge.yosupo.jp/problem/system_of_linear_congruence)

## Tutorial Link

- [Chinese Remainder / Linear Congruences](../../../../topics/math/chinese-remainder/README.md)
