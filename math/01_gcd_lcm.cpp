#include <iostream>
#include <numeric>

using namespace std;

/*
    このファイルで学ぶこと:
      - gcd
      - lcm
      - ユークリッドの互除法が何に使われるか

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
