#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int N, T, ans = 0, price = 0, profit = 0, cheapest = 0;

  cin >> N >> T;

  for(int i = 0; i < N; i++) {
    cin >> price;
    if(i == 0 || price - cheapest < 0) {
      cheapest = price;
    } else if(price - cheapest > profit) {
      ans = 1;
      profit = price - cheapest;
    } else if (price - cheapest == profit) {
      ans++;
    }
  }

  cout << ans << endl;
}
