#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Query {
    int l;
    int r;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    int max_value = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_value = max(max_value, a[i]);
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        --queries[i].l;
        --queries[i].r;
        queries[i].idx = i;
    }

    int block_size = max(1, static_cast<int>(sqrt(n)));
    sort(queries.begin(), queries.end(), [&](const Query& x, const Query& y) {
        int block_x = x.l / block_size;
        int block_y = y.l / block_size;
        if (block_x != block_y) {
            return block_x < block_y;
        }
        if (block_x & 1) {
            return x.r > y.r;
        }
        return x.r < y.r;
    });

    // This direct-index version assumes values are bounded and nonnegative.
    // For a wider or signed universe, compress first and keep the same Mo loop.
    vector<long long> freq(max_value + 1, 0);
    vector<long long> ans(q);
    long long cur = 0;

    auto add = [&](int pos) {
        int x = a[pos];
        long long f = freq[x];
        cur -= f * f * x;
        ++freq[x];
        f = freq[x];
        cur += f * f * x;
    };

    auto remove = [&](int pos) {
        int x = a[pos];
        long long f = freq[x];
        cur -= f * f * x;
        --freq[x];
        f = freq[x];
        cur += f * f * x;
    };

    int l = 0;
    int r = -1;
    for (const Query& query : queries) {
        while (l > query.l) {
            add(--l);
        }
        while (r < query.r) {
            add(++r);
        }
        while (l < query.l) {
            remove(l++);
        }
        while (r > query.r) {
            remove(r--);
        }
        ans[query.idx] = cur;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
