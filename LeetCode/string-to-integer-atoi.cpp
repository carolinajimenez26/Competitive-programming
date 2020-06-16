#include <iostream>
#include <vector>
#include <limits>
using namespace std;

using int64 = long long int;
class Solution {
private:
  const int INF = numeric_limits<int>::max();

  int IgnoreSpaces(const string& s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') return i;
    }
    return s.size();
  }

  bool IsLetter(char c) {
    for (char letter = 'a'; letter <= 'z'; letter++) {
      if (c == letter) return true;
    }
    return false;
  }

  bool IsNumber(char c) {
    for (char n = '0'; n <= '9'; n++) {
      if (c == n) return true;
    }
    return false;
  }

  int ParseToInt(const string& s, bool negative) {
    if (s.size() >= 11) { // we can represent maximum 2^32, which needs log(2^32) = 10 digits
      return negative ? -INF - 1 : INF;
    }
    int64 power_10 = 1;
    int64 ans = 0;
    for (int i = s.size() - 1; i >= 0 && ans <= INF; i--, power_10 *= 10) {
      ans += ((s[i] - '0') * power_10);
    }
    if (ans > INF) {
      return negative ? -INF - 1 : INF;
    }
    if (negative) {
      ans *= -1;
    }
    return ans;
  }

public:
  int myAtoi(string str) {
    int i = IgnoreSpaces(str);
    if (i == str.size() || IsLetter(str[i])) return 0;
    bool negative = str[i] == '-';
    if (str[i] == '-' || str[i] == '+') i++;
    string number = "";
    for (; i < str.size(); i++) {
      if (IsNumber(str[i])) {
        if (number.empty() && str[i] == '0') {
          continue;
        }
        number.push_back(str[i]);
      } else {
        break;
      }
    }
    if (number.empty()) return 0;
    return ParseToInt(number, negative);
  }
};

struct Test {
  string word;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    {
      "42",
      42
    },
    {
      "   -42",
      -42
    },
    {
      "4193 with words",
      4193
    },
    {
      "words and 987",
      0
    },
    {
      "-91283472332",
      -2147483648
    },    
    {
      "  0000000000012345678",
      12345678
    },
    {
      "2147483647",
      2147483647
    },
    {
      "-2147483647",
      -2147483647
    },
    {
      "20000000000000000000",
      2147483647
    }
  };

  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.myAtoi(test.word);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " 
           << test.expected << endl;
      succeed = false;
    }
    tc++;
  }

  if (succeed) cout << "Good Job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}