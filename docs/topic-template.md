# Topic Template

Use this as the source of truth for mature topic pages in `topics/`.

If the README, topic hubs, or planning docs ever phrase the structure differently, this file wins.

The goal is no longer just "a quick intro". A mature topic page should be self-contained enough that a serious reader can learn the algorithm without opening five other tabs, while still linking outward to repo notes, templates, and references.

Use a layered shape:

- `Core path`: the shortest route through the idea
- `Deep dive`: proofs, variants, worked examples, and implementation detail

Not every topic must be equally long, and not every topic page has the same job. Use one of these archetypes:

## Page Archetypes

### 1. Technique Leaf

Use this for one concrete algorithm or data structure, such as `Fenwick Tree`, `Prefix Sums`, `KMP`, or `Dinic`.

This is the full deep-template default.

### 2. Family / Chooser Page

Use this for pages like `Shortest Paths`, where the main teaching goal is to choose among multiple algorithms.

Keep the same opening blocks, but emphasize:

- variant comparison
- recognition cues
- anti-cues
- when each child technique wins or fails

Do not force full proofs for every child algorithm into one family page. Push those into child pages when needed.

### 3. Theory-Led Page

Use this for pages where the main payoff is modeling language, theorem intuition, or proof habits more than one fixed implementation.

These pages may compress the pseudocode and implementation blocks, but they should still stay self-contained on intuition, vocabulary, and the central argument.

The section contract below is the source of truth for `Technique Leaf` pages and the strongest default for anchor topics.

## 1. At A Glance

- what the technique solves
- prerequisites
- strongest recognition cues
- strongest anti-cues
- what "success" looks like after studying the page

## 2. Problem Model And Notation

- define the input model, state, or graph/object the algorithm works on
- define every recurring symbol before using it
- use rendered math when it materially clarifies the invariant or derivation
- follow [Markdown Math Style](authoring/markdown-math-style.md)

## 3. From Brute Force To The Right Idea

- start from the naive or closest-known baseline
- identify the bottleneck clearly
- show the structural observation that removes that bottleneck
- make the transition feel inevitable instead of magical

## 4. Core Invariant And Why It Works

- state the main invariant, lemma, or exchange argument
- give one real proof, not just a slogan
- add a second lemma only when the topic is subtle enough to need it
- connect the proof back to the actual loops or state transitions

## 5. Complexity And Tradeoffs

- time and memory complexity
- constant-factor reality when it matters in contests
- when a nearby technique is lighter or more general
- when this technique is the wrong hammer

## 6. Variant Chooser

- compare the standard variants in one place
- for each variant, include:
  - what changes in the model
  - complexity
  - when to choose it
  - where it fails or becomes awkward

## 7. Worked Examples

Include exactly two kinds of examples whenever possible:

1. one tiny traced example that shows the invariant mechanically
2. one contest-style example that shows recognition and modeling

If you need more than two worked examples, push the extra detail into ladder notes.

## 8. Algorithm And Pseudocode

- present language-neutral pseudocode
- make the data flow or state transitions explicit
- keep full reusable C++ code in `templates/` and `template-library.md`

## 9. Implementation Notes

- indexing policy
- overflow and numeric type policy
- boundary conditions
- hidden pitfalls the pseudocode does not reveal
- link the canonical repo template and the best companion note

## 10. Practice Archetypes

Use `warm-up`, `core`, and `stretch`, but annotate each problem with why it triggers this topic.

The reader should leave this section knowing not only what to solve next, but why each problem belongs here.

## 11. References And Repo Anchors

- `Course`: official or course-primary link
- `Reference`: CP-Algorithms / OI Wiki / project-primary link
- `Practice`: official platform or archive
- `Repo anchors`: ladder, notebook, template, and strongest internal problem notes

References should support the page, not replace it. The page itself should carry the main teaching load.

## 12. Related Topics

- prerequisites
- nearby confusing alternatives
- next topics
- reusable reductions or connections
