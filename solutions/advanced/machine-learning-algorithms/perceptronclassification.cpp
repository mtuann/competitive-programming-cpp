#include <iostream>
#include <vector>

using namespace std;

struct PerceptronModel {
    vector<long long> w;
    long long b = 0;

    explicit PerceptronModel(int d = 0) : w(d, 0), b(0) {}

    long long score(const vector<long long>& x) const {
        long long s = b;
        for (int j = 0; j < static_cast<int>(w.size()); ++j) {
            s += w[j] * x[j];
        }
        return s;
    }

    int predict(const vector<long long>& x) const {
        return score(x) >= 0 ? 1 : -1;
    }
};

bool train_perceptron_separable(const vector<vector<long long>>& xs,
                                const vector<int>& ys,
                                PerceptronModel& model,
                                long long max_updates = 1000000) {
    const int n = static_cast<int>(xs.size());
    const int d = static_cast<int>(model.w.size());

    long long updates = 0;
    while (updates <= max_updates) {
        bool changed = false;
        for (int i = 0; i < n; ++i) {
            long long margin = static_cast<long long>(ys[i]) * model.score(xs[i]);
            if (margin <= 0) {
                changed = true;
                model.b += ys[i];
                for (int j = 0; j < d; ++j) {
                    model.w[j] += static_cast<long long>(ys[i]) * xs[i][j];
                }
                ++updates;
                if (updates > max_updates) {
                    return false;
                }
            }
        }
        if (!changed) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, q;
    if (!(cin >> n >> d >> q)) {
        return 0;
    }

    vector<vector<long long>> xs(n, vector<long long>(d));
    vector<int> ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> ys[i];
        for (int j = 0; j < d; ++j) {
            cin >> xs[i][j];
        }
    }

    PerceptronModel model(d);
    const bool ok = train_perceptron_separable(xs, ys, model);
    if (!ok) {
        cout << "FAILED\n";
        return 0;
    }

    while (q--) {
        vector<long long> x(d);
        for (int j = 0; j < d; ++j) {
            cin >> x[j];
        }
        cout << model.predict(x) << '\n';
    }
    return 0;
}
