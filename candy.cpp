#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const int kMaxPackets = 10000;
  vector<int> packets(kMaxPackets);

  while (1) {
    int n;
    cin >> n;

    if (n == -1)
      break;

    int total = 0;
    for (int i = 0; i < n; i++) {
      cin >> packets[i];
      total += packets[i];
    }

    if (total % n) {
      cout << "-1\n";
    }
    else {
      int target = total / n;

      int result = 0;
      for (int i = 0; i < n; i++) {
        if (packets[i] < target) {
          result += (target - packets[i]);
        }
      }

      cout << result << "\n";
    }
  }
  return 0;
}
