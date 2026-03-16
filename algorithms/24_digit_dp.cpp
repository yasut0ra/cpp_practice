#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - digit DP
      - 桁ごとに条件を管理する方法
      - tight フラグ

    直感メモ:
      - 左から 1 桁ずつ決めながら、「ここまでで何個非ゼロを使ったか」を持つ
      - まだ上限とぴったり同じか、それともすでに小さいかを一緒に管理する

    問題設定:
      0 以上 N 以下の整数のうち、非ゼロ桁がちょうど K 個のものの個数を数える。

    入力:
      N
      K

    ミニ入力例:
      105
      1

    ミニ出力例:
      count: 19
*/

using ll = long long;

int main() {
    string N;
    int K;
    cin >> N >> K;

    int len = static_cast<int>(N.size());
    vector<vector<vector<ll>>> dp(len + 1, vector<vector<ll>>(K + 2, vector<ll>(2, 0)));
    dp[0][0][1] = 1;

    for (int pos = 0; pos < len; ++pos) {
        for (int used = 0; used <= K; ++used) {
            for (int tight = 0; tight <= 1; ++tight) {
                int limit = (tight ? N[pos] - '0' : 9);
                for (int digit = 0; digit <= limit; ++digit) {
                    int next_used = used + (digit != 0);
                    if (next_used > K) {
                        continue;
                    }
                    int next_tight = (tight && digit == limit);
                    dp[pos + 1][next_used][next_tight] += dp[pos][used][tight];
                }
            }
        }
    }

    cout << "count: " << dp[len][K][0] + dp[len][K][1] << '\n';
    return 0;
}
