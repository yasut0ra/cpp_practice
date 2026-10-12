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

    図解:
      木 (根は 0):
                  0               depth 0
               /     \
             1         2          depth 1
            / \       / \
           3   4     5   6        depth 2

      parent[k][v] = v から 2^k 個上の祖先 (-1 はそれ以上の親がない):
        v            :   0   1   2   3   4   5   6
        depth        :   0   1   1   2   2   2   2
        parent[0][v] :  -1   0   0   1   1   2   2    1 個上
        parent[1][v] :  -1  -1  -1   0   0   0   0    2 個上

      query(3, 5): 深さは同じ 2 なので、大きいジャンプから順に同時に試す
        k = 1 (2 個上): 3 -> 0, 5 -> 0 で同じ -> 行き過ぎかもしれないので跳ばない
        k = 0 (1 個上): 3 -> 1, 5 -> 2 で違う -> 跳ぶ (u = 1, v = 2)
        最後に 1 個上が LCA: parent[0][1] = 0

      深さが違うときは、先に深いほうを差の分だけ上げてそろえる
      (差を 2 進数で分解する。差が 3 なら 2 個 + 1 個)

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
