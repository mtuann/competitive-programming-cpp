# Difference Arrays

Difference arrays are the offline sibling of prefix sums. They are the right tool when you need many range additions, but only care about the final array after all updates are applied.

## Summary

Suspect difference arrays when:

- there are many range updates
- you do not need to answer queries between updates
- the output only depends on the final values or one final scan

What success looks like:

- you can convert each range update into two endpoint changes
- you can rebuild the final array with one prefix pass
- you know when this is enough and when you need Fenwick or segment tree instead

## Prerequisites

- [Prefix Sums](../prefix-sums/README.md)

## Core Idea

Instead of adding `x` to every position in `[l, r]`, store only where the effect starts and where it stops:

```text
diff[l] += x
diff[r + 1] -= x
```

After all updates, rebuild the array by taking prefix sums of `diff`.

That works because the contribution of one update is “active” exactly between its start and end.

## Theory / Proof Sketch

Think of `diff[i]` as the change that happens when moving from position `i - 1` to position `i`.

For one update adding `x` on `[l, r]`:

- the value should increase by `x` when you enter `l`
- the value should decrease by `x` after you leave `r`

So the endpoint encoding is:

```text
diff[l] += x
diff[r + 1] -= x
```

Now when you take the prefix sum of `diff`, every update contributes exactly on the positions where it is active.

## Complexity And Tradeoffs

If there are `q` updates on an array of length `n`:

- each range update: `O(1)`
- rebuild final values: `O(n)`
- total: `O(n + q)`

Tradeoffs:

- perfect for offline range additions
- useless if you need online answers after each update
- best when the final reconstruction is enough

## Canonical C++ Pattern

Template in this repo:

- [difference-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/difference-array.cpp)

Typical pattern:

```cpp
vector<long long> diff(n + 2, 0);
for (each update [l, r] += x) {
    diff[l] += x;
    if (r + 1 <= n) diff[r + 1] -= x;
}
for (int i = 1; i <= n; ++i) {
    diff[i] += diff[i - 1];
}
```

After the prefix pass, `diff[i]` becomes the final value at position `i` if the initial array was all zero. If there was an initial array, add the rebuilt effect to it.

## Decision Check

Ask one question before choosing this tool:

```text
Do I need answers while the updates are still happening?
```

If the answer is yes, difference arrays alone are not enough. Move to Fenwick tree or segment tree. If the answer is no, this offline approach is often the cleanest option.

## Standard Patterns

### 1. Offline Range Addition

The classic use:

- many `add x on [l, r]`
- one final output

### 2. Event Sweep On A Line

You can treat interval starts and ends as signed changes and then scan the line once.

Examples:

- how many intervals cover each point
- how many active events exist at each coordinate

### 3. Difference Then Prefix Then Check

Sometimes the final array is not the direct output. You rebuild it first, then:

- take a max
- count positions meeting a threshold
- run another scan or greedy step

## Worked Examples

### Example 1: many interval increments

Problem:

```text
apply q updates: add x to every a[i] in [l, r]
print the final array
```

Difference-array solution:

- record the start and stop of each update in `O(1)`
- rebuild once in `O(n)`

### Example 2: active intervals by coordinate

If an interval `[l, r]` contributes `+1` while active:

```text
diff[l] += 1
diff[r + 1] -= 1
```

Prefix sum gives the number of active intervals at every position.

### Example 3: initial array plus updates

If the initial array is not zero, the clean mental model is:

```text
final[i] = initial[i] + accumulated_update_effect[i]
```

Keep those two layers conceptually separate.

## Recognition Cues

Strong clues:

- “apply many range increments”
- “after all operations, print / count / maximize”
- no intermediate query needs the updated state
- brute force per update would be `O(nq)`

Difference arrays are often confused with:

- [Prefix Sums](../prefix-sums/README.md), because reconstruction is a prefix sum
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md), because both touch prefix logic
- [Segment Tree](../../../data-structures/segment-tree/README.md), because all three can appear in range-update problems

The deciding question is:

```text
Do I need answers during the update process, or only after all updates finish?
```

## Common Mistakes

- forgetting the `r + 1` boundary check
- rebuilding from the wrong base array
- mixing zero-based and one-based indexing
- using difference arrays when online queries are required
- forgetting that subtraction at `r + 1` ends the update after `r`, not at `r`

## Practice Ladder

- [Difference arrays ladder](../../../../practice/ladders/foundations/difference-arrays/README.md)
- [Prefix sums ladder](../../../../practice/ladders/foundations/prefix-sums/README.md)

Suggested order:

1. zero-initialized range additions
2. initial array plus updates
3. event-count reconstruction
4. compare offline difference arrays against online Fenwick

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
- Next step: [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)

## Related Topics

- [Prefix Sums](../prefix-sums/README.md)
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)
- [Segment Tree](../../../data-structures/segment-tree/README.md)
