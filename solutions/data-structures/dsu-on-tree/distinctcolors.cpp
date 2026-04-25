// Problem: Distinct Colors
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1139/
// Topic: DSU on tree, small-to-large merging, subtree frequency maps
// Idea: each node owns a frequency map of colors in its subtree. Process nodes
// bottom-up, always keep the larger child bag alive, and merge smaller bags
// into it. The number of keys in the surviving bag is the subtree answer.

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> color(n);
    for (int& x : color) {
        cin >> x;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n, -1), order;
    order.reserve(n);
    vector<int> stack = {0};
    parent[0] = 0;

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

    delete bag[0];

    for (int i = 0; i < n; ++i) {
        cout << answer[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
