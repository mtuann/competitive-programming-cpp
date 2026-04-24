# Strings, Math, And Counting 01

This pack is for `symbolic pattern switching`: string borders, modular reasoning, and combinatorial counting in one sitting.

## Who This Is For

Use this pack if:

- you already know at least one string matching technique
- modular exponentiation and basic combinatorics are familiar, but slow to recall under pressure
- you want a round where recognition matters more than heavy implementation

## Entry Gate

Try this pack only if these already feel like review:

- [String Matching](../ladders/strings/kmp/stringmatching.md)
- [Finding Periods](../ladders/strings/z-function/findingperiods.md)
- [Exponentiation II](../ladders/math/modular-arithmetic/exponentiation2.md)
- [Distributing Apples](../ladders/combinatorics/counting-basics/distributingapples.md)
- [Prime Multiples](../ladders/combinatorics/inclusion-exclusion/primemultiples.md)

## Pack Shape

- Type: `review and switching drill`
- Topic mix: `KMP + Z-function + modular arithmetic + counting basics + inclusion-exclusion`
- Problems: `5`
- Suggested time: `2.5-3.5 hours`

## Topics Under Test

- recognizing fallback-table string scans
- turning prefix/suffix alignment into one linear-time check
- reducing exponents before computing powers
- mapping a story directly to a counting model
- keeping inclusion-exclusion signs and overflow guards disciplined

## Suggested Order

| Slot | Problem | Topic | Why it is here |
| --- | --- | --- | --- |
| 1 | [String Matching](../ladders/strings/kmp/stringmatching.md) | `KMP` | Starts with one crisp pattern-matching engine and overlap handling. |
| 2 | [Finding Periods](../ladders/strings/z-function/findingperiods.md) | `Z-function` | Keeps you in strings but changes the recognition cue from matching to periodicity. |
| 3 | [Exponentiation II](../ladders/math/modular-arithmetic/exponentiation2.md) | `Modular arithmetic` | Breaks the string rhythm with one algebraic reduction problem. |
| 4 | [Distributing Apples](../ladders/combinatorics/counting-basics/distributingapples.md) | `Stars and bars` | Switches from formula manipulation to direct counting-model recognition. |
| 5 | [Prime Multiples](../ladders/combinatorics/inclusion-exclusion/primemultiples.md) | `Inclusion-exclusion` | Finishes with a subset-sign problem where the main risk is logical drift, not code length. |

## How To Run It

- solve in order so the round alternates between symbolic string reasoning and arithmetic/counting reasoning
- keep one scratch line per slot: `first wrong instinct`
- if recognition is still fuzzy after about `12-15 minutes`, allow one refresher page but not the solved note
- if one slot still feels dead after about `25-30 minutes`, move on and return only during debrief

## Allowed Refreshers

- [String cheatsheet](../../notebook/string-cheatsheet.md)
- [Number theory cheatsheet](../../notebook/number-theory-cheatsheet.md)
- [Combinatorics cheatsheet](../../notebook/combinatorics-cheatsheet.md)
- [KMP](../../topics/strings/kmp/README.md)
- [Modular Arithmetic](../../topics/math/modular-arithmetic/README.md)

## Debrief

After the pack, write down:

1. Which slot you recognized fastest, and what cue triggered it.
2. Whether your string slots felt more mechanical or more conceptual than the counting slots.
3. Which formula or invariant you should now be able to restate without reopening the note.

## Go Back Next

- if slots `1-2` were weak, revisit [KMP](../ladders/strings/kmp/README.md) or [Z-Function](../ladders/strings/z-function/README.md)
- if slot `3` was weak, revisit [Modular Arithmetic](../ladders/math/modular-arithmetic/README.md)
- if slots `4-5` were weak, revisit [Counting Basics](../ladders/combinatorics/counting-basics/README.md) or [Inclusion-Exclusion](../ladders/combinatorics/inclusion-exclusion/README.md)
- if the whole pack felt manageable, go back to [Contest Core Switching 01](contest-core-switching-01.md) and compare which family still costs you the most recognition time
