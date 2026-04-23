# Practice

<div class="home-hero" markdown>
  <p class="hero-kicker">Deliberate repetition, not random grinding</p>
  <p class="hero-copy">
    Practice is organized <code>by topic first</code>, not only by judge. The goal is to help you learn an idea,
    solve targeted problems, and come back for repetition without losing the connection between concept and use.
  </p>
  <div class="hero-actions">
    <a class="md-button md-button--primary" href="ladders/">Open ladders</a>
    <a class="md-button" href="mixed-rounds/">Open mixed rounds</a>
    <a class="md-button" href="contest-playbooks/">Open contest playbooks</a>
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

-   __Mixed Rounds__

    Mix areas on purpose when you want retrieval practice, breadth, and contest-style switching.

    [Open mixed rounds](mixed-rounds/README.md)

-   __Contest Playbooks__

    Train toward a contest style such as `ICPC`, `USACO`, or olympiad-style prep with clearer workflow guidance.

    [Open contest playbooks](contest-playbooks/README.md)

</div>

## How To Use Problem Notes

<div class="grid cards" markdown>

-   __Read the classification first__

    Check the main topic, subtype, and difficulty before you jump into code. That keeps your practice intentional.

-   __Use the idea section actively__

    Try to restate the key idea in your own words before comparing with the stored solution.

-   __Track status honestly__

    Keep `todo`, `attempted`, `solved`, and `reviewed` meaningful so the repo becomes a real training log.

</div>

## Browse The Catalog

- [Problem index](../docs/problem-index.md): one table for every currently tracked solved note, with links to the note, code, ladder, and tutorial hub
- [External problem index](../docs/external-problem-index.md): curated official and trusted problems outside the repo, organized by topic and usable as the next practice queue
- [Topic maps](../docs/topic-maps/index.md): source-backed pages for each subtopic, including trusted learning references, official practice banks, and every repo problem tagged there

## Path Shapes

```text
practice/ladders/<area>/<subtopic>/<problem-code>.md
practice/mixed-rounds/<pack>.md
practice/contest-playbooks/<track>.md
```

## Problem Note Contract

Required fields:

- `Title`
- `Judge / source`
- `Original URL`
- `Main topic`
- `Secondary topics`
- `Difficulty`
- `Status`: `todo`, `attempted`, `solved`, `reviewed`
- `Solution file`

Optional fields:

- `Subtype`
- `Mirror / English URL`
- `Source contest`
- `Alternate solution variants`

Suggested section order:

1. `Why practice this`
2. `Core idea`
3. `Complexity`
4. `Pitfalls / judge notes`
5. `Solutions`

!!! tip "Best way to use this section"
    Read one topic page, solve one focused problem note, then write or adapt one clean implementation before moving on.

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
