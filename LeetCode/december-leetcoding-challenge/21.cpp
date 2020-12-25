#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int smallestRangeII(vector<int>& A, int K_) {
    if (A.size() <= 1) return 0;
    sort(A.begin(), A.end());
    K = K_;
    v = A;
    int ans = A.back() - A[0];
    for (int p = 0; p < A.size() - 1; p++) {
      ans = min(ans, GetMax(p) - GetMin(p));
    }
    return ans;
  }
private:
  vector<int> v;
  int K;

  int GetMax(int idx) {
    return max(v[idx] + K, v.back() - K);
  }
  
  int GetMin(int idx) {
    return min(v[0] + K, v[idx + 1] - K);
  }
};

/*

[2,3,5,6] --> (2 + 3 + 5 + 6) / 4 = 4

[2,3,5,6], K = 1 => B: [3,4,4,5] ==> 2
[2,3,5,6], K = 2 => B: [4,5,3,4] ==> 2
[2,3,5,6], K = 2 => B: [4,5,3,4] ==> 2
[2,3,5,6], K = 10 => B: [12,13,-5,-4] ==> 18
                     B: [12,13,15,16] ==> 4

[3,6] K = 6

1. [9,12] adding both 6 ==> 3
2. [-3,0] adding both -6 ==> 3
3. [9,0] adding first 6 and second -6 ==> 9
3. [3,12] adding first -6 and second 6 ==> 9

               [3,6]                i = 0

        [-3,6]         [9,6]        i = 1

  [-3,0]  [-3,12]   [9,0]   [9,12]  i = 2   
*/

struct Test {
  vector<int> A;
  int K, expected;
};

int main(void) {
  vector<Test> tests = {
    { {1}, 0, 0 },
    { {1,3,4,6}, 3, 4 },
    { {1,3,4,6,10,20}, 3, 13 },
    { {0,10}, 2, 6 },
    { {1,3,6}, 3, 3 },
    { {1,3,6}, 3, 3 },
    { {10,7,1}, 3, 3 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.smallestRangeII(test.A, test.K);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}
