function solution(N) {
  let bin = N.toString(2)

  // cut off '0' at the edge of string
  let trimmedBin = bin.substring(bin.indexOf(1), bin.lastIndexOf(1) + 1)

  // length of longest '000...'
  return trimmedBin.split('1').sort().pop().length;
}
