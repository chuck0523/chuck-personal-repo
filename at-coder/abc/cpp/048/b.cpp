#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  long long a, b, x, i;

  cin >> a >> b >> x;

  if(a > 0){
		cout << b / x - (a - 1) / x << endl;
	}
	if(a == 0){
		cout << b / x + 1 << endl;
	}
}

// better answer
