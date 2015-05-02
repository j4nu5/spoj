#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int N;
    cin >> N;

    vector<int> men(N), women(N);
    for (int i = 0; i < N; i++)
      cin >> men[i];
    for (int i = 0; i < N; i++)
      cin >> women[i];

    sort(men.begin(), men.end());
    sort(women.begin(), women.end());

    int hotness = 0;
    for (int i = 0; i < N; i++)
      hotness += (men[i] * women[i]);

    cout << hotness << "\n";
  }
  return 0;
}
