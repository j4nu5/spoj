#include <iostream>
#include <algorithm>

using namespace std;

int digs[][4] = {
  {0, 0, 0, 0},
  {1, 1, 1, 1},
  {2, 4, 8, 6},
  {3, 9, 7, 1},
  {4, 6, 4, 6},
  {5, 5, 5, 5},
  {6, 6, 6, 6},
  {7, 9, 3, 1},
  {8, 4, 2, 6},
  {9, 1, 9, 1}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    long long a, b;
    cin >> a >> b;

    a = a % 10;
    int result = 0;
    if (a) {
      if (!b) {
        result = 1;
      }
      else {
        b = (b - 1) % 4;
        result = digs[a][b];
      }
    }

    cout << result << "\n";
  }
  return 0;
}
