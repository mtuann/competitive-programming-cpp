#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct WaveletTree {
    struct Node {
        int lo = 0;
        int hi = -1;
        int left = -1;
        int right = -1;
        vector<int> pref;
    };

    int root = -1;
    vector<Node> nodes;
    vector<int> coords;

    explicit WaveletTree(const vector<int>& a) {
        build(a);
    }

    int kth_smallest(int l, int r, int k) const {
        return coords[kth_smallest(root, l, r, k)];
    }

private:
    void build(const vector<int>& a) {
        coords = a;
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        vector<int> compressed(a.size());
        for (int i = 0; i < static_cast<int>(a.size()); ++i) {
            compressed[i] = static_cast<int>(
                lower_bound(coords.begin(), coords.end(), a[i]) - coords.begin());
        }

        nodes.clear();
        root = build_node(compressed, 0, static_cast<int>(coords.size()) - 1);
    }

    int build_node(const vector<int>& a, int lo, int hi) {
        int id = static_cast<int>(nodes.size());
        nodes.push_back(Node());
        nodes[id].lo = lo;
        nodes[id].hi = hi;
        nodes[id].pref.reserve(a.size() + 1);
        nodes[id].pref.push_back(0);

        if (lo == hi) {
            for (int i = 0; i < static_cast<int>(a.size()); ++i) {
                nodes[id].pref.push_back(i + 1);
            }
            return id;
        }

        int mid = lo + (hi - lo) / 2;
        vector<int> left_values;
        vector<int> right_values;
        left_values.reserve(a.size());
        right_values.reserve(a.size());

        for (int value : a) {
            if (value <= mid) {
                left_values.push_back(value);
                nodes[id].pref.push_back(nodes[id].pref.back() + 1);
            } else {
                right_values.push_back(value);
                nodes[id].pref.push_back(nodes[id].pref.back());
            }
        }

        if (!left_values.empty()) {
            nodes[id].left = build_node(left_values, lo, mid);
        }
        if (!right_values.empty()) {
            nodes[id].right = build_node(right_values, mid + 1, hi);
        }
        return id;
    }

    int kth_smallest(int id, int l, int r, int k) const {
        const Node& node = nodes[id];
        if (node.lo == node.hi) {
            return node.lo;
        }
        int left_l = node.pref[l];
        int left_r = node.pref[r];
        int left_count = left_r - left_l;
        if (k < left_count) {
            return kth_smallest(node.left, left_l, left_r, k);
        }
        return kth_smallest(node.right, l - left_l, r - left_r, k - left_count);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    WaveletTree wt(a);

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << wt.kth_smallest(i - 1, j, k - 1) << '\n';
    }
    return 0;
}
