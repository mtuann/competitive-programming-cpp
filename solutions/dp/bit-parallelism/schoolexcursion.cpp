#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    explicit DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

struct DynamicBitsetReachability {
    int max_index;
    vector<uint64_t> words;

    explicit DynamicBitsetReachability(int max_index_)
        : max_index(max_index_), words((max_index_ >> 6) + 1, 0) {
        words[0] = 1ULL;
        trim_tail();
    }

    void trim_tail() {
        int used_bits = (max_index & 63) + 1;
        if (used_bits == 64) return;
        words.back() &= ((1ULL << used_bits) - 1ULL);
    }

    void or_shift_left(int shift) {
        if (shift <= 0) return;
        int whole = shift >> 6;
        int offset = shift & 63;
        for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i) {
            uint64_t shifted = 0;
            int from = i - whole;
            if (from >= 0) {
                shifted |= words[from] << offset;
                if (offset != 0 && from - 1 >= 0) {
                    shifted |= words[from - 1] >> (64 - offset);
                }
            }
            words[i] |= shifted;
        }
        trim_tail();
    }

    bool test(int index) const {
        return (words[index >> 6] >> (index & 63)) & 1ULL;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        dsu.unite(a, b);
    }

    vector<int> comp_sizes;
    for (int v = 0; v < n; ++v) {
        if (dsu.find(v) == v) comp_sizes.push_back(dsu.size[v]);
    }

    DynamicBitsetReachability reachable(n);
    for (int c : comp_sizes) reachable.or_shift_left(c);

    for (int s = 1; s <= n; ++s) {
        cout << (reachable.test(s) ? '1' : '0');
    }
    cout << '\n';
    return 0;
}
