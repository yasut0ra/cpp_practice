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

    図解:
      N = 105 を左から 1 桁ずつ決める。tight は「ここまで N とぴったり同じか」:
        tight = 1 : 次の桁は N の桁以下しか置けない
                    例: 1 _ _ の十の位は 0 まで
        tight = 0 : すでに N より小さいので、次の桁は 0..9 を自由に置ける
                    例: 0 _ _ の残りは何でもよい

      dp[pos][used][tight] の値 (pos 桁決めて、非ゼロを used 個使った数の個数):
        (used, tight) :  (0,1)  (0,0)  (1,1)  (1,0)
        pos 0         :      1      0      0      0    まだ何も決めていない
        pos 1         :      0      1      1      0    0 / 1
        pos 2         :      0      1      1      9    00 / 10 / 01..09
        pos 3         :      0      1      0     19    105 は非ゼロが 2 個なので (1, 1) は 0

      最後の 19 個の内訳 (used = 1 で 3 桁決め終わったもの):
        0 0 [1..9]  ->  9 個  (1, 2, ..., 9)
        0 [1..9] 0  ->  9 個  (10, 20, ..., 90)
        1 0 0       ->  1 個  (100)

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
