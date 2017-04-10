// https://arena.topcoder.com/#/u/practiceCode/16319/46378/13642/1/325040

// You are given two s: N and K. Lun the dog is interested in strings that satisfy the following conditions:
//
// The string has exactly N characters, each of which is either 'A' or 'B'.
// The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.
// If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class AB {
public:
  string createString(int N, int K) {
    string ans(N, 'B');

    int countA = 0;
    int pairs = 0;
    for(int i = 1; i <= N; i++) {
      int newPairs = N - i;
      if((pairs - countA) + newPairs <= K) {
        pairs = (pairs - countA) + newPairs;
        countA += 1;
        ans[i - 1] = 'A';
      }
      if(pairs == K) {
        return ans;
      }
    }
    return "";
  }
};

int main() {
  AB ab;
  cout << ab.createString(10, 12);
}
