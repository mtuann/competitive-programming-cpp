# Freshness Backbone

- Purpose: maintainer-facing audit spine for freshness-sensitive content and external-source drift
- Scope: official links, platform rules, playbooks, workflow pages, route pages, and source-family expansions
- Doc type: process
- Owner: repo maintainer
- Status: active
- Snapshot established: 2026-04-25
- Update triggers: quarterly audit, any new contest-source lane, any external-link break, or any wording drift caught by review sweeps
- Canonical companion docs: [Source Map](source-map.md), [Expansion Roadmap](expansion-roadmap.md), [Roadmap](roadmap.md), [Content Blueprint](content-blueprint.md)

This file exists so freshness-sensitive content does not rely on memory, ad hoc chat history, or one-off link checks.

## What This Governs

Use this backbone for repo surfaces whose recommendations, rules, or official links can drift:

- `practice/contest-playbooks/`
- contest-source clinics and worksheets
- workflow pages in `notebook/`
- route pages in `docs/`
- any maintainer plan that points at external study ecosystems

Do **not** use this page to re-audit evergreen algorithm proofs every quarter. Topic pages still need source-backed writing, but their freshness discipline is lighter and should flow through ordinary review sweeps.

## Core Rule

Before calling any freshness-sensitive wave "shipped", verify the relevant official or project-primary sources **during that pass** and leave a durable trace here or in the governed page.

That means:

1. verify the current official/project-primary link still exists
2. confirm the repo wording still matches the source's current role
3. decide whether the repo should:
   - keep the existing page as-is
   - revise wording
   - add a new drill / clinic / topic
   - retire or downgrade stale guidance

## Audit Cadence

## Quarterly Rhythm

- `Q1`: first two weeks of January
- `Q2`: first two weeks of April
- `Q3`: first two weeks of July
- `Q4`: first two weeks of October

If a major expansion wave lands between those windows, do a targeted spot-check immediately for the affected source family instead of waiting for the next quarter.

## Minimum Pass Types

### 1. Quarterly Baseline Audit

Run this on every core freshness-sensitive source family.

Deliverables:

- update the audit table below
- fix broken links or source-role drift
- refresh any page-level `last reviewed` markers that materially matter

### 2. Wave-Triggered Spot Check

Run this whenever a new contest-source lane, workflow page, or playbook drill ships.

Deliverables:

- verify only the source family that governs the new wave
- record the new snapshot date here
- note any special caveat such as `archive-based`, `official but no syllabus`, or `community curriculum rather than official rules`

### 3. Sweep-Follow-Up Check

Run this when review sweeps catch wording drift such as:

- stale "official" claims
- archive pages described like live ecosystems
- practice-source labels that are really course/reference links
- route pages recommending ecosystems the repo no longer supports well

## Audit Table

| Source family | Primary pages to verify | Governs these repo surfaces | Default cadence | Current snapshot | Notes |
| --- | --- | --- | --- | --- | --- |
| `VNOI Wiki` | [wiki.vnoi.info](https://wiki.vnoi.info/) | expansion planning, topic-gap comparison, source mining for long-tail algorithms | quarterly | `2026-04-25` | treat as coverage radar and advanced-topic source pool, not as repo law |
| `USACO Guide Advanced` | [usaco.guide/adv](https://usaco.guide/adv) | expansion planning, advanced sequencing comparisons, topic-gap checks | quarterly | `2026-04-25` | project-primary curriculum, not official USACO rules |
| `CP-Algorithms` | [cp-algorithms.com](https://cp-algorithms.com/) | topic maps, references, implementation/reference sanity for new leaves | quarterly | `2026-04-25` | strongest reference layer for many algorithm pages |
| `IOI syllabus + stats` | [syllabus](https://ioinformatics.org/page/syllabus/12), [stats](https://stats.ioinformatics.org/) | IOI / OI playbook, olympiad drills, source-backed trend notes | quarterly and before olympiad-lane edits | `2026-04-25` | use syllabus for scope, stats for task-difficulty drift |
| `ICPC WF official pages` | [WF problems](https://worldfinals.icpc.global/problems/2025/finals/index.html), [programming environment](https://docs.icpc.global/worldfinals-programming-environment/) | ICPC playbook, modeling drills, environment/process wording | quarterly and before ICPC-lane edits | `2026-04-25` | prefer official finals/problem/environment pages over regional summaries |
| `Codeforces official ecosystem` | [contest rules](https://codeforces.com/blog/entry/4088?locale=en), [interactive guide](https://codeforces.com/blog/entry/45307?mobile=true), [AI rule topic](https://codeforces.com/topic/134567/en4) | Codeforces playbook, anti-hack workflow, short-round drills, constructive/validator-first clinic | quarterly and before Codeforces-lane edits | `2026-04-25` | official pages are fragmented; preserve the exact page role in wording |
| `Google archive lane` | [coding competitions archive](https://github.com/google/coding-competitions-archive), [farewell post](https://developers.googleblog.com/celebrate-googles-coding-competitions-with-a-final-round-of-programming-fun/), [Kick Start retrospective](https://developers.googleblog.com/en/a-decade-of-kick-start/) | Code Jam / Kick Start clinic, distributed clinic, special-judge/output-protocol guidance | quarterly | `2026-04-25` | wording should stay `archive-based`, not sound like a live contest circuit |
| `Topcoder official ecosystem` | [SRM support](https://help.topcoder.com/hc/en-us/articles/24954129102491-Single-Round-Matches-SRMs), [arena](https://www.topcoder.com/community/arena), [rated event guide](https://www.topcoder.com/community/competitive-programming/how-to-compete/ratedEvent) | Topcoder clinics, one-hard-problem lane, weird-task lane | quarterly | `2026-04-25` | focus on current official operating guidance, not old forum lore |

## Page-Type Checklist

Use this when deciding what a newly observed external pattern should become inside the repo.

### Make It A Topic Page When

- the pattern is reusable across many judges and years
- it has one stable core invariant or theorem
- the repo can support it with:
  - one starter template or strong exact retrieval route
  - one hot sheet or parent cheatsheet route
  - at least one flagship note

Examples:

- `2-SAT`
- `Centroid Decomposition`
- `Chinese Remainder / Linear Congruences`

### Make It A Playbook Drill Or Clinic When

- the pattern is mostly about contest behavior, execution, or decision quality
- the main payoff is process under pressure rather than a reusable standalone algorithm
- the source is format-specific or ecosystem-specific

Examples:

- `Codeforces short-round shipping`
- `IOI checkpoint / score-path planning`
- `Topcoder one-hard-problem discipline`

### Make It A Mixed Round When

- the skill is about switching, pacing, or composing already-taught topics
- the underlying topics already have stable teaching and retrieval support
- the pack can diagnose failure modes better than one more prose page

Examples:

- `ICPC breadth + implementation`
- `Petrozavodsk / OpenCup hard mixed`

### Make It A Hot Sheet Or Workflow Page When

- the issue is retrieval under pressure
- the invariant already exists in a mature topic page
- or the content is an operational loop rather than a new theory lesson

Examples:

- `Anti-Hack Workflow`
- `Special Judge / Output Protocol Workflow`
- `Chinese Remainder hot sheet`

### Do Not Add A New Surface Yet When

- the external pattern is only one-off flavor, not a reusable family
- the repo has no exact starter, note, or route to support it
- the same payoff can be captured as one compare-point paragraph in an existing page

## Audit Procedure

When you run one freshness pass, do it in this order:

1. identify the affected source family
2. open only the official/project-primary pages that govern that family
3. verify the repo wording at the relevant surfaces:
   - `playbooks`
   - `workflow pages`
   - `route pages`
   - `expansion / source docs`
4. classify each finding:
   - `link drift`
   - `role drift`
   - `scope drift`
   - `new opportunity`
5. patch the governed repo pages
6. record the snapshot date here if the pass changed meaningfully
7. if the pass materially changes priorities, patch [Expansion Roadmap](expansion-roadmap.md) in the same turn

## Findings Taxonomy

Use these labels internally when triaging audit results.

- `link drift`: a URL moved, redirected strangely, or no longer represents the intended official source
- `role drift`: the page still exists, but the repo describes it with the wrong role, such as calling an archive lane "current"
- `scope drift`: the ecosystem now rewards a different skill mix than the repo currently emphasizes
- `new opportunity`: a recurring pattern now deserves a topic, clinic, mixed round, or hot sheet

## Current Snapshot Summary

The `2026-04-25` baseline pass and first reprioritization pass support these current repo stances:

- `VNOI Wiki`, `USACO Guide Advanced`, and `CP-Algorithms` are the main `coverage radar` trio for algorithm-gap discovery
- `IOI` should still be treated as `syllabus + task-stats + partial-scoring discipline`
- `ICPC` should still be treated as `official environment + breadth + modeling under pressure`
- `Codeforces` should still be treated as `official rules + interactive / anti-hack / upsolve discipline`
- `Google` contest content must be described as `archive-based`
- `Topcoder` should stay framed around `one hard problem`, `weird-task surfaces`, and official operating guidance

## 2026-04-25 Reprioritization Findings

This pass rechecked the repo's main freshness-sensitive source families and used that review to reprioritize future expansion.

### Link Drift

- no blocker-level link drift was found in the spot-checked source families used by the current contest-system layer:
  - `VNOI Wiki`
  - `USACO Guide Advanced`
  - `CP-Algorithms`
  - `IOI stats`
  - `ICPC WF official pages`
  - `Codeforces official ecosystem`
  - `Google coding competitions archive`
  - `Topcoder SRM / Marathon support pages`

### Role Drift

- `Google` should continue to be written as an `archive-based` source family, not as a live contest circuit
- `Topcoder Marathon` should remain an `intro / clinic` lane until the repo has exact internal heuristic anchors strong enough to support a deeper learning family
- `Codeforces` official pages remain fragmented, so wording should continue to preserve each exact page role instead of flattening them into one generic "official syllabus"

### Scope Drift

- the repo's explicit `contest-system` backlog is now mature enough that future waves should not open purely from momentum
- the repo's earlier `highest-value canonical gaps` have largely been shipped, so the expansion spine should now be treated as `audit-driven` rather than `missing-core-topics-driven`

### New Opportunity Rule

Open a new expansion wave only when at least one of these becomes true:

- a quarterly audit finds real `scope drift` in a tracked source family
- a review sweep finds a durable `retrieval / exact-anchor deficit`
- at least one strong repo-fit flagship anchor appears for a topic or clinic that the repo does not currently support well

## Immediate Next Audit Window

Unless a new source-sensitive wave lands first, the next routine freshness pass should happen in:

- `Q3 2026` (`first half of July 2026`)

If a new contest-source lane lands before then, run a source-family spot-check as part of that wave.
