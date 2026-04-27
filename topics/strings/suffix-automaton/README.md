# Suffix Automaton

Suffix automaton is the compact DFA view of **all substrings of one string**.

Among the standard contest string tools:

- [KMP](../kmp/README.md) and [Z-Function](../z-function/README.md) are narrower and easier
- [Suffix Array And LCP](../suffix-array-lcp/README.md) is often cleaner for static lexicographic order
- suffix automaton is the strongest "one string, all substrings, online build" structure in this cluster

This page teaches the contest route that matters most:

1. understand what one state actually means
2. understand why clones are necessary
3. derive the standard counting / occurrence / LCS tricks from the state invariant

## At A Glance

Reach for suffix automaton when:

- the string is built left to right and you want to keep a substring structure online
- the task is about **all substrings of one base string**
- you want distinct-substring counting, occurrence aggregation, or longest common substring with another string
- suffix order is not the main object, but substring behavior is

Strong contest triggers:

- "number of distinct substrings"
- "for each pattern, how many times does it occur in the text?"
- "longest common substring"
- "one fixed base string, many substring-structure questions"
- "online appends, then queries"

Strong anti-cues:

- you only need one exact pattern match: KMP or Z is simpler
- you mainly care about sorted suffixes, suffix ranks, or adjacent LCPs: suffix array is more natural
- the task is about many patterns inserted into one trie-like machine: [Aho-Corasick](../aho-corasick/README.md) may fit better
- you only need substring equality and collision risk is acceptable: hashing may be much lighter

What success looks like after studying this page:

- you can explain a SAM state as an `endpos` class, not as "some node in a graph"
- you know why every non-root state represents lengths in one interval
- you can explain what the suffix link of a state means
- you can say exactly when a clone is created and what invariant it repairs
- you can derive the formula for distinct substrings and the standard occurrence-propagation trick

## Prerequisites

- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md)

Helpful neighboring topics:

- [Trie](../trie/README.md)
- [Aho-Corasick](../aho-corasick/README.md)
- [String Hashing](../hashing/README.md)

## Problem Model And Notation

Let $s$ be a string of length $n$.

For a substring $x$, define:

$$
\mathrm{endpos}(x) = \{ i \mid x \text{ ends at position } i \text{ in } s \}.
$$

Two substrings are equivalent if they have the same `endpos` set.

The suffix automaton of $s$ is the minimal partial DFA recognizing all substrings of $s$. In contest language, we usually think of each state as one equivalence class of substrings with the same `endpos` behavior.

For each state `v`, the standard fields are:

- `len[v]`: the maximum length of a substring represented by `v`
- `link[v]`: the suffix link of `v`
- `next[v][c]`: transition by character `c`

The root is state `0`, with:

- `len[0] = 0`
- `link[0] = -1`

The single most important invariant is:

$$
\text{all substrings represented by } v \text{ have lengths in }
(\mathrm{len}[\mathrm{link}[v]],\ \mathrm{len}[v]].
$$

So every non-root state represents a **contiguous interval of substring lengths**, not one substring and not an arbitrary set of lengths.

## Clone Playground

<div class="visual-card" data-sam-visualizer>
  <p class="visual-caption">
    Replay the single clone event while building the suffix automaton of `abaabb`. The important thing to watch is not the whole
    algorithm at once, but why one existing transition becomes too long for a shorter context and must be split.
  </p>
  <div class="chip-row">
    <span class="chip">Blue solid edges: transitions</span>
    <span class="chip">Purple dashed edges: suffix links</span>
    <span class="chip">Blue nodes: states on the current conflict path</span>
    <span class="chip">Purple node: the clone</span>
  </div>
  <div class="visual-controls">
    <button type="button" data-role="step">Show clone repair</button>
    <button type="button" data-role="run">Jump to repaired SAM</button>
    <button type="button" data-role="reset">Reset</button>
  </div>
  <div class="visual-grid">
    <div class="visual-panel">
      <div class="visual-surface graph-visual-surface" data-role="canvas"></div>
      <h4>Processed text</h4>
      <div class="visual-strip visual-strip--six" data-role="text-strip"></div>
    </div>
    <div class="visual-panel">
      <h4>What to watch</h4>
      <div class="visual-stats">
        <div class="visual-stat">
          <strong>Invariant</strong>
          <div data-role="invariant"></div>
        </div>
        <div class="visual-stat">
          <strong>Current stage</strong>
          <code data-role="stage"></code>
        </div>
        <div class="visual-stat">
          <strong>Conflict</strong>
          <code data-role="conflict"></code>
        </div>
        <div class="visual-stat">
          <strong>Repair</strong>
          <code data-role="repair"></code>
        </div>
      </div>
      <p class="visual-note" data-role="note"></p>
    </div>
  </div>
</div>

### Visual Reading Guide

What to notice:

- before the final `b`, the suffix-link walk reaches the root and finds an existing `b` transition into a state whose `len` is too large for the shorter context
- after cloning, the root goes by `b` into a new state with `len = 1`, while the old state keeps the longer interval and changes its suffix link to the clone

Why it matters:

- this is the shortest route from "clones happen in the weird case" to seeing the precise invariant they repair
- it also makes clear that a clone is not a new occurrence of a substring; it is a new representative for the shorter `endpos` class that used to be merged too coarsely

Code bridge:

- the conflict is exactly the standard branch `if len[p] + 1 < len[q]`
- the repair shown here is the textbook clone procedure: copy transitions and suffix link of `q`, set `len[clone] = len[p] + 1`, redirect affected transitions, then set `link[q] = link[cur] = clone`

Boundary:

- this widget isolates one clone event only; the rest of the SAM extension loop still depends on the suffix-link walk that adds missing transitions on the way back
- if you only need one exact pattern search, this whole structure is overkill; reopen [KMP](../kmp/README.md) or [Z-Function](../z-function/README.md)

## From Brute Force To The Right Idea

### Brute Force

If you want to reason about all substrings of a string of length $n$, the naive picture is:

1. enumerate all $O(n^2)$ substrings
2. store them explicitly
3. deduplicate or answer queries over that huge set

This is too large both conceptually and computationally.

### First Compression: Many Substrings Behave The Same

Suppose two substrings always end at exactly the same positions in the text.

Then whenever one can be extended on the right by some continuation inside the text, the other can too, because they occur in exactly the same ending contexts. So these substrings have the same future behavior.

That suggests a more aggressive summary:

- do not store every substring separately
- merge substrings that have the same `endpos` set

This is the automaton viewpoint.

### Why This Leads To A DFA

If a state summarizes one `endpos` class, then reading one more character should move us to the class of the longer substring.

So transitions are not arbitrary graph edges. They are "extend the represented substrings by one character when that extension is still a substring of $s$."

That is why suffix automaton becomes a deterministic acyclic graph of substring behavior.

### Why Online Construction Is Possible

When we append one new character `c` to the current text:

- only substrings ending at the new last position are new
- all older internal substring behavior remains valid, except for the places where new suffixes must be connected into the automaton

That is exactly what the standard extension algorithm does:

1. create a new state for the new longest suffix
2. walk suffix links backward to add missing `c` transitions
3. split one old state with a clone if an old transition would otherwise violate the length invariant

## Core Invariant And Why It Works

### 1. What One State Really Means

A SAM state is not "one substring." It is one equivalence class of substrings sharing the same `endpos` set.

Inside one state `v`:

- the longest represented substring has length `len[v]`
- the longest represented substring in the suffix-link parent has length `len[link[v]]`

Everything strictly between those two lengths belongs to `v` as well:

$$
\mathrm{len}[\mathrm{link}[v]] + 1,\ \mathrm{len}[\mathrm{link}[v]] + 2,\ \dots,\ \mathrm{len}[v].
$$

That interval is the reason many classic formulas become one-liners.

### 2. What The Suffix Link Means

For a non-root state `v`, `link[v]` points to the state representing the **longest proper suffix** that lives in a different `endpos` class.

So suffix links are not arbitrary fallback pointers. They are the structural chain:

- take the longest string in `v`
- move to the longest proper suffix whose behavior is genuinely different

This immediately implies:

$$
\mathrm{len}[\mathrm{link}[v]] < \mathrm{len}[v].
$$

That strict drop is what keeps the graph acyclic and what makes length-ordered DP possible later.

### 3. Why Walking Suffix Links During Extension Is Correct

Suppose we append character `c`.

The new substrings are exactly the suffixes of the new full string ending at that new last position. Starting from the old `last` state and walking suffix links enumerates those suffix classes from longest to shorter ones.

Whenever some visited state has no `c` transition yet, we add one to the new state. This is correct because:

- that state represents a suffix class of the old string
- appending `c` creates a new valid longer substring ending at the new last position
- until we meet a state that already had a `c` transition, this extension behavior is genuinely new

### 4. Why Clones Exist

The only delicate case is when we first hit a state `p` that already has a transition by `c` to some state `q`.

If:

$$
\mathrm{len}[p] + 1 = \mathrm{len}[q],
$$

then `q` is already the correct suffix-link target for the new state, and life is easy.

But if:

$$
\mathrm{len}[p] + 1 < \mathrm{len}[q],
$$

then `q` is too "long" to be used directly. It mixes two behaviors that should now be separated:

- the shorter-context behavior needed by the new path
- the older longer-context behavior already stored in `q`

So we create a **clone**:

- copy all outgoing transitions of `q`
- copy `link[q]`
- set `len[clone] = len[p] + 1`
- redirect the relevant `c` transitions along the suffix-link chain from `q` to `clone`
- make both `q` and the new state point by suffix link to `clone`

The clone is not a new substring occurrence. It is a new representative for the shorter equivalence class that was previously merged too coarsely.

Why are copied transitions still correct? Because cloning does **not** change which right-extensions are currently valid from that class. It only fixes the boundary between:

- the shorter interval that should branch earlier
- and the longer interval that should remain in `q`

### 5. Why The Structure Stays Small

On each appended character:

- we always create one new "real" state
- we create at most one clone

So after processing a string of length $n$:

$$
\text{number of states} \le 2n - 1
$$

for $n \ge 1$.

The classic bound on transitions is linear as well:

$$
\text{number of transitions} \le 3n - 4
$$

for the standard suffix automaton theorem.

That is the core reason SAM is contest-usable at all: it represents all substrings, but only with linear many states and transitions.

### 6. Terminal States And Occurrences

During construction, every prefix of the processed string corresponds to the current `last` state at some moment.

Those states are called terminal states. They correspond to suffixes of the whole string.

For occurrence counting, the common pattern is:

1. every time we append a character, increment the count of the new real state
2. sort states by `len`
3. propagate counts from longer states to `link[v]`

After that propagation, the state reached by a pattern stores how many times that pattern occurs in the base string.

## Complexity And Tradeoffs

For a standard online SAM build:

- states: $O(n)$
- transitions: $O(n)$ total
- build: $O(n)$ with constant alphabet arrays or expected near-linear with sparse maps
- many classic queries become $O(|pattern|)$ or one extra DAG DP

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| suffix automaton | one base string, many substring-structure questions, online build | linear build | hardest mental model in the standard strings toolkit |
| suffix array + LCP | static lexicographic order / repeated-substring structure | `O(n log n)` preprocess | not online |
| KMP / Z | one exact matching or border-style task | linear | much narrower |
| hashing | equality / compare-style tasks with acceptable collision risk | very light | probabilistic and less structural |
| Aho-Corasick | many patterns against one text stream | linear in text + matches | solves the opposite direction of many SAM tasks |

Rule of thumb:

- if the question is "what can all substrings of this one text do?" -> think suffix automaton
- if the question is "where do these many patterns occur in one text?" -> think Aho-Corasick
- if the question is "what is the sorted suffix structure?" -> think suffix array

## Variant Chooser

| Variant | Use it when | Main idea | Main pitfall |
| --- | --- | --- | --- |
| bare SAM build | you need online substring structure | one state per `endpos` class | not knowing what a state means |
| SAM + distinct-count formula | count distinct substrings | sum `len[v] - len[link[v]]` | counting root or misunderstanding intervals |
| SAM + occurrence propagation | answer frequency queries | push counts from longer states to suffix links | incrementing clones like real states |
| SAM + scan second string | longest common substring | walk transitions, fallback by suffix links | forgetting to shrink current matched length when following links |
| SAM + DAG DP | count / optimize over all substrings | DP in increasing or decreasing `len` order | using the wrong topological direction |

## Worked Examples

### Example 1: Distinct Substrings From State Intervals

Take:

```text
s = aba
```

Its non-root SAM states contribute:

- one state with interval `(0, 1]`, contribution `1`
- one state with interval `(0, 2]`, contribution `2`
- one state with interval `(1, 3]`, contribution `2`

So:

$$
1 + 2 + 2 = 5
$$

distinct substrings.

And indeed the distinct substrings are:

```text
a, b, ab, ba, aba
```

This is the most important formula on the page:

$$
\text{distinct substrings}
=
\sum_{v \ne 0}
(\mathrm{len}[v] - \mathrm{len}[\mathrm{link}[v]]).
$$

Why is this a true partition rather than a lucky counting trick?

- each non-root state contributes exactly one substring for every length in its interval
- no substring can belong to two different states, because a substring has exactly one `endpos` class

So the intervals do not overlap across states at the level of represented substrings.

### Example 2: Why A Clone Appears

Take:

```text
s = banana
```

During the build, when the later `a` is appended, you encounter a state `q` already reached by character `a`, but it is too long:

$$
\mathrm{len}[p] + 1 < \mathrm{len}[q].
$$

Intuitively, the old state `q` was summarizing both:

- the very short substring `a`
- and longer contexts that also end with `a`

After the new append, those two behaviors must be separated. So we create a clone:

- same outgoing transitions as `q`
- same old suffix link as `q`
- shorter `len`

The clone becomes the correct representative for the shorter-context class, while `q` keeps the longer-context class.

That is the whole point of cloning:

- not "make another copy just in case"
- but "split one too-large equivalence class so the interval invariant stays true"

### Example 3: Longest Common Substring With Another String

Build the SAM of:

```text
s = ababa
```

Now scan:

```text
t = cababd
```

Maintain:

- current state `v`
- current matched length `cur`

As you read `t`:

- if the next edge exists, follow it and increase `cur`
- otherwise follow suffix links until the edge exists or you return to root
- if you follow a suffix link to state `u`, reset `cur` to `len[u]`

This scan discovers the longest common substring:

```text
abab
```

of length `4`.

The reason it works is exactly the same SAM invariant:

- state = right-context summary
- suffix link = longest valid fallback class

So scanning another string through the automaton is the substring analogue of "reuse the biggest valid suffix and continue."

## Algorithm And Pseudocode

Repo starter template:

- [suffix-automaton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-automaton.cpp)

Best practice anchor for a full solved note:

- [distinctsubstrings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-automaton/distinctsubstrings.cpp)

### Standard Extension

```text
extend(c):
    create cur
    len[cur] = len[last] + 1
    occ[cur] = 1   // only if you plan to propagate occurrences later

    p = last
    while p != -1 and next[p][c] does not exist:
        next[p][c] = cur
        p = link[p]

    if p == -1:
        link[cur] = root

    else:
        q = next[p][c]

        if len[p] + 1 == len[q]:
            link[cur] = q

        else:
            create clone
            copy transitions of q into clone
            link[clone] = link[q]
            len[clone] = len[p] + 1
            occ[clone] = 0   // clone is structural, not a new end position

            while p != -1 and next[p][c] == q:
                next[p][c] = clone
                p = link[p]

            link[q] = clone
            link[cur] = clone

    last = cur
```

### Distinct Substrings

```text
answer = 0
for each non-root state v:
    answer += len[v] - len[link[v]]
```

### Occurrence Propagation

```text
counting sort states by len
process states from longer to shorter:
    occ[link[v]] += occ[v]
```

After this, if a pattern walks to state `v`, then `occ[v]` is its number of occurrences.

The important initialization rule is:

- real appended states start with `occ = 1`
- clones start with `occ = 0`

because clones are structural splits, not new end positions.

### Longest Common Substring With Another String

```text
v = root
cur = 0
best = 0

for character c in other_string:
    while v != root and next[v][c] does not exist:
        v = link[v]
        cur = len[v]

    if next[v][c] exists:
        v = next[v][c]
        cur++
    else:
        v = root
        cur = 0

    best = max(best, cur)
```

## Implementation Notes

### 1. Know Exactly What Each Field Means

Do not code SAM while thinking:

- `len` is "depth"
- `link` is "parent"

That is too vague.

Use the real meaning:

- `len[v]` = maximum represented substring length
- `link[v]` = longest proper suffix in a different class

Once those are solid, clone logic becomes much easier to debug.

### 2. A Clone Is Structural, Not A New Occurrence

When you create a clone:

- copy transitions
- copy the suffix link
- set a shorter `len`

But do **not** treat it as a newly seen end position.

This is the classic bug in frequency problems:

- real appended state gets occurrence `1`
- clone gets occurrence `0`

and only later receives counts through propagation.

### 3. Propagate In Descending `len`

If you want occurrence counts, process states from longer to shorter.

Why?

Because the suffix link points from a longer class to a shorter one. So the data flow is:

- children / longer states first
- suffix-link parent / shorter state later

Reversing that order silently breaks frequency answers.

### 4. A Reached State Represents A Whole Class, Not One End Position

If a pattern walks successfully to state `v`, the answer you read from `v` is about the whole `endpos` class of that pattern.

This is why one state can answer:

- how many times the pattern occurs
- whether it appears at all
- and, after extra preprocessing, some aggregate over its occurrences

Do not think "the path ended at one occurrence." Think "the path ended at the class summarizing all occurrences of this substring."

### 5. Arrays Versus Maps

For lowercase Latin letters:

- fixed `26`-transition arrays are simple and fast

For larger alphabets:

- maps or hash tables are often cleaner

The contest tradeoff is:

- arrays: faster, larger memory, alphabet-specific
- maps: more general, slightly heavier constants

### 6. State Count Is Linear, But Mental Overhead Is Real

Suffix automaton is powerful, but contest mistakes are usually conceptual, not syntactic:

- wrong clone length
- wrong redirect loop
- wrong occurrence propagation
- wrong interpretation of which queries are answered by a reached state

If the task is only about exact pattern matching or borders, the simpler structure is usually the better one.

### 7. Suffix Automaton Versus Suffix Array

This is the most useful judgment call in the static-string setting:

- suffix array is better when lexicographic order and adjacent LCP are the main story
- suffix automaton is better when you want one compact machine for all substrings and state-based aggregation

If the task sounds like:

- "sort suffixes"
- "rank suffixes"
- "RMQ on LCP"

prefer suffix array.

If it sounds like:

- "count all distinct substrings"
- "aggregate occurrences by substring state"
- "scan another string against one growing base text"

prefer suffix automaton.

## Practice Archetypes

The most common suffix-automaton-flavored tasks are:

- **count distinct substrings**
- **count occurrences of a queried pattern after one preprocessing build**
- **longest common substring**
- **DP over all substring states**
- **online extension of one base string**

The strongest contest smell is:

- one string is special
- all substrings of that string matter
- the result depends on state-style aggregation rather than suffix order

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary:

- [Blumer, Blumer, Haussler, Ehrenfeucht, Chen, Seiferas: The Smallest Automaton Recognizing the Subwords of a Text](https://www.sciencedirect.com/science/article/pii/0304397585901574)

Course:

- [CMU 15-451 Notes: Suffix Trees and Suffix Automata](https://www.cs.cmu.edu/~15451-f20/LectureNotes/suffix-trees.pdf)

Reference:

- [CP-Algorithms: Suffix Automaton](https://cp-algorithms.com/string/suffix-automaton.html)
- [USACO Guide: Suffix Automaton](https://usaco.guide/adv/string-suffix?lang=cpp)
- [OI Wiki: Suffix Automaton](https://en.oi-wiki.org/string/sam/)

Essay / blog:

- [CMU 15-295 course page noting suffix automata in the strings toolkit](https://contest.cs.cmu.edu/295/f22/)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Suffix Automaton ladder](../../../practice/ladders/strings/suffix-automaton/README.md)
- practice note: [Distinct Substrings](../../../practice/ladders/strings/suffix-automaton/distinctsubstrings.md)
- starter template: [suffix-automaton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-automaton.cpp)
- starter example: [distinctsubstrings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-automaton/distinctsubstrings.cpp)
- notebook refresher: [String cheatsheet](../../../notebook/string-cheatsheet.md)

## Related Topics

- [Suffix Array And LCP](../suffix-array-lcp/README.md)
- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
- [Aho-Corasick](../aho-corasick/README.md)
- [String Hashing](../hashing/README.md)
