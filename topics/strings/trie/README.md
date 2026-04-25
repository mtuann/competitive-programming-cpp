# Trie

A trie is the canonical data structure for **prefix-shaped search**.

It is the right tool when the important unit is not "the whole string as one comparable object," but rather:

- prefixes shared by many strings
- character-by-character or bit-by-bit traversal
- dictionary structure that should be reused across many queries

Among the standard contest string tools:

- sorting + binary search treats strings as whole ordered keys
- [KMP](../kmp/README.md) and [Z-Function](../z-function/README.md) treat one string or one pattern structurally
- [Aho-Corasick](../aho-corasick/README.md) adds failure links on top of a trie
- trie itself is the base prefix tree underneath that whole family

This page teaches the contest route that matters most:

1. understand a node as a prefix, not a character
2. know exactly when `pass_count` and `end_count` are the right metadata
3. separate plain dictionary tries from the dedicated [Binary Trie / XOR Queries](../../data-structures/binary-trie-xor/README.md) lane and heavier descendants like Aho-Corasick

## At A Glance

Reach for a trie when:

- you have many strings with shared prefixes
- prefix queries are frequent
- operations naturally consume one character or one bit at a time
- sorting plus binary search keeps re-checking long common prefixes

Strong contest triggers:

- "how many words start with this prefix?"
- "is this word in the dictionary?"
- "autocomplete / prefix counting / dictionary queries"
- "build a structure over many patterns before doing heavier matching"

Strong anti-cues:

- the dictionary is tiny and static, so sorting plus binary search is simpler
- the task is about one pattern against one text: KMP or Z is usually better
- the task is about sorted suffixes or substring order: suffix array is the right lens
- the alphabet is huge and sparse enough that raw trie memory would dominate
- the dictionary is static and even prefix queries can be answered by one sorted interval plus `lower_bound`

What success looks like after studying this page:

- you can explain a trie node as the prefix spelled by the root-to-node path
- you know why insert / query time depends on key length, not number of stored words
- you can distinguish `pass_count` from `end_count`
- you know when trie beats sorting and when it does not
- you can see xor trie and Aho-Corasick as natural variants rather than unrelated tricks

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

Helpful neighboring topics:

- [KMP](../kmp/README.md)
- [Aho-Corasick](../aho-corasick/README.md)
- [String Hashing](../hashing/README.md)
- [Binary Trie / XOR Queries](../../data-structures/binary-trie-xor/README.md)

## Problem Model And Notation

Let $D$ be a set or multiset of strings over an alphabet $\Sigma$.

A trie node corresponds to one prefix of the stored dictionary:

- the root corresponds to the empty string
- each edge appends one character
- the label of a node is the full root-to-node path

So if a node is reached by the path:

```text
c -> a -> t
```

then that node represents the prefix:

```text
cat
```

The standard node fields in a lowercase trie are:

- `next[v][c]`: child pointer by character `c`
- `pass_count[v]`: how many inserted words pass through this node
- `end_count[v]`: how many inserted words end exactly at this node

The key invariant is simple:

- every word with prefix `p` must pass through the node labeled `p`
- every word equal to `p` must also end there

Everything else in plain trie problems is built on top of that.

## From Brute Force To The Right Idea

### Brute Force

Suppose you store all words in a vector.

For membership:

- compare the query against many full strings

For prefix count:

- scan all words and test whether each one starts with the query prefix

That wastes work when many words share long prefixes.

For example, if the dictionary contains:

```text
apple
apply
application
apt
```

then every query starting with `ap` keeps re-reading the same early characters over and over.

### Prefix Sharing Is The Whole Point

A trie stores shared prefixes once:

- one node for `a`
- one node for `ap`
- then branches only where the words diverge

So the work for a query is:

- follow the query path character by character
- stop as soon as an edge is missing

That makes the runtime depend on the **query length**, not on the total number of stored strings.

### Why Sorting Is Not Always Enough

For a static dictionary, sorting is often a perfectly good solution.

If the dictionary is sorted, prefix counting can often be answered by finding the interval of words starting with that prefix. So trie is not automatically better just because the word "prefix" appears in the statement.

But sorting still treats words as whole comparable objects. A trie becomes more attractive when:

- there are many prefix queries
- you want online insertions
- you need extra prefix metadata
- or the same prefix path is reused repeatedly in later logic

That is the bridge from plain dictionary queries to structures like xor tries and Aho-Corasick.

## Core Invariant And Why It Works

### 1. A Node Represents A Prefix, Not A Character

This is the first thing to internalize.

The edge labels are characters. The node itself represents the whole prefix formed by the path to it.

That is why storing counts at nodes makes sense:

- `pass_count` is about the whole prefix
- `end_count` is about the whole word equal to that prefix

### 2. Why Membership Query Works

To test whether a word `w` exists:

1. start at the root
2. follow edges for each character of `w`
3. if any edge is missing, `w` is absent
4. otherwise, after the last character, check `end_count`

This is correct because every stored word corresponds to exactly one root-to-node path, and the terminal marker distinguishes:

- "this string is a stored word"
- from "this string is only a prefix of longer stored words"

### 3. Why Prefix Counting Works

To count how many words start with prefix `p`:

1. walk the trie along `p`
2. if the path fails, answer `0`
3. otherwise return `pass_count` at the final node

This works because every word with prefix `p` must pass through that prefix node, and no word without prefix `p` can pass through it.

### 4. `pass_count` And `end_count` Solve Different Questions

This distinction causes many beginner bugs.

If you insert:

```text
car
card
car
```

then at node `car`:

- `pass_count = 3`
- `end_count = 2`

So:

- `pass_count` answers prefix-frequency questions
- `end_count` answers exact-word multiplicity questions

Using one where the other is needed gives a logically wrong but often plausible-looking answer.

### 5. Why Lexicographic Enumeration Works Naturally

If children are traversed in character order, a DFS of the trie outputs the represented words in lexicographic order.

That is because trie edges already encode the first place where strings differ.

This is a useful structural fact even when the contest problem is not explicitly asking for "sort strings."

### 6. Why Xor Trie Is The Same Idea

For bitwise xor problems, replace characters by bits.

Each node now represents:

- one binary prefix of inserted numbers

For maximum xor with query `x`, the greedy rule is:

- at each bit, prefer the opposite bit if it exists

This is still just a prefix walk through a trie. The only difference is:

- the alphabet is `{0, 1}`
- the optimization target is numeric xor, not dictionary lookup

One practical rule matters a lot here:

- choose one fixed bit width for every inserted value and every query

Otherwise the tree shape itself becomes inconsistent across numbers.

## Complexity And Tradeoffs

If the total length of all inserted strings is $M$, then a plain trie has:

- nodes: $O(M)$
- insert: $O(|s|)$
- membership query: $O(|s|)$
- prefix query: $O(|prefix|)$

Memory depends heavily on the alphabet representation:

- dense arrays: fast transitions, larger memory
- sparse maps: smaller memory, heavier constants

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| trie | many prefix queries / online dictionary operations | by key length | memory-heavy on large sparse alphabets |
| sorting + binary search | static dictionary, few query types | `O(log n)` comparisons | each comparison still touches characters |
| hashing | exact membership / equality | light and practical | loses explicit prefix structure |
| Aho-Corasick | many patterns against one text | linear after preprocessing | heavier automaton layer |
| xor trie | maximum/minimum xor style tasks | by bit length | specialized to numeric bit problems |

Rule of thumb:

- if the key operation is "walk one prefix path," trie is a natural fit
- if you only need exact lookup in a small static set, sorting or hashing may be simpler

## Variant Chooser

| Variant | Use it when | Main idea | Main pitfall |
| --- | --- | --- | --- |
| lowercase dense trie | alphabet is small and fixed | array children per node | memory blow-up if copied to large alphabets blindly |
| sparse-map trie | alphabet is large / Unicode-like / sparse | keep only real edges | slower constants and more verbose code |
| multiset trie | duplicates matter | keep `pass_count` and `end_count` | using booleans where multiplicity matters |
| xor trie | maximize / minimize xor | greedy bit walk | forgetting signed / bit-width conventions |
| trie + DP | shared prefixes only make transitions cheaper | trie is not the whole answer | forcing the trie to solve the DP itself |
| Aho-Corasick descendant | many patterns against one text | add failure links on top of trie | forgetting the base trie meaning under the automaton |

## Worked Examples

### Example 1: Prefix Count

Insert:

```text
apple
apply
apt
bat
```

Now query prefix:

```text
ap
```

The walk is:

```text
root -> a -> p
```

and the final node has:

```text
pass_count = 3
```

because exactly three inserted words start with `ap`.

This is the cleanest example of why node metadata belongs on prefixes.

### Example 2: Exact Word Versus Prefix

Insert:

```text
car
card
care
```

Now query:

```text
car
```

The path exists, so `car` is definitely a prefix in the trie.

But to answer exact membership, we must also check:

```text
end_count("car") > 0
```

If later we deleted the word `car` but kept `card` and `care`, the path would still exist while exact membership would become false.

That is why "path exists" and "word exists" are different statements.

### Example 3: Why Trie Helps `Word Combinations`

In [Word Combinations](../../../practice/ladders/strings/trie/wordcombinations.md), the trie is not the whole solution.

We define:

$$
dp[i] = \text{number of ways to split } s[i..n-1].
$$

Then from each start position `i`, we walk forward through the text and the trie simultaneously.

Whenever the current trie node is terminal at position `j`, we add:

$$
dp[j + 1]
$$

into `dp[i]`.

The trie helps because:

- it explores only prefixes that actually exist in the dictionary
- it stops immediately when the next text character has no edge

So the trie is acting as a **shared-prefix transition filter** for the DP.

### Example 4: Xor Trie

Suppose we inserted numbers:

```text
5 = 0101
9 = 1001
```

and query with:

```text
6 = 0110
```

For maximum xor, inspect bits from most significant to least significant.

At each bit:

- if the current bit of `6` is `0`, prefer child `1`
- if the current bit of `6` is `1`, prefer child `0`

This greedy rule works because a higher differing bit dominates all lower bits in xor value.

So xor trie is not a separate magic trick. It is the same prefix-tree idea applied to binary strings with a greedy objective.

## Algorithm And Pseudocode

The repo starter implementation is:

- [trie-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/trie-basic.cpp)

### Insert

```text
insert(word):
    v = root
    pass_count[v]++

    for character c in word:
        if next[v][c] missing:
            create child
        v = next[v][c]
        pass_count[v]++

    end_count[v]++
```

### Exact Membership

```text
contains(word):
    v = root
    for character c in word:
        if next[v][c] missing:
            return false
        v = next[v][c]
    return end_count[v] > 0
```

### Prefix Count

```text
count_prefix(prefix):
    v = root
    for character c in prefix:
        if next[v][c] missing:
            return 0
        v = next[v][c]
    return pass_count[v]
```

### Lexicographic DFS

```text
dfs(v, current_string):
    output current_string end_count[v] times if terminal
    for children in character order:
        dfs(child, current_string + edge_character)
```

## Implementation Notes

### 1. Design Node Metadata Intentionally

Do not copy random trie fields from memory.

Ask what the problem actually needs:

- exact membership -> `end_count` or `is_terminal`
- prefix count -> `pass_count`
- duplicates -> counts, not booleans
- later DP / aggregation -> maybe extra metadata

This one decision often determines whether the trie code stays simple or becomes messy.

### 2. Dense Versus Sparse Child Storage

For lowercase `a-z`:

- `array<int, 26>` is usually the cleanest contest choice

For larger alphabets:

- `map`, `unordered_map`, or coordinate compression may be better

The wrong representation can waste most of your memory budget.

### 3. Root Counts Need A Policy Too

If `pass_count` is used, decide whether the root should count:

- all inserted words
- or only be treated as a structural node

The repo starter increments `pass_count` at the root as well. That is a good default, but it should be deliberate.

With that policy:

- `pass_count[root]` equals the total number of inserted words

which can occasionally answer a query directly, but only if you intended root to behave that way.

### 4. Trie Is Often A Helper, Not The Whole Solution

In many contest problems, the trie only makes transitions cheap enough. The real logic may still be:

- DP
- greedy
- offline counting
- or automaton construction

`Word Combinations` is the perfect reminder: trie filters candidate words, DP does the counting.

### 5. Tries Can Be Much Heavier Than They Look

The asymptotics are good, but node count is proportional to total inserted characters.

Common practical bugs:

- rebuilding huge tries per test case unnecessarily
- using dense arrays for a very sparse alphabet
- forgetting to reset pooled nodes between test cases

### 6. Xor Tries Need Bit Conventions Up Front

For xor tries, decide early:

- how many bits are stored
- whether values are treated as signed or unsigned
- whether leading zeros are part of the represented path

The greedy xor walk is only correct after those conventions are fixed consistently for both inserts and queries.

### 7. Trie Versus Aho-Corasick

This is the most useful boundary in this area:

- trie stores dictionary prefixes
- Aho-Corasick adds failure links so the dictionary can be scanned against a long text in one pass

So if the task reads like:

- "many patterns, one text"

plain trie is usually not the finish line. It is the base structure you must augment.

## Practice Archetypes

The most common trie-flavored tasks are:

- **exact dictionary membership**
- **count words with a prefix**
- **shared-prefix transition filtering**
- **xor maximize / minimize**
- **base structure for Aho-Corasick**

The strongest contest smell is:

- queries are naturally consumed one character or bit at a time
- shared prefixes are the structural win

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary:

- [Archive of Formal Proofs entry citing Fredkin's 1960 trie origin](https://www.isa-afp.org/entries/Trie.html)

Course:

- [Stanford CS166: Tries and Suffix Trees slides](https://web.stanford.edu/class/archive/cs/cs166/cs166.1206/lectures/02/Slides02.pdf)

Reference:

- [USACO Guide: Trie](https://usaco.guide/gold/trie)
- [OI Wiki: Trie](https://en.oi-wiki.org/string/trie/)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Trie ladder](../../../practice/ladders/strings/trie/README.md)
- practice note: [Word Combinations](../../../practice/ladders/strings/trie/wordcombinations.md)
- starter template: [trie-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/trie-basic.cpp)
- notebook refresher: [String cheatsheet](../../../notebook/string-cheatsheet.md)
- xor compare point: [Binary Trie / XOR Queries](../../data-structures/binary-trie-xor/README.md)

## Related Topics

- [Aho-Corasick](../aho-corasick/README.md)
- [KMP](../kmp/README.md)
- [Suffix Automaton](../suffix-automaton/README.md)
- [String Hashing](../hashing/README.md)
