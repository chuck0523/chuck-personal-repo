#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string f(string x, string y) {
  int pos = 0;
  while(pos = x.find(y, pos), pos != string::npos) {
    x.replace(pos, y.length(), "0");
    pos = x.find(y, pos + 1);
  }
  return x;
}

int main()
{
  string s;
  const string Dreamer = "dreamer";
  const string Eraser = "eraser";
  const string Dream = "dream";
  const string Erase = "erase";

  cin >> s;

  s = f(s, "eraser");
  s = f(s, "erase");
  s = f(s, "dreamer");
  s = f(s, "dream");

  cout << ( s.find_first_not_of("0") == string::npos ? "YES" : "NO" ) << endl;
}

// better answer
