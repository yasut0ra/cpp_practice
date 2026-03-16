#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 累積和 prefix[i] の意味
      - 区間和を O(1) で求める方法
      - 半開区間 [l, r) の扱い

    入力:
      n q
      a0 a1 ... a(n-1)
      l r   (q 個)

    ルール:
      - クエリは 0-indexed
      - 区間は [l, r) なので、r は含まない

    例:
      a = [5, 1, 4, 2]
      prefix = [0, 5, 6, 10, 12]
      [1, 4) の和は prefix[4] - prefix[1] = 7
*/

vector<long long> build_prefix_sum(const vector<long long>& values) {
    vector<long long> prefix(values.size() + 1, 0);
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        prefix[i + 1] = prefix[i] + values[i];
    }
    return prefix;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    vector<long long> prefix = build_prefix_sum(values);

    for (int query = 0; query < q; ++query) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << '\n';
    }
    return 0;
}
