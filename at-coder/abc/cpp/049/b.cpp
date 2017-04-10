#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int h, w, i;
  string str;
  vector<string> lines;

  cin >> h >> w;

  for(i = 0; i < h; i++) {
    cin >> str;
    lines.push_back(str);
    lines.push_back(str);
  }

  vector<string>::iterator it;
  for (it = lines.begin(); it != lines.end(); it++){
    cout << *it << endl;
  }
}

// better answer
// int main()
// {
//   int h, w, i;
//   string str;
//
//   cin >> h >> w;
//
//   for(i = 0; i < h; i++) {
//     cin >> str;
//     cout << str << endl << str << endl;
//   }
// }
