// Template: Dinic max flow.

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

struct Dinic {
    struct Edge {
        int to, rev;
        long long cap;
    };

    int n;
    vector<vector<Edge>> g;
    vector<int> level, ptr;

    explicit Dinic(int n) : n(n), g(n), level(n), ptr(n) {}

    void add_edge(int u, int v, long long cap) {
        Edge a{v, static_cast<int>(g[v].size()), cap};
        Edge b{u, static_cast<int>(g[u].size()), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const Edge &e : g[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int u, int t, long long pushed) {
        if (u == t || pushed == 0) return pushed;
        for (int &cid = ptr[u]; cid < static_cast<int>(g[u].size()); ++cid) {
            Edge &e = g[u][cid];
            if (e.cap == 0 || level[e.to] != level[u] + 1) continue;
            long long tr = dfs(e.to, t, min(pushed, e.cap));
            if (tr == 0) continue;
            e.cap -= tr;
            g[e.to][e.rev].cap += tr;
            return tr;
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, numeric_limits<long long>::max() / 4)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    Dinic dinic(4);
    dinic.add_edge(0, 1, 3);
    dinic.add_edge(0, 2, 2);
    dinic.add_edge(1, 2, 1);
    dinic.add_edge(1, 3, 2);
    dinic.add_edge(2, 3, 4);
    cout << dinic.max_flow(0, 3) << '\n';
    return 0;
}
