#include <iostream>
#include <math.h>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string S;

  cin >> S;

  string codes;

  for(int i = 0; i < S.length(); i++) {
    if(S[i] == 'B') {
      if(codes.length() != 0) {
        codes.pop_back();  
      }
    } else {
      codes.push_back(S[i]);
    }
  }

  cout << codes << endl;
}
