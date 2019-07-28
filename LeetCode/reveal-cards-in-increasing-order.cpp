#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template <class T>
void print(T v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}

queue<int> initializeGame(int limit) {
  queue<int> deck;
  for (int i = 0; i < limit; i++) deck.push(i);
  return deck;
}

vector<int> play(vector<int>& deck) {
  vector<int> result;
  queue<int> q = initializeGame(deck.size());
  int n;
  while (!q.empty()) {
    n = q.front();
    q.pop();
    result.push_back(n);
    n = q.front();
    q.pop();
    q.push(n);
  }
  return result;
}

vector<int> deckRevealedIncreasing(vector<int>& deck) {
  sort(deck.begin(), deck.end());
  vector<int> order = play(deck);
  // print(order);
  vector<int> result(deck.size());
  for (int i = 0; i < order.size(); i++) {
    result[order[i]] = deck[i];
  }

  return result;
}

int main(void) {
  vector<int> input = {17,13,11,2,3,5,7};
  vector<int> expectedOutput = {2,13,3,11,5,17,7};
  if (expectedOutput == deckRevealedIncreasing(input))
    cout << "Good Job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}
