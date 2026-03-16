#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - LIS (Longest Increasing Subsequence)
      - O(n log n) 解法
      - 長さだけでなく実際の部分列を復元する方法

    入力:
      n
      a0 a1 ... a(n-1)

    出力:
      LIS の長さ
      復元した 1 つの LIS

    補足:
      - strictly increasing を求めている
      - non-decreasing にしたいなら lower_bound / upper_bound を見直す
*/

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp;
    vector<int> dp_index;
    vector<int> prev_index(n, -1);

    for (int i = 0; i < n; ++i) {
        int pos = static_cast<int>(lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin());

        if (pos == static_cast<int>(dp.size())) {
            dp.push_back(a[i]);
            dp_index.push_back(i);
        } else {
            dp[pos] = a[i];
            dp_index[pos] = i;
        }

        if (pos > 0) {
            prev_index[i] = dp_index[pos - 1];
        }
    }

    vector<int> lis;
    int current = dp_index.back();
    while (current != -1) {
        lis.push_back(a[current]);
        current = prev_index[current];
    }
    reverse(lis.begin(), lis.end());

    cout << "length: " << lis.size() << '\n';
    cout << "sequence:";
    for (int x : lis) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}
