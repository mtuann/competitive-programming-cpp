// Template: Deutsch-Jozsa promise-problem simulator.
// Signal: one Boolean oracle f on {0,1}^n, promised constant or balanced, and
// the point is to preserve the first quantum-algorithm invariant in a
// classical simulator.
// Assumes: the full truth table is explicit and the promise holds.
// Exposes: deutsch_jozsa_zero_amplitude_numerator() and
// classify_deutsch_jozsa().
// Complexity: O(2^n).
// Main trap: forgetting this is a promise-problem simulator and then
// overclaiming practical speedup from explicit truth-table input.
// Links:
//   Topic: topics/advanced/quantum-algorithms/README.md
//   Note: practice/ladders/advanced/quantum-algorithms/deutschjozsa.md

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long deutsch_jozsa_zero_amplitude_numerator(const vector<int>& oracle_values) {
    long long sum = 0;
    for (int bit : oracle_values) {
        assert(bit == 0 || bit == 1);
        sum += (bit == 0 ? 1LL : -1LL);
    }
    return sum;
}

string classify_deutsch_jozsa(const vector<int>& oracle_values) {
    const long long amplitude_num = deutsch_jozsa_zero_amplitude_numerator(oracle_values);
    return (amplitude_num == 0 ? "BALANCED" : "CONSTANT");
}

int main() {
    vector<int> constant_oracle = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> balanced_oracle = {0, 0, 0, 0, 1, 1, 1, 1};

    cout << classify_deutsch_jozsa(constant_oracle) << '\n';
    cout << classify_deutsch_jozsa(balanced_oracle) << '\n';
    return 0;
}
