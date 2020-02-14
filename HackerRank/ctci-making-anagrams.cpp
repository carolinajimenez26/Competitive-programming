#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
  int makeAnagram(string a, string b) {
    if (a.size() == 0 || b.size() == 0) {
      return a.size() + b.size();
    } 
    string smaller = (a.size() > b.size() ? b : a);
    string bigger = (smaller == a ? b : a);
    int res = 0;
    sort(smaller.begin(), smaller.end());
    sort(bigger.begin(), bigger.end());
    int i = 0, j = 0;
    while (i < smaller.size() && j < bigger.size()) {
      if (smaller[i] < bigger[j]) {
        i++;
        res++;
      } else if (smaller[i] > bigger[j]) {
        j++;
        res++;
      } else {
        i++;
        j++;
      }
    }
    res += (j >= bigger.size() ? 0 : bigger.size() - j);
    res += (i >= smaller.size() ? 0 : smaller.size() - i);
    return res;
  }
};

struct Test {
  string a;
  string b;
  int result;
};

int main(void) {
  vector<Test> tests = {
    {
      "cde",
      "dcf",
      2
    },
    {
      "cde",
      "abc",
      4
    },
    {
      "caro",
      "carox",
      1
    },
    {
      "caro",
      "caroxyz",
      3
    },
    {
      "carol",
      "caroxyz",
      4
    },
    {
      "abbc",
      "abcc",
      2
    },
    {
      "",
      "abc",
      3
    },
    {
      "",
      "",
      0
    },
  };
  int tc = 0;
  bool succeed = true;

  for (auto test : tests) {
    Solution sol;
    int out = sol.makeAnagram(test.a, test.b);
    if (out != test.result) {
      cout << "--------" << endl;
      succeed = false;
      cout << "Failed on test #" << tc << endl;
      cout << "Got: " << out << ", expected " << test.result << endl;
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}