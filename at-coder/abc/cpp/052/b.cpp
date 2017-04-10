#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
  int N;
  string S;

  cin >> N >> S;

  vector<int> vec;
  vec.push_back(0);

  for(int i = 0; i < N; i++) {
    vec.push_back((S[i] == 'I') ? vec[i] + 1 : vec[i] - 1);
  }
  cout << *std::max_element(vec.begin(), vec.end()) << endl;

  return 0;
}

// better answer
// don't need to use vector
// 
// for (char c : s) {
//  if (c == 'I') {
//    x++;
//  } else {
//    x--;
//  }
// m = max(m, x);
