#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  while (cin >> N) {
    if (!N)
      break;

    vector<int> permutation(N);
    for (int i = 0; i < N; i++)
      cin >> permutation[i];

    bool ambiguous = true;
    for (int i = 0; i < N; i++) {
      if (permutation[permutation[i] - 1] != (i + 1)) {
        ambiguous = false;
        break;
      }
    }

    if (ambiguous)
      cout << "ambiguous\n";
    else
      cout << "not ambiguous\n";
  }
}
