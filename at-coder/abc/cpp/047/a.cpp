#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::sort;
using std::reverse;

int main()
{
  array<int, 3> ary;
  cin >> ary[0] >> ary[1] >> ary[2];

  sort(ary.begin(), ary.end());

  cout << (( ary[2] == ary[0] + ary[1] ) ? "Yes" : "No") << endl;
}
