// Template: unweighted matroid intersection on one explicit ground set using
// independence oracles.
// Signal: one explicit ground set, two matroids, and maximum-cardinality common
// independent set matters more than weights.
// Assumes: the ground set is small / medium and both independence oracles are
// fast enough to call many times.
// Exposes: matroid_intersection_maximum(ground_size, independent1, independent2).
// Complexity: O(n^3 * T_oracle) in the straightforward contest route here.
// Main trap: forcing ordinary matching / xor-basis tasks through this generic
// route when a specialized solver is much smaller.
// Links:
//   Topic: topics/advanced/matroid-intersection/README.md
//   Note: practice/ladders/advanced/matroid-intersection/pickyourownnim.md

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using IndependentOracle = function<bool(const vector<int>&)>;

vector<int> materialize_subset(const vector<char>& in_set, int remove_id = -1, int add_id = -1) {
    vector<int> subset;
    subset.reserve(in_set.size());
    for (int id = 0; id < static_cast<int>(in_set.size()); ++id) {
        if (in_set[id] && id != remove_id) {
            subset.push_back(id);
        }
    }
    if (add_id != -1) {
        subset.push_back(add_id);
    }
    return subset;
}

vector<int> enumerate_subset(const vector<char>& in_set) {
    vector<int> subset;
    for (int id = 0; id < static_cast<int>(in_set.size()); ++id) {
        if (in_set[id]) {
            subset.push_back(id);
        }
    }
    return subset;
}

vector<int> matroid_intersection_maximum(
    int ground_size,
    const IndependentOracle& independent1,
    const IndependentOracle& independent2
) {
    vector<char> in_set(ground_size, false);

    while (true) {
        vector<int> current = enumerate_subset(in_set);
        vector<vector<int>> m1_exchange(ground_size);
        vector<vector<int>> m2_exchange(ground_size);
        vector<char> in_z2(ground_size, false);
        vector<int> z1;

        for (int add = 0; add < ground_size; ++add) {
            if (in_set[add]) {
                continue;
            }
            vector<int> grown = materialize_subset(in_set, -1, add);
            bool addable1 = independent1(grown);
            bool addable2 = independent2(grown);
            if (addable1) {
                z1.push_back(add);
            }
            if (addable2) {
                in_z2[add] = true;
            }
            for (int remove : current) {
                vector<int> swapped = materialize_subset(in_set, remove, add);
                if (independent1(swapped)) {
                    m1_exchange[remove].push_back(add);
                }
                if (independent2(swapped)) {
                    m2_exchange[add].push_back(remove);
                }
            }
        }

        queue<pair<int, int>> q;
        vector<int> parent_out(ground_size, -1);
        vector<int> parent_in(ground_size, -1);
        int end_out = -1;

        for (int start : z1) {
            if (parent_out[start] != -1) {
                continue;
            }
            parent_out[start] = -2;
            q.push({0, start});
        }

        while (!q.empty() && end_out == -1) {
            auto [side, id] = q.front();
            q.pop();
            if (side == 0) {
                if (in_z2[id]) {
                    end_out = id;
                    break;
                }
                for (int nxt : m2_exchange[id]) {
                    if (parent_in[nxt] == -1) {
                        parent_in[nxt] = id;
                        q.push({1, nxt});
                    }
                }
            } else {
                for (int nxt : m1_exchange[id]) {
                    if (parent_out[nxt] == -1) {
                        parent_out[nxt] = id;
                        q.push({0, nxt});
                    }
                }
            }
        }

        if (end_out == -1) {
            return enumerate_subset(in_set);
        }

        vector<int> add_nodes;
        vector<int> remove_nodes;
        int out = end_out;
        while (true) {
            add_nodes.push_back(out);
            int in = parent_out[out];
            if (in == -2) {
                break;
            }
            remove_nodes.push_back(in);
            out = parent_in[in];
        }

        for (int id : remove_nodes) {
            in_set[id] = false;
        }
        for (int id : add_nodes) {
            in_set[id] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct Edge {
        int left = 0;
        int right = 0;
    };

    vector<Edge> edges = {
        {0, 0},
        {0, 1},
        {1, 0},
    };

    auto left_partition = [&](const vector<int>& subset) -> bool {
        vector<int> used(2, -1);
        for (int id : subset) {
            if (used[edges[id].left] != -1) {
                return false;
            }
            used[edges[id].left] = id;
        }
        return true;
    };

    auto right_partition = [&](const vector<int>& subset) -> bool {
        vector<int> used(2, -1);
        for (int id : subset) {
            if (used[edges[id].right] != -1) {
                return false;
            }
            used[edges[id].right] = id;
        }
        return true;
    };

    vector<int> chosen = matroid_intersection_maximum(
        static_cast<int>(edges.size()),
        left_partition,
        right_partition
    );

    cout << chosen.size() << '\n';
    for (int i = 0; i < static_cast<int>(chosen.size()); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << chosen[i];
    }
    cout << '\n';  // 2 / 1 2
    return 0;
}
