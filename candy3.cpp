#include <iostream>
#include <cassert>

using namespace std;

int main() {
  long long T;
  cin >> T;

  while (T--) {
    long long N;
    cin >> N;
    assert(N > 0);

    long long candies = 0;
    for (long long i = 0; i < N; i++) {
      long long c;
      cin >> c;
      candies = (candies + c) % N;
    }

    if (candies % N == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
