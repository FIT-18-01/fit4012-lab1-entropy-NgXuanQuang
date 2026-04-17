#include <iostream>

using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int main() {
    int pairs[][2] = {{3, 7}, {10, 17}, {6, 9}};
    for (auto p : pairs) {
        int res = mod_inverse(p[0], p[1]);
        if (res != -1) cout << p[0] << " mod " << p[1] << " = " << res << endl;
        else cout << p[0] << " mod " << p[1] << " : No inverse" << endl;
    }
    return 0;
}