#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 2 次元 vector
      - 行列の入力
      - 行ごと / 列ごとの集計

    入力:
      h w
      matrix

    ミニ入力例:
      2 3
      1 2 3
      4 5 6

    ミニ出力例:
      total: 21
      row_sums: 6 15
      col_sums: 5 7 9
*/

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> matrix(h, vector<int>(w));
    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            cin >> matrix[row][col];
        }
    }

    int total = 0;
    vector<int> row_sums(h, 0);
    vector<int> col_sums(w, 0);

    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            total += matrix[row][col];
            row_sums[row] += matrix[row][col];
            col_sums[col] += matrix[row][col];
        }
    }

    cout << "total: " << total << '\n';
    cout << "row_sums:";
    for (int x : row_sums) {
        cout << ' ' << x;
    }
    cout << '\n';

    cout << "col_sums:";
    for (int x : col_sums) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}
