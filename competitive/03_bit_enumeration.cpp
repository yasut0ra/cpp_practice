#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - bit 全探索
      - 部分集合を整数の bit 列で表す方法
      - mask の i ビット目が立っていれば i 番目を採用する、という考え方

    図解:
      w = [6, 4, 5, 3], limit = 10 のとき、mask の i ビット目 = 「w[i] を選ぶか」:

        mask = 3 (2 進で 0011) の場合:
          i    :  3  2  1  0
          mask :  0  0  1  1
          w[i] :  3  5  4  6
                        ^  ^    ビットが 1 の w[1] と w[0] を選ぶ -> 4 + 6 = 10

        mask   binary   chosen        sum
           0   0000     {}              0
           1   0001     {0}             6
           2   0010     {1}             4
           3   0011     {0, 1}         10   limit 以下で最大
           4   0100     {2}             5
           5   0101     {0, 2}         11   limit 超え
          ..   ....     ...            ..
          15   1111     {0, 1, 2, 3}   18   limit 超え

        mask を 0 から 2^n - 1 まで数えるだけで、全部の選び方 (2^4 = 16 通り) をなめられる

    問題設定:
      重さの配列から、合計が limit 以下になるようにいくつか選ぶ。
      その中で合計を最大にする。

    入力:
      n limit
      w0 w1 ... w(n-1)

    ミニ入力例:
      4 10
      6 4 5 3

    ミニ出力例:
      best_sum: 10
      chosen_indices: 0 1

    注意:
      - 計算量は O(2^n * n)
      - だいたい n <= 20 くらいまでが目安
*/

int main() {
    int n;
    long long limit;
    cin >> n >> limit;

    vector<long long> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    long long best_sum = 0;
    long long best_mask = 0;

    for (long long mask = 0; mask < (1LL << n); ++mask) {
        long long total = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1LL << i)) {
                total += weight[i];
            }
        }

        if (total <= limit && total > best_sum) {
            best_sum = total;
            best_mask = mask;
        }
    }

    cout << "best_sum: " << best_sum << '\n';
    cout << "chosen_indices:";
    for (int i = 0; i < n; ++i) {
        if (best_mask & (1LL << i)) {
            cout << ' ' << i;
        }
    }
    cout << '\n';
    return 0;
}
