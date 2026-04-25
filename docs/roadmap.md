# Roadmap

- Purpose: durable backlog and format contract for the next content passes
- Scope: public learning content, practice content, reusable code layers, and maintainer docs
- Doc type: planning
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-25
- Update triggers: after any major topic-page pass, new content layer, or roadmap reprioritization
- Canonical companion docs: [Content Blueprint](content-blueprint.md), [Topic Template](topic-template.md), [Source Map](source-map.md), [Freshness Backbone](freshness-backbone.md), [Expansion Roadmap](expansion-roadmap.md), [CRT / Lucas / Mobius Wave Plan](crt-lucas-mobius-wave-plan.md)

This file exists so future work does not drift into memory or scattered chat history.

## How To Use This File

- use this as the repo-wide `now / next / later` backlog
- update a line here when a content pass changes priority or scope
- keep page-format rules short here and move public writing contracts into the canonical docs they govern
- when a task is completed, either remove it or move it to a short `recently shipped` note

## Shared Standard

The repo should feel like one learning system, not a pile of Markdown files.

That means:

- each page type should answer one primary question and stop there
- `topics/` teaches the reusable idea
- `templates/` stores reusable code
- `notebook/` stores contest-time recall and workflows
- `practice/` stores recognition, sequencing, and problem-specific transformations
- `docs/` stores route pages, standards, research notes, and planning
- every content pass should be classified as either `evergreen` or `freshness-sensitive` before writing starts

## Sourcing And Freshness Rules

This backlog should assume that online research is part of the authoring process, not an optional polish step.

### Evergreen

Use for:

- algorithm topics
- proofs and derivations
- most templates
- most ladders and solved notes

Rule:

- still do a research sweep before calling the content `mature`
- prefer `Primary`, `Course`, and `Reference` sources for facts and proofs
- use `Essay / Blog` only when it genuinely deepens understanding

### Freshness-Sensitive

Use for:

- toolchain and workflow guidance
- playbooks and route pages that recommend current resources
- platform, judge, library, and official-program links
- any content whose recommendations may drift over time

Rule:

- verify the relevant official or primary online sources during the pass
- record a snapshot or last-reviewed date when the date matters
- prefer official docs and project-primary pages over summaries

### Layer Expectations

- `topics/`: deep explanation plus researched sources
- `templates/`: researched assumptions, not just copied snippets
- `notebook/`: compact recall backed by researched topic/workflow content
- `practice/`: official problem links and researched topic framing
- `docs/`: strongest freshness discipline in the repo when external recommendations are involved

## Topic Formats

These rules synthesize the current topic contract plus agent review.

### Area Hub

Use for:

- `topics/<area>/README.md`

Job:

- route the reader into the right subtopic, not teach the full lesson

Must include:

- what this area covers
- who should open it now
- 3-6 strongest next doors
- route suggestions by level or goal

Must avoid:

- long proofs
- giant problem catalogs near the top
- duplicating all child pages

### Technique Leaf

Use for one concrete algorithm or data structure like `Fenwick Tree`, `KMP`, `DSU`, or `Segment Tree`.

Canonical examples:

- [Fenwick Tree](../topics/data-structures/fenwick-tree/README.md)
- [FFT And NTT](../topics/math/fft-ntt/README.md)

Must include:

- `At A Glance`
- `Problem Model And Notation`
- `From Brute Force To The Right Idea`
- `Core Invariant And Why It Works`
- `Complexity And Tradeoffs`
- `Worked Examples`
- `Algorithm And Pseudocode`
- `Implementation Notes`
- `Practice Archetypes`
- `References And Repo Anchors`
- `Related Topics`

### Family / Chooser Page

Use when the main job is choosing among sibling algorithms, such as `Shortest Paths`.

Must include:

- a chooser table
- decision axes
- anti-cues
- comparison examples
- child-page routing

Must avoid:

- full deep proofs for every child technique in one page

### Theory-Led Page

Use when the main payoff is modeling, vocabulary, or proof habits, such as `Reasoning` or `Graph Modeling`.

Must include:

- why it matters in contests
- core vocabulary
- one central principle or argument
- concrete examples
- actionable checklist
- practice anchors

## Content Layer Formats

These are the public-content formats to keep stable across future passes.

### 1. Beginner Onboarding And C++ Workflow

Primary question:

- how do I write, compile, run, debug, and trust simple C++ contest programs locally?

Main files:

- `topics/foundations/cpp-language/README.md`
- `notebook/foundations-cheatsheet.md`
- `notebook/local-judge-workflow.md`
- `notebook/stress-testing-workflow.md`
- `practice/ladders/foundations/cpp-language/README.md`

Standard:

- topic page teaches the default loop and the reasoning behind it
- cheatsheet stores exact commands and tiny syntax reminders
- workflow pages store operational loops
- ladder page stores the progression and exit criteria

### 2. Template Library

Primary question:

- what code should I grab, and what does it already assume?

Standard:

- every template should expose `Signal`, `Assumes`, `Complexity`, `Main trap`, and `Links`
- `template-library.md` should stay signal-first, not become a theory page

### 3. Notebook / Cheatsheets

Primary question:

- what is the shortest route back to the right invariant and template under contest pressure?

Standard:

- start with `Use when` and `Do not use when`
- keep `signal -> invariant -> trap` before anything else
- point back to topic pages for proofs

### 4. Workflow Pages

Examples:

- `stress-testing-workflow.md`
- `local-judge-workflow.md`
- `contest-checklist.md`

Primary question:

- what exact operational loop should I run right now?

Standard:

- `Trigger`
- `Inputs needed`
- `Output artifact`
- `Stop condition`
- one compact command loop
- one failure-logging rule

### 5. Ladder README

Primary question:

- what should I solve next in this subtopic, and why is each problem placed there?

Standard:

- `Who This Is For`
- `Before You Start`
- `Warm-Up`
- `Core`
- `Stretch`
- `Exit Criteria`
- `Repo Connections`

### 6. Solved Problem Notes

Primary question:

- what transformation turned this statement into a solvable pattern?

Standard:

- explain the delta from the topic page
- keep the `Reusable Pattern` block strong and consistent
- avoid reteaching the entire topic

Recommended body:

- `Why Practice This`
- `Recognition Cue`
- `Problem-Specific Transformation`
- `Core Idea`
- `Complexity`
- `Pitfalls / Judge Notes`
- `Reusable Pattern`
- `Solutions`
- optional `Review Prompt`

### 7. Mixed Rounds

Primary question:

- how do I test retrieval and switching across topics on purpose?

Standard:

- `Who This Is For`
- `Pack Shape`
- `Topics Under Test`
- `Suggested Order`
- `How To Run It`
- `Allowed Refreshers`
- `Debrief`
- `Go Back Next`

### 8. High-Level Guidance And Contest Playbooks

Examples:

- `docs/start-here.md`
- `docs/site-home.md`
- `practice/contest-playbooks/*.md`

Primary question:

- what should I do next, and what should I ignore for now?

Standard:

- one clear primary route
- at most a few alternate routes
- explicit exit criteria
- explicit next clicks

### 9. Maintainer Docs

Examples:

- `docs/content-blueprint.md`
- `docs/topic-template.md`
- `docs/authoring/*.md`
- `docs/source-map.md`
- this roadmap

Primary question:

- what is the contract, what is unfinished, and what is the exact next shippable step?

Standard:

- clear ownership and scope
- stable vocabulary
- tables for gaps and coverage
- `Open loops`
- `Next review`

## Current Topic Backlog

The next deep-topic candidates with the highest payoff are:

1. `topics/data-structures/segment-tree/README.md`
2. `topics/strings/kmp/README.md`
3. `topics/math/modular-arithmetic/README.md`
4. `topics/dp/digit-dp/README.md`
5. `topics/graphs/lca/README.md`
6. `topics/geometry/convex-hull/README.md`
7. `topics/strings/z-function/README.md`
8. `topics/data-structures/dsu/README.md`
9. `topics/graphs/matching/README.md`
10. `topics/strings/suffix-array-lcp/README.md`

Family / chooser pages to deepen later:

- `topics/graphs/shortest-paths/README.md`
- `topics/graphs/flow/README.md`
- `topics/graphs/scc-toposort/README.md`
- `topics/data-structures/heaps-and-ordered-sets/README.md`

Theory-led pages to strengthen later:

- `topics/foundations/reasoning/README.md`
- `topics/graphs/graph-modeling/README.md`
- `topics/advanced/contest-engineering/README.md`

## Current Content Backlog

Priority order outside `topics/`:

1. beginner onboarding and `C++ workflow / compile / run / syntax / debugging`
2. template-library metadata and retrieval polish
3. notebook / cheatsheet density
4. solved-problem-note consistency
5. mixed rounds expansion
6. contest playbooks
7. docs UX / route pages
8. maintainer docs and authoring guides

## Now

### Theme

- strengthen the beginner stack so the repo has one genuinely strong first door

### Files To Touch First

- `topics/foundations/cpp-language/README.md`
- `notebook/foundations-cheatsheet.md`
- `practice/ladders/foundations/cpp-language/README.md`
- `notebook/local-judge-workflow.md`
- `notebook/stress-testing-workflow.md`
- `docs/start-here.md`

### Definition Of Done For This Pass

- one canonical release build command
- one canonical debug / sanitizer build command
- clear explanation of flag choices
- one tiny compile-and-run example
- one debug-failure example
- one local sample workflow
- one stable ladder route for beginner C++
- clean links among topic page, cheatsheet, workflow pages, and first practice notes
- current official or project-primary links rechecked for the workflow guidance that depends on them

## Next

- deepen `segment-tree`
- raise `template-library.md` to the new metadata contract
- standardize solved-note structure where it still feels uneven

## Later

- add more mixed-round packs with explicit training goals
- expand contest playbooks with `before / during / after` workflows
- add more authoring guides for naming, slugs, citation rules, and metadata formatting

## Forgotten Work Guardrail

When this file is updated, check these questions explicitly:

- which pages are mentioned often but still thin?
- which topic maps still rely more on external links than strong internal pages?
- which templates are battle-tested but poorly explained?
- which ladders have problems but weak sequencing comments?
- which workflows are referenced often but not concrete enough to execute blindly?

## Open Loops

- add a maintainer-facing coverage table once the next 3-5 deep-topic pages are finished
- decide whether this roadmap should also be linked in site navigation, not only from the repo
- standardize template file headers when the template-library pass starts

## Next Review

- after the C++ workflow pass is shipped
- after the next deep-topic page beyond `Fenwick` and `FFT / NTT` is published
