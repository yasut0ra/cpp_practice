#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 座標圧縮
      - 値が大きくても添字として扱えるようにする方法

    典型用途:
      - 値の範囲が 10^9 など大きい
      - しかし実際に登場する値の個数は n 個しかない

    入力:
      n
      a0 a1 ... a(n-1)

    ミニ入力例:
      5
      100 500 100 300 500

    ミニ出力例:
      compressed: 0 2 0 1 2
      restore_table:
      0 -> 100
      1 -> 300
      2 -> 500
*/

template <class T>
pair<vector<int>, vector<T>> compress(const vector<T>& values) {
    vector<T> sorted = values;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    vector<int> compressed(values.size());
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        compressed[i] = static_cast<int>(lower_bound(sorted.begin(), sorted.end(), values[i]) - sorted.begin());
    }

    return {compressed, sorted};
}

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto [compressed, restore_table] = compress(a);

    cout << "compressed:";
    for (int x : compressed) {
        cout << ' ' << x;
    }
    cout << '\n';

    cout << "restore_table:" << '\n';
    for (int i = 0; i < static_cast<int>(restore_table.size()); ++i) {
        cout << i << " -> " << restore_table[i] << '\n';
    }
    return 0;
}
