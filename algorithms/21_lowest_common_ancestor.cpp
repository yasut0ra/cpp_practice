#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - LCA (Lowest Common Ancestor)
      - binary lifting
      - 木上クエリを高速に処理する方法

    直感メモ:
      - 親を 1 個ずつ上る代わりに、2^k 個ずつジャンプできる表を作る
      - 深さをそろえてから同時に上げると、最初に分かれる直前が見つかる

    入力:
      n
      n - 1 本の辺
      q
      u v

    ミニ入力例:
      7
      0 1
      0 2
      1 3
      1 4
      2 5
      2 6
      3
      3 4
      3 5
      5 6

    ミニ出力例:
      lca:
      1
      0
      2
*/

struct LCA {
    int n;
    int log_n;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<vector<int>> graph;

    explicit LCA(int n) : n(n), log_n(1), depth(n, 0), graph(n) {
        while ((1 << log_n) <= n) {
            ++log_n;
        }
        parent.assign(log_n, vector<int>(n, -1));
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int node, int par) {
        parent[0][node] = par;
        for (int next : graph[node]) {
            if (next == par) {
                continue;
            }
            depth[next] = depth[node] + 1;
            dfs(next, node);
        }
    }

    void build(int root) {
        dfs(root, -1);
        for (int k = 0; k + 1 < log_n; ++k) {
            for (int v = 0; v < n; ++v) {
                if (parent[k][v] == -1) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    int query(int u, int v) const {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];
        for (int k = 0; k < log_n; ++k) {
            if (diff & (1 << k)) {
                u = parent[k][u];
            }
        }

        if (u == v) {
            return u;
        }

        for (int k = log_n - 1; k >= 0; --k) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }
};

int main() {
    int n;
    cin >> n;

    LCA lca(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        lca.add_edge(u, v);
    }
    lca.build(0);

    int q;
    cin >> q;

    cout << "lca:" << '\n';
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << '\n';
    }
    return 0;
}
