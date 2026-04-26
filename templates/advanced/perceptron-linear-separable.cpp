// Template: Perceptron for linearly separable binary classification.
// Signal: one binary linear classifier with labels -1/+1, deterministic example
// order, and online updates only on mistakes.
// Assumes: the training data is linearly separable, so one full pass with no
// mistakes is a meaningful stopping condition for this first route.
// Exposes: PerceptronModel, train_perceptron_separable(), and predict().
// Complexity: O(P * n * d) if convergence takes P full passes.
// Main trap: forgetting the bias update, or silently applying this first route
// to nonseparable data and expecting convergence.
// Links:
//   Topic: topics/advanced/machine-learning-algorithms/README.md
//   Note: practice/ladders/advanced/machine-learning-algorithms/perceptronclassification.md

#include <cassert>
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
    assert(static_cast<int>(ys.size()) == n);

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
    vector<vector<long long>> xs = {
        {2, 1},
        {1, 2},
        {-1, -2},
        {-2, -1},
    };
    vector<int> ys = {1, 1, -1, -1};

    PerceptronModel model(2);
    const bool ok = train_perceptron_separable(xs, ys, model);
    cout << (ok ? "CONVERGED" : "FAILED") << '\n';

    vector<vector<long long>> queries = {
        {3, 1},
        {-1, -3},
    };
    for (const auto& q : queries) {
        cout << model.predict(q) << '\n';
    }
    return 0;
}
