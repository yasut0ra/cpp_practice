#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 競プロでよくある solve() 形式
      - 複数テストケースの処理
      - ios::sync_with_stdio(false); cin.tie(nullptr); の意味

    入力:
      t
      各テストケースごとに:
        n
        a0 a1 ... a(n-1)

    出力:
      各ケースについて、配列の合計値と最大値
*/

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;
    long long maximum_value = -(1LL << 60);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        maximum_value = max(maximum_value, a[i]);
    }

    cout << sum << ' ' << maximum_value << '\n';
}

int main() {
    // C と C++ の入出力の同期を切ることで cin / cout を高速化する。
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
