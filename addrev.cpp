#include <iostream>

using namespace std;

long long Reverse(long long n) {
  long long result = 0;

  while (n) {
    result = (result * 10) + (n % 10);
    n /= 10;
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    long long a, b;
    cin >> a >> b;

    a = Reverse(a);
    b = Reverse(b);

    cout << Reverse(a + b) << "\n";
  }
  return 0;
}
