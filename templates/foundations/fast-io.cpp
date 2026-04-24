// Template: fast I/O
// Use when input is large but the problem still fits standard C++ streams.
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
