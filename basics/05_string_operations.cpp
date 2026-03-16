#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*
    このファイルで学ぶこと:
      - string の基本操作
      - length / substr / find / reverse
      - 文字列を組み合わせる方法

    入力:
      s pattern

    ミニ入力例:
      algorithm go

    ミニ出力例:
      length: 9
      substring(2, 4): gori
      find_pattern: 2
      reversed: mhtirogla
      merged: algorithm_go
*/

int main() {
    string s, pattern;
    cin >> s >> pattern;

    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    int start = min(2, static_cast<int>(s.size()));
    int length = min(4, static_cast<int>(s.size()) - start);
    string part = s.substr(start, length);

    size_t pos = s.find(pattern);
    int found_index = (pos == string::npos ? -1 : static_cast<int>(pos));

    cout << "length: " << s.size() << '\n';
    cout << "substring(2, 4): " << part << '\n';
    cout << "find_pattern: " << found_index << '\n';
    cout << "reversed: " << reversed << '\n';
    cout << "merged: " << s + "_" + pattern << '\n';
    return 0;
}
