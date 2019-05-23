# TIL

TIL in golang

## 2019/05/23

### strconv.ParseFloat

`string -> float` には `strconv.ParseFloat` を使う。
第一引数が対象文字列、第二引数が `32`, `64` など。 `32` を指定すると float32 型になる。

### strings.ReplaceAll

`strings.Replace` という関数もあるけど、全て置換したいときは `strings.ReplaceAll` を使ったほうがよいかも。
