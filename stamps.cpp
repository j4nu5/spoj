#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int need, num_friends;
    cin >> need >> num_friends;

    vector<int> f(num_friends);
    for (int i = 0; i < num_friends; i++)
      cin >> f[i];
    sort(f.begin(), f.end(), greater<int>());

    int nf = 0, s = 0;
    while (s < need && nf < num_friends) {
      s += f[nf];
      nf++;
    }

    cout << "Scenario #" << t << ":\n";
    if (s >= need) {
      cout << nf << "\n\n";
    }
    else {
      cout << "impossible\n\n";
    }
  }

  return 0;
}
