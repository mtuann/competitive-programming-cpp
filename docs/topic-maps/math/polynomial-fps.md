# Math -> Polynomial / Formal Power Series

Truncated formal power series algebra under an NTT-friendly prime, with FPS inverse as the first exact route and log/exp/pow as follow-ups.

- Topic slug: `math/polynomial-fps`
- Tutorial page: [Open tutorial](../../../topics/math/polynomial-fps/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/polynomial-fps/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `4`

## Microtopics

- formal-power-series
- polynomial-inverse
- newton-doubling
- truncation-mod-xn
- ntt-backed-convolution
- fps-log-exp-pow

## Learning Sources

| Source | Type |
| --- | --- |
| [AtCoder ACL Convolution](https://atcoder.github.io/ac-library/production/document_en/convolution.html) | `Primary` |
| [Library Checker Inv of Formal Power Series](https://judge.yosupo.jp/problem/inv_of_formal_power_series) | `Practice` |
| [Library Checker Log of Formal Power Series](https://judge.yosupo.jp/problem/log_of_formal_power_series) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Exp of Formal Power Series](https://judge.yosupo.jp/problem/exp_of_formal_power_series) | `Practice` |
| [Library Checker Pow of Formal Power Series](https://judge.yosupo.jp/problem/pow_of_formal_power_series) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Polynomial / FPS hot sheet](../../../notebook/polynomial-fps-hot-sheet.md) | `quick reference` |
| [Inv of Formal Power Series note](../../../practice/ladders/math/polynomial-fps/invofformalpowerseries.md) | `flagship note` |
| [FFT / NTT tutorial](../../../topics/math/fft-ntt/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Inv of Formal Power Series](https://judge.yosupo.jp/problem/inv_of_formal_power_series) | `Library Checker` | `Hard` | Formal Power Series, NTT | Implementation; Algebra | Exact Convolution; Formal Power Series Mod X^n | Inverse; Newton Iteration | The clean first benchmark where the entire task is one truncated FPS inverse and Newton doubling is the exact intended route. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Log of Formal Power Series](https://judge.yosupo.jp/problem/log_of_formal_power_series) | `Library Checker` | `Hard` | Formal Power Series, NTT | Implementation; Algebra | Fps Inverse; Derivative And Integral | Logarithm; Derivative; Inverse | The natural follow-up once the inverse route is trusted, because FPS log is just derivative, inverse, product, and integral glued together. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Exp of Formal Power Series](https://judge.yosupo.jp/problem/exp_of_formal_power_series) | `Library Checker` | `Hard` | Formal Power Series, NTT | Implementation; Advanced Algebra | Fps Inverse; Fps Log | Exponential; Newton Iteration; Advanced | A major step up where the same FPS worldview survives but the contract grows beyond plain inversion. |
| [Pow of Formal Power Series](https://judge.yosupo.jp/problem/pow_of_formal_power_series) | `Library Checker` | `Hard` | Formal Power Series, NTT | Implementation; Advanced Algebra | Fps Log; Fps Exp | Power; Log-Exp; Advanced | A good later verifier once inverse/log/exp are in place and FPS algebra starts to feel compositional instead of magical. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `INVOFFORMALPOWERSERIES` | Inv of Formal Power Series | `primary` | `hard` | - | [Note](../../../practice/ladders/math/polynomial-fps/invofformalpowerseries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/polynomial-fps/invofformalpowerseries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
