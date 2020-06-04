#include <iostream>
#include <set>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

int FindMinK(const set<int>& s) {
  int MAX = 1024;
  for (int n = 1; n <= MAX; n++) {
    // dbg(n);
    set<int> s_prime;
    for (auto e : s) {
      int x = e ^ n;
      // dbg(e); dbg(x);
      s_prime.insert(x);
    }
    if (s_prime == s) {
      return n;
    }
  }
  return -1;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s.insert(x);
    }
    cout << FindMinK(s) << endl;
  }
  return 0;
}