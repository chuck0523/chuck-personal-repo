#include <iostream>

using namespace std;

int main()
{
  int num1, num2;
  char op;

  cin >> num1 >> op >> num2;

  if(op == '+') cout << num1 + num2 << endl;
  else  cout << num1 - num2 << endl;
}
