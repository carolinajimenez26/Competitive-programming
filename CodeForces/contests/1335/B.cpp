#include <iostream>

using namespace std;

string CreateSubstring(int subs_size, int diff_letter) {
  string result = "";
  if (diff_letter == 1) {
    while (result.size() < subs_size) {
      result.push_back('a');
    }
  } else {
    char letter = 'a';
    for (int i = 0; i < (diff_letter - 1); i++) {
      result.push_back(letter);
      letter++;
    }
    while (result.size() < subs_size) {
      result.push_back(letter);
    }
  }
  return result;
}

string CreateString(int size, int subs_size, int diff_letter) {
  string subs = CreateSubstring(subs_size, diff_letter);
  string result = "";
  int i = 0;
  while (result.size() < size) {
    result.push_back(subs[i % subs.size()]);
    i++;
  }
  return result;
}

int main(void) {
  int tc, n, a, b;
  cin >> tc;
  while (tc--) {
    cin >> n >> a >> b;
    cout << CreateString(n,a,b) << endl;
  }
  return 0;
}