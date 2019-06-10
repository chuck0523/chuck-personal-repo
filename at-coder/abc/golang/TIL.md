# TIL

TIL in golang

## 2019/05/23

### strconv.ParseFloat

`string -> float` には `strconv.ParseFloat` を使う。
第一引数が対象文字列、第二引数が `32`, `64` など。 `32` を指定すると float32 型になる。

### strings.ReplaceAll

`strings.Replace` という関数もあるけど、全て置換したいときは `strings.ReplaceAll` を使ったほうがよいかも。

### 空sliceの定義

いつもこのシンタックスを忘れてしまう…

```go
emptySlice := []int{}
```

## 2019/05/24

### string to int[]

JS なら `str.split().map(toInt)` 的に簡単に書ける処理が、 golang ではできない。
以下のように書く。

```go
strings := make([]string, N)
strings = strings.Split(str)

numbers := make([]int, N)
for i := 0; i < N, i++ {
  num, _ := strcnv.Atoi(strings[i])
  numbers[i] = num
}
```

[Golang: How to convert string to []int? - stackoverflow.com](https://stackoverflow.com/questions/37765687/golang-how-to-convert-string-to-int)

### pop from Slice

slice から簡潔に 1st element を削除する方法。

```go
elements := {1, 2, 3, 4}
elements = elements[1:]
```

[How do I (succinctly) remove the first element from a slice in Go? - stackoverflow.com](https://stackoverflow.com/questions/23531891/how-do-i-succinctly-remove-the-first-element-from-a-slice-in-go)

### sort Slice without comparator

comparator を指定しないソートは以下の通り

```golang
s := []int{4, 2, 3, 1}
sort.Ints(s)
fmt.Println(s) // [1 2 3 4]
```

`sort.Float64s, sort.Strings` などもある。

https://yourbasic.org/golang/how-to-sort-in-go/


### Ternary in Golang

golang ではデフォルトで ternary expression が存在しない
短く書くなら以下のとおり。

```golang
num := 0
if someBool {
  num := 1
}
```

https://stackoverflow.com/questions/26545883/how-to-do-one-liner-if-else-statement/26546039
