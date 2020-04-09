#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    Convert(S);
    Convert(T);
    return S == T;
  }
private:
  void Convert(string& s) {
    // Replace all the elements to remove for .
    DeleteAndReplace(s, '#', '.');
    // Then, move all valid elements to the begining
    MoveAllValidToBegining(s);
    // Then, remove the . in s
    int first_invalid = FindFirstOccurrance(s, '.');
    while (first_invalid != -1 && s.size() != first_invalid) {
      s.pop_back();
    }
  }

  void DeleteAndReplace(string& s, char delete_char, char replace_char) {
    int to_delete = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == delete_char) {
        to_delete++;
        s[i] = replace_char;
      } else {
        if (to_delete > 0) {
          s[i] = replace_char;
          to_delete--;
        }
      }
    }
  }

  int FindFirstOccurrance(const string& s, char c) {
    int result = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == c) {
        result = i;
        break;
      }
    }
    return result;
  }

  void MoveAllValidToBegining(string& s) {
    int point_i, valid_letter_i;
    point_i = valid_letter_i = FindFirstOccurrance(s, '.');
    if (point_i == -1) {
      return;
    }
    while (point_i < s.size() && valid_letter_i < s.size()) {
      while (valid_letter_i < s.size() && s[valid_letter_i] == '.') {
        valid_letter_i++;
      }
      while (point_i < s.size() && s[point_i] != '.') {
        point_i++;
      }
      if (valid_letter_i >= s.size() || point_i >= s.size()) {
        break;
      }
      swap(s[valid_letter_i], s[point_i]);
      valid_letter_i++;
      point_i++;
    }
  }
};

struct Test {
  string S;
  string T;
  bool equals;
};

int main(void) {
  vector<Test> tests = {
    {
      "xywrrmp",
      "xywrrmu#p",
      true
    },
    {
      "a#c",
      "b",
      false
    },
    {
      "a##c",
      "#a#c",
      true
    },
    {
      "ab##",
      "c#d#",
      true
    },
    {
      "ab#c",
      "ad#c",
      true
    },
    {
      "abcd##e###f#g",
      "g",
      true
    }
  };
  Solution sol;
  int tc = 0;
  for (auto test : tests) {
    bool out = sol.backspaceCompare(test.S, test.T);
    if (out != test.equals) {
      cout << "Failed on test #" << tc << endl;
    }
  }
  return 0;
}