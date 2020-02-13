#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  vector<int> rotLeft(vector<int> a, int d) {
    if (a.size() == 0 || d == a.size()) return a;
    if (d > a.size()) {
      int times = d / a.size();
      d -= (times * a.size());
    }
    vector<int> result(a.size(), 0);
    for (int i = 0; i < a.size(); i++) {
      int j = (a.size() - d + i) % a.size();
      result[j] = a[i];
    }
    return result;
  }
};

struct Test {
  vector<int> nums;
  int d;
  vector<int> result;
};

void print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  vector<Test> tests = {
    {
      {1,2,3,4,5},
      2,
      {3,4,5,1,2}
    },
    {
      {1,2,3,4,5},
      4,
      {5,1,2,3,4}
    },
    {
      {1},
      4,
      {1}
    },
    {
      {},
      4,
      {}
    },
    {
      {1,2,3,4,5},
      5,
      {1,2,3,4,5}
    },
    {
      {1,2,3,4,5},
      6,
      {2,3,4,5,1}
    },
    {
      {1,2,3,4},
      2,
      {3,4,1,2}
    },
    {
      {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51},
      10,
      {77, 97, 58, 1, 86, 58, 26, 10, 86, 51, 41, 73, 89, 7, 10, 1, 59, 58, 84, 77}
    }
  };
  int tc = 0;
  bool succeed = true;

  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.rotLeft(test.nums, test.d);
    if (out != test.result) {
      cout << "--------" << endl;
      succeed = false;
      cout << "Failed on test #" << tc << endl;
      cout << "Got: " << endl;
      print(out);
      cout << "Expected: " << endl;
      print(test.result);
      cout << "--------" << endl;
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}