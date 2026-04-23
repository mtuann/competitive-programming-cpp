// Problem: KINGDOMS - VM 10 Bài 14 - KINGDOMS
// Judge: VN SPOJ / VNOI
// Source URL: https://vn.spoj.com/ranks/KINGDOMS/
// Mirror URL: https://oj.vnoi.info/problem/kingdoms
// Topic: geometry, sweep line
// Idea: sweep by x; active convex polygons form a laminar family of vertical
// intervals. Order active kingdoms by their lower boundary, take the predecessor
// below the query y, then climb parents until the upper boundary contains y.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

static __int128 cross(const Point& a, const Point& b, const Point& c) {
    return static_cast<__int128>(b.x - a.x) * (c.y - a.y) -
           static_cast<__int128>(b.y - a.y) * (c.x - a.x);
}

static vector<Point> build_chain(vector<Point> pts, bool upper) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    vector<Point> hull;
    if (!upper) {
        for (const Point& p : pts) {
            while (hull.size() >= 2 &&
                   cross(hull[hull.size() - 2], hull.back(), p) <= 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }
    } else {
        for (int i = static_cast<int>(pts.size()) - 1; i >= 0; --i) {
            const Point& p = pts[i];
            while (hull.size() >= 2 &&
                   cross(hull[hull.size() - 2], hull.back(), p) <= 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }
        reverse(hull.begin(), hull.end());
    }
    return hull;
}

struct Polygon {
    vector<Point> lower;
    vector<Point> upper;
    long long min_x = 0;
    long long max_x = 0;
    long long start_y = 0;
};

static vector<Polygon> polygons;
static long double sweep_x = 0;

static int segment_index(const vector<Point>& chain, long double x) {
    int left = 0;
    int right = static_cast<int>(chain.size()) - 2;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (static_cast<long double>(chain[mid].x) <= x) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

static long double line_y(const vector<Point>& chain, long double x) {
    int idx = segment_index(chain, x);
    const Point& a = chain[idx];
    const Point& b = chain[idx + 1];
    long double dx = static_cast<long double>(b.x - a.x);
    long double t = (x - static_cast<long double>(a.x)) / dx;
    return static_cast<long double>(a.y) +
           (static_cast<long double>(b.y - a.y) * t);
}

static bool lower_less_than_value(int id, long double y) {
    return line_y(polygons[id].lower, sweep_x) < y;
}

static bool upper_greater_than_y(int id, long long x, long long y) {
    const vector<Point>& chain = polygons[id].upper;
    int idx = segment_index(chain, static_cast<long double>(x));
    const Point& a = chain[idx];
    const Point& b = chain[idx + 1];
    __int128 orient = static_cast<__int128>(b.x - a.x) * (y - a.y) -
                      static_cast<__int128>(b.y - a.y) * (x - a.x);
    return orient < 0;
}

static bool upper_greater_than_value(int id, long double y) {
    return line_y(polygons[id].upper, sweep_x) > y;
}

struct Event {
    long long x;
    int type;  // 0 = end, 1 = query, 2 = start
    int id;
    long long y;
    int extra;
};

struct Node {
    int id;
    unsigned priority;
    Node* left;
    Node* right;

    explicit Node(int id_, unsigned priority_)
        : id(id_), priority(priority_), left(nullptr), right(nullptr) {}
};

static unsigned rng_state = 712367821u;

static unsigned next_rand() {
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 17;
    rng_state ^= rng_state << 5;
    return rng_state;
}

static bool polygon_less(int lhs, int rhs) {
    if (lhs == rhs) return false;
    long double yl = line_y(polygons[lhs].lower, sweep_x);
    long double yr = line_y(polygons[rhs].lower, sweep_x);
    if (fabsl(yl - yr) > 1e-18L) return yl < yr;
    return lhs < rhs;
}

static void split(Node* root, int key_id, Node*& left, Node*& right) {
    if (root == nullptr) {
        left = right = nullptr;
        return;
    }
    if (polygon_less(root->id, key_id)) {
        split(root->right, key_id, root->right, right);
        left = root;
    } else {
        split(root->left, key_id, left, root->left);
        right = root;
    }
}

static Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    }
    right->left = merge(left, right->left);
    return right;
}

static Node* insert(Node* root, Node* node) {
    if (root == nullptr) return node;
    if (node->priority > root->priority) {
        split(root, node->id, node->left, node->right);
        return node;
    }
    if (polygon_less(node->id, root->id)) {
        root->left = insert(root->left, node);
    } else {
        root->right = insert(root->right, node);
    }
    return root;
}

static Node* erase(Node* root, int id) {
    if (root == nullptr) return nullptr;
    if (root->id == id) {
        Node* result = merge(root->left, root->right);
        delete root;
        return result;
    }
    if (polygon_less(id, root->id)) {
        root->left = erase(root->left, id);
    } else {
        root->right = erase(root->right, id);
    }
    return root;
}

static int predecessor_by_value(Node* root, long double y) {
    int result = 0;
    while (root != nullptr) {
        if (lower_less_than_value(root->id, y)) {
            result = root->id;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    polygons.assign(n + 1, Polygon());

    vector<Event> events;
    events.reserve(2 * n + q);

    for (int id = 1; id <= n; ++id) {
        int k;
        cin >> k;
        vector<Point> pts(k);
        for (int i = 0; i < k; ++i) cin >> pts[i].x >> pts[i].y;

        polygons[id].lower = build_chain(pts, false);
        polygons[id].upper = build_chain(pts, true);
        polygons[id].min_x = polygons[id].lower.front().x;
        polygons[id].max_x = polygons[id].lower.back().x;
        polygons[id].start_y = polygons[id].lower.front().y;

        events.push_back({polygons[id].max_x, 0, id, 0, 0});
        events.push_back({polygons[id].min_x, 2, id, polygons[id].start_y, 0});
    }

    vector<long long> qx(q), qy(q);
    for (int i = 0; i < q; ++i) {
        cin >> qx[i] >> qy[i];
        events.push_back({qx[i], 1, i, qy[i], 0});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.x != b.x) return a.x < b.x;
        if (a.type != b.type) return a.type < b.type;
        if (a.type == 2 && a.y != b.y) return a.y < b.y;
        return a.id < b.id;
    });

    const int LOG = 17;
    vector<int> parent(n + 1, 0);
    vector<vector<int> > up(LOG, vector<int>(n + 1, 0));
    vector<int> answer(q, 0);

    Node* active = nullptr;

    for (const Event& event : events) {
        if (event.type == 0) {
            sweep_x = static_cast<long double>(event.x) - 0.5L;
            active = erase(active, event.id);
            continue;
        }

        if (event.type == 2) {
            sweep_x = static_cast<long double>(event.x) + 0.5L;
            long double probe = line_y(polygons[event.id].lower, sweep_x);
            int node = predecessor_by_value(active, probe);
            if (node != 0 && !upper_greater_than_value(node, probe)) {
                int cur = node;
                for (int j = LOG - 1; j >= 0; --j) {
                    int anc = up[j][cur];
                    if (anc != 0 && !upper_greater_than_value(anc, probe)) {
                        cur = anc;
                    }
                }
                node = parent[cur];
            }
            parent[event.id] = node;
            up[0][event.id] = parent[event.id];
            for (int j = 1; j < LOG; ++j) {
                up[j][event.id] = up[j - 1][up[j - 1][event.id]];
            }
            active = insert(active, new Node(event.id, next_rand()));
            continue;
        }

        sweep_x = static_cast<long double>(event.x);
        int node = predecessor_by_value(active, static_cast<long double>(event.y));
        if (node == 0) {
            answer[event.id] = 0;
            continue;
        }
        if (!upper_greater_than_y(node, event.x, event.y)) {
            int cur = node;
            for (int j = LOG - 1; j >= 0; --j) {
                int anc = up[j][cur];
                if (anc != 0 && !upper_greater_than_y(anc, event.x, event.y)) {
                    cur = anc;
                }
            }
            node = parent[cur];
        }
        answer[event.id] = node;
    }

    for (int i = 0; i < q; ++i) cout << answer[i] << '\n';
    return 0;
}
