#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 隣接リストでの BFS
      - 重みなしグラフの最短路
      - parent による経路復元

    直感メモ:
      - グラフ上で BFS をすると、近い頂点から順に波が広がる
      - queue に入る順番が、そのまま距離の順番になる

    入力:
      n m s
      u v   (無向辺)

    ミニ入力例:
      5 4 0
      0 1
      1 2
      0 3
      3 4

    ミニ出力例:
      distances:
      0: 0
      1: 1
      2: 2
      3: 1
      4: 2
      path_to_last_node: 0 3 4
*/

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

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (dist[next] != -1) {
                continue;
            }
            dist[next] = dist[node] + 1;
            parent[next] = node;
            q.push(next);
        }
    }

    cout << "distances:" << '\n';
    for (int i = 0; i < n; ++i) {
        cout << i << ": " << dist[i] << '\n';
    }

    int goal = n - 1;
    if (dist[goal] == -1) {
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
