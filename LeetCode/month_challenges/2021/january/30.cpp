#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    set<int> ordered(nums.begin(), nums.end());
    int best = MoveSmallersToRight(ordered);
    best = min(best, MoveGreatestToLeft(ordered));
    return best;
  }
private:
  bool IsEven(int n) {
    return n % 2 == 0;
  }

  int MoveSmallersToRight(set<int>& ordered) {
    int first = *ordered.begin();
    int last = *ordered.rbegin();
    int best = last - first;
    while (!IsEven(*ordered.begin())) {
      first = *ordered.begin();
      ordered.erase(first);
      ordered.insert(first * 2);
      first = *ordered.begin();
      last = *ordered.rbegin();
      int diff = last - first;
      best = min(best, diff);
    }
    return best;
  }

  int MoveGreatestToLeft(set<int>& ordered) {
    int first = *ordered.begin();
    int last = *ordered.rbegin();
    int best = last - first;
    while (IsEven(*ordered.rbegin())) {
      last = *ordered.rbegin();
      ordered.erase(last);
      ordered.insert(last / 2);
      first = *ordered.begin();
      last = *ordered.rbegin();
      int diff = last - first;
      best = min(best, diff);
    }
    return best;
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {4,1,5,20,3};
  cout << sol.minimumDeviation(nums) << endl;
  return 0;
}