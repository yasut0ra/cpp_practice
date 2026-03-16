#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - vector: 配列を可変長で扱う
      - sort: 並べ替え
      - set: 重複なし + 昇順管理
      - map: 値ごとの個数管理

    入力:
      n
      a0 a1 ... a(n-1)

    見てほしいポイント:
      - 同じ配列でも、vector / set / map で見え方が変わる
      - map はキー順に走査される
*/

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    // vector は並べ替える前の順番を覚えている。
    cout << "original:";
    for (int x : values) {
        cout << ' ' << x;
    }
    cout << '\n';

    sort(values.begin(), values.end());

    set<int> unique_values(values.begin(), values.end());
    map<int, int> frequency;
    for (int x : values) {
        ++frequency[x];
    }

    cout << "sorted:";
    for (int x : values) {
        cout << ' ' << x;
    }
    cout << '\n';

    cout << "unique_values:";
    for (int x : unique_values) {
        cout << ' ' << x;
    }
    cout << '\n';

    cout << "frequencies:" << '\n';
    for (const auto& [value, count] : frequency) {
        cout << value << " -> " << count << '\n';
    }
    return 0;
}
