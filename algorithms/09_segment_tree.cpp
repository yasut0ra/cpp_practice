#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - Segment Tree
      - 区間和を高速に求める方法
      - 1 点更新 + 区間クエリ

    直感メモ:
      - 配列を半分、さらに半分、と束ねていった集計用の木
      - 葉に元の値、親に「子 2 つの合計」を置く

    問題設定:
      初期配列が与えられる。
      以下のクエリを処理する。
        1 index value : a[index] = value に更新
        2 l r         : 区間 [l, r) の和を出力

    ミニ入力例:
      5 4
      1 2 3 4 5
      2 1 4
      1 2 10
      2 1 4
      2 0 5

    ミニ出力例:
      9
      16
      22

    計算量:
      - 構築: O(n)
      - 更新: O(log n)
      - クエリ: O(log n)

    つまずきやすい点:
      - 半開区間 [l, r) を守る
      - 葉の開始位置が size になることを意識する
*/

struct SegmentTree {
    int size = 1;
    vector<long long> data;

    explicit SegmentTree(int n) {
        while (size < n) {
            size *= 2;
        }
        data.assign(2 * size, 0);
    }

    void build(const vector<long long>& values) {
        for (int i = 0; i < static_cast<int>(values.size()); ++i) {
            data[size + i] = values[i];
        }
        for (int node = size - 1; node >= 1; --node) {
            data[node] = data[node * 2] + data[node * 2 + 1];
        }
    }

    void set_value(int index, long long value) {
        int node = size + index;
        data[node] = value;

        while (node > 1) {
            node /= 2;
            data[node] = data[node * 2] + data[node * 2 + 1];
        }
    }

    long long range_sum(int l, int r) const {
        long long left_sum = 0;
        long long right_sum = 0;

        l += size;
        r += size;

        while (l < r) {
            if (l % 2 == 1) {
                // l が右の子なら、その区間は丸ごと使ってよい。
                left_sum += data[l];
                ++l;
            }
            if (r % 2 == 1) {
                --r;
                // r は先に 1 つ戻すと、ちょうど使うべき左の区間になる。
                right_sum += data[r];
            }
            l /= 2;
            r /= 2;
        }

        return left_sum + right_sum;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    SegmentTree seg(n);
    seg.build(values);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int index;
            long long value;
            cin >> index >> value;
            seg.set_value(index, value);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.range_sum(l, r) << '\n';
        }
    }
    return 0;
}
