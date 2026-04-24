# Markdown Math Style

Use `plain-language-first math` across this repo.

The site now supports rendered math through `MathJax`, but the writing rule is still:

1. explain the idea in words
2. define every symbol before you use it
3. show the symbolic form when it clarifies the argument
4. keep the page understandable even if math rendering fails on GitHub

## When To Use Rendered Math

Rendered math is worth it when notation is part of the idea:

- Fenwick-tree block definitions
- dynamic-programming recurrences
- flow, cut, and matching identities
- combinatorial counting formulas
- geometry predicates and area formulas
- FFT / NTT derivations or convolution identities

If plain text says it just as well, keep it plain.

Good plain-text cases:

- `sum(l..r) = pref[r] - pref[l - 1]`
- `dist[v] <= dist[u] + w`
- `l <= answer < r`

## Preferred Delimiters

To keep source files compatible with both GitHub Markdown rendering and the MkDocs site, use:

- inline math: `$...$`
- display math: `$$...$$` on their own lines

Example:

Inline:

```md
The Fenwick node at index $i$ stores the sum over the block of length $\operatorname{lowbit}(i)$.
```

Display:

```md
$$
\operatorname{bit}[i] = \sum_{j=i-\operatorname{lowbit}(i)+1}^{i} a_j
$$
```

## Writing Pattern

Use this order whenever the formula matters:

1. state the claim in prose
2. define the variables
3. show the formula
4. explain the consequence in prose again

Example:

- `pref[i]` means the sum of the first `i` values.
- Then the interval sum follows from subtracting two prefixes:

```md
$$
\sum_{k=l}^{r} a_k = \operatorname{pref}[r] - \operatorname{pref}[l - 1]
$$
```

- The important takeaway is that one precomputed array answers every static range-sum query in `O(1)`.

## Keep It Readable

- Prefer one notation for one quantity on the whole page.
- Keep display equations short enough to fit mobile screens.
- Split derivations across multiple lines only when the proof genuinely needs it.
- Use prose to explain why the formula matters; do not drop equations without context.

## Avoid

- symbolic walls with no explanation
- switching between several names for the same variable
- using rendered math for filenames, code identifiers, or shell commands
- hiding implementation details behind notation that a reader cannot map back to code

## GitHub And Raw-Source Fallback

GitHub's web Markdown renderer supports math, so `$...$` and `$$...$$` should render there as well.

Still write the surrounding prose so the page remains understandable when someone is:

- reading the raw Markdown source
- browsing in an editor without math rendering
- skimming quickly and not relying on every equation

1. the surrounding prose already explains the meaning
2. the variables are defined nearby
3. the page is still understandable without the rendered form
