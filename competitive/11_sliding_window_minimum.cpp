#include <deque>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - スライディングウィンドウ最小値
      - deque を使って O(n) で区間最小値を求める方法

    直感メモ:
      - 新しい要素より大きい候補は、後ろから見るともう勝てない
      - 先頭には常に「今の窓で最小の候補」が残る

    図解:
      a = [4, 2, 12, 3, 5, 1], k = 3 (deque には index を持つが、ここでは値で表示):

        i  a[i]  window      deque      min
        0    4   [4]         [4]
        1    2   [4 2]       [2]               4 は 2 に勝てないので後ろから捨てる
        2   12   [4 2 12]    [2, 12]      2
        3    3   [2 12 3]    [2, 3]       2    12 は 3 に勝てないので捨てる
        4    5   [12 3 5]    [3, 5]       3    2 は窓から出たので前から捨てる
        5    1   [3 5 1]     [1]          1    3 と 5 は 1 に勝てないので捨てる

    入力:
      n k
      a0 a1 ... a(n-1)

    ミニ入力例:
      6 3
      4 2 12 3 5 1

    ミニ出力例:
      window_minimums: 2 2 3 1
*/

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    deque<int> dq;
    vector<long long> answer;

    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            answer.push_back(a[dq.front()]);
        }
    }

    cout << "window_minimums:";
    for (long long x : answer) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}
