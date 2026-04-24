# Build Kit

Use this page when the algorithm is mostly known and the bottleneck is now:

- implementing it cleanly
- reopening the right snippet quickly
- checking one invariant under pressure
- stabilizing a suspicious solution locally

This is the repo's `retrieve and execute` layer.

## Quick Split

- `Notebook` = recall the invariant, signal, or trap
- `Template Library` = retrieve the smallest reusable snippet
- `Build Kit` = choose between notebook, templates, and workflow pages

## What Lives Here

| Need | Best door |
| --- | --- |
| reusable contest code | [Template Library](../template-library.md) |
| short invariant/trap reminders | [Notebook](../notebook/README.md) |
| debug a suspicious implementation | [Stress testing workflow](../notebook/stress-testing-workflow.md) |
| validator-heavy / interactive / many-valid-answers local loop | [Local judge workflow](../notebook/local-judge-workflow.md) |
| before-contest checklist | [Contest checklist](../notebook/contest-checklist.md) |

## Choose The Smallest Useful Tool

### Template Library

Open [Template Library](../template-library.md) when:

- you already know the family
- you want the smallest contest-ready implementation
- you need one fast chooser table, not a tutorial

Do **not** open it first if you still do not trust the topic itself.

### Notebook

Open [Notebook](../notebook/README.md) when:

- you mostly know the idea
- you need the main invariant, trap, or signal fast
- you want the shortest route back to the right family

Do **not** use it as first exposure.

### Workflows

Open a workflow page when the algorithm feels right but the solution still feels unsafe:

- [Stress testing workflow](../notebook/stress-testing-workflow.md)
- [Local judge workflow](../notebook/local-judge-workflow.md)

## Build Kit Routes

| If the problem feels like... | Open first | Then |
| --- | --- | --- |
| “I know the topic, just give me the snippet” | [Template Library](../template-library.md) | the matching topic page only if trust is low |
| “I know the topic, but I forgot the invariant” | [Notebook](../notebook/README.md) | the matching template |
| “The code compiles, but I do not trust it” | [Stress testing workflow](../notebook/stress-testing-workflow.md) | the matching note or template |
| “This task has a judge/protocol quirk” | [Local judge workflow](../notebook/local-judge-workflow.md) | the matching playbook or note |

## Best Pairings

- shortest paths -> [Graph cheatsheet](../notebook/graph-cheatsheet.md) + graph templates
- range-query structures -> [Data structures cheatsheet](../notebook/data-structures-cheatsheet.md) + [Template Library](../template-library.md)
- modular arithmetic -> [Number theory cheatsheet](../notebook/number-theory-cheatsheet.md) + math templates
- geometry predicates -> [Geometry cheatsheet](../notebook/geometry-cheatsheet.md) + geometry templates

## After This Page

- if trust in the snippet is still low, go back to `topics/`
- if you now need the next problem, go to [Problem Finder](problem-finder.md)
- if you want a contest-format workflow, go to [Contest Playbooks](../practice/contest-playbooks/README.md)
