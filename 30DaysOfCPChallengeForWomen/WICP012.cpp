#include <iostream>

using namespace std;

int GetLastOne(string& s, int from) {
  for (int i = from; i >= 0; i--) {
    if (s[i] == '1') return i;
  }
  return -1;
}

int HowManyFlips(string& s) {
  int result = 0;
  int last_one = GetLastOne(s, s.size() - 1);
  if (last_one < 0) return 0;
  while (last_one >= 0) {
    for (int i = 0; i <= last_one; i++) {
      s[i] = (s[i] == '1' ? '0' : '1');
    }
    result++;
    last_one = GetLastOne(s, last_one);
  }
  return result;
}

int main(void) {
  string s;
  cin >> s;
  cout << HowManyFlips(s) << endl;
  return 0;
}