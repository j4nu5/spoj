#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int64;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int64 t;
  cin >> t;

  vector<int64> nums;
  for (int64 i = 0; i < 1000; i++) {
    int64 cube = i * i * i;
    if (cube % 1000 == 888)
      nums.push_back(i);
  }
  int64 x = nums.size();

  while (t--) {
    int64 k;
    cin >> k;
    k--;

    int64 a, b;
    b = k % x;
    a = k / x;

    int64 result = 1000L * a + nums[b];

    cout << result << "\n";
  }
  return 0;
}
