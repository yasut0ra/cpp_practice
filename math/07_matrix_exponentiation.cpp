#include <iostream>

using namespace std;

/*
    このファイルで学ぶこと:
      - 行列累乗
      - 繰り返し二乗法
      - Fibonacci を O(log n) で求める方法

    図解:
      Fibonacci の 1 ステップを行列で書く:
        | F(k+1) |   | 1  1 |   | F(k)   |
        | F(k)   | = | 1  0 | x | F(k-1) |

      M = | 1  1 |  とおくと、M^(n-1) の左上が F(n)
          | 1  0 |

      n = 10: M^9 を繰り返し二乗法で求める (9 = 1001 (2 進))
        bit    :      0      1      2      3
        9      :      1      0      0      1
        base   :    M^1    M^2    M^4    M^8    base は毎回 2 乗
        result :    M^1    M^1    M^1    M^9    ビットが 1 のときだけ掛ける

        M^9 = | 55  34 |   -> 左上の 55 が F(10)
              | 34  21 |
        9 回掛ける代わりに、約 log2(9) 回のループで済む

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
