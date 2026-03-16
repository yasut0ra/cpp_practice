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
