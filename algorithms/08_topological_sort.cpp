#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - トポロジカルソート
      - 入次数 indegree の考え方
      - DAG 上での順序付き処理
      - 閉路があるとトポロジカル順序が作れないこと

    入力:
      n m
      u v   (u -> v の有向辺)

    出力:
      閉路がなければトポロジカル順序
      閉路があれば cycle_detected

    ミニ入力例:
      4 4
      0 1
      0 2
      1 3
      2 3

    ミニ出力例:
      topological_order: 0 1 2 3

    計算量:
      O(n + m)
*/

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        ++indegree[v];
    }

    queue<int> q;
    for (int node = 0; node < n; ++node) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> order;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int next : graph[node]) {
            --indegree[next];
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (static_cast<int>(order.size()) != n) {
        cout << "cycle_detected" << '\n';
        return 0;
    }

    cout << "topological_order:";
    for (int node : order) {
        cout << ' ' << node;
    }
    cout << '\n';
    return 0;
}
