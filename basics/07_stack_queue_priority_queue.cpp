#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - stack: 後入れ先出し
      - queue: 先入れ先出し
      - priority_queue: 優先度の高い要素から取り出す

    入力:
      n
      a0 a1 ... a(n-1)

    ミニ入力例:
      4
      5 1 4 2

    ミニ出力例:
      stack_order: 2 4 1 5
      queue_order: 5 1 4 2
      min_heap_order: 1 2 4 5
*/

int main() {
    int n;
    cin >> n;

    stack<int> st;
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.push(x);
        q.push(x);
        min_heap.push(x);
    }

    cout << "stack_order:";
    while (!st.empty()) {
        cout << ' ' << st.top();
        st.pop();
    }
    cout << '\n';

    cout << "queue_order:";
    while (!q.empty()) {
        cout << ' ' << q.front();
        q.pop();
    }
    cout << '\n';

    cout << "min_heap_order:";
    while (!min_heap.empty()) {
        cout << ' ' << min_heap.top();
        min_heap.pop();
    }
    cout << '\n';
    return 0;
}
