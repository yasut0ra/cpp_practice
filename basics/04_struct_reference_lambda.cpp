#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - struct に複数の情報をまとめる
      - 参照渡しで元の配列を書き換える
      - const 参照でコピーを避ける
      - ラムダ式でソート条件を書く

    入力:
      n bonus
      name_0 score_0
      ...
      name_(n-1) score_(n-1)

    ミニ入力例:
      3 5
      Taro 60
      Hanako 75
      Jiro 75

    ミニ出力例:
      total_score: 225
      ranking:
      Hanako 80
      Jiro 80
      Taro 65
*/

struct Student {
    string name;
    int score;
};

void add_bonus(vector<Student>& students, int bonus) {
    // 参照で受けるので、この関数の変更が呼び出し元にも反映される。
    for (auto& student : students) {
        student.score += bonus;
    }
}

int total_score(const vector<Student>& students) {
    int total = 0;
    for (const auto& student : students) {
        total += student.score;
    }
    return total;
}

int main() {
    int n, bonus;
    cin >> n >> bonus;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].score;
    }

    add_bonus(students, bonus);

    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {
        if (left.score != right.score) {
            return left.score > right.score;
        }
        return left.name < right.name;
    });

    cout << "total_score: " << total_score(students) << '\n';
    cout << "ranking:" << '\n';
    for (const auto& student : students) {
        cout << student.name << ' ' << student.score << '\n';
    }
    return 0;
}
