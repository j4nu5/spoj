#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<char> operators = {'+', '-', '*', '/', '^'};
  unordered_map<char, int> precedence;
  for (int i = 0; i < operators.size(); i++) {
    precedence[operators[i]] = i;
  }

  int T;
  cin >> T;
  cin.ignore(1, '\n');

  while (T--) {
    string infix;
    cin >> infix;

    string postfix;

    stack<char> S;
    for (char ch : infix) {
      if (ch == '(') {
        S.push(ch);
      }
      else if (ch == ')') {
        while (S.top() != '(') {
          postfix += S.top();
          S.pop();
        }
        S.pop();
      }
      else if (precedence.count(ch)) {
        while (!S.empty() && (S.top() != '(') && (precedence[S.top()] >= precedence[ch])) {
          postfix += S.top();
          S.pop();
        }
        S.push(ch);
      }
      else {
        postfix += ch;
      }
    }

    while (!S.empty()) {
      postfix += S.top();
      S.pop();
    }

    cout << postfix << "\n";
  }
  return 0;
}
