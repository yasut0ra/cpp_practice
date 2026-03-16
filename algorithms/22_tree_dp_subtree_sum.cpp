#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - Tree DP
      - 部分木に対する値の集計
      - DFS と DP の組み合わせ

    直感メモ:
      - 子の答えを全部集めてから、自分の答えを作る
      - 木では「親に戻らない」ように DFS すれば考えやすい

    入力:
      n
      values
      n - 1 本の辺

    ミニ入力例:
      5
      5 3 4 2 1
      0 1
      0 2
      1 3
      1 4

    ミニ出力例:
      subtree_sums: 15 6 4 2 1
*/

long long dfs(int node, int parent, const vector<vector<int>>& graph, const vector<int>& values, vector<long long>& subtree_sum) {
    subtree_sum[node] = values[node];
    for (int next : graph[node]) {
        if (next == parent) {
            continue;
        }
        subtree_sum[node] += dfs(next, node, graph, values, subtree_sum);
    }
    return subtree_sum[node];
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<long long> subtree_sum(n, 0);
    dfs(0, -1, graph, values, subtree_sum);

    cout << "subtree_sums:";
    for (long long x : subtree_sum) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}
