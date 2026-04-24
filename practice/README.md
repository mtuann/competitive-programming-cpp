# Practice

<div class="home-hero" markdown>
  <p class="hero-kicker">Deliberate repetition, not random grinding</p>
  <p class="hero-copy">
    Practice is organized <code>by topic first</code>, not only by judge. The goal is to help you learn an idea,
    solve targeted problems, and come back for repetition without losing the connection between concept and use.
  </p>
  <div class="hero-actions">
    <a class="md-button md-button--primary" href="ladders/">Open ladders</a>
    <a class="md-button" href="../docs/problem-finder/">Open problem finder</a>
    <a class="md-button" href="mixed-rounds/">Mixed rounds (later)</a>
    <a class="md-button" href="contest-playbooks/">Contest playbooks (later)</a>
  </div>
  <div class="chip-row">
    <span class="chip">Topic-first</span>
    <span class="chip">Judge-linked</span>
    <span class="chip">Review-friendly</span>
    <span class="chip">Contest-aware</span>
  </div>
</div>

## Choose A Practice Mode

<div class="grid cards" markdown>

-   __Ladders__

    Stay inside one topic long enough to build recognition and clean execution.

    [Open ladders](ladders/README.md)

-   __Problem Finder__

    Use one searchable doorway when you know the weak topic or want the next good set quickly.

    [Open problem finder](../docs/problem-finder.md)

-   __Mixed Rounds__

    Mix areas on purpose when you want retrieval practice, breadth, and contest-style switching.
    The starter packs are best after you already have one pass through the corresponding ladders.

    [Open mixed rounds](mixed-rounds/README.md)

-   __Contest Playbooks__

    Train toward a contest style such as `ICPC`, `USACO`, or olympiad-style prep with clearer workflow guidance.

    [Open contest playbooks](contest-playbooks/README.md)

</div>

## The Default Practice Loop

Use the repo layers in this order whenever possible:

1. learn the idea in `topics/`
2. stay in one family through [Ladders](ladders/README.md)
3. compare against one solved note
4. reopen [Notebook](../notebook/README.md) or [Build Kit](../docs/build-kit.md) only if retrieval or implementation is the bottleneck
5. move to [Mixed Rounds](mixed-rounds/README.md) or [Contest Playbooks](contest-playbooks/README.md) only after the family is already familiar

That is the default `topic -> ladder -> note -> retrieve -> switch` loop of the repo.

## Choose By Bottleneck

| If your bottleneck is... | Best first door | Then |
| --- | --- | --- |
| I need the next good problems | [Problem Finder](../docs/problem-finder.md) | the matching ladder or playbook |
| I am still learning one topic | the matching topic page in [topics/](../topics/README.md) | [Ladders](ladders/README.md) |
| I know several topics but switch badly | [Mixed Rounds](mixed-rounds/README.md) | [Notebook](../notebook/README.md) |
| I care about one contest format now | [Contest Playbooks](contest-playbooks/README.md) | [Problem Finder](../docs/problem-finder.md) |

## How To Use Problem Notes

<div class="grid cards" markdown>

-   __Read the recognition cue first__

    Check the topic, subtype, and recognition sentence before reading the solution. That keeps your practice tied to pattern recognition instead of only code recall.

-   __Compare the transformation, not just the answer__

    Ask what changed between the raw statement and the reusable topic pattern. That delta is usually what you want to remember for the next problem.

-   __Track status honestly__

    Keep `todo`, `attempted`, `solved`, and `reviewed` meaningful so the repo becomes a real training log.

</div>

## Browse The Catalog

- [Problem index](../docs/problem-index.md): one table for every currently tracked solved note, with links to the note, code, ladder, and tutorial hub
- [External problem index](../docs/external-problem-index.md): curated official and trusted problems outside the repo, organized by topic and usable as the next practice queue
- [Topic maps](../docs/topic-maps/index.md): source-backed pages for each subtopic, including trusted learning references, practice and follow-up sources, and every repo problem tagged there

## After One Practice Session

- weak topic recognition -> reopen the matching tutorial in [Topics](../topics/README.md)
- weak family-level repetition -> stay inside [Ladders](ladders/README.md) for one more note set
- weak implementation trust -> reopen [Build Kit](../docs/build-kit.md)
- weak retrieval under pressure -> reopen [Notebook](../notebook/README.md)
- weak contest-time behavior -> reopen [Contest Playbooks](contest-playbooks/README.md)

## Path Shapes

```text
practice/ladders/<area>/<subtopic>/<problem-code>.md
practice/mixed-rounds/<pack>.md
practice/contest-playbooks/<track>.md
```

Contributor note contract lives here:

- [Problem Note Contract](../docs/authoring/problem-note-contract.md)

!!! tip "Best way to use this section"
    Read one topic page, pause at `Recognition Cue`, solve or re-solve the problem, then compare your transformation against the stored note before reading the code.

## Current Examples

### Data Structures

- [CVP00001 - Ô ăn quan](ladders/data-structures/fenwick-tree/cvp00001.md)
- [C11XU - Bộ sưu tập đồng xu](ladders/data-structures/dsu/c11xu.md)

### Graphs

- [QBFLOWER - Tặng hoa](ladders/graphs/matching/qbflower.md)
- [FFLOW - Fast Maximum Flow](ladders/graphs/flow/fflow.md)
- [MCQUERY - MinCut Query](ladders/graphs/flow/mcquery.md)
- [MINCOST - Luồng với chi phí nhỏ nhất](ladders/graphs/flow/mincost.md)
- [QOS - Chất lượng dịch vụ](ladders/graphs/shortest-paths/qos.md)
- [MTREECOL - Color a tree](ladders/graphs/trees/mtreecol.md)
- [VMWTREE - Lại là cây khung](ladders/graphs/trees/vmwtree.md)
- [VOSTRIP - VOSTRIP](ladders/graphs/tree-dp/vostrip.md)

### DP / Greedy

- [VMSCALE - Chiếc cân kỳ diệu](ladders/dp/foundations/vmscale.md)
- [TFIELD - Ruộng bậc thang](ladders/dp/sliding-window/tfield.md)
- [VMMARBLE - Phân loại bi](ladders/dp/bitmask-dp/vmmarble.md)
- [VODIVIDE - Chia phần](ladders/greedy/prefix-constraints/vodivide.md)

### Math / Combinatorics

- [POST2 - A cộng B version 2](ladders/math/fft/post2.md)
- [CRYPTKEY - Chìa khóa mã số](ladders/math/gcd-lcm/cryptkey.md)
- [LAMP - Dàn đèn màu](ladders/math/number-theory-basics/lamp.md)
- [VOSFENCE - Xay hang rao](ladders/combinatorics/bounded-compositions/vosfence.md)
- [VOITSORT - Cây hoán vị](ladders/combinatorics/lexicographic-enumeration/voitsort.md)

### Geometry

- [KINGDOMS - Các vương quốc lồng nhau](ladders/geometry/sweep-line/kingdoms.md)
- [VOTELPH - Bà Nà](ladders/geometry/sweep-line/votelph.md)
- [PRAVO - Tam giác vuông](ladders/geometry/right-triangles/pravo.md)

### Advanced / Constructive

- [VMCOINS - Trò chơi với những đồng xu](ladders/advanced/constructive/vmcoins.md)
