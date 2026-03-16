#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 再帰 DFS
      - visited 配列の代わりに component_id を持つ方法
      - 連結成分分解

    入力:
      n m
      u v   (無向辺)

    出力:
      連結成分の個数
      各頂点がどの成分に属するか

    ミニ入力例:
      6 3
      0 1
      1 2
      3 4

    ミニ出力例:
      components: 3
      component_id: 0 0 0 1 1 2

    注意:
      - 深い再帰が発生するグラフでは stack が足りないことがある
      - 競プロでは iterative DFS に切り替える場合もある
*/

void dfs(int node, int component_id, const vector<vector<int>>& graph, vector<int>& component) {
    component[node] = component_id;

    for (int next : graph[node]) {
        if (component[next] != -1) {
            continue;
        }
        dfs(next, component_id, graph, component);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> component(n, -1);
    int component_count = 0;

    for (int node = 0; node < n; ++node) {
        if (component[node] != -1) {
            continue;
        }
        dfs(node, component_count, graph, component);
        ++component_count;
    }

    cout << "components: " << component_count << '\n';
    cout << "component_id:";
    for (int id : component) {
        cout << ' ' << id;
    }
    cout << '\n';
    return 0;
}
