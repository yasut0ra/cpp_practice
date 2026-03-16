#include <iostream>

using namespace std;

/*
    このファイルで学ぶこと:
      - 行列累乗
      - 繰り返し二乗法
      - Fibonacci を O(log n) で求める方法

    入力:
      n

    ミニ入力例:
      10

    ミニ出力例:
      fibonacci: 55
*/

using ll = long long;

struct Matrix {
    ll a00, a01, a10, a11;
};

Matrix multiply(const Matrix& x, const Matrix& y) {
    return {
        x.a00 * y.a00 + x.a01 * y.a10,
        x.a00 * y.a01 + x.a01 * y.a11,
        x.a10 * y.a00 + x.a11 * y.a10,
        x.a10 * y.a01 + x.a11 * y.a11
    };
}

Matrix power(Matrix base, long long exponent) {
    Matrix result = {1, 0, 0, 1};
    while (exponent > 0) {
        if (exponent & 1LL) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exponent >>= 1LL;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << "fibonacci: 0" << '\n';
        return 0;
    }

    Matrix fib = {1, 1, 1, 0};
    Matrix result = power(fib, n - 1);
    cout << "fibonacci: " << result.a00 << '\n';
    return 0;
}
