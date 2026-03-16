#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - next_permutation
      - 順列全探索
      - 配列を並べ替えて全パターンをなめる方法

    入力:
      n
      a0 a1 ... a(n-1)

    ミニ入力例:
      3
      1 2 3

    ミニ出力例:
      permutations:
      1 2 3
      1 3 2
      2 1 3
      2 3 1
      3 1 2
      3 2 1
*/

void print_vector(const vector<int>& values) {
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << values[i];
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    sort(values.begin(), values.end());

    cout << "permutations:" << '\n';
    do {
        print_vector(values);
    } while (next_permutation(values.begin(), values.end()));
    return 0;
}
