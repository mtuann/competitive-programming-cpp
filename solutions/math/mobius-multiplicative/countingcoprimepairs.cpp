#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> build_mobius(int n) {
    vector<int> mu(n + 1, 0);
    vector<int> lp(n + 1, 0);
    vector<int> primes;
    mu[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            long long v = 1LL * i * p;
            if (v > n) {
                break;
            }
            lp[v] = p;
            if (i % p == 0) {
                mu[v] = 0;
                break;
            }
            mu[v] = -mu[i];
        }
    }

    return mu;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> values(n);
    int max_v = 0;
    for (int& x : values) {
        cin >> x;
        max_v = max(max_v, x);
    }

    vector<int> freq(max_v + 1, 0);
    for (int x : values) {
        ++freq[x];
    }

    vector<int> mu = build_mobius(max_v);

    long long answer = 0;
    for (int d = 1; d <= max_v; ++d) {
        int divisible = 0;
        for (int multiple = d; multiple <= max_v; multiple += d) {
            divisible += freq[multiple];
        }
        answer += 1LL * mu[d] * divisible * (divisible - 1) / 2;
    }

    cout << answer << '\n';
    return 0;
}
