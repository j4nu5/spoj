#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    int num_cols;
    cin >> num_cols;

    if (!num_cols)
      break;

    string cipher_text;
    cin >> cipher_text;

    int msg_length = cipher_text.length();
    assert(msg_length % num_cols == 0);

    int num_rows = msg_length / num_cols;

    vector<vector<char>> grid(num_rows, vector<char>(num_cols));
    int pos = 0;
    int row = 0;
    bool rev = false;
    while (pos < msg_length) {
      if (!rev) {
        for (int j = 0; j < num_cols; j++)
          grid[row][j] = cipher_text[pos++];
      }
      else {
        for (int j = num_cols - 1; j >= 0; j--)
          grid[row][j] = cipher_text[pos++];
      }

      row++;
      rev = !rev;
    }

    string plain_text;
    for (int j = 0; j < num_cols; j++) {
      for (int i = 0; i < num_rows; i++) {
        plain_text += grid[i][j];
      }
    }

    cout << plain_text << "\n";
  }
  return 0;
}
