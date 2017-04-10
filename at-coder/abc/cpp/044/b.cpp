#include <iostream>
#include <math.h>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;

int main()
{
  string w;

  cin >> w;
  w.sort();

  char prev = w[0];

  for(int i = 1; i < w.length(); i++) {
    // odd
    if(prev != w[i]) {
      cout << "No" << endl;
      break;
    } else {
      prev = w[i];
    }
  }
  cout << "Yes" << endl;
}
