#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - しゃくとり法
      - 左端と右端を動かして条件を保つ方法

    直感メモ:
      - 右端で条件を満たすまで伸ばし、左端で無駄を削る
      - 1 つの区間を少しずつスライドさせるイメージ

    図解:
      a = [2, 1, 5, 2, 3], target = 7。[ ] が各 left での区間 [left, right):

        index  :  0  1  2  3  4
        a      :  2  1  5  2  3
        left 0 : [2  1  5]         sum 8 >= 7   長さ 3
        left 1 :    [1  5  2]      sum 8 >= 7   長さ 3
        left 2 :       [5  2]      sum 7 >= 7   長さ 2  <- 最短
        left 3 :          [2  3]   sum 5 <  7   右端がもう伸ばせない
        left 4 :             [3]   sum 3 <  7

      left も right も戻らずに右へ進むだけなので、全体で O(n)

    問題設定:
      正の整数列 a と target が与えられる。
      和が target 以上になる最短部分配列の長さを求める。

    入力:
      n target
      a0 a1 ... a(n-1)

    ミニ入力例:
      5 7
      2 1 5 2 3

    ミニ出力例:
      minimum_length: 2
      best_range: [2, 4)

    重要:
      - この実装は「要素がすべて正」のときに使える
      - 負の値が混ざると、右端を進めたときに和が単調に増えない
*/

int main() {
    int n;
    long long target;
    cin >> n >> target;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum = 0;
    int right = 0;
    int best_length = n + 1;
    int best_left = -1;
    int best_right = -1;

    for (int left = 0; left < n; ++left) {
        while (right < n && sum < target) {
            sum += a[right];
            ++right;
        }

        if (sum >= target && right - left < best_length) {
            best_length = right - left;
            best_left = left;
            best_right = right;
        }

        // 左端を 1 つ捨てて、次の区間へ進む。
        sum -= a[left];
    }

    if (best_length == n + 1) {
        cout << "minimum_length: 0" << '\n';
    } else {
        cout << "minimum_length: " << best_length << '\n';
        cout << "best_range: [" << best_left << ", " << best_right << ")" << '\n';
    }
    return 0;
}
