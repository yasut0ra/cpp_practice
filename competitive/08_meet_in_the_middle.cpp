#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 半分全列挙 (meet-in-the-middle)
      - 2^n が大きすぎるときに、配列を半分に分ける発想

    問題設定:
      n 個の重さからいくつか選び、合計を limit 以下で最大化する。

    入力:
      n limit
      w0 w1 ... w(n-1)

    制約感:
      - n <= 40 くらいを想定
      - 全探索 O(2^n) は厳しい
      - 2^(n/2) ずつなら現実的
*/

vector<long long> enumerate_subset_sums(const vector<long long>& values) {
    vector<long long> sums;
    int n = static_cast<int>(values.size());

    for (int mask = 0; mask < (1 << n); ++mask) {
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                total += values[i];
            }
        }
        sums.push_back(total);
    }

    sort(sums.begin(), sums.end());
    return sums;
}

int main() {
    int n;
    long long limit;
    cin >> n >> limit;

    vector<long long> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    vector<long long> left(weight.begin(), weight.begin() + n / 2);
    vector<long long> right(weight.begin() + n / 2, weight.end());

    vector<long long> left_sums = enumerate_subset_sums(left);
    vector<long long> right_sums = enumerate_subset_sums(right);

    long long answer = 0;

    for (long long x : left_sums) {
        if (x > limit) {
            continue;
        }

        long long remain = limit - x;
        auto it = upper_bound(right_sums.begin(), right_sums.end(), remain);
        if (it == right_sums.begin()) {
            answer = max(answer, x);
            continue;
        }

        --it;
        answer = max(answer, x + *it);
    }

    cout << "best_sum: " << answer << '\n';
    return 0;
}
