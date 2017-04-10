#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int N, K;

  cin >> N >> K;

  cout << int(K * pow(K - 1, N - 1)) << endl;
}
