#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Dinic {
    struct Edge {
        int to;
        int rev;
        int cap;
    };

    int n;
    vector<vector<Edge>> g;
    vector<int> level;
    vector<int> ptr;

    explicit Dinic(int n) : n(n), g(n), level(n), ptr(n) {}

    void add_edge(int u, int v, int cap) {
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

    int dfs(int u, int t, int pushed) {
        if (u == t || pushed == 0) {
            return pushed;
        }
        for (int &cid = ptr[u]; cid < static_cast<int>(g[u].size()); ++cid) {
            Edge &e = g[u][cid];
            if (e.cap == 0 || level[e.to] != level[u] + 1) {
                continue;
            }
            int tr = dfs(e.to, t, min(pushed, e.cap));
            if (tr == 0) {
                continue;
            }
            e.cap -= tr;
            g[e.to][e.rev].cap += tr;
            return tr;
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, 1e9)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Dinic dinic(n);
    vector<pair<int, int>> streets;
    streets.reserve(m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        streets.push_back({a, b});
        dinic.add_edge(a, b, 1);
        dinic.add_edge(b, a, 1);
    }

    int answer = dinic.max_flow(0, n - 1);

    vector<int> seen(n, 0);
    queue<int> q;
    seen[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &e : dinic.g[u]) {
            if (e.cap > 0 && !seen[e.to]) {
                seen[e.to] = 1;
                q.push(e.to);
            }
        }
    }

    vector<pair<int, int>> cut;
    for (auto [u, v] : streets) {
        if (seen[u] != seen[v]) {
            cut.push_back({u + 1, v + 1});
        }
    }

    cout << answer << '\n';
    for (auto [u, v] : cut) {
        cout << u << ' ' << v << '\n';
    }
    return 0;
}
