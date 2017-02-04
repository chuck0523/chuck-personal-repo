#include <iostream>

using namespace std;

int main()
{
  string str;
  int head, tail;

  cin >> str;

  head = str.find('A');
  tail = str.rfind('Z');

  cout << str.substr(head, (tail - head + 1)).length();
}

// better answer

// 1. don't need to substr
//  cout << head - tail + 1 << endl;

// 2. return 0 at the end of main function
//   not must. But feel it better
