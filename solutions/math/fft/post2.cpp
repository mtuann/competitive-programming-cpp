// Problem: POST2 - A cộng B version 2
// Judge: VN SPOJ / VNOI
// Source URL: https://vn.spoj.com/problems/POST2/
// Topic: FFT, polynomial convolution
// Idea: count frequencies of A and B, convolve them, then sum the pair counts
// matching each value in C.

#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1.0);

static void fft(vector<cd>& a, bool invert) {
    int n = static_cast<int>(a.size());

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (int i = 0; i < n; ++i) a[i] /= n;
    }
}

static vector<long long> convolution(const vector<long long>& a,
                                     const vector<long long>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < static_cast<int>(a.size() + b.size() - 1)) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);

    vector<long long> result(a.size() + b.size() - 1);
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        result[i] = static_cast<long long>(llround(fa[i].real()));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int OFFSET = 50000;
    const int LIMIT = 100001;

    int n;
    cin >> n;

    vector<long long> freqA(LIMIT, 0), freqB(LIMIT, 0), freqC(LIMIT, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freqA[x + OFFSET];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freqB[x + OFFSET];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freqC[x + OFFSET];
    }

    vector<long long> ab = convolution(freqA, freqB);

    long long answer = 0;
    for (int value = -50000; value <= 50000; ++value) {
        answer += ab[value + 2 * OFFSET] * freqC[value + OFFSET];
    }

    cout << answer << '\n';
    return 0;
}
