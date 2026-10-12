#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - Bellman-Ford 法
      - 負の辺があっても使える最短路
      - 負閉路の検出

    直感メモ:
      - 全辺の緩和を何度も繰り返すと、最短距離が少しずつ前へ伝わる
      - n 回目でも更新されるなら、どこかで負閉路の影響を受けている

    図解:
      グラフ (有向。1 -> 2 が負の辺):

         +---------------- 4 ---------------+
         |                                  v
        (0) ---- 2 ----> (1) ---- -3 ----> (2) ---- 2 ----> (3)
                          |                                  ^
                          +--------------- 5 ----------------+

      1 周目: 全部の辺を入力順に緩和する
        edge            dist[0]  dist[1]  dist[2]  dist[3]
        start                 0      INF      INF      INF
        0 -> 1 (2)            0        2      INF      INF
        1 -> 2 (-3)           0        2       -1      INF    2 + (-3) = -1
        0 -> 2 (4)            0        2       -1      INF    0 + 4 = 4 は -1 より大きいので更新しない
        2 -> 3 (2)            0        2       -1        1
        1 -> 3 (5)            0        2       -1        1    2 + 5 = 7 は 1 より大きいので更新しない
      2 周目: どの辺でも更新されない -> 打ち切り
      負閉路チェック: もう 1 周しても更新されない -> negative_cycle: false

      直通の 0 -> 2 (4) より、負の辺を通る 0 -> 1 -> 2 (2 + (-3) = -1) のほうが近い。
      辺の順番が悪いと 1 周で 1 辺ぶんずつしか伝わらないので、最大 n - 1 周まわす

    入力:
      n m s
      u v w   (有向辺)

    ミニ入力例:
      4 5 0
      0 1 2
      1 2 -3
      0 2 4
      2 3 2
      1 3 5

    ミニ出力例:
      negative_cycle: false
      distances:
      0: 0
      1: 2
      2: -1
      3: 1
*/

using ll = long long;

struct Edge {
    int from;
    int to;
    ll cost;
};

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }

    constexpr ll INF = numeric_limits<ll>::max() / 4;
    vector<ll> dist(n, INF);
    dist[s] = 0;

    for (int iter = 0; iter < n - 1; ++iter) {
        bool updated = false;
        for (const auto& edge : edges) {
            if (dist[edge.from] == INF) {
                continue;
            }
            if (dist[edge.to] > dist[edge.from] + edge.cost) {
                dist[edge.to] = dist[edge.from] + edge.cost;
                updated = true;
            }
        }
        if (!updated) {
            break;
        }
    }

    bool negative_cycle = false;
    for (const auto& edge : edges) {
        if (dist[edge.from] == INF) {
            continue;
        }
        if (dist[edge.to] > dist[edge.from] + edge.cost) {
            negative_cycle = true;
        }
    }

    cout << "negative_cycle: " << (negative_cycle ? "true" : "false") << '\n';
    cout << "distances:" << '\n';
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << i << ": INF" << '\n';
        } else {
            cout << i << ": " << dist[i] << '\n';
        }
    }
    return 0;
}
