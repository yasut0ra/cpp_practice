#include <iostream>
#include <numeric>

using namespace std;

/*
    このファイルで学ぶこと:
      - gcd
      - lcm
      - ユークリッドの互除法が何に使われるか

    図解:
      ユークリッドの互除法: gcd(a, b) = gcd(b, a % b) を b が 0 になるまで繰り返す
        gcd(12, 18)
        = gcd(18, 12)    12 % 18 = 12
        = gcd(12,  6)    18 % 12 = 6
        = gcd( 6,  0)    12 %  6 = 0  -> 答え 6

      図で見ると: 18 x 12 の長方形を、できるだけ大きい正方形で切り取っていく
        +------------+------+
        |            |      |
        |            | 6x6  |
        |   12x12    |      |
        |            +------+
        |            |      |
        |            | 6x6  |
        |            |      |
        +------------+------+
        余りなく敷き詰められた最後の正方形の一辺 6 が gcd

      lcm = a / gcd * b = 12 / 6 * 18 = 36   (先に割ると a * b のオーバーフローを避けやすい)

    入力:
      a b

    ミニ入力例:
      12 18

    ミニ出力例:
      gcd: 6
      lcm: 36
*/

int main() {
    long long a, b;
    cin >> a >> b;

    long long g = gcd(a, b);
    long long l = a / g * b;

    cout << "gcd: " << g << '\n';
    cout << "lcm: " << l << '\n';
    return 0;
}
