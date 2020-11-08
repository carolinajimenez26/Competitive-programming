#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // Runtime: O(v.size())
  // Space: O(v.size())
  unordered_map<int, int> CreateHash(const vector<int>& v) {
    unordered_map<int, int> hash_freqs;
    for (auto e : v) {
      hash_freqs[e]++;
    }
    return hash_freqs;
  }
  // Runtime: O(smaller.size() + larger.size())
  // Runtime: O(smaller.size())
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    vector<int> smaller = nums1.size() < nums2.size() ? nums1 : nums2;
    vector<int> larger = smaller == nums1 ? nums2 : nums1;
    unordered_map<int, int> smaller_hash_freqs = CreateHash(smaller);
    for (auto e : larger) {
      if (smaller_hash_freqs[e] > 0) {
        ans.push_back(e);
        smaller_hash_freqs[e]--;
      }
    }
    return ans;
  }
};

struct Test {
  vector<int> nums1, nums2, expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {1,2,2,1},
      {2,2},
      {2,2}
    },
    {
      {4,9,5},
      {9,4,9,8,4},
      {4,9}
    },
    {
      {1,2,3},
      {4,5,6},
      {}
    },
    {
      {1,2,3},
      {4,5,3},
      {3}
    },
    {
      {1,2,3,4,5},
      {4,5,3},
      {4,5,3}
    },
    {
      {1,2,3,4,5},
      {4,1,5,3},
      {4,1,5,3}
    },
    {
      {1,2},
      {1,1},
      {1}
    }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.intersect(test.nums1, test.nums2);
    unordered_map<int,int> out_hash = sol.CreateHash(out);
    unordered_map<int,int> expected_hash = sol.CreateHash(test.expected);
    if (out_hash != expected_hash) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}