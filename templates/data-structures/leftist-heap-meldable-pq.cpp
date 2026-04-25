// Template: Leftist-heap meldable priority queue over one fixed item set.
// Signal: every item starts in its own heap, heaps must meld online, and the
// only query is current minimum / delete-min from the heap containing x.
// Assumes: items are 1-indexed, keys are fixed at creation, and equal keys are
// tie-broken by item id so ownership after pop stays deterministic.
// Exposes: LeftistHeapForest with find_heap(), meld_items(), top_of_item_heap(),
// and pop_min_from_item_heap().
// Complexity: O(log n) meld / pop-min, plus inverse-Ackermann owner lookup.
// Main trap: confusing heap merge logic with owner-tracking; after pop the old
// root must redirect to the merged children root.
// Links:
//   Topic: topics/data-structures/pairing-leftist-heap/README.md
//   Note: practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct LeftistHeapForest {
    vector<long long> key;
    vector<int> left_child, right_child, rank_value, representative;
    vector<char> alive;

    explicit LeftistHeapForest(const vector<long long>& values)
        : key(values),
          left_child(values.size(), 0),
          right_child(values.size(), 0),
          rank_value(values.size(), 0),
          representative(values.size(), 0),
          alive(values.size(), 1) {
        representative[0] = 0;
        alive[0] = 0;
        for (int i = 1; i < static_cast<int>(values.size()); ++i) {
            representative[i] = i;
        }
    }

    bool better_root(int a, int b) const {
        if (key[a] != key[b]) {
            return key[a] < key[b];
        }
        return a < b;
    }

    int find_representative(int x) {
        if (x == 0) {
            return 0;
        }
        if (representative[x] == x) {
            return x;
        }
        return representative[x] = find_representative(representative[x]);
    }

    int find_heap(int x) {
        if (x == 0 || !alive[x]) {
            return 0;
        }
        int root = find_representative(x);
        if (root == 0 || !alive[root]) {
            return 0;
        }
        return root;
    }

    int merge_roots(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        if (!better_root(a, b)) {
            swap(a, b);
        }
        right_child[a] = merge_roots(right_child[a], b);
        if (rank_value[left_child[a]] < rank_value[right_child[a]]) {
            swap(left_child[a], right_child[a]);
        }
        rank_value[a] = rank_value[right_child[a]] + 1;
        return a;
    }

    void meld_items(int x, int y) {
        int heap_x = find_heap(x);
        int heap_y = find_heap(y);
        if (heap_x == 0 || heap_y == 0 || heap_x == heap_y) {
            return;
        }
        int root = merge_roots(heap_x, heap_y);
        representative[heap_x] = root;
        representative[heap_y] = root;
        representative[root] = root;
    }

    pair<bool, pair<long long, int>> top_of_item_heap(int x) {
        int root = find_heap(x);
        if (root == 0) {
            return {false, {0, 0}};
        }
        return {true, {key[root], root}};
    }

    pair<bool, pair<long long, int>> pop_min_from_item_heap(int x) {
        int root = find_heap(x);
        if (root == 0) {
            return {false, {0, 0}};
        }
        pair<long long, int> answer = {key[root], root};
        int merged_children = merge_roots(left_child[root], right_child[root]);
        alive[root] = 0;
        left_child[root] = 0;
        right_child[root] = 0;
        rank_value[root] = 0;
        representative[root] = merged_children;
        if (merged_children != 0) {
            representative[merged_children] = merged_children;
        }
        return {true, answer};
    }
};

int main() {
    vector<long long> values = {0, 5, 2, 7, 1};
    LeftistHeapForest heaps(values);

    heaps.meld_items(1, 2);
    heaps.meld_items(3, 4);
    heaps.meld_items(1, 3);

    auto first = heaps.pop_min_from_item_heap(1);
    auto second = heaps.pop_min_from_item_heap(2);
    cout << first.second.first << '\n';
    cout << second.second.first << '\n';
    return 0;
}
