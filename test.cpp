#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  while ((cin >> n) && (n != 42))
    cout << n << "\n";

  return 0;
}
