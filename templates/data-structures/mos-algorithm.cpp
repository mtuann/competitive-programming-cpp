// Template: Mo's Algorithm
// Signal: many static range queries over one array, where maintaining the
// current answer for one active range becomes easy after moving one endpoint.
// Assumes: all queries are known in advance; the array is static; add/remove
// operations are symmetric and cheap enough to pay O((n + q) * sqrt(n)).
// Exposes: MoQuery and MoAlgorithm with add_query() and process() for the
// ordinary array-only Mo ordering using inclusive [l, r] queries.
// Complexity: O((n + q) * sqrt(n) * update_cost) with the standard block sort.
// Main trap: using the starter when a monotone sweep is cleaner, or writing
// add/remove that are not exact inverses.
// Links:
//   Topic: topics/data-structures/mos-algorithm/README.md
//   Note: practice/ladders/data-structures/mos-algorithm/powerfularray.md

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct MoQuery {
    int l;
    int r;
    int idx;
};

struct MoAlgorithm {
    int n;
    int block_size;
    vector<MoQuery> queries;

    explicit MoAlgorithm(int n) : n(n), block_size(max(1, static_cast<int>(sqrt(max(1, n))))) {}

    void add_query(int l, int r, int idx) {
        queries.push_back({l, r, idx});
    }

    template <class Add, class Remove, class Output>
    void process(Add&& add, Remove&& remove, Output&& output) {
        vector<MoQuery> order = queries;
        sort(order.begin(), order.end(), [&](const MoQuery& a, const MoQuery& b) {
            int block_a = a.l / block_size;
            int block_b = b.l / block_size;
            if (block_a != block_b) {
                return block_a < block_b;
            }
            if (block_a & 1) {
                return a.r > b.r;
            }
            return a.r < b.r;
        });

        int cur_l = 0;
        int cur_r = -1;

        for (const MoQuery& q : order) {
            while (cur_l > q.l) {
                add(--cur_l);
            }
            while (cur_r < q.r) {
                add(++cur_r);
            }
            while (cur_l < q.l) {
                remove(cur_l++);
            }
            while (cur_r > q.r) {
                remove(cur_r--);
            }
            output(q.idx);
        }
    }
};

int main() {
    vector<int> a = {1, 2, 1, 3, 2};
    vector<int> answers(2, 0);
    vector<int> freq(4, 0);
    int distinct = 0;

    auto add = [&](int pos) {
        if (freq[a[pos]]++ == 0) {
            ++distinct;
        }
    };
    auto remove = [&](int pos) {
        if (--freq[a[pos]] == 0) {
            --distinct;
        }
    };

    MoAlgorithm mo(static_cast<int>(a.size()));
    mo.add_query(0, 2, 0);  // {1, 2, 1}
    mo.add_query(1, 4, 1);  // {2, 1, 3, 2}

    mo.process(add, remove, [&](int idx) {
        answers[idx] = distinct;
    });

    for (int i = 0; i < static_cast<int>(answers.size()); ++i) {
        cout << answers[i] << (i + 1 == static_cast<int>(answers.size()) ? '\n' : ' ');
    }
    return 0;
}
