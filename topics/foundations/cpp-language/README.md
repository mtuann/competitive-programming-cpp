# C++ Language For Contests

This page is about getting C++ out of your way. In competitive programming, the language is not the goal, but weak language habits create enough friction to hide good algorithmic ideas.

## Summary

Study this topic if:

- you know the idea but lose time to syntax, container choice, or indexing bugs
- you are unsure when to use `int`, `long long`, `vector`, `pair`, `struct`, `map`, or `set`
- your wrong answers come from implementation mistakes more often than from bad modeling

What success looks like:

- you can write a clean contest skeleton from memory
- you choose containers based on needed operations, not habit
- you can compile, run, debug, and trust small local programs without hesitation
- you can read and modify standard CP templates without fear

## Prerequisites

- basic programming experience in any language

## Start In 5 Minutes

If you only want one default local loop, use these two commands:

Release-style build:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main < input.txt
```

Debug-style build:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
./main_dbg < input.txt
```

The fastest first exercise is one tiny sum program:

```cpp
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum << '\n';
}
```

Use it with:

```text
input.txt
5
1 2 3 4 5
```

and expect output `15`.

If you can write, compile, and run that loop without searching for commands, you already have the first useful local habit.

## One Canonical Local Loop

Until the local workflow becomes automatic, do not keep changing the commands.

Use exactly this release loop:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main < input.txt > output.txt
diff -u expected.txt output.txt
```

and exactly this debug loop:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
./main_dbg < input.txt
```

The main beginner goal is not “know many shell commands.” It is “have one boring loop you trust.”

## Tooling Contract

This repo assumes a very small toolchain contract:

- `c++` or `g++` as the compiler command
- `-std=c++20` as the language level
- one release build for normal runs
- one debug build with sanitizers when behavior feels suspicious

The usual flags mean:

- `-std=c++20`: use the language level assumed across the repo
- `-O2`: optimize roughly like a normal judge build
- `-Wall -Wextra`: surface many common mistakes early
- `-pedantic`: warn when the code drifts toward non-standard behavior
- `-O0 -g`: keep debug builds easy to inspect
- `-Wshadow`: catch accidental variable shadowing
- `-fsanitize=address,undefined`: catch many memory and UB mistakes that otherwise hide as random wrong answers

Rule of thumb:

- use the release build when the program is conceptually stable
- use the debug build when you are still chasing crashes, memory bugs, or suspicious branch behavior

## Release, Debug, And `LOCAL`

In practice, beginners only need three build modes:

- release build: what you trust for normal local runs
- debug / sanitizer build: what you switch to when behavior stops making sense
- optional `LOCAL` build: the same local binary, but with temporary debug-only logging enabled

The repo examples keep the debug route at:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
```

That choice is intentional:

- `-O0 -g` keeps line-by-line stepping simple
- sanitizers catch many memory and UB bugs early
- `-DLOCAL` gives you one switch for `cerr`, assertions, or temporary file hooks that should never leak into the judged build

GCC's official optimize-options documentation also recommends `-Og` as a debug-friendly optimization level. That is a reasonable second step once the local loop already feels stable. This repo keeps `-O0 -g` in the beginner path because it is easier to reason about while learning the tools.

## Core Idea

Contest C++ is mostly about four habits:

1. choose the simplest representation that matches the problem
2. keep variable meanings explicit
3. use standard-library tools you can trust
4. reduce repetition without hiding logic

The right mental model is:

```text
algorithm first
representation second
syntax last
```

When the representation is clean, correctness arguments and debugging both get easier.

## Theory / Proof Sketch

There is no theorem here, but there is a useful invariant:

- each variable should have one stable meaning
- each helper should remove repetition, not hide important decisions
- each container should match the operations you actually need

If that invariant breaks, bugs spread quickly:

- wrong type choice leads to overflow
- wrong container choice leads to awkward or slow code
- unclear helper behavior makes debugging much harder

## Complexity And Tradeoffs

Good C++ habits do not change big-O by themselves, but they matter a lot for:

- constant factors
- memory usage
- bug rate
- speed of implementation under pressure

Useful defaults:

- `vector` is the normal dynamic sequence container
- `array` is good for fixed-size small structures
- `pair` is fine when the meaning is obvious
- `struct` is better when named fields improve clarity
- `map` and `set` keep order
- `unordered_map` and `unordered_set` are hash-based and faster on average, but less predictable
- `priority_queue` is good when you only need the current extremum

Type defaults:

- `int` for indexes and small counts
- `long long` for sums, products, weights, and answers that may exceed about `2e9`
- `__int128` only when one multiplication can already exceed `long long`

## Canonical C++ Pattern

Start from a small contest skeleton and add helpers only when they remove real repetition.

Templates in this repo:

- [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)
- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

Good contest habits:

- keep input parsing close to the data model
- prefer `struct` when field names explain the problem
- pass large objects by `const &` when read-only
- write comparators and helper functions with one clear job
- choose one indexing convention and keep it

Small example:

```cpp
struct Edge {
    int to;
    int weight;
};

long long total_weight(const vector<Edge> &edges) {
    long long sum = 0;
    for (const Edge &e : edges) sum += e.weight;
    return sum;
}
```

This is better than anonymous nested pairs if the fields matter later.

## Tiny Template Walkthrough

The two first templates to actually understand are:

- [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)

When you open them through the [Template Library](../../../template-library.md), scan the short contract first:

- `Signal`
- `Assumes`
- `Exposes`
- `Complexity`
- `Main trap`

What they are teaching is modest but important:

- initialize the stream settings once
- keep `main()` visually empty until real logic arrives
- separate “boilerplate I always want” from “problem logic I still need to think about”

The beginner mistake is not “using too small a template.” The beginner mistake is copying a big template whose invariants you do not actually understand.

One discipline to keep in mind:

- once you call `ios::sync_with_stdio(false);`, do not casually mix C++ streams with `scanf` / `printf`
- keep `cout` reserved for judged output
- keep temporary logs on `cerr`, ideally under `#ifdef LOCAL`

## Build, Run, And Compare

The baseline loop should stay boring:

1. write the smallest correct version you can
2. compile until the warnings make sense, not just until the binary exists
3. run one tiny handmade `input.txt`
4. compare against the expected output before touching bigger tests

Named-binary version:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main < input.txt > output.txt
diff -u expected.txt output.txt
```

If your machine prefers `g++` instead of `c++`, keep the same flags and only swap the compiler command.

When the bug feels like memory misuse, stale state, or one branch silently going wrong, switch to the debug build instead of guessing.

## How To Read The First Real Compiler Error

Do not read compiler output as one giant wall of text.

Read it in this order:

1. find the first line that says `error:`
2. look at the source location attached to that first error
3. read the one or two diagnostic notes immediately under it
4. only after that look at the rest of the output

Useful beginner pattern matches:

- `expected ';'` or `expected '}'`: suspect the line above, not the line below
- `no matching function for call`: the argument types do not match what the function expects
- `invalid operands` or `cannot convert`: suspect a type mismatch, often between container element types, `string` vs number, or signed width
- `comparison of integer expressions of different signedness` or narrowing warnings: stop and think about the type contract before pushing forward

Treat warnings seriously when they mention:

- shadowing
- narrowing
- unused but set variables
- suspicious signed/unsigned conversions

The goal is not to memorize every diagnostic. The goal is to stop letting the first real error drown inside the tenth consequence.

## Your First Problem Folder

For a normal batch problem, keep the first local workspace tiny:

```text
problem/
  main.cpp
  input.txt
  expected.txt
```

Recommended ritual:

1. copy or rewrite the smallest skeleton from [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
2. write only enough code to read the input and print one obviously correct answer
3. save one tiny `input.txt`
4. save one matching `expected.txt`
5. compile, run, and compare before adding any optimization or helper layer

Only reach for [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp) once the problem is still ordinary batch stdin/stdout but the input size is large enough that you want the stream setup extracted cleanly.

## First Syntax Worth Internalizing

Do not try to learn all of modern C++ at once. The highest-ROI early subset is:

- `vector`, `string`, `pair`, and `struct`
- `sort`, `lower_bound`, and simple lambdas
- range-for loops
- `auto` for iterators and long obvious types
- structured bindings for local unpacking
- `const &` for large read-only objects
- `set`, `map`, and `priority_queue`

If those five feel stable, most beginner CP solutions stop feeling like language puzzles.

## Three Input Patterns You Must Recognize

Most beginner contest problems fit one of these three shapes.

### 1. One case

Read once, solve once:

```cpp
int n;
cin >> n;
```

Examples: `Missing Number`, `Weird Algorithm`.

### 2. `t` test cases

Read `t`, then repeat the solve routine:

```cpp
int t;
cin >> t;
while (t--) {
    solve();
}
```

The most common beginner mistake here is forgetting to reinitialize per-test-case state.

### 3. Read until EOF

Keep reading while input succeeds:

```cpp
int x;
while (cin >> x) {
    // process one record
}
```

This appears less often early on, but the pattern is simple enough that it should already feel familiar.

Whenever a statement looks confusing, first ask: which of these three input shapes is this?

## Standard Toolkit

### Types

- prefer `int` until the range is not safe
- cast before multiplying if overflow is possible:

```cpp
long long area2 = 1LL * x1 * y2 - 1LL * y1 * x2;
```

- avoid mixing signed and unsigned types casually

### Containers

Ask which operations matter:

- append and iterate: `vector`
- FIFO: `queue`
- LIFO: `stack`
- min or max retrieval: `priority_queue`
- ordered membership / predecessor / successor: `set`
- key-value dictionary with order: `map`
- frequency table over small integer range: usually `vector<int>` beats any map

### Functions And Helpers

Use helpers for:

- repeated transitions
- geometry primitives
- compare / check predicates
- reusable data structures

Avoid helpers that force the reader to jump around just to understand the main algorithm.

## Debugging Discipline

Do not treat every failure as the same class of bug.

The first useful split is:

- compile error: the program does not build
- runtime error: the program crashes or trips sanitizer checks
- wrong answer: the program runs but violates the intended invariant
- time limit: the algorithm or one implementation choice is too slow

Good local habits:

- shrink to the smallest failing input first
- print variables by meaning, not randomly
- write down the invariant you expect before adding debug output
- if behavior looks impossible, recompile with the debug build and sanitizers

Typical signs:

- crash on a tiny case: suspect indexing, uninitialized state, or out-of-bounds access
- wrong only on bigger numbers: suspect overflow
- output almost correct but shifted: suspect off-by-one or wrong half-open / closed interval convention
- accepted brute force but broken optimized version: suspect the optimization invariant, not syntax

Sanitizers are especially valuable early. They are not a contest submission tool, but they are often the fastest local route from “something weird happened” to the first real clue.

## Minimal Debugging Toolkit

Before reaching for a full debugger, get comfortable with three tools:

- `cerr` for temporary state logging
- `assert(...)` for conditions that should be impossible if your invariant is right
- the debug build with sanitizers for memory and UB mistakes

Minimal pattern:

```cpp
#include <cassert>

#ifdef LOCAL
cerr << "i=" << i << " sum=" << sum << '\n';
#endif
assert(0 <= l && l <= r && r < n);
```

Use them with discipline:

- print to `cerr`, not `cout`, so you do not pollute judged output
- guard noisy local-only prints behind `#ifdef LOCAL` once the amount of logging grows
- assert invariants you genuinely believe should always hold
- keep the first failing input instead of hoping you will rediscover it later

The right escalation order is usually:

1. smallest failing case
2. `cerr` by meaning
3. `assert`
4. debug / sanitizer build
5. debugger

## Short Modern C++ Wins

The goal is not to memorize the whole language. It is to internalize a few short constructs that remove friction.

Structured bindings for pairs or tuples:

```cpp
pair<int, int> seg{l, r};
auto [left, right] = seg;
```

Range-for loops when you only need values:

```cpp
long long sum = 0;
for (int x : values) sum += x;
```

`auto` when the type is obvious from the right-hand side:

```cpp
auto it = lower_bound(a.begin(), a.end(), target);
```

Lambda comparators for local ordering rules:

```cpp
sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
    return a.right < b.right;
});
```

Use these to shorten boilerplate, not to hide meaning. If `auto` or a lambda makes the code harder to read, step back and name the concept more clearly.

## Local Run And Judge Workflow

For ordinary batch problems, the smallest stable loop is:

```bash
./main < input.txt > output.txt
diff -u expected.txt output.txt
```

When there are several saved samples:

```bash
for f in tests/*.in; do
  ./main < "$f" > out.txt || break
  diff -u "${f%.in}.out" out.txt || break
done
```

Escalate only when needed:

- if one saved sample already fails, stay here
- if all saved samples pass but the code still feels risky, move to [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
- if the task is interactive or validator-heavy, move to [Local Judge Workflow](../../../notebook/local-judge-workflow.md)

## GDB / LLDB First Step

Use a debugger only after you already have a tiny reproducible failing case.

For `gdb`, the smallest useful loop is:

```bash
gdb ./main_dbg
```

then:

```text
(gdb) break main
(gdb) run < input.txt
(gdb) next
(gdb) print sum
(gdb) backtrace
```

For `lldb`, the smallest useful loop is:

```bash
lldb ./main_dbg
```

then:

```text
(lldb) breakpoint set --name main
(lldb) run
(lldb) next
(lldb) frame variable sum
(lldb) bt
```

For beginner use, keep the debugger job narrow:

- stop near the first wrong state
- inspect one or two important variables
- confirm where the invariant breaks

If you are still searching for the failing input, the debugger is often too early. Stay with saved samples or stress testing first.

## Tiny Debug Failure Walkthrough

Suppose the intended code is:

```cpp
vector<int> a(n);
for (int i = 0; i < n; ++i) cin >> a[i];
```

but you accidentally write:

```cpp
vector<int> a(n);
for (int i = 0; i <= n; ++i) cin >> a[i];
```

The release build may only “behave strangely.” The debug build is much more useful:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
./main_dbg < input.txt
```

What you should expect from that loop is not a mysterious wrong answer, but a concrete sanitizer complaint pointing at an out-of-bounds access near `a[n]`.

The learning pattern is:

1. freeze the smallest failing input
2. rerun under the debug build
3. trust the first real memory or UB report
4. repair the violated invariant before adding more print statements

For logic bugs that do not trip sanitizers, the next move is usually one `cerr` under `#ifdef LOCAL` or one short debugger session, not blind refactoring.

## Newbie Retrieval Layer

When you are stuck on "how do I even start coding this?", open these in order:

- [Foundations Cheatsheet](../../../notebook/foundations-cheatsheet.md)
- [Local Judge Workflow](../../../notebook/local-judge-workflow.md) when stdin/stdout alone is not enough
- [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md) when samples pass but trust is still low
- [Template Library](../../../template-library.md)
- [Weird Algorithm](../../../practice/ladders/foundations/cpp-language/weirdalgorithm.md)
- [Missing Number](../../../practice/ladders/foundations/cpp-language/missingnumber.md)
- [STL ladder](../../../practice/ladders/foundations/stl/README.md)

That route is usually faster than searching random syntax online mid-problem.

## Worked Examples

### Example 1: compile, run, and trust one tiny sum file

If the first local file reads `n`, sums `n` integers, and prints the answer, the important things you are practicing are:

- reading from `cin` with fast I/O enabled
- choosing `long long` for the accumulator
- compiling with warnings before submission
- running from redirected stdin instead of typing everything manually

That is enough to build a stable first loop before any STL sophistication.

### Example 1.5: first real judged loop with `Weird Algorithm`

The first repo note that exercises this local loop directly is:

- [Weird Algorithm](../../../practice/ladders/foundations/cpp-language/weirdalgorithm.md)

It is valuable because the algorithm is almost trivial, so the main practice is elsewhere:

- read one number cleanly
- keep the loop invariant simple
- print a sequence without corrupting spacing
- use `long long` because values can grow on the Collatz path

If even that note feels noisy, the real blocker is usually the compile / run / inspect loop, not algorithmic difficulty.

### Example 2: `pair` vs `struct`

Use `pair<int, int>` when the meaning is obvious and local:

```cpp
vector<pair<int, int>> intervals;
```

Use a `struct` when fields carry meaning or there are more than two of them:

```cpp
struct Interval {
    int left;
    int right;
    int id;
};
```

### Example 2: passing vectors

Use:

- `const vector<int>& a` when only reading
- `vector<int>& a` when mutating
- plain `vector<int> a` only when you intentionally want a copy

This matters because accidental copies of `O(n)` containers are a common hidden slowdown.

### Example 3: choosing a frequency structure

If values are small and dense:

```cpp
vector<int> freq(max_value + 1);
```

If values are large or arbitrary:

```cpp
unordered_map<int, int> freq;
```

If you also need ordered iteration over keys:

```cpp
map<int, int> freq;
```

The right choice comes from operations, not style.

### Example 4: catching an overflow before submission

Suppose you write:

```cpp
int x1, y1, x2, y2;
cin >> x1 >> y1 >> x2 >> y2;
int area2 = x1 * y2 - y1 * x2;
```

This may overflow even when the final mathematical expression is conceptually simple.

The minimal repair is:

```cpp
long long area2 = 1LL * x1 * y2 - 1LL * y1 * x2;
```

The debugging lesson is larger than this one line:

- if a result is “nonsensical only on larger values”, suspect type width early
- fix the type before printing ten random variables
- if you are unsure, build once with the debug flags and test a boundary-shaped case deliberately

## Recognition Cues

You should revisit this topic when:

- coding time dominates thinking time
- you often patch the same syntax mistakes repeatedly
- your accepted solutions look much messier than editorial ones
- you cannot explain why you chose one container over another

This topic is often confused with “just learn more STL”. That is only part of it. The real goal is implementation fluency and representation discipline.

## Common Mistakes

- mixing `int` and `long long` carelessly in products
- using `unordered_map` when ordered iteration is part of the logic
- overusing macros that hide control flow or types
- copying large containers by value accidentally
- switching between 0-based and 1-based indexing mid-solution
- writing clever one-liners that are hard to debug under contest pressure

## A Good First Week

If you are rebuilding C++ fluency from scratch, a strong first week is:

1. compile and run one tiny file every day with the same flags
2. rewrite one small loop using range-for, `auto`, and a lambda comparator
3. practice the release build and the debug build until both feel ordinary
4. solve one easy note with `vector` + `sort`
5. only after that, touch `set`, `map`, and `priority_queue`

## Practice Ladder

- [Foundations ladder overview](../../../practice/ladders/foundations/README.md)
- [C++ language ladder](../../../practice/ladders/foundations/cpp-language/README.md)
- [STL ladder](../../../practice/ladders/foundations/stl/README.md)

Suggested order:

1. basic I/O and vector manipulation
2. local compile / run / diff workflow
3. pairs, structs, and sorting records
4. maps, sets, queues, and stacks
5. rewriting one messy solution into a clean version

## Go Deeper

Workflow/tool references in this section were reviewed against official docs current through `April 24, 2026`.

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Primary: [GCC warning options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- Primary: [GCC diagnostic message formatting options](https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Message-Formatting-Options.html)
- Primary: [GCC optimize options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
- Primary: [Clang AddressSanitizer documentation](https://clang.llvm.org/docs/AddressSanitizer.html)
- Primary: [Clang diagnostics reference](https://clang.llvm.org/docs/DiagnosticsReference.html)
- Primary: [Clang UndefinedBehaviorSanitizer documentation](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
- Primary: [GDB input/output and redirection](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Input_002fOutput.html)
- Primary: [LLDB tutorial](https://lldb.llvm.org/use/tutorial.html)
- Reference: [CPPReference](https://en.cppreference.com/w/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/)
- Repo anchor: [Template Library](https://github.com/mtuann/competitive-programming-cpp/blob/main/template-library.md)

## Related Topics

- [Reasoning](../reasoning/README.md)
- [Sorting](../patterns/sorting/README.md)
- [Binary Search](../patterns/binary-search/README.md)
- [Prefix Sums](../patterns/prefix-sums/README.md)
