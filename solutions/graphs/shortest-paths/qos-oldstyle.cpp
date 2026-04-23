// Problem: QOS - Chất lượng dịch vụ
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/QOS/
// Topic: shortest paths with bounded extra slack and k-th lexicographic reconstruction
// Style: minimal-diff rewrite of an older matrix-based submission

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, t, Cmin = 1111, cc = 0;
long long k;
int minT[1010];
int cost[1010][1010];
long long dp[1010][110];
set<pair<int, int> > q;
vector<int> ans;
pair<int, int> dc[1010];

void input() {
    memset(cost, 0x3f, sizeof(cost));
    scanf("%d%d%d%lld", &n, &m, &t, &k);
    --t;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u;
        --v;
        cost[u][v] = min(cost[u][v], c);
        Cmin = min(Cmin, c);
    }
}

void findMinT() {
    memset(minT, 0x3f, sizeof(minT));
    minT[t] = 0;
    q.insert(make_pair(0, t));
    while (!q.empty()) {
        int du = q.begin()->first;
        int u = q.begin()->second;
        q.erase(q.begin());
        if (du > minT[u]) continue;
        for (int v = 0; v < n; ++v) {
            int l = cost[v][u];
            if (l == INF) continue;
            if (minT[v] > du + l) {
                minT[v] = du + l;
                q.insert(make_pair(minT[v], v));
            }
        }
    }
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

void buildDp() {
    for (int i = 0; i < n; ++i) dc[i] = make_pair(minT[i], i);
    sort(dc, dc + n, cmp);

    for (int p = 0; p <= Cmin; ++p) {
        for (int i = 0; i < n; ++i) {
            int u = dc[i].second;
            if (minT[u] == INF) continue;

            long long ways = (u == t ? 1 : 0);
            for (int v = 0; v < n; ++v) {
                if (cost[u][v] == INF || minT[v] == INF) continue;

                int c = p + minT[u] - minT[v] - cost[u][v];
                if (c < 0) continue;

                ways += dp[v][c];
                if (ways > k) ways = k;
            }
            dp[u][p] = ways;
        }
    }
}

int calculator(int u, long long& need, int& cur_cost) {
    if (u == t) {
        if (need == 1) return -2;
        --need;
    }

    for (int v = 0; v < n; ++v) {
        if (cost[u][v] == INF || minT[v] == INF) continue;

        int cp = minT[0] + Cmin - cost[u][v] - minT[v] - cur_cost;
        if (cp < 0 || cp > Cmin) continue;

        if (need > dp[v][cp]) {
            need -= dp[v][cp];
        } else {
            return v;
        }
    }
    return -1;
}

void solution() {
    if (minT[0] == INF || dp[0][Cmin] < k) {
        puts("-1");
        return;
    }

    ans.push_back(0);
    int tt = 0;
    while (true) {
        int vv = tt;
        int nxt = calculator(tt, k, cc);
        if (nxt == -2) break;
        if (nxt == -1) {
            puts("-1");
            return;
        }
        cc += cost[vv][nxt];
        tt = nxt;
        ans.push_back(tt);
    }

    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d", ans[i] + 1);
        if (i + 1 < (int)ans.size()) printf(" ");
    }
    puts("");
}

int main() {
    input();
    findMinT();
    buildDp();
    solution();
    return 0;
}
