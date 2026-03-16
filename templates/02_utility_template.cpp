#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 汎用関数の切り出し
      - print_vector のような出力補助
      - 座標圧縮を「圧縮結果 + 復元表」で持つ考え方
*/

template <class T>
void print_vector(const vector<T>& values) {
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << values[i];
    }
    cout << '\n';
}

template <class T>
struct CompressionResult {
    vector<int> compressed;
    vector<T> restore_table;
};

template <class T>
CompressionResult<T> compress(const vector<T>& values) {
    vector<T> restore_table = values;
    sort(restore_table.begin(), restore_table.end());
    restore_table.erase(unique(restore_table.begin(), restore_table.end()), restore_table.end());

    vector<int> compressed;
    compressed.reserve(values.size());
    for (const T& value : values) {
        int index = static_cast<int>(lower_bound(restore_table.begin(), restore_table.end(), value) - restore_table.begin());
        compressed.push_back(index);
    }

    return {compressed, restore_table};
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    CompressionResult<int> result = compress(values);

    cout << "original: ";
    print_vector(values);

    cout << "compressed: ";
    print_vector(result.compressed);

    cout << "restore_table: ";
    print_vector(result.restore_table);
    return 0;
}
