#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - Union-Find で連結成分を高速に管理する
      - root: 根を探す
      - 経路圧縮: root を呼ぶたびに木を平らにする
      - union by size: 小さい木を大きい木につなぐ

    入力:
      n q
      type ...

    クエリ:
      1 u v : u と v を連結する
      2 u v : 同じ連結成分か判定する
      3 u   : u が属する成分のサイズを出す

    ミニ入力例:
      5 5
      1 0 1
      1 1 2
      2 0 2
      3 1
      2 3 4

    ミニ出力例:
      Yes
      3
      No
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

        // 帰りがけに root を直接つなぐので、次回以降が速くなる。
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

    bool same(int a, int b) {
        return root(a) == root(b);
    }

    int size(int x) {
        return sizes[root(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else if (type == 2) {
            int u, v;
            cin >> u >> v;
            cout << (uf.same(u, v) ? "Yes" : "No") << '\n';
        } else if (type == 3) {
            int u;
            cin >> u;
            cout << uf.size(u) << '\n';
        }
    }
    return 0;
}
