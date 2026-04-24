# Contest Playbooks

Contest playbooks are the track-specific operating manuals of this repo.

Use them when you already know some core topics and now need answers to questions like:

- what does this contest format actually reward?
- how should I practice for it with the assets already in this repo?
- what should I do before, during, and after a contest?

This folder is **freshness-sensitive** content.

- last reviewed: `2026-04-24`
- official or primary sources were rechecked during this pass

## What This Folder Is For

Open a playbook when:

- you want a contest-format-specific training loop
- you want to know which repo pages matter most for one track
- your bottleneck is no longer "learn one topic", but "convert knowledge into results under that format"

Do **not** open this folder first if you are still learning core syntax or first-exposure algorithms.

Go to:

- [Start Here](../../docs/start-here.md)
- [Topic Maps](../../docs/topic-maps/index.md)
- [Contest Engineering](../../topics/advanced/contest-engineering/README.md)

first.

## Track Chooser

| Track | Optimizes for | Practice mode | Biggest failure signal | Best first repo asset |
| --- | --- | --- | --- | --- |
| [USACO](usaco.md) | solo implementation, steady division progression, clean local testing | archive-first, topic ladders, timed solo blocks | you solve ideas after contest but miss easy implementation points during it | [C++ Language](../../topics/foundations/cpp-language/README.md) |
| [IOI / OI](ioi-oi.md) | deep modeling, proof confidence, partial-score planning | fewer tasks, deeper review, subtask-first thinking | you see the full idea too late or throw away safe partial points | [Reasoning](../../topics/foundations/reasoning/README.md) |
| [ICPC](icpc.md) | breadth, switching, team workflow, one-machine execution | mixed rounds, live triage, notebook retrieval | your team burns time on one hard problem or loses solves to bad handoff/debug loops | [Contest Engineering](../../topics/advanced/contest-engineering/README.md) |

## Start Today

| If your current format target is... | Start with |
| --- | --- |
| solo progression with archive problems | [USACO](usaco.md) |
| partial scoring and proof-heavy tasks | [IOI / OI](ioi-oi.md) |
| breadth, switching, and one-machine teamwork | [ICPC](icpc.md) |

## Shared Repo Kit

Every mature playbook should route through the same repo layers:

| Layer | Main job | Best shared doors |
| --- | --- | --- |
| `topics/` | teach the reusable idea | [Topic Maps](../../docs/topic-maps/index.md) |
| `practice/ladders/` | sequence one subtopic on purpose | [Practice Hub](../README.md) |
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

Canonical section set:

- `Track Snapshot`
- `Who This Is For`
- `What To Optimize`
- `Repo Route`
- `Training Rhythm`
- `Before A Contest`
- `During A Contest`
- `After A Contest`
- `Common Failure Modes`
- `Progress Markers`
- `References And Repo Anchors`

## Current Playbooks

- [USACO](usaco.md): solo archive-based progression with strict contest-conduct rules
- [IOI / OI](ioi-oi.md): proof-heavy partial-scoring workflow
- [ICPC](icpc.md): team contest operating manual for breadth, triage, and one-machine execution

## Good Pairings

- if a playbook says "your retrieval is the bottleneck", reopen [Notebook](../../notebook/README.md)
- if it says "your topic depth is the bottleneck", reopen `topics/`
- if it says "your switching is weak", reopen [Mixed Rounds](../mixed-rounds/README.md)
- if it says "your process is weak", reopen [Contest Engineering](../../topics/advanced/contest-engineering/README.md)

## Research Notes

This layer was refreshed against official or primary pages on `2026-04-24`.

Shared sources used for this pass:

- [USACO Details / FAQ](https://usaco.org/current/current/index.php?page=details)
- [USACO Contest Instructions and Rules](https://usaco.org/index.php/current/tpcm/current/data/index.php?page=instructions)
- [USACO Training](https://usaco.org/index.php?page=training)
- [ICPC World Finals Programming Environment](https://docs.icpc.global/worldfinals-programming-environment/)
- [ICPC Regional Rules example (NCNA 2025/26)](https://nc.na.icpc.global/rules/)
- [IOI Regulations](https://ioinformatics.org/files/regulations03.pdf)
- [IOI Syllabus](https://ioinformatics.org/page/syllabus/)
