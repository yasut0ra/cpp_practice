#include <deque>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 0-1 BFS
      - 辺の重みが 0 または 1 のときの最短路
      - deque の front / back の使い分け

    直感メモ:
      - 重み 0 の移動は「今すぐ処理」
      - 重み 1 の移動は「あとで処理」

    入力:
      n m s
      u v w   (無向辺, w は 0 または 1)

    ミニ入力例:
      4 4 0
      0 1 0
      1 2 1
      0 2 1
      2 3 0

    ミニ出力例:
      distances:
      0: 0
      1: 0
      2: 1
      3: 1
*/

struct Edge {
    int to;
    int cost;
};

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    constexpr int INF = numeric_limits<int>::max() / 4;
    vector<int> dist(n, INF);
    deque<int> dq;

    dist[s] = 0;
    dq.push_front(s);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (const auto& edge : graph[node]) {
            int next_dist = dist[node] + edge.cost;
            if (next_dist >= dist[edge.to]) {
                continue;
            }

            dist[edge.to] = next_dist;
            if (edge.cost == 0) {
                dq.push_front(edge.to);
            } else {
                dq.push_back(edge.to);
            }
        }
    }

    cout << "distances:" << '\n';
    for (int i = 0; i < n; ++i) {
        cout << i << ": " << dist[i] << '\n';
    }
    return 0;
}
