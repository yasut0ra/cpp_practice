#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 手書き二分探索
      - lower_bound の意味
      - 「ok は常に条件を満たす」「ng は常に条件を満たさない」という不変条件

    入力:
      n x
      昇順にソート済みの配列 a

    出力:
      x 以上の最初の位置

    注意:
      - 二分探索は、対象の配列が単調性を持っていることが前提
*/

int first_greater_equal(const vector<int>& a, int x) {
    // ng は「条件を満たさない」ことが確定している位置。
    int ng = -1;

    // ok は「条件を満たす」ことが確定している位置。
    // 配列外の a.size() を仮想的な番兵として使う。
    int ok = static_cast<int>(a.size());

    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        if (a[mid] >= x) {
            ok = mid;
        } else {
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
