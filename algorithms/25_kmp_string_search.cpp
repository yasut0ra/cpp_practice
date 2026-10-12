#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - KMP 法
      - prefix function
      - 文字列検索を線形時間で行う方法

    直感メモ:
      - 一致に失敗しても、すでに分かっている接頭辞の情報を使って戻り先を決める
      - text の先頭へ戻らず、pattern 内だけを賢くずらす

    図解:
      pattern = "aba" の prefix function:
        i       :  0  1  2
        pattern :  a  b  a
        pi[i]   :  0  0  1    "aba" の先頭 "a" と末尾 "a" が一致するので pi[2] = 1

      text = "ababa" を左から 1 回だけなめる:
        index   :  0  1  2  3  4
        text    :  a  b  a  b  a
        match 1 :  a  b  a           位置 0 で一致 (matched = 3)
        match 2 :        a  b  a     matched = pi[2] = 1 から再開 -> 位置 2 で一致
                         ^
                         text[2] の "a" は一致済みとして扱い、比べ直さない

    入力:
      text
      pattern

    ミニ入力例:
      ababa
      aba

    ミニ出力例:
      occurrences: 0 2
*/

vector<int> build_prefix_function(const string& s) {
    vector<int> pi(s.size(), 0);
    for (int i = 1; i < static_cast<int>(s.size()); ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> pi = build_prefix_function(pattern);
    vector<int> occurrences;

    int matched = 0;
    for (int i = 0; i < static_cast<int>(text.size()); ++i) {
        while (matched > 0 && text[i] != pattern[matched]) {
            matched = pi[matched - 1];
        }
        if (text[i] == pattern[matched]) {
            ++matched;
        }
        if (matched == static_cast<int>(pattern.size())) {
            occurrences.push_back(i - matched + 1);
            matched = pi[matched - 1];
        }
    }

    cout << "occurrences:";
    for (int index : occurrences) {
        cout << ' ' << index;
    }
    cout << '\n';
    return 0;
}
