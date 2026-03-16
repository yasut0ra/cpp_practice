#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 1 次元 DP
      - 遷移式の立て方
      - 復元用の prev 配列

    直感メモ:
      - 各足場に着くまでの「いま判明している最安値メモ」を前から埋めていく
      - 未来を全部読むのではなく、次に行ける場所へメモを配る感じ

    問題設定:
      足場 0 から足場 n - 1 まで進む。
      i から i + 1 または i + 2 に移動できる。
      移動コストは |height[i] - height[j]|。
      最小コストを求める。

    入力:
      n
      h0 h1 ... h(n-1)

    ミニ入力例:
      4
      10 30 40 20

    ミニ出力例:
      minimum_cost: 30
      path: 0 1 3

    つまずきやすい点:
      - dp[i] を「i から先の答え」と見るか「i に着くまでの答え」と見るかを混ぜない
*/

using ll = long long;

vector<int> restore_path(const vector<int>& prev, int goal) {
    vector<int> path;
    for (int current = goal; current != -1; current = prev[current]) {
        path.push_back(current);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n;
    cin >> n;

    vector<ll> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    constexpr ll INF = numeric_limits<ll>::max() / 4;
    vector<ll> dp(n, INF);
    vector<int> prev(n, -1);

    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int jump = 1; jump <= 2; ++jump) {
            int next = i + jump;
            if (next >= n) {
                continue;
            }

            ll cost = dp[i] + llabs(height[i] - height[next]);
            if (cost < dp[next]) {
                // next へ行くより安いルートを見つけたので、メモを書き換える。
                dp[next] = cost;
                prev[next] = i;
            }
        }
    }

    cout << "minimum_cost: " << dp[n - 1] << '\n';

    vector<int> path = restore_path(prev, n - 1);
    cout << "path:";
    for (int node : path) {
        cout << ' ' << node;
    }
    cout << '\n';
    return 0;
}
