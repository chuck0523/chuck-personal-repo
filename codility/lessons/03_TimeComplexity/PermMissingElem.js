function solution(N) {
  let n = N.length + 1
  let sum = n * (n + 1) / 2

  let arraySum = N.reduce((sum, num) => {
    sum + num
  }, 0)

  return sum - arraySum
}
