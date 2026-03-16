# C++ 学習用コード集

このリポジトリは、C++ と競技プログラミングを段階的に学ぶための教材集です。
各ファイルは「単体で読める」「単体でコンパイルできる」ことを重視しています。

基本文法から始めて、データ構造、グラフ、動的計画法、競プロ定番テクニックまで順番に積み上げられる構成にしています。

## 対象読者

- C++ をこれから勉強したい人
- 競技プログラミングの定番解法を整理したい人
- 手元で動かしながらアルゴリズムを理解したい人

## 特徴

- 1 ファイル 1 テーマで学べる
- 各ファイルに「何を学ぶか」「入力形式」「見るべきポイント」のコメント付き
- 重めのテーマには「直感メモ」を入れて、最初の取っかかりを作っている
- そのまま `g++` でコンパイルして動かせる
- 学習順を README に整理している

## 使い方

1. まずファイル先頭のコメントを読む
2. 入力例を自分で作って実行する
3. 途中の変数を紙に書いて追う
4. 少しだけ改造する
5. 最後に白紙から書き直す

## 読み方のコツ

- 最初から厳密に理解しようとしすぎない
- まずは「このアルゴリズムは何をうまくサボっているのか」を掴む
- そのあとで、配列やキューや DP テーブルの中身を追う

この教材では、重めのファイルに短い `直感メモ` を入れています。
最初の理解は雑でもいいので、その一言で絵を作ってからコードを読むと入りやすいです。

たとえば:

- 二分探索: 白黒の境界線を探す
- BFS: 水が近いマスから順に広がる
- DP: 各地点までの「最小コストのメモ」を前から埋める
- Segment Tree: 配列を半分ずつ束ねた集計木

## ローカルでの確認

### 単体コンパイル例

```bash
g++ -std=c++17 -O2 -Wall -Wextra basics/01_io_and_types.cpp -o basics01
./basics01
```

### 全ファイルまとめて確認

```bash
./scripts/check_all.sh
```

GitHub Actions でも同じ確認を回すようにしてあります。

## 学習ロードマップ

### Phase 1: 基本文法

1. `basics/01_io_and_types.cpp`
2. `basics/02_control_flow_and_functions.cpp`
3. `basics/03_vector_map_set.cpp`
4. `basics/04_struct_reference_lambda.cpp`

### Phase 2: 競プロでよく使う部品

5. `templates/01_competitive_programming_template.cpp`
6. `templates/02_utility_template.cpp`

### Phase 3: 基本アルゴリズム

7. `algorithms/01_binary_search.cpp`
8. `algorithms/02_prefix_sum.cpp`
9. `algorithms/03_bfs_grid.cpp`
10. `algorithms/04_union_find.cpp`
11. `algorithms/05_dijkstra.cpp`
12. `algorithms/06_dfs_recursive.cpp`
13. `algorithms/07_dynamic_programming.cpp`
14. `algorithms/08_topological_sort.cpp`
15. `algorithms/09_segment_tree.cpp`
16. `algorithms/10_longest_increasing_subsequence.cpp`
17. `algorithms/11_warshall_floyd.cpp`

### Phase 4: 競プロ定番テクニック

18. `competitive/01_fast_io_and_multiple_tests.cpp`
19. `competitive/02_coordinate_compression.cpp`
20. `competitive/03_bit_enumeration.cpp`
21. `competitive/04_two_pointers.cpp`
22. `competitive/05_mod_pow_and_combination.cpp`
23. `competitive/06_imos_1d.cpp`
24. `competitive/07_monotonic_stack.cpp`
25. `competitive/08_meet_in_the_middle.cpp`

## ファイル一覧

### basics

- `01_io_and_types.cpp`
  - `cin` / `cout`
  - `int`, `long long`, `double`, `bool`, `string`
  - 型変換とオーバーフローの基本
- `02_control_flow_and_functions.cpp`
  - `if`, `for`, `while`
  - 関数分割
  - 配列をなめる基本パターン
- `03_vector_map_set.cpp`
  - `vector`、`sort`
  - `set` による重複除去
  - `map` による頻度カウント
- `04_struct_reference_lambda.cpp`
  - `struct`
  - 参照渡し / 定数参照
  - ラムダ式によるソート

### templates

- `01_competitive_programming_template.cpp`
  - `chmin` / `chmax`
  - `INF`
  - 方向配列
  - ループマクロ
- `02_utility_template.cpp`
  - `print_vector`
  - 座標圧縮の汎用関数
  - 復元テーブルの持ち方

### algorithms

- `01_binary_search.cpp`
  - 手書き二分探索
  - `lower_bound`
  - 不変条件の考え方
- `02_prefix_sum.cpp`
  - 累積和
  - 半開区間 `[l, r)` の扱い
- `03_bfs_grid.cpp`
  - グリッド最短路
  - BFS とキュー
- `04_union_find.cpp`
  - 結合判定
  - 経路圧縮
  - union by size
- `05_dijkstra.cpp`
  - 重み付き最短路
  - 優先度付きキュー
  - 経路復元
- `06_dfs_recursive.cpp`
  - 再帰 DFS
  - 連結成分分解
- `07_dynamic_programming.cpp`
  - 1 次元 DP
  - 遷移式
  - 復元
- `08_topological_sort.cpp`
  - トポロジカルソート
  - DAG
  - 入次数管理
- `09_segment_tree.cpp`
  - Segment Tree
  - 1 点更新
  - 区間和クエリ
- `10_longest_increasing_subsequence.cpp`
  - LIS
  - O(n log n)
  - 復元
- `11_warshall_floyd.cpp`
  - 全点対最短路
  - 3 重ループ DP
  - 負閉路検出

### competitive

- `01_fast_io_and_multiple_tests.cpp`
  - `solve()` 形式
  - 高速入出力
  - 複数テストケース
- `02_coordinate_compression.cpp`
  - 値の圧縮
  - 添字への置き換え
- `03_bit_enumeration.cpp`
  - bit 全探索
  - 部分集合の表現
- `04_two_pointers.cpp`
  - しゃくとり法
  - 区間を動かす考え方
- `05_mod_pow_and_combination.cpp`
  - 繰り返し二乗法
  - `nCr mod MOD`
  - 逆元
- `06_imos_1d.cpp`
  - いもす法
  - 差分配列
  - 区間加算
- `07_monotonic_stack.cpp`
  - 単調スタック
  - 近い要素の探索
  - O(n) 処理
- `08_meet_in_the_middle.cpp`
  - 半分全列挙
  - 部分和
  - `n <= 40` 付近の典型

## 勉強のコツ

- コードを読むだけでは弱いので、必ず 1 回は自分で写経せずに書き直してください。
- `vector<int>` を `vector<long long>` に変える、0-index を 1-index に変える、といった小改造をすると理解が定着しやすいです。
- アルゴリズム系は「何を状態として持つか」「どこで更新するか」を口で説明できるまで詰めると強いです。
- 詰まったら、入力をかなり小さくして 3 要素や 4 頂点で手計算してください。大抵そこに理解の穴があります。

## 公開向けメモ

- `LICENSE` は MIT にしています
- `scripts/check_all.sh` で全サンプルのコンパイル確認ができます
- `.github/workflows/build.yml` で push / pull request 時に自動ビルドします

## License

MIT
