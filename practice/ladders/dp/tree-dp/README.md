# Tree DP Ladder

This ladder is about turning rooted-tree structure into DP states without overcomplicating the local state.

## Who This Is For

Use this ladder if:

- subtree aggregation feels okay, but richer tree DP still feels fragile
- you are unsure when child contributions are independent
- rerooting and basic subtree DP still blur together

## Warm-Up

- subtree sums and subtree counts
- simple take / skip states

Target skill:

- define one clean subtree state

## Core

- merge child answers
- root the tree cleanly
- rerooting later if needed

Target skill:

- reason in terms of subtree boundaries and child merges

## Example Notes

- [VOSTRIP](../../graphs/tree-dp/vostrip.md)

## Stretch

- compare plain subtree DP against rerooting needs
- simplify an overdesigned local state

Target skill:

- keep the state minimal while preserving all necessary child information

## Exit Criteria

You are ready to move on when:

- you can write the DFS merge order from memory
- you know whether your answer is subtree-local or whole-tree
- you can explain why the child subproblems are independent once the parent boundary is fixed

## External Practice

- [USACO Guide - Tree DP](https://usaco.guide/gold/dp-trees)
- [OI Wiki - Tree DP](https://en.oi-wiki.org/dp/tree/)

## Tutorial Link

- [Tree DP](../../../../topics/dp/tree-dp/README.md)
