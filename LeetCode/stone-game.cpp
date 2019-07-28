#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Game {
  vector<int> stones;
  int left;
  int right;
  Game(vector<int> _stones) : stones(_stones), left(0), right(_stones.size() - 1) {}

  int takeFirstPile() {
    if (left >= stones.size()) return -1;
    int result = stones[left];
    left++;
    return result;
  }

  int takeLastPile() {
    if (right < 0) return -1;
    int result = stones[right];
    right--;
    return result;
  }

  bool isOver() {
    return left > right;
  }

  void goBack(bool lastMove) {
    if (lastMove == 0) { // last move was to get the first pile
      left = (left - 1 >= 0 ? left - 1 : 0);
    } else {
      right = (right + 1 < stones.size() ? right + 1 : stones.size() - 1);
    }
  }
};

struct Player {
  vector<int> gained;
  int total_amount;
  bool turn;
  string name;
  Player(string _name) : total_amount(0), turn(false), name(_name) {}

  void switchTurn() {
    turn = !turn;
  }

  void incrementAmount(int n) {
    gained.push_back(n);
    total_amount += n;
  }

  void decrementAmount() {
    if (gained.size() == 0) return;
    total_amount -= gained[gained.size() - 1];
    gained.pop_back();
  }

  int getTotalAmount() {
    return total_amount;
  }
};

void incrementAmount(Game& game, Player& p, int move) {
  if (move == 0) {
    p.incrementAmount(game.takeFirstPile());
  } else {
    p.incrementAmount(game.takeLastPile());
  }
}

bool play(Game& game, Player& p1, Player& p2, bool move) {

  if (game.isOver()) return p1.getTotalAmount() > p2.getTotalAmount();

  incrementAmount(game, p1.turn ? p1 : p2, move);

  p1.switchTurn();
  p2.switchTurn();
  bool p1_won = play(game, p1, p2, !move);

  if (p1_won) return true;

  game.goBack(!move);
  if (p1.turn) {
    p1.decrementAmount();
  } else {
    p2.decrementAmount();
  }

  p1.switchTurn();
  p2.switchTurn();

  return play(game, p1, p2, move);
}

class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    Game game(piles);
    Player p1("Alex");
    Player p2("Lee");
    p1.switchTurn();
    bool move_option = 0; // first
    return play(game, p1, p2, move_option);
  }
};

int main(void) {
  vector<int> input = {5,3,4,5};
  Solution sol;
  cout << sol.stoneGame(input) << endl;
  return 0;
}
