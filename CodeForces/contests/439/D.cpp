#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;
using int64 = long long int;

int64 Difference(const vector<int>& a, const vector<int>& b, int point) {
  int64 ans = 0;
  for (auto e : a) {
    if (e < point) ans += (point - e);
  }
  for (auto e : b) {
    if (e > point) ans += (e - point);
  }
  return ans;
}

int64 MinStepsTo(const vector<int>& a, const vector<int>& b) {
  int MAX = 1e9;
  int64 best = numeric_limits<int64>::max();
  int l = 1, r = MAX;
  for (int t = 1; t <= MAX; t++) {
    if (r - l <= 3) {
      break;
    }
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = Difference(a,b,m1);      //evaluates the function at m1
    double f2 = Difference(a,b,m2);      //evaluates the function at m2
    if (f1 > f2) {
      l = m1;
    } else {
      r = m2;
    }
  }
  for (int t = l; t <= r; t++) {
    best = min(best, Difference(a,b,t));
  }
  return best;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  cout << MinStepsTo(a,b) << endl;
  return 0;
}