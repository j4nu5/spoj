#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

void Trim(string& s) {
  int pos = 0;
  while (pos <= s.length() && s[pos] == '0')
    pos++;

  if (pos == s.length()) {
    s = "0";
  }
  else {
    s = s.substr(pos);
  }
}

string Subtract(const string& x, const string& b) {
  string a = x;
  string result;

  int pa = a.length() - 1, pb = b.length() - 1;
  while (pa >= 0 && pb >= 0) {
    int da = a[pa] - '0';
    int db = b[pb] - '0';

    if (da >= db) {
      result += (da - db + '0');
    }
    else {
      int tmp = pa - 1;

      assert(tmp >= 0);
      while (tmp >= 0 && a[tmp] == '0') {
        a[tmp] = '9';
        tmp--;
      }
      assert(tmp >= 0);

      a[tmp] -= 1;
      result += (10 + da - db + '0');
    }

    pa--;
    pb--;
  }

  while (pa >= 0) {
    result += a[pa];
    pa--;
  }
  reverse(result.begin(), result.end());
  Trim(result);

  return result;
}

string Multiply(const string& s, int n) {
  string result;

  int pos = s.length() - 1;
  int carry = 0;

  while (pos >= 0) {
    int d = s[pos] - '0';
    int r = d * n + carry;

    carry = r / 10;
    r = r % 10;

    result += (r + '0');
    pos--;
  }
  if (carry) {
    result += (carry + '0');
  }
  reverse(result.begin(), result.end());

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int t = 0; t < 10; t++) {
    string n, k;
    cin >> n >> k;

    string diff = Subtract(n, k);
    string natalia = Multiply(diff, 5);
    if (natalia.length() > 1)
      natalia.pop_back();
    else
      natalia = "0";

    string klaudia = Subtract(n, natalia);

    cout << klaudia << "\n" << natalia << "\n";
  }

  return 0;
}
