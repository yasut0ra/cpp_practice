#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 最小全域木 (MST)
      - Kruskal 法
      - Union-Find と辺ソートの組み合わせ

    直感メモ:
      - 軽い辺から順に見て、「閉路を作らないなら採用」を繰り返す
      - 必要な線だけを残して、全体を最小コストでつなぐ

    入力:
      n m
      u v w   (無向辺)

    ミニ入力例:
      4 5
      0 1 1
      1 2 2
      0 2 4
      2 3 1
      1 3 5

    ミニ出力例:
      mst_exists: true
      mst_cost: 4
      chosen_edges:
      0 1 1
      2 3 1
      1 2 2
*/

struct UnionFind {
    vector<int> parent;
    vector<int> sizes;

    explicit UnionFind(int n) : parent(n), sizes(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int root(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = root(parent[x]);
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) {
            return false;
        }
        if (sizes[a] < sizes[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sizes[a] += sizes[b];
        return true;
    }
};

struct Edge {
    int u;
    int v;
    int w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge& left, const Edge& right) {
        return make_tuple(left.w, left.u, left.v) < make_tuple(right.w, right.u, right.v);
    });

    UnionFind uf(n);
    long long mst_cost = 0;
    vector<Edge> chosen;

    for (const auto& edge : edges) {
        if (!uf.unite(edge.u, edge.v)) {
            continue;
        }
        mst_cost += edge.w;
        chosen.push_back(edge);
    }

    bool mst_exists = static_cast<int>(chosen.size()) == n - 1;
    cout << "mst_exists: " << (mst_exists ? "true" : "false") << '\n';

    if (mst_exists) {
        cout << "mst_cost: " << mst_cost << '\n';
        cout << "chosen_edges:" << '\n';
        for (const auto& edge : chosen) {
            cout << edge.u << ' ' << edge.v << ' ' << edge.w << '\n';
        }
    }
    return 0;
}
