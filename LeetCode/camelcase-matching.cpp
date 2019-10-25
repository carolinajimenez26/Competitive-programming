#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

class Solution {
public:
  void AddRest(string& to, const string& from, int idx) {
    for (; idx < from.size(); idx++) {
      if (!isupper(from[idx])) {
        to.push_back(from[idx]);
      }
    }
  }

  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> result(queries.size(), true);

    int queries_idx = 0;
    for (auto query : queries) {
      string pattern_s;
      int i = 0, j = 0;
      for (; i < query.size() && j < pattern.size(); i++) {
        if (query[i] == pattern[j]) {
          pattern_s.push_back(query[i]);
          j++;
        } else {
          if (isupper(query[i])) {
            result[queries_idx] = false;
          } else {
            pattern_s.push_back(query[i]);
          }
        }
      }
      AddRest(pattern_s, query, i);
      result[queries_idx] = pattern_s == query && j == pattern.size();
      queries_idx++;
    }
    return result;
  }
};

struct Test {
  vector<string> queries;
  string pattern;
  vector<bool> expected;
};

void Print(const vector<bool>& v) {
  for (auto b : v) {
    cout << b << " ";
  }
  cout << endl;
}

int main(void) {
  vector<Test> tests = {
    {
      {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"},
      "FB",
      {true,false,true,true,false}
    },
    {
      {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"},
      "FoBa",
      {true,false,true,false,false}
    },
    {
      {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"},
      "FoBaT",
      {false,true,false,false,false}
    }
  };

  bool succeed = true;

  int test_case = 0;
  for (auto test : tests) {
    Solution sol;
    vector<bool> out = sol.camelMatch(test.queries, test.pattern);
    if (out != test.expected) {
      cout << "Failed on test #" << test_case << endl;
      succeed = false;
      cout << "Got: " << endl;
      Print(out);
      cout << "Expected: " << endl;
      Print(test.expected);
    }
    test_case++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}