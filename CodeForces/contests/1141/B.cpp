#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200000;

void print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int maximalContinuousRest(vector<int>& v) {
  int ones = 0, result = 0;
  int prev = v[0];
  if (prev) ones++;
  for (int i = 1; i < v.size(); i++) {
    if (v[i]) ones++;
    else {
      if (ones > result) result = ones;
      ones = 0;
    }
    prev = v[i];
  }
  return result;
}

int main(void) {
  int n, ones = 0;
  cin >> n;
  vector<int> v(2*n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i]) ones++;
  }
  if (ones == n) cout << MAX << endl;
  else {
    int j = 0;
    for (int i = n; i < v.size(); i++, j++) {
      v[i] = v[j];
    }
    // print(v);
    cout << maximalContinuousRest(v) << endl;
  }
  return 0;
}
