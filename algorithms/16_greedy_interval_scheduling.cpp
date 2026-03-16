#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 貪欲法
      - 区間スケジューリング
      - 「終了時刻が早いものから取る」戦略

    直感メモ:
      - 早く終わる区間を先に取ると、その後に残る余白が広くなる
      - 未来の選択肢をできるだけ残すのがコツ

    入力:
      n
      l r

    ミニ入力例:
      4
      1 3
      2 5
      4 7
      6 9

    ミニ出力例:
      count: 2
      chosen_intervals:
      1 3
      4 7
*/

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end(), [](const auto& left, const auto& right) {
        return make_pair(left.second, left.first) < make_pair(right.second, right.first);
    });

    vector<pair<int, int>> chosen;
    int current_end = -2'000'000'000;

    for (const auto& [l, r] : intervals) {
        if (current_end <= l) {
            chosen.push_back({l, r});
            current_end = r;
        }
    }

    cout << "count: " << chosen.size() << '\n';
    cout << "chosen_intervals:" << '\n';
    for (const auto& [l, r] : chosen) {
        cout << l << ' ' << r << '\n';
    }
    return 0;
}
