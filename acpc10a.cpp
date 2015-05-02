#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string line;
  while (getline(cin, line)) {
    long long a, b, c;
    {
      stringstream ss(line);
      ss >> a >> b >> c;
    }

    if (!a && !b && !c)
      break;

    if ((b - a) == (c - b)) {
      cout << "AP " << 2 * c - b << "\n";
    }
    else {
      cout << "GP " << (c * c) / b << "\n";
    }
  }
  return 0;
}
