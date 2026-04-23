#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Problem: VMMARBLE - Phan loai bi
Judge: VN SPOJ
URL: https://vn.spoj.com/problems/VMMARBLE/
Topic: exact search, residual-state DP, bitmask DP

Status:
- this is an experimental exact direction for subtask K = 2, M <= 3
- it is based on the "8-invariant" residual compression after fixing the final
  keeper color of each box
- it is useful for research/debugging and matches many brute-force checks, but
  it is NOT yet claimed as a full accepted solution

Main idea:
1. For K = 1, the problem is the standard assignment/coverage DP:
   choose one final color per box, maximize marbles kept in place.
2. For K = 2, M <= 3:
   - choose one keeper color for each box
   - even parts are easy; the hard part is the odd leftovers
   - the exact future of the odd leftovers can be compressed into 8 values:
       B0, B1, B2,
       T01 = S01 + S10,
       T02 = S02 + S20,
       T12 = S12 + S21,
       d0, d1
   - max_save(state) is solved exactly by memoized recursion on that 8-key
   - boxes are grouped by parity pattern, and we run grouped DFS with pruning

This file is intentionally kept separate from the current repo solution so we
can iterate on the exact direction without overwriting the known-wrong file.
*/

static inline int get6(uint64_t key, int idx) {
    return static_cast<int>((key >> (6 * idx)) & 63ULL);
}

static inline int popcount3(int mask) {
    return __builtin_popcount(static_cast<unsigned>(mask));
}

struct Option {
    uint64_t delta9 = 0;   // packed 9-counter delta, each counter in 6 bits
    unsigned char mask = 0;
    int gain = 0;
    int upper = 0;
};

static unordered_map<uint64_t, int> save_memo;

static uint64_t pack8_from_9(uint64_t key9) {
    const int B0 = get6(key9, 0);
    const int B1 = get6(key9, 1);
    const int B2 = get6(key9, 2);
    const int S01 = get6(key9, 3);
    const int S02 = get6(key9, 4);
    const int S10 = get6(key9, 5);
    const int S12 = get6(key9, 6);
    const int S20 = get6(key9, 7);
    const int S21 = get6(key9, 8);

    const int T01 = S01 + S10;
    const int T02 = S02 + S20;
    const int T12 = S12 + S21;
    const int d0 = (S01 + S02) - (S10 + S20) + 64;
    const int d1 = (S10 + S12) - (S01 + S21) + 64;

    uint64_t key8 = 0;
    key8 |= static_cast<uint64_t>(B0);
    key8 |= static_cast<uint64_t>(B1) << 6;
    key8 |= static_cast<uint64_t>(B2) << 12;
    key8 |= static_cast<uint64_t>(T01) << 18;
    key8 |= static_cast<uint64_t>(T02) << 25;
    key8 |= static_cast<uint64_t>(T12) << 32;
    key8 |= static_cast<uint64_t>(d0) << 39;
    key8 |= static_cast<uint64_t>(d1) << 47;
    return key8;
}

static inline uint64_t pack8(
    int B0,
    int B1,
    int B2,
    int T01,
    int T02,
    int T12,
    int d0,
    int d1
) {
    uint64_t key8 = 0;
    key8 |= static_cast<uint64_t>(B0);
    key8 |= static_cast<uint64_t>(B1) << 6;
    key8 |= static_cast<uint64_t>(B2) << 12;
    key8 |= static_cast<uint64_t>(T01) << 18;
    key8 |= static_cast<uint64_t>(T02) << 25;
    key8 |= static_cast<uint64_t>(T12) << 32;
    key8 |= static_cast<uint64_t>(d0 + 64) << 39;
    key8 |= static_cast<uint64_t>(d1 + 64) << 47;
    return key8;
}

static bool decode8(
    uint64_t key8,
    int& B0,
    int& B1,
    int& B2,
    int& T01,
    int& T02,
    int& T12,
    int& d0,
    int& d1,
    int& L,
    int& U,
    int& P,
    int& R
) {
    B0 = static_cast<int>(key8 & 63ULL);
    B1 = static_cast<int>((key8 >> 6) & 63ULL);
    B2 = static_cast<int>((key8 >> 12) & 63ULL);
    T01 = static_cast<int>((key8 >> 18) & 127ULL);
    T02 = static_cast<int>((key8 >> 25) & 127ULL);
    T12 = static_cast<int>((key8 >> 32) & 127ULL);
    d0 = static_cast<int>((key8 >> 39) & 255ULL) - 64;
    d1 = static_cast<int>((key8 >> 47) & 255ULL) - 64;

    const int s1 = T01 + T02 + d0;
    const int s2 = d1 - T01 + T12;
    if ((s1 & 1) || (s2 & 1)) {
        return false;
    }

    P = s1 / 2;
    R = s2 / 2;
    L = max(max(0, P - T02), -R);
    U = min(min(T01, P), T12 - R);
    return L <= U;
}

static int max_save8(uint64_t key8) {
    auto it = save_memo.find(key8);
    if (it != save_memo.end()) {
        return it->second;
    }

    int B0, B1, B2, T01, T02, T12, d0, d1, L, U, P, R;
    if (!decode8(key8, B0, B1, B2, T01, T02, T12, d0, d1, L, U, P, R)) {
        return -1000000000;
    }

    auto has_S01 = [&]() { return U >= 1; };
    auto has_S10 = [&]() { return L <= T01 - 1; };
    auto has_S02 = [&]() { return L <= P - 1; };
    auto has_S20 = [&]() { return U >= P - T02 + 1; };
    auto has_S12 = [&]() { return U >= -R + 1; };
    auto has_S21 = [&]() { return L <= T12 - R - 1; };

    int best = 0;
    auto relax = [&](uint64_t next_key8, int add) {
        const int candidate = add + max_save8(next_key8);
        if (candidate > best) {
            best = candidate;
        }
    };

    // Bx + S?^x -> By, gain 0
    if (B0 && T01 > 0 && has_S10()) {
        relax(pack8(B0 - 1, B1 + 1, B2, T01 - 1, T02, T12, d0 + 1, d1 - 1), 0);
    }
    if (B0 && T02 > 0 && has_S20()) {
        relax(pack8(B0 - 1, B1, B2 + 1, T01, T02 - 1, T12, d0 + 1, d1), 0);
    }
    if (B1 && T01 > 0 && has_S01()) {
        relax(pack8(B0 + 1, B1 - 1, B2, T01 - 1, T02, T12, d0 - 1, d1 + 1), 0);
    }
    if (B1 && T12 > 0 && has_S21()) {
        relax(pack8(B0, B1 - 1, B2 + 1, T01, T02, T12 - 1, d0, d1 + 1), 0);
    }
    if (B2 && T02 > 0 && has_S02()) {
        relax(pack8(B0 + 1, B1, B2 - 1, T01, T02 - 1, T12, d0 - 1, d1), 0);
    }
    if (B2 && T12 > 0 && has_S12()) {
        relax(pack8(B0, B1 + 1, B2 - 1, T01, T02, T12 - 1, d0, d1 - 1), 0);
    }

    // Bx + S_y^z -> save 1
    if (B0 && T12 > 0 && has_S12()) {
        relax(pack8(B0 - 1, B1, B2, T01, T02, T12 - 1, d0, d1 - 1), 1);
    }
    if (B0 && T12 > 0 && has_S21()) {
        relax(pack8(B0 - 1, B1, B2, T01, T02, T12 - 1, d0, d1 + 1), 1);
    }
    if (B1 && T02 > 0 && has_S02()) {
        relax(pack8(B0, B1 - 1, B2, T01, T02 - 1, T12, d0 - 1, d1), 1);
    }
    if (B1 && T02 > 0 && has_S20()) {
        relax(pack8(B0, B1 - 1, B2, T01, T02 - 1, T12, d0 + 1, d1), 1);
    }
    if (B2 && T01 > 0 && has_S01()) {
        relax(pack8(B0, B1, B2 - 1, T01 - 1, T02, T12, d0 - 1, d1 + 1), 1);
    }
    if (B2 && T01 > 0 && has_S10()) {
        relax(pack8(B0, B1, B2 - 1, T01 - 1, T02, T12, d0 + 1, d1 - 1), 1);
    }

    // Bx + By -> save 1 + create one singleton on the opposite edge
    if (B0 && B1) {
        relax(pack8(B0 - 1, B1 - 1, B2, T01 + 1, T02, T12, d0 + 1, d1 - 1), 1);
        relax(pack8(B0 - 1, B1 - 1, B2, T01 + 1, T02, T12, d0 - 1, d1 + 1), 1);
    }
    if (B0 && B2) {
        relax(pack8(B0 - 1, B1, B2 - 1, T01, T02 + 1, T12, d0 + 1, d1), 1);
        relax(pack8(B0 - 1, B1, B2 - 1, T01, T02 + 1, T12, d0 - 1, d1), 1);
    }
    if (B1 && B2) {
        relax(pack8(B0, B1 - 1, B2 - 1, T01, T02, T12 + 1, d0, d1 + 1), 1);
        relax(pack8(B0, B1 - 1, B2 - 1, T01, T02, T12 + 1, d0, d1 - 1), 1);
    }

    save_memo[key8] = best;
    return best;
}

static Option make_option(const array<int, 3>& box, int home) {
    Option option;
    vector<int> odd_other;
    for (int color = 0; color < 3; ++color) {
        if (color != home && (box[color] & 1)) {
            odd_other.push_back(color);
        }
    }

    if (static_cast<int>(odd_other.size()) == 2) {
        option.delta9 += 1ULL << (6 * home);
    } else if (static_cast<int>(odd_other.size()) == 1) {
        const int color = odd_other[0];
        int id = -1;
        if (home == 0 && color == 1) id = 3;
        if (home == 0 && color == 2) id = 4;
        if (home == 1 && color == 0) id = 5;
        if (home == 1 && color == 2) id = 6;
        if (home == 2 && color == 0) id = 7;
        if (home == 2 && color == 1) id = 8;
        option.delta9 += 1ULL << (6 * id);
    }

    option.mask = static_cast<unsigned char>(1 << home);
    option.gain = (box[home] + 1) / 2;
    option.upper = max_save8(pack8_from_9(option.delta9));
    return option;
}

static long long solve_k2_m3_exact_direction(const vector<array<int, 3>>& boxes) {
    int required_mask = 0;
    long long constant_term = 0;
    array<vector<array<int, 3>>, 8> by_parity;

    for (const auto& box : boxes) {
        for (int color = 0; color < 3; ++color) {
            constant_term += (box[color] + 1LL) / 2LL;
            if (box[color] > 0) {
                required_mask |= (1 << color);
            }
        }
        const int pattern = (box[0] & 1) | ((box[1] & 1) << 1) | ((box[2] & 1) << 2);
        by_parity[pattern].push_back(box);
    }

    vector<vector<Option>> groups;
    vector<int> group_box_counts;

    for (int pattern = 0; pattern < 8; ++pattern) {
        if (by_parity[pattern].empty()) {
            continue;
        }

        unordered_map<uint64_t, array<int, 8>> current, next;
        array<int, 8> init;
        init.fill(-1000000000);
        init[0] = 0;
        current[0] = init;

        for (const auto& box : by_parity[pattern]) {
            next.clear();
            const Option options[3] = {
                make_option(box, 0),
                make_option(box, 1),
                make_option(box, 2)
            };

            for (const auto& entry : current) {
                for (int home = 0; home < 3; ++home) {
                    const uint64_t next_delta = entry.first + options[home].delta9;
                    auto iter = next.find(next_delta);
                    if (iter == next.end()) {
                        array<int, 8> blank;
                        blank.fill(-1000000000);
                        iter = next.emplace(next_delta, blank).first;
                    }

                    for (int mask = 0; mask < 8; ++mask) {
                        if (entry.second[mask] <= -1000000000) {
                            continue;
                        }
                        const int next_mask = mask | options[home].mask;
                        iter->second[next_mask] =
                            max(iter->second[next_mask], entry.second[mask] + options[home].gain);
                    }
                }
            }
            current.swap(next);
        }

        vector<Option> compressed;
        compressed.reserve(current.size() * 2);
        for (const auto& entry : current) {
            for (int mask = 0; mask < 8; ++mask) {
                if (entry.second[mask] <= -1000000000) {
                    continue;
                }
                Option option;
                option.delta9 = entry.first;
                option.mask = static_cast<unsigned char>(mask);
                option.gain = entry.second[mask];
                option.upper = max_save8(pack8_from_9(option.delta9));
                compressed.push_back(option);
            }
        }

        sort(
            compressed.begin(),
            compressed.end(),
            [](const Option& a, const Option& b) {
                if (a.gain + a.upper != b.gain + b.upper) {
                    return a.gain + a.upper > b.gain + b.upper;
                }
                return a.gain > b.gain;
            }
        );

        groups.push_back(compressed);
        group_box_counts.push_back(static_cast<int>(by_parity[pattern].size()));
    }

    vector<int> order(groups.size());
    iota(order.begin(), order.end(), 0);
    sort(
        order.begin(),
        order.end(),
        [&](int lhs, int rhs) {
            const int score_l = groups[lhs][0].gain + 4 * groups[lhs][0].upper + 3 * group_box_counts[lhs];
            const int score_r = groups[rhs][0].gain + 4 * groups[rhs][0].upper + 3 * group_box_counts[rhs];
            return score_l > score_r;
        }
    );

    vector<vector<Option>> reordered_groups;
    vector<int> reordered_counts;
    for (int id : order) {
        reordered_groups.push_back(groups[id]);
        reordered_counts.push_back(group_box_counts[id]);
    }
    groups.swap(reordered_groups);
    group_box_counts.swap(reordered_counts);

    const int group_count = static_cast<int>(groups.size());
    vector<int> remaining_boxes(group_count + 1, 0);
    for (int idx = group_count - 1; idx >= 0; --idx) {
        remaining_boxes[idx] = remaining_boxes[idx + 1] + group_box_counts[idx];
    }

    int best_reward = -1;
    uint64_t greedy_delta = 0;
    int greedy_mask = 0;
    int greedy_gain = 0;
    for (int idx = 0; idx < group_count; ++idx) {
        const Option& option = groups[idx][0];
        greedy_delta += option.delta9;
        greedy_mask |= option.mask;
        greedy_gain += option.gain;
    }
    if ((greedy_mask & required_mask) == required_mask) {
        best_reward = greedy_gain + max_save8(pack8_from_9(greedy_delta));
    }

    function<void(int, uint64_t, int, int)> dfs = [&](int idx, uint64_t delta9, int mask, int gain) {
        const int current_save = max_save8(pack8_from_9(delta9));
        const int need = required_mask & (~mask & 7);

        if (popcount3(need) > remaining_boxes[idx]) {
            return;
        }

        if (idx == group_count) {
            if ((mask & required_mask) == required_mask) {
                best_reward = max(best_reward, gain + current_save);
            }
            return;
        }

        for (const auto& option : groups[idx]) {
            dfs(idx + 1, delta9 + option.delta9, mask | option.mask, gain + option.gain);
        }
    };

    dfs(0, 0, 0, 0);
    return constant_term - best_reward;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> input(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> input[i][j];
        }
    }

    if (k == 1) {
        long long total = 0;
        int required_mask = 0;
        vector<int> dp(1 << m, -1000000000);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> next = dp;
            for (int color = 0; color < m; ++color) {
                total += input[i][color];
                if (input[i][color] > 0) {
                    required_mask |= (1 << color);
                }
            }

            for (int mask = 0; mask < (1 << m); ++mask) {
                if (dp[mask] <= -1000000000) {
                    continue;
                }
                for (int color = 0; color < m; ++color) {
                    const int next_mask = mask | (1 << color);
                    next[next_mask] = max(next[next_mask], dp[mask] + input[i][color]);
                }
            }
            dp.swap(next);
        }

        cout << (total - dp[required_mask]) << '\n';
        return 0;
    }

    if (!(k == 2 && m <= 3)) {
        // This experimental file only targets the official subtasks:
        // - K = 1
        // - K = 2, M <= 3
        cout << "-1\n";
        return 0;
    }

    vector<array<int, 3>> boxes(n);
    for (int i = 0; i < n; ++i) {
        boxes[i] = {0, 0, 0};
        for (int color = 0; color < m; ++color) {
            boxes[i][color] = input[i][color];
        }
    }

    cout << solve_k2_m3_exact_direction(boxes) << '\n';
    return 0;
}
