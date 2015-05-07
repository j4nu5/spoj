#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

bool IsNumber(const string& str) {
  for (char ch : str)
    if (ch < '0' || ch > '9')
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long t;
  cin >> t;
  cin.ignore(1, '\n');

  while (t--) {
    string expression;
    cin.ignore(1, '\n');
    getline(cin, expression);

    string token;
    vector<string> tokens;
    for (int i = 0; i < expression.length(); i++) {
      if (expression[i] == ' ') {
        tokens.push_back(token);
        token = "";

        while ((i+1) < expression.length() &&
            (expression[i+1] == ' ' || expression[i+1] == '+' || expression[i+1] == '='))
          i++;
      }
      else {
        token += expression[i];
      }
    }
    if (token.length())
      tokens.push_back(token);

    int error_index = -1;

    assert(tokens.size() == 3);
    for (int i = 0; i < 3; i++) {
      if (!IsNumber(tokens[i])) {
        error_index = i;
        break;
      }
    }
    assert(error_index >= 0 && error_index < 3);

    string result;
    if (!error_index) {
      tokens[0] = to_string(stoll(tokens[2]) - stoll(tokens[1]));
    }
    else if (error_index == 1) {
      tokens[1] = to_string(stoll(tokens[2]) - stoll(tokens[0]));
    }
    else {
      tokens[2] = to_string(stoll(tokens[0]) + stoll(tokens[1]));
    }

    cout << tokens[0] << " + " << tokens[1] << " = " << tokens[2] << "\n";
  }
  return 0;
}
