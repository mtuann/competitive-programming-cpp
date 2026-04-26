// Template: batch gradient descent for one-feature linear regression.
// Signal: one smooth loss, one affine predictor wx + b, and the whole lesson is
// the deterministic gradient update loop.
// Assumes: squared loss, fixed learning rate, fixed epoch count.
// Exposes: train_linear_regression_1d_batch_gd() and mse_cost().
// Complexity: O(epochs * n).
// Main trap: updating in the +gradient direction, or forgetting the bias term.
// Links:
//   Topic: topics/advanced/gradient-descent/README.md
//   Note: practice/ladders/advanced/gradient-descent/linearregressiongd.md

#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct LinearRegression1DState {
    long double w = 0.0L;
    long double b = 0.0L;
};

long double mse_cost(const vector<long double>& xs, const vector<long double>& ys,
                     const LinearRegression1DState& state) {
    assert(xs.size() == ys.size());
    if (xs.empty()) {
        return 0.0L;
    }
    long double sum = 0.0L;
    for (size_t i = 0; i < xs.size(); ++i) {
        const long double err = state.w * xs[i] + state.b - ys[i];
        sum += err * err;
    }
    return sum / (2.0L * static_cast<long double>(xs.size()));
}

LinearRegression1DState train_linear_regression_1d_batch_gd(
    const vector<long double>& xs, const vector<long double>& ys,
    long double alpha, int epochs) {
    assert(xs.size() == ys.size());
    assert(alpha > 0.0L);
    assert(epochs >= 0);

    LinearRegression1DState state;
    if (xs.empty()) {
        return state;
    }

    const long double inv_n = 1.0L / static_cast<long double>(xs.size());
    for (int epoch = 0; epoch < epochs; ++epoch) {
        long double dw = 0.0L;
        long double db = 0.0L;
        for (size_t i = 0; i < xs.size(); ++i) {
            const long double pred = state.w * xs[i] + state.b;
            const long double err = pred - ys[i];
            dw += err * xs[i];
            db += err;
        }
        dw *= inv_n;
        db *= inv_n;
        state.w -= alpha * dw;
        state.b -= alpha * db;
    }
    return state;
}

int main() {
    vector<long double> xs = {0.0L, 1.0L, 2.0L, 3.0L};
    vector<long double> ys = {1.0L, 3.0L, 5.0L, 7.0L};

    const LinearRegression1DState state =
        train_linear_regression_1d_batch_gd(xs, ys, 0.05L, 200);

    cout << fixed << setprecision(10);
    cout << state.w << ' ' << state.b << '\n';
    cout << mse_cost(xs, ys, state) << '\n';
    return 0;
}
