# IOI Checkpoint / Score-Path Drill 01

Goal:

- practice banking a real safe score path before gambling on the full solution

Time budget:

- `90-110 minutes`

Entry gate:

- you already know the core topic family well enough that the main bottleneck is proof, checkpointing, or subtask planning

Inputs:

- one official task, olympiad-style problem, or one repo note with visible easier routes
- one blank [IOI Subtask-First Worksheet](ioi-subtask-first-worksheet.md)

Output artifacts:

- one filled worksheet
- one bank / upgrade / park decision
- one short debrief naming the first false assumption

## Use This When

- you keep seeing the full idea too late
- you often lose safe partial points while chasing the full route
- your post-contest notes say “I almost had it” without identifying which checkpoint was actually safe

## Good Repo Anchors

- [TFIELD](../ladders/dp/sliding-window/tfield.md)
- [QOS](../ladders/graphs/shortest-paths/qos.md)
- [CRYPTKEY](../ladders/math/gcd-lcm/cryptkey.md)
- [VOITSORT](../ladders/combinatorics/lexicographic-enumeration/voitsort.md)
- [VOSTRIP](../ladders/graphs/tree-dp/vostrip.md)

If none of those fit the family you want, take one official task and keep the same protocol.

## Session Script

### `0-10 min`: Read And Fill The Buckets

- read the statement and visible subtask or score structure
- fill every row of the [IOI Subtask-First Worksheet](ioi-subtask-first-worksheet.md) without coding
- write the smallest valid algorithm for each visible bucket before thinking about the full solution

### `10-20 min`: Choose The Safest Score Path

- select one current target bucket
- complete only the worksheet's `Current Target Proof Gate`
- if that proof gate still feels vague, downshift to the safest bucket you can actually prove

### `20-60 min`: Implement Only The Checkpoint

- code the chosen score path only
- do not “half-build” the full solution during this phase
- keep one compiling checkpoint at all times

### `60-75 min`: Validate At The Boundary

- test the smallest legal cases
- test the exact subtask boundary that justifies the chosen bucket
- if relevant, use [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) or [Local Judge Workflow](../../notebook/local-judge-workflow.md)

### `75-90 min`: Decide `Bank / Upgrade / Park`

- `bank` if the checkpoint is proved and stable
- `upgrade` only if the next bucket is adjacent and the proof delta is concrete
- `park` if the next route is still intuition-only or validation is unstable

### `90-100 min`: Debrief

Log exactly:

1. highest proven score path
2. safe checkpoint actually banked
3. first false assumption
4. next repo door

## Success Criteria

- you banked one route that you could explain and validate cleanly
- your next action is explicit: `upgrade`, `topic review`, `validation fix`, or `park`
- the first false assumption was caught before it consumed the entire session

## Failure Routing

| Failure signal | Go next |
| --- | --- |
| proof still fuzzy | [Reasoning](../../topics/foundations/reasoning/README.md) |
| validation is the real bottleneck | [Stress Testing Workflow](../../notebook/stress-testing-workflow.md) or [Local Judge Workflow](../../notebook/local-judge-workflow.md) |
| implementation blocked a known idea | [Build Kit](../../docs/build-kit.md) |
| topic depth was weaker than expected | the corresponding [Topic](../../topics/README.md) page, then the matching [Ladder](../ladders/README.md) |

## After This Drill

- return to [IOI / OI Playbook](ioi-oi.md) if the track logic still fits
- reopen [Problem Finder](../../docs/problem-finder.md) if you want the next official-style rep
- go back to [Mixed Rounds](../mixed-rounds/README.md) only if the real bottleneck is switching rather than proof discipline

Research snapshot refreshed against official IOI sources on `2026-04-24`.
