#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define ll long long

int main()
{
  int64_t N, x, crnt, prev = 0, cnt = 0;

  cin >> N >> x;

  for(int i = 0; i < N; i++) {
    cin >> crnt;

    if(prev + crnt > x) {
      cnt += (prev + crnt) - x;
      crnt -= (prev + crnt) - x;
    }
    prev = crnt;
  }

  cout << cnt << endl;
}
