# LCA Ladder

LCA practice should make ancestor preprocessing feel worthwhile instead of heavy, because once many path queries appear, preprocessing is the whole point.

## Who This Is For

Use this ladder if:

- repeated tree queries still tempt you into recomputing paths from scratch
- binary lifting is known but not yet comfortable
- distance and ancestor formulas still feel memorized

## Warm-Up

- ancestor checks
- binary lifting table building

Target skill:

- fill depth and jump tables with one clean preprocessing pass

## Core

- LCA queries
- tree distance queries

Target skill:

- derive path formulas naturally from the LCA

## Stretch

- path-query decomposition using LCA
- compare binary lifting with Euler-tour RMQ viewpoint

Target skill:

- see LCA as a reusable preprocessing layer, not just one query type

## Exit Criteria

You are ready to move on when:

- you can equalize depths and lift both nodes confidently
- you can derive the tree-distance formula without looking it up
- you know when binary lifting is enough versus when RMQ-style LCA is worth it

## External Practice

- [CP-Algorithms - LCA](https://cp-algorithms.com/graph/lca_binary_lifting.html)
- [CSES Tree Algorithms](https://cses.fi/problemset/)

## Tutorial Link

- [LCA](../../../../topics/graphs/lca/README.md)
