#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  int K, S;
  int cnt = 0;
  int z = 0;

  cin >> K >> S;

  for(int x = 0; x <= K; x++) {
    for(int y = 0; y <= K; y++) {
      z = S - x - y;
      if(z >= 0 && z <= K) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}