# Start Here

If you are not sure where to begin, use this page instead of browsing the repo randomly.

The goal is simple:

- pick one clear route
- ignore the advanced doors for now
- finish a small first week that already feels like real progress

## Who This Page Is For

Use this page if any of these sound like you:

- you are new to competitive programming
- you know some syntax, but do not yet have a stable practice loop
- the repo looks rich, but you are not sure which page is the real first page

## What To Ignore For Now

Do not start with these unless you already know why you need them:

- `Topic Maps`
- `External Problem Index`
- `Mixed Rounds`
- `Advanced`
- `Contest Playbooks`

They are useful later, but they are not the best first door for a beginner.

## Best First Route

If you want one default route, use this:

1. [Foundations overview](../topics/foundations/README.md)
2. [Foundations ladders](../practice/ladders/foundations/README.md)
3. [Foundations cheatsheet](../notebook/foundations-cheatsheet.md)

That route works because it gives you:

- one teaching layer
- one practice layer
- one quick-reference layer

## First 3 Pages

Open these in order:

1. [C++ Language For Contests](../topics/foundations/cpp-language/README.md)
2. [Reasoning And Implementation Discipline](../topics/foundations/reasoning/README.md)
3. [Prefix Sums](../topics/foundations/patterns/prefix-sums/README.md)

Those three are enough to build a real local loop:

- write code comfortably
- debug by meaning and invariant
- solve at least one standard static-query problem cleanly

If Day 1 still feels shaky, keep these open beside the first page:

- [Foundations cheatsheet](../notebook/foundations-cheatsheet.md)
- [Local judge workflow](../notebook/local-judge-workflow.md)
- [Stress testing workflow](../notebook/stress-testing-workflow.md)

## First 3 Repo Notes

Solve these in order:

1. [Weird Algorithm](../practice/ladders/foundations/cpp-language/weirdalgorithm.md)
2. [Missing Number](../practice/ladders/foundations/cpp-language/missingnumber.md)
3. [Increasing Array](../practice/ladders/foundations/complexity-and-invariants/increasingarray.md)

Optional next two if you still feel good:

4. [Static Range Sum Queries](../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)
5. [Ferris Wheel](../practice/ladders/foundations/sorting/ferriswheel.md)

## Your First Week

If you want a concrete seven-day rhythm:

1. Day 1: read [C++ Language](../topics/foundations/cpp-language/README.md), open [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp), compile it once with the release build, rerun it once with the debug build, optionally glance at [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp), then solve [Weird Algorithm](../practice/ladders/foundations/cpp-language/weirdalgorithm.md)
2. Day 2: solve [Missing Number](../practice/ladders/foundations/cpp-language/missingnumber.md) and [Distinct Numbers](../practice/ladders/foundations/stl/distinctnumbers.md)
3. Day 3: read [Reasoning](../topics/foundations/reasoning/README.md) and solve [Increasing Array](../practice/ladders/foundations/complexity-and-invariants/increasingarray.md)
4. Day 4: read [Sorting](../topics/foundations/patterns/sorting/README.md) and solve [Ferris Wheel](../practice/ladders/foundations/sorting/ferriswheel.md)
5. Day 5: read [Binary Search](../topics/foundations/patterns/binary-search/README.md) and solve [Factory Machines](../practice/ladders/foundations/binary-search/factorymachines.md)
6. Day 6: read [Prefix Sums](../topics/foundations/patterns/prefix-sums/README.md) and solve [Static Range Sum Queries](../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)
7. Day 7: read [Two Pointers](../topics/foundations/patterns/two-pointers/README.md) and solve [Apartments](../practice/ladders/foundations/two-pointers/apartments.md)

## What “Good Progress” Looks Like

By the end of that route, you do **not** need to know graphs, DP, or suffix structures yet.

You only need to be able to:

- compile and run C++ comfortably
- explain what your main variables mean
- recognize sorting, prefix sums, and simple two-pointer scans
- solve a few clean CSES-style tasks without guessing

That is already a strong start.

## Which Workflow To Use Right Now

Use the smallest workflow that matches the task:

- ordinary batch problem with saved sample:
  stay with the compile/run/diff loop from [Foundations cheatsheet](../notebook/foundations-cheatsheet.md)
- samples pass, but the optimized solution still feels untrustworthy:
  move to [Stress testing workflow](../notebook/stress-testing-workflow.md)
- interactive task, validator-heavy task, or many-valid-answers task:
  move to [Local judge workflow](../notebook/local-judge-workflow.md)

Do not escalate too early. Most beginner problems should stay in the first bucket.

## After This Page

- If you want the main curriculum, go to [Topics](../topics/README.md)
- If you want the practice-first route, go to [Practice](../practice/README.md)
- If you already know what topic you need, go to [Problem Finder](problem-finder.md)
