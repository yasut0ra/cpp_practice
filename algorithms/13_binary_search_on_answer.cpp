#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 答えに対する二分探索
      - 単調な判定関数を作る方法
      - 最大値 / 最小値を高速に探す考え方

    直感メモ:
      - 配列を探すのではなく、「この答えは可能か？」を白黒判定する
      - 可能な長さは全部 OK、ある長さを超えると全部 NG、という境界線を探す

    問題設定:
      長さの配列 lengths から、長さ x の piece を合計 k 本以上切り出したい。
      可能な x の最大値を求める。

    入力:
      n k
      lengths

    ミニ入力例:
      3 5
      8 7 6

    ミニ出力例:
      maximum_length: 3
*/

bool can_make(const vector<long long>& lengths, long long k, long long piece_length) {
    long long count = 0;
    for (long long length : lengths) {
        count += length / piece_length;
    }
    return count >= k;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    long long ok = 0;
    long long ng = *max_element(lengths.begin(), lengths.end()) + 1;

    while (ng - ok > 1) {
        long long mid = (ok + ng) / 2;
        if (can_make(lengths, k, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << "maximum_length: " << ok << '\n';
    return 0;
}
