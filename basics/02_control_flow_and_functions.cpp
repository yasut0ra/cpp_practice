#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - if / else
      - for 文、range-based for、while 文
      - 関数に処理を切り出す書き方

    入力:
      n
      a0 a1 ... a(n-1)

    出力:
      合計、正の数の個数、最初の要素の符号、最初の正の値の位置など

    ミニ入力例:
      5
      -2 4 0 7 -1

    ミニ出力例:
      sum: 8
      positive_count: 2
      first_value_sign: -1
      first_positive_index: 1
      factorial(min(n, 10)): 120

    見てほしいポイント:
      - 役割ごとに関数を分けると main が読みやすくなる
      - while は「条件を満たすまで進める」ときに使いやすい
*/

int sign_of(int x) {
    if (x > 0) {
        return 1;
    }
    if (x < 0) {
        return -1;
    }
    return 0;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum = 0;
    int positive_count = 0;

    // range-based for は「全要素を順番に見る」用途に向いている。
    for (int x : a) {
        sum += x;
        if (x > 0) {
            ++positive_count;
        }
    }

    // while は「条件に合う位置が見つかるまで進める」形と相性が良い。
    int first_positive_index = -1;
    int index = 0;
    while (index < n) {
        if (a[index] > 0) {
            first_positive_index = index;
            break;
        }
        ++index;
    }

    cout << "sum: " << sum << '\n';
    cout << "positive_count: " << positive_count << '\n';

    if (n == 0) {
        cout << "first_value_sign: array_is_empty" << '\n';
    } else {
        cout << "first_value_sign: " << sign_of(a[0]) << '\n';
    }

    cout << "first_positive_index: " << first_positive_index << '\n';

    // 階乗はすぐ大きくなるので、ここでは 10 までに制限している。
    cout << "factorial(min(n, 10)): " << factorial(min(n, 10)) << '\n';
    return 0;
}
