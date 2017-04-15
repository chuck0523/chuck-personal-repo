function solution(A, K) {
  const len = A.length
  const num = K % len

  if(len === 0 || len === 1 || K === 0 || len === K) {
    return A
  }

  return [...A.slice(len - num, len), ...A.slice(0, len - num)]
}
