#include <iostream>

using namespace std;

typedef long long int64;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int64 N;
    cin >> N;

    int64 result = 0;
    int64 p = 5, tmp = N / p;

    while (tmp) {
      result += tmp;
      p *= 5;
      tmp = N / p;
    }

    cout << result << "\n";
  }
  return 0;
}
