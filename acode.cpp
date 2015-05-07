#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string message;
  while (cin >> message) {
    if (message == "0")
      break;

    int N = message.length();
    vector<long long> dp(N, 0);

    if (message[N-1] != '0')
      dp[N-1]++;

    for (int i = N-2; i >= 0; i--) {
      if (message[i] != '0') {
        dp[i] += dp[i+1];

        int n = (message[i] - '0') * 10 + (message[i+1] - '0');
        if (n >= 1 && n <= 26) {
          if (i+2 < N)
            dp[i] += dp[i+2];
          else
            dp[i]++;
        }
      }
    }

    cout << dp[0] << "\n";
  }
  return 0;
}
