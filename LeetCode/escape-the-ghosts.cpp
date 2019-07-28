#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
  double r1 = abs(target[0]) + abs(target[1]);
  for (auto ghost : ghosts) {
    double r2 = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);
    if (r2 <= r1) return false;
  }
  return true;
}

int main(void) {
  vector<vector<int>> ghosts = {{1,8},{-9,0},{-7,-6},{4,3},{1,3}};
  vector<int> target = {6,-9};
  escapeGhosts(ghosts, target);
  return 0;
}
