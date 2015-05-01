#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int64;

const int64 kNumPrimes = 10000001;

vector<bool> isprime;
vector<int64> primes;

void Prep() {
  isprime.resize(kNumPrimes, true);
  isprime[0] = isprime[1] = false;

  int64 i;
  for (i = 2; i * i <= kNumPrimes; i++) {
    if (isprime[i]) {
      primes.push_back(i);

      int64 next = i * i;
      while (next < kNumPrimes) {
        isprime[next] = false;
        next += i;
      }
    }
  }
  for (; i < kNumPrimes; i++) {
    if (isprime[i])
      primes.push_back(i);
  }
}

bool IsPrime(int64 n) {
  if (n < kNumPrimes)
    return isprime[n];

  for (int64 p : primes) {
    if (p * p > n)
      break;

    if (n % p == 0)
      return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  Prep();

  int T;
  cin >> T;

  while (T--) {
    int64 m, n;
    cin >> m >> n;

    for (int64 i = m; i <= n; i++) {
      if (IsPrime(i))
        cout << i << "\n";
    }
    cout << "\n";
  }
  return 0;
}
