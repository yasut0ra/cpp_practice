#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 0/1 ナップサック DP
      - 2 次元 DP テーブル
      - 選んだ品物の復元

    直感メモ:
      - 「i 個目まで見て、重さ cap まで使ってよいときの最高得点」を順番に埋める
      - 取る / 取らないの 2 択を毎回比較する

    入力:
      n W
      weight value

    ミニ入力例:
      3 8
      3 30
      4 50
      5 60

    ミニ出力例:
      maximum_value: 90
      chosen_indices: 0 2
*/

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int cap = 0; cap <= W; ++cap) {
            dp[i + 1][cap] = max(dp[i + 1][cap], dp[i][cap]);
            if (cap + weight[i] <= W) {
                dp[i + 1][cap + weight[i]] = max(dp[i + 1][cap + weight[i]], dp[i][cap] + value[i]);
            }
        }
    }

    int best_capacity = 0;
    for (int cap = 0; cap <= W; ++cap) {
        if (dp[n][cap] > dp[n][best_capacity]) {
            best_capacity = cap;
        }
    }

    vector<int> chosen;
    int cap = best_capacity;
    for (int i = n - 1; i >= 0; --i) {
        if (cap >= weight[i] && dp[i + 1][cap] == dp[i][cap - weight[i]] + value[i]) {
            chosen.push_back(i);
            cap -= weight[i];
        }
    }
    reverse(chosen.begin(), chosen.end());

    cout << "maximum_value: " << dp[n][best_capacity] << '\n';
    cout << "chosen_indices:";
    for (int index : chosen) {
        cout << ' ' << index;
    }
    cout << '\n';
    return 0;
}
