#include <iostream>
#include <deque>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct Player {
  string name;
  int sweets_eaten;
  bool playing;

  void Print() {
    cout << name << ", " << sweets_eaten << endl;
  }
};

void ToggleTurns(Player& a, Player& b) {
  if (a.playing) {
    a.playing = false;
    b.playing = true;
  } else {
    b.playing = false;
    a.playing = true;
  }
}
 // 1 1 1
int Play(Player& a, Player& b, int last_move, deque<int>& candies) {
  // a.Print(); b.Print();
  if (candies.empty()) return 0; // end of the game
  int curr_move = 0;
  while (!candies.empty() && last_move >= curr_move) {
    if (a.playing) {
      curr_move += candies.front();
      candies.pop_front();
    } else {
      curr_move += candies.back();
      candies.pop_back();
    }
  }
  // dbg(curr_move);
  a.playing ? (a.sweets_eaten += curr_move) : (b.sweets_eaten += curr_move);
  ToggleTurns(a,b);
  return 1 + Play(a, b, curr_move, candies);
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    deque<int> candies;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      candies.push_back(x);
    }
    Player alice{"Alice", 0, true}, bob{"Bob", 0, false};
    int total_moves = Play(alice, bob, 0, candies);
    cout << total_moves << " " << alice.sweets_eaten << " " << bob.sweets_eaten <<  endl;
  }
  return 0;
}