#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#define INF numeric_limits<int>::max()

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freqs;
    for (auto e : nums) {
      freqs[e]++;
    }
    for (auto freq : freqs) {
      if (freq.second == 1) return freq.first;
    }
    return -INF; // error
  }
};

int main(void) {
  vector<int> v = {4,1,2,1,2};
  Solution sol;
  cout << sol.singleNumber(v) << endl;
  return 0;
}