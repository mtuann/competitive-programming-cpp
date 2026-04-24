# Foundations Cheatsheet

Use this page as the short-reference layer for the beginner stack: compile/run, a few modern C++ shortcuts, and the first correctness checks worth doing before submission.

## Local Compile And Run

Default release loop:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main < input.txt
```

Debug / sanitizer loop:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
./main_dbg < input.txt
```

What the flags are doing:

- `-std=c++20`: use the language level assumed by this repo
- `-O2`: optimize roughly like a normal judge build
- `-Wall -Wextra`: surface common mistakes early
- `-pedantic`: warn when code drifts toward non-standard behavior
- `-O0 -g`: keep debug builds easier to inspect
- `-Wshadow`: catch accidental name shadowing
- `-fsanitize=address,undefined`: catch many memory and UB mistakes locally

Optional note:

- `-DLOCAL` lets you guard temporary `cerr` logs or local-only hooks behind `#ifdef LOCAL`
- GCC's docs also describe `-Og -g` as a debug-friendly choice; keep the repo default on `-O0 -g` until stepping through code already feels ordinary

Same commands with `g++`:

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
g++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
```

## One Canonical Local Loop

Release loop:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main < input.txt > output.txt
diff -u expected.txt output.txt
```

Debug loop:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
./main_dbg < input.txt
```

Keep these two loops fixed until they feel automatic.

## Compare Against Expected Output

Single saved sample:

```bash
./main < input.txt > output.txt
diff -u expected.txt output.txt
```

Several saved samples:

```bash
for f in tests/*.in; do
  ./main < "$f" > out.txt || break
  diff -u "${f%.in}.out" out.txt || break
done
```

This is the default loop before stress testing.

## How To Read The First Real Compiler Error

Use this scan order:

1. first `error:` line
2. attached file and line number
3. one or two notes directly under it
4. only then the rest

Typical meanings:

- `expected ';'` or `expected '}'`: inspect the nearby lines above first
- `no matching function for call`: the argument types do not fit
- `invalid operands` / `cannot convert`: type mismatch
- signedness / narrowing warning: your type contract is probably weak

## One Optional `LOCAL` Pattern

Use `cout` for judged output and `cerr` for temporary local clues.

Minimal pattern:

```cpp
#ifdef LOCAL
cerr << "mid=" << mid << " ok=" << ok(mid) << '\n';
#endif
```

This keeps noisy logs out of the release build without inventing a heavy debug framework.

## First Templates To Know

- [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)
- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)
- [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp)
- [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp)

You do not need to memorize every template. Learn a very small set until they feel predictable, and browse them through the [Template Library](../template-library.md).

The foundations pilot templates there now expose the short contract you should scan first:

- `Signal`
- `Assumes`
- `Exposes`
- `Complexity`
- `Main trap`

## Modern C++ Short Wins

Structured bindings:

```cpp
pair<int, int> seg{l, r};
auto [left, right] = seg;
```

Range-for loops:

```cpp
long long sum = 0;
for (int x : values) sum += x;
```

Local lambda comparator:

```cpp
sort(a.begin(), a.end(), [](const Item &x, const Item &y) {
    return x.key < y.key;
});
```

`auto` for iterators or obvious long types:

```cpp
auto it = lower_bound(a.begin(), a.end(), target);
```

`emplace_back` when constructing in place:

```cpp
edges.emplace_back(u, v);
```

## Type Discipline

- use `int` for indices and small counters
- use `long long` for sums, products, weights, and most answers
- cast before multiplying when overflow is possible:

```cpp
long long area2 = 1LL * x1 * y2 - 1LL * y1 * x2;
```

- use `const vector<int>& a` when reading a large container
- use `vector<int>& a` when mutating it intentionally

## Debug By Symptom

- compile error:
  read the first real error, not the last one
- runtime error or weird crash:
  rerun with the debug / sanitizer build
- wrong answer only on larger values:
  suspect overflow first
- almost-correct output:
  suspect indexing or interval convention
- accepted brute force but broken optimized code:
  inspect the invariant, not the syntax

## `cerr` And `assert`

Use:

```cpp
#include <cassert>

cerr << "i=" << i << " sum=" << sum << '\n';
assert(0 <= l && l <= r && r < n);
```

Rules:

- debug prints go to `cerr`, not `cout`
- once the prints get noisy, guard them behind `#ifdef LOCAL`
- assert the invariant you expect, not a random expression
- keep the first failing input after an assertion trips

## Debugger First Step

`gdb`:

```bash
gdb ./main_dbg
```

```text
(gdb) break main
(gdb) run < input.txt
(gdb) next
(gdb) print answer
(gdb) backtrace
```

`lldb`:

```bash
lldb ./main_dbg
```

```text
(lldb) breakpoint set --name main
(lldb) run
(lldb) next
(lldb) frame variable answer
(lldb) bt
```

Use the debugger only after you already have a reproducible failing case.

## First Syntax Worth Remembering

- range-for loops
- `auto` for iterators and obvious long types
- `sort`, `lower_bound`
- structured bindings
- lambda comparator
- `set`, `map`, `priority_queue`

Tiny patterns:

```cpp
auto it = lower_bound(a.begin(), a.end(), target);
auto [u, v] = edge;
sort(items.begin(), items.end(), [](const Item &x, const Item &y) {
    return x.key < y.key;
});
```

## Three Input Patterns You Must Recognize

One case:

```cpp
int n;
cin >> n;
```

`t` test cases:

```cpp
int t;
cin >> t;
while (t--) solve();
```

Read until EOF:

```cpp
int x;
while (cin >> x) {
    // process
}
```

If a statement feels confusing, classify the input shape before touching the algorithm.

## First Correctness Checklist

- What does each important variable mean right now?
- What is the indexing convention: `0..n-1`, `1..n`, or half-open `[l, r)`?
- Is the answer type large enough?
- If using prefix sums, did you define `pref[0] = 0`?
- If using binary search, do `l` and `r` have fixed meanings?
- If using two pointers, is the condition monotone enough?
- If using difference arrays, did you handle `r + 1` safely?

## Tiny Test Routine

Before submission, try:

1. smallest legal input
2. all equal values
3. strictly increasing or decreasing values
4. one edge case that attacks your invariant directly

If all saved samples pass but confidence is still low:

- use [Stress testing workflow](stress-testing-workflow.md)
- use [Local judge workflow](local-judge-workflow.md) for interactive or validator-heavy tasks

## Good Next Reads

- [Foundations overview](../topics/foundations/README.md)
- [C++ Language For Contests](../topics/foundations/cpp-language/README.md)
- [Reasoning And Implementation Discipline](../topics/foundations/reasoning/README.md)
- [Foundations ladders](../practice/ladders/foundations/README.md)
- first practice anchor -> [Weird Algorithm](../practice/ladders/foundations/cpp-language/weirdalgorithm.md)
