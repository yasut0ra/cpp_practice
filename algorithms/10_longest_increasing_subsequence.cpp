#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - LIS (Longest Increasing Subsequence)
      - O(n log n) 解法
      - 長さだけでなく実際の部分列を復元する方法

    直感メモ:
      - 長さ k の増加列の「最後の値」は、できるだけ小さいほうが得
      - 末尾が小さいほど、その先に続けやすい

    図解:
      a = [1, 4, 2, 3, 5] を左から見て、dp (長さごとの最小の末尾) を更新する:

        i  a[i]  dp
        0    1   [1]            末尾に追加
        1    4   [1, 4]         末尾に追加
        2    2   [1, 2]         4 を 2 に置き換え (長さ 2 の末尾は小さいほうが得)
        3    3   [1, 2, 3]      末尾に追加 (4 のままだったら 3 は続けられなかった)
        4    5   [1, 2, 3, 5]   末尾に追加 -> 長さ 4

      復元 (prev_index で 1 つ前の要素をたどる):
        5 (i=4) -> 3 (i=3) -> 2 (i=2) -> 1 (i=0)  => 逆順にして 1 2 3 5

    入力:
      n
      a0 a1 ... a(n-1)

    出力:
      LIS の長さ
      復元した 1 つの LIS

    ミニ入力例:
      5
      1 4 2 3 5

    ミニ出力例:
      length: 4
      sequence: 1 2 3 5

    補足:
      - strictly increasing を求めている
      - non-decreasing にしたいなら lower_bound / upper_bound を見直す

    つまずきやすい点:
      - dp 配列そのものが LIS 本体ではない
      - dp は「各長さの最良の末尾」を持つ補助配列
*/

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp;
    vector<int> dp_index;
    vector<int> prev_index(n, -1);

    for (int i = 0; i < n; ++i) {
        int pos = static_cast<int>(lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin());

        if (pos == static_cast<int>(dp.size())) {
            dp.push_back(a[i]);
            dp_index.push_back(i);
        } else {
            // 同じ長さを作れるなら、末尾はより小さい値で置き換えたほうが有利。
            dp[pos] = a[i];
            dp_index[pos] = i;
        }

        if (pos > 0) {
            prev_index[i] = dp_index[pos - 1];
        }
    }

    vector<int> lis;
    int current = dp_index.back();
    while (current != -1) {
        lis.push_back(a[current]);
        current = prev_index[current];
    }
    reverse(lis.begin(), lis.end());

    cout << "length: " << lis.size() << '\n';
    cout << "sequence:";
    for (int x : lis) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}
