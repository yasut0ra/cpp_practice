#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - ダイクストラ法で重み付き最短路を求める
      - priority_queue を最小ヒープとして使う
      - parent を持って経路復元する

    直感メモ:
      - 「いま確定できる中で一番近い頂点」から順に確定していく
      - BFS の重み付き版だが、距離が小さい順に処理する必要がある

    入力:
      n m s
      u v w   (無向辺)

    ミニ入力例:
      4 4 0
      0 1 2
      1 2 3
      0 2 10
      2 3 1

    ミニ出力例:
      distances:
      0: 0
      1: 2
      2: 5
      3: 6
      path_to_last_node: 0 1 2 3

    注意:
      - 辺の重みは非負であることが前提
      - 負の辺があると、このやり方は壊れる
*/

using ll = long long;

struct Edge {
    int to;
    int cost;
};

vector<int> restore_path(const vector<int>& parent, int goal) {
    vector<int> path;
    for (int current = goal; current != -1; current = parent[current]) {
        path.push_back(current);
    }
    reverse(path.begin(), path.end());
    return path;
}

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

    constexpr ll INF = numeric_limits<ll>::max() / 4;
    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [current_dist, node] = pq.top();
        pq.pop();

        // 古い情報がキューに残っていることがあるので捨てる。
        if (current_dist != dist[node]) {
            continue;
        }

        for (const auto& edge : graph[node]) {
            ll next_dist = current_dist + edge.cost;
            if (next_dist < dist[edge.to]) {
                // より短い道を見つけたので更新する。
                dist[edge.to] = next_dist;
                parent[edge.to] = node;
                pq.push({next_dist, edge.to});
            }
        }
    }

    cout << "distances:" << '\n';
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << i << ": -1" << '\n';
        } else {
            cout << i << ": " << dist[i] << '\n';
        }
    }

    int goal = n - 1;
    if (dist[goal] == INF) {
        cout << "path_to_last_node: unreachable" << '\n';
    } else {
        vector<int> path = restore_path(parent, goal);
        cout << "path_to_last_node:";
        for (int node : path) {
            cout << ' ' << node;
        }
        cout << '\n';
    }
    return 0;
}
