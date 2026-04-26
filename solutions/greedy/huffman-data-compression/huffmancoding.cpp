#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct HuffmanResult {
    long long weighted_cost = 0;
    vector<string> codes;
};

struct HuffmanNode {
    long long freq = 0;
    int min_symbol = -1;
    int left = -1;
    int right = -1;
    bool leaf = false;
    int symbol = -1;
};

HuffmanResult build_huffman_codes(const vector<long long>& freq) {
    int n = (int)freq.size();
    HuffmanResult result;
    result.codes.assign(n, "");
    if (n == 0) {
        return result;
    }
    if (n == 1) {
        result.codes[0] = "-";
        return result;
    }

    vector<HuffmanNode> nodes;
    nodes.reserve(2 * n);
    using HeapItem = pair<pair<long long, int>, int>;
    priority_queue<HeapItem, vector<HeapItem>, greater<HeapItem>> pq;

    for (int i = 0; i < n; i++) {
        nodes.push_back(HuffmanNode{freq[i], i, -1, -1, true, i});
        pq.push({{freq[i], i}, i});
    }

    while ((int)pq.size() > 1) {
        auto [key_a, a] = pq.top();
        pq.pop();
        auto [key_b, b] = pq.top();
        pq.pop();

        long long merged = nodes[a].freq + nodes[b].freq;
        int min_symbol = min(nodes[a].min_symbol, nodes[b].min_symbol);
        nodes.push_back(HuffmanNode{merged, min_symbol, a, b, false, -1});
        int parent = (int)nodes.size() - 1;
        pq.push({{merged, min_symbol}, parent});
        result.weighted_cost += merged;
    }

    int root = pq.top().second;
    string path;
    function<void(int)> dfs = [&](int u) {
        if (nodes[u].leaf) {
            result.codes[nodes[u].symbol] = path;
            return;
        }
        path.push_back('0');
        dfs(nodes[u].left);
        path.back() = '1';
        dfs(nodes[u].right);
        path.pop_back();
    };
    dfs(root);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> freq(n);
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    HuffmanResult result = build_huffman_codes(freq);
    cout << result.weighted_cost << '\n';
    for (const string& code : result.codes) {
        cout << code << '\n';
    }
    return 0;
}
