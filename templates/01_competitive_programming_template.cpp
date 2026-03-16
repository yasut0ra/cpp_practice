#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 競プロでよく使う型エイリアス
      - chmin / chmax
      - INF の置き方
      - 方向配列
      - ループマクロ

    直感メモ:
      - テンプレは「最初に持っていく工具箱」
      - ただし工具の名前と用途が分からないまま増やすと、逆に手が止まる

    ミニ入力例:
      5
      4 1 7 3 2

    ミニ出力例:
      sum: 17
      min: 1
      max: 7
      direction_example: (1, 0)
      linf_example: 2305843009213693951

    注意:
      - テンプレは短く書けて便利だが、意味を理解せずにコピペすると危ない
      - まずは関数や定数が何をしているか読めるようになるのが先
*/

using ll = long long;

template <class T>
bool chmin(T& current, const T& candidate) {
    if (current <= candidate) {
        return false;
    }
    current = candidate;
    return true;
}

template <class T>
bool chmax(T& current, const T& candidate) {
    if (current >= candidate) {
        return false;
    }
    current = candidate;
    return true;
}

constexpr int INF = numeric_limits<int>::max() / 4;
constexpr ll LINF = numeric_limits<ll>::max() / 4;
constexpr array<int, 4> dx = {1, 0, -1, 0};
constexpr array<int, 4> dy = {0, 1, 0, -1};

// REP(i, n) は i = 0 から n - 1 まで回す省略記法。
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    REP(i, n) {
        cin >> a[i];
    }

    ll sum = 0;
    int minimum_value = INF;
    int maximum_value = -INF;

    REP(i, n) {
        sum += a[i];
        chmin(minimum_value, a[i]);
        chmax(maximum_value, a[i]);
    }

    cout << "sum: " << sum << '\n';
    cout << "min: " << minimum_value << '\n';
    cout << "max: " << maximum_value << '\n';
    cout << "direction_example: (" << dx[0] << ", " << dy[0] << ")" << '\n';
    cout << "linf_example: " << LINF << '\n';
    return 0;
}
