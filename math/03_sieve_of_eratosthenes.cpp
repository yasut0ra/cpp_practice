#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - エラトステネスのふるい
      - 1 から n までの素数をまとめて求める方法

    図解:
      n = 20 (. は消された数):

      はじめ: 1 は素数ではないので最初に消す
          .  2  3  4  5  6  7  8  9 10
         11 12 13 14 15 16 17 18 19 20

      p = 2: 2 * 2 = 4 から 2 おきに消す
          .  2  3  .  5  .  7  .  9  .
         11  . 13  . 15  . 17  . 19  .

      p = 3: 3 * 3 = 9 から 3 おきに消す (12, 18 はもう消えている)
          .  2  3  .  5  .  7  .  .  .
         11  . 13  .  .  . 17  . 19  .

      p = 4: すでに消されているのでスキップ
      p = 5: 5 * 5 = 25 > 20 なのでここで終了
      残った数: 2 3 5 7 11 13 17 19

      p * p から始めてよいのは、それより小さい p の倍数は、もっと小さい素数で消し済みだから

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
