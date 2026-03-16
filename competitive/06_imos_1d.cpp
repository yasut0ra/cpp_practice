#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - いもす法 (差分配列)
      - 区間加算をまとめて処理する方法

    直感メモ:
      - 区間全体に配る代わりに、「ここから増える」「ここで増加終了」という付箋だけ貼る
      - 最後に左から累積すると、本当に足したかった配列が復元される

    問題設定:
      長さ n の配列が 0 で初期化されている。
      q 個の区間 [l, r) に x を加える。
      最終的な配列を求める。

    入力:
      n q
      l r x   (q 個)

    ミニ入力例:
      5 3
      0 3 2
      1 5 1
      2 4 3

    ミニ出力例:
      result: 2 3 6 4 1

    計算量:
      O(n + q)

    発想:
      - 各区間に直接足すと O(nq)
      - 代わりに「始点で +x, 終点で -x」を記録し、最後に累積する
*/

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> diff(n + 1, 0);

    for (int i = 0; i < q; ++i) {
        int l, r;
        long long x;
        cin >> l >> r >> x;

        // 区間の始まりで増やし、
        diff[l] += x;
        // 区間の終わりで元に戻す。
        diff[r] -= x;
    }

    vector<long long> result(n, 0);
    long long current = 0;
    for (int i = 0; i < n; ++i) {
        current += diff[i];
        result[i] = current;
    }

    cout << "result:";
    for (long long x : result) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}
