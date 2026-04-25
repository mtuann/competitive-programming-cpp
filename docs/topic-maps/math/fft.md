# Math -> FFT And NTT

Polynomial multiplication and convolution with roots of unity, integer-friendly NTTs, and transform implementation details.

- Topic slug: `math/fft`
- Tutorial page: [Open tutorial](../../../topics/math/fft-ntt/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/fft/README.md)
- Repo problems currently tagged here: `2`
- Repo companion pages: `0`
- Curated external problems: `8`

## Microtopics

- convolution
- DFT
- roots-of-unity
- bit-reversal
- polynomial-multiplication
- NTT-prime
- primitive-root

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms FFT](https://cp-algorithms.com/algebra/fft.html) | `Reference` |
| [OI Wiki FFT](https://en.oi-wiki.org/math/poly/fft/) | `Reference` |
| [AtCoder ACL Convolution](https://atcoder.github.io/ac-library/production/document_en/convolution.html) | `Primary` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder Practice2 F](https://atcoder.jp/contests/practice2/tasks/practice2_f) | `Practice` |
| [CSES Signal Processing](https://cses.fi/problemset/task/2113/) | `Practice` |
| [CSES Apples and Bananas](https://cses.fi/problemset/task/2112/) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Convolution](https://atcoder.jp/contests/practice2/tasks/practice2_f) | `AtCoder` | `Easy` | Convolution, NTT, Polynomial Multiplication | Implementation; Math | Polynomial Convolution; Roots Of Unity | Number Theoretic Transform; Acl | The cleanest official practice problem for plain convolution under a prime modulus. |
| [Convolution](https://judge.yosupo.jp/problem/convolution) | `Library Checker` | `Easy-Medium` | Polynomial Multiplication, NTT | - | - | Convolution; 998244353 | The standard NTT/convolution benchmark. |
| [Convolution Mod](https://judge.yosupo.jp/problem/convolution_mod) | `Library Checker` | `Medium` | Polynomial Multiplication, NTT | - | - | Mod Convolution; NTT-Friendly; Formal Power Series | Same core idea but in the Library Checker format. |
| [Fast Fourier Transform](https://atcoder.jp/contests/atc001/tasks/fft_c) | `AtCoder` | `Medium` | Convolution | Math; Implementation | Complex Numbers; Polynomial Multiplication | Signal Processing | The canonical introductory FFT task and a very natural first heavy-convolution problem. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Divisor Set](https://codeforces.com/problemset/problem/1257/g) | `Codeforces` | `Hard` | Number Theory | Math; Divide-And-Conquer | Convolution; Divisor Structure | Divisors | A strong FFT-adjacent number theory problem where convolution appears inside a divisor lattice. |
| [Function Sum](https://codeforces.com/problemset/problem/1731/F) | `Codeforces` | `Hard` | Combinatorics | Combinatorics; Math | FFT; Generating Functions | Generating Functions | A more advanced combinatorial setting where convolution is the right language. |
| [Substring Search](https://codeforces.com/problemset/problem/1334/G) | `Codeforces` | `Hard` | Strings | Strings; Convolution | FFT Matching Ideas; String Hashing Basics | Substring Matching; Bitmasks | A challenging string task that benefits from efficient batch correlation. |
| [Yet Another String Matching Problem](https://codeforces.com/contest/954/problem/I) | `Codeforces` | `Hard` | String-Matching | Strings; Convolution | FFT-Based Matching; Alphabet Encoding | Pattern Matching | A classic FFT-powered string matching problem with a memorable, reusable trick. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CONVOLUTION` | Convolution | `primary` | `medium` | - | [Note](../../../practice/ladders/math/fft/convolution.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/fft/convolution.cpp) |
| `POST2` | A cộng B version 2 | `primary` | `medium` | convolution; digit aggregation; big integer addition | [Note](../../../practice/ladders/math/fft/post2.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/fft/post2.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
