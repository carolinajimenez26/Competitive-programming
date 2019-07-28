#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
  vector<int> result(T.size());
  for (int i = 0; i < T.size(); i++) {
    int days = 1, j;
    for (j = i + 1; j < T.size(); j++, days++) {
      if (T[j] > T[i]) {
        result[i] = days;
        break;
      }
    }
    if (j == T.size()) result[i] = 0;
  }
  return result;
}

int main(void) {
  return 0;
}
