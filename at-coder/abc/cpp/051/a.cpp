#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string S;
  const char separator = ' ';
  
  cin >> S;

  S[5] = separator;
  S[13] = separator;

  cout << S << endl;
}