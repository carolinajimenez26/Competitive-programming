#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool judgeCircle(string moves) {
    int row = 0, col = 0;
    for (auto move : moves) {
      if (move == 'U') { // up
        row -= 1;
      }
      if (move == 'D') { // down
        row += 1;
      }
      if (move == 'L') { // left
        col -= 1;
      }
      if (move == 'R') { // right
        col += 1;
      }
    }
    return row == 0 && col == 0;
  }
};

int main(void) {
  return 0;
}