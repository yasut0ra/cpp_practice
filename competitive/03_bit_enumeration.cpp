#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - bit 全探索
      - 部分集合を整数の bit 列で表す方法
      - mask の i ビット目が立っていれば i 番目を採用する、という考え方

    問題設定:
      重さの配列から、合計が limit 以下になるようにいくつか選ぶ。
      その中で合計を最大にする。

    入力:
      n limit
      w0 w1 ... w(n-1)

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
