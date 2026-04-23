#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
Problem: VMCOINS - Trò chơi với những đồng xu
Judge: VN SPOJ / VNOI
URL: https://vn.spoj.com/problems/VMCOINS/
Mirror: https://oj.vnoi.info/problem/vmcoins
Topic: Constructive, promise-driven search, state BFS

Key idea:
- the earlier version was too strong: it assumed the last mismatch can always be
  finished in at most two direct moves
- a better interpretation of the promise is:
    find a translation where N-2 coins can stay fixed as a common core
    and let the remaining two coins move around that core
- for each candidate core, BFS on the unordered positions of the two free coins
  while the core stays fixed
*/

namespace {

struct Point {
    long long x;
    long long y;

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point &other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

struct PointHash {
    size_t operator()(const Point &p) const {
        uint64_t a = static_cast<uint64_t>(p.x) ^ (static_cast<uint64_t>(p.x) >> 33);
        uint64_t b = static_cast<uint64_t>(p.y) ^ (static_cast<uint64_t>(p.y) >> 29);
        return static_cast<size_t>(a * 1000003ULL ^ (b + 0x9e3779b97f4a7c15ULL));
    }
};

struct State {
    int a;
    int b;
};

using PointSet = unordered_set<Point, PointHash>;

int neighbor_count(const PointSet &core, const Point &cell, const Point &other_free) {
    static const int DX[4] = {1, -1, 0, 0};
    static const int DY[4] = {0, 0, 1, -1};

    int count = 0;
    for (int dir = 0; dir < 4; ++dir) {
        Point neighbor{cell.x + DX[dir], cell.y + DY[dir]};
        if (neighbor == other_free || core.find(neighbor) != core.end()) {
            ++count;
        }
    }
    return count;
}

vector<array<Point, 2>> helper_bfs(
    const vector<Point> &core_points,
    const array<Point, 2> &start_free,
    const array<Point, 2> &goal_free
) {
    PointSet core;
    core.reserve(core_points.size() * 4 + 8);
    for (const Point &p : core_points) {
        core.insert(p);
    }

    vector<Point> candidates;
    candidates.reserve(core_points.size() * 4 + 4);

    auto add_candidate = [&](const Point &p) {
        if (core.find(p) == core.end()) {
            candidates.push_back(p);
        }
    };

    add_candidate(start_free[0]);
    add_candidate(start_free[1]);
    add_candidate(goal_free[0]);
    add_candidate(goal_free[1]);

    static const int DX[4] = {1, -1, 0, 0};
    static const int DY[4] = {0, 0, 1, -1};
    for (const Point &p : core_points) {
        for (int dir = 0; dir < 4; ++dir) {
            add_candidate(Point{p.x + DX[dir], p.y + DY[dir]});
        }
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    auto get_index = [&](const Point &p) {
        return static_cast<int>(lower_bound(candidates.begin(), candidates.end(), p) - candidates.begin());
    };

    State start{get_index(start_free[0]), get_index(start_free[1])};
    State goal{get_index(goal_free[0]), get_index(goal_free[1])};
    if (start.a > start.b) {
        swap(start.a, start.b);
    }
    if (goal.a > goal.b) {
        swap(goal.a, goal.b);
    }

    const int m = static_cast<int>(candidates.size());
    vector<vector<char>> visited(m, vector<char>(m, 0));
    vector<vector<State>> parent(m, vector<State>(m, State{-1, -1}));
    vector<vector<array<Point, 2>>> move_used(m, vector<array<Point, 2>>(m));

    deque<State> q;
    visited[start.a][start.b] = 1;
    q.push_back(start);

    auto push_state = [&](State from, State to, array<Point, 2> move) {
        if (to.a > to.b) {
            swap(to.a, to.b);
        }
        if (!visited[to.a][to.b]) {
            visited[to.a][to.b] = 1;
            parent[to.a][to.b] = from;
            move_used[to.a][to.b] = move;
            q.push_back(to);
        }
    };

    while (!q.empty()) {
        State cur = q.front();
        q.pop_front();

        if (cur.a == goal.a && cur.b == goal.b) {
            break;
        }

        Point pa = candidates[cur.a];
        Point pb = candidates[cur.b];

        for (int next = 0; next < m; ++next) {
            if (next == cur.a || next == cur.b) {
                continue;
            }
            Point dst = candidates[next];

            if (neighbor_count(core, dst, pb) >= 2) {
                push_state(cur, State{next, cur.b}, array<Point, 2>{pa, dst});
            }
            if (neighbor_count(core, dst, pa) >= 2) {
                push_state(cur, State{cur.a, next}, array<Point, 2>{pb, dst});
            }
        }
    }

    if (!visited[goal.a][goal.b]) {
        return {};
    }

    vector<array<Point, 2>> answer;
    State cur = goal;
    while (!(cur.a == start.a && cur.b == start.b)) {
        answer.push_back(move_used[cur.a][cur.b]);
        cur = parent[cur.a][cur.b];
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> start(n), target(n);
    for (int i = 0; i < n; ++i) {
        cin >> start[i].x >> start[i].y;
    }
    for (int i = 0; i < n; ++i) {
        cin >> target[i].x >> target[i].y;
    }

    PointSet start_set;
    start_set.reserve(n * 4);
    for (const Point &p : start) {
        start_set.insert(p);
    }

    vector<pair<long long, long long>> translations;
    translations.reserve(n * n);
    for (const Point &s : start) {
        for (const Point &t : target) {
            translations.push_back({s.x - t.x, s.y - t.y});
        }
    }
    sort(translations.begin(), translations.end());
    translations.erase(unique(translations.begin(), translations.end()), translations.end());

    for (const auto &shift : translations) {
        long long dx = shift.first;
        long long dy = shift.second;

        vector<Point> shifted_target(n);
        PointSet target_set;
        target_set.reserve(n * 4);
        for (int i = 0; i < n; ++i) {
            shifted_target[i] = Point{target[i].x + dx, target[i].y + dy};
            target_set.insert(shifted_target[i]);
        }

        vector<Point> common;
        for (const Point &p : shifted_target) {
            if (start_set.find(p) != start_set.end()) {
                common.push_back(p);
            }
        }
        if (static_cast<int>(common.size()) < max(0, n - 2)) {
            continue;
        }

        vector<pair<int, int>> excluded_pairs;
        if (static_cast<int>(common.size()) == n - 2) {
            excluded_pairs.push_back({-1, -1});
        } else if (static_cast<int>(common.size()) == n - 1) {
            for (int i = 0; i < n - 1; ++i) {
                excluded_pairs.push_back({i, -1});
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    excluded_pairs.push_back({i, j});
                }
            }
        }

        for (const auto &excluded : excluded_pairs) {
            vector<Point> core_points;
            core_points.reserve(max(0, n - 2));
            for (int i = 0; i < static_cast<int>(common.size()); ++i) {
                if (i == excluded.first || i == excluded.second) {
                    continue;
                }
                core_points.push_back(common[i]);
            }
            if (static_cast<int>(core_points.size()) != max(0, n - 2)) {
                continue;
            }

            PointSet core_set;
            core_set.reserve(core_points.size() * 4 + 8);
            for (const Point &p : core_points) {
                core_set.insert(p);
            }

            vector<Point> start_free;
            vector<Point> goal_free;
            for (const Point &p : start) {
                if (core_set.find(p) == core_set.end()) {
                    start_free.push_back(p);
                }
            }
            for (const Point &p : shifted_target) {
                if (core_set.find(p) == core_set.end()) {
                    goal_free.push_back(p);
                }
            }

            if (static_cast<int>(start_free.size()) != 2 || static_cast<int>(goal_free.size()) != 2) {
                continue;
            }

            vector<array<Point, 2>> moves = helper_bfs(
                core_points,
                array<Point, 2>{start_free[0], start_free[1]},
                array<Point, 2>{goal_free[0], goal_free[1]}
            );

            if (!moves.empty() || (start_free[0] == goal_free[0] && start_free[1] == goal_free[1]) ||
                (start_free[0] == goal_free[1] && start_free[1] == goal_free[0])) {
                cout << moves.size() << '\n';
                for (const auto &move : moves) {
                    cout << move[0].x << ' ' << move[0].y << ' '
                         << move[1].x << ' ' << move[1].y << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}
