# Visual Content Contract

- Purpose: quality bar for diagrams, interactive widgets, and explanatory charts across the docs site
- Scope: `topics/`, route pages, overview pages, and any custom visual in `docs-assets/`
- Doc type: maintainer standard
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-26
- Canonical companion docs: [Visual Roadmap](visual-roadmap.md), [Topic Template](topic-template.md), [Content Blueprint](content-blueprint.md)

This file exists so visuals do not stop at "present" or "cool". They should carry real teaching load, and they should do it in a repeatable way.

## Core Rule

Every shipped visual must make one hard part of the page easier to understand than prose alone.

If the page reads just as well after deleting the visual, the visual is either too weak or solving the wrong problem.

## What A Visual Is Allowed To Do

Each visual must have one primary job.

Use these labels internally when designing or reviewing:

- `Chooser`: helps the reader pick the right technique or variant
- `Mechanism`: shows how state, invariant, or structure evolves during the algorithm
- `Structure`: shows what is cached, partitioned, linked, or summarized
- `Tradeoff`: compares variants, costs, or design choices
- `Failure mode`: shows where the naive intuition breaks or where this technique stops fitting

One visual may have a small secondary job, but it should still be obvious what the main lesson is.

## The Teaching Questions

Before building a visual, answer these questions in one or two sentences:

1. what exactly is the reader likely to be confused about here?
2. why is this confusion hard to resolve with text alone?
3. what single insight should the reader walk away with after looking at the visual?

If those answers are vague, the visual is not ready to build.

## The Minimum Companion Text

No visual should stand alone with only a caption.

Each visual should come with the equivalent of these three cues, either around the visual or embedded in its companion block:

- `What to notice`
- `Why it matters`
- `How this connects to the algorithm or code`

For stronger visuals, add:

- `Boundary` or `When this visual stops being the whole story`

This is the smallest reliable teaching scaffold for visual content in this repo.

## The Three-Layer Teaching Bundle

For important topics, the best visual coverage usually has three layers:

1. `Orientation`
   - one static diagram that answers "what object or route am I even looking at?"
2. `Mechanism`
   - one visual or widget that shows the invariant or state change step by step
3. `Transfer`
   - one explicit bridge back to variables, loops, decomposition, or variant choice

Do not assume a single widget can do all three well.

## Visual Maturity Tiers

Use these tiers to think about how complete a topic's visual treatment really is.

### `V0` Text-first

- no custom visual needed yet
- the topic still reads well without a diagram

### `V1` Static orientation

- one static diagram or chart
- clarifies the object, decomposition, or route

### `V2` Mechanism demo

- one interactive or trace visual
- shows state movement or invariant maintenance
- still needs explicit text bridge back to code

### `V3` Full teaching bundle

- orientation layer
- mechanism layer
- transfer layer
- at least one boundary or failure-mode note

Not every page should aim for `V3`. The tier should match the topic's teaching bottleneck.

## Page-Level Budget

Most pages should stay within this visual budget:

- `1` orientation visual
- `1` mechanism visual
- `1` optional comparison or boundary visual

More than `3` meaningful visuals on one topic page is unusual and should be justified.

## Design Rules

### 1. One hard insight per visual

If a visual is trying to teach decomposition, traversal order, and variant choice all at once, split it.

### 2. Deterministic first

The default state should be:

- small
- stable
- replayable
- chosen to surface the intended invariant quickly

Random or user-generated states are secondary controls, not the default teaching path.

### 3. Show the invariant, not only the motion

Animations are not enough.

The reader should be able to see:

- what is already fixed
- what is currently active
- what summary is being maintained
- what decomposition or frontier is in force

### 4. Bridge back to code explicitly

Every mechanism visual should be traceable to real code patterns such as:

- one loop
- one pointer move
- one decomposition rule
- one node summary
- one update or query climb

If the reader can understand the visual but still cannot map it to code, the visual is incomplete.

### 5. Include a boundary when it matters

Good visuals do not only show how a technique works.

They should often also show:

- when this technique is the wrong tool
- when another variant is needed
- where the current mental model stops being sufficient

### 6. Controls should be few and task-shaped

The best controls are usually:

- `reset`
- `step`
- `run`
- one or two domain inputs

Do not turn a topic page into a general-purpose sandbox unless the page truly needs that depth.

### 7. Degrade gracefully

If JavaScript fails:

- the page should still read well
- the static structure should still communicate something
- the surrounding text should still carry the main lesson

## Review Checklist

Before shipping a visual, check:

1. does it teach one clearly named insight?
2. does that insight matter for understanding the algorithm?
3. is the insight hard to communicate with prose alone?
4. does the visual show the invariant or summary explicitly?
5. is there a clear bridge back to code or pseudocode?
6. does the page explain what to notice?
7. is there at least one boundary, anti-cue, or failure note when relevant?
8. does the page remain understandable if the script fails?
9. is this the lightest tool that can teach the idea well?
10. does the page still feel like documentation, not a mini-app?

If a visual fails multiple checklist items, revise it before expanding the wave.

## Strong Default Pattern For Topic Pages

For most topic pages in this repo, the best default is:

1. one static diagram near `One Picture Before Code`
2. one interactive or traced mechanism block
3. one short interpretation block immediately after the mechanism:
   - what to notice
   - why it matters
   - code bridge
   - boundary

This pattern is a better default than dropping a widget into the middle of the page and moving on.

## Anti-Patterns

Avoid:

- decorative visuals that add no new idea
- giant controls panels
- visuals that require hidden prior knowledge to decode
- visuals that only mirror the code without explaining the invariant
- visuals that teach a toy case but never reconnect to contest-scale reasoning
- multiple visuals on one page that all repeat the same lesson

## Enforcement Direction

When adding future visual waves:

- treat this file as the content-level review gate
- treat [Visual Roadmap](visual-roadmap.md) as the sequencing and tooling gate
- treat [Topic Template](topic-template.md) as the page-depth gate

If these files disagree, resolve the disagreement in the maintainer docs before shipping more visuals.
