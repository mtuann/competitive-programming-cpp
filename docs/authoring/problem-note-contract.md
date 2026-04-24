# Problem Note Contract

This page is for contributors and maintainers, not first-time learners.

Use it when you are writing or revising a solved note under `practice/ladders/`.

## Required Fields

- `Title`
- `Judge / source`
- `Original URL`
- `Secondary topics`
- `Difficulty`
- `Status`: `todo`, `attempted`, `solved`, `reviewed`
- `Solution file`

## Derived Field

- `Main topic`: generated from the note path `practice/ladders/<area>/<subtopic>/...` and the canonical title in `data/topic-resources.json`

## Optional Fields

- `Subtype`
- `Mirror / English URL`
- `Source contest`
- `Alternate solution variants`

## Suggested Section Order

1. `Why practice this`
2. `Recognition Cue`
3. `Problem-Specific Transformation`
4. `Core Idea`
5. `Complexity`
6. `Pitfalls / Judge Notes`
7. `Reusable Pattern`
8. `Solutions`

## Writing Rules

- solved notes should emphasize the delta from the topic page, not reteach the entire topic from scratch
- `Recognition Cue` should help the reader notice the right pattern next time
- `Problem-Specific Transformation` should explain how the raw statement was rewritten into that pattern
- `Reusable Pattern` should point back to the best internal topic, template, and notebook refreshers

## Maintenance Check

When a note changes enough to affect catalogs or docs, rerun:

```bash
python3 scripts/generate_problem_catalog.py --validate-only
python3 scripts/generate_problem_catalog.py
python3 scripts/build_site_docs.py
mkdocs build --strict
```
