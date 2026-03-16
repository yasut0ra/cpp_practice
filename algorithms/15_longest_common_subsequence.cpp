#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - LCS (Longest Common Subsequence)
      - 2 文字列 DP
      - 文字列の復元

    直感メモ:
      - s の先頭 i 文字と t の先頭 j 文字だけを見たときの最善を持つ
      - 末尾が一致したら伸ばせるし、一致しないなら片方を捨てて比較する

    入力:
      s
      t

    ミニ入力例:
      abcde
      ace

    ミニ出力例:
      length: 3
      lcs: ace
*/

int main() {
    string s, t;
    cin >> s >> t;

    int n = static_cast<int>(s.size());
    int m = static_cast<int>(t.size());
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }

    string lcs;
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
            lcs.push_back(s[i - 1]);
            --i;
            --j;
        } else if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());

    cout << "length: " << dp[n][m] << '\n';
    cout << "lcs: " << lcs << '\n';
    return 0;
}
