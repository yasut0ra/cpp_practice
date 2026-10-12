#include <iostream>

using namespace std;

/*
    このファイルで学ぶこと:
      - mod inverse
      - 拡張 Euclid の互除法
      - 逆元が存在する条件

    図解:
      3 * x を 11 で割ると 1 余る x を探したい
      = 3x + 11y = 1 を満たす整数 (x, y) の x を探せばよい

      行き: (a, b) -> (b, a % b) と互除法で小さくする
        (3, 11) -> (11, 3) -> (3, 2) -> (2, 1) -> (1, 0)   b = 0 になったので gcd = 1

      帰り: 下から x = next_y, y = next_x - (a / b) * next_y で組み立てる
        (a, b)      x    y    a*x + b*y
        (1, 0)      1    0    1*1  + 0*0     = 1
        (2, 1)      0    1    2*0  + 1*1     = 1
        (3, 2)      1   -1    3*1  + 2*(-1)  = 1
        (11, 3)    -1    4    11*(-1) + 3*4  = 1
        (3, 11)     4   -1    3*4  + 11*(-1) = 1    <- x = 4 が逆元

        3 * 4 = 12 = 11 + 1 なので、mod 11 で 3 * 4 は 1
        (x が負になったときは m を足して 0..m-1 に直す)

    入力:
      a m

    ミニ入力例:
      3 11

    ミニ出力例:
      gcd: 1
      mod_inverse: 4
*/

long long extended_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long next_x, next_y;
    long long g = extended_gcd(b, a % b, next_x, next_y);
    x = next_y;
    y = next_x - (a / b) * next_y;
    return g;
}

int main() {
    long long a, m;
    cin >> a >> m;

    long long x, y;
    long long g = extended_gcd(a, m, x, y);

    cout << "gcd: " << g << '\n';
    if (g != 1) {
        cout << "mod_inverse: does_not_exist" << '\n';
    } else {
        long long inverse = (x % m + m) % m;
        cout << "mod_inverse: " << inverse << '\n';
    }
    return 0;
}
