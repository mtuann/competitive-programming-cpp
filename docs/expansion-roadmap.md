# Expansion Roadmap

- Purpose: phased TODO list for future algorithm coverage, contest-source integration, and practice-system expansion
- Scope: new topic pages, starter templates, notebook hot sheets, ladders, mixed rounds, playbooks, and freshness audits
- Doc type: planning
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-25
- Update triggers: after each expansion wave, after any major reprioritization, or after a new external-source audit
- Canonical companion docs: [Roadmap](roadmap.md), [Content Blueprint](content-blueprint.md), [Topic Template](topic-template.md), [Source Map](source-map.md)

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

### Highest-Value Canonical Gaps

These are the most valuable missing topics or families relative to the repo's current maturity.

- `Lazy Segment Tree`
- `DSU Rollback / Offline Dynamic Connectivity`
- `Persistent Data Structures`
- `Manacher`
- `Convex Hull Trick / Li Chao Tree`
- `Linear Recurrence / Matrix Exponentiation`
- `CRT / Lucas / Möbius / multiplicative functions`

### Contest-Source Lanes Worth Mining

These should be treated as content-source families, not just random inspiration.

- `IOI / OI`: subtask-first planning, checkpointing, score-path design, proof discipline
- `ICPC`: breadth, modeling under pressure, team triage, communication, implementation-heavy mixed sets
- `Codeforces`: short-round shipping, anti-hack, validator-first constructive work, implementation clinics, interactive discipline
- `Topcoder / TCO`: one-hard-problem culture, weird-task clinics, marathon / heuristic bridge
- `Google Code Jam / Kick Start / Distributed Code Jam`: small-vs-large escalation, analysis-first solving, custom judge discipline, distributed decomposition
- `Petrozavodsk / OpenCup / Andrew Stankevich`: advanced mixed modeling, hard implementation, camp-style drills

## Now

These are the next waves with the highest ROI and the cleanest fit with the current repo.

### Phase 0. Freshness Backbone

- [ ] add `docs/freshness-radar.md` or equivalent maintainer page for external-source audits
- [ ] define a quarterly audit cadence for `VNOI Wiki`, `USACO Guide Advanced`, `CP-Algorithms`, `IOI syllabus/stats`, `ICPC WF problem sets`, and official `Codeforces` ecosystem pages
- [ ] write a short maintainer checklist for deciding whether a new external pattern becomes a `topic page`, `playbook drill`, `mixed round`, or `hot sheet`

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
  - [ ] `topics/data-structures/persistent-data-structures/README.md`
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

- [ ] add `topics/math/linear-recurrence/README.md`
- [ ] add `templates/math/matrix-exponentiation.cpp`
- [ ] add `notebook/linear-recurrence-hot-sheet.md`
- [ ] add `practice/ladders/math/linear-recurrence/README.md`
- [ ] add one flagship linear-recurrence note plus solution
- [ ] add a `CRT / Lucas / Möbius` wave plan, then split it into at most `2` math waves instead of bulk-shipping everything together

### Phase 8. Contest-Source Lane B

- [ ] add a `Code Jam / Kick Start analysis-first clinic`
- [ ] add a `special judge / output protocol` workflow page
- [ ] add a `distributed decomposition` note or clinic if the repo gets enough supporting anchors
- [ ] add a `Topcoder one-hard-problem clinic`
- [ ] add a `Topcoder weird-task clinic`
- [ ] add one `Petrozavodsk / OpenCup hard mixed pack`

## Later

These are valuable, but should wait until the earlier phases land cleanly.

### Long-Tail Algorithm Candidates

- [ ] `Eulerian Path / Cycle`
- [ ] `Mo's Algorithm`
- [ ] `Binary Trie / XOR Queries`
- [ ] `Flow with Lower Bounds`
- [ ] `Segment Tree Beats`
- [ ] `Wavelet Tree`
- [ ] `Treap / Implicit Treap`
- [ ] `Eertree / Palindromic Tree`
- [ ] `XOR Basis / Linear Basis`
- [ ] `Game Theory / Sprague-Grundy`
- [ ] `Probability`

### Long-Tail Contest-System Ideas

- [ ] `interactive protocol clinic` with richer local-testing patterns
- [ ] `many-valid-answers / validator-first` workflow page
- [ ] `precision / formatting robustness` clinic for Google-style tasks
- [ ] `heuristic / marathon intro` page if the repo opens a heuristic lane

## Definition Of Done For One Expansion Wave

A wave is only considered shipped when:

- the new content is routed from at least one hub page
- the relevant `Template Library`, `Build Kit`, and `Problem Finder` routes exist
- at least one flagship solved note or drill exists for each new family
- the right hot sheet or parent cheatsheet route exists
- the wave has gone through a review sweep
- the full build/check suite passes

## Immediate Next Action

The cleanest next task after the current shipped waves is:

1. `Persistent Data Structures`
2. `Linear Recurrence / Matrix Exponentiation`

That pair has the best balance of:

- modern canonical value
- clean fit with the current graph stack
- strong template/hot-sheet payoff
- strong contest payoff without opening too many new surfaces at once
