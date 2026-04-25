#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using u64 = uint64_t;

struct HeapChoice {
    int box = -1;
    u64 value = 0;
};

struct LinearBasisMask {
    array<u64, 60> basis_value{};
    array<u64, 60> basis_mask{};

    bool insert(u64 value, u64 mask) {
        for (int bit = 59; bit >= 0; --bit) {
            if (((value >> bit) & 1ULL) == 0) {
                continue;
            }
            if (basis_value[bit] == 0) {
                basis_value[bit] = value;
                basis_mask[bit] = mask;
                return true;
            }
            value ^= basis_value[bit];
            mask ^= basis_mask[bit];
        }
        return false;
    }

    pair<u64, u64> reduce(u64 value) const {
        u64 mask = 0;
        for (int bit = 59; bit >= 0; --bit) {
            if (((value >> bit) & 1ULL) == 0) {
                continue;
            }
            if (basis_value[bit] == 0) {
                return {value, mask};
            }
            value ^= basis_value[bit];
            mask ^= basis_mask[bit];
        }
        return {0, mask};
    }
};

bool is_independent_over_gf2(const vector<u64>& values) {
    LinearBasisMask basis;
    int idx = 0;
    for (u64 value : values) {
        if (!basis.insert(value, 1ULL << idx)) {
            return false;
        }
        ++idx;
    }
    return true;
}

vector<int> solve_pick_your_own_nim(const vector<u64>& alice, int box_count, const vector<HeapChoice>& choices) {
    if (!is_independent_over_gf2(alice)) {
        return {};
    }
    if (static_cast<int>(alice.size()) + box_count > 60) {
        return {};
    }

    int total = static_cast<int>(choices.size());
    vector<char> chosen(total, false);
    vector<int> chosen_in_box(box_count, -1);
    int chosen_count = 0;

    while (true) {
        vector<int> current_ids;
        current_ids.reserve(chosen_count);
        for (int id = 0; id < total; ++id) {
            if (chosen[id]) {
                current_ids.push_back(id);
            }
        }

        LinearBasisMask basis;
        for (int i = 0; i < static_cast<int>(alice.size()); ++i) {
            basis.insert(alice[i], 1ULL << i);
        }
        for (int j = 0; j < static_cast<int>(current_ids.size()); ++j) {
            basis.insert(choices[current_ids[j]].value, 1ULL << (static_cast<int>(alice.size()) + j));
        }

        vector<vector<int>> linear_exchange_from_inside(total);
        vector<char> linear_start(total, false);
        vector<char> partition_end(total, false);

        for (int id = 0; id < total; ++id) {
            if (chosen[id]) {
                continue;
            }
            auto [residual, mask] = basis.reduce(choices[id].value);
            if (residual != 0) {
                linear_start[id] = true;
            } else {
                u64 chosen_mask = mask >> static_cast<int>(alice.size());
                while (chosen_mask != 0) {
                    int bit = __builtin_ctzll(chosen_mask);
                    chosen_mask &= chosen_mask - 1;
                    int inside_id = current_ids[bit];
                    linear_exchange_from_inside[inside_id].push_back(id);
                }
            }
            if (chosen_in_box[choices[id].box] == -1) {
                partition_end[id] = true;
            }
        }

        queue<pair<int, int>> q;
        vector<int> parent_out(total, -1);
        vector<int> parent_in(total, -1);
        int end_out = -1;

        for (int id = 0; id < total; ++id) {
            if (!linear_start[id]) {
                continue;
            }
            parent_out[id] = -2;
            q.push({0, id});
        }

        while (!q.empty() && end_out == -1) {
            auto [side, id] = q.front();
            q.pop();
            if (side == 0) {
                if (partition_end[id]) {
                    end_out = id;
                    break;
                }
                int matched = chosen_in_box[choices[id].box];
                if (matched != -1 && parent_in[matched] == -1) {
                    parent_in[matched] = id;
                    q.push({1, matched});
                }
            } else {
                for (int nxt : linear_exchange_from_inside[id]) {
                    if (parent_out[nxt] == -1) {
                        parent_out[nxt] = id;
                        q.push({0, nxt});
                    }
                }
            }
        }

        if (end_out == -1) {
            break;
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
            chosen[id] = false;
            chosen_in_box[choices[id].box] = -1;
            --chosen_count;
        }
        for (int id : add_nodes) {
            chosen[id] = true;
            chosen_in_box[choices[id].box] = id;
            ++chosen_count;
        }
    }

    if (chosen_count != box_count) {
        return {};
    }
    return chosen_in_box;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<u64> alice(n);
    for (int i = 0; i < n; ++i) {
        cin >> alice[i];
    }

    int m;
    cin >> m;

    vector<HeapChoice> choices;
    choices.reserve(5000);
    for (int box = 0; box < m; ++box) {
        int k;
        cin >> k;
        while (k--) {
            u64 value;
            cin >> value;
            choices.push_back({box, value});
        }
    }

    vector<int> picked = solve_pick_your_own_nim(alice, m, choices);
    if (picked.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    for (int box = 0; box < m; ++box) {
        if (box) {
            cout << ' ';
        }
        cout << choices[picked[box]].value;
    }
    cout << '\n';
    return 0;
}
