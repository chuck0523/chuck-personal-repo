#include <iostream>
#include <string>
#include <vector>

// io
using std::cout;
using std::endl;

// data type
using std::string;
using std::vector;

// method
using std::reverse; // http://en.cppreference.com/w/cpp/algorithm/reverse

#define ONE_CHAR 3


// 文字列の逆順
void _00()
{
  string S = "stressed";
  reverse(S.begin(), S.end());
  cout << S << endl; // desserts
}

// 「パタトクカシーー」
void _01()
{

  string S = "パタトクカシーー";

  for(int i = 0; i < 4; i++) {
    cout << S.substr(i * ONE_CHAR * 2, ONE_CHAR);
  }
  cout << endl;
}

// 「パトカー」＋「タクシー」＝「パタトクカシーー」
void _02()
{
  string S1 = "パトカー";
  string S2 = "タクシー";
  for(int i = 0; i < 4; i++) {
    cout << S1.substr(i * ONE_CHAR, ONE_CHAR);
    cout << S2.substr(i * ONE_CHAR, ONE_CHAR);
  }
  cout << endl;
}

// 円周率
void _03()
{
  string S = "Now I need a drink, alcoholic of course, after the heavy lectures involving quantum mechanics.";
  vector<char> vec;
  char pre;
  for(int i = 0; i < S.length(); i++) {
    if(i == 0 || pre == ' ') {
      vec.push_back(S[i]);
    }
    pre = S[i];
  }
  // NInadaocathliqm
}

// 元素記号
bool isOnePrefix(size_t index) {
  return index == 1 || index == 5 || index == 6 || index == 7 || index == 8 ||
    index == 9 || index == 15 || index == 16 || index == 19;
}

void _04()
{
  string S = "Hi He Lied Because Boron Could Not Oxidize Fluorine. New Nations Might Also Sign Peace Security Clause. Arthur King Can.";
  vector<string> vec;
  string tmp;
  for(size_t i = 0; i < S.length(); i++) {
    tmp += S[i];
    if(S[i] == ' ' || i == S.length() - 1) {
      string prefix = isOnePrefix(vec.size() + 1) ? tmp.substr(0, 1) : tmp.substr(0, 2);
      vec.push_back(prefix);
      tmp.erase();
    }
  }
  // H, He, Li, Be, B, C, N, O, F, Ne, Na, Mi, Al, Si, P, S, Cl, Ar, K, Ca
}

int main()
{
  _04();
}
