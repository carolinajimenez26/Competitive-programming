#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

int FindMinDifference(const vector<int>& v) {
  int ans = numeric_limits<int>::max();
  for (int i = 1; i < v.size(); i++) {
    ans = min(ans, abs(v[i - 1] - v[i]));
  }
  return ans;
}

int main(void) {
  int tc, n;
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    cout << FindMinDifference(s) << endl;
  }
  return 0;
}