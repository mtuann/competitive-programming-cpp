// Template: Sprague-Grundy for one subtraction set
// Signal: impartial normal-play game with one bounded heap/state parameter and a fixed move set, then xor across independent heaps.
// Assumes: every component is one non-negative integer state; moves strictly decrease the state; precompute bound is manageable.
// Exposes: compute_grundy_subtract_set(max_state, moves) and first_player_wins_sum(heaps, grundy).
// Complexity: O(max_state * |moves|) preprocessing, then O(number of heaps) per query.
// Main trap: using this on score games, misere play, or tasks where the components are not independent.
// Links:
//   Topic: topics/math/game-theory/README.md
//   Note: practice/ladders/math/game-theory/snim.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> compute_grundy_subtract_set(int max_state, vector<int> moves) {
    sort(moves.begin(), moves.end());
    moves.erase(unique(moves.begin(), moves.end()), moves.end());

    vector<int> grundy(max_state + 1, 0);
    vector<int> seen(static_cast<int>(moves.size()) + 1, -1);

    for (int state = 1; state <= max_state; ++state) {
        for (int move : moves) {
            if (move > state) {
                break;
            }
            int g = grundy[state - move];
            if (g < static_cast<int>(seen.size())) {
                seen[g] = state;
            }
        }

        int mex = 0;
        while (mex < static_cast<int>(seen.size()) && seen[mex] == state) {
            ++mex;
        }
        grundy[state] = mex;
    }

    return grundy;
}

bool first_player_wins_sum(const vector<int>& heaps, const vector<int>& grundy) {
    int xorsum = 0;
    for (int heap : heaps) {
        xorsum ^= grundy[heap];
    }
    return xorsum != 0;
}

int main() {
    vector<int> grundy = compute_grundy_subtract_set(8, {1, 2, 3});
    cout << grundy[1] << ' ' << grundy[2] << ' ' << grundy[3] << ' ' << grundy[4] << '\n';
    cout << (first_player_wins_sum({5, 7, 2, 5}, grundy) ? 'W' : 'L') << '\n';
    return 0;
}
