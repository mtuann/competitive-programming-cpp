# Precision / Formatting Robustness Clinic 01

## Who This Is For

Use this clinic if:

- the main idea is mostly correct, but accepted-looking numeric output still feels brittle
- you keep leaking archive-style tasks to `setprecision`, rounding, or the wrong arithmetic representation
- your post-mortems say `should have stayed integer`, `printed too few digits`, or `used double too casually`

## Entry Gate

Run this only if the core algorithm family is already mostly known.

Good prerequisite doors:

- [Foundations cheatsheet](../../notebook/foundations-cheatsheet.md)
- [C++ Language For Contests](../../topics/foundations/cpp-language/README.md)
- [Code Jam / Kick Start Analysis-First Clinic 01](code-jam-kick-start-analysis-first-clinic-01.md)

If the real issue is still choosing the algorithm family, go back to the relevant topic and ladder first.

## Clinic Goal

- turn `the model is fine` into `the arithmetic regime and final output contract are both safe`

The point is not to memorize one `cout << fixed << setprecision(...)` spell.

The point is to decide early:

- should the solution stay in exact integer arithmetic?
- should it use scaled integers?
- should it use `long double`?
- what output tolerance or formatting contract actually needs to be satisfied?

## Starter Reps

Pick **one** of these per clinic run:

- [Polygon Area](../ladders/geometry/polygon-area-point-location/polygonarea.md)
- [Dice Probability](../ladders/math/probability/diceprobability.md)
- [VOTELPH](../ladders/geometry/sweep-line/votelph.md)

These three cover the most common contest-time decisions:

- stay exact in doubled-area integer form
- accumulate probabilities safely and print a fixed decimal format
- mix preprocessing with scaled arithmetic and a precise final rendering step

## Running Rules

### Step 1: Fill The Numeric Contract Card

Write this card before polishing code:

| Item | Your answer |
| --- | --- |
| exact output type expected by the judge |  |
| exact arithmetic possible? |  |
| if not, what floating type and why? |  |
| output tolerance or decimal requirement |  |
| last step where rounding is allowed |  |
| one smallest value family that could expose drift |  |

If the first four rows are fuzzy, you are still coding under vibes.

### Step 2: Choose The Arithmetic Regime Early

Pick one of these deliberately:

- `exact integer arithmetic`
  - use when the statement is exact and a transformed integer form exists
- `scaled integer arithmetic`
  - use when inputs live on a fixed decimal grid and scaling removes avoidable floating error
- `long double` or careful `double`
  - use only when the real-valued model is truly part of the problem

Do **not** slide into floating point just because the statement shows decimals.

### Step 3: Delay Formatting Until The End

Keep internal state in the strongest trustworthy form you have.

Typical safe patterns:

- geometry -> doubled area or squared distance first, then print once
- probability / expectation -> accumulate in `long double`, then format once
- scaled numeric grid -> keep scaled integers through all transitions, then divide only at the output boundary

Formatting should be a serialization step, not part of the algorithm.

### Step 4: Treat Tolerance As A Contract, Not A Guess

If the statement accepts absolute or relative error:

- print enough digits that formatting is not the bottleneck
- avoid premature rounding inside the algorithm
- make sure your local spot checks hit values near `0`, near boundaries, and near cancellation

If the statement wants an exact decimal count like `6` places, print exactly that only at the end.

### Step 5: Build Tiny Numeric Edge Families

Attack one small case from each family that applies:

- exact integer result that should stay exact
- very small positive answer
- values near a formatting boundary such as `x.xxx4999...` or `x.xxx5000...`
- repeated additions where drift can accumulate
- one case where scaling avoids a floating comparison entirely

The goal is not huge stress. The goal is to break the weakest arithmetic choice quickly.

### Step 6: Separate Model Error From Numeric Error

When the answer is wrong, decide first:

- did the model compute the wrong mathematical quantity?
- or did the quantity drift only when represented or printed?

If that split is unclear, debugging becomes much slower than it needs to be.

## Allowed Refreshers

- [Foundations cheatsheet](../../notebook/foundations-cheatsheet.md)
- [C++ Language For Contests](../../topics/foundations/cpp-language/README.md)
- [Probability hot sheet](../../notebook/probability-hot-sheet.md)
- [Geometry cheatsheet](../../notebook/geometry-cheatsheet.md)
- [FFT / NTT](../../topics/math/fft-ntt/README.md) when the real issue is floating convolution trust rather than simple decimal formatting

## Success Criteria

- you can name the arithmetic regime before coding the final version
- rounding happens in one obvious place, not all over the algorithm
- one tiny numeric edge family has been checked on purpose
- you can explain why the printed format is sufficient instead of saying `I hope enough digits is fine`

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| the real issue is still `small -> large` promotion, not numeric robustness | [Code Jam / Kick Start Analysis-First Clinic 01](code-jam-kick-start-analysis-first-clinic-01.md) |
| the task accepts many legal outputs and the contract itself is still fuzzy | [Many-Valid-Answers / Validator-First Workflow](../../notebook/many-valid-answers-validator-first-workflow.md) |
| you need a checker / scorer loop more than arithmetic discipline | [Special Judge / Output Protocol Workflow](../../notebook/special-judge-output-protocol-workflow.md) |
| the clean route is to stay exact in integer geometry | [Geometry cheatsheet](../../notebook/geometry-cheatsheet.md) and the relevant geometry topic |
| the real issue is plain implementation trust, not numbers | [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) |

## After This Clinic

- rerun one archived or repo-native numeric task after rewriting only the arithmetic contract card
- then log one sentence naming the first true leak:
  - `wrong regime`
  - `premature rounding`
  - `too few digits`
  - `should have stayed integer`
  - `model was wrong before formatting even mattered`

## References And Repo Anchors

Research snapshot refreshed on `2026-04-25`.

Official / primary:

- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)
- [A Decade of Kick Start](https://developers.googleblog.com/en/a-decade-of-kick-start/)
- [Single Round Matches (SRMs) - Topcoder Support](https://help.topcoder.com/hc/en-us/articles/24954129102491-Single-Round-Matches-SRMs)

Repo anchors:

- [Polygon Area](../ladders/geometry/polygon-area-point-location/polygonarea.md)
- [Dice Probability](../ladders/math/probability/diceprobability.md)
- [VOTELPH](../ladders/geometry/sweep-line/votelph.md)
- [C++ Language For Contests](../../topics/foundations/cpp-language/README.md)
