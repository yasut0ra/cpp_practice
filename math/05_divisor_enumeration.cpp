#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 約数列挙
      - 約数がペアで現れること
      - sqrt(x) まで見ればよい理由

    入力:
      x

    ミニ入力例:
      12

    ミニ出力例:
      divisors: 1 2 3 4 6 12
*/

int main() {
    long long x;
    cin >> x;

    vector<long long> divisors;
    for (long long d = 1; d * d <= x; ++d) {
        if (x % d != 0) {
            continue;
        }
        divisors.push_back(d);
        if (d * d != x) {
            divisors.push_back(x / d);
        }
    }

    sort(divisors.begin(), divisors.end());

    cout << "divisors:";
    for (long long d : divisors) {
        cout << ' ' << d;
    }
    cout << '\n';
    return 0;
}
