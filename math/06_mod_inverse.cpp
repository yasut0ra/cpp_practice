#include <iostream>

using namespace std;

/*
    このファイルで学ぶこと:
      - mod inverse
      - 拡張 Euclid の互除法
      - 逆元が存在する条件

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
