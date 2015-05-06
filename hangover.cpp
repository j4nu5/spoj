#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<long double> hangs;
  hangs.push_back(0);
  for (int i = 1; hangs[i-1] <= 5.3; i++) {
    hangs.push_back(hangs[i-1] + 1.0F / (i+1));
  }

  long double c;
  while (cin >> c) {
    if (c <= 0.00)
      break;

    auto it = lower_bound(hangs.begin(), hangs.end(), c);
    cout << it - hangs.begin() << " card(s)\n";
  }
  return 0;
}
