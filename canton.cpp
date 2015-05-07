#include <iostream>
#include <algorithm>

using namespace std;

long long FindSeries(long long n) {
  long long lo = 0, hi = n;
  while (lo < hi) {
    long long m = lo + (hi-lo)/2;

    long long p = (m * (m + 1)) / 2;
    if (p >= n)
      hi = m;
    else
      lo = m + 1;
  }

  return lo;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;
    long long N = FindSeries(n);

    long long denominator = n - (N * (N - 1)) / 2;
    if (N % 2 == 0)
      denominator = N + 1 - denominator;

    long long numerator = N + 1 - denominator;
    cout << "TERM " << n << " IS " << numerator << "/" << denominator << "\n";
  }
  return 0;
}
