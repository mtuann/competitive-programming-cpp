// Template: Li Chao tree (minimum)
// Signal: the transition becomes min_j(m_j * x_i + b_j), with online line insertion
// and online point queries over a known integer x-domain.
// Assumes: lines are active on the full domain [x_low, x_high]; this starter is minimum-only.
// Querying before adding any line returns +INF, so treat an empty structure explicitly if that case matters.
// Exposes: LiChaoMin(x_low, x_high), add_line(m, b), and query(x).
// Complexity: O(log C) per add/query, where C = x_high - x_low + 1.
// Main trap: using Li Chao before checking for a lighter monotone-hull route, or forgetting
// that the x-domain must cover every query point.
// Links:
//   Topic: topics/dp/cht-li-chao/README.md
//   Note: practice/ladders/dp/cht-li-chao/monstergame2.md

#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <limits>

using namespace std;

struct LiChaoMin {
    struct Line {
        long long m = 0;
        long long b = 0;
        bool empty = true;

        __int128 eval(long long x) const {
            return static_cast<__int128>(m) * x + b;
        }
    };

    struct Node {
        Line line;
        int left = -1;
        int right = -1;
    };

    static constexpr __int128 INF128 = (static_cast<__int128>(1) << 120);
    static constexpr long long INF = numeric_limits<long long>::max();

    long long x_low;
    long long x_high;
    deque<Node> nodes;

    LiChaoMin(long long x_low, long long x_high) : x_low(x_low), x_high(x_high) {
        nodes.push_back(Node());
    }

    void add_line(long long m, long long b) {
        Line line;
        line.m = m;
        line.b = b;
        line.empty = false;
        add_line(0, x_low, x_high, line);
    }

    long long query(long long x) const {
        __int128 ans = query(0, x_low, x_high, x);
        return ans >= INF128 / 2 ? INF : static_cast<long long>(ans);
    }

private:
    int new_node() {
        nodes.push_back(Node());
        return static_cast<int>(nodes.size()) - 1;
    }

    void add_line(int idx, long long l, long long r, Line line) {
        Node& node = nodes[idx];
        if (node.line.empty) {
            node.line = line;
            return;
        }

        long long mid = l + (r - l) / 2;
        bool left_better = line.eval(l) < node.line.eval(l);
        bool mid_better = line.eval(mid) < node.line.eval(mid);

        if (mid_better) {
            swap(line, node.line);
        }
        if (l == r || line.empty) {
            return;
        }

        if (left_better != mid_better) {
            if (node.left == -1) {
                node.left = new_node();
            }
            add_line(node.left, l, mid, line);
        } else {
            if (node.right == -1) {
                node.right = new_node();
            }
            add_line(node.right, mid + 1, r, line);
        }
    }

    __int128 query(int idx, long long l, long long r, long long x) const {
        if (idx == -1) {
            return INF128;
        }
        const Node& node = nodes[idx];
        __int128 ans = node.line.empty ? INF128 : node.line.eval(x);
        if (l == r) {
            return ans;
        }
        long long mid = l + (r - l) / 2;
        if (x <= mid) {
            return min(ans, query(node.left, l, mid, x));
        }
        return min(ans, query(node.right, mid + 1, r, x));
    }
};

int main() {
    LiChaoMin hull(-10, 10);
    hull.add_line(2, 3);    // y = 2x + 3
    hull.add_line(-1, 10);  // y = -x + 10
    cout << hull.query(4) << '\n';  // min(11, 6) = 6
    return 0;
}
