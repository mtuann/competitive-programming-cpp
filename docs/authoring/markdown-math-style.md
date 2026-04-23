# Markdown Math Style

Use `plain-text-first math` across this repo so pages stay readable on both GitHub and the website.

## Rule Of Thumb

- If a formula can be said clearly in plain text, prefer plain text.
- If symbols help, use inline code for short identities.
- If the formula is multi-line, use a fenced `text` block.
- Do not make correctness depend on custom rendering.

## Preferred Patterns

Inline identities:

- `sum(l..r) = pref[r] - pref[l - 1]`
- `dist[v] <= dist[u] + w`
- `l <= answer < r`
- `lowbit(x) = x & -x`

Multi-line recurrences:

```text
dp[i][j] = best answer using the first i items with capacity j
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + value[i])
```

Define variables before the formula:

- `pref[i]`: sum of the first `i` values
- `dist[u]`: current shortest-known distance to node `u`
- `dp[i][j]`: answer for a state indexed by `i` and `j`

## Avoid

- site-only layout syntax for important formulas
- dense LaTeX when a shorter plain-text version is enough
- mixing several notations for the same quantity on one page

## If We Add Rendered Math Later

If the site later enables MathJax or KaTeX, keep using the same writing rule:

1. explain the formula in plain language
2. give the symbolic form
3. keep the page understandable even if the math renderer fails
