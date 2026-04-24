// Use when: solving ax + by = c or needing Bezout coefficients.
// Invariant: returned g is gcd(|a|, |b|); if solvable, (x, y) satisfies ax + by = c.
// Complexity: O(log(min(|a|, |b|))).

#include <cstdlib>

using namespace std;

long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1 = 0, y1 = 0;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool find_any_diophantine(long long a, long long b, long long c,
                          long long &x, long long &y, long long &g) {
    if (a == 0 && b == 0) {
        if (c != 0) return false;
        x = y = g = 0;
        return true;
    }
    long long x0 = 0, y0 = 0;
    g = ext_gcd(llabs(a), llabs(b), x0, y0);
    if (c % g != 0) return false;
    x = x0 * (c / g);
    y = y0 * (c / g);
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

void shift_solution(long long &x, long long &y,
                    long long a_div_g, long long b_div_g, long long t) {
    x += t * b_div_g;
    y -= t * a_div_g;
}
