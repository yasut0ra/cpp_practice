#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - Warshall-Floyd 法
      - 全点対最短路
      - 3 重ループ DP
      - 負閉路の検出

    直感メモ:
      - 「中継点として 0..k を使ってよい世界」を少しずつ広げていく
      - via を 1 個増やすたびに、通れる寄り道が増える

    入力:
      n m
      u v w   (u -> v の有向辺)

    ミニ入力例:
      3 3
      0 1 4
      1 2 1
      0 2 10

    ミニ出力例:
      distance_matrix:
      0 4 5
      INF 0 1
      INF INF 0

    計算量:
      O(n^3)

    注意:
      - n が大きいと重い
      - 目安として n <= 400 程度で使うことが多い
*/

using ll = long long;
constexpr ll INF = numeric_limits<ll>::max() / 4;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = w;
        }
    }

    for (int via = 0; via < n; ++via) {
        for (int from = 0; from < n; ++from) {
            if (dist[from][via] == INF) {
                continue;
            }
            for (int to = 0; to < n; ++to) {
                if (dist[via][to] == INF) {
                    continue;
                }
                // from -> to を直接行くより、via を経由したほうが短いか比べる。
                if (dist[from][to] > dist[from][via] + dist[via][to]) {
                    dist[from][to] = dist[from][via] + dist[via][to];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            cout << "negative_cycle_detected" << '\n';
            return 0;
        }
    }

    cout << "distance_matrix:" << '\n';
    for (int from = 0; from < n; ++from) {
        for (int to = 0; to < n; ++to) {
            if (to > 0) {
                cout << ' ';
            }
            if (dist[from][to] == INF) {
                cout << "INF";
            } else {
                cout << dist[from][to];
            }
        }
        cout << '\n';
    }
    return 0;
}
