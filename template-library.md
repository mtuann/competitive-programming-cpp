# Template Library

This page is the overview for the repo's reusable contest-ready code.

The actual implementations live under [`templates/`](https://github.com/mtuann/competitive-programming-cpp/tree/main/templates), while this page explains what should belong there and how it should relate back to the teaching material in `topics/`.

## First-Wave Templates

- DSU
- Fenwick tree
- segment tree
- Dijkstra
- Kruskal / Prim
- flow starter kit
- string hashing
- modular arithmetic helpers

## Standard

Each template should stay compact, contest-usable, and linked back to the teaching page that explains:

- when to use it
- why it works
- the main implementation invariants
- the common failure cases

## Utility Notes

### `__int128` helper

Use `__int128` when a single multiplication may already be near `10^18`, or when many such products are accumulated exactly.

Typical examples:

- shoelace area for geometry
- modular multiplication before taking `%`
- prefix sums of large products

Minimal print helper:

```cpp
static void print_int128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
```

Keep in mind:

- `__int128` is a GCC/Clang extension, not standard C++
- it has no normal `cin` / `cout` overloads
- it is great for exact integer arithmetic, but it still has finite range
