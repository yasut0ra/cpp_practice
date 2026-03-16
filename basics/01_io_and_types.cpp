#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/*
    このファイルで学ぶこと:
      - cin / cout による基本入出力
      - int, long long, double, bool, string の使い分け
      - 1LL を使った型の持ち上げ

    入力:
      a b name

    ミニ入力例:
      3 5 Taro

    ミニ出力例:
      name: Taro
      sum: 8
      diff: -2
      product: 15
      average: 4.0
      a_is_even: false

    見てほしいポイント:
      - product は int ではなく long long で受けている
      - average は 2.0 で割って小数にしている
      - bool はそのままだと 0/1 なので、三項演算子で文字列にしている
*/

int main() {
    int a, b;
    string name;
    cin >> a >> b >> name;

    // 1LL を掛けると式全体が long long として計算される。
    long long product = 1LL * a * b;

    // 2.0 で割ることで、整数除算ではなく実数の計算になる。
    double average = (a + b) / 2.0;

    bool is_a_even = (a % 2 == 0);

    cout << "name: " << name << '\n';
    cout << "sum: " << a + b << '\n';
    cout << "diff: " << a - b << '\n';
    cout << "product: " << product << '\n';

    // fixed と setprecision(1) で小数点以下 1 桁固定表示にする。
    cout << fixed << setprecision(1);
    cout << "average: " << average << '\n';

    cout << "a_is_even: " << (is_a_even ? "true" : "false") << '\n';
    return 0;
}
