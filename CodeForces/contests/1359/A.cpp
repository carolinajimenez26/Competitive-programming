#include <iostream>
using namespace std;

int Ceil(int a, int b) {
  int ans = a / b;
  ans += (a % b == 0 ? 0 : 1);
  return ans;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int cards, jokers, players;
    cin >> cards >> jokers >> players;
    int ans = 0;
    if (jokers != 0) {
      int cards_per_player = cards / players;
      int max_jokers = cards_per_player;
      if (jokers <= cards_per_player) {
        ans = jokers;
      } else {
        // i have to get the max amount for me and try to give the least I can to others
        jokers -= cards_per_player;
        ans = cards_per_player - Ceil(jokers, (players - 1));
      }
    }
    cout << ans << endl;
  }
  return 0;
}