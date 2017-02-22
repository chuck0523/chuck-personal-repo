#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

int main()
{
  int W, H, N, x, y, a;

  cin >> W >> H >> N;

  int left = 0, right = W, bottom = 0, top = H;

  for(int i = 0; i < N; i++) {
    cin >> x >> y >> a;
    switch(a) {
      case 1: // kill left
        left =  max(x, left);
        break;
      case 2: // kill right
        right = min(x, right);
        break;
      case 3: // kill below
        bottom = max(y, bottom);
        break;
      case 4: // kill above
        top = min(y, top);
        break;
      default:
        break;
    }
  }

  int width = max(right - left, 0);
  int height = max(top - bottom, 0);

  cout << width * height << endl;
}
