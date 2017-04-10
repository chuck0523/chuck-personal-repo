#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::equal;
using std::min;

typedef long long ll;
#define inf 0x7ff0000000000000

int main()
{
  int N;
  cin >> N;

  int num;
  vector<int> nums;
  nums.assign(N, 0);

  for(int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  if(equal(nums.begin() + 1, nums.end(), nums.begin())) {
    cout << 0 << endl;
    return 0;
  }

  ll lowest_cost = inf;
  for(int i = -100; i <= 100; i++) {
    ll cost = 0;
    for(int k = 0; k < N; k ++) {
      cost += (nums[k] - i) * (nums[k] - i);
    }
    lowest_cost = min(lowest_cost, cost);
  }

  cout << lowest_cost << endl;
}
