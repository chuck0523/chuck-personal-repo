#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int a, b, c, cnt;

  cin >> a >> b >> c;

  if(a == b && b == c) {
    cnt = 1;
  } else if(a == b || b == c || a == c) {
    cnt = 2;
  } else {
    cnt = 3;
  }
  cout << cnt << endl;
}
