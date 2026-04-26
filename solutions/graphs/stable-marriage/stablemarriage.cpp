#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct StableMarriage {
    int n;
    vector<vector<int>> proposer_pref, accepter_rank;
    vector<int> next_choice, proposer_to_accepter, accepter_to_proposer;

    StableMarriage(const vector<vector<int>> &proposer_pref,
                   const vector<vector<int>> &accepter_pref)
        : n(static_cast<int>(proposer_pref.size())),
          proposer_pref(proposer_pref),
          accepter_rank(n, vector<int>(n, -1)),
          next_choice(n, 0),
          proposer_to_accepter(n, -1),
          accepter_to_proposer(n, -1) {
        for (int a = 0; a < n; ++a) {
            for (int rank = 0; rank < n; ++rank) {
                accepter_rank[a][accepter_pref[a][rank]] = rank;
            }
        }
    }

    vector<int> solve() {
        queue<int> free_proposers;
        for (int p = 0; p < n; ++p) {
            free_proposers.push(p);
        }

        while (!free_proposers.empty()) {
            int p = free_proposers.front();
            free_proposers.pop();
            int a = proposer_pref[p][next_choice[p]++];
            int current = accepter_to_proposer[a];
            if (current == -1) {
                proposer_to_accepter[p] = a;
                accepter_to_proposer[a] = p;
            } else if (accepter_rank[a][p] < accepter_rank[a][current]) {
                proposer_to_accepter[p] = a;
                accepter_to_proposer[a] = p;
                proposer_to_accepter[current] = -1;
                free_proposers.push(current);
            } else {
                free_proposers.push(p);
            }
        }
        return proposer_to_accepter;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> proposer_pref(n, vector<int>(n));
    vector<vector<int>> accepter_pref(n, vector<int>(n));
    for (int p = 0; p < n; ++p) {
        for (int j = 0; j < n; ++j) {
            cin >> proposer_pref[p][j];
            --proposer_pref[p][j];
        }
    }
    for (int a = 0; a < n; ++a) {
        for (int j = 0; j < n; ++j) {
            cin >> accepter_pref[a][j];
            --accepter_pref[a][j];
        }
    }

    StableMarriage solver(proposer_pref, accepter_pref);
    vector<int> match = solver.solve();
    for (int p = 0; p < n; ++p) {
        cout << (p + 1) << ' ' << (match[p] + 1) << '\n';
    }
    return 0;
}
