#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - Z-algorithm
      - 各位置から始まる接頭辞一致長
      - 文字列の前処理

    直感メモ:
      - s[0..] と s[i..] がどれだけ同じかを全部の i で調べる
      - すでに分かっている一致区間を流用して、比較回数を減らす

    入力:
      s

    ミニ入力例:
      aabxaabx

    ミニ出力例:
      z_values: 8 1 0 0 4 1 0 0
*/

vector<int> z_algorithm(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> z(n, 0);
    z[0] = n;

    int left = 0;
    int right = 0;
    for (int i = 1; i < n; ++i) {
        if (i < right) {
            z[i] = min(right - i, z[i - left]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;

    vector<int> z = z_algorithm(s);

    cout << "z_values:";
    for (int x : z) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}
