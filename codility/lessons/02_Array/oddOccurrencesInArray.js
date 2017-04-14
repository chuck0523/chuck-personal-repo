function solution(N) {
  let ary = N.sort((a, b) => a - b)
  for(let i = 0; i <= N.length; i += 2) {
    if(ary[i] != ary[i + 1]) {
      return ary[i]
    }
  }
}
