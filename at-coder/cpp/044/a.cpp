#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;

  if(N < K) {
    cout << N * X << endl;    
  } else {
    cout << K * X + (N - K) * Y << endl;
  }
}
