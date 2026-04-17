#include <iostream>
using namespace std;

// Hàm tính gcd (Euclid thường)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Euclid mở rộng
int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

// Hàm tìm nghịch đảo modulo
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);

    // Không tồn tại nghịch đảo
    if (g != 1) {
        return -1;
    }

    // Chuẩn hóa kết quả về [0, m-1]
    return (x % m + m) % m;
}

int main() {
    int a, m;
    cout << "Nhap a, m: ";
    cin >> a >> m;

    // Kiểm tra điều kiện tồn tại
    if (gcd(a, m) != 1) {
        cout << "Khong ton tai nghich dao modulo vi gcd(a, m) != 1.\n";
        return 0;
    }

    int inv = mod_inverse(a, m);

    cout << "Nghich dao cua " << a << " mod " << m << " la: " << inv << endl;

    // Kiểm tra lại
    cout << "Kiem tra: " << a << " * " << inv << " % " << m
         << " = " << (1LL * a * inv % m) << endl;

    return 0;
}