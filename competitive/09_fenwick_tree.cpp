#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - Fenwick Tree (Binary Indexed Tree)
      - 1 点加算
      - prefix sum / range sum

    直感メモ:
      - prefix の集計を少しずつ分担して持つ配列
      - Segment Tree より軽く、和の管理に特に使いやすい

    入力:
      n q
      a0 a1 ... a(n-1)
      type ...

    クエリ:
      1 index delta : a[index] に delta を足す
      2 l r         : [l, r) の和を出力

    ミニ入力例:
      5 4
      1 2 3 4 5
      2 0 3
      1 1 5
      2 1 4
      2 0 5

    ミニ出力例:
      6
      14
      20
*/

struct FenwickTree {
    int n;
    vector<long long> bit;

    explicit FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    void add(int index, long long delta) {
        for (int i = index + 1; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    long long prefix_sum(int right) const {
        long long result = 0;
        for (int i = right; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }

    long long range_sum(int l, int r) const {
        return prefix_sum(r) - prefix_sum(l);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    FenwickTree bit(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        bit.add(i, x);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int index;
            long long delta;
            cin >> index >> delta;
            bit.add(index, delta);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << bit.range_sum(l, r) << '\n';
        }
    }
    return 0;
}
