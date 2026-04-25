#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> compute_grundy(int max_heap, vector<int> moves) {
    sort(moves.begin(), moves.end());
    moves.erase(unique(moves.begin(), moves.end()), moves.end());

    vector<int> sg(max_heap + 1, 0);
    vector<int> seen(static_cast<int>(moves.size()) + 1, -1);

    for (int heap = 1; heap <= max_heap; ++heap) {
        for (int move : moves) {
            if (move > heap) {
                break;
            }
            int g = sg[heap - move];
            if (g < static_cast<int>(seen.size())) {
                seen[g] = heap;
            }
        }

        int mex = 0;
        while (mex < static_cast<int>(seen.size()) && seen[mex] == heap) {
            ++mex;
        }
        sg[heap] = mex;
    }

    return sg;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<int> moves(k);
    for (int i = 0; i < k; ++i) {
        cin >> moves[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> positions(m);
    int max_heap = 0;

    for (int i = 0; i < m; ++i) {
        int len;
        cin >> len;
        positions[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> positions[i][j];
            max_heap = max(max_heap, positions[i][j]);
        }
    }

    vector<int> sg = compute_grundy(max_heap, moves);

    for (const auto& heaps : positions) {
        int xorsum = 0;
        for (int heap : heaps) {
            xorsum ^= sg[heap];
        }
        cout << (xorsum != 0 ? 'W' : 'L');
    }
    cout << '\n';

    return 0;
}
