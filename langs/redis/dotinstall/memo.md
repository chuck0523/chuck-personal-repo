# ドットインストールメモ

## 特徴

- インメモリデータベース（速い）
- 永続化（定期的にディスクに書き出す）
- データ構造サーバ


## 公式サイト

コマンドをインタラクティブに試すことができる。


## KVS(Key Value Store)

DatabaseにKeyとValueのセットで保存

## DataType

String, List, Set, Sorted Set, Hash

- String: 個々の要素、基本的な方
- List: 順番に並べた複数の要素, 時系列データに最適
- Set: 順不同の複数の要素、重複を許さない, タグ・ソーシャルグラフに最適
- Sorted Set: Setの特徴を持ちつつ、個々の要素に重み付けのためのスコアがついている。
- Hash: 連想配列, わかりやすいラベルと値のセット

## サーバの起動と終了

$ redis-server # 起動
(CTRL + C で強制終了)

## クライアントの起動と終了

$ redis-cli # 起動
\> exit # 終了
\> shutdow # 終了。ただしデータ保存をしてくれる

## データベースの選択

DBは0~15が用意されている。デフォルトでは0番。

\> select 10 # 10番のDBを使用


## データの保存

\> bgsave # backgroundで保存

データの保存先としては、当該ディレクトリにdump.rdbが生成される。

## データの格納

### String

$ set key value
$ mset key value key value... # 複数保存
$ get key
$ mget key key key

整数値っぽい値には、
incr/ incrby
decr/ decrby
というメソッドが使える

### Key操作を覚える

\> keys * # 全keyを取得
\> keys \*m* # mを含むものを取得
\> exists hoge # keyが存在するかどうか, 1||0で返る
\> del hoge # keyの削除
\> expire hoge 10 # hogeを10秒後に削除
\> randomkey # 文字通り

### List

[key] [value]

mycolor: red blue yellow pink green

要素の追加: (l/r)push
要素の削除: (l/r)pop
(l/r): 左と右どちらに行うか

\> lrange mycolor 0 5 # 要素を0から5番目まで表示
\> lrange mycolor 0 -1 # 要素を0番目から最後まで表示
\> lindex mycolor 3 # 単数取得
\> llen mycolor # 要素数取得
\> ltrim mycolor 0 2 # トリム

### Set

追加: sadd
削除: srem

一覧: smembers

和集合: sunion
積集合: sinter
差集合: sdiff

\> sunionstore myunion myset1 myset2 # 和集合をmyunionという名前で新規作成

### Sorted Set

追加: zadd
削除: zrem

一覧: zrange （降順: zrevrange）
ランク: zrank

### Hash

key value

set: hset, hmset
get: hget, hmget

hlen

hkeys
hvals

hgetall

## Sortコマンド

List, Set, Sorted Setに対して使える

sort mycolor alpha desc: 文字列を降順でソート


## Transactionっぽいもの

ある複数の処理をやりたい時用。

multi
処理
処理
処理
exec/discard

他の処理が割り込んでこない。
ただし、途中で何かしらのエラーが起きても、整合性が取れるわけではない=完全ではない
