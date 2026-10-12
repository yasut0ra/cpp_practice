#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - bit DP
      - 巡回セールスマン問題 (TSP) の基本形
      - 集合を bit で表す方法

    直感メモ:
      - 「どの都市を訪問済みか」と「最後にどこにいるか」を状態にする
      - 状態数は多いが、n が小さければ全探索よりずっと整理しやすい

    図解:
      状態 dp[bit][last]:
        bit  = 訪問済みの都市の集合 (i ビット目が 1 なら都市 i は訪問済み)
        last = 今いる都市
        例: bit = 1011 (2 進) は {0, 1, 3} を訪問済みという意味
              city :  3  2  1  0
              bit  :  1  0  1  1

      遷移: まだ訪れていない都市 next へ進む
        dp[bit][last] + cost[last][next] -> dp[bit | (1 << next)][next]

      最適ルートの一例 0 -> 1 -> 3 -> 2 -> 0 を状態で追う (dp[0001][0] = 0 からスタート):
        bit    last    dp
        0001    0       0
        0011    1      10    + cost[0][1] = 10
        1011    3      35    + cost[1][3] = 25
        1111    2      65    + cost[3][2] = 30
        最後に 0 へ戻る: 65 + cost[2][0] = 65 + 15 = 80

    入力:
      n
      cost matrix

    ミニ入力例:
      4
      0 10 15 20
      10 0 35 25
      15 35 0 30
      20 25 30 0

    ミニ出力例:
      minimum_cycle_cost: 80
*/

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<vector<ll>> cost(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    constexpr ll INF = numeric_limits<ll>::max() / 4;
    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));
    dp[1][0] = 0;

    for (int bit = 0; bit < (1 << n); ++bit) {
        for (int last = 0; last < n; ++last) {
            if (dp[bit][last] == INF) {
                continue;
            }
            for (int next = 0; next < n; ++next) {
                if (bit & (1 << next)) {
                    continue;
                }
                int next_bit = bit | (1 << next);
                if (dp[next_bit][next] > dp[bit][last] + cost[last][next]) {
                    dp[next_bit][next] = dp[bit][last] + cost[last][next];
                }
            }
        }
    }

    ll answer = INF;
    for (int last = 0; last < n; ++last) {
        answer = min(answer, dp[(1 << n) - 1][last] + cost[last][0]);
    }

    cout << "minimum_cycle_cost: " << answer << '\n';
    return 0;
}
