#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const string kNA = "No Number";

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long N;
  cin >> N;

  while (N--) {
    int x, y;
    cin >> x >> y;

    if (y != x && y != (x - 2)) {
      cout << kNA << "\n";
    }
    else {
      long long result = 0;

      if (y == x) {
        result += 2;
        y -= 2;
      }

      if (x & 1) {
        result += 1;
        x--;
        y--;
      }

      long long n = x / 2;
      result += (2 + (n - 1) * 4);
      
      cout << result << "\n";
    }
  }
  return 0;
}
