#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int ToInt(char c) {
  return c - '0';
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    string input;
    cin >> input;
    vector<int> result;
    int pow10 = 1;
    for (int i = input.size() - 1; i >= 0; i--, pow10 *= 10) {
      if (input[i] == '0') continue;
      result.push_back((ToInt(input[i]) * pow10));
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }
    cout << endl;
  }
  return 0;
}