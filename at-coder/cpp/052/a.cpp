#include <iostream>
#include <cmath>

using namespace std;


int main()
{
  int A,B,C,D;
  int rect1, rect2;

  cin >> A >> B >> C >> D;

  rect1 = A * B;
  rect2 = C * D;

  if(rect1 > rect2) {
    cout << rect1 << endl;
  } else {
    cout << rect2 << endl;
  }
  return 0;
}

// better answer
// 1. use max of cmath
//  #include <cmath>
//  cout << max(A*B, C*D) << endl;
