# Route Map

Use this page when you do **not** need the repo explained section by section.

Use it when you need one of these instead:

- one route that fits your current level
- one route that fits your current bottleneck
- one route that fits your contest track

This page uses learner `Stage 1-4` language. If you want the content-progression map by area, use the curriculum `Level 0-5` view in [Project Overview](../project-readme.md).

## Pick By Situation

| If you are here because... | Start with | Then go next |
| --- | --- | --- |
| you are completely new | [Start Here](start-here.md) | [Foundations ladders](../practice/ladders/foundations/README.md) |
| you want a learner-stage route instead of a topic list | [Start Here](start-here.md) | the `Learner Stage Plan` section there, then either [Foundations ladders](../practice/ladders/foundations/README.md), [Learning Areas](../topics/README.md), [Practice hub](../practice/README.md), or [Contest Playbooks](../practice/contest-playbooks/README.md) |
| you know basics but your practice is inconsistent | [Practice hub](../practice/README.md) | [Ladders](../practice/ladders/README.md) |
| you already know the weak topic | [Learning Areas](../topics/README.md) | the corresponding ladder, then one repo note |
| you want contest-style training | [Contest Playbooks](../practice/contest-playbooks/README.md) | [Mixed Rounds](../practice/mixed-rounds/README.md) and [Problem Finder](problem-finder.md) |
| you are debugging or implementing under pressure | [Build Kit](build-kit.md) | [Notebook](../notebook/README.md) |

## Door Meanings

Use the repo doors for different jobs:

| Door | Main job | Open it when... |
| --- | --- | --- |
| [Topics](../topics/README.md) | teach the idea slowly and correctly | you still need the invariant, proof, or variant chooser |
| [Ladders](../practice/ladders/README.md) | give focused same-family repetitions | the idea is roughly known but recognition is not yet stable |
| one solved note in `practice/ladders/.../*.md` | show the statement-to-pattern transformation | you want to compare one real contest problem to the reusable family |
| [Notebook](../notebook/README.md) | recall the invariant, trap, or nearest snippet fast | the topic is mostly known and retrieval is the bottleneck |
| [Build Kit](build-kit.md) | route to workflows, templates, and checklists | implementation trust is weaker than topic understanding |
| [Mixed Rounds](../practice/mixed-rounds/README.md) | test switching across known topics | breadth and retrieval are now the real bottleneck |
| [Contest Playbooks](../practice/contest-playbooks/README.md) | train toward one format | your question is about performance under `ICPC`, `USACO`, or olympiad-style constraints |

## Route Shapes

### Beginner Route

1. [Start Here](start-here.md)
2. [Foundations overview](../topics/foundations/README.md)
3. [Foundations ladders](../practice/ladders/foundations/README.md)
4. one first repo note inside the ladder
5. [Foundations cheatsheet](../notebook/foundations-cheatsheet.md)

Use this when syntax, local workflow, and first recognition cues are still the bottleneck.

### Topic-First Route

1. [Learning Areas](../topics/README.md)
2. one area overview
3. one leaf topic page
4. the corresponding ladder
5. one repo note
6. [Build Kit](build-kit.md) or [Notebook](../notebook/README.md) only after the idea is trusted

Use this when you want depth before speed.

### Practice-First Route

1. [Practice hub](../practice/README.md)
2. [Problem Finder](problem-finder.md)
3. one ladder or one mixed round
4. the corresponding topic page only when recognition is fuzzy
5. [Notebook](../notebook/README.md) or [Build Kit](build-kit.md) when retrieval or implementation becomes the bottleneck

Use this when you already know some ideas and need more reps, not more taxonomy.

### Contest Route

1. [Contest Playbooks](../practice/contest-playbooks/README.md)
2. one track page: [USACO](../practice/contest-playbooks/usaco.md), [IOI / OI](../practice/contest-playbooks/ioi-oi.md), or [ICPC](../practice/contest-playbooks/icpc.md)
3. [Mixed Rounds](../practice/mixed-rounds/README.md)
4. [Notebook](../notebook/README.md)
5. [Build Kit](build-kit.md)

Use this when your question is no longer “what is this algorithm?” and is now “how do I perform under this format?”

## Pick By Bottleneck

| Your bottleneck | Best first door | Best second door |
| --- | --- | --- |
| weak C++ / compile / local loop | [Start Here](start-here.md) | [Build Kit](build-kit.md) |
| weak topic recognition | [Learning Areas](../topics/README.md) | [Ladders](../practice/ladders/README.md) or one anchored note |
| weak retrieval during implementation | [Notebook](../notebook/README.md) | [Template Library](../template-library.md) |
| weak problem selection | [Problem Finder](problem-finder.md) | [Practice hub](../practice/README.md) |
| weak contest switching | [Mixed Rounds](../practice/mixed-rounds/README.md) | [Contest Playbooks](../practice/contest-playbooks/README.md) |
| weak post-contest follow-through | [Contest Playbooks](../practice/contest-playbooks/README.md) | [Problem Finder](problem-finder.md) |

## High-Value Bridge Pages

These are the family pages worth reopening before you dive into a narrower
leaf, especially when the repo starts feeling wider than your current mental
map.

| If the family feels fragmented | Reopen this bridge page first | Then branch into... |
| --- | --- | --- |
| tree topics | [Trees](../topics/graphs/trees/README.md) | Euler tour, LCA, tree DP, HLD, virtual tree |
| flow and cut topics | [Maximum Flow](../topics/graphs/flow/README.md) | global min-cut, Gomory-Hu, lower bounds, min-cost flow |
| divisibility and congruence topics | [GCD / LCM](../topics/math/gcd-lcm/README.md) | CRT, modular arithmetic, prime-exponent constructions |
| transform topics | [FFT / NTT](../topics/math/fft-ntt/README.md) | polynomial / FPS |
| subset-state bit work | [Bit Tricks](../topics/foundations/bit-tricks/README.md) | bitmask DP, xor basis, SOS, FWHT, bit-parallelism |
| explicit search trees | [Recursion And Backtracking](../topics/foundations/recursion-backtracking/README.md) | bitmask DP, meet-in-the-middle, complexity triage |
| monotone scan structures | [Monotonic Stack / Queue](../topics/data-structures/monotonic-stack-queue/README.md) | sliding-window extrema, nearest-greater/smaller, histogram boundaries |

## The Core Loop

When in doubt, fall back to this:

1. learn one idea in `topics/`
2. stay inside the corresponding ladder in `practice/ladders/`
3. solve one anchored note there
4. reopen one reusable snippet or workflow through [Build Kit](build-kit.md)
5. compress the invariant in [Notebook](../notebook/README.md)
6. return later through [Mixed Rounds](../practice/mixed-rounds/README.md)

That is the repo's default `Learn -> Practice -> Retrieve -> Reuse -> Switch` loop.

## Good Companion Doors

- [Build Kit](build-kit.md): templates, notebook, and workflows
- [Problem Finder](problem-finder.md): choose the next problem set
- [Topic Maps](topic-maps/index.md): source-backed reading and coverage lookup
- [Project Overview](../project-readme.md): the full curriculum-level map
