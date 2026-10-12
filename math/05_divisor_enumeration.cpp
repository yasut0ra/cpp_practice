#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 約数列挙
      - 約数がペアで現れること
      - sqrt(x) まで見ればよい理由

    図解:
      d を 1 から sqrt(12) = 3.46... まで動かすと、ペアの相手 12 / d も同時に見つかる:

        1    2    3    :    4    6    12
        |    |    |    :    |    |    |
        |    |    +---------+    |    |
        |    +-------------------+    |
        +-----------------------------+
                    sqrt(12)

        d = 1 : 1 と 12 を追加
        d = 2 : 2 と  6 を追加
        d = 3 : 3 と  4 を追加
        d = 4 : 4 * 4 = 16 > 12 なので終了
        見つかった順 1 12 2 6 3 4 を sort して 1 2 3 4 6 12

      x = 16 の 4 のように d * d == x のときは、同じ数を 2 回入れないよう 1 回だけ追加する

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
