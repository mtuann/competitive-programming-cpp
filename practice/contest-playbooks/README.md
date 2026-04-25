# Contest Playbooks

Contest playbooks are the track-specific operating manuals of this repo.

Use them when you already know some core topics and now need answers to questions like:

- what does this contest format actually reward?
- how should I practice for it with the assets already in this repo?
- what should I do before, during, and after a contest?

This folder is **freshness-sensitive** content.

- last reviewed: `2026-04-25`
- official or primary sources were rechecked during this pass

## What This Folder Is For

Open a playbook when:

- you want a contest-format-specific training loop
- you want to know which repo pages matter most for one track
- your bottleneck is no longer "learn one topic", but "convert knowledge into results under that format"

Do **not** open this folder first if you are still learning core syntax or first-exposure algorithms.

Go to:

- [Start Here](../../docs/start-here.md) if syntax or local workflow is still shaky
- [Ladders](../ladders/README.md) if one topic family is still unstable
- [Build Kit](../../docs/build-kit.md) if implementation trust or local testing is the real bottleneck
- [Topic Maps](../../docs/topic-maps/index.md) if you need broader external study references
- [Contest Engineering](../../topics/advanced/contest-engineering/README.md) if the issue is contest-time process rather than topic depth

first.

## Track Chooser

| Track | Optimizes for | Practice mode | Biggest failure signal | Best first repo asset |
| --- | --- | --- | --- | --- |
| [USACO](usaco.md) | solo implementation, steady division progression, clean local testing | archive-first, topic ladders, timed solo blocks | you solve ideas after contest but miss easy implementation points during it | [C++ Language](../../topics/foundations/cpp-language/README.md) |
| [Codeforces](codeforces.md) | short-round shipping, anti-hack discipline, and clean upsolve loops | short simulated rounds, validator-first clinics, fast review blocks | you often know the family after the round, but miss live solves to pacing, hack fear, or weak hardening | [Contest Engineering](../../topics/advanced/contest-engineering/README.md) |
| [IOI / OI](ioi-oi.md) | deep modeling, proof confidence, partial-score planning | fewer tasks, deeper review, subtask-first thinking | you see the full idea too late or throw away safe partial points | [Reasoning](../../topics/foundations/reasoning/README.md) |
| [ICPC](icpc.md) | breadth, switching, team workflow, one-machine execution | mixed rounds, live triage, notebook retrieval | your team burns time on one hard problem or loses solves to bad handoff/debug loops | [Contest Engineering](../../topics/advanced/contest-engineering/README.md) |

## Start Today

| If your current format target is... | Start with |
| --- | --- |
| solo progression with archive problems | [USACO](usaco.md) |
| short rounds with hacks, rejudge pressure, or fast upsolve loops | [Codeforces](codeforces.md) |
| partial scoring and proof-heavy tasks | [IOI / OI](ioi-oi.md) |
| breadth, switching, and one-machine teamwork | [ICPC](icpc.md) |

## Track Drill Index

Use this table when you want one executable drill instead of more prose.

| Track | First drill | Use when | If it breaks, reopen |
| --- | --- | --- | --- |
| [USACO](usaco.md) | `Solo Archive Block 01` in [USACO](usaco.md) | you want a clean timed solo block with explicit post-contest review | [Foundations ladders](../ladders/foundations/README.md), [Problem Finder](../../docs/problem-finder.md), or [Local Judge Workflow](../../notebook/local-judge-workflow.md) |
| [Codeforces](codeforces.md) | [Codeforces Short Round 01](../mixed-rounds/codeforces-short-round-01.md) | you want one short simulated round with banker-first shipping, anti-hack passes, and a precise upsolve route | [Codeforces Upsolve Worksheet](codeforces-upsolve-worksheet.md), [Anti-Hack Workflow](../../notebook/anti-hack-workflow.md), or [Problem Finder](../../docs/problem-finder.md) |
| [IOI / OI](ioi-oi.md) | [IOI Checkpoint / Score-Path Drill 01](ioi-checkpoint-score-path-drill-01.md) | you need to practice safe-point collection before gambling on the full solve | [Reasoning](../../topics/foundations/reasoning/README.md), [Stress Testing Workflow](../../notebook/stress-testing-workflow.md), or [DP ladders](../ladders/dp/README.md) |
| [ICPC](icpc.md) | [ICPC Modeling Under Pressure 01](icpc-modeling-under-pressure-01.md) | you want a repeatable opening model, priority board, and one-machine-ready handoff | [Mixed Rounds](../mixed-rounds/README.md), [Contest Engineering](../../topics/advanced/contest-engineering/README.md), or [Build Kit](../../docs/build-kit.md) |

## Contest-Source Clinics

These are not full track playbooks yet. They are source-family clinics mined from contest ecosystems that reward one distinctive operating habit.

| Source lane | Start with | Use when | If it breaks, reopen |
| --- | --- | --- | --- |
| `Code Jam / Kick Start` | [Code Jam / Kick Start Analysis-First Clinic 01](code-jam-kick-start-analysis-first-clinic-01.md) | you keep seeing the idea only after the official analysis because the `small -> large` bridge never became explicit | [Reasoning](../../topics/foundations/reasoning/README.md), [Binary Search](../../topics/foundations/patterns/binary-search/README.md), or [Digit DP](../../topics/dp/digit-dp/README.md) |
| `Distributed Code Jam-style decomposition` | [Distributed Decomposition Clinic 01](distributed-decomposition-clinic-01.md) | you want to practice `split -> summarize -> merge` without opening a full distributed platform first | [Graph Modeling](../../topics/graphs/graph-modeling/README.md), [Subtree Queries](../../topics/graphs/euler-tour-subtree/README.md), or [Reasoning](../../topics/foundations/reasoning/README.md) |
| `Topcoder one hard problem` | [Topcoder One-Hard-Problem Clinic 01](topcoder-one-hard-problem-clinic-01.md) | one hard slot keeps eating the whole session even when the topic is mostly known | [Topcoder Weird-Task Clinic 01](topcoder-weird-task-clinic-01.md), [Reasoning](../../topics/foundations/reasoning/README.md), or the corresponding advanced ladder |
| `Topcoder weird statement surfaces` | [Topcoder Weird-Task Clinic 01](topcoder-weird-task-clinic-01.md) | the wrapper looks exotic enough that you never stabilize the object model | [Graph Modeling](../../topics/graphs/graph-modeling/README.md), [Constructive](../../topics/advanced/constructive/README.md), or [Counting Geometry](../../topics/geometry/counting-geometry/README.md) |

## Shared Repo Kit

Every mature playbook should route through the same repo layers:

| Layer | Main job | Best shared doors |
| --- | --- | --- |
| `topics/` | teach the reusable idea | [Learning Areas](../../topics/README.md) |
| `practice/ladders/` | sequence one subtopic on purpose | [Ladders](../ladders/README.md) |
| `docs/problem-finder` | choose the next concrete problem set quickly | [Problem Finder](../../docs/problem-finder.md) |
| `practice/mixed-rounds/` | retrieval and switching after topics are known | [Mixed Rounds](../mixed-rounds/README.md) |
| `notebook/` | short contest-time recall | [Notebook](../../notebook/README.md), [Contest Checklist](../../notebook/contest-checklist.md) |
| `templates/` | reusable code you can retrieve on demand | [Template Library](../../template-library.md) |
| `workflow pages` | exact operational loops | [Local Judge Workflow](../../notebook/local-judge-workflow.md), [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) |

## Open This Next

| If today's question is... | Open |
| --- | --- |
| what should I practice next? | [Problem Finder](../../docs/problem-finder.md) |
| what format am I training for? | one track page below |
| what do I reopen during implementation? | [Build Kit](../../docs/build-kit.md) |

## Playbook Contract

Every contest playbook page should answer:

1. `What does this track reward?`
2. `Who should use this page right now?`
3. `What are the 3-5 highest-payoff skills to optimize?`
4. `Which repo assets should I open first?`
5. `What is my default training rhythm?`
6. `What should I do before, during, and after a contest?`
7. `What failure modes are most common in this format?`
8. `How do I know I am ready to move up or change training mode?`
9. `Which drill or worksheet should I run next?`

Canonical section set:

- `Track Snapshot`
- `Who This Is For`
- `What To Optimize`
- `Repo Route`
- `Training Rhythm`
- `Before A Contest`
- `Drills / Worksheets`
- `During A Contest`
- `After A Contest`
- `Common Failure Modes`
- `Failure -> Next Repo Door`
- `Progress Markers`
- `References And Repo Anchors`

## Current Playbooks

- [USACO](usaco.md): solo archive-based progression with strict contest-conduct rules
- [Codeforces](codeforces.md): short-round operating manual for shipping, anti-hack, validator-first construction, and upsolve discipline
- [IOI / OI](ioi-oi.md): proof-heavy partial-scoring workflow
- [ICPC](icpc.md): team contest operating manual for breadth, triage, and one-machine execution
- [Code Jam / Kick Start Analysis-First Clinic 01](code-jam-kick-start-analysis-first-clinic-01.md): `small -> large` promotion and analysis-first solving
- [Distributed Decomposition Clinic 01](distributed-decomposition-clinic-01.md): local summary and merge-contract thinking
- [Topcoder One-Hard-Problem Clinic 01](topcoder-one-hard-problem-clinic-01.md): one-hard-slot proof and system-test discipline
- [Topcoder Weird-Task Clinic 01](topcoder-weird-task-clinic-01.md): strange statement surfaces turned into canonical models

## Good Pairings

- if a playbook says "your retrieval is the bottleneck", reopen [Notebook](../../notebook/README.md)
- if it says "your topic depth is the bottleneck", reopen `topics/`
- if it says "your switching is weak", reopen [Mixed Rounds](../mixed-rounds/README.md)
- if it says "your process is weak", reopen [Contest Engineering](../../topics/advanced/contest-engineering/README.md)

## Research Notes

This layer was refreshed against official or primary pages on `2026-04-25`.

Shared sources used for this pass:

- [USACO Details / FAQ](https://usaco.org/current/current/index.php?page=details)
- [USACO Contest Instructions and Rules](https://usaco.org/index.php/current/tpcm/current/data/index.php?page=instructions)
- [USACO Training](https://usaco.org/index.php?page=training)
- [Codeforces Contest Rules](https://codeforces.com/blog/entry/4088?locale=en)
- [Rule Restricting the Use of AI [revision 2024-09-14]](https://codeforces.com/topic/134567/en4)
- [Interactive Problems: Guide for Participants](https://codeforces.com/blog/entry/45307?mobile=true)
- [ICPC World Finals Programming Environment](https://docs.icpc.global/worldfinals-programming-environment/)
- [ICPC Regional Rules example (NCNA 2025/26)](https://nc.na.icpc.global/rules/)
- [IOI Regulations](https://ioinformatics.org/files/regulations03.pdf)
- [IOI Syllabus](https://ioinformatics.org/page/syllabus/)
- [Celebrate Google's Coding Competitions with a final round of programming fun](https://developers.googleblog.com/celebrate-googles-coding-competitions-with-a-final-round-of-programming-fun/)
- [google/coding-competitions-archive](https://github.com/google/coding-competitions-archive)
- [A Decade of Kick Start](https://developers.googleblog.com/en/a-decade-of-kick-start/)
- [Single Round Matches (SRMs) - Topcoder Support](https://help.topcoder.com/hc/en-us/articles/24954129102491-Single-Round-Matches-SRMs)
- [Competitive Programming at Topcoder](https://www.topcoder.com/community/arena)
- [Competing in a Topcoder Rated Event](https://www.topcoder.com/community/competitive-programming/how-to-compete/ratedEvent)
