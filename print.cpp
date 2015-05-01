#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

typedef long long int64;

const int64 kAccuracy = 3;

random_device rd;
mt19937 rng(rd());

int64 Power(int64 a, int64 x, int64 n) {
  int64 ans = 1;

  while (x > 0) {
    if (x & 1)
      ans = (ans * a) % n;
    a = (a * a) % n;
    x >>= 1;
  }

  return ans;
}

bool IsPrime(int64 n) {
  if (n <= 1)
    return false;

  if (n <= 3)
    return true;

  if (n % 2 == 0)
    return false;

  int64 s, d;

  // n - 1 = 2^s * d : d is odd
  s = 0;
  int64 n_1 = n - 1;
  while (n_1 % 2 == 0) {
    n_1 /= 2;
    s++;
  }
  d = n_1;
  
  uniform_int_distribution<int64> distr(2, n-2);
  for (int64 run = 0; run < kAccuracy; run++) {
    int64 a = distr(rng);

    int64 x = Power(a, d, n);
    if ((x == 1) || (x == (n-1)))
      continue;

    bool prime = false;
    for (int64 i = 0; i < s-1; i++) {
      x = (x * x) % n;
      if (x == 1)
        return false;
      if (x == n-1) {
        prime = true;
        break;
      }
    }

    if (prime)
      continue;

    return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int64 m, n;
    cin >> m >> n;

    for (int64 i = m; i <= n; i++) {
      if (IsPrime(i))
        cout << i << "\n";
    }
  }
  return 0;
}
