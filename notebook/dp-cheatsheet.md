# DP Cheatsheet

## State Checklist

- what has been processed?
- what still matters?
- does the state forget any information needed later?

## Transition Checklist

- are all legal next moves covered?
- are any cases counted twice?
- what iteration order respects dependencies?

## Common Forms

```text
dp[i] = best answer on the first i elements
dp[i][j] = answer on prefix i with extra parameter j
```

## Safety Checks

- base case
- final answer location
- overflow type
- reconstruction needs parent or choice arrays
