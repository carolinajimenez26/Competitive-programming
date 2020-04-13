#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    if (stones.size() == 0) return 0;
    if (stones.size() == 1) return stones[0];
    priority_queue<int> q;
    for (auto stone : stones) {
      q.push(stone);
    }
    while (!q.empty() && q.size() > 1) {
      int a = q.top();
      q.pop();
      int b = q.top();
      q.pop();
      int diff = a - b;
      if (diff != 0) {
        q.push(diff);
      }
    }
    if (q.empty()) return 0;
    return q.top();
  }
};

int main(void) {
  return 0;
}