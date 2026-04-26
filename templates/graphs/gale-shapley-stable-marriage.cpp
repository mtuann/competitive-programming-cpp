// Template: Gale-Shapley stable marriage
// Signal: two equal-sized sides with complete strict preference lists and a stability objective.
// Assumes: both sides have size n, and every preference list is a permutation of 0..n-1.
// Exposes: StableMarriage(proposer_pref, accepter_pref).solve() -> {proposer_to_accepter, accepter_to_proposer}.
// Complexity: O(n^2).
// Main trap: using this when the true objective is maximum cardinality or minimum total cost instead of stability.
// Links:
//   Topic: topics/graphs/stable-marriage/README.md
//   Note: practice/ladders/graphs/stable-marriage/stablemarriage.md

#include <cassert>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct StableMarriage {
    int n;
    vector<vector<int>> proposer_pref, accepter_pref, accepter_rank;
    vector<int> next_choice, proposer_to_accepter, accepter_to_proposer;

    StableMarriage(vector<vector<int>> proposer_pref, vector<vector<int>> accepter_pref)
        : n(static_cast<int>(proposer_pref.size())),
          proposer_pref(std::move(proposer_pref)),
          accepter_pref(std::move(accepter_pref)),
          accepter_rank(n, vector<int>(n, -1)),
          next_choice(n, 0),
          proposer_to_accepter(n, -1),
          accepter_to_proposer(n, -1) {
        assert(static_cast<int>(this->accepter_pref.size()) == n);
        for (int p = 0; p < n; ++p) {
            assert(static_cast<int>(this->proposer_pref[p].size()) == n);
        }
        for (int a = 0; a < n; ++a) {
            assert(static_cast<int>(this->accepter_pref[a].size()) == n);
            for (int rank = 0; rank < n; ++rank) {
                int p = this->accepter_pref[a][rank];
                assert(0 <= p && p < n);
                accepter_rank[a][p] = rank;
            }
        }
    }

    pair<vector<int>, vector<int>> solve() {
        queue<int> free_proposers;
        for (int p = 0; p < n; ++p) {
            free_proposers.push(p);
        }

        while (!free_proposers.empty()) {
            int p = free_proposers.front();
            free_proposers.pop();
            assert(next_choice[p] < n);
            int a = proposer_pref[p][next_choice[p]++];
            int current = accepter_to_proposer[a];
            if (current == -1) {
                proposer_to_accepter[p] = a;
                accepter_to_proposer[a] = p;
                continue;
            }
            if (accepter_rank[a][p] < accepter_rank[a][current]) {
                proposer_to_accepter[p] = a;
                accepter_to_proposer[a] = p;
                proposer_to_accepter[current] = -1;
                free_proposers.push(current);
            } else {
                free_proposers.push(p);
            }
        }

        return {proposer_to_accepter, accepter_to_proposer};
    }
};

int main() {
    vector<vector<int>> proposer_pref = {
        {0, 1, 2},
        {1, 0, 2},
        {1, 2, 0},
    };
    vector<vector<int>> accepter_pref = {
        {1, 0, 2},
        {0, 1, 2},
        {0, 1, 2},
    };

    StableMarriage solver(proposer_pref, accepter_pref);
    auto [match_p, match_a] = solver.solve();
    for (int a : match_p) {
        cout << a << ' ';
    }
    cout << '\n';
    return 0;
}
