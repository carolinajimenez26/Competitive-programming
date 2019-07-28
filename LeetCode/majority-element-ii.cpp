#include <iostream>
#include <algorithm>
#include <vector>
#define dbg(x) cout << #x << ": " << (x) << endl

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    if (nums.size() == 0) return {};
    vector<int> result;
    int min_times = nums.size() / 3;
    int INF = numeric_limits<int>::max();
    int e1 = -INF, e2 = -INF; // There could be only 2 numbers
    int counter_e1 = 0, counter_e2 = 0;
    
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (counter_e1 == 0 && num != e2) {
        e1 = num;
        counter_e1++;
        continue;
      }
      if (counter_e2 == 0 && num != e1) {
        e2 = num;
        counter_e2++;
        continue;
      }
      if (num == e1) {
        counter_e1++;
      }
      if (num == e2) {
        counter_e2++;
      }
      if (num != e1 && num != e2) {
        counter_e1--;
        counter_e2--;
      }
    }

    counter_e1 = counter_e2 = 0;
    
    for (auto num : nums) {
      if (num == e1) counter_e1++;
      if (num == e2) counter_e2++;
    }

    if (counter_e1 > min_times) result.push_back(e1);
    if (counter_e2 > min_times) result.push_back(e2);

    sort(result.begin(), result.end());
    return result;
  }
};

int main() {
  vector<int> input = {1,1,1,3,3,2,2,2};//{1,2,3,3,3,6,6,6};
  vector<int> output = majorityElement(input);
  print(output);
  return 0;
}
