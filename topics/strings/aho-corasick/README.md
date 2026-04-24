# Aho-Corasick

Aho-Corasick is the standard exact-matching automaton for:

- many patterns
- one text stream
- one preprocessing pass over the pattern dictionary
- then one linear scan over the text

Among the standard contest string tools:

- [KMP](../kmp/README.md) is for one pattern
- [Z-Function](../z-function/README.md) is for one-string prefix-style structure
- [Suffix Automaton](../suffix-automaton/README.md) is for all substrings of one base string
- Aho-Corasick is for **many patterns against one text**

This page teaches the contest route that matters most:

1. build a trie of the patterns
2. add failure links by BFS
3. decide how outputs are propagated
4. scan the text or run DP over automaton states

## At A Glance

Reach for Aho-Corasick when:

- the pattern set is known first
- many patterns share prefixes
- you want to search one long text or many generated strings against the same dictionary
- rerunning KMP once per pattern would waste too much work

Strong contest triggers:

- "given `k` patterns and one text, find all matches"
- "for each pattern, does it appear in the text?"
- "count how many forbidden patterns occur"
- "build strings that avoid a forbidden dictionary"
- "multi-pattern exact matching"

Strong anti-cues:

- there is only one pattern: KMP or Z is usually simpler
- you need approximate matching rather than exact matching
- the real problem is about one base string and all its substrings: suffix automaton or suffix array may fit better
- the alphabet is huge and the pattern set is tiny enough that direct hashing / map-based checks are simpler

What success looks like after studying this page:

- you can explain failure links as trie-state fallback, not as a memorized BFS trick
- you know why BFS order is exactly what makes failure-link construction valid
- you can distinguish `terminal`, `output`, and `visited-count propagation` viewpoints
- you can decide when to complete missing transitions eagerly and when to leave them sparse
- you can reuse the automaton for both text scanning and DP over generated strings

## Prerequisites

- [Trie](../trie/README.md)
- [KMP](../kmp/README.md)
- [BFS And DFS](../../graphs/bfs-dfs/README.md)

Helpful neighboring topics:

- [Z-Function](../z-function/README.md)
- [Suffix Automaton](../suffix-automaton/README.md)
- [Digit DP](../../dp/digit-dp/README.md)

## Problem Model And Notation

Let:

- $P = \{p_1, p_2, \dots, p_k\}$ be the pattern set
- $T$ be the text
- $\Sigma$ be the alphabet

The trie of the patterns has:

- one node per distinct prefix of a pattern
- one edge per character extension

For each node `v`, the key fields are usually:

- `next[v][c]`: trie or automaton transition by character `c`
- `link[v]`: failure link
- `out[v]`: pattern ids, terminal count, or some aggregated output information

The root is node `0`.

The most important conceptual invariant is:

- node `v` represents one trie prefix
- `link[v]` is the node for the **longest proper suffix** of that prefix that is also a trie prefix

So when a transition fails, the automaton does **not** restart blindly. It falls back to the longest suffix state that could still continue matching.

## From Brute Force To The Right Idea

### Brute Force

Suppose you have `k` patterns and one text of length `n`.

The naive route is:

1. run one exact matcher per pattern
2. or restart matching from many text positions

Even if each individual pattern match is efficient, the repeated work is wasteful because many patterns share prefixes.

For example, if the pattern set contains:

```text
he, her, hers, hero
```

then all four patterns begin with the same prefix `he`. Matching them independently throws away that shared structure.

### First Compression: Store Shared Prefixes Once

The trie is the right first step:

- identical prefixes are stored once
- every pattern becomes one root-to-node path

This already compresses the pattern set structurally.

But a raw trie is not enough for streaming text search, because after a mismatch you do not want to restart at the root every time.

### Why Failure Links Are The Missing Piece

Suppose you are at trie node for:

```text
she
```

and the next text character does not continue from there.

You should not forget everything. The suffix:

```text
he
```

may still be a useful matched prefix of some dictionary pattern.

So the correct fallback is:

- not "go to root"
- but "go to the longest proper suffix that is also a trie node"

That is exactly what failure links encode.

### Why This Produces An Automaton

Once failure links exist, every text character can be processed by:

1. following trie edges when they exist
2. otherwise following failure links until a valid edge appears
3. then advancing by that character

This transforms the trie into a multi-pattern exact-matching automaton.

The original 1975 Aho-Corasick paper describes this in terms of three functions:

- `goto`
- `failure`
- `output`

That is still the cleanest mental model today.

## Core Invariant And Why It Works

### 1. Trie Nodes Represent Pattern Prefixes

Before adding failure links, every node already has a clean meaning:

- it is the prefix spelled by the path from the root

So a current node during scanning means:

- "the longest suffix of the processed text that is also a trie prefix is this path label"

This interpretation is what failure links preserve.

### 2. What The Failure Link Means

For a non-root node `v`, `link[v]` points to the node whose path label is the longest proper suffix of the label of `v` that also appears in the trie.

This is the trie-state analogue of KMP fallback:

- KMP falls back along borders of one pattern
- Aho-Corasick falls back along suffix-prefix relationships among trie nodes

If a node spells `hers`, then its failure link points to the node for the longest proper suffix of `hers` that is also a dictionary prefix.

### 3. Why BFS Builds Failure Links Correctly

Failure links are built in increasing depth order.

Why BFS?

Because when we compute `link[child]`, we need `link[parent]` already known.

Suppose:

- node `v` is already processed
- there is a trie edge by character `c` to node `u`

Then the correct failure target of `u` is:

$$
\text{the state reached from } link[v] \text{ by character } c.
$$

This works because:

- `link[v]` is already the best proper suffix state for `v`
- if that state can continue by `c`, then appending `c` gives the longest suffix-prefix candidate for `u`
- if not, repeated failure-link fallback keeps searching shorter suffix-prefix candidates

So BFS is not just an implementation convenience. It is the topological order that makes the recurrence valid.

### 4. Why Text Scan Is Linear

During scanning, each text character may cause:

- zero or more failure-link jumps
- then one successful transition

The key amortized fact is:

- every failure jump strictly shortens the current matched prefix
- every successful goto transition lengthens it by one

So the total amount of fallback work across the whole scan is linear in the text length, just like the failure-reuse argument in KMP.

The original paper emphasizes the same operational property: one input symbol is processed per machine cycle once root behavior is completed properly.

### 5. Output Semantics: Three Common Contest Views

There are three equally standard ways to think about outputs.

#### Terminal-list view

Each terminal node stores the pattern ids that end there.

When the scan reaches a node, you may also need to follow failure links to report all suffix patterns that end there.

This is the cleanest conceptual model.

#### Aggregated-output view

Instead of storing only local terminals, propagate output counts through failure links during BFS:

$$
out[v] \mathrel{+}= out[link[v]].
$$

Then every state already knows how many pattern endings are represented there.

This is what the repo template does for simple counting.

The tradeoff is that plain aggregated counts are great for:

- "how many pattern endings are active here?"

but not enough by themselves for:

- "which exact pattern ids ended here?"

#### Offline visited-count propagation

For yes/no or count-per-pattern problems, a common contest trick is:

1. scan the text and count visits to states
2. process states in reverse BFS order
3. add each state's visits into its failure-link parent

After that, the terminal node of each pattern knows how many times that pattern appeared.

Duplicate patterns are handled naturally here: if two inputs end at the same terminal node, they simply read the same propagated total.

This is the route used in [Finding Patterns](../../../practice/ladders/strings/aho-corasick/findingpatterns.md).

### 6. Why Automaton DP Works

Once missing transitions are completed, the automaton becomes a deterministic machine over the alphabet.

That means DP states such as:

$$
dp(pos,\ state)
$$

are natural whenever you generate strings character by character.

Typical rule:

- if landing in a terminal / forbidden-output state is illegal, ban those transitions

This is the exact bridge from "pattern matching automaton" to "constraint DP over strings."

## Complexity And Tradeoffs

Let:

- $M$ be the total length of all patterns
- $S$ be the number of trie nodes, so $S = O(M)$

Typical bounds:

- trie construction: $O(M)$
- BFS failure-link construction: $O(S \cdot |\Sigma|)$ for dense fixed alphabets
- scan one text: $O(|T|)$ once transitions are completed densely, or $O(|T| + \text{matches})$ when reporting explicit matches
- memory: $O(S \cdot |\Sigma|)$ for dense arrays, smaller but heavier-constant for sparse maps

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| Aho-Corasick | many exact patterns against one text / one generated-string DP | linear after preprocessing | more memory and setup than one-pattern tools |
| KMP | one pattern against one text | linear and simpler | cannot reuse prefix structure across many patterns |
| Z-function | one-string prefix-matching tasks | linear and compact | not the right model for large pattern dictionaries |
| suffix automaton | one base string, all substrings matter | linear build | solves the opposite direction of many AC tasks |
| hashing | many equality checks with acceptable collision risk | very light | not a full exact multi-pattern automaton |

Rule of thumb:

- one pattern -> KMP / Z
- many patterns, one text -> Aho-Corasick
- one text, all substrings of it matter -> suffix automaton or suffix array

## Variant Chooser

| Variant | Use it when | Main idea | Main pitfall |
| --- | --- | --- | --- |
| dense lowercase automaton | alphabet is tiny and fixed | complete all missing transitions | memory is tied to alphabet size |
| sparse-edge AC | alphabet is large or patterns are sparse | keep only real edges, follow failure in scan loop | scan code becomes more delicate |
| aggregated-output AC | only counts / presence matter | push output info through failure links | losing per-pattern identity |
| reverse-BFS propagation | per-pattern answers after one scan | count visits, then push counts upward | forgetting reverse BFS order |
| automaton DP | forbid / require patterns in generated strings | DP on `(pos, state)` | forgetting to block terminal / output states |

## Worked Examples

### Example 1: The Classic `he / she / his / hers`

Take the dictionary:

```text
he
she
his
hers
```

This is the original paper's famous example.

The trie shares prefixes:

- `h`
- `he`
- `hi`
- `s`
- `sh`

Now look at the node for:

```text
she
```

Its longest proper suffix that is also a trie prefix is:

```text
he
```

So:

```text
link("she") = "he"
```

That one failure link explains the whole algorithmic idea: after matching `she`, the automaton still remembers that `he` is also a valid suffix match.

If we scan:

```text
ushers
```

then after reading the prefix ending at `e`, the automaton lands at the node for `she`, and through its output / failure structure we report:

- `she`
- `he`

Then on the next letters `r`, `s`, the automaton eventually reports:

- `hers`

So one pass over the text finds all overlapping matches naturally.

### Example 2: Why Reverse BFS Propagation Solves `Finding Patterns`

In [Finding Patterns](../../../practice/ladders/strings/aho-corasick/findingpatterns.md), we only need to know whether each pattern appears at least once.

The clean route is:

1. remember the terminal node of each pattern
2. scan the text and count how many times each state is visited
3. process states in reverse BFS order and add visits into `link[v]`

Why does this work?

Because if the scan visits some state `v`, then every suffix-pattern state on the failure chain also matched at that text position.

So reverse propagation along failure links is exactly aggregating suffix matches.

After that:

- `visits[terminal(pattern)] > 0`

means the pattern occurred at least once.

This trick is perfect for:

- yes / no per pattern
- total occurrence count per terminal class

but it does **not** by itself recover every individual match position. For full reporting, keep explicit output lists during the scan.

This is a great first Aho-Corasick problem because it teaches:

- terminal nodes
- failure links
- and failure-tree aggregation

without drowning in output-list bookkeeping.

### Example 3: Forbidden-Pattern DP

Suppose we want to count strings of length `n` over some alphabet that avoid a dictionary of forbidden words.

Build the Aho-Corasick automaton for the forbidden words.

Then define:

$$
dp(pos,\ state)
$$

as the number of length-`pos` prefixes that end in automaton state `state` without having hit a forbidden output yet.

Transition rule:

- try each next character
- move by the automaton transition
- if the destination state is terminal or has inherited forbidden output, skip it
- otherwise add the DP value

This is the cleanest "Aho-Corasick meets DP" pattern, and it is why this automaton belongs near [Digit DP](../../dp/digit-dp/README.md) and not only near pure matching topics.

## Algorithm And Pseudocode

The repo starter implementation is:

- [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)

### Build Trie

```text
add_word(word):
    v = root
    for character c in word:
        if next[v][c] does not exist:
            create it
        v = next[v][c]
    mark v as terminal
```

### Build Failure Links By BFS

```text
build():
    queue q

    for each character c:
        if root has real child by c:
            link[child] = root
            push child
        else:
            next[root][c] = root

    while q not empty:
        v = pop q

        propagate local output from link[v] into v if desired

        for each character c:
            if v has real child u by c:
                link[u] = next[link[v]][c]
                push u
            else:
                next[v][c] = next[link[v]][c]
```

This "complete the missing transitions" style gives a very simple scan loop later.

### Scan One Text

```text
state = root
for character c in text:
    state = next[state][c]
    consume output(state)
```

If you keep sparse edges instead, replace that one-line transition by:

```text
while state != root and next[state][c] missing:
    state = link[state]
if next[state][c] exists:
    state = next[state][c]
else:
    state = root
```

So the sparse version keeps the same logical fallback, but performs it explicitly during the scan instead of pre-filling all automaton transitions.

### Reverse-BFS Visit Propagation

```text
scan text and count visits[state]

for v in reverse_bfs_order:
    visits[link[v]] += visits[v]
```

Now a terminal node stores the total number of text positions whose failure chain reaches it.

## Implementation Notes

### 1. Decide Dense Versus Sparse Early

For lowercase English patterns:

- fixed `26`-transition arrays are simple and fast

For large alphabets:

- maps or hash tables may save a lot of memory

The tradeoff is exactly the usual one:

- dense arrays: fastest transitions, more memory
- sparse maps: more flexible, heavier constants

### 2. Root Behavior Is Part Of Correctness

The original paper emphasizes that root transitions should never fail during scanning.

In dense implementations, this is handled by filling:

```text
next[root][c] = root
```

for missing characters.

That is why the scan loop can process one input character cleanly each iteration.

In sparse implementations, you keep the same semantic rule, but write it in code as:

- "while I can still fail, follow `link`"
- and if root still has no edge, stay at root

### 3. `terminal` And `output` Are Not The Same Concept

A node may be:

- directly terminal for some pattern
- or non-terminal but still have inherited output through failure links

This distinction matters a lot in automaton DP:

- a state can be forbidden even if its own trie path is not itself a full pattern

### 4. Reverse BFS Is The Right Direction For Failure Aggregation

Failure links go from deeper states to shallower suffix states.

So if you want to push information from matches to all suffix patterns, the correct data flow is:

- longer / deeper states first
- then their failure-link parents

That is exactly why reverse BFS order works.

### 5. Aho-Corasick Versus KMP

This is the single most important boundary:

- KMP preprocesses one pattern
- Aho-Corasick preprocesses a whole dictionary

You can think of Aho-Corasick as "KMP fallback, but on trie states."

If there is only one pattern, Aho-Corasick is usually unnecessary overhead.

### 6. Aho-Corasick Versus Suffix Automaton

These two are often confused because both are automata over strings.

But they solve opposite modeling directions:

- Aho-Corasick: many patterns, one text
- suffix automaton: one text, all substrings of it

If the problem statement starts from a pattern dictionary, Aho-Corasick is much more likely to be the natural fit.

## Practice Archetypes

The most common Aho-Corasick-flavored tasks are:

- **does each pattern appear?**
- **count all matches of many patterns**
- **report pattern ids at matches**
- **count / construct strings avoiding forbidden patterns**
- **DP on `(position, automaton_state)`**

The strongest contest smell is:

- the pattern set is reused
- shared prefixes should matter
- exact matching is still required

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary:

- [Aho and Corasick: Efficient String Matching: An Aid to Bibliographic Search](https://cr.yp.to/bib/1975/aho.pdf)

Course:

- [Stanford CS166 course page: Aho-Corasick String Matching](https://web.stanford.edu/class/archive/cs/cs166/cs166.1146/)

Reference:

- [CP-Algorithms: Aho-Corasick algorithm](https://cp-algorithms.com/string/aho_corasick.html)
- [OI Wiki: AC Automaton](https://en.oi-wiki.org/string/ac-automaton/)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Aho-Corasick ladder](../../../practice/ladders/strings/aho-corasick/README.md)
- practice note: [Finding Patterns](../../../practice/ladders/strings/aho-corasick/findingpatterns.md)
- starter template: [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)
- notebook refresher: [String cheatsheet](../../../notebook/string-cheatsheet.md)

## Related Topics

- [Trie](../trie/README.md)
- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
- [Suffix Automaton](../suffix-automaton/README.md)
- [Digit DP](../../dp/digit-dp/README.md)
