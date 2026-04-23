// Template: iterative FFT-based convolution.

#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

const double PI = acos(-1.0);

void fft(vector<complex<double>> &a, bool invert) {
    int n = static_cast<int>(a.size());
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        complex<double> wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; ++j) {
                complex<double> u = a[i + j];
                complex<double> v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (complex<double> &x : a) {
            x /= n;
        }
    }
}

vector<long long> convolution(const vector<int> &a, const vector<int> &b) {
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < static_cast<int>(a.size() + b.size() - 1)) {
        n <<= 1;
    }
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }
    fft(fa, true);

    vector<long long> result(a.size() + b.size() - 1);
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        result[i] = llround(fa[i].real());
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5};
    vector<long long> c = convolution(a, b);
    for (long long x : c) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
