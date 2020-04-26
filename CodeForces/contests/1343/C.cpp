#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;
using int64 = long long int;

inline string GetSign(int x) {
  return x > 0 ? "+" : "-";
}

int64 GetBest(const vector<int64>& v, int size) {
  if (size == 0) return 0;
  const int64 INF = numeric_limits<int64>::max();
  string sign = GetSign(v[0]);
  int64 result = 0, best = -INF;
  int i = 0;
  while (i < size) {
    while (i < size && GetSign(v[i]) == sign) {
      best = max(best, v[i]);
      i++;
    }
    result += best;
    best = -INF;
    sign = i < size ? GetSign(v[i]) : "+";
  }
  return result;
}

int main(void) {
  const int MAX = 2e5 + 5;
  vector<int64> A(MAX);
  int tc, n;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    cout << GetBest(A, n) << endl;
  }
  return 0;
}