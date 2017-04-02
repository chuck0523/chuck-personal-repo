#include <iostream>
#include <math.h>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::bitset;

int main()
{
  string S;
  cin >> S;

  int len = S.length();

  long long sum = 0;

  for(int i = 0; i < (1 << (len - 1)); i++) {
    string isPlus = bitset<9>(i).to_string().substr(10 - len);

    string num;
    for(int j = 0; j < 2 * len - 1; j++) {
      if(j % 2 == 0) {
        num += S[j / 2];
      } else {
        if(isPlus[floor(j / 2)] == '1') {
          sum += stoll(num);
          num.clear();
        }
      }
    }
    sum += stoll(num);
  }
  cout << sum << endl;
}
