#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, epochs;
    long double alpha;
    if (!(cin >> n >> alpha >> epochs)) {
        return 0;
    }

    vector<long double> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }

    long double w = 0.0L;
    long double b = 0.0L;
    if (n > 0) {
        const long double inv_n = 1.0L / static_cast<long double>(n);
        for (int epoch = 0; epoch < epochs; ++epoch) {
            long double dw = 0.0L;
            long double db = 0.0L;
            for (int i = 0; i < n; ++i) {
                const long double pred = w * xs[i] + b;
                const long double err = pred - ys[i];
                dw += err * xs[i];
                db += err;
            }
            dw *= inv_n;
            db *= inv_n;
            w -= alpha * dw;
            b -= alpha * db;
        }
    }

    cout << fixed << setprecision(10) << w << ' ' << b << '\n';
    return 0;
}
