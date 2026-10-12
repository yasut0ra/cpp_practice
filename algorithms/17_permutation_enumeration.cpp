#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - next_permutation
      - 順列全探索
      - 配列を並べ替えて全パターンをなめる方法

    図解:
      [1, 2, 3] の順列を辞書順に並べると、この木を上から順に読んだ形になる:

        1 -+- 2 - 3    1 2 3
           +- 3 - 2    1 3 2
        2 -+- 1 - 3    2 1 3
           +- 3 - 1    2 3 1
        3 -+- 1 - 2    3 1 2
           +- 2 - 1    3 2 1

      next_permutation 1 回の動き (例: 1 3 2 -> 2 1 3):
        (1) 右から見て、初めて「右隣より小さい」位置 i を探す
              1  3  2
              ^           a[0] = 1 < a[1] = 3 なので i = 0
        (2) i より右で a[i] より大きい最小の値 (= 2) と交換する
              2  3  1
        (3) i より右を反転して、いちばん小さい並びに戻す
              2  1  3

      最初に sort しておくのは、辞書順で最小の並びからスタートするため

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
