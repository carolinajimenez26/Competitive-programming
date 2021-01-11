#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0; i < m; i++) {
      nums1.push_back(0);
    }
    reverse(nums1.begin(), nums1.end());
    const int INF = numeric_limits<int>::max();
    int writer = 0;
    int i = nums1.size() - 1;
    int j = 0;
    int max_i = nums1.size() - m;
    while (writer < nums1.size()) {
      int a = i >= max_i ? nums1[i] : INF;
      int b = j < nums2.size() ? nums2[j] : INF;
      if (a < b) {
        nums1[writer] = a;
        i--;
      } else {
        nums1[writer] = b;
        j++;
      }
      writer++;
    }

    for (int i = 0; i < m; i++) {
      nums1.pop_back();
    }
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct Test {
  vector<int> nums1;
  int m;
  vector<int> nums2;
  int n;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3,0,0,0}, 3, {2,5,6}, 3, {1,2,2,3,5,6} },
    { {1}, 1, {}, 0, {1} },
    { {0}, 0, {1}, 1, {1} },
    { {1,2,3,0}, 3, {1}, 1, {1,1,2,3} },
    { {1,0,0,0}, 1, {1,2,3}, 3, {1,1,2,3} },
    { {1,2,3,0,0}, 3, {4,5}, 2, {1,2,3,4,5} },
    { {4,5,6,0,0}, 3, {1,2}, 2, {1,2,4,5,6} },
    { {1,3,5,0,0}, 3, {2,4}, 2, {1,2,3,4,5} },
    { {2,4,0,0,0}, 2, {1,3,5}, 3, {1,2,3,4,5} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    sol.merge(test.nums1, test.m, test.nums2, test.n);
    if (test.nums1 != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(test.nums1);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}