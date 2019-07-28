#include <iostream>
#include <string>

using namespace std;

void shift(string& s) {
  char saved = s[0], tmp;
  int i;
  for (i = s.size() - 1; i >= 0; i--) {
    tmp = s[i];
    s[i] = saved;
    saved = tmp;
  }
}

bool rotateString(string A, string B) {
  if (A == B) return true;
  if (A.size() != B.size()) return false;
  for (int i = 0; i < A.size(); i++) {
    shift(A);
    if (A == B) return true;
  }
  return false;
}

int main(void) {
  cout << rotateString("aaaaab", "baaaa") << endl;
  return 0;
}
