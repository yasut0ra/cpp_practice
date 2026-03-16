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
