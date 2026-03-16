# C++ 学習用コード集

このリポジトリは、C++ と競技プログラミングを段階的に学ぶための教材集です。
各ファイルは「単体で読める」「単体でコンパイルできる」ことを重視しています。

基本文法から始めて、データ構造、グラフ、動的計画法、競プロ定番テクニックまで順番に積み上げられる構成にしています。
最近は「まず広く触ってから、あとで深掘る」方針で、基礎トピックをかなり広めに追加しています。

## 対象読者

- C++ をこれから勉強したい人
- 競技プログラミングの定番解法を整理したい人
- 手元で動かしながらアルゴリズムを理解したい人
- 自分

## 特徴

- 1 ファイル 1 テーマで学べる
- 各ファイルに「何を学ぶか」「入力形式」「見るべきポイント」のコメント付き
- 各ファイルにそのまま試せる `ミニ入力例 / ミニ出力例` 付き
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
5. `basics/05_string_operations.cpp`
6. `basics/06_pair_tuple_and_sort.cpp`
7. `basics/07_stack_queue_priority_queue.cpp`
8. `basics/08_two_dimensional_vector.cpp`
9. `basics/09_recursion_basics.cpp`
10. `basics/10_class_and_constructor.cpp`
11. `basics/11_template_function_and_class.cpp`
12. `basics/12_pointer_and_smart_pointer.cpp`

### Phase 2: 競プロでよく使う部品

13. `templates/01_competitive_programming_template.cpp`
14. `templates/02_utility_template.cpp`

### Phase 3: 基本アルゴリズム

15. `algorithms/01_binary_search.cpp`
16. `algorithms/02_prefix_sum.cpp`
17. `algorithms/03_bfs_grid.cpp`
18. `algorithms/04_union_find.cpp`
19. `algorithms/05_dijkstra.cpp`
20. `algorithms/06_dfs_recursive.cpp`
21. `algorithms/07_dynamic_programming.cpp`
22. `algorithms/08_topological_sort.cpp`
23. `algorithms/09_segment_tree.cpp`
24. `algorithms/10_longest_increasing_subsequence.cpp`
25. `algorithms/11_warshall_floyd.cpp`
26. `algorithms/12_graph_bfs.cpp`
27. `algorithms/13_binary_search_on_answer.cpp`
28. `algorithms/14_knapsack_dp.cpp`
29. `algorithms/15_longest_common_subsequence.cpp`
30. `algorithms/16_greedy_interval_scheduling.cpp`
31. `algorithms/17_permutation_enumeration.cpp`
32. `algorithms/18_minimum_spanning_tree_kruskal.cpp`
33. `algorithms/19_bellman_ford.cpp`
34. `algorithms/20_strongly_connected_components.cpp`
35. `algorithms/21_lowest_common_ancestor.cpp`
36. `algorithms/22_tree_dp_subtree_sum.cpp`
37. `algorithms/23_bit_dp_tsp.cpp`
38. `algorithms/24_digit_dp.cpp`
39. `algorithms/25_kmp_string_search.cpp`
40. `algorithms/26_z_algorithm.cpp`

### Phase 4: 数学の基本

41. `math/01_gcd_lcm.cpp`
42. `math/02_prime_check.cpp`
43. `math/03_sieve_of_eratosthenes.cpp`
44. `math/04_prime_factorization.cpp`
45. `math/05_divisor_enumeration.cpp`
46. `math/06_mod_inverse.cpp`
47. `math/07_matrix_exponentiation.cpp`

### Phase 5: 競プロ定番テクニック

48. `competitive/01_fast_io_and_multiple_tests.cpp`
49. `competitive/02_coordinate_compression.cpp`
50. `competitive/03_bit_enumeration.cpp`
51. `competitive/04_two_pointers.cpp`
52. `competitive/05_mod_pow_and_combination.cpp`
53. `competitive/06_imos_1d.cpp`
54. `competitive/07_monotonic_stack.cpp`
55. `competitive/08_meet_in_the_middle.cpp`
56. `competitive/09_fenwick_tree.cpp`
57. `competitive/10_zero_one_bfs.cpp`
58. `competitive/11_sliding_window_minimum.cpp`

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
- `05_string_operations.cpp`
  - `string`
  - `substr`, `find`, `reverse`
  - 文字列操作
- `06_pair_tuple_and_sort.cpp`
  - `pair`, `tuple`
  - `get<>`
  - 複数条件ソート
- `07_stack_queue_priority_queue.cpp`
  - `stack`
  - `queue`
  - `priority_queue`
- `08_two_dimensional_vector.cpp`
  - 2 次元 `vector`
  - 行列入力
  - 行列集計
- `09_recursion_basics.cpp`
  - 再帰関数
  - base case
  - 小さい問題への分割
- `10_class_and_constructor.cpp`
  - `class`
  - `constructor`
  - `member function`
- `11_template_function_and_class.cpp`
  - `template`
  - 関数テンプレート
  - クラステンプレート
- `12_pointer_and_smart_pointer.cpp`
  - pointer
  - `*`, `&`
  - `unique_ptr`

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
- `12_graph_bfs.cpp`
  - グラフ BFS
  - 最短路
  - 経路復元
- `13_binary_search_on_answer.cpp`
  - 答えに対する二分探索
  - 判定関数
  - 単調性
- `14_knapsack_dp.cpp`
  - 0/1 ナップサック
  - 2 次元 DP
  - 復元
- `15_longest_common_subsequence.cpp`
  - LCS
  - 文字列 DP
  - 復元
- `16_greedy_interval_scheduling.cpp`
  - 貪欲法
  - 区間スケジューリング
  - 終了時刻ソート
- `17_permutation_enumeration.cpp`
  - `next_permutation`
  - 順列全探索
  - 全パターン列挙
- `18_minimum_spanning_tree_kruskal.cpp`
  - 最小全域木
  - Kruskal 法
  - Union-Find
- `19_bellman_ford.cpp`
  - Bellman-Ford
  - 負の辺
  - 負閉路検出
- `20_strongly_connected_components.cpp`
  - SCC
  - Kosaraju 法
  - 有向グラフの分解
- `21_lowest_common_ancestor.cpp`
  - LCA
  - binary lifting
  - 木上クエリ
- `22_tree_dp_subtree_sum.cpp`
  - Tree DP
  - 部分木集計
  - DFS + DP
- `23_bit_dp_tsp.cpp`
  - bit DP
  - TSP
  - 集合を bit で管理
- `24_digit_dp.cpp`
  - digit DP
  - tight
  - 桁ごとの状態管理
- `25_kmp_string_search.cpp`
  - KMP
  - prefix function
  - 文字列検索
- `26_z_algorithm.cpp`
  - Z-algorithm
  - 接頭辞一致長
  - 文字列前処理

### math

- `01_gcd_lcm.cpp`
  - `gcd`
  - `lcm`
  - 数学の基本演算
- `02_prime_check.cpp`
  - 素数判定
  - 試し割り
  - 最初の約数
- `03_sieve_of_eratosthenes.cpp`
  - エラトステネスのふるい
  - 素数列挙
  - 前計算
- `04_prime_factorization.cpp`
  - 素因数分解
  - 指数カウント
  - 試し割り
- `05_divisor_enumeration.cpp`
  - 約数列挙
  - ソート
  - sqrt まで探索
- `06_mod_inverse.cpp`
  - mod inverse
  - 拡張 Euclid
  - 逆元の存在条件
- `07_matrix_exponentiation.cpp`
  - 行列累乗
  - Fibonacci
  - 繰り返し二乗法

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
- `09_fenwick_tree.cpp`
  - Fenwick Tree
  - 1 点加算
  - 区間和
- `10_zero_one_bfs.cpp`
  - 0-1 BFS
  - deque
  - 0/1 重み最短路
- `11_sliding_window_minimum.cpp`
  - スライディングウィンドウ最小値
  - deque
  - O(n) 区間最小

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
