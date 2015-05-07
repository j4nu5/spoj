#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool AllNines(const string& str) {
  for (char ch : str)
    if (ch != '9')
      return false;
  return true;
}

string Add(const string& str, int n) {
  string result;
  int carry = n;
  for (int i = str.length() - 1; i >= 0; i--) {
    int r = (str[i] - '0') + carry;
    result += (r % 10) + '0';
    carry = r / 10;
  }
  if (carry)
    result += carry + '0';
  reverse(result.begin(), result.end());

  return result;
}

string Construct(const string& first_half, int target_length) {
  string second_half = first_half;
  reverse(second_half.begin(), second_half.end());

  if (target_length & 1)
    second_half = second_half.substr(1);

  return first_half + second_half;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  cin.ignore(1, '\n');

  while (t--) {
    string num;
    cin >> num;
    int n = num.length();

    if (AllNines(num)) {
      cout << Add(num, 2) << "\n";
    }
    else if (n == 1) {
      cout << Add(num, 1) << "\n";
    }
    else {
      string first_half = num.substr(0, (n + 1) / 2);
      string result = Construct(first_half, n);

      if (result <= num) {
        first_half = Add(first_half, 1);
        result = Construct(first_half, n);
      }

      cout << result << "\n";
    }
  }
  return 0;
}
