#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 単調スタック
      - 各要素について「左側で一番近い小さい要素」を求める方法

    直感メモ:
      - 新しい値から見て役に立たない候補は、その場で退場させる
      - 一度退場した要素は、今後も逆転できない

    入力:
      n
      a0 a1 ... a(n-1)

    出力:
      各 i に対して、a[i] より左で最も近い「小さい値」の位置
      存在しなければ -1

    ミニ入力例:
      6
      2 5 3 7 1 4

    ミニ出力例:
      nearest_left_smaller: -1 0 0 2 -1 4

    計算量:
      O(n)

    発想:
      - stack には「まだ次の比較相手として使える候補」だけを残す
      - 条件に合わないものは二度と使わないので捨ててよい
*/

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> nearest_left_smaller(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        // a[i] 以上の値は、「左で一番近い小さい値」の候補として失格。
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nearest_left_smaller[i] = st.top();
        }

        st.push(i);
    }

    cout << "nearest_left_smaller:";
    for (int index : nearest_left_smaller) {
        cout << ' ' << index;
    }
    cout << '\n';
    return 0;
}
