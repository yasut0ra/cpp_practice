#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - エラトステネスのふるい
      - 1 から n までの素数をまとめて求める方法

    入力:
      n

    ミニ入力例:
      20

    ミニ出力例:
      primes: 2 3 5 7 11 13 17 19
*/

int main() {
    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    if (n >= 0) {
        is_prime[0] = false;
    }
    if (n >= 1) {
        is_prime[1] = false;
    }

    for (int p = 2; p * p <= n; ++p) {
        if (!is_prime[p]) {
            continue;
        }
        for (int multiple = p * p; multiple <= n; multiple += p) {
            is_prime[multiple] = false;
        }
    }

    cout << "primes:";
    for (int x = 2; x <= n; ++x) {
        if (is_prime[x]) {
            cout << ' ' << x;
        }
    }
    cout << '\n';
    return 0;
}
