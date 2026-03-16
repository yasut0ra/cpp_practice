#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 手書き二分探索
      - lower_bound の意味
      - 「ok は常に条件を満たす」「ng は常に条件を満たさない」という不変条件

    直感メモ:
      - 白黒に塗られた列の「境界線」を探すイメージ
      - 毎回まんなかを見るので、候補が半分ずつ減っていく

    入力:
      n x
      昇順にソート済みの配列 a

    出力:
      x 以上の最初の位置

    ミニ入力例:
      5 6
      1 3 6 8 10

    ミニ出力例:
      first_index: 2
      value: 6
      lower_bound_index: 2

    注意:
      - 二分探索は、対象の配列が単調性を持っていることが前提
      - 迷ったら「ok 側は正しい、ng 側はまだダメ」を声に出して追う
*/

int first_greater_equal(const vector<int>& a, int x) {
    // ng は「条件を満たさない」ことが確定している位置。
    int ng = -1;

    // ok は「条件を満たす」ことが確定している位置。
    // 配列外の a.size() を仮想的な番兵として使う。
    int ok = static_cast<int>(a.size());

    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        // mid が条件を満たすなら、境界線は mid より左側にもありうる。
        if (a[mid] >= x) {
            ok = mid;
        } else {
            // mid がダメなら、境界線は mid より右側にある。
            ng = mid;
        }
    }

    return ok;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int index = first_greater_equal(a, x);
    int stl_index = static_cast<int>(lower_bound(a.begin(), a.end(), x) - a.begin());

    if (index == n) {
        cout << "first_index: not_found" << '\n';
    } else {
        cout << "first_index: " << index << '\n';
        cout << "value: " << a[index] << '\n';
    }

    cout << "lower_bound_index: " << stl_index << '\n';
    return 0;
}
