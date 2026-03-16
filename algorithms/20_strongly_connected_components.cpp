#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 強連結成分分解 (SCC)
      - 有向グラフを「相互に行き来できる塊」に分ける考え方
      - Kosaraju 法

    直感メモ:
      - まず「帰りがけ順」で並べる
      - 次に辺を逆向きにして、大きい塊からまとめて回収する

    入力:
      n m
      u v   (有向辺)

    ミニ入力例:
      5 5
      0 1
      1 2
      2 0
      1 3
      3 4

    ミニ出力例:
      component_count: 3
      component_id: 0 0 0 1 2
*/

void dfs_order(int node, const vector<vector<int>>& graph, vector<int>& used, vector<int>& order) {
    used[node] = true;
    for (int next : graph[node]) {
        if (!used[next]) {
            dfs_order(next, graph, used, order);
        }
    }
    order.push_back(node);
}

void dfs_component(int node, int id, const vector<vector<int>>& reverse_graph, vector<int>& component_id) {
    component_id[node] = id;
    for (int next : reverse_graph[node]) {
        if (component_id[next] == -1) {
            dfs_component(next, id, reverse_graph, component_id);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n), reverse_graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }

    vector<int> used(n, false);
    vector<int> order;
    for (int node = 0; node < n; ++node) {
        if (!used[node]) {
            dfs_order(node, graph, used, order);
        }
    }

    reverse(order.begin(), order.end());

    vector<int> component_id(n, -1);
    int component_count = 0;
    for (int node : order) {
        if (component_id[node] != -1) {
            continue;
        }
        dfs_component(node, component_count, reverse_graph, component_id);
        ++component_count;
    }

    cout << "component_count: " << component_count << '\n';
    cout << "component_id:";
    for (int id : component_id) {
        cout << ' ' << id;
    }
    cout << '\n';
    return 0;
}
