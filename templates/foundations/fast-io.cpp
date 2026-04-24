// Template: fast I/O
// Use when input is large but the problem still fits standard C++ streams.
// Signal: large ordinary stdin/stdout input, but no interactive protocol.
// Assumes: iostream-only policy after disabling sync.
// Exposes: init_fast_io() plus a minimal main().
// Complexity: same asymptotic work; stream setup is a constant-factor choice.
// Main trap: mixing iostreams with scanf / printf after disabling sync.
// Links:
//   Topic: topics/foundations/cpp-language/README.md
//   Notebook: notebook/foundations-cheatsheet.md
// After disabling sync, avoid casually mixing iostreams with scanf / printf.

#include <iostream>

using namespace std;

static void init_fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    init_fast_io();

    return 0;
}
