#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int ans = 0;
    int left = 0, right = people.size() - 1;
    while (left <= right) {
      ans++;
      if (people[right] + people[left] <= limit) {
        left++;
      }
      right--;
    }
    return ans;
  }
};

struct Test {
  vector<int> people;
  int limit;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2}, 3, 1},
    { {3,2,2,1}, 3, 3 },
    { {3,5,3,4}, 5, 4 }, // {3,3,4,5}
    { {1,2}, 2, 2 },
    { {1,1}, 1, 2 },
    { {1}, 1, 1 },
    { {1,4,4,4,4}, 4, 5 },
    { {1,1,2,2,3}, 3, 3 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.numRescueBoats(test.people, test.limit);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}