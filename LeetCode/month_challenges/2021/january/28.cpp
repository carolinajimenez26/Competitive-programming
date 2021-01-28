#include <iostream>
using namespace std;

class Solution {
public:
  string getSmallestString(int n, int k) {
    string ans = CreateWith(n, 'a');
    int sum = n;
    int i = ans.size() - 1;
    while (i >= 0 && sum < k) {
      int x = sum - GetVal(ans[i]) + GetVal('z');
      if (x > k) {
        ans[i] = GetChar(k - (sum - GetVal(ans[i])));
        break;
      }
      ans[i] = 'z';
      sum = x;
      i--;
    }
    return ans;
  }
private:
  char GetChar(int value) {
    char ans = value - 1 + 'a';
    return ans;
  }

  int GetVal(char c) {
    return c - 'a' + 1;
  }

  string CreateWith(int size, char c) {
    string ans;
    while (ans.size() < size) {
      ans.push_back(c);
    }
    return ans;
  }
};

int main(void) {
  Solution sol;
  cout << sol.getSmallestString(5, 73) << endl;
  return 0;
}