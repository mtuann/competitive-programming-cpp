// Problem: VOITSORT - VOI 2015 Day 2 - Cây hoán vị
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/VOITSORT/
// Topic: count stack-sortable permutations in a short lexicographic interval
// Idea: TSort is exactly one-stack-sortable; since k < 10!, only the last 10 positions need explicit enumeration

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct PrefixState {
    vector<int> st;
    int need;
};

static PrefixState process_prefix(const vector<int>& perm, int prefix_len) {
    PrefixState state;
    state.need = 1;
    state.st.reserve(prefix_len);

    for (int i = 0; i < prefix_len; ++i) {
        state.st.push_back(perm[i]);
        while (!state.st.empty() && state.st.back() == state.need) {
            state.st.pop_back();
            ++state.need;
        }
    }
    return state;
}

static bool check_suffix(const PrefixState& base, const vector<int>& suffix, int n) {
    vector<int> st = base.st;
    int need = base.need;

    for (int x : suffix) {
        st.push_back(x);
        while (!st.empty() && st.back() == need) {
            st.pop_back();
            ++need;
        }
    }

    return st.empty() && need == n + 1;
}

static long long rank_suffix(vector<int> values, const vector<int>& perm, const vector<long long>& fact) {
    long long rank = 0;
    int d = (int)perm.size();
    for (int i = 0; i < d; ++i) {
        int pos = 0;
        while (values[pos] != perm[i]) ++pos;
        rank += pos * fact[d - 1 - i];
        values.erase(values.begin() + pos);
    }
    return rank;
}

static long long count_block(const vector<int>& perm, long long len, int d) {
    int n = (int)perm.size();
    int prefix_len = n - d;
    PrefixState base = process_prefix(perm, prefix_len);

    vector<int> suffix(perm.begin() + prefix_len, perm.end());
    long long answer = 0;

    for (long long step = 0; step < len; ++step) {
        if (check_suffix(base, suffix, n)) ++answer;
        if (step + 1 == len) break;
        next_permutation(suffix.begin(), suffix.end());
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) cin >> perm[i];

    int d = min(n, 10);
    vector<long long> fact(d + 1, 1);
    for (int i = 1; i <= d; ++i) fact[i] = fact[i - 1] * i;

    int prefix_len = n - d;
    vector<int> suffix(perm.begin() + prefix_len, perm.end());
    vector<int> sorted_suffix = suffix;
    sort(sorted_suffix.begin(), sorted_suffix.end());

    long long rank = rank_suffix(sorted_suffix, suffix, fact);
    long long first_block = min(k, fact[d] - rank);

    long long answer = count_block(perm, first_block, d);

    if (k > first_block) {
        vector<int> block_last = perm;
        sort(block_last.begin() + prefix_len, block_last.end(), greater<int>());

        if (next_permutation(block_last.begin(), block_last.end())) {
            answer += count_block(block_last, k - first_block, d);
        }
    }

    cout << answer << '\n';
    return 0;
}
