#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int N;
  cin >> N;

  int sum = 0;

  for(int i = 1; i <= N; i++) {
    sum += i;
  }

  cout << sum << endl;
}
