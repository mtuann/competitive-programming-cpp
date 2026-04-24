#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int index, int delta) {
        for (; index <= n; index += index & -index) {
            bit[index] += delta;
        }
    }

    int sum(int index) const {
        int result = 0;
        for (; index > 0; index -= index & -index) {
            result += bit[index];
        }
        return result;
    }

    int range_sum(int left, int right) const {
        return sum(right) - sum(left - 1);
    }
};

struct Query {
    int left;
    int right;
    int index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> values(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].left >> queries[i].right;
        queries[i].index = i;
    }

    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) {
        if (a.right != b.right) {
            return a.right < b.right;
        }
        return a.left < b.left;
    });

    Fenwick bit(n);
    unordered_map<int, int> last_position;
    last_position.reserve(static_cast<size_t>(n) * 2);

    vector<int> answer(q);
    int query_ptr = 0;

    for (int i = 1; i <= n; ++i) {
        auto it = last_position.find(values[i]);
        if (it != last_position.end()) {
            bit.add(it->second, -1);
        }
        bit.add(i, 1);
        last_position[values[i]] = i;

        while (query_ptr < q && queries[query_ptr].right == i) {
            answer[queries[query_ptr].index] =
                bit.range_sum(queries[query_ptr].left, queries[query_ptr].right);
            ++query_ptr;
        }
    }

    for (int value : answer) {
        cout << value << '\n';
    }

    return 0;
}
