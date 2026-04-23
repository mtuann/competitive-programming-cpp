// Problem: TFIELD - VOI 2015 Day 1 - Ruộng bậc thang
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/TFIELD/
// Topic: weighted sliding window after sorting nested polygons by area
// Idea: compute doubled polygon areas, sort by area, turn them into ring weights, then scan each color with two pointers

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct PolygonInfo {
    __int128 area2;
    int color;
};

static __int128 abs128(__int128 x) {
    return x >= 0 ? x : -x;
}

static void print_area2(__int128 value) {
    __int128 whole = value / 2;
    int half = (int)(value % 2);

    if (whole == 0) {
        cout << '0';
    } else {
        string digits;
        while (whole > 0) {
            digits.push_back(char('0' + whole % 10));
            whole /= 10;
        }
        reverse(digits.begin(), digits.end());
        cout << digits;
    }

    cout << '.' << (half ? '5' : '0') << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;
    cin >> m >> k;

    vector<PolygonInfo> polys(m);
    vector<int> colors_present;
    vector<int> seen(m + 1, 0);

    for (int i = 0; i < m; ++i) {
        int n, color;
        cin >> n >> color;
        polys[i].color = color;
        if (!seen[color]) {
            seen[color] = 1;
            colors_present.push_back(color);
        }

        vector<pair<long long, long long> > pt(n);
        for (int j = 0; j < n; ++j) {
            cin >> pt[j].first >> pt[j].second;
        }

        __int128 area2 = 0;
        for (int j = 0; j < n; ++j) {
            int nxt = (j + 1) % n;
            area2 += (__int128)pt[j].first * pt[nxt].second
                   - (__int128)pt[j].second * pt[nxt].first;
        }
        polys[i].area2 = abs128(area2);
    }

    sort(polys.begin(), polys.end(),
         [](const PolygonInfo& a, const PolygonInfo& b) {
             if (a.area2 != b.area2) return a.area2 < b.area2;
             return a.color < b.color;
         });

    vector<__int128> weight(m);
    vector<int> color(m);
    __int128 prev_area2 = 0;

    for (int i = 0; i < m; ++i) {
        weight[i] = polys[i].area2 - prev_area2;
        prev_area2 = polys[i].area2;
        color[i] = polys[i].color;
    }

    __int128 best = 0;

    for (int target_color : colors_present) {
        int left = 0;
        int changed = 0;
        __int128 sum = 0;

        for (int right = 0; right < m; ++right) {
            sum += weight[right];
            if (color[right] != target_color) ++changed;

            while (changed > k) {
                if (color[left] != target_color) --changed;
                sum -= weight[left];
                ++left;
            }

            if (sum > best) best = sum;
        }
    }

    print_area2(best);
    return 0;
}
