#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long kLim = 10000000;

vector<long long> dp(kLim);

void prep() {
  dp[0] = 0;
  for (long long i = 1; i < kLim; i++) {
    dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
  }
}

long long GetMaxProfit(long long n) {
  if (n < kLim)
    return dp[n];

  return max(n, GetMaxProfit(n/2) + GetMaxProfit(n/3) + GetMaxProfit(n/4));
}

int main() {
  prep();

  long long n;
  while (cin >> n) {
    cout << GetMaxProfit(n) << "\n";
  }
  return 0;
}
