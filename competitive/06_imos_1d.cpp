#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - いもす法 (差分配列)
      - 区間加算をまとめて処理する方法

    問題設定:
      長さ n の配列が 0 で初期化されている。
      q 個の区間 [l, r) に x を加える。
      最終的な配列を求める。

    入力:
      n q
      l r x   (q 個)

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
        diff[l] += x;
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
