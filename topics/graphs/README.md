# Graphs

Graphs are one of the central contest areas because many problems are really about states and transitions in disguise. This section should teach graph modeling first, then standard algorithms, then deeper tree, cut, and matching ideas.

## Entry

- Prereqs: [Foundations](../foundations/README.md), [Data Structures](../data-structures/README.md)
- Defer for later: flow, matching, and advanced tree decompositions

## Learn In Order

1. Core now
- graph modeling
- BFS / DFS
- topological sort
- MST with DSU
- shortest paths

2. Contest core
- SCC
- trees, LCA, and rerooting-style thinking
- bridge and articulation ideas

3. Advanced later
- flow
- matching
- heavy-light and more specialized tree machinery

## Recognition Cues

- the problem has objects connected by edges, dependencies, or transitions
- you are asked about connectivity, reachability, shortest routes, cuts, or tree structure
- the story sounds unrelated, but the clean model is still vertices plus edges

## Common Pitfalls

- spending too long on the story instead of drawing the graph
- using weighted shortest-path machinery when BFS is enough
- treating all graph topics as flat difficulty instead of learning them in layers

## Exit Criteria

After this section, you should be able to recognize the common graph models, choose the standard algorithm family quickly, and explain why a chosen graph representation is the right one.

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)
