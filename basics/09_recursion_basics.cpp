#include <iostream>

using namespace std;

/*
    このファイルで学ぶこと:
      - 再帰関数の基本形
      - base case
      - 「少し小さい問題」に分ける発想

    入力:
      n

    ミニ入力例:
      5

    ミニ出力例:
      sum_to_n: 15
      factorial: 120
*/

long long sum_to_n(int n) {
    if (n == 0) {
        return 0;
    }
    return sum_to_n(n - 1) + n;
}

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int main() {
    int n;
    cin >> n;

    cout << "sum_to_n: " << sum_to_n(n) << '\n';
    cout << "factorial: " << factorial(n) << '\n';
    return 0;
}
