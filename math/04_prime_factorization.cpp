#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 素因数分解
      - 何回割れるかを数えて指数にする方法

    入力:
      x

    ミニ入力例:
      360

    ミニ出力例:
      prime_factors:
      2^3
      3^2
      5^1
*/

int main() {
    long long x;
    cin >> x;

    vector<pair<long long, int>> factors;
    for (long long p = 2; p * p <= x; ++p) {
        if (x % p != 0) {
            continue;
        }

        int exponent = 0;
        while (x % p == 0) {
            x /= p;
            ++exponent;
        }
        factors.push_back({p, exponent});
    }

    if (x > 1) {
        factors.push_back({x, 1});
    }

    cout << "prime_factors:" << '\n';
    for (const auto& [prime, exponent] : factors) {
        cout << prime << '^' << exponent << '\n';
    }
    return 0;
}
