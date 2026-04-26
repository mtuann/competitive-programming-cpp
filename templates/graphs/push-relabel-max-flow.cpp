// Template: Push-relabel max flow
// Signal: plain static max-flow / min-cut where you want a non-augmenting-path engine,
// especially as a dense-graph or hard-benchmark fallback beside Dinic.
// Assumes: directed network, integral capacities, reverse edges stay paired, and the graph is static during one run.
// Exposes: PushRelabel with add_edge(u, v, cap) and max_flow(s, t).
// Complexity: strong practical performance; safe coarse bound O(n^2 * m) for this highest-label + gap variant.
// Main trap: preflow allows intermediate excess away from s/t, so conservation is not a step-by-step invariant.
// Links:
//   Topic: topics/graphs/flow/README.md
//   Note: practice/ladders/graphs/flow/maximumflowpushrelabel.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct PushRelabel {
    struct Edge {
        int to, rev;
        long long cap;
    };

    int n;
    int limit;
    int highest;
    vector<vector<Edge>> g;
    vector<long long> excess;
    vector<int> height, count, ptr;
    vector<char> active;
    vector<vector<int>> bucket;

    explicit PushRelabel(int n)
        : n(n),
          limit(2 * n + 1),
          highest(0),
          g(n),
          excess(n, 0),
          height(n, 0),
          count(limit + 1, 0),
          ptr(n, 0),
          active(n, 0),
          bucket(limit + 1) {}

    void add_edge(int u, int v, long long cap) {
        if (u == v) return;
        Edge a{v, static_cast<int>(g[v].size()), cap};
        Edge b{u, static_cast<int>(g[u].size()), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    void enqueue(int v) {
        if (v < 0 || v >= n) return;
        if (active[v] || excess[v] == 0 || height[v] >= n) return;
        active[v] = 1;
        bucket[height[v]].push_back(v);
        highest = max(highest, height[v]);
    }

    void push(int u, Edge &e) {
        if (height[u] != height[e.to] + 1 || e.cap == 0 || excess[u] == 0) return;
        long long send = min(excess[u], e.cap);
        e.cap -= send;
        g[e.to][e.rev].cap += send;
        excess[u] -= send;
        excess[e.to] += send;
        enqueue(e.to);
    }

    void relabel(int u) {
        int old_h = height[u];
        int best = limit;
        for (const Edge &e : g[u]) {
            if (e.cap > 0) best = min(best, height[e.to] + 1);
        }
        height[u] = best;
        ptr[u] = 0;
        --count[old_h];
        ++count[height[u]];
    }

    void gap(int h) {
        for (int v = 0; v < n; ++v) {
            if (height[v] < h || height[v] >= n) continue;
            --count[height[v]];
            height[v] = limit;
            ++count[height[v]];
            ptr[v] = 0;
        }
    }

    void discharge(int u) {
        while (excess[u] > 0) {
            if (ptr[u] == static_cast<int>(g[u].size())) {
                if (count[height[u]] == 1) {
                    gap(height[u]);
                } else {
                    relabel(u);
                }
                if (height[u] >= n) break;
            } else {
                Edge &e = g[u][ptr[u]];
                if (e.cap > 0 && height[u] == height[e.to] + 1) {
                    push(u, e);
                } else {
                    ++ptr[u];
                }
            }
        }
    }

    long long max_flow(int s, int t) {
        if (s == t) return 0;
        fill(excess.begin(), excess.end(), 0);
        fill(height.begin(), height.end(), 0);
        fill(count.begin(), count.end(), 0);
        fill(ptr.begin(), ptr.end(), 0);
        fill(active.begin(), active.end(), 0);
        for (auto &b : bucket) b.clear();
        highest = 0;

        height[s] = n;
        count[0] = n - 1;
        count[n] = 1;

        for (Edge &e : g[s]) {
            if (e.cap == 0) continue;
            long long send = e.cap;
            e.cap -= send;
            g[e.to][e.rev].cap += send;
            excess[e.to] += send;
            excess[s] -= send;
            enqueue(e.to);
        }

        while (highest >= 0) {
            if (bucket[highest].empty()) {
                --highest;
                continue;
            }
            int u = bucket[highest].back();
            bucket[highest].pop_back();
            active[u] = 0;
            if (u == s || u == t || excess[u] == 0 || height[u] != highest) continue;
            discharge(u);
            enqueue(u);
        }

        return excess[t];
    }
};

int main() {
    PushRelabel flow(4);
    flow.add_edge(0, 1, 3);
    flow.add_edge(0, 2, 2);
    flow.add_edge(1, 2, 1);
    flow.add_edge(1, 3, 2);
    flow.add_edge(2, 3, 4);
    cout << flow.max_flow(0, 3) << '\n';
    return 0;
}
