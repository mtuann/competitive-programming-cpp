// Template: wavelet tree (static range kth / counting)
// Signal: one static array with many value-sensitive subarray queries such as
// k-th smallest, count <= x, or count == x.
// Assumes: zero-based half-open intervals [l, r); no updates after build;
// coordinate compression is built in; kth_smallest() uses zero-based k.
// Exposes: WaveletTree with build(a), kth_smallest(), count_leq(), and
// count_equal().
// Complexity: O(n log sigma) build and O(log sigma) per query, where sigma is
// the number of distinct values.
// Main trap: forgetting that l and r become positions inside the current
// node's subsequence after each descent.
// Links:
//   Topic: topics/data-structures/wavelet-tree/README.md
//   Note: practice/ladders/data-structures/wavelet-tree/mkthnum.md

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

    int n = 0;
    int root = -1;
    vector<Node> nodes;
    vector<long long> coords;

    WaveletTree() = default;

    explicit WaveletTree(const vector<long long>& a) {
        build(a);
    }

    void build(const vector<long long>& a) {
        n = static_cast<int>(a.size());
        coords = a;
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        nodes.clear();
        if (n == 0) {
            root = -1;
            return;
        }

        vector<int> compressed(n);
        for (int i = 0; i < n; ++i) {
            compressed[i] = static_cast<int>(
                lower_bound(coords.begin(), coords.end(), a[i]) - coords.begin());
        }
        root = build_node(compressed, 0, static_cast<int>(coords.size()) - 1);
    }

    long long kth_smallest(int l, int r, int k) const {
        if (root == -1 || l >= r) {
            return 0;
        }
        return coords[kth_smallest(root, l, r, k)];
    }

    int count_leq(int l, int r, long long x) const {
        if (root == -1 || l >= r) {
            return 0;
        }
        auto it = upper_bound(coords.begin(), coords.end(), x);
        if (it == coords.begin()) {
            return 0;
        }
        int rank = static_cast<int>(it - coords.begin()) - 1;
        return count_leq(root, l, r, rank);
    }

    int count_equal(int l, int r, long long x) const {
        if (root == -1 || l >= r) {
            return 0;
        }
        auto it = lower_bound(coords.begin(), coords.end(), x);
        if (it == coords.end() || *it != x) {
            return 0;
        }
        int rank = static_cast<int>(it - coords.begin());
        return count_equal(root, l, r, rank);
    }

private:
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

    int count_leq(int id, int l, int r, int rank) const {
        if (id == -1 || l >= r) {
            return 0;
        }
        const Node& node = nodes[id];
        if (rank < node.lo) {
            return 0;
        }
        if (node.hi <= rank) {
            return r - l;
        }
        int mid = node.lo + (node.hi - node.lo) / 2;
        int left_l = node.pref[l];
        int left_r = node.pref[r];
        if (rank <= mid) {
            return count_leq(node.left, left_l, left_r, rank);
        }
        return (left_r - left_l) +
               count_leq(node.right, l - left_l, r - left_r, rank);
    }

    int count_equal(int id, int l, int r, int rank) const {
        if (id == -1 || l >= r) {
            return 0;
        }
        const Node& node = nodes[id];
        if (rank < node.lo || rank > node.hi) {
            return 0;
        }
        if (node.lo == node.hi) {
            return r - l;
        }
        int mid = node.lo + (node.hi - node.lo) / 2;
        int left_l = node.pref[l];
        int left_r = node.pref[r];
        if (rank <= mid) {
            return count_equal(node.left, left_l, left_r, rank);
        }
        return count_equal(node.right, l - left_l, r - left_r, rank);
    }
};

int main() {
    vector<long long> a = {1, 5, 2, 6, 3, 7, 4};
    WaveletTree wt(a);
    cout << wt.kth_smallest(1, 5, 2) << '\n';
    cout << wt.count_leq(1, 5, 3) << '\n';
    cout << wt.count_equal(0, 7, 6) << '\n';
    return 0;
}
