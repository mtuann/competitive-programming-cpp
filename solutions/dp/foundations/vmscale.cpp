// Problem: VMSCALE - Chiếc cân kỳ diệu
// Judge: VN SPOJ / VNOI
// Source URL: https://vn.spoj.com/problems/VMSCALE/
// Mirror URL: https://oj.vnoi.info/problem/vmscale
// Topic: DP, decision tree, balanced ternary
// Idea: one weighing compares x with an integer pivot T, and its cost is the
// number of nonzero digits in balanced ternary. Let far[B][L] be the farthest
// R such that every x in [L, R] can be identified with worst-case total cost
// <= B. If the first pivot is T with cost c, then [L, T - 1] and [T + 1, R]
// both need budget B - c. This yields an exact budget DP.

#include <algorithm>
#include <array>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

namespace {

constexpr int MAX_W = 10000;

struct FastScanner {
    static const int BUFSIZE = 1 << 16;
    int idx = 0;
    int size = 0;
    char buf[BUFSIZE];

    char read() {
        if (idx >= size) {
            size = static_cast<int>(fread(buf, 1, BUFSIZE, stdin));
            idx = 0;
            if (size == 0) {
                return 0;
            }
        }
        return buf[idx++];
    }

    int next_int() {
        char c = read();
        while (c && !isdigit(static_cast<unsigned char>(c)) && c != '-') {
            c = read();
        }
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = read();
        }
        int x = 0;
        while (isdigit(static_cast<unsigned char>(c))) {
            x = x * 10 + (c - '0');
            c = read();
        }
        return sign * x;
    }
};

int balanced_ternary_weight(int x) {
    int cost = 0;
    while (x > 0) {
        int r = x % 3;
        if (r == 0) {
            x /= 3;
        } else if (r == 1) {
            ++cost;
            x /= 3;
        } else {
            ++cost;
            x = (x + 1) / 3;
        }
    }
    return cost;
}

}  // namespace

int main() {
    FastScanner in;
    int q = in.next_int();

    array<int, MAX_W + 1> weight{};
    int max_weight_cost = 0;
    for (int x = 1; x <= MAX_W; ++x) {
        weight[x] = balanced_ternary_weight(x);
        max_weight_cost = max(max_weight_cost, weight[x]);
    }

    vector<vector<int> > prev_with_cost(max_weight_cost + 1, vector<int>(MAX_W + 1, 0));
    vector<int> last(max_weight_cost + 1, 0);
    for (int x = 1; x <= MAX_W; ++x) {
        last[weight[x]] = x;
        for (int c = 1; c <= max_weight_cost; ++c) {
            prev_with_cost[c][x] = last[c];
        }
    }

    vector<vector<int> > far(1, vector<int>(MAX_W + 2, 0));
    for (int l = 1; l <= MAX_W; ++l) {
        far[0][l] = l;
    }
    far[0][MAX_W + 1] = MAX_W;

    int max_budget = 0;
    while (far[max_budget][1] < MAX_W) {
        ++max_budget;
        far.push_back(vector<int>(MAX_W + 2, 0));
        far[max_budget][MAX_W + 1] = MAX_W;

        for (int l = MAX_W; l >= 1; --l) {
            int best = far[max_budget - 1][l];
            int usable_cost = min(max_budget, max_weight_cost);

            for (int c = 1; c <= usable_cost; ++c) {
                int limit = far[max_budget - c][l] + 1;
                if (limit > MAX_W) {
                    limit = MAX_W;
                }
                int t = prev_with_cost[c][limit];
                if (t < l) {
                    continue;
                }

                int candidate = (t == MAX_W ? MAX_W : far[max_budget - c][t + 1]);
                if (candidate > best) {
                    best = candidate;
                }
            }

            far[max_budget][l] = best;
        }
    }

    string output;
    output.reserve(static_cast<size_t>(q) * 4);

    for (int i = 0; i < q; ++i) {
        int l = in.next_int();
        int r = in.next_int();

        int lo = 0;
        int hi = max_budget;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (far[mid][l] >= r) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        output += to_string(lo);
        output.push_back('\n');
    }

    fwrite(output.c_str(), 1, output.size(), stdout);
    return 0;
}
