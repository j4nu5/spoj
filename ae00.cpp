#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  int rectangles = 0;
  for (int b = 1; b*b <= N; b++) {
    int l = N / b;
    rectangles += (l - b + 1);
  }
  cout << rectangles << "\n";
  return 0;
}
