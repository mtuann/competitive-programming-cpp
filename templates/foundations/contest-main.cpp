// Template: contest main
// Use when you want the smallest clean starting point for a single-file solution.
// Signal: ordinary batch problem, one-file solution, no reusable structure needed yet.
// Assumes: standard C++ streams, single-file submission, local loop uses main / main_dbg.
// Exposes: one minimal main() with fast iostream setup already in place.
// Complexity: no algorithmic cost; starter scaffold only.
// Main trap: leaving local-only cerr or file hooks in judged output.
// Links:
//   Topic: topics/foundations/cpp-language/README.md
//   Note: practice/ladders/foundations/cpp-language/weirdalgorithm.md
//   Note: practice/ladders/foundations/cpp-language/missingnumber.md
// Release:
//   c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
// Debug:
//   c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
// Build with -DLOCAL only for temporary local logging or assertions you do not want in the judged build.

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
