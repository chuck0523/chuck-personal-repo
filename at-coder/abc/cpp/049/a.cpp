#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  char c;
  string s = "aeiou";

  cin >> c;

  cout << ((s.find(c) != string::npos) ? "vowel" : "consonant") << endl;
}
