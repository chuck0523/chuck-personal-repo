#include <iostream>
#include <math.h>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main()
{
  // each string
  unordered_map<char, string> cards;
  cin >> cards['a'] >> cards['b'] >> cards['c'];

  // index for each string
  unordered_map<char, int> indexes;
  indexes['a'] = 0;
  indexes['b'] = 0;
  indexes['c'] = 0;

  char target = 'a';

  // run
  while(true) {
    int index = indexes[target];
    char card = cards[target][index];

    // reach the final card
    if(index >= cards[target].length()) {
      // result
      cout << char(toupper(target)) << endl;
      break;
    } else {
      target = card;
      indexes[target] += 1;
    }
  }
}
