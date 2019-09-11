#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool Play(int N, string player) {
    if (N <= 1) {
      return player == "Bob";
    }
    string next_player = (player == "Alice" ? "Bob" : "Alice");
    if (Play(N - 1, next_player)) {
      return true;
    }
    return false;
  }

  bool divisorGame(int N) {
    return Play(N, "Alice");
  }
};

int main(void) {
  Solution sol;
  cout << sol.divisorGame(999) << endl;
  return 0;
}
