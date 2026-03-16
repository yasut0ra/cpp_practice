#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - pair と tuple
      - get<> で値を取り出す方法
      - structured bindings
      - 複数条件でのソート

    入力:
      n
      score penalty name

    ミニ入力例:
      3
      300 20 Alice
      450 50 Bob
      450 30 Carol

    ミニ出力例:
      best_score_penalty: 450 30
      ranking:
      Carol 450 30
      Bob 450 50
      Alice 300 20
*/

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, string>> players(n);
    for (int i = 0; i < n; ++i) {
        int score, penalty;
        string name;
        cin >> score >> penalty >> name;
        players[i] = {score, penalty, name};
    }

    sort(players.begin(), players.end(), [](const auto& left, const auto& right) {
        return make_tuple(-get<0>(left), get<1>(left), get<2>(left)) <
               make_tuple(-get<0>(right), get<1>(right), get<2>(right));
    });

    pair<int, int> best_score_penalty = {get<0>(players[0]), get<1>(players[0])};
    cout << "best_score_penalty: " << best_score_penalty.first << ' ' << best_score_penalty.second << '\n';
    cout << "ranking:" << '\n';

    for (const auto& [score, penalty, name] : players) {
        cout << name << ' ' << score << ' ' << penalty << '\n';
    }
    return 0;
}
