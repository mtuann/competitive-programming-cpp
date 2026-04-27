# Expansion Roadmap

- Purpose: phased TODO list for future algorithm coverage, contest-source integration, and practice-system expansion
- Scope: new topic pages, starter templates, notebook hot sheets, ladders, mixed rounds, playbooks, and freshness audits
- Doc type: planning
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-25
- Update triggers: after each expansion wave, after any major reprioritization, or after a new external-source audit
- Canonical companion docs: [Roadmap](roadmap.md), [Algorithm Gap Roadmap](algorithm-gap-roadmap.md), [Book Coverage Roadmap](book-coverage-roadmap.md), [Visual Roadmap](visual-roadmap.md), [Content Blueprint](content-blueprint.md), [Topic Template](topic-template.md), [Source Map](source-map.md)

This file exists so future expansion work stays phased, source-backed, and small enough to preserve quality.

## How To Use This File

- use this for `post-core` expansion only
- keep the main [Roadmap](roadmap.md) for repo-wide maintenance and cross-layer priorities
- mark a task complete only after the relevant topic, retrieval, and practice routes all ship together
- prefer small waves over broad backlog dumps

## Working Rules

### Wave Cap

- no wave may introduce more than `2` new deep topics
- no wave may introduce more than `1` new content surface at a time
- do not run more than `2` topic waves in a row without a reinforcement wave
- keep `advanced / proof-heavy` topics to `1` per wave unless the second item is much lighter

### Alternation Rule

- after `2` topic waves, run a reinforcement wave
- reinforcement waves can be:
  - retrieval / hot-sheet alignment
  - ladder / solved-note reinforcement
  - mixed rounds
  - playbook / workflow drills
- do not combine `mixed rounds` and `playbooks` into the same wave

### Ship Gates

- `Topic wave gate`: every new topic must ship with a mature topic page, ladder placement, at least one anchored flagship note, and a clear `Build Kit / Template Library / Problem Finder` route
- `Retrieval gate`: if a topic is important enough to appear in mixed rounds or playbooks, it should already have a hot sheet or a strong parent cheatsheet route
- `Practice gate`: no mixed-round pack unless every tested topic already has stable teaching and retrieval pages
- `Playbook gate`: no new track drill unless the relevant mixed-round or practice route already exists
- `Freshness gate`: every playbook, route page, or workflow page in a wave must verify current official links during that pass
- `Build gate`: `generate_problem_catalog --validate-only`, `build_site_docs.py`, `mkdocs build --strict`, and `git diff --check` must pass before a wave is considered shipped

## Current Synthesis

### 2026-04-25 Reprioritization Result

The repo is no longer in the same state as the early backlog that created this file.

- the old `highest-value canonical gaps` listed here have now been shipped
- the explicit `contest-system` backlog in this file has also been shipped at the current intro / clinic / drill level
- future waves should now open from `Freshness Backbone` findings, sweep results, or exact-anchor deficits rather than from a standing list of "obvious next missing topics"

### Source Families To Keep Watching

These should still be treated as content-source families, not just random inspiration.

- `IOI / OI`: subtask-first planning, checkpointing, score-path design, proof discipline
- `ICPC`: breadth, modeling under pressure, team triage, communication, implementation-heavy mixed sets
- `Codeforces`: short-round shipping, anti-hack, validator-first constructive work, implementation clinics, interactive discipline
- `Topcoder / TCO`: one-hard-problem culture, weird-task clinics, marathon / heuristic bridge
- `Google archive lane (Code Jam / Kick Start / Distributed Code Jam)`: small-vs-large escalation, analysis-first solving, custom judge discipline, distributed decomposition
- `Petrozavodsk / OpenCup / Andrew Stankevich`: advanced mixed modeling, hard implementation, camp-style drills

### Open Candidate Pools, Not Standing Commitments

These are legitimate future directions, but none of them should open automatically without an audit trigger or strong repo-fit anchor.

The main standing queue for those future algorithm-family additions now lives in [Algorithm Gap Roadmap](algorithm-gap-roadmap.md).

- `contest-source reinforcement`:
  - `communication / output-only / output-scored` drills if a later olympiad or Google-style audit justifies them
  - a deeper `heuristic / marathon` lane only after the repo gains exact internal anchors beyond the current intro clinic
- `long-tail algorithm expansions`:
  - only when the `VNOI Wiki` / `USACO Guide Advanced` / `CP-Algorithms` trio still shows a persistent gap and the repo can support an exact starter route plus flagship note
- `reinforcement rather than expansion`:
  - sweep-driven router cleanup
  - exact-anchor densification
  - source-sensitive wording refreshes

## Now

These are the next waves with the highest ROI and the cleanest fit with the current repo.

### Phase 0. Freshness Backbone

- [x] add `docs/freshness-backbone.md` as the maintainer page for external-source audits
- [x] define a quarterly audit cadence for `VNOI Wiki`, `USACO Guide Advanced`, `CP-Algorithms`, `IOI syllabus/stats`, `ICPC WF problem sets`, official `Codeforces` ecosystem pages, and the newer contest-source lanes
- [x] write a short maintainer checklist for deciding whether a new external pattern becomes a `topic page`, `playbook drill`, `mixed round`, or `hot sheet`
- [x] run the first `freshness audit / reprioritization pass` and convert the expansion spine from `backlog-driven` to `audit-driven`

### Phase 1. Canonical Graph Wave A

- [x] add `topics/graphs/two-sat/README.md`
- [x] add `templates/graphs/two-sat.cpp`
- [x] add `notebook/two-sat-hot-sheet.md`
- [x] add `practice/ladders/graphs/two-sat/README.md`
- [x] add one flagship `2-SAT` note plus solution
- [x] add `topics/graphs/bridges-articulation/README.md`
- [x] add `templates/graphs/bridges-articulation-lowlink.cpp`
- [x] add `notebook/lowlink-hot-sheet.md`
- [x] add `practice/ladders/graphs/bridges-articulation/README.md`
- [x] add one flagship low-link note plus solution
- [x] wire both topics into `Build Kit`, `Template Library`, `Problem Finder`, and graph hub/router pages

### Phase 2. Contest-System Drill Wave A

- [x] add an `IOI subtask-first worksheet`
- [x] add an `IOI checkpoint / score-path drill`
- [x] add an `ICPC modeling-under-pressure drill`
- [x] add one `ICPC breadth + implementation` mixed round
- [x] update `practice/contest-playbooks/ioi-oi.md` with exact drill doors
- [x] update `practice/contest-playbooks/icpc.md` with exact drill doors

### Phase 3. Repo-Fit Data Structure Wave A

- [x] add `topics/data-structures/lazy-segment-tree/README.md`
- [x] add `templates/data-structures/segment-tree-lazy-range-add-sum.cpp`
- [x] add `notebook/lazy-segment-tree-hot-sheet.md`
- [x] add `practice/ladders/data-structures/lazy-segment-tree/README.md`
- [x] add one flagship lazy-segtree note plus solution
- [x] add `topics/graphs/euler-tour-subtree/README.md`
- [x] add `templates/graphs/euler-tour-subtree.cpp`
- [x] add `notebook/subtree-queries-hot-sheet.md`
- [x] add `practice/ladders/graphs/euler-tour-subtree/README.md`
- [x] add one flagship subtree-query note plus solution

### Phase 4. Codeforces Operating Layer

- [x] add `practice/contest-playbooks/codeforces.md`
- [x] add `notebook/anti-hack-workflow.md`
- [x] add one `Codeforces short-round` drill pack
- [x] add one `Codeforces implementation clinic`
- [x] add one `Codeforces constructive / validator-first clinic`
- [x] add a `Codeforces upsolve worksheet`
- [x] surface a `Codeforces` route from `Practice Hub` and `Problem Finder`

## Next

These should follow after the `Now` block ships cleanly.

### Phase 5. Canonical Tree / Data-Structure Wave B

- [x] add `topics/graphs/centroid-decomposition/README.md`
- [x] add `templates/graphs/centroid-decomposition.cpp`
- [x] add `notebook/centroid-hot-sheet.md`
- [x] add `practice/ladders/graphs/centroid-decomposition/README.md`
- [x] add one flagship centroid note plus solution
- [x] choose one of the following as the paired second topic:
  - [x] `topics/data-structures/dsu-rollback/README.md`
  - [x] `topics/data-structures/persistent-data-structures/README.md`
- [x] add the matching template, hot sheet, ladder, and flagship note for the paired second topic

### Phase 6. Strings / DP Modern Wave

- [x] add `topics/strings/palindromes/README.md` with `Manacher` as the first shipped primitive
- [x] add `templates/strings/manacher.cpp`
- [x] add `notebook/palindromes-hot-sheet.md`
- [x] add `practice/ladders/strings/palindromes/README.md`
- [x] add one flagship palindrome note plus solution
- [x] add `topics/dp/cht-li-chao/README.md`
- [x] add `templates/dp/li-chao-tree.cpp`
- [x] add `notebook/cht-hot-sheet.md`
- [x] add `practice/ladders/dp/cht-li-chao/README.md`
- [x] add one flagship CHT / Li Chao note plus solution

### Phase 7. Math Modern Wave

- [x] add `topics/math/linear-recurrence/README.md`
- [x] add `templates/math/matrix-exponentiation.cpp`
- [x] add `notebook/linear-recurrence-hot-sheet.md`
- [x] add `practice/ladders/math/linear-recurrence/README.md`
- [x] add one flagship linear-recurrence note plus solution
- [x] add a [`CRT / Lucas / Mobius` wave plan](crt-lucas-mobius-wave-plan.md), then split it into at most `2` math waves instead of bulk-shipping everything together
- [x] add `topics/math/chinese-remainder/README.md`
- [x] add `templates/math/chinese-remainder.cpp`
- [x] add `notebook/chinese-remainder-hot-sheet.md`
- [x] add `practice/ladders/math/chinese-remainder/README.md`
- [x] add one flagship CRT / congruence-system note plus solution
- [x] add `topics/math/lucas-theorem/README.md`
- [x] add `templates/math/lucas-binomial.cpp`
- [x] add `notebook/lucas-hot-sheet.md`
- [x] add `practice/ladders/math/lucas-theorem/README.md`
- [x] add one flagship Lucas note plus solution
- [x] add `topics/math/mobius-multiplicative/README.md`
- [x] add `templates/math/mobius-linear-sieve.cpp`
- [x] add `notebook/mobius-hot-sheet.md`
- [x] add `practice/ladders/math/mobius-multiplicative/README.md`
- [x] add one flagship Mobius note plus solution

### Phase 8. Contest-Source Lane B

- [x] add a `Code Jam / Kick Start analysis-first clinic`
- [x] add a `special judge / output protocol` workflow page
- [x] add a `distributed decomposition` note or clinic if the repo gets enough supporting anchors
- [x] add a `Topcoder one-hard-problem clinic`
- [x] add a `Topcoder weird-task clinic`
- [x] add one `Petrozavodsk / OpenCup hard mixed pack`

## Later

These are valuable, but should wait until the earlier phases land cleanly.

### Long-Tail Algorithm Candidates

- [x] `Eulerian Path / Cycle`
- [x] `Mo's Algorithm`
- [x] `Binary Trie / XOR Queries`
- [x] `Flow with Lower Bounds`
- [x] `Segment Tree Beats`
- [x] `Wavelet Tree`
- [x] `Treap / Implicit Treap`
- [x] `Eertree / Palindromic Tree`
- [x] `XOR Basis / Linear Basis`
- [x] `Game Theory / Sprague-Grundy`
- [x] `Probability`

### Long-Tail Contest-System Ideas

- [x] `interactive protocol clinic` with richer local-testing patterns
- [x] `many-valid-answers / validator-first` workflow page
- [x] `precision / formatting robustness` clinic for Google-style tasks
- [x] `heuristic / marathon intro` page if the repo opens a heuristic lane

## Definition Of Done For One Expansion Wave

A wave is only considered shipped when:

- the new content is routed from at least one hub page
- the relevant `Template Library`, `Build Kit`, and `Problem Finder` routes exist
- at least one flagship solved note or drill exists for each new family
- the right hot sheet or parent cheatsheet route exists
- the wave has gone through a review sweep
- the full build/check suite passes

## Immediate Next Action

The cleanest default next step after the current shipped waves is:

1. wait for the next `quarterly freshness audit`, a sweep finding, or a strong exact-anchor opportunity before opening another expansion wave

That is now the best default because:

- the earlier explicit canonical and contest-system backlog in this file is now largely shipped
- the repo now has a stronger risk of `quality dilution by momentum` than `coverage failure`
- future expansion should be triggered by source-backed need, exact-anchor evidence, or retrieval/sweep findings
- the next routine trigger is the `Q3 2026` freshness window unless a smaller justified wave appears first
