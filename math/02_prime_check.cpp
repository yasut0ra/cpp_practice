#include <iostream>

using namespace std;

/*
    このファイルで学ぶこと:
      - 素数判定
      - sqrt(x) まで調べれば十分な理由
      - 合成数なら約数が見つかること

    図解:
      21 の約数はペアで現れる:
         1 x 21
         3 x  7
        -------- sqrt(21) = 4.58...
         7 x  3    (ここから先は左右が入れ替わっただけ)
        21 x  1
      ペアの小さいほうは必ず sqrt(x) 以下にあるので、d * d <= x の範囲だけ調べればよい

        d = 2 : 21 % 2 = 1
        d = 3 : 21 % 3 = 0 -> 割り切れたので合成数 (first_divisor = 3)

    入力:
      x

    ミニ入力例:
      21

    ミニ出力例:
      is_prime: false
      first_divisor: 3
*/

int main() {
    long long x;
    cin >> x;

    if (x <= 1) {
        cout << "is_prime: false" << '\n';
        cout << "first_divisor: -1" << '\n';
        return 0;
    }

    long long divisor = -1;
    for (long long d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            divisor = d;
            break;
        }
    }

    cout << "is_prime: " << (divisor == -1 ? "true" : "false") << '\n';
    cout << "first_divisor: " << divisor << '\n';
    return 0;
}
