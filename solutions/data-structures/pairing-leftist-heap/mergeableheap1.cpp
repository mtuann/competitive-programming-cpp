#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct LeftistHeapForest {
    vector<int> key;
    vector<int> left_child, right_child, rank_value, representative;
    vector<char> alive;

    explicit LeftistHeapForest(const vector<int>& values)
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

    int pop_min_from_item_heap(int x) {
        int root = find_heap(x);
        if (root == 0) {
            return -1;
        }
        int answer = key[root];
        int merged_children = merge_roots(left_child[root], right_child[root]);
        alive[root] = 0;
        left_child[root] = 0;
        right_child[root] = 0;
        rank_value[root] = 0;
        representative[root] = merged_children;
        if (merged_children != 0) {
            representative[merged_children] = merged_children;
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> values(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    LeftistHeapForest heaps(values);
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            heaps.meld_items(x, y);
        } else {
            int x;
            cin >> x;
            cout << heaps.pop_min_from_item_heap(x) << '\n';
        }
    }
    return 0;
}
