#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  int cnt = 0;
  string S;
  cin >> S;
  int len = S.length();

  for(int i = 1; i < len; i++) {
    if(S[i] != S[i - 1]) {
      cnt++;
    }
  }

  cout << cnt << endl;
}
