// Template: small-to-large subtree container merging
// Signal: every node needs one subtree answer and each child contributes a
// mergeable container such as a frequency map or set.
// Assumes: the subtree summary can be updated by inserting all entries from one
// smaller child container into one larger surviving container.
// Exposes: compute_subtree_distinct_counts(adj, color, root) using one
// unordered_map<int,int> per surviving subtree bag.
// Complexity: near O(n log n) average with hash maps, or O(n log^2 n) if the
// container is switched to an ordered map/set.
// Main trap: merging the large bag into the small one, or using this when
// fixed-size tree DP or Euler-tour flattening already solves the task.
// Links:
//   Topic: topics/data-structures/dsu-on-tree/README.md
//   Note: practice/ladders/data-structures/dsu-on-tree/distinctcolors.md

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 0x9e3779b97f4a7c15ULL;
        return splitmix64(x + FIXED_RANDOM);
    }
};

using FreqMap = unordered_map<int, int, custom_hash>;

static void merge_small_into_large(FreqMap& large, FreqMap& small) {
    large.reserve(large.size() + small.size());
    for (const auto& [value, count] : small) {
        large[value] += count;
    }
}

vector<int> compute_subtree_distinct_counts(const vector<vector<int>>& adj,
                                            const vector<int>& color,
                                            int root = 0) {
    int n = static_cast<int>(adj.size());
    vector<int> parent(n, -1), order;
    order.reserve(n);
    vector<int> stack = {root};
    parent[root] = root;

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            stack.push_back(v);
        }
    }

    vector<FreqMap*> bag(n, nullptr);
    vector<int> answer(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        bag[u] = new FreqMap();
        bag[u]->reserve(2);
        (*bag[u])[color[u]] = 1;

        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            FreqMap* child = bag[v];
            if (bag[u]->size() < child->size()) {
                swap(bag[u], child);
            }
            merge_small_into_large(*bag[u], *child);
            delete child;
            bag[v] = nullptr;
        }

        answer[u] = static_cast<int>(bag[u]->size());
    }

    delete bag[root];
    return answer;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {0},
        {0, 3, 4},
        {2},
        {2}
    };
    vector<int> color = {2, 3, 2, 2, 1};
    vector<int> answer = compute_subtree_distinct_counts(adj, color, 0);
    for (int i = 0; i < static_cast<int>(answer.size()); ++i) {
        cout << answer[i] << (i + 1 == static_cast<int>(answer.size()) ? '\n' : ' ');
    }
    return 0;
}
