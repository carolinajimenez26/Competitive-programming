#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string stringShift(string s, vector<vector<int>>& shifts) {
    for (auto shift : shifts) { // O (shifts.size() * s.size())
      if (shift[0] == 0) {
        s = RotateLeft(s, shift[1]);
      } else {
        s = RotateRight(s, shift[1]);
      }
    }
    return s;
  }
private:
  // O (s.size())
  string RotateRight(const string& s, int times) {
    string result = "";
    times %= s.size();
    for (int i = s.size() - times; i < s.size(); i++) {
      result.push_back(s[i]);
    }
    for (int i = 0; i < s.size() - times; i++) {
      result.push_back(s[i]);
    }
    return result;
  }
  // O (s.size())
  string RotateLeft(const string& s, int times) {
    string result = "";
    times %= s.size();
    for (int i = times; i < s.size(); i++) {
      result.push_back(s[i]);
    }
    for (int i = 0; i < times; i++) {
      result.push_back(s[i]);
    }
    return result;
  }
};

int main(void) {
  string s = "abc";
  vector<vector<int>> shift = {{0,1},{1,2}};
  Solution sol;
  cout << sol.stringShift(s, shift) << endl;
  return 0;
}