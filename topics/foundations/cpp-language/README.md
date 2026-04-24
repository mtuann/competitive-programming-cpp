# C++ Language For Contests

This page is not "learn all of C++."

It is:

- learn the small subset that keeps contest code fast to write
- stable to debug
- and easy to trust under time pressure

In competitive programming, the language is rarely the real bottleneck by itself.

The bottleneck is usually one of these:

- the compile / run / debug loop is not automatic yet
- types and containers are chosen by habit instead of by required operations
- helper code hides logic instead of clarifying it
- local tooling is weak enough that trivial bugs survive until submission

So the real goal of this page is not syntax accumulation.

It is implementation fluency.

Freshness note: official compiler, sanitizer, debugger, and `cppreference` links on this page were last reviewed on `2026-04-24`.

## At A Glance

- **Use when:** the algorithm is mostly known, but coding still feels slower or less reliable than the actual thinking.
- **Core worldview:** contest C++ is a small trusted subset plus one boring local workflow you can repeat without hesitation.
- **Main tools:** `vector`, `string`, `pair`, `struct`, `sort`, `lower_bound`, `set`, `map`, `priority_queue`, one release build, one debug/sanitizer build.
- **Strongest trap:** using more language or tooling than you can currently trust.
- **Success after studying this page:** you can compile and run from memory, choose a container by required operations, pick a safe numeric type, and debug small failures systematically instead of randomly.

## Quick Route

Use this page as a router for implementation friction.

```text
1. I know the idea but coding still feels noisy.
   Learn the trusted language subset and one contest skeleton.

2. I keep choosing the wrong container or type.
   Use the operation-first chooser below.

3. The code compiles, but I do not trust it.
   Switch from release loop to debug / sanitizer loop.

4. stdin/stdout handling is still shaky.
   Start with the first local loop and Weird Algorithm.

5. The problem is interactive or validator-heavy.
   Leave this page and open Local Judge Workflow.
```

## Prerequisites

- basic programming experience in any language

Helpful neighboring layers:

- [Reasoning, Invariants, And Proof Discipline](../reasoning/README.md)
- [Foundations Cheatsheet](../../../notebook/foundations-cheatsheet.md)
- [Build Kit](../../../docs/build-kit.md)
- [Template Library](../../../template-library.md)

## Problem Model And Notation

This page uses one implementation contract.

For any solution, write down four things early:

1. **data model**
   - what objects exist in the solution?
   - array, graph, interval, record, frequency table?
2. **operation contract**
   - what operations must be fast?
   - append, lookup, predecessor, min extraction, sorting?
3. **type contract**
   - what numeric range is safe?
   - `int`, `long long`, or rarely `__int128`?
4. **tooling mode**
   - release run, debug/sanitizer run, or local-judge workflow?

That is the language analogue of an algorithm invariant:

> your code structure, types, and tools should match the operations the problem actually needs.

This page will use:

- **release build** for ordinary local runs
- **debug build** for sanitizer-assisted or debugger-assisted diagnosis
- **LOCAL mode** for local-only `cerr` logs or assertions guarded behind `#ifdef LOCAL`

## From "I Know C++ A Bit" To The Right Contest Subset

### The Naive Path

The unstable beginner path is:

- search syntax on demand
- accumulate many STL names
- copy a big template
- improvise build flags
- debug only after submission pain

That path creates too much moving surface area.

### The Better Compression

The better path is:

1. choose one boring compile / run loop
2. learn one small language subset really well
3. choose containers by operations, not by aesthetics
4. choose numeric types by range, not hope
5. escalate debugging cleanly instead of guessing

That is enough for a surprisingly large fraction of accepted contest code.

### The Trusted Subset

A very high-ROI subset is:

- `vector`, `string`, `pair`, `struct`
- range-for loops
- `auto` where the type is obvious from the right-hand side
- lambdas for small local comparators or predicates
- `sort`, `lower_bound`, `upper_bound`
- `set`, `map`, `priority_queue`
- `const &` for large read-only objects

Most beginner-to-intermediate contest programs do not need more language surface than that.

## Core Invariant And Why It Works

This page is really about six implementation invariants.

### 1. Every Variable Should Have One Stable Meaning

This is the first bridge to [Reasoning](../reasoning/README.md).

Good examples:

- `sum` is the current prefix sum
- `dist[v]` is the current best known distance
- `freq[x]` is the current count of value `x`

Bad examples:

- `tmp`, `cur2`, `ans2` without a stable meaning
- one variable reused for two unrelated roles because it "seems convenient"

The more overloaded the variable meanings are, the harder the code becomes to debug.

### 2. Container Choice Should Follow Operations

The first question is not:

- "which STL container do I remember?"

It is:

- "which operations need to be efficient and simple?"

Examples:

- append and iterate -> `vector`
- ordered membership / predecessor / successor -> `set`
- key -> value with sorted keys -> `map`
- average-case hash lookup with no ordered iteration requirement -> `unordered_map`
- current min or max only -> `priority_queue`
- small dense frequency domain -> `vector<int>` often beats any map

That is why the right invariant is:

> the chosen container should make the needed operations natural, not merely possible.

### 3. Type Width Is Part Of Correctness

Many C++ bugs are not syntax bugs.

They are type-contract bugs.

Good rules of thumb:

- `int` for indices and small counters
- `long long` for sums, products, weights, and most answers
- cast before multiplying if overflow is plausible
- use `__int128` only when one multiplication can already exceed `long long`

Example:

```cpp
long long area2 = 1LL * x1 * y2 - 1LL * y1 * x2;
```

This is not "extra caution." It is the type contract matching the arithmetic.

### 4. One Trusted Local Loop Beats Five Fancy Ones

Until local workflow is boring, keep exactly one default release loop:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main < input.txt > output.txt
diff -u expected.txt output.txt
```

and one debug loop:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
./main_dbg < input.txt
```

Why this works:

- release loop approximates ordinary judge behavior
- debug loop catches many memory and UB mistakes locally
- `-DLOCAL` gives one clean switch for logs and assertions

The invariant here is:

> do not keep changing the workflow while still learning the workflow.

### 5. Helpers Should Remove Repetition, Not Hide Logic

Good helper functions:

- parse or build one clear object
- compute one primitive
- encapsulate one reusable data structure operation

Bad helpers:

- hide the main recurrence or sweep logic
- force the reader to jump around just to understand one local step

This is why a small `struct` often beats anonymous `pair<pair<int,int>,int>`-style code.

Example:

```cpp
struct Interval {
    int left;
    int right;
    int id;
};
```

The fields document the data model directly.

### 6. Tooling Escalation Should Be Predictable

Do not treat all failures the same.

Use this escalation:

1. compile error -> read the first real compiler error
2. wrong answer on saved sample -> shrink the case and inspect the invariant
3. crash / impossible state / weird memory behavior -> rerun under sanitizers
4. samples pass but trust is low -> use [Stress Testing Workflow](../../../notebook/stress-testing-workflow.md)
5. judge/protocol quirks -> use [Local Judge Workflow](../../../notebook/local-judge-workflow.md)

That predictable escalation is more valuable than memorizing debugger commands too early.

## Complexity And Tradeoffs

Good C++ habits do not change asymptotic complexity by themselves, but they strongly affect:

- constant factors
- memory usage
- bug rate
- implementation speed under contest pressure

Important tradeoffs:

| Choice | Benefit | Main risk |
| --- | --- | --- |
| `vector` over tree/hash containers | tiny constants, simple iteration | wrong if you truly need ordered queries |
| `struct` over nested `pair` | readable fields, easier debugging | slightly more typing |
| `map` / `set` | ordered behavior is explicit | slower than dense arrays or direct sorting when order is unnecessary |
| `unordered_map` / `unordered_set` | faster average lookup | iteration order is unusable for logic, behavior less predictable |
| release build | realistic local performance | weaker at exposing UB or memory bugs |
| debug/sanitizer build | catches many local mistakes | slower, higher memory overhead |
| compact clever code | faster to type sometimes | much harder to trust under pressure |

The best contest code is usually not the shortest code.

It is the shortest code whose invariants remain obvious.

## Variant Chooser

### Build-Mode Chooser

| Situation | Use first | Why |
| --- | --- | --- |
| ordinary batch task, sample already clear | release build | closest to normal contest loop |
| crash, impossible branch, suspicious memory behavior | debug/sanitizer build | strongest local clue for UB and bounds bugs |
| noisy local tracing needed | debug build with `-DLOCAL` | keeps logs out of judged output |
| interactive / validator-heavy task | local judge workflow | stdin/stdout diff loop is no longer enough |

### Type Chooser

| Need | Default type | Main caveat |
| --- | --- | --- |
| indices, small counts | `int` | do not multiply blindly |
| sums, weights, answers | `long long` | cast before mixed-width products |
| exact very large intermediate product | `__int128` | keep usage local and deliberate |

### Representation Chooser

| Signal | Default choice | Avoid when |
| --- | --- | --- |
| sequence with append + scan | `vector` | you need order statistics / predecessor queries |
| tiny record with named fields | `struct` | never; this is usually the clearer choice |
| obviously local 2-tuple | `pair` | field meaning matters later |
| ordered keys matter | `map` / `set` | order is irrelevant |
| min/max only | `priority_queue` | you also need arbitrary erase or predecessor |
| small dense counts | `vector<int>` freq table | key range is huge or sparse |

### Input-Pattern Chooser

| Pattern | Canonical form |
| --- | --- |
| one case | read once, solve once |
| `t` cases | `while (t--) solve();` |
| until EOF | `while (cin >> x) { ... }` |

Choosing the input pattern early reduces a surprising amount of implementation noise.

## Worked Examples

### Example 1: The First Trusted Local Loop

Start with one tiny sum file:

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

Why is this a good first exercise?

- it forces one input pattern
- it uses `long long` for the first meaningful overflow-sensitive accumulator
- it establishes the local compile / run loop without extra algorithm noise

If this loop is not comfortable yet, the blocker is implementation workflow, not advanced STL.

### Example 2: `pair` Versus `struct`

Suppose a problem stores intervals.

This is acceptable when the meaning is very local:

```cpp
vector<pair<int, int>> intervals;
```

But once fields matter later, a `struct` is better:

```cpp
struct Interval {
    int left;
    int right;
    int id;
};
```

Why?

- sort keys become clearer
- debug prints become more meaningful
- later extensions do not require mentally decoding `.first` and `.second`

This is exactly the kind of local clarity that reduces contest mistakes.

### Example 3: Choosing A Frequency Structure

Suppose you need frequencies.

If values are small and dense:

```cpp
vector<int> freq(max_value + 1);
```

If values are large or arbitrary:

```cpp
unordered_map<int, int> freq;
```

If ordered iteration over keys matters:

```cpp
map<int, int> freq;
```

The important lesson is not the syntax.

It is that the container comes from the operations contract.

### Example 4: Overflow Before Submission

Suppose you write:

```cpp
int x1, y1, x2, y2;
cin >> x1 >> y1 >> x2 >> y2;
int area2 = x1 * y2 - y1 * x2;
```

That may overflow even though the math expression looks simple.

The repair is:

```cpp
long long area2 = 1LL * x1 * y2 - 1LL * y1 * x2;
```

The larger debugging lesson is:

- when results become nonsense only on larger values, suspect type width early
- fix the type contract before printing random state everywhere

### Example 5: First Real Judged Loop

The first repo note that should feel mechanically easy after this page is:

- [Weird Algorithm](../../../practice/ladders/foundations/cpp-language/weirdalgorithm.md)

Its value is that the algorithm is almost trivial, so the actual practice is:

- read one number cleanly
- choose `long long`
- print a sequence without spacing bugs
- trust the local compile / run loop

That is exactly the right first checkpoint for this topic.

## Algorithm And Pseudocode

For this page, the reusable "algorithm" is an implementation checklist.

```text
ContestImplementationContract(problem):
    classify the input pattern
    define the data model
    list the operations that must be efficient
    choose:
        container by operations
        type by range
        build mode by risk
    write the smallest contest skeleton
    run one tiny saved case
    if behavior is suspicious:
        escalate to debug/sanitizer build
        then stress or local-judge workflow if needed
```

For normal batch tasks, the executable loop is:

```text
write smallest correct version
compile with warnings
run tiny saved case
compare with expected output
only then add optimization or helpers
```

## Implementation Notes

- After `ios::sync_with_stdio(false);`, do not casually mix C++ streams with `scanf` / `printf`.
- Use `cout` for judged output and `cerr` for local debug information.
- Guard noisy logs behind `#ifdef LOCAL`.
- Read compiler output in this order:
  1. first `error:` line
  2. source location
  3. one or two notes immediately under it
- Warnings worth taking seriously early:
  - shadowing
  - narrowing
  - suspicious signed/unsigned conversions
  - unused-but-set values
- Use `const vector<int>& a` for large read-only containers and `vector<int>& a` when intentional mutation is part of the contract.
- Avoid macros that hide control flow or types in beginner/intermediate contest code.
- If you need a debugger, start only after you already have a reproducible failing case.

## Practice Archetypes

- **Warm-up**
  - [Weird Algorithm](../../../practice/ladders/foundations/cpp-language/weirdalgorithm.md)
    Why: pure compile/run/type/printing fluency with almost no algorithmic load.
  - [Missing Number](../../../practice/ladders/foundations/cpp-language/missingnumber.md)
    Why: small clean loop, simple accumulation, early type-discipline practice.
- **Core**
  - [Distinct Numbers](../../../practice/ladders/foundations/stl/distinctnumbers.md)
    Why: first real container-choice and `sort + unique` judgment.
  - [Movie Festival](../../../practice/ladders/foundations/sorting/moviefestival.md)
    Why: records, comparators, and readable `struct`-driven implementation.
- **Stretch**
  - [Factory Machines](../../../practice/ladders/foundations/binary-search/factorymachines.md)
    Why: combines implementation discipline with type width and check-function hygiene.
  - [Apartments](../../../practice/ladders/foundations/two-pointers/apartments.md)
    Why: good test of whether the language has stopped being the bottleneck for invariant-driven code.

## References And Repo Anchors

Tooling references in this section were reviewed against official docs current through **April 24, 2026**.

- **Primary**
  - [GCC Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
  - [GCC Optimize Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
  - [Clang AddressSanitizer documentation](https://clang.llvm.org/docs/AddressSanitizer.html)
  - [Clang UndefinedBehaviorSanitizer documentation](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
  - [GDB: program input/output redirection](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Input_002fOutput.html)
  - [LLDB tutorial](https://lldb.llvm.org/use/tutorial.html)
- **Reference**
  - [cppreference: `std::ios_base::sync_with_stdio`](https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio)
  - [cppreference](https://en.cppreference.com/w/)
- **Practice**
  - [CSES Problem Set](https://cses.fi/problemset/)
  - [USACO Guide](https://usaco.guide/)
- **Repo anchors**
  - [Foundations Cheatsheet](../../../notebook/foundations-cheatsheet.md)
  - [Build Kit](../../../docs/build-kit.md)
  - [Template Library](../../../template-library.md)
  - [Local Judge Workflow](../../../notebook/local-judge-workflow.md)
  - [C++ Language Ladder](../../../practice/ladders/foundations/cpp-language/README.md)
  - [STL Ladder](../../../practice/ladders/foundations/stl/README.md)
  - [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
  - [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)
  - [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

## Related Topics

- [Reasoning, Invariants, And Proof Discipline](../reasoning/README.md)
- [Sorting](../patterns/sorting/README.md)
- [Binary Search](../patterns/binary-search/README.md)
- [Prefix Sums](../patterns/prefix-sums/README.md)
- [Build Kit](../../../docs/build-kit.md)
