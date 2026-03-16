#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - BFS は「重みなしグラフの最短路」を求める
      - グリッドも頂点と辺の集まりとして扱える
      - queue に入れた順番に広げると最短距離になる

    入力:
      h w
      grid

    文字の意味:
      S: スタート
      G: ゴール
      .: 通れる
      #: 壁
*/

bool inside(int row, int col, int h, int w) {
    return 0 <= row && row < h && 0 <= col && col < w;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    pair<int, int> start = {-1, -1};
    pair<int, int> goal = {-1, -1};

    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            if (grid[row][col] == 'S') {
                start = {row, col};
            }
            if (grid[row][col] == 'G') {
                goal = {row, col};
            }
        }
    }

    if (start.first == -1 || goal.first == -1) {
        cout << -1 << '\n';
        return 0;
    }

    constexpr array<int, 4> dr = {1, 0, -1, 0};
    constexpr array<int, 4> dc = {0, 1, 0, -1};

    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int next_row = row + dr[dir];
            int next_col = col + dc[dir];

            if (!inside(next_row, next_col, h, w)) {
                continue;
            }
            if (grid[next_row][next_col] == '#') {
                continue;
            }
            if (dist[next_row][next_col] != -1) {
                continue;
            }

            dist[next_row][next_col] = dist[row][col] + 1;
            q.push({next_row, next_col});
        }
    }

    cout << dist[goal.first][goal.second] << '\n';
    return 0;
}
