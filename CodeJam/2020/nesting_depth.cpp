#include <iostream>

using namespace std;

string NestingDepthSimple(const string& S) {
  string result = "";
  int i = 0;
  while (i < S.size()) {
    if (S[i] == '1') {
      result.push_back('(');
      while (S[i] == '1' && i < S.size()) {
        result.push_back('1');
        i++;
      }
      result.push_back(')');
    } else {
      while (S[i] == '0' && i < S.size()) {
        result.push_back('0');
        i++;
      }
    }
  }
  return result;
}

inline int ToInt(char c) {
  return c - '0';
}

string NestingDepth(const string& S) {
  string result = "";
  int i = 0, opening = 0;
  while (i < S.size()) {
    int x = ToInt(S[i]);
    if (opening > x) { // close some parenthesis
      int rest = opening - x;
      for (int j = 0; j < rest; j++) {
        result.push_back(')');
        opening--;
      }
    } else { // open some parenthesis
      int rest = x - opening;
      for (int j = 0; j < rest; j++) {
        result.push_back('(');
        opening++;
      }
      char tmp = S[i];
      while (i < S.size() && S[i] == tmp) {
        result.push_back(S[i]);
        i++;
      }
    }
  }
  while (opening > 0) {
    result.push_back(')');
    opening--;
  }
  return result;
}

int main(void) {
  int tc;
  string S;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cin >> S;
    // string S_prime = NestingDepthSimple(S);
    string S_prime = NestingDepth(S);
    cout << "Case #" << i << ": " << S_prime << endl;
  }
  return 0;
}