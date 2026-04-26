# Dynamic Programming Ladders

These ladders follow the DP path from state design to structured variants.

## Recommended Order

1. foundations
2. knapsack family
3. bitmask DP
4. tree DP
5. digit DP
6. interval DP
7. SOS DP
8. FWHT / xor convolution / subset convolution
9. bit-parallelism / bitset optimization
10. broken profile / plug DP
11. divide and conquer DP
12. Knuth optimization
13. CHT / Li Chao
14. slope trick
15. Lagrangian relaxation / Aliens trick
16. sliding window / mixed optimization notes

## Subtopic Ladders

- [DP foundations](foundations/README.md)
- [Knapsack family](knapsack-family/README.md)
- [Bitmask DP](bitmask-dp/README.md)
- [SOS DP](sos-dp/README.md)
- [FWHT / XOR Convolution / Subset Convolution](fwht-subset-convolution/README.md)
- [Bit-Parallelism / Bitset Optimization](bit-parallelism/README.md)
- [Tree DP](tree-dp/README.md)
- [Digit DP](digit-dp/README.md)
- [Interval DP](interval-dp/README.md)
- [Broken Profile / Plug DP](broken-profile/README.md)
- [Divide and Conquer DP](divide-and-conquer-dp/README.md)
- [Knuth Optimization](knuth-optimization/README.md)
- [CHT / Li Chao](cht-li-chao/README.md)
- [Slope Trick](slope-trick/README.md)
- [Lagrangian Relaxation / Aliens Trick](lagrangian-relaxation/README.md)
- [Sliding window](sliding-window/README.md)

## Representative Solved Note

- [VMSCALE](foundations/vmscale.md): exact budget DP for a non-uniform comparison tree
- [Ciel and Gondolas](divide-and-conquer-dp/cielandgondolas.md): partition DP with monotone split optimization on each row
- [Knuth Division](knuth-optimization/knuthdivision.md): split-point interval DP with additive interval cost and Knuth opt windows
- [Counting Tilings](broken-profile/countingtilings.md): frontier-mask DP on a small-width grid
- [Compatible Numbers](sos-dp/compatiblenumbers.md): complement-mask witness propagation over all submasks of the bitwise complement
- [Bitwise XOR Convolution](fwht-subset-convolution/bitwisexorconvolution.md): exact boolean-cube transform route once pair-combining under xor replaces one-array SOS sweeps
- [School Excursion](bit-parallelism/schoolexcursion.md): DSU component sizes collapsed into one packed boolean reachability row
- [Line Add Get Min](cht-li-chao/lineaddgetmin.md): direct full-domain line-container verifier inside the affine-DP family
- [Monster Game II](cht-li-chao/monstergame2.md): affine-DP optimization via online line insertion and point queries
- [Snuketoon](slope-trick/snuketoon.md): convex piecewise-linear DP updated by one-sided hinge penalties and bounded movement
- [Red and Blue Lamps](lagrangian-relaxation/redandbluelamps.md): exact-`R` non-adjacent picks recovered from a penalized linear DP
- [TFIELD](sliding-window/tfield.md): weighted window reasoning over sorted polygon layers
