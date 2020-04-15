#include <iostream>
#include <vector>
#define MAX 1e5 + 5
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct Game {
  int x, n, m;

  void print() {
    dbg(x); dbg(n); dbg(m);
  }
};

int main(void) {
  int tc,x,n,m;
  cin >> tc;
  while (tc--) {
    cin >> x >> n >> m;
    bool won = false;
    int y = (x / 2) + 10;
    if (y < x) {
      for (int i = 0; i < n; i++) {
        x = (x / 2) + 10;
        if (x <= 0) won = true;
      }
    }
    for (int i = 0; i < m; i++) {
      x = x - 10;
      if (x <= 0) won = true;
    }
    cout << (won ? "YES" : "NO") << endl;
  }
  return 0;
}